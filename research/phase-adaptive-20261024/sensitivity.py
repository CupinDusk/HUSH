"""Prespecified architecture-model sensitivity, including failed admissions."""
from pathlib import Path
from itertools import product
import json,hashlib,time
import closed_loop as c
HERE=Path(__file__).resolve().parent
proto=json.loads((HERE/'sensitivity_protocol.json').read_text())
base=dict(c.P);specs=[]
for family,n,g,p in product(*proto['main_cross_product'].values()):
 specs.append(dict(family=family,shared_blocks=n,receiver_compute_gap=g,period=p))
ref=dict(proto['secondary_one_factor']['reference'])
for field,values in proto['secondary_one_factor'].items():
 if field=='reference':continue
 for value in values:
  s=dict(ref);s[field if field!='writer_compute_gaps' else 'writer_gap']=value;specs.append(s)
rows=[];start=time.perf_counter()
def best(candidates,budget):
 permitted=[r for r in candidates if r['reader_bound']<=budget]
 return min(permitted,key=lambda r:(r['makespan'],r['reader_cycles'],r['updates'],r['K'])) if permitted else None
for i,s in enumerate(specs):
 c.P.clear();c.P.update(base);c.P.update({k:v for k,v in s.items() if k in base})
 n=c.P['shared_blocks'];c.P['receiver_dense_reads']=8*n;c.P['writer_store_count']=64*n
 c.P['analytic_unknown_read_bound_cycles']=c.P['update_slot_cycles']+1+c.P['miss_slot_cycles']
 ops=c.instructions(s['family'],512);gap=s.get('writer_gap',4)
 compute=sum(v for op,v in ops if op=='compute');reads=sum(op=='read' for op,v in ops)
 dynamic=[];fixed=[];reset_bounds={}
 for ks in product(proto['dynamic_domain'],repeat=3):
  a=c.analyze(ops,ks);r=c.simulate(ops,ks,gap,0,a)
  dynamic.append(r);reset_bounds[ks]=c.analyze(ops,ks,True)['bound']
 for k in range(1,256):
  fixed.append(c.simulate(ops,(k,k,k),gap,0))
 points=[]
 for f in proto['budget_fractions']:
  b=compute+f*reads*71+2
  reset=[dict(r,reader_bound=reset_bounds[tuple(r['K'])]) for r in dynamic]
  points.append({'fraction':f,'budget':b,'fixed':best(fixed,b),'phase':best(dynamic,b),'reset':best(reset,b),
   'carry_paths':sum(r['reader_bound']<=b for r in dynamic),
   'reset_paths':sum(reset_bounds[tuple(r['K'])]<=b for r in dynamic)})
 main=next(p for p in points if p['fraction']==.6);holdout=None
 if main['fixed'] and main['phase']:
  holdout={name:c.simulate(ops,tuple(main[name]['K']),gap,c.P['period']-1) for name in ['fixed','phase']}
 rows.append({'spec':s,'parameters':dict(c.P),'points':points,'heldout':holdout})
 if (i+1)%10==0:print(f'{i+1}/{len(specs)} cases; {time.perf_counter()-start:.1f}s',flush=True)
points=[p for r in rows for p in r['points']]
both=[p for p in points if p['fixed'] and p['phase']]
summary={'cases':len(rows),'budget_points':len(points),'both_feasible':len(both),
 'phase_only_feasible':sum(p['phase'] is not None and p['fixed'] is None for p in points),
 'fixed_only_feasible':sum(p['fixed'] is not None and p['phase'] is None for p in points),
 'neither_feasible':sum(p['fixed'] is None and p['phase'] is None for p in points),
 'improve':sum(p['phase']['makespan']<p['fixed']['makespan'] for p in both),
 'tie':sum(p['phase']['makespan']==p['fixed']['makespan'] for p in both),
 'regress':sum(p['phase']['makespan']>p['fixed']['makespan'] for p in both),
 'carry_adds_paths':sum(p['carry_paths']>p['reset_paths'] for p in points),
 'carry_better_than_reset':sum(p['phase'] is not None and (p['reset'] is None or p['phase']['makespan']<p['reset']['makespan']) for p in points),
 'heldout_cases':sum(r['heldout'] is not None for r in rows),
 'heldout_regressions':sum(r['heldout']['phase']['makespan']>r['heldout']['fixed']['makespan'] for r in rows if r['heldout'])}
result={'protocol_sha256':hashlib.sha256((HERE/'sensitivity_protocol.json').read_bytes()).hexdigest(),
 'model_sha256':hashlib.sha256((HERE/'closed_loop.py').read_bytes()).hexdigest(),
 'source_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
 'rows':rows,'summary':summary,'elapsed_seconds':time.perf_counter()-start}
(HERE/'SENSITIVITY_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'summary':summary,'elapsed_seconds':result['elapsed_seconds']},indent=2))
