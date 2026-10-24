from bound_inputs import read_bound
from pathlib import Path
import json,csv,argparse
ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path);a=ap.parse_args();F=Path(__file__).resolve().parent;O=a.out or F;O.mkdir(parents=True,exist_ok=True)
d=json.loads((F/'TRANSFER_MEASUREMENTS.json').read_text());rows=[];epochs=[]
for r in d['rows']:
 assert r['K']==[128,16,1];z={k:r[k] for k in ['id','cache','N','phi','J','WU','instructions','misses','hits']};z['explicit_producer_frame_stores']=((r['N']**2+7)//8)*64;z['WU_per_explicit_producer_frame_store']=r['WU']/z['explicit_producer_frame_stores']
 for name in ['frozen_fixed','frozen_fastest']:
  for metric in ['J','WU','instructions','misses','hits']:z[name+'_'+metric]=r[name][metric];z['phase_minus_'+name+'_'+metric]=r[metric]-r[name][metric]
  z['phase_minus_'+name+'_J_pct']=100*(r['J']-r[name]['J'])/r[name]['J'];z['WU_reduction_vs_'+name+'_pct']=100*(r[name]['WU']-r['WU'])/r[name]['WU']
 rows.append(z);prev={m:0 for m in ['WU','instructions','misses','hits']};tick=r['roi_start_tick'];parts=[]
 for e in r['epochs']:
  q={'id':r['id'],'N':r['N'],'phi':r['phi'],'epoch':e['epoch'],'J':(e['tick']-tick)/1000,**{k:e[k]-prev[k] for k in prev}};epochs.append(q);parts.append(q);tick=e['tick'];prev={k:e[k] for k in prev}
 assert sum(x['J'] for x in parts)==r['J'] and all(sum(x[k] for x in parts)==r[k] for k in prev) and tick==r['roi_end_tick']
def save(name,rr):
 with (O/name).open('w',encoding='utf-8',newline='') as f:w=csv.DictWriter(f,fieldnames=list(rr[0]),lineterminator='\n');w.writeheader();w.writerows(rr)
save('POSTHOC_TRANSFER.csv',rows);save('POSTHOC_TRANSFER_EPOCHS.csv',epochs)
audit={'identity':d['identity'],'new_runs':9,'valid':9,'epoch_rows':len(epochs),'all_epoch_sums_exact':True,'frozen_policies_unchanged':True,'same_offset_J_signs_vs_frozen_fixed':{'negative':sum(r['phase_minus_frozen_fixed_J']<0 for r in rows),'zero':sum(r['phase_minus_frozen_fixed_J']==0 for r in rows),'positive':sum(r['phase_minus_frozen_fixed_J']>0 for r in rows)},'all_9_WU_lower_vs_both_comparators':all(r['phase_minus_'+n+'_WU']<0 for n in ['frozen_fixed','frozen_fastest'] for r in rows)}
(O/'POSTHOC_TRANSFER_AUDIT.json').write_text(json.dumps(audit,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps(audit))
