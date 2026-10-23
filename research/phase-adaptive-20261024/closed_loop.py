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
P=json.loads((HERE/'closed_loop_protocol.json').read_text())
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

def analyze(ops,ks,reset=False):
 rem=[-10**12]*P['shared_blocks'];elapsed=0;k=ks[0];phase=0;pred={};hits=misses=switches=0
 for index,(op,value) in enumerate(ops):
  if op=='phase':
   phase=value
   if ks[phase]!=k:
    k=ks[phase];switches+=1
    rem=[min(r,retention(k)) if not reset else -10**12 for r in rem]
    elapsed+=P['switch_cycles'];rem=[r-P['switch_cycles'] for r in rem]
  elif op=='compute':
   elapsed+=value;rem=[r-value for r in rem]
  else:
   hit=rem[value]>0;pred[index]=hit;hits+=int(hit);misses+=int(not hit)
   service=1 if hit else P['analytic_unknown_read_bound_cycles']
   # Earliest possible cancellation/capture is request issue. If the access
   # is conservatively charged unknown but actually hits, this still covers
   # WUs during its buffered response. A miss captures no earlier than issue.
   rem[value]=retention(k)
   elapsed+=service;rem=[r-service for r in rem]
 compute=sum(v for op,v in ops if op=='compute')
 budget=compute+.6*(hits+misses)*P['analytic_unknown_read_bound_cycles']+2*P['switch_cycles']
 return {'bound':elapsed,'budget':budget,'feasible':elapsed<=budget,'hits':hits,
         'unknown':misses,'switches':switches,'predictions':pred}

def simulate(ops,ks,writer_gap,phi,analysis=None,keep_trace=False,writer_count=None,phase_policy=None,admission_guard=True):
 writer_count=writer_count or P['writer_store_count']
 ks=list(ks)
 analysis=analysis or analyze(ops,ks)
 n=P['shared_blocks']
 valid=[False]*n;active=[False]*n;count=[0]*n;data=[0]*n;version=[0]*n;shared=[False]*n
 ip=0;rready=0;rwaiting=False;rhit_due=None;config_due=None;k=ks[0]
 windex=0;wready=0;wwaiting=False;private_due=None
 rq=None;wq=None;bus=None;last=1
 packets=deliveries=misses=hits=unsafe=0;read_done=write_done=None;max_read_service=max_update_service=0
 read_issue=None;trace=[]
 t=0
 def finish_read(now):
  nonlocal rwaiting,rready,max_read_service
  rwaiting=False;rready=now
  max_read_service=max(max_read_service,now-read_issue)
 while read_done is None or write_done is None:
  if t>200000:raise RuntimeError('simulation watchdog')
  if config_due is not None and config_due[0]==t:
   k=config_due[1];config_due=None;rwaiting=False;rready=t
  if bus is not None and bus['end']==t:
   b=bus['block']
   if bus['kind']=='wu':
    version[b]+=1;packets+=1
    if valid[b]:
     data[b]=version[b];active[b]=(k!=255);count[b]=(k if k!=255 else 0);deliveries+=1
    shared[b]=valid[b];windex+=1;wwaiting=False;wready=t+writer_gap
    max_update_service=max(max_update_service,t-bus['issue'])
   else:
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
     if count[b]==0:active[b]=False;valid[b]=False
  if rhit_due is not None and rhit_due[0]==t:
   # The response payload is a snapshot captured before any intervening WU.
   assert rhit_due[1]==rhit_due[2]
   rhit_due=None;finish_read(t)
  if windex==writer_count and write_done is None:write_done=t
  if ip==len(ops) and not rwaiting and t>=rready and read_done is None:read_done=t
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
     if phase_policy is not None:
      choice,completion=phase_policy(tuple(ks[:v]),{'phase':v,'t':t,
        'writer_completed':windex,'writer_total':writer_count,
        'receiver_hits':hits,'receiver_misses':misses,'deliveries':deliveries})
      ks[v]=choice
      analysis=analyze(ops,completion)
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
  t+=1
 assert sum(version)==writer_count
 assert read_done<=analysis['bound'],(read_done,analysis,ks)
 assert max_read_service<=P['analytic_unknown_read_bound_cycles'] and max_update_service<=P['analytic_unknown_read_bound_cycles'],(max_read_service,max_update_service)
 return {'K':list(ks),'phi':phi,'reader_cycles':read_done,'reader_bound':analysis['bound'],
         'writer_cycles':write_done,'makespan':max(read_done,write_done),
         'updates':packets,'deliveries':deliveries,'actual_misses':misses,'actual_hits':hits,
         'analysis_hits':analysis['hits'],'analysis_unknown':analysis['unknown'],
         'max_read_service':max_read_service,'max_update_service':max_update_service,
         'unsafe_hits':unsafe,'trace':trace if keep_trace else None}

def main():
 start=time.perf_counter();records=[]
 for kind,quiet,gap in product(P['families'],P['quiet_compute'],P['writer_compute_gaps']):
  ops=instructions(kind,quiet);admitted=[];reset_admitted=0
  for ks in product(P['domain'],repeat=3):
   a=analyze(ops,ks);reset_admitted+=int(analyze(ops,ks,True)['feasible'])
   if a['feasible']:admitted.append((ks,a))
  results=[simulate(ops,ks,gap,0,a) for ks,a in admitted]
  def choose(values):return min(values,key=lambda r:(r['makespan'],r['reader_cycles'],r['updates'],r['K'])) if values else None
  fixed_candidates=[]
  for kfixed in range(1,256):
   ksf=(kfixed,)*3;af=analyze(ops,ksf)
   if af['feasible']:fixed_candidates.append(simulate(ops,ksf,gap,0,af))
  fixed=choose(fixed_candidates);phased=choose(results)
  heldout=[]
  if phased and fixed:
   for phi in P['heldout_decrement_phases']:
    heldout.append({'phi':phi,'fixed':simulate(ops,tuple(fixed['K']),gap,phi),
                    'phased':simulate(ops,tuple(phased['K']),gap,phi)})
  records.append({'case':f'{kind}-q{quiet}-w{gap}','kind':kind,'quiet':quiet,'writer_gap':gap,
                  'feasible_paths':len(admitted),'reset_feasible_paths':reset_admitted,
                  'fixed_encodings_tested':255,'feasible_fixed_encodings':len(fixed_candidates),
                  'fixed':fixed,'phased':phased,'heldout':heldout})
 summary={'cases':len(records),'both_feasible':sum(bool(c['fixed'] and c['phased']) for c in records),
          'improved_makespan':sum(c['phased']['makespan']<c['fixed']['makespan'] for c in records if c['fixed'] and c['phased']),
          'heldout_regressions':sum(h['phased']['makespan']>h['fixed']['makespan'] for c in records for h in c['heldout']),
          'heldout_improvements':sum(h['phased']['makespan']<h['fixed']['makespan'] for c in records for h in c['heldout'])}
 result={'protocol_sha256':hashlib.sha256((HERE/'closed_loop_protocol.json').read_bytes()).hexdigest(),
         'source_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),'records':records,'summary':summary,'elapsed_seconds':time.perf_counter()-start}
 (HERE/'CLOSED_LOOP_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps({'summary':summary,'seconds':result['elapsed_seconds']},indent=2))
 for c in records:
  print(c['case'],'paths',c['feasible_paths'],c['reset_feasible_paths'],'fixed',c['fixed'] and c['fixed']['K'],c['fixed'] and c['fixed']['makespan'],'phase',c['phased'] and c['phased']['K'],c['phased'] and c['phased']['makespan'])
if __name__=='__main__':main()
