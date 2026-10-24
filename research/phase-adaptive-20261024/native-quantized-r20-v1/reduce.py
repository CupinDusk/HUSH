from pathlib import Path
import json,csv
F=Path(__file__).resolve().parent;p=json.loads((F/'PROTOCOL.json').read_text());freeze=json.loads((F/'FROZEN_SELECTION.json').read_text());rows=json.loads((F/'DATA.json').read_text())['rows']
validation_count=len(json.loads((F/'VALIDATION_MANIFEST.json').read_text())['cases']);total=1686+validation_count+375
assert len(rows)==total and [sum(r['group']==g for r in rows) for g in ['train','validation','offset']]==[1686,validation_count,375]
scalars=['instructions','WU','misses','hits','replacements'];timings=[];epochs=[]
for r in rows:
 s=r['summary'];c=r['case'];assert r['valid'] and not s['marker_errors'] and s['terminal']['code']==0
 assert s['timer_period_cycles']==c['P']==128 and s['tick_phase_cycles']==c['phi']
 assert c['mode']!='hush' or s['K_schedule']==c['K']
 assert s['schedule_cycles']==[k*128 for k in c['K']]
 assert r['benchmark_sha256']=='2240805a3edaceb2741e7b0285f9dd1cdd07188395705322a8ca088206300096'
 assert r['simulator_sha256']=='08271cdc2858f14731698e18463d4c53dc60ac9b7091183c3aa9bae34c4ddf6a'
 assert r['config_sha256']=='7349b98e8a0bd3ee17a26c38b9c770ab75396693cce0a0333fc4a658547ef0b9'
 assert r['driver_sha256']=='26d6d6353436f78c3c1a6dea7bcd912b3256852a4a9f7a8349b68a94de102c8d'
 assert len(s['command'][5])==5 and int(s['command'][5])==c['cost']
 assert len(s['phase_events'])==8 and {x['id'] for x in s['phase_events']}=={0,1,2,10,11,12,13,99}
 prev={k:0 for k in scalars};tick=s['roi_start_tick'];parts=[]
 assert [x['label'] for x in r['epoch_cumulative_metrics']]==['validation','fir','features','join']
 for e in r['epoch_cumulative_metrics']:
  z={'id':c['id'],'epoch':e['label'],'cycles':(e['tick']-tick)/1000,**{k:e['metrics'][k]-prev[k] for k in scalars}};assert all(z[k]>=0 for k in scalars)
  parts.append(z);epochs.append(z);prev=e['metrics'];tick=e['tick']
 assert sum(x['cycles'] for x in parts)==s['roi_ticks']/1000 and tick==s['roi_end_tick']
 assert all(sum(x[k] for x in parts)==r['total_metrics'][k] for k in scalars)
 timings.append({'id':c['id'],'group':r['group'],'cache':c['cache'],'N':c['N'],'phi':c['phi'],'kind':c['kind'],'K':c['K'],'J':s['roi_ticks']/1000,**r['total_metrics']})
byid={r['case']['id']:r for r in rows}
comparisons=[];sweep=[]
for frozen in freeze['selection']:
 train=[r for r in timings if r['group']=='train' and r['cache']==frozen['cache'] and r['kind'] in ['fixed','phase']]
 assert len(train)==837
 groups={}
 for r in train:groups.setdefault((r['kind'],tuple(r['K'])),[]).append(r)
 aggregates=[]
 for (kind,k),rr in groups.items():
  assert len(rr)==3 and {r['phi'] for r in rr}=={0,64,127}
  aggregates.append({'kind':kind,'K':list(k),'J':max(r['J'] for r in rr),'WU':max(r['WU'] for r in rr)})
 ff=min((r for r in aggregates if r['kind']=='fixed'),key=lambda r:(r['J'],r['K']))
 ef=[r for r in aggregates if r['kind']=='fixed' and r['J']*1000<=ff['J']*1001]
 bestfixed=min(ef,key=lambda r:(r['WU'],r['J'],r['K']))
 ep=[r for r in aggregates if r['kind']=='phase' and r['J']*1000<=ff['J']*1001]
 bestphase=min(ep,key=lambda r:(r['WU'],r['J'],r['K'])) if ep else min((r for r in aggregates if r['kind']=='phase'),key=lambda r:(r['J'],r['K']))
 dep='phase' if ep and bestphase['WU']<bestfixed['WU'] else 'fixed'
 assert ff['K']==frozen['fastest_fixed']['K'] and bestfixed['K']==frozen['fixed']['K'] and bestphase['K']==frozen['phase']['K'] and dep==frozen['deployed_mode']
 assert len(ef)==frozen['eligible_fixed_candidates'] and len(ep)==frozen['eligible_phase_candidates']
 assert not frozen['heldout_seen'] and freeze['heldout_rows_seen']==0
