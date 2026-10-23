from pathlib import Path
from itertools import product
import json,hashlib,time
import interlocked_model as c
H=Path(__file__).resolve().parent
protocol=json.loads((H/'runtime_cost_protocol.json').read_text())
start=time.perf_counter();rows=[]
for kind,quiet,gap in product(c.P['families'],c.P['quiet_compute'],c.P['writer_compute_gaps']):
 base_ops=c.instructions(kind,quiet)
 budget=c.analyze(base_ops,(255,)*3)['budget']
 for stores in protocol['writer_store_counts']:
  controls=[]
  for k,mask in product(range(1,256),[(),(1,),(2,),(1,2)]):
   ks=(k,)*3;a=c.analyze(base_ops,ks,flush_at_boundaries=mask)
   if a['bound']>budget:continue
   r=c.simulate(base_ops,ks,gap,0,a,writer_count=stores,flush_at_finish=True,flush_at_boundaries=mask)
   controls.append((r,mask))
  fixed,mask=min(controls,key=lambda rm:(rm[0]['makespan'],rm[0]['reader_cycles'],rm[0]['updates'],rm[0]['K'],rm[1]))
  preferred=fixed['K'][0];domain=sorted(set(c.P['domain'])|{preferred})
  baseline=[]
  for phi in protocol['tick_phases']:
   a=c.analyze(base_ops,(preferred,)*3,flush_at_boundaries=mask)
   baseline.append(c.simulate(base_ops,(preferred,)*3,gap,phi,a,writer_count=stores,flush_at_finish=True,flush_at_boundaries=mask))
  for delta in protocol['helper_cycles_per_noninitial_marker']:
   ops=[]
   for op,value in base_ops:
    if op=='phase' and value>0:ops.append(('compute',delta))
    ops.append((op,value))
   safe=[]
   for suffix in product(domain,repeat=2):
    ks=(preferred,)+suffix;a=c.analyze(ops,ks)
    if a['bound']<=budget:safe.append(ks)
   edges={}
   for ks in safe:
    for depth in range(3):edges.setdefault(ks[:depth],set()).add(ks[depth])
   calls=[]
   def policy(prefix,observed):
    choices=sorted(edges[prefix]);busy=observed['writer_completed']<observed['writer_total']
    k=min(choices) if observed['phase']==2 and busy else min(choices,key=lambda x:(abs(x-preferred),x))
    chosen=prefix+(k,);completion=next(ks for ks in safe if ks[:len(chosen)]==chosen)
    calls.append({'prefix':prefix,'observed':observed,'selected':k})
    return k,completion
   records=[]
   for phi,b in zip(protocol['tick_phases'],baseline):
    if safe:
     r=c.simulate(ops,(preferred,)*3,gap,phi,writer_count=stores,phase_policy=policy,flush_at_finish=True)
     assert r['reader_bound']<=budget and r['reader_cycles']<=budget
    else:r=dict(b)
    records.append({'phi':phi,'fixed':b,'runtime':r})
   rows.append({'case':f'{kind}-q{quiet}-w{gap}','writer_stores':stores,'helper_cycles':delta,
    'budget':budget,'preferred_fixed_k':preferred,'fixed_flush_boundaries':list(mask),'domain':domain,
    'safe_suffix_paths':len(safe),'mode':'runtime' if safe else 'offline_fixed_fallback','records':records,'policy_calls':calls})
summary=[]
for delta in protocol['helper_cycles_per_noninitial_marker']:
 rs=[r for r in rows if r['helper_cycles']==delta]
 pairs=[z for r in rs for z in r['records']]
 summary.append({'helper_cycles':delta,'runs':len(pairs),'improve':sum(z['runtime']['makespan']<z['fixed']['makespan'] for z in pairs),
  'tie':sum(z['runtime']['makespan']==z['fixed']['makespan'] for z in pairs),'regress':sum(z['runtime']['makespan']>z['fixed']['makespan'] for z in pairs),
  'offline_fallback_runs':sum(len(r['records']) for r in rs if r['mode']=='offline_fixed_fallback'),
  'largest_regression_fraction':max(z['runtime']['makespan']/z['fixed']['makespan']-1 for z in pairs)})
result={'protocol_sha256':hashlib.sha256((H/'runtime_cost_protocol.json').read_bytes()).hexdigest(),
 'model_sha256':hashlib.sha256((H/'interlocked_model.py').read_bytes()).hexdigest(),
 'study_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),'summary':summary,'rows':rows,'elapsed_seconds':time.perf_counter()-start}
(H/'RUNTIME_COST_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(summary,indent=2),flush=True)
