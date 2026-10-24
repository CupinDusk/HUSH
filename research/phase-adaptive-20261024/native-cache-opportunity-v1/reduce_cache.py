from pathlib import Path
import json,csv
V=Path(__file__).resolve().parent;F=V/'native-cache' if (V/'native-cache/DATA.json').exists() else V
p=json.loads((F/'PROTOCOL.json').read_text());freeze=json.loads((F/'FROZEN_SELECTION.json').read_text());rows=json.loads((F/'DATA.json').read_text())['rows']
assert len(rows)==196 and sum(x['group']=='train' for x in rows)==82
scalars=['instructions','WU','misses','hits','replacements'];epochs=[];timings=[]
for r in rows:
 s=r['summary'];c=r['case'];assert r['valid'] and not s['marker_errors'] and s['terminal']['code']==0
 assert len(s['command'][5])==5 and int(s['command'][5])==c['cost']
 assert len(s['phase_events'])==8 and {x['id'] for x in s['phase_events']}=={0,1,2,10,11,12,13,99}
 prev={k:0 for k in scalars};tick=s['roi_start_tick'];parts=[]
 assert [x['label'] for x in r['epoch_cumulative_metrics']]==['validation','fir','features','join']
 for e in r['epoch_cumulative_metrics']:
  z={'id':c['id'],'epoch':e['label'],'cycles':(e['tick']-tick)/1000,**{k:e['metrics'][k]-prev[k] for k in scalars}};assert all(z[k]>=0 for k in scalars);parts.append(z);epochs.append(z);prev=e['metrics'];tick=e['tick']
 assert sum(x['cycles'] for x in parts)==s['roi_ticks']/1000 and tick==s['roi_end_tick']
 assert all(sum(x[k] for x in parts)==r['total_metrics'][k] for k in scalars)
 timings.append({'id':c['id'],'group':r['group'],'cache':c['cache'],'N':c['N'],'kind':c['kind'],'K':c['K'],'J':s['roi_ticks']/1000,**r['total_metrics']})
assert {r['benchmark_sha256'] for r in rows}=={'2240805a3edaceb2741e7b0285f9dd1cdd07188395705322a8ca088206300096'}
assert {r['config_sha256'] for r in rows}=={'44c05c6607a2b8ed8291491f2ce526128df2785e4276d1e2aa5897dda16e4a63'}
comparisons=[]
for selection in freeze['selection']:
 cache=selection['cache'];tr=[r for r in timings if r['group']=='train' and r['cache']==cache]
 best=lambda z:min(z,key=lambda r:(r['J'],r['K']))
 fix=best([r for r in tr if r['kind']=='fixed']);phase=best([r for r in tr if r['kind']=='phase'])
 assert fix['K']==selection['fixed_K'] and phase['K']==selection['phase_K'] and fix['J']==selection['fixed_J'] and phase['J']==selection['phase_J']
 assert selection['deployed_mode']==('phase' if phase['J']<fix['J'] else 'fixed') and not selection['heldout_seen']
 for n in p['heldout_N']:
  vr=[r for r in timings if r['group']=='validation' and r['cache']==cache and r['N']==n]
  assert len(vr)==19
  oracle=best([r for r in vr if r['kind']=='fixed']);fixed=next(r for r in vr if r['kind']=='fixed' and r['K']==selection['fixed_K']);phase=next(r for r in vr if r['kind']=='phase');sup=next(r for r in vr if r['kind']=='suppress')
  assert phase['K']==sup['K']==selection['phase_K'];appraw=next(r for r in rows if r['case']['id']==phase['id']);supraw=next(r for r in rows if r['case']['id']==sup['id'])
  assert appraw['summary']['command']==supraw['summary']['command']
  # A different first→second phase write is legitimate in64KiB; only the
  # validation epoch necessarily precedes intervention for both geometries.
  assert appraw['epoch_cumulative_metrics'][0]==supraw['epoch_cumulative_metrics'][0]
  deployed=phase if selection['deployed_mode']=='phase' else fixed
  comparisons.append({'cache':cache,'N':n,'deployed_mode':selection['deployed_mode'],'fixed_K':selection['fixed_K'],'phase_K':selection['phase_K'],'frozen_fixed_J':fixed['J'],'best15_J':oracle['J'],'best15_K':oracle['K'],'phase_J':phase['J'],'suppressed_J':sup['J'],'deployed_J':deployed['J'],'deployed_vs_frozen_fixed_reduction_percent':100*(fixed['J']-deployed['J'])/fixed['J'],'deployed_vs_best15_reduction_percent':100*(oracle['J']-deployed['J'])/oracle['J'],'phase_vs_best15_reduction_percent':100*(oracle['J']-phase['J'])/oracle['J'],'write_only_reduction_percent':100*(sup['J']-phase['J'])/sup['J'],'phase_WU':phase['WU'],'suppressed_WU':sup['WU'],'frozen_fixed_WU':fixed['WU'],'phase_misses':phase['misses'],'suppressed_misses':sup['misses'],'frozen_fixed_misses':fixed['misses']})
def save(name,z):
 with (F/name).open('w',newline='') as f:w=csv.DictWriter(f,fieldnames=list(z[0]),lineterminator='\n');w.writeheader();w.writerows(z)
save('ALL_TIMINGS.csv',timings);save('EPOCHS.csv',epochs);save('COMPARISONS.csv',comparisons)
a={'runs':196,'all_valid':True,'training_runs':82,'validation_runs':114,'all_epoch_counters_reconcile':True,'selection':freeze['selection'],'comparisons':comparisons,'scope':'Prespecified two-cache sensitivity; identical native ELF/config, frozen N16 selection, allN32/36/40 inputs retained. No4core task-WCET certification. Matched-write intervention conditional on same guest path and initial timeout.'}
(F/'RESULTS.json').write_text(json.dumps(a,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps(a,indent=2))