def compare(ss,vr,n,phi):
 fixed=next(r for r in vr if r['kind']=='fixed' and r['K']==ss['fixed']['K'])
 phase=next(r for r in vr if r['kind']=='phase');sup=next(r for r in vr if r['kind']=='suppress')
 assert phase['K']==sup['K']==ss['phase']['K']
 ar,sr=byid[phase['id']],byid[sup['id']];assert ar['summary']['command']==sr['summary']['command']
 assert ar['epoch_cumulative_metrics'][0]==sr['epoch_cumulative_metrics'][0]
 dep=phase if ss['deployed_mode']=='phase' else fixed
 return {'cache':ss['cache'],'N':n,'phi':phi,'deployed_mode':ss['deployed_mode'],'fixed_K':ss['fixed']['K'],'phase_K':phase['K'],'frozen_fixed_J':fixed['J'],'phase_J':phase['J'],'suppressed_J':sup['J'],'deployed_J':dep['J'],'deployed_time_change_percent':100*(dep['J']-fixed['J'])/fixed['J'],'phase_time_change_percent':100*(phase['J']-fixed['J'])/fixed['J'],'write_only_time_change_percent':100*(phase['J']-sup['J'])/sup['J'],'deployed_WU_reduction_percent':100*(fixed['WU']-dep['WU'])/fixed['WU'],'phase_WU_reduction_percent':100*(fixed['WU']-phase['WU'])/fixed['WU'],'write_only_WU_reduction_percent':100*(sup['WU']-phase['WU'])/sup['WU'],'frozen_fixed_WU':fixed['WU'],'phase_WU':phase['WU'],'suppressed_WU':sup['WU'],'deployed_WU':dep['WU']}
for ss in freeze['selection']:
 for n in p['heldout_N']:
  for phi in p['tick_offsets_cycles']:
   vr=[r for r in timings if r['group']=='validation' and r['cache']==ss['cache'] and r['N']==n and r['phi']==phi];assert len(vr) in [20,21,22]
   c=compare(ss,vr,n,phi);oracle=min((r for r in vr if r['kind']=='fixed'),key=lambda r:(r['J'],r['K']))
   c.update({'diagnostic_fixed_J':oracle['J'],'diagnostic_fixed_K':oracle['K'],'deployed_vs_diagnostic_fixed_time_change_percent':100*(c['deployed_J']-oracle['J'])/oracle['J']});comparisons.append(c)
ss=next(s for s in freeze['selection'] if s['cache']=='32KiB')
for phi in range(128):
 group='validation' if phi in [0,64,127] else 'offset'
 vr=[r for r in timings if r['group']==group and r['cache']=='32KiB' and r['N']==32 and r['phi']==phi]
 if group=='validation':vr=[r for r in vr if r['kind'] in ['phase','suppress'] or (r['kind']=='fixed' and r['K']==ss['fixed']['K'])]
 assert len(vr)==3;sweep.append(compare(ss,vr,32,phi))
def save(name,z):
 with (F/name).open('w',newline='',encoding='utf-8') as f:
  w=csv.DictWriter(f,fieldnames=list(z[0]),lineterminator='\n');w.writeheader();w.writerows(z)
save('ALL_TIMINGS.csv',timings);save('EPOCHS.csv',epochs);save('COMPARISONS.csv',comparisons);save('OFFSET_SWEEP.csv',sweep)
result={'runs':total,'training_runs':1686,'validation_runs':validation_count,'new_offset_runs':375,'all_valid':True,'all_epoch_counters_reconcile':True,'selection':freeze['selection'],'comparisons':comparisons,'offset_sweep':sweep,'scope':p['scope']}
(F/'RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps({'runs':total,'comparison_conditions':len(comparisons),'offsets':len(sweep),'WU_range':[min(c['deployed_WU_reduction_percent'] for c in comparisons),max(c['deployed_WU_reduction_percent'] for c in comparisons)],'time_change_range':[min(c['deployed_time_change_percent'] for c in comparisons),max(c['deployed_time_change_percent'] for c in comparisons)]},indent=2))
