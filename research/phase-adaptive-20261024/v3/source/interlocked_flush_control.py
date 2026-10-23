"""Strong optimistic controls: zero-cost clean release and boundary flush.
These are additional hardware operations, not claimed implemented by HUSH.
Compare like-for-like release to identify gains before reader completion.
"""
from pathlib import Path
from itertools import product
import interlocked_model as c
import json,time,hashlib
HERE=Path(__file__).resolve().parent
protocol={'status':'prospective_before_flush_control','date':'2026-10-24',
 'purpose':'test if phase gains merely reflect retaining receiver copies after task completion',
 'release':'optimistically invalidate all clean receiver slots and directory state at reader completion, zero cycles and no traffic charge',
 'boundary_flush':'same optimistic clean flush at each noninitial program phase, with fresh unknown analyzer state',
 'comparison':'all255 fixed loads, dynamic343 paths; both receive identical end release; fixed also receives optional boundary flush',
 'scope':'counterfactual controls only, not additional implemented protocol features'}
p=HERE/'flush_control_protocol.json'
if not p.exists():p.write_text(json.dumps(protocol,indent=2)+'\n')
rows=[];start=time.perf_counter()
for kind,quiet,gap in product(c.P['families'],c.P['quiet_compute'],c.P['writer_compute_gaps']):
 ops=c.instructions(kind,quiet)
 def choose(xs):return min(xs,key=lambda r:(r['makespan'],r['reader_cycles'],r['updates'],r['K'])) if xs else None
 fixed=[];flush=[];phase=[]
 for k in range(1,256):
  ks=(k,)*3;a=c.analyze(ops,ks)
  if a['feasible']:fixed.append(c.simulate(ops,ks,gap,0,a,flush_at_finish=True))
  for mask in [(1,),(2,),(1,2)]:
   a=c.analyze(ops,ks,flush_at_boundaries=mask)
   if a['feasible']:
    r=c.simulate(ops,ks,gap,0,a,flush_at_boundaries=mask,flush_at_finish=True)
    r['flushed_boundaries']=mask;flush.append(r)
 for ks in product(c.P['domain'],repeat=3):
  a=c.analyze(ops,ks)
  if a['feasible']:phase.append(c.simulate(ops,ks,gap,0,a,flush_at_finish=True))
 rows.append({'case':f'{kind}-q{quiet}-w{gap}','fixed_end_release':choose(fixed),
              'fixed_boundary_flush_and_release':choose(flush),'phase_end_release':choose(phase)})
result={'protocol_sha256':hashlib.sha256(p.read_bytes()).hexdigest(),
 'model_sha256':hashlib.sha256((HERE/'interlocked_model.py').read_bytes()).hexdigest(),
 'rows':rows,'elapsed_seconds':time.perf_counter()-start}
(HERE/'INTERLOCKED_FLUSH_CONTROL_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n')
for r in rows:print(r['case'],[(key,None if not r[key] else (r[key]['K'],r[key]['makespan'],r[key]['reader_cycles'],r[key]['actual_misses'])) for key in ['fixed_end_release','fixed_boundary_flush_and_release','phase_end_release']])
