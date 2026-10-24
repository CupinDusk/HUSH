"""Same complete source-event path: observed work vs carry/reset bounds."""
from pathlib import Path
import json,hashlib
import replacement_model as m
HERE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
assert sha(HERE/'replacement_model.py')=='6270a7fa1c79a81dab99f9712e170c60c1ded14dd5052f3b987ba421a1b99e10'
assert {k:m.P[k] for k in ['update_slot_cycles','miss_slot_cycles','analytic_unknown_read_bound_cycles','switch_cycles']}=={
 'update_slot_cycles':10,'miss_slot_cycles':60,'analytic_unknown_read_bound_cycles':71,'switch_cycles':1}
trace=json.loads((HERE/'ALL_DATA_TRACE.json').read_text());ops=[];stage='prepare'
for e in trace:
 if e[0]=='S':stage=e[1]
 elif e[0]=='P':
  stage='body';p=int(e[1])
  ops.extend(([('compute',4)] if p else [])+[('phase',p)])
 elif e[0]=='D' and stage=='body':
  ops.append(('compute',1))
  if e[1:3]==['R','array']:ops.append(('read',(int(e[3])*4)//64))
  else:ops.append(('compute',1))
m.P.update(shared_blocks=3,writer_store_count=192,period=10)
ks=(254,16,1);a=m.analyze(ops,ks,cache_sets=1,cache_ways=2)
reset=m.analyze(ops,ks,reset=True,cache_sets=1,cache_ways=2);rows=[]
for phi in range(10):
 r=m.simulate(ops,ks,4,phi,a,writer_count=192,flush_at_finish=True,cache_sets=1,cache_ways=2)
 rows.append({'phi':phi,'reader_body':r['reader_cycles'],'receiver_work_observed':r['reader_cycles']+372,
 'bound':a['bound']+372,'reset_bound':reset['bound']+372,'joint':r['makespan']+372,
 'actual_hits':r['actual_hits'],'evictions':r['replacement_evictions'],'unsafe_hits':r['unsafe_hits']})
out={'model_sha256':sha(HERE/'replacement_model.py'),'input_trace_sha256':sha(HERE/'ALL_DATA_TRACE.json'),
 'K':ks,'compute_gap':1,'private_service':1,'helper_delta':4,'preparation_cleanup':372,
 'cache_sets':1,'cache_ways':2,'writer_count':192,'writer_gap':4,'bound':a['bound']+372,
 'reset_bound':reset['bound']+372,'rows':rows,'observed_receiver_work_max':max(r['receiver_work_observed'] for r in rows)}
assert out['bound']==1854 and out['reset_bound']==1994
assert all(r['receiver_work_observed']==1818 and not r['unsafe_hits'] for r in rows)
(HERE/'SAME_PATH_OBSERVATION_CHECK.json').write_text(json.dumps(out,indent=2)+'\n')
print('All ten phases: observed receiver work1818; bound1854; reset1994; no unsafe hit.')
