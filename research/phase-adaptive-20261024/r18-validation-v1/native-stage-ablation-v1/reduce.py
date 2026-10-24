from pathlib import Path
import json,csv,math
F=Path(__file__).resolve().parent
rows=json.loads((F/'DATA.json').read_text())['rows'];manifest=json.loads((F/'MANIFEST.json').read_text())
assert len(rows)==87 and {x['case']['id'] for x in rows}=={x['id'] for x in manifest['cases']}
assert len({x['benchmark_sha256'] for x in rows})==len({x['config_sha256'] for x in rows})==1
scalar=['instructions','WU','misses','hits','replacements','timer_starts','timer_restarts','timer_expiries']
epochs=[];allrows=[];legacy=[];costs=[];comparisons=[];byid={x['case']['id']:x for x in rows}
for x in rows:
 c=x['case'];s=x['summary'];assert x['valid'] and x['returncode']==0 and x['test_pass'] and not s['marker_errors'] and s['terminal']['code']==0
 assert len(s['phase_events'])==8 and {e['id'] for e in s['phase_events']}=={0,1,2,10,11,12,13,99}
 assert (s['cost_layout']=='legacy')==c['legacy_layout'] and s['api_write_policy']==c['write_policy']
 if not c['legacy_layout']:assert len(s['command'][5])==5 and int(s['command'][5])==c['cost']
 e=x['epoch_cumulative_metrics'];assert [z['label'] for z in e]==['validation','fir','features','join']
 prev={k:0 for k in scalar};previous_tick=s['roi_start_tick'];group=[]
 for z in e:
  d={k:z['metrics'][k]-prev[k] for k in scalar};assert all(v>=0 for v in d.values())
  assert z['tick']>=previous_tick
  row={'id':c['id'],'N':c['N'],'kind':c['kind'],'cost':c['cost'],'epoch':z['label'],'cycles':(z['tick']-previous_tick)/1000,**d}
  epochs.append(row);group.append(row);prev={k:z['metrics'][k] for k in scalar};previous_tick=z['tick']
 assert sum(z['cycles'] for z in group)==s['roi_ticks']/1000 and previous_tick==s['roi_end_tick']
 assert all(sum(z[k] for z in group)==x['total_metrics'][k] for k in scalar)
 assert sum(x['total_metrics']['commit_instructions_per_core'])==x['total_metrics']['instructions']
 if c['kind']=='suppress':assert s['timeout_register_writes']==0 and s['suppressed_timeout_writes']==4
 if c['kind']=='apply':assert s['timeout_register_writes']==4 and s['suppressed_timeout_writes']==0
 if c['kind']=='fixed':assert s['timeout_register_writes']==s['requested_timeout_writes']==0
 t={q['id']:q['tick'] for q in s['phase_events']};start=s['roi_start_tick']
 allrows.append({'id':c['id'],'N':c['N'],'kind':c['kind'],'cost':c['cost'],'write_policy':c['write_policy'],'legacy_layout':c['legacy_layout'],'K':c['K'],'J':s['roi_ticks']/1000,'receiver':(max(t[k] for k in [10,11,12])-start)/1000,'writer':(t[13]-start)/1000,'join_tail':(t[99]-max(t[k] for k in [10,11,12,13]))/1000,**{k:x['total_metrics'][k] for k in scalar}})
for ref in json.loads((F/'LEGACY_REFERENCE.json').read_text()):
 x=next(z for z in rows if z['case']['N']==ref['N'] and z['case']['kind']==ref['kind'])
 assert x['case']['K']==ref['K'] and x['summary']['roi_ticks']==ref['roi_ticks'] and x['benchmark_sha256']==ref['benchmark_sha256']
 assert [{'id':e['id'],'tick':e['tick']} for e in x['summary']['phase_events']]==ref['phase_events']
 assert all(x['total_metrics'][k]==ref[k] for k in ['WU','misses','replacements'])
 legacy.append({'N':ref['N'],'kind':ref['kind'],'all_original_ticks_and_counters_match':True})
