from pathlib import Path
import json,csv,hashlib
F=Path(__file__).resolve().parent
def load(n):return json.loads((F/n).read_text())
t=load('STAGE3_TRAINING_ROWS.json');v=load('STAGE3_VALIDATION_ROWS.json');r=load('STAGE3_REPLICATION_ROWS.json');s=load('STAGE3_FROZEN_SELECTION.json')
assert len(t)==41 and len(v)==18 and len(r)==36 and s['N32_native_timing_seen'] is False
b=(F/'STAGE3_TRAINING_ROWS.json').read_bytes();assert s['training_rows_sha256'] in {hashlib.sha256(b).hexdigest(),hashlib.sha256(b.replace(b'\r\n',b'\n').replace(b'\n',b'\r\n')).hexdigest()}
assert all(x['valid'] and not x['invariant_failures'] and x['returncode']==0 for x in t+v+r)
assert len({x['benchmark_sha256'] for x in t+v+r})==1
best=lambda z:min(z,key=lambda x:(x['roi_cycles'],x['case']['K']))
p=best([x for x in t if x['case']['kind']=='phase']);f=best([x for x in t if x['case']['kind']=='fixed'])
assert p['case']['K']==s['phase_K'] and f['case']['K']==s['fixed_K']
assert all(k%128==0 and 1<=k//128<=254 for k in s['phase_K'])
out=[]
for n in [32,36,40]:
 z=[x for x in v+r if x['case']['N']==n];assert len(z)==18
 fixed=[x for x in z if x['case']['kind']=='fixed'];assert len(fixed)==15
 phase=next(x for x in z if x['case']['kind']=='selected-phase');assert phase['case']['K']==s['phase_K']
 oracle=best(fixed);enc=best([x for x in fixed if x['case']['K'][0]%128==0 and x['case']['K'][0]//128<=254])
 for x in z:
  ids={e['id'] for e in x['phase_events']};assert ids=={0,1,2,10,11,12,13,99}
 out.append({'N':n,'phase_K':s['phase_K'],'phase_J':phase['roi_cycles'],'best15_fixed_K':oracle['case']['K'],'best15_fixed_J':oracle['roi_cycles'],'phase_reduction_percent':100*(oracle['roi_cycles']-phase['roi_cycles'])/oracle['roi_cycles'],'common_P128_finite_fixed_K':enc['case']['K'],'common_P128_finite_fixed_J':enc['roi_cycles'],'phase_vs_encodable_fixed_reduction_percent':100*(enc['roi_cycles']-phase['roi_cycles'])/enc['roi_cycles'],'phase_updates':phase['updates'],'fixed_updates':oracle['updates'],'phase_misses':phase['misses'],'fixed_misses':oracle['misses']})
a={'training_cases':41,'first_validation_cases':18,'followup_replication_cases':36,'total_cases':95,'all_valid':True,'all_phase_values_encodable_at_P128':True,'phase_K_encoding':s['phase_K_encoding'],'training_mode_selection':s['mode'],'phase_family_forced_comparison':True,'replication_declared_after_N32':True,'rows':out,'scope':'Exploratory nonconstant-phase candidate, frozen before native N32; no native WCET or full-pipeline cost-aware deployment proof.'}
(F/'STAGE3_RESULTS.json').write_text(json.dumps(a,indent=2)+'\n')
with (F/'STAGE3_TIMING_COMPARISONS.csv').open('w',newline='') as stream:
 w=csv.DictWriter(stream,fieldnames=list(out[0]));w.writeheader();w.writerows(out)
print(json.dumps(a,indent=2))
