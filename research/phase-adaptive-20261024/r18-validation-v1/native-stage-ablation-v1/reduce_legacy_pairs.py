"""Pairwise prospective-T intervention, preserving guest bytes/control/stall."""
from pathlib import Path
import csv,hashlib,json
F=Path(__file__).resolve().parent
data=json.loads((F/'DATA_LEGACY_PAIRS.json').read_text(encoding='utf-8'))
rows=data['rows'];manifest=json.loads((F/'LEGACY_PAIRS_MANIFEST.json').read_text(encoding='utf-8'))
assert len(rows)==30 and {x['case']['id'] for x in rows}=={x['id'] for x in manifest['cases']}
assert len({x['benchmark_sha256'] for x in rows})==len({x['config_sha256'] for x in rows})==1
old=json.loads((F/'DATA.json').read_text(encoding='utf-8'))['rows'];byid={x['case']['id']:x for x in rows}
scalar=['instructions','WU','misses','hits','replacements','timer_starts','timer_restarts','timer_expiries']
epochs=[];pairs=[];replications=[]
for x in rows:
    c=x['case'];s=x['summary'];assert x['valid'] and x['returncode']==0 and x['test_pass'] and not s['marker_errors'] and s['terminal']['code']==0
    assert c['legacy_layout'] and s['cost_layout']=='legacy' and s['api_write_policy']==c['write_policy']
    assert len(s['phase_events'])==8 and {e['id'] for e in s['phase_events']}=={0,1,2,10,11,12,13,99}
    e=x['epoch_cumulative_metrics'];assert [z['label'] for z in e]==['validation','fir','features','join']
    prev={k:0 for k in scalar};tick=s['roi_start_tick'];group=[]
    events={z['id']:z['tick'] for z in s['phase_events']}
    ends=[events[1],events[2],max(events[k] for k in [10,11,12,13]),events[99]]
    for idx,z in enumerate(e):
        assert z['tick']==ends[idx] and z['tick']>=tick
        delta={k:z['metrics'][k]-prev[k] for k in scalar};assert all(v>=0 for v in delta.values())
        group.append({'id':c['id'],'N':c['N'],'kind':c['kind'],'cost':c['cost'],'epoch':z['label'],'cycles':(z['tick']-tick)/1000,**delta})
        prev={k:z['metrics'][k] for k in scalar};tick=z['tick']
    assert sum(z['cycles'] for z in group)==s['roi_ticks']/1000
    assert all(sum(z[k] for z in group)==x['total_metrics'][k] for k in scalar)
    assert sum(x['total_metrics']['commit_instructions_per_core'])==x['total_metrics']['instructions']
    epochs.extend(group)
for n in [32,36,40]:
    for cost in [0,8,16,32,64]:
        a=byid[f'n{n}-legacy-apply-cost{cost}'];s=byid[f'n{n}-legacy-suppress-cost{cost}']
        assert a['summary']['command']==s['summary']['command']
        assert a['epoch_cumulative_metrics'][:2]==s['epoch_cumulative_metrics'][:2]
        assert a['summary']['timeout_register_writes']==4 and a['summary']['suppressed_timeout_writes']==0
        assert s['summary']['timeout_register_writes']==0 and s['summary']['suppressed_timeout_writes']==4
        at=a['summary']['roi_ticks'];st=s['summary']['roi_ticks']
        pairs.append({'N':n,'cost':cost,'apply_J':at/1000,'suppressed_J':st/1000,
            'TTL_reduction_cycles':(st-at)/1000,'TTL_reduction_percent':100*(st-at)/st,
            'apply_WU':a['total_metrics']['WU'],'suppressed_WU':s['total_metrics']['WU'],
            'apply_misses':a['total_metrics']['misses'],'suppressed_misses':s['total_metrics']['misses'],
            'pre_intervention_epochs_exact':True})
        if cost==8:
            ref=next(x for x in old if x['case']['N']==n and x['case']['kind']=='legacy-phase')
            assert a['summary']['roi_ticks']==ref['summary']['roi_ticks']
            assert [{'id':e['id'],'tick':e['tick']} for e in a['summary']['phase_events']]==[{'id':e['id'],'tick':e['tick']} for e in ref['summary']['phase_events']]
            assert a['total_metrics']==ref['total_metrics']
            assert a['epoch_cumulative_metrics']==ref['epoch_cumulative_metrics']
            replications.append({'N':n,'all_original_phase_ticks_and_selected_counters_exact':True})
fixed32=next(x for x in old if x['case']['N']==32 and x['case']['kind']=='legacy-fixed')['summary']['roi_ticks']/1000
pair32=next(x for x in pairs if x['N']==32 and x['cost']==8)
original_gain=fixed32-pair32['apply_J'];remaining=fixed32-pair32['suppressed_J']
five=json.loads((F/'SUMMARY.json').read_text(encoding='utf-8'))
all_effects=[x['TTL_reduction_percent'] for x in pairs]+five['matched_mechanism_reduction_range']
summary={'runs':30,'all_valid':True,'matched_pairs':15,'pre_intervention_epoch_pairs_exact':15,
    'old_cost8_phase_points_reproduced':replications,'all_epoch_counters_reconcile':True,
    'legacy_TTL_reduction_percent_range':[min(x['TTL_reduction_percent'] for x in pairs),max(x['TTL_reduction_percent'] for x in pairs)],
    'combined_layout_matched_pairs':30,'combined_TTL_reduction_percent_range':[min(all_effects),max(all_effects)],
    'N32_cost8_decomposition':{'original_fixed_J':fixed32,**pair32,'original_fixed_vs_phase_gain_cycles':original_gain,
        'fixed_vs_suppressed_gain_cycles':remaining,'fraction_original_difference_remaining_under_suppression':remaining/original_gain},
    'scope':'Matched counterfactual implementation diagnostic conditional on initial timeout16384. The residual versus the best fixed policy also includes differing initial constant timeouts, control and interleaving; it does not isolate these components. No policy retuning or native acceleration claim is inferred.'}
def out(name,obj):
    (F/name).write_text(json.dumps(obj,indent=2)+'\n',encoding='utf-8',newline='\n')
def savecsv(name,records):
    with (F/name).open('w',encoding='utf-8',newline='') as stream:
        writer=csv.DictWriter(stream,fieldnames=list(records[0]),lineterminator='\n');writer.writeheader();writer.writerows(records)
savecsv('LEGACY_PAIR_COSTS.csv',pairs);savecsv('LEGACY_PAIR_EPOCHS.csv',epochs)
out('LEGACY_PAIRS_SUMMARY.json',summary)
print(json.dumps(summary,indent=2))
