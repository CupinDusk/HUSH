"""Original-model parity and a deliberately unsafe replacement ablation."""
from itertools import product
from pathlib import Path
import hashlib,json
import original_model as old
import replacement_model as new
V=Path(__file__).resolve().parent
base=dict(new.P);checks=0
for n,period,ks,phi in product([2,4,8],[2,10],[(254,4,4),(32,4,1),(32,32,32),(255,255,255)],[0,1]):
 for module in [old,new]:
  module.P.clear();module.P.update(base,shared_blocks=n,period=period,receiver_dense_reads=8*n,writer_store_count=64*n)
 ops=old.instructions('BSQ',512)
 a=old.analyze(ops,ks);b=new.analyze(ops,ks,cache_sets=n,cache_ways=1)
 for key in ['bound','hits','unknown','switches','predictions']:assert a[key]==b[key],key
 r=old.simulate(ops,ks,4,phi,a,flush_at_finish=True)
 s=new.simulate(ops,ks,4,phi,b,flush_at_finish=True,cache_sets=n,cache_ways=1)
 assert {k:v for k,v in s.items() if k!='replacement_evictions'}==r
 checks+=1
# A protected-slot classifier must fail on a conflicting finite cache.
new.P.clear();new.P.update(base,shared_blocks=3,writer_store_count=24)
ops=[('phase',0),('read',0),('read',1),('read',0),('read',2),('read',1)]
unsafe=new.analyze(ops,(255,255,255))
rejected=False
try:new.simulate(ops,(255,255,255),4,0,unsafe,cache_sets=1,cache_ways=1)
except AssertionError:rejected=True
assert rejected
safe=new.analyze(ops,(255,255,255),cache_sets=1,cache_ways=1)
safe_run=new.simulate(ops,(255,255,255),4,0,safe,cache_sets=1,cache_ways=1)
assert safe['hits']==0 and safe_run['unsafe_hits']==0 and safe_run['replacement_evictions']>0
ops_flush=[('phase',0),('read',0),('read',1),('phase',1),('read',0),('phase',2),('read',1)]
flush_run=new.simulate(ops_flush,(255,255,255),4,0,flush_at_boundaries=True,cache_sets=2,cache_ways=2)
assert flush_run['analysis_unknown']==4 and flush_run['actual_misses']==4 and flush_run['unsafe_hits']==0
result={'parity_configurations':checks,'all_original_predictions_and_execution_metrics_match':True,
 'protected_classifier_rejected_on_conflicting_cache':True,
 'replacement_aware_classifier_safe':True,'safe_example':safe_run,'automatic_analysis_boundary_flush_safe':True,
 'driver_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest()}
(V/'EXTENSION_CHECK.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
