"""All selected settings and prespecified-primary views; no filtering on gain."""
from pathlib import Path
import json,csv,statistics,hashlib
P=Path(__file__).resolve().parent
d=json.loads((P/'RESULTS.json').read_text());primary=[];selected=[]
for c in d['cases']:
 for r in c['selections']:
  s=r['selected'];fixed=r['fixed'];v=[z['signed_gain'] for z in r['validation'] if 'signed_gain' in z]
  selected.append(dict(case=c['index'],family=c['spec']['family'],q=c['parameters']['shared_blocks'],
   g=c['parameters']['receiver_compute_gap'],P=c['parameters']['period'],training_gap=c['training_gap'],
   delta=r['delta'],margin=r['margin'],B0=c['B0'],budget=r['budget'],mode=r['mode'],
   K1=s['K'][0],K2=s['K'][1],K3=s['K'][2],W=s['W'],C=s['C'],M=s['M'],S=s['S'],Lsw=s['Lsw'],
   fixed_J=fixed['execution']['makespan'],selected_J=s['execution']['makespan'],
   training_signed_gain=r['training_signed_gain'],valid=r['valid']))
  if r['delta']==8 and r['margin']==32:
   primary.append(dict(case=c['index'],family=c['spec']['family'],q=c['parameters']['shared_blocks'],g=c['parameters']['receiver_compute_gap'],P=c['parameters']['period'],training_gap=c['training_gap'],B0=c['B0'],budget=r['budget'],delta=8,mode=r['mode'],K=s['K'],flush=s['flush'],W=s['W'],C=s['C'],M=s['M'],S=s['S'],Lsw=s['Lsw'],fixed_J=fixed['execution']['makespan'],selected_J=s['execution']['makespan'],selected_updates=s['execution']['updates'],reader_completion=s['execution']['reader_cycles'],training_signed_gain=r['training_signed_gain'],validation_min=min(v),validation_median=statistics.median(v),validation_max=max(v)))
def save(name,rows):
 with (P/name).open('w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
save('PRIMARY_CASE_ROWS.csv',primary);save('SELECTED_SETTINGS.csv',selected)
with (P/'VALIDATION_ROWS.csv').open(newline='') as f:
 reader=csv.DictReader(f);primaryvalidation=[r for r in reader if r['delta']=='8' and r['margin']=='32']
save('PRIMARY_VALIDATION_ROWS.csv',primaryvalidation)
d.pop('elapsed_seconds',None)
provenance={'results_scientific_sha256':hashlib.sha256(json.dumps(d,sort_keys=True,separators=(',',':')).encode()).hexdigest(),
 'validation_rows_sha256':hashlib.sha256((P/'VALIDATION_ROWS.csv').read_bytes()).hexdigest(),
 'views':{name:hashlib.sha256((P/name).read_bytes()).hexdigest() for name in ['SELECTED_SETTINGS.csv','PRIMARY_CASE_ROWS.csv','PRIMARY_VALIDATION_ROWS.csv']},
 'selected_rows':len(selected),'primary_cases':len(primary),'primary_validation':len(primaryvalidation)}
(P/'VIEW_PROVENANCE.json').write_text(json.dumps(provenance,indent=2)+'\n')
print(json.dumps(provenance,indent=2))
