from bound_inputs import read_bound
"""Match total ROI WU to explicit producer frame stores; keep CPU totals distinct."""
from pathlib import Path
import json,csv,hashlib,argparse
ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path);a=ap.parse_args();F=Path(__file__).resolve().parent;O=a.out or F;O.mkdir(exist_ok=True,parents=True)
d=json.loads(read_bound('COUNTERS_MIN.json').decode('utf-8'));m=json.loads(read_bound('MEASUREMENTS.json').decode('utf-8'))['rows'];old={r['case']['id']:r for r in m}
assert hashlib.sha256((F/'fir_pipeline_v3.c').read_bytes()).hexdigest()==d['guest_source_sha256'];assert hashlib.sha256((F/'WORK_DISASSEMBLY.txt').read_bytes()).hexdigest()==d['work_disassembly_sha256'];assert d['source_and_ELF_two_start_barriers_verified']
rows=[];epochs=[]
for r in d['rows']:
 c=r['case'];z=old[c['id']];ss=r['snapshots'][0]['counters'];stores=((c['N']**2+7)//8)*64;q=r['checksums'][0]
 assert int(q[1])==stores and q[3]==q[4] and ss['system.membus.hushUpdateAccepted']==z['total_metrics']['WU'] and ss['simInsts']==z['total_metrics']['instructions']
 row={'id':c['id'],'cache':c['cache'],'N':c['N'],'phi':c['phi'],'policy':c['kind'],'explicit_producer_frame_stores_in_ROI':stores,'total_system_WU_in_ROI':ss['system.membus.hushUpdateAccepted'],'WU_per_explicit_producer_frame_store':ss['system.membus.hushUpdateAccepted']/stores,'system_committed_numInsts':ss['simInsts']}
 for i in range(4):
  for key in ['numInsts','numLoadInsts','numStoreInsts','numMemRefs']:row[f'cpu{i}_committed_{key}']=ss[f'system.cpu{i}.commitStats0.{key}']
 row['cpu3_store_counter_minus_explicit_frame_stores']=row['cpu3_committed_numStoreInsts']-stores;assert row['cpu3_store_counter_minus_explicit_frame_stores']>=0;rows.append(row)
 prev={k:0 for k in ss};tick=r['roi_start_tick']
 for e in r['snapshots'][1:]:
  cur=e['counters'];er={'id':c['id'],'cache':c['cache'],'N':c['N'],'phi':c['phi'],'policy':c['kind'],'epoch':e['label'],'J':(e['tick']-tick)/1000,'whole_system_WU':cur['system.membus.hushUpdateAccepted']-prev['system.membus.hushUpdateAccepted']}
  for i in range(4):
   for key in ['numInsts','numLoadInsts','numStoreInsts','numMemRefs']:er[f'cpu{i}_committed_{key}']=cur[f'system.cpu{i}.commitStats0.{key}']-prev[f'system.cpu{i}.commitStats0.{key}']
  epochs.append(er);prev=cur;tick=e['tick']
 assert prev==ss and tick==r['roi_end_tick']
def save(name,rr):
 with (O/name).open('w',encoding='utf-8',newline='') as f:w=csv.DictWriter(f,fieldnames=list(rr[0]),lineterminator='\n');w.writeheader();w.writerows(rr)
save('NORMALIZED.csv',rows);save('CPU_EPOCHS.csv',epochs)
summary=[]
for cache in ['32KiB','64KiB']:
 for N in [16,32,36,40]:
  rr=[r for r in rows if (r['cache'],r['N'])==(cache,N)];z={'cache':cache,'N':N,'explicit_producer_frame_stores':rr[0]['explicit_producer_frame_stores_in_ROI']}
  for policy in ['fixed','phase','suppress']:
   qq=[r for r in rr if r['policy']==policy]
   for key in ['WU_per_explicit_producer_frame_store','cpu3_committed_numInsts','cpu3_committed_numStoreInsts','cpu3_store_counter_minus_explicit_frame_stores']:z[policy+'_'+key+'_min']=min(r[key] for r in qq);z[policy+'_'+key+'_max']=max(r[key] for r in qq)
  summary.append(z)
save('NORMALIZATION_SUMMARY.csv',summary)
audit={'counter_rows':len(rows),'epoch_rows':len(epochs),'all_72_source_stdout_denominators_match':True,'all_counter_totals_match_original_measurements':True,'all_288_cpu_epochs_reconcile':True,'producer_stores_by_N':{N:((N*N+7)//8)*64 for N in [16,32,36,40]},'cpu3_store_counter_extra_range':[min(r['cpu3_store_counter_minus_explicit_frame_stores'] for r in rows),max(r['cpu3_store_counter_minus_explicit_frame_stores'] for r in rows)],'WU_store_ratio_scope':'whole-system accepted WU per explicit producer frame store, same ROI; not producer-attributed WU or updates per receiver, not a polling-isolated causal quantity','polling_work':'The retained per-core committed counters include all work. They do not isolate polling PCs, barrier loads, stack/global writes or frame-attributed WU. Exact polling attribution needs PC-tagged instruction/memory event counts or dedicated source counters under a newly bound instrumented ELF.'}
(O/'NORMALIZATION_AUDIT.json').write_text(json.dumps(audit,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps(audit))
