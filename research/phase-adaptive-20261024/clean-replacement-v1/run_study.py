"""Declared replacement checks and separate static-bound/efficiency evidence."""
from pathlib import Path
from itertools import product
import csv,hashlib,json,time
import replacement_model as m

V=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
base=dict(m.P)
POLICIES=[(254,4,4),(254,16,1),(32,4,1),(32,16,4),(4,4,4),(32,32,32),(255,255,255)]
GEOMETRIES=[(1,1),(1,2),(2,2),(4,2)]
protocol={
 'scope':'Finite clean receiver cache, known local read sequence; same bounded service as base; no receiver dirty writes, writer eviction, LLC or DRAM claims.',
 'families':['BSQ','DQD'],'shared_blocks':[2,4,8],'compute_gaps':[1,4],'periods':[2,10],
 'cache_geometries':GEOMETRIES,'policies':POLICIES,'tick_phases':'0 and P-1',
 'writer_stores_per_block':64,'writer_gap':4,'quiet_cycles':512,
 'fixed_phase_flush':False,'free_end_release':True,
 'FIR2DIM':'145 actual input reads, three source markers; model compute/refresh timings remain explicit assumptions',
 'metrics':'Predicted/actual hits, per-access service bound and reader bound, clean evictions; no configuration-selection speedup claim.'}
(V/'STUDY_PROTOCOL.json').write_text(json.dumps(protocol,indent=2)+'\n')
start=time.perf_counter();rows=[]
def record(name,ops,ks,sets,ways,gap,phi,compute):
 a=m.analyze(ops,ks,cache_sets=sets,cache_ways=ways)
 reset=m.analyze(ops,ks,reset=True,cache_sets=sets,cache_ways=ways)
 r=m.simulate(ops,ks,gap,phi,a,flush_at_finish=True,cache_sets=sets,cache_ways=ways)
 assert r['unsafe_hits']==0 and r['reader_cycles']<=a['bound']
 assert reset['bound']>=a['bound']
 overhead=a['switches']*m.P['switch_cycles']
 row={'family':name,'blocks':m.P['shared_blocks'],'compute_gap':compute,
  'period':m.P['period'],'sets':sets,'ways':ways,'slots':sets*ways,'K':list(ks),'writer_gap':gap,'phi':phi,
  'compute_bound':sum(v for op,v in ops if op=='compute'),'configuration_bound':overhead,
  'reader_bound':a['bound'],'memory_bound':a['bound']-sum(v for op,v in ops if op=='compute')-overhead,
  'reset_reader_bound':reset['bound'],'reset_memory_bound':reset['bound']-sum(v for op,v in ops if op=='compute')-overhead,
  **{k:r[k] for k in ['reader_cycles','makespan','updates','replacement_evictions','analysis_hits','analysis_unknown','actual_hits','actual_misses','max_read_service','unsafe_hits']}}
 rows.append(row)

for family,n,g,period,(sets,ways),ks in product(protocol['families'],[2,4,8],[1,4],[2,10],GEOMETRIES,POLICIES):
 m.P.clear();m.P.update(base,shared_blocks=n,receiver_dense_reads=8*n,receiver_compute_gap=g,writer_store_count=64*n,period=period)
 ops=m.instructions(family,512)
 for phi in [0,period-1]:record(family,ops,ks,sets,ways,4,phi,g)
print('synthetic complete',len(rows),flush=True)
trace=json.loads((V/'fir2dim-read-trace.json').read_text())
assert sum(k=='R' for k,v in trace)==145 and [v for k,v in trace if k=='P']==[0,1,2]
for compute,gap,(sets,ways),ks in product([1,4,16],[0,4,16],[(1,1),(1,2),(1,4),(2,1),(2,2),(4,1)],[(254,4,4),(254,16,1),(32,32,32),(255,255,255)]):
 m.P.clear();m.P.update(base,shared_blocks=3,writer_store_count=192)
 ops=[]
 for k,v in trace:
  if k=='P':ops.append(('phase',v))
  else:ops.extend([('compute',compute),('read',(4*v)//64)])
 for phi in [0,9]:record('FIR2DIM',ops,ks,sets,ways,gap,phi,compute)
summary={'runs':len(rows),'synthetic_runs':sum(r['family']!='FIR2DIM' for r in rows),
 'FIR2DIM_runs':sum(r['family']=='FIR2DIM' for r in rows),
 'runs_with_clean_evictions':sum(r['replacement_evictions']>0 for r in rows),
 'clean_evictions':sum(r['replacement_evictions'] for r in rows),
 'predicted_hits_checked':sum(r['analysis_hits'] for r in rows),
 'unsafe_hits':sum(r['unsafe_hits'] for r in rows),
 'reader_bound_violations':sum(r['reader_cycles']>r['reader_bound'] for r in rows),
 'service_bound_violations':sum(r['max_read_service']>base['analytic_unknown_read_bound_cycles'] for r in rows),
 'carry_in_strict_bound_improvements':sum(r['memory_bound']<r['reset_memory_bound'] for r in rows)}
result={'protocol_sha256':sha(V/'STUDY_PROTOCOL.json'),'model_sha256':sha(V/'replacement_model.py'),
 'driver_sha256':sha(Path(__file__)),'trace_sha256':sha(V/'fir2dim-read-trace.json'),
 'summary':summary,'elapsed_seconds':time.perf_counter()-start,'rows':rows}
(V/'REPLACEMENT_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n')
with (V/'REPLACEMENT_ROWS.csv').open('w',newline='',encoding='utf-8') as f:
 w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
print(json.dumps({k:v for k,v in result.items() if k!='rows'},indent=2),flush=True)
