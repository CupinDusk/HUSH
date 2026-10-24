from bound_inputs import read_bound
"""Retrospective tolerance exploration. Does not change original frozen policies."""
from pathlib import Path
from fractions import Fraction
import json,csv,argparse
ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path);a=ap.parse_args();F=Path(__file__).resolve().parent;O=a.out or F;O.mkdir(exist_ok=True,parents=True)
original=json.loads(read_bound('TRAIN_CANDIDATES.json').decode('utf-8'));measured=json.loads(read_bound('MEASUREMENTS.json').decode('utf-8'))['rows']
def save(name,rows):
 with (O/name).open('w',encoding='utf-8',newline='') as f:w=csv.DictWriter(f,fieldnames=list(rows[0]),lineterminator='\n');w.writeheader();w.writerows(rows)
def best(aa):return min(aa,key=lambda x:(x['WU'],x['J'],x['K'])) if aa else None
def ident(x):return '' if x is None else x['kind']+':'+','.join(map(str,x['K']))
allpoints=[];keytable=[];steps=[]
for cache in ['32KiB','64KiB']:
 groups={}
 for x in original:
  if x['cache']==cache:groups.setdefault((x['kind'],tuple(x['K'])),[]).append(x)
 assert len(groups)==279
 aa=[{'cache':cache,'kind':kind,'K':K,'J':int(max(x['J'] for x in rr)),'WU':int(max(x['WU'] for x in rr)),'identity':'original R20 candidate'} for (kind,K),rr in groups.items()]
 anchor=min(x['J'] for x in aa if x['kind']=='fixed');ss=[r for r in measured if (r['case']['cache'],r['case']['N'],r['case']['kind'])==(cache,16,'suppress')];assert len(ss)==3
 aa.append({'cache':cache,'kind':'suppress','K':tuple(ss[0]['case']['K']),'J':int(max(r['summary']['roi_ticks']/1000 for r in ss)),'WU':int(max(r['total_metrics']['WU'] for r in ss)),'identity':'R23 post-selection matched ablation'})
 for x in aa:
  x['threshold_pct_exact']=str(100*Fraction(x['J']-anchor,anchor));x['threshold_pct']=float(100*Fraction(x['J']-anchor,anchor));x['anchor_maxJ']=anchor
  x['pareto_all_measured_families']=not any(y['J']<=x['J'] and y['WU']<=x['WU'] and (y['J']<x['J'] or y['WU']<x['WU']) for y in aa)
  allpoints.append({**x,'K':','.join(map(str,x['K']))})
 def at(tol):
  eligible=[x for x in aa if Fraction(x['J']-anchor,anchor)*100<=tol];bb={kind:best([x for x in eligible if x['kind']==kind]) for kind in ['fixed','phase','suppress']}
  deployed=bb['phase'] if bb['phase'] is not None and bb['phase']['WU']<bb['fixed']['WU'] else bb['fixed']
  extended=best(eligible)
  row={'cache':cache,'tolerance_pct':float(tol),'tolerance_pct_exact':str(tol),'cap_cycles':float(anchor*(1+tol/100)),'cap_cycles_exact':str(anchor*(1+tol/100)),'anchor_maxJ':anchor}
  for kind in ['fixed','phase','suppress']:
   x=bb[kind];row[kind+'_K']='' if x is None else ','.join(map(str,x['K']));row[kind+'_J']='' if x is None else x['J'];row[kind+'_WU']='' if x is None else x['WU'];row[kind+'_eligible_candidates']=sum(x['kind']==kind for x in eligible)
  row['original_family_decision']=ident(deployed);row['original_family_decision_J']=deployed['J'];row['original_family_decision_WU']=deployed['WU'];row['augmented_posthoc_best']=ident(extended);row['augmented_posthoc_best_J']=extended['J'];row['augmented_posthoc_best_WU']=extended['WU']
  return row
 for t in ['0','0.05','0.1','0.2','0.5']:keytable.append(at(Fraction(t)))
 bounds=sorted({Fraction(0),Fraction(1,2),*[100*Fraction(x['J']-anchor,anchor) for x in aa if 0<x['J']-anchor<=Fraction(anchor,200)]})
 last=None
 for i,t in enumerate(bounds):
  row=at(t);signature=tuple(row[k] for k in ['fixed_K','phase_K','suppress_K','original_family_decision','augmented_posthoc_best'])
  if signature==last:continue
  if steps and steps[-1]['cache']==cache:
   steps[-1]['until_tolerance_pct_exclusive']=float(t);steps[-1]['until_tolerance_pct_exact']=str(t)
  steps.append({'cache':cache,'from_tolerance_pct_inclusive':float(t),'from_tolerance_pct_exact':str(t),'until_tolerance_pct_exclusive':0.5,'until_tolerance_pct_exact':'1/2','final_upper_endpoint_inclusive':False,**{k:v for k,v in row.items() if k not in ['cache','tolerance_pct','tolerance_pct_exact']}});last=signature
 steps[-1]['final_upper_endpoint_inclusive']=True
save('TRAINING_FRONTIER.csv',allpoints);save('TOLERANCE_KEY_TABLE.csv',keytable);save('TOLERANCE_STEPS.csv',steps)
print(json.dumps({'candidate_aggregates':len(allpoints),'key_rows':len(keytable),'complete_winner_intervals_0_to_0_5_pct':len(steps)}))
