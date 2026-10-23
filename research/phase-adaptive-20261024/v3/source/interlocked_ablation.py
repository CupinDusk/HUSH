"""Admission and runtime ablations following first PDF-only peer review."""
from pathlib import Path
from itertools import product
import json,time,hashlib
import interlocked_model as c
HERE=Path(__file__).resolve().parent
protocol={'date':'2026-10-24','status':'prospective_before_closed_loop_ablation',
 'budget_fractions':[0.1,0.2,0.3,0.4,0.6,1.0],
 'writer_store_counts':[16,256],
 'online_policy':'choose the smallest certified successor in the last phase only if the writer still has unfinished work; otherwise prefer the best fixed load. Earlier phases prefer that fixed load. Only past completion count is observed.',
 'signals':'one externally supplied writer-work-remaining flag at program phase entry; producer of that flag is outside timer RTL',
 'domain':c.P['domain'],'fixed_domain':'all1..255',
 'purpose':'quantify carry-in admission and useful runtime execution; report receiver cost and makespan separately'}
p=HERE/'closed_loop_ablation_protocol.json'
if not p.exists():p.write_text(json.dumps(protocol,indent=2)+'\n')
start=time.perf_counter();records=[]
for kind,quiet,gap in product(c.P['families'],c.P['quiet_compute'],c.P['writer_compute_gaps']):
 ops=c.instructions(kind,quiet);compute=sum(v for op,v in ops if op=='compute');nr=sum(op=='read' for op,v in ops)
 analyzed={ks:(c.analyze(ops,ks),c.analyze(ops,ks,True)) for ks in product(c.P['domain'],repeat=3)}
 simulated={ks:c.simulate(ops,ks,gap,0,a) for ks,(a,b) in analyzed.items()}
 admission=[]
 for f in protocol['budget_fractions']:
  budget=compute+f*nr*71+2
  safe=[ks for ks,(a,b) in analyzed.items() if a['bound']<=budget]
  reset=[ks for ks,(a,b) in analyzed.items() if b['bound']<=budget]
  assert set(reset)<=set(safe)
  best=lambda paths:min((simulated[ks]['makespan'] for ks in paths),default=None)
  admission.append({'fraction':f,'budget':budget,'carry_paths':len(safe),'reset_paths':len(reset),
                    'carry_only_paths':len(set(safe)-set(reset)),
                    'best_carry_makespan':best(safe),'best_reset_makespan':best(reset)})
 safe=[ks for ks,(a,b) in analyzed.items() if a['feasible']]
 edges={}
 for ks in safe:
  for depth in range(3):edges.setdefault(ks[:depth],set()).add(ks[depth])
 runtime=[]
 for nw in protocol['writer_store_counts']:
  fixed=[]
  for kk in range(1,256):
   ks=(kk,)*3;a=c.analyze(ops,ks)
   if a['feasible']:fixed.append(c.simulate(ops,ks,gap,0,a,writer_count=nw))
  bestfixed=min(fixed,key=lambda r:(r['makespan'],r['reader_cycles'],r['updates'],r['K']))
  # Prefer the nearest available certified load; hardware encodings are not
  # assumed identical between sampled dynamic domain and full fixed domain.
  preferred=bestfixed['K'][0]
  online_domain=sorted(set(c.P['domain'])|{preferred})
  safe_online=[ks for ks in product(online_domain,repeat=3) if c.analyze(ops,ks)['feasible']]
  online_edges={}
  for ks in safe_online:
   for depth in range(3):online_edges.setdefault(ks[:depth],set()).add(ks[depth])
  call_records=[]
  def policy(prefix,observed):
   opts=sorted(online_edges[prefix]);last=observed['phase']==2
   k=min(opts) if last and observed['writer_completed']<observed['writer_total'] else min(opts,key=lambda k:(abs(k-preferred),k))
   prefix2=prefix+(k,)
   completion=next(ks for ks in safe_online if ks[:len(prefix2)]==prefix2)
   call_records.append({'prefix':list(prefix),'observed':dict(observed),'selected_K':k})
   return k,completion
  online=[];fixed_phases=[]
  for phi in range(10):
   # The initial register is initialized to the first permitted preferred
   # value. Selection at later boundaries uses no future requests or trace.
   initial=preferred
   online.append(c.simulate(ops,(initial,initial,initial),gap,phi,
                            writer_count=nw,phase_policy=policy))
   fixed_phases.append(c.simulate(ops,tuple(bestfixed['K']),gap,phi,writer_count=nw))
  runtime.append({'writer_count':nw,'selected_fixed_K':bestfixed['K'],'online_domain':online_domain,
                  'online':online,'fixed':fixed_phases,'policy_calls':call_records})
 records.append({'case':f'{kind}-q{quiet}-w{gap}','admission':admission,'runtime':runtime,
                 'candidate_summaries':[{'K':ks,'carry_bound':a['bound'],'reset_bound':b['bound'],
                                         'makespan':simulated[ks]['makespan'],'carry_hits':a['hits'],'reset_hits':b['hits']}
                                        for ks,(a,b) in analyzed.items()]})
summary={'admission_points':sum(len(r['admission']) for r in records),
 'points_with_carry_only_paths':sum(a['carry_only_paths']>0 for r in records for a in r['admission']),
 'points_with_better_carry_makespan':sum(a['best_carry_makespan'] is not None and (a['best_reset_makespan'] is None or a['best_carry_makespan']<a['best_reset_makespan']) for r in records for a in r['admission']),
 'online_runs':sum(len(x['online']) for r in records for x in r['runtime']),
 'online_makespan_improvements':sum(a['makespan']<b['makespan'] for r in records for x in r['runtime'] for a,b in zip(x['online'],x['fixed'])),
 'online_makespan_regressions':sum(a['makespan']>b['makespan'] for r in records for x in r['runtime'] for a,b in zip(x['online'],x['fixed']))}
result={'protocol_sha256':hashlib.sha256(p.read_bytes()).hexdigest(),
 'model_sha256':hashlib.sha256((HERE/'interlocked_model.py').read_bytes()).hexdigest(),
 'records':records,'summary':summary,'elapsed_seconds':time.perf_counter()-start}
(HERE/'INTERLOCKED_CLOSED_LOOP_ABLATION.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'summary':summary,'seconds':result['elapsed_seconds']},indent=2))
for r in records:
 print(r['case'],'carry',[(a['fraction'],a['carry_only_paths'],a['best_carry_makespan'],a['best_reset_makespan']) for a in r['admission'] if a['carry_only_paths']])
