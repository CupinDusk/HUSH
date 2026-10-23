from pathlib import Path
from itertools import product
import json,time,hashlib
import interlocked_model as c
HERE=Path(__file__).resolve().parent
protocol=json.loads((HERE/'tight_budget_protocol.json').read_text())
old=json.loads((HERE/'sensitivity_protocol.json').read_text());base=dict(c.P);specs=[]
for family,n,g,p in product(*old['main_cross_product'].values()):
 specs.append(dict(family=family,shared_blocks=n,receiver_compute_gap=g,period=p))
ref=dict(old['secondary_one_factor']['reference'])
for field,values in old['secondary_one_factor'].items():
 if field=='reference':continue
 for v in values:
  s=dict(ref);s[field if field!='writer_compute_gaps' else 'writer_gap']=v;specs.append(s)
source_hash=hashlib.sha256((HERE/'interlocked_model.py').read_bytes()).hexdigest()
rows=[];start=time.perf_counter()
def select(xs,budget,key='bound'):
 vals=[r for r in xs if r[key]<=budget]
 return min(vals,key=lambda r:(r['execution']['makespan'],r['execution']['reader_cycles'],r['execution']['updates'],r['execution']['K'])) if vals else None
for i,s in enumerate(specs):
 c.P.clear();c.P.update(base);c.P.update({k:v for k,v in s.items() if k in base})
 q=c.P['shared_blocks'];c.P['receiver_dense_reads']=8*q;c.P['writer_store_count']=64*q
 c.P['analytic_unknown_read_bound_cycles']=c.P['update_slot_cycles']+1+c.P['miss_slot_cycles']
 ops=c.instructions(s['family'],512);gap=s.get('writer_gap',4)
 compute=sum(v for op,v in ops if op=='compute');nr=sum(op=='read' for op,v in ops)
 minimum=compute+q*c.P['analytic_unknown_read_bound_cycles']+(nr-q)
 candidates=[];fixed=[];maintenance=[]
 paths=sorted(set(product(c.P['domain'],repeat=3))|{(k,)*3 for k in range(1,256)})
 for ks in paths:
  a=c.analyze(ops,ks);r=c.simulate(ops,ks,gap,0,a,flush_at_finish=True)
  item={'bound':a['bound'],'reset_bound':c.analyze(ops,ks,True)['bound'],'execution':r}
  candidates.append(item)
  if len(set(ks))==1:
   fixed.append(item);maintenance.append(item)
   for mask in [(1,),(2,),(1,2)]:
    af=c.analyze(ops,ks,flush_at_boundaries=mask)
    rf=c.simulate(ops,ks,gap,0,af,flush_at_boundaries=mask,flush_at_finish=True)
    maintenance.append({'bound':af['bound'],'flush_boundaries':mask,'execution':rf})
 points=[]
 for slack in protocol['slack_cycles']:
  b=minimum+slack
  points.append({'slack':slack,'budget':b,'phase':select(candidates,b),'reset':select(candidates,b,'reset_bound'),
   'fixed':select(fixed,b),'fixed_maintenance':select(maintenance,b),
   'carry_paths':sum(r['bound']<=b for r in candidates),'reset_paths':sum(r['reset_bound']<=b for r in candidates)})
  assert all(points[-1][k] is not None for k in ['phase','reset','fixed','fixed_maintenance'])
 rows.append({'spec':s,'parameters':dict(c.P),'minimum_bound':minimum,'points':points})
 if (i+1)%10==0:print(f'{i+1}/{len(specs)}; {time.perf_counter()-start:.1f}s',flush=True)
assert source_hash==hashlib.sha256((HERE/'interlocked_model.py').read_bytes()).hexdigest()
ps=[p for r in rows for p in r['points']]
summary={'cases':len(rows),'points':len(ps),
 'phase_beats_fixed':sum(p['phase']['execution']['makespan']<p['fixed']['execution']['makespan'] for p in ps),
 'phase_beats_maintenance':sum(p['phase']['execution']['makespan']<p['fixed_maintenance']['execution']['makespan'] for p in ps),
 'phase_loses_maintenance':sum(p['phase']['execution']['makespan']>p['fixed_maintenance']['execution']['makespan'] for p in ps),
 'carry_beats_reset':sum(p['phase']['execution']['makespan']<p['reset']['execution']['makespan'] for p in ps),
 'carry_adds_paths':sum(p['carry_paths']>p['reset_paths'] for p in ps)}
result={'protocol_sha256':hashlib.sha256((HERE/'tight_budget_protocol.json').read_bytes()).hexdigest(),
 'model_sha256':source_hash,'source_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
 'rows':rows,'summary':summary,'elapsed_seconds':time.perf_counter()-start}
(HERE/'INTERLOCKED_TIGHT_BUDGET_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'summary':summary,'seconds':result['elapsed_seconds']},indent=2))
