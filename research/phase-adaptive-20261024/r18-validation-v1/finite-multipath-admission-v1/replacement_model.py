"""Execution-driven single-writer two-core HUSH subset with bounded service.

Read hits cancel at capture; responses use the captured payload. A miss
reserves sharing at bus grant, obtains current data at bus completion, then
returns. Phase writes are real 1-cycle operations; local computation and
request service determine later issue times. Independent per-core queues,
one outstanding transaction per core, and round-robin bus arbitration.
"""
from pathlib import Path
from itertools import product
import json,time,hashlib
HERE=Path(__file__).resolve().parent
P=json.loads((HERE/'interlocked_closed_loop_protocol.json').read_text())
def retention(k):return 10**12 if k==255 else (k-1)*P['period']

def instructions(kind,quiet):
 ops=[]
 for p in range(3):
  ops.append(('phase',p))
  dense=(kind=='DQD' and p!=1) or (kind=='SDS' and p==1) or (kind=='BSQ' and p!=2)
  nreads=P['shared_blocks'] if kind=='BSQ' and p==0 else P['receiver_dense_reads'] if dense else 1
  for j in range(nreads):
   ops.append(('compute',P['receiver_compute_gap'] if dense else 0))
   ops.append(('read',j%P['shared_blocks']))
  if not dense:ops.append(('compute',quiet))
 return ops

def analyze(ops,ks,reset=False,flush_at_boundaries=False,cache_sets=None,cache_ways=None,budget=None):
 rem=[-10**12]*P['shared_blocks'];elapsed=0;k=ks[0];phase=0;pred={};hits=misses=switches=0
 assert (cache_sets is None)==(cache_ways is None)
 if cache_sets is not None:assert cache_sets>0 and cache_ways>0
 # Most-recent distinct LOCAL references. Ignoring expiry gives a
 # conservative reuse-distance certificate, not the concrete cache state.
 recent=[[] for _ in range(cache_sets or 1)]
 residency_predictions={}
 for index,(op,value) in enumerate(ops):
  if op=='phase':
   phase=value
   if phase>0 and flush_at_boundaries and (flush_at_boundaries is True or phase in flush_at_boundaries):rem=[-10**12]*P['shared_blocks']
   if ks[phase]!=k:
    k=ks[phase];switches+=1
    rem=[min(r,retention(k)) if not reset else -10**12 for r in rem]
    elapsed+=P['switch_cycles'];rem=[r-P['switch_cycles'] for r in rem]
  elif op=='compute':
   elapsed+=value;rem=[r-value for r in rem]
  else:
   s=value%(cache_sets or 1)
   resident=cache_sets is None or value in recent[s]
   hit=rem[value]>0 and resident
   residency_predictions[index]=resident
   pred[index]=hit;hits+=int(hit);misses+=int(not hit)
   if cache_sets is not None:
    if value in recent[s]:recent[s].remove(value)
    recent[s].insert(0,value);recent[s]=recent[s][:cache_ways]
   service=1 if hit else P['analytic_unknown_read_bound_cycles']
   # Earliest possible cancellation/capture is request issue. If the access
   # is conservatively charged unknown but actually hits, this still covers
   # WUs during its buffered response. A miss captures no earlier than issue.
   rem[value]=retention(k)
   elapsed+=service;rem=[r-service for r in rem]
 compute=sum(v for op,v in ops if op=='compute')
 # An optional task budget is supplied externally, never inferred here.
 return {'bound':elapsed,'budget':budget,'feasible':(elapsed<=budget if budget is not None else None),'hits':hits,
         'unknown':misses,'switches':switches,'predictions':pred,'residency_predictions':residency_predictions}

