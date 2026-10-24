"""Prespecified full source-event accounting; no native timing interpretation."""
from pathlib import Path
from itertools import product
from collections import Counter
import json,csv,time,hashlib,shutil
HERE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
protocol=json.loads((HERE/'PROTOCOL.json').read_text(encoding='utf-8-sig'))
import replacement_model as m
base=dict(m.P)
events=json.loads((HERE/'ALL_DATA_TRACE.json').read_text())
prepare=[];body=[];cleanup=[];stage='prepare'
for e in events:
 if e[0]=='S':stage=e[1]
 elif e[0]=='P':stage='body';body.append(e)
 elif e[0]=='D':{'prepare':prepare,'body':body,'cleanup':cleanup}[stage].append(e)
assert len(prepare)==len(cleanup)==93 and sum(e[0]=='D' for e in body)==596
assert sum(e[:3]==['D','R','array'] for e in body)==145

def instructions(gap,phase):
 ops=[]
 for e in body:
  if e[0]=='P':
   p=int(e[1])
   if phase and p>0:ops.append(('compute',protocol['marker_helper_cycles']))
   ops.append(('phase',p))
  else:
   # Gap is a supplied comprehensive non-data bound for this source interval,
   # including arithmetic/control/stack/fetch. The trace does not measure it.
   ops.append(('compute',gap))
   if e[1:3]==['R','array']:ops.append(('read',(4*int(e[3]))//64))
   else:ops.append(('compute',protocol['private_data_service_cycles']))
 return ops

def analyze(ops,ks,sets,ways,flush=(),reset=False):
 return m.analyze(ops,ks,reset=reset,flush_at_boundaries=flush,cache_sets=sets,cache_ways=ways)

def execution(ops,ks,sets,ways,a,flush,phi):
 return m.simulate(ops,ks,protocol['writer_gap'],phi,a,writer_count=protocol['writer_stores'],
                   flush_at_boundaries=flush,flush_at_finish=True,cache_sets=sets,cache_ways=ways)

def choose(candidates):
 return min(candidates,key=lambda x:(x['execution']['makespan'],x['execution']['reader_cycles'],x['execution']['updates'],x['K'],x['flush'])) if candidates else None

start=time.perf_counter();rows=[];all_candidates=[];static_rows=[]
for gap,(sets,ways) in product(protocol['compute_cycles_per_source_data_interval'],protocol['geometries']):
 m.P.clear();m.P.update(base,period=protocol['period'],shared_blocks=3,writer_store_count=protocol['writer_stores'])
 fixedops=instructions(gap,False);phaseops=instructions(gap,True)
 serial=len(prepare+cleanup)*(gap+protocol['private_data_service_cycles'])
 known_fixed=sum(v for op,v in fixedops if op=='compute')
 known_phase=sum(v for op,v in phaseops if op=='compute')
 assert known_phase-known_fixed==2*protocol['marker_helper_cycles']
 analyses_fixed=[];analyses_phase=[]
 for k,flush in product(range(1,256),[(),(1,),(2,),(1,2)]):
  ks=(k,k,k);a=analyze(fixedops,ks,sets,ways,flush)
  analyses_fixed.append((ks,flush,a))
 for ks in product(protocol['phase_domain'],repeat=3):
  a=analyze(phaseops,ks,sets,ways)
  reset=analyze(phaseops,ks,sets,ways,reset=True)
  assert a['bound']<=reset['bound']
  static_rows.append({'compute_gap':gap,'sets':sets,'ways':ways,'K':ks,
       'carry_receiver_work_bound':serial+a['bound'],'reset_receiver_work_bound':serial+reset['bound'],
       'carry_memory_bound':a['bound']-known_phase-a['switches'],
       'reset_memory_bound':reset['bound']-known_phase-reset['switches']})
  analyses_phase.append((ks,(),a))
 # One phi=0 run per candidate, shared across budgets; selection is never
 # retuned to held-out decrement phases.
 fixedruns=[];phaseruns=[]
 maxbudget=max(protocol['task_budget_cycles'])
 for label,ops,analyses,out in [('fixed',fixedops,analyses_fixed,fixedruns),('phase',phaseops,analyses_phase,phaseruns)]:
  for ks,flush,a in analyses:
   if serial+a['bound']<=maxbudget:
    r=execution(ops,ks,sets,ways,a,flush,0)
    row={'policy':label,'compute_gap':gap,'sets':sets,'ways':ways,'K':ks,'flush':flush,
         'reader_bound_full':serial+a['bound'],'known_body_cycles':sum(v for op,v in ops if op=='compute'),
         'memory_bound':a['bound']-sum(v for op,v in ops if op=='compute')-a['switches'],
         'execution':r}
    out.append(row);all_candidates.append(row)
 for budget in protocol['task_budget_cycles']:
  fs=[x for x in fixedruns if x['reader_bound_full']<=budget]
  ps=[x for x in phaseruns if x['reader_bound_full']<=budget]
  f=choose(fs);p=choose(ps)
  row={'compute_gap':gap,'sets':sets,'ways':ways,'budget':budget,'serial_prepare_cleanup':serial,
       'compute_bound_full':782*gap,'private_access_bound_full':637,'marker_helper_bound':8,
       'fixed_admitted':len(fs),'phase_admitted':len(ps),'fixed':f,'phase':p,'heldout':[]}
  if f and p:
   # Re-run chosen vectors at ALL timing points, preserving training point.
   for phi in range(protocol['period']):
    fr=execution(fixedops,tuple(f['K']),sets,ways,analyze(fixedops,f['K'],sets,ways,f['flush']),f['flush'],phi)
    pa=analyze(phaseops,p['K'],sets,ways)
    pr=execution(phaseops,tuple(p['K']),sets,ways,pa,(),phi)
    reset=analyze(phaseops,p['K'],sets,ways,reset=True)
    row['heldout'].append({'phi':phi,'fixed_kernel_joint_cycles':serial+fr['makespan'],
       'phase_kernel_joint_cycles':serial+pr['makespan'],'fixed_receiver_cycles':serial+fr['reader_cycles'],
       'phase_receiver_cycles':serial+pr['reader_cycles'],'fixed':fr,'phase':pr,
       'phase_carry_memory_bound':pa['bound']-known_phase-pa['switches'],
       'phase_reset_memory_bound':reset['bound']-known_phase-reset['switches']})
  rows.append(row)
  print('case',gap,sets,ways,budget,'admitted',len(fs),len(ps),'best',f and [f['K'],f['flush'],f['execution']['makespan']+serial],p and [p['K'],p['execution']['makespan']+serial],flush=True)
comparisons=[x for r in rows for x in r['heldout']]
summary={'settings':len(rows),'settings_with_both_admitted':sum(bool(r['fixed'] and r['phase']) for r in rows),
 'timing_comparisons':len(comparisons),
 'wins':sum(r['phase_kernel_joint_cycles']<r['fixed_kernel_joint_cycles'] for r in comparisons),
 'ties':sum(r['phase_kernel_joint_cycles']==r['fixed_kernel_joint_cycles'] for r in comparisons),
 'losses':sum(r['phase_kernel_joint_cycles']>r['fixed_kernel_joint_cycles'] for r in comparisons),
 'unsafe_hits':sum(r['execution']['unsafe_hits'] for r in all_candidates)+sum(r[k]['unsafe_hits'] for r in comparisons for k in ['fixed','phase']),
 'candidate_executions':len(all_candidates),'kernel_data_accesses':782,'shared_reads':145,'private_data_accesses':637}
summary['static_comparisons']=len(static_rows)
summary['carry_strict_bound_improvements']=sum(r['carry_memory_bound']<r['reset_memory_bound'] for r in static_rows)
result={'protocol_sha256':sha(HERE/'PROTOCOL.json'),'model_sha256':sha(HERE/'replacement_model.py'),
 'driver_sha256':sha(Path(__file__)),'trace_sha256':sha(HERE/'ALL_DATA_TRACE.json'),
 'summary':summary,'rows':rows,'elapsed_seconds':time.perf_counter()-start}
(HERE/'COMPLETE_ACCOUNTING_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n')
(HERE/'ALL_ADMITTED_CANDIDATES.json').write_text(json.dumps(all_candidates,indent=2)+'\n')
(HERE/'STATIC_BOUND_ROWS.json').write_text(json.dumps(static_rows,indent=2)+'\n')
print(json.dumps(summary,indent=2))
