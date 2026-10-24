"""Prespecified cost-aware admission/selection, unchanged protocol model."""
from pathlib import Path
from itertools import product
import json,hashlib,time,csv
import replacement_model as m
HERE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
assert sha(HERE/'replacement_model.py')=='6270a7fa1c79a81dab99f9712e170c60c1ded14dd5052f3b987ba421a1b99e10'
P=json.loads((HERE/'PROTOCOL.json').read_text())
m.P.update(shared_blocks=2,receiver_dense_reads=16,receiver_compute_gap=1,
           writer_store_count=128,period=2)
original=m.instructions('BSQ',512)
paths=sorted(set(product(P['phase_domain'],repeat=3))|{(k,k,k) for k in range(1,256)})
assert len(paths)==591
fixedflush=[(),(1,),(2,),(1,2)]

def operations(delta):
 out=[]
 for op,v in original:
  if op=='phase' and v>0:out.append(('compute',delta))
  out.append((op,v))
 return out

def analyze(ops,ks,flush=()):
 a=m.analyze(ops,ks,flush_at_boundaries=flush)
 C=sum(v for op,v in ops if op=='compute')
 return a,{'W':a['bound'],'C':C,'M':a['bound']-C-a['switches'],
           'changed_loads':a['switches'],'configuration_write_cycles':a['switches'],
           'analysis_hits':a['hits'],'analysis_unknown':a['unknown']}

def execute(ops,ks,flush,a,phi):
 return m.simulate(ops,ks,4,phi,a,writer_count=128,flush_at_boundaries=flush,flush_at_finish=True)

def choose(rows):
 return min(rows,key=lambda x:(x['execution']['makespan'],x['execution']['reader_cycles'],x['execution']['updates'],x['K'],x['flush'])) if rows else None

maxB=max(P['budgets']);start=time.perf_counter();fixed=[];phase={};candidate_rows=[]
for k,flush in product(range(1,256),fixedflush):
 ks=(k,k,k);a,metrics=analyze(original,ks,flush)
 r=execute(original,ks,flush,a,0) if metrics['W']<=maxB else None
 row={'mode':'fixed','delta':0,'K':ks,'flush':flush,**metrics,
      'budget_admission':{str(b):metrics['W']<=b for b in P['budgets']},'execution':r}
 fixed.append(row);candidate_rows.append(row)
for delta in P['helper_cycles_per_noninitial_marker']:
 ops=operations(delta);out=[]
 for ks in paths:
  a,metrics=analyze(ops,ks)
  r=execute(ops,ks,(),a,0) if metrics['W']<=maxB else None
  row={'mode':'phase','delta':delta,'K':ks,'flush':(),**metrics,'helper_cycles':2*delta,
       'budget_admission':{str(b):metrics['W']<=b for b in P['budgets']},'execution':r}
  out.append(row);candidate_rows.append(row)
 phase[delta]=out
 print('delta',delta,'admitted',sum(x['execution'] is not None for x in out),flush=True)
rows=[]
for budget,delta in product(P['budgets'],P['helper_cycles_per_noninitial_marker']):
 fs=[r for r in fixed if r['W']<=budget];ps=[r for r in phase[delta] if r['W']<=budget]
 f=choose(fs);p=choose(ps)
 selected=p if p and (f is None or p['execution']['makespan']<f['execution']['makespan']) else f
 mode=selected['mode'] if selected else None
 row={'budget':budget,'delta':delta,'fixed_admitted':len(fs),'phase_admitted':len(ps),
      'fixed_selected':f,'phase_selected':p,'deployed_mode':mode,'deployed_K':selected and selected['K'],
      'offline_fixed_fallback':bool(f and selected is f),'timing_points':[]}
 if selected and f:
  for phi in [0,1]:
   fr=execute(original,f['K'],f['flush'],analyze(original,f['K'],f['flush'])[0],phi)
   sop=original if mode=='fixed' else operations(delta)
   sr=execute(sop,selected['K'],selected['flush'],analyze(sop,selected['K'],selected['flush'])[0],phi)
   row['timing_points'].append({'phi':phi,'fixed':fr,'deployed':sr,
       'signed_joint_improvement':(fr['makespan']-sr['makespan'])/fr['makespan']})
 rows.append(row)
 print('selection',budget,delta,mode,selected and selected['K'],selected and selected['W'],
       'J',[r['deployed']['makespan'] for r in row['timing_points']],flush=True)
summary={'settings':len(rows),'candidate_rows':len(candidate_rows),
 'candidate_executions':sum(r['execution'] is not None for r in candidate_rows),
 'unsafe_hits':sum(r['execution']['unsafe_hits'] for r in candidate_rows if r['execution']),
 'selected_timing_points':sum(len(r['timing_points']) for r in rows),
 'offline_fixed_fallback_settings':sum(r['offline_fixed_fallback'] for r in rows)}
alltimings=[x for r in rows for x in r['timing_points']]
summary.update(wins=sum(x['signed_joint_improvement']>0 for x in alltimings),
               ties=sum(x['signed_joint_improvement']==0 for x in alltimings),
               losses=sum(x['signed_joint_improvement']<0 for x in alltimings))
result={'protocol_sha256':sha(HERE/'PROTOCOL.json'),'model_sha256':sha(HERE/'replacement_model.py'),
 'driver_sha256':sha(Path(__file__)),'summary':summary,'rows':rows,'elapsed_seconds':time.perf_counter()-start}
(HERE/'CONTROL_COST_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n')
(HERE/'ALL_CANDIDATES.json').write_text(json.dumps(candidate_rows,indent=2)+'\n')
flat=[]
for r in rows:
 for t in r['timing_points']:
  s=r['fixed_selected'] if r['deployed_mode']=='fixed' else r['phase_selected']
  flat.append({'budget':r['budget'],'delta':r['delta'],'phi':t['phi'],'mode':r['deployed_mode'],
       'K':s['K'],'W':s['W'],'C':s['C'],'M':s['M'],'changes':s['changed_loads'],
       'fixed_J':t['fixed']['makespan'],'deployed_J':t['deployed']['makespan'],
       'updates':t['deployed']['updates'],'reader_completion':t['deployed']['reader_cycles'],
       'signed_joint_improvement':t['signed_joint_improvement']})
with (HERE/'SELECTED_ROWS.csv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(flat[0]));w.writeheader();w.writerows(flat)
print(json.dumps(summary,indent=2))