def simulate(ops,ks,writer_gap,phi,analysis=None,keep_trace=False,writer_count=None,phase_policy=None,admission_guard=True,flush_at_boundaries=False,flush_at_finish=False,cache_sets=None,cache_ways=None):
 writer_count=writer_count or P['writer_store_count']
 ks=list(ks)
 analysis=analysis or analyze(ops,ks,flush_at_boundaries=flush_at_boundaries,cache_sets=cache_sets,cache_ways=cache_ways)
 n=P['shared_blocks']
 assert (cache_sets is None)==(cache_ways is None)
 if cache_sets is not None:assert cache_sets>0 and cache_ways>0
 lru=[[] for _ in range(cache_sets or 1)];evictions=0
 valid=[False]*n;active=[False]*n;count=[0]*n;data=[0]*n;version=[0]*n;shared=[False]*n
 ip=0;rready=0;rwaiting=False;rhit_due=None;config_due=None;k=ks[0]
 windex=0;wready=0;wwaiting=False;private_due=None
 rq=None;wq=None;bus=None;last=1
 packets=deliveries=misses=hits=unsafe=0;read_done=write_done=None;max_read_service=max_update_service=0
 read_issue=None;trace=[];config_wu_deferrals=0
 t=0
 def touch_cache(block):
  nonlocal evictions
  if cache_sets is None:return
  stack=lru[block%cache_sets]
  if block in stack:stack.remove(block)
  elif len(stack)==cache_ways:
   victim=stack.pop()
   assert valid[victim]
   valid[victim]=False;active[victim]=False;count[victim]=0;evictions+=1
   # Silent clean eviction may leave a stale-positive writer sharing bit,
   # exactly as silent expiry does. A later WU reconciles that bit.
  stack.insert(0,block)
 def finish_read(now):
  nonlocal rwaiting,rready,max_read_service
  rwaiting=False;rready=now
  max_read_service=max(max_read_service,now-read_issue)
 while read_done is None or write_done is None:
  if t>200000:raise RuntimeError('simulation watchdog')
  config_completed_now=config_due is not None and config_due[0]==t
  if config_completed_now:
   k=config_due[1];config_due=None;rwaiting=False;rready=t
  if config_completed_now and bus is not None and bus['kind']=='wu' and bus['end']==t:
   bus['end']+=1;config_wu_deferrals+=1
  if bus is not None and bus['end']==t:
   b=bus['block']
   if bus['kind']=='wu':
    version[b]+=1;packets+=1
    if valid[b]:
     data[b]=version[b];active[b]=(k!=255);count[b]=(k if k!=255 else 0);deliveries+=1
    shared[b]=valid[b];windex+=1;wwaiting=False;wready=t+writer_gap
    max_update_service=max(max_update_service,t-bus['issue'])
   else:
    touch_cache(b)
    valid[b]=True;active[b]=False;count[b]=0;data[b]=version[b];shared[b]=True
    finish_read(t)
   bus=None
  if private_due is not None and private_due[0]==t:
   _,b=private_due;assert not shared[b]
   version[b]+=1;windex+=1;wwaiting=False;wready=t+writer_gap;private_due=None
  if t%P['period']==phi:
   for b in range(n):
    if active[b]:
     count[b]-=1
     if count[b]==0:
      active[b]=False;valid[b]=False
      if cache_sets is not None:lru[b%cache_sets].remove(b)
  if rhit_due is not None and rhit_due[0]==t:
   # The response payload is a snapshot captured before any intervening WU.
   assert rhit_due[1]==rhit_due[2]
   rhit_due=None;finish_read(t)
  if windex==writer_count and write_done is None:write_done=t
  if ip==len(ops) and not rwaiting and t>=rready and read_done is None:
   read_done=t
   if flush_at_finish:
    valid=[False]*n;active=[False]*n;count=[0]*n;shared=[False]*n
    for stack in lru:stack.clear()
  if windex<writer_count and not wwaiting and t>=wready:
   b=windex%n
   if shared[b]:
    wwaiting=True;wq={'kind':'wu','block':b,'issue':t}
   elif rq is None or not admission_guard:
    wwaiting=True;private_due=(t+1,b)
  if ip<len(ops) and not rwaiting and t>=rready:
   while ip<len(ops):
    op,v=ops[ip]
    if op=='phase':
     if v>0 and flush_at_boundaries and (flush_at_boundaries is True or v in flush_at_boundaries):
      valid=[False]*n;active=[False]*n;count=[0]*n;shared=[False]*n
      for stack in lru:stack.clear()
     if phase_policy is not None:
      choice,completion=phase_policy(tuple(ks[:v]),{'phase':v,'t':t,
        'writer_completed':windex,'writer_total':writer_count,
        'receiver_hits':hits,'receiver_misses':misses,'deliveries':deliveries})
      ks[v]=choice
      analysis=analyze(ops,completion,flush_at_boundaries=flush_at_boundaries,cache_sets=cache_sets,cache_ways=cache_ways)
     ip+=1
     if ks[v]!=k:
      rwaiting=True;config_due=(t+P['switch_cycles'],ks[v]);break
    elif op=='compute':
     ip+=1
     if v:rready=t+v;break
    else:
     read_issue=t;rwaiting=True
     predicted=analysis['predictions'][ip]
     unsafe+=int(predicted and not valid[v]);assert not predicted or valid[v]
     if valid[v]:
      touch_cache(v)
      hits+=1;assert data[v]==version[v]
      active[v]=False;count[v]=0;rhit_due=(t+1,data[v],version[v])
     else:
      misses+=1;rq={'kind':'miss','block':v,'issue':t}
     if keep_trace:trace.append({'t':t,'ip':ip,'line':v,'actual_hit':valid[v],'predicted_hit':predicted,'K':k})
     ip+=1;break
  if bus is None:
   eligible=[]
   if wq is not None:eligible.append(0)
   if rq is not None and private_due is None:eligible.append(1)
   if eligible:
    core=next((c for c in ((last+1)%2,last) if c in eligible))
    req=wq if core==0 else rq
    bus=dict(req);bus['end']=t+(P['update_slot_cycles'] if core==0 else P['miss_slot_cycles']);last=core
    if core==0:wq=None
    else:
     rq=None;shared[req['block']]=True
  if cache_sets is not None:
   for s,stack in enumerate(lru):
    assert len(stack)<=cache_ways and len(stack)==len(set(stack))
    assert all(valid[b] and b%cache_sets==s for b in stack)
   assert sum(valid)==sum(map(len,lru))
  t+=1
 assert sum(version)==writer_count
 assert read_done<=analysis['bound'],(read_done,analysis,ks)
 assert max_read_service<=P['analytic_unknown_read_bound_cycles'] and max_update_service<=P['analytic_unknown_read_bound_cycles'],(max_read_service,max_update_service)
 return {'K':list(ks),'phi':phi,'reader_cycles':read_done,'reader_bound':analysis['bound'],
         'writer_cycles':write_done,'makespan':max(read_done,write_done),
         'updates':packets,'deliveries':deliveries,'actual_misses':misses,'actual_hits':hits,
         'analysis_hits':analysis['hits'],'analysis_unknown':analysis['unknown'],
         'max_read_service':max_read_service,'max_update_service':max_update_service,
         'unsafe_hits':unsafe,'config_wu_deferrals':config_wu_deferrals,'replacement_evictions':evictions,'trace':trace if keep_trace else None}