for n in [32,36,40]:
 fixed=min((x for x in allrows if x['N']==n and x['kind']=='fixed'),key=lambda x:(x['J'],x['K']))
 for cost in [0,8,16,32,64]:
  app=next(x for x in allrows if x['N']==n and x['kind']=='apply' and x['cost']==cost);sup=next(x for x in allrows if x['N']==n and x['kind']=='suppress' and x['cost']==cost)
  assert byid[app['id']]['summary']['command']==byid[sup['id']]['summary']['command']
  costs.append({'N':n,'cost':cost,'phase_J':app['J'],'suppressed_J':sup['J'],'best15_fixed_J':fixed['J'],'best15_fixed_K':fixed['K'],'phase_vs_fixed_reduction_percent':100*(fixed['J']-app['J'])/fixed['J'],'phase_vs_suppressed_reduction_percent':100*(sup['J']-app['J'])/sup['J'],'phase_WU':app['WU'],'suppressed_WU':sup['WU'],'fixed_WU':fixed['WU'],'phase_misses':app['misses'],'suppressed_misses':sup['misses'],'fixed_misses':fixed['misses']})
 oldfix=next(x for x in allrows if x['N']==n and x['kind']=='legacy-fixed');oldphase=next(x for x in allrows if x['N']==n and x['kind']=='legacy-phase')
 differences={}
 for label in ['validation','fir','features','join']:
  f=next(x for x in epochs if x['id']==oldfix['id'] and x['epoch']==label);p=next(x for x in epochs if x['id']==oldphase['id'] and x['epoch']==label)
  differences[label]={'fixed_cycles':f['cycles'],'phase_cycles':p['cycles'],'delta_cycles':p['cycles']-f['cycles'],'delta_percent_of_fixed_J':100*(p['cycles']-f['cycles'])/oldfix['J'],'fixed_WU':f['WU'],'phase_WU':p['WU'],'fixed_misses':f['misses'],'phase_misses':p['misses']}
 assert sum(d['delta_cycles'] for d in differences.values())==oldphase['J']-oldfix['J']
 comparisons.append({'N':n,'fixed_J':oldfix['J'],'phase_J':oldphase['J'],'reduction_percent':100*(oldfix['J']-oldphase['J'])/oldfix['J'],'epoch_difference':differences,'fixed_WU':oldfix['WU'],'phase_WU':oldphase['WU'],'fixed_misses':oldfix['misses'],'phase_misses':oldphase['misses']})
def savecsv(name,z):
 with (F/name).open('w',newline='') as p:
  w=csv.DictWriter(p,fieldnames=list(z[0]),lineterminator='\n');w.writeheader();w.writerows(z)
savecsv('ALL_TIMINGS.csv',allrows);savecsv('EPOCHS.csv',epochs);savecsv('COST_ABLATION.csv',costs)
summary={'cases':87,'all_valid':True,'legacy_replays_exact':len(legacy),'all_epoch_counters_reconcile':True,'same_layout_apply_suppress_pairs':15,'controller_stall_values':[0,8,16,32,64],'legacy_comparisons':comparisons,'new_layout_phase_fixed_reduction_range':[min(x['phase_vs_fixed_reduction_percent'] for x in costs),max(x['phase_vs_fixed_reduction_percent'] for x in costs)],'matched_mechanism_reduction_range':[min(x['phase_vs_suppressed_reduction_percent'] for x in costs),max(x['phase_vs_suppressed_reduction_percent'] for x in costs)],'scope':'Deterministic native system-epoch and matched-write ablations; extra stall is a declared parameter, not a certified helper/CSR WCET.'}
(F/'SUMMARY.json').write_text(json.dumps(summary,indent=2)+'\n',encoding='utf-8',newline='\n')
(F/'LEGACY_MATCH_AUDIT.json').write_text(json.dumps(legacy,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps(summary,indent=2))
