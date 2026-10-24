"""Stdlib deterministic replay; sanitized counters only, no simulator/source required."""
from pathlib import Path
import json,csv,hashlib,argparse
ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path);a=ap.parse_args()
F=Path(__file__).resolve().parent;O=a.out or F;O.mkdir(parents=True,exist_ok=True)

# Exact-bound, data-only input loader. Encoded names are fixed below; no execution,
# extraction, remote fetch, arbitrary path, or filesystem write occurs.
import gzip,base64
ENCODED_INPUTS={'MEASUREMENTS.json': {'file': 'MEASUREMENTS.json.gz.b64', 'decoded_bytes': 342147, 'decoded_sha256': '8fca09273cdad47dfd2b4afe11f6b30c5805ad7cdb2fccef347cc5d1d5e5e730', 'encoded_bytes': 21112, 'encoded_sha256': '517804548ebb31a07a64071b4a4ca6bd1cb9e1cee0b8ec5b9acbe3d0454b5df3', 'encoding': 'gzip+base64'}, 'TRAIN_CANDIDATES.json': {'file': 'TRAIN_CANDIDATES.json.gz.b64', 'decoded_bytes': 252081, 'decoded_sha256': '8af30502ac722d6da4cecc6f18121f7f63197de5bc63719a120b490ed5936b78', 'encoded_bytes': 13572, 'encoded_sha256': 'e178d2d747e426d20aa8960297d65a4b6d2fc70a5fdfb6c2475714e6bd972c5f', 'encoding': 'gzip+base64'}}
def read_bound(name):
 if name not in ENCODED_INPUTS:return (F/name).read_bytes()
 b=ENCODED_INPUTS[name];encoded=(F/b['file']).read_bytes()
 assert len(encoded)==b['encoded_bytes'] and hashlib.sha256(encoded).hexdigest()==b['encoded_sha256']
 raw=gzip.decompress(base64.b64decode(encoded,validate=True))
 assert len(raw)==b['decoded_bytes'] and hashlib.sha256(raw).hexdigest()==b['decoded_sha256']
 return raw

sha=lambda p:hashlib.sha256(read_bound(p.name)).hexdigest()
d=json.loads(read_bound('MEASUREMENTS.json').decode('utf-8'));rules=json.loads((F/'FROZEN_RULES.json').read_text());candidates=json.loads(read_bound('TRAIN_CANDIDATES.json').decode('utf-8'));anchors=json.loads((F/'FROZEN_FASTEST_ANCHORS.json').read_text())
sel={x['cache']:x for x in rules['selection']};assert rules['heldout_rows_seen']==0
def save(name,rows):
 with (O/name).open('w',encoding='utf-8',newline='') as f:
  w=csv.DictWriter(f,fieldnames=list(rows[0]),lineterminator='\n');w.writeheader();w.writerows(rows)
def write(name,obj):(O/name).write_text(json.dumps(obj,indent=2)+'\n',encoding='utf-8',newline='\n')
def dominated(x,others):return any(y['J']<=x['J'] and y['WU']<=x['WU'] and (y['J']<x['J'] or y['WU']<x['WU']) for y in others)
records=[];epochs=[];original={}
metrics=['instructions','WU','misses','hits','replacements']
for r in d['rows']:
 c=r['case'];s=r['summary'];assert r['valid'] and c['P']==128 and c['cost']==8 and s['K_schedule']==c['K'] and s['tick_phase_cycles']==c['phi']
 assert r['simulator_sha256']=='08271cdc2858f14731698e18463d4c53dc60ac9b7091183c3aa9bae34c4ddf6a' and r['config_sha256']=='7349b98e8a0bd3ee17a26c38b9c770ab75396693cce0a0333fc4a658547ef0b9' and r['benchmark_sha256']=='2240805a3edaceb2741e7b0285f9dd1cdd07188395705322a8ca088206300096'
 assert [x['label'] for x in r['epoch_cumulative_metrics']]==['validation','fir','features','join']
 assert s['terminal']['code']==0 and not s['marker_errors'] and {x['id'] for x in s['phase_events']}=={0,1,2,10,11,12,13,99}
 helper=[0]+[int(c['K'][i]!=c['K'][i-1]) for i in [1,2]]+[0]
 prev={k:0 for k in metrics};tick=s['roi_start_tick'];ee=[]
 for i,e in enumerate(r['epoch_cumulative_metrics']):
  z={'cache':c['cache'],'N':c['N'],'phi':c['phi'],'kind':c['kind'],'id':c['id'],'epoch':e['label'],'J':(e['tick']-tick)/1000,**{k:e['metrics'][k]-prev[k] for k in metrics},'nominal_helper_calls':helper[i],'nominal_helper_quiesce_cycles':8*helper[i],'timeout_writes_at_start':4*helper[i] if c['kind']=='phase' else 0,'suppressed_writes_at_start':4*helper[i] if c['kind']=='suppress' else 0}
  assert all(z[k]>=0 for k in metrics);ee.append(z);epochs.append(z);prev=e['metrics'];tick=e['tick']
 assert sum(x['J'] for x in ee)==s['roi_ticks']/1000 and tick==s['roi_end_tick']
 assert all(sum(x[k] for x in ee)==r['total_metrics'][k] for k in metrics)
 assert s['timeout_register_writes']==sum(x['timeout_writes_at_start'] for x in ee) and s['suppressed_timeout_writes']==sum(x['suppressed_writes_at_start'] for x in ee)
 z={'cache':c['cache'],'N':c['N'],'phi':c['phi'],'kind':c['kind'],'K':','.join(map(str,c['K'])),'J':s['roi_ticks']/1000,**r['total_metrics'],'timeout_writes':s['timeout_register_writes'],'suppressed_timeout_writes':s['suppressed_timeout_writes'],'nominal_helper_calls':sum(helper),'nominal_helper_quiesce_cycles':8*sum(helper),'deployed':c['kind']==sel[c['cache']]['deployed_mode'],'origin':'R23 post-selection ablation' if r['group']=='post-selection' else 'R20 frozen original'}
 records.append(z);original[(c['cache'],c['N'],c['phi'],c['kind'])]=r
assert len(records)==72 and len(epochs)==288
pairs=[];deltas=[]
for cache in ['32KiB','64KiB']:
 for N in [16,32,36,40]:
  for phi in [0,64,127]:
   rr={x['kind']:x for x in records if (x['cache'],x['N'],x['phi'])==(cache,N,phi)};assert set(rr)=={'fixed','phase','suppress'}
   p,s,f=rr['phase'],rr['suppress'],rr['fixed'];pr=original[(cache,N,phi,'phase')];sr=original[(cache,N,phi,'suppress')]
   assert pr['summary']['command']==sr['summary']['command'] and pr['epoch_cumulative_metrics'][0]==sr['epoch_cumulative_metrics'][0]
   for x in rr.values():x['pareto_among_frozen_triple']=not dominated(x,list(rr.values()))
   row={'cache':cache,'N':N,'phi':phi,**{kind+'_'+m:rr[kind][m] for kind in ['fixed','phase','suppress'] for m in ['J','WU','misses','hits','instructions','replacements']}}
   for other in ['fixed','suppress']:
    for m in ['J','WU','misses','hits','instructions','replacements']:row['phase_minus_'+other+'_'+m]=p[m]-rr[other][m]
    row['phase_minus_'+other+'_J_pct']=100*(p['J']-rr[other]['J'])/rr[other]['J']
   row['phase_WU_reduction_vs_fixed_pct']=100*(f['WU']-p['WU'])/f['WU'];row['phase_WU_extra_vs_suppress_pct']=100*(p['WU']-s['WU'])/s['WU'];pairs.append(row)
   for epoch in ['validation','fir','features','join']:
    er={x['kind']:x for x in epochs if (x['cache'],x['N'],x['phi'],x['epoch'])==(cache,N,phi,epoch)}
    for other in ['fixed','suppress']:
     deltas.append({'cache':cache,'N':N,'phi':phi,'epoch':epoch,'comparison':'phase-minus-'+other,**{m:er['phase'][m]-er[other][m] for m in ['J',*metrics]},'phase_helper_quiesce_cycles':er['phase']['nominal_helper_quiesce_cycles'],'comparator_helper_quiesce_cycles':er[other]['nominal_helper_quiesce_cycles']})
# Recompute original max-offset training objective, without adding the new suppression ablation to its candidate set.
training=[]
for cache,ss in sel.items():
 groups={}
 for x in candidates:
  if x['cache']==cache:groups.setdefault((x['kind'],tuple(x['K'])),[]).append(x)
 assert len(groups)==279
 aa=[]
 for (kind,K),rr in groups.items():
  assert len(rr)==3 and {x['phi'] for x in rr}=={0,64,127}
  aa.append({'cache':cache,'kind':kind,'K':','.join(map(str,K)),'J':max(x['J'] for x in rr),'WU':max(x['WU'] for x in rr),'original_candidate':True})
 fastest=min((x for x in aa if x['kind']=='fixed'),key=lambda x:(x['J'],x['K']))
 assert fastest['J']==ss['fastest_fixed']['max_J']
 for x in aa:x['training_cap_cycles']=fastest['J']*1001/1000;x['eligible']=x['J']*1000<=fastest['J']*1001;x['pareto_original_candidates']=not dominated(x,aa)
 for kind in ['fixed','phase']:
  eligible=[x for x in aa if x['kind']==kind and x['eligible']]
  if eligible:
   winner=min(eligible,key=lambda x:(x['WU'],x['J'],tuple(map(int,x['K'].split(',')))))
   assert winner['K']==','.join(map(str,ss[kind]['K']))
  else:assert cache=='64KiB' and kind=='phase'
 training+=aa
caps=[]
for cache,ss in sel.items():
 for N in [16,32,36,40]:
  ar=[x for x in anchors if (x['cache'],x['N'])==(cache,N)];assert len(ar)==3
  anchor=max(x['J'] for x in ar);row={'cache':cache,'N':N,'identity':'original training cap' if N==16 else 'same-N postfreeze diagnostic cap','anchor_frozen_fastest_K':','.join(map(str,ar[0]['K'])),'anchor_maxJ':anchor,'cap_cycles':anchor*1001/1000}
  for kind in ['fixed','phase','suppress']:
   rr=[x for x in records if (x['cache'],x['N'],x['kind'])==(cache,N,kind)];assert len(rr)==3
   row[kind+'_maxJ']=max(x['J'] for x in rr);row[kind+'_maxWU']=max(x['WU'] for x in rr);row[kind+'_fits_cap']=row[kind+'_maxJ']*1000<=anchor*1001
  caps.append(row)
for name,rows in [('PARETO_INPUTS.csv',records),('PAIRED.csv',pairs),('EPOCHS.csv',epochs),('EPOCH_DELTAS.csv',deltas),('TRAINING_PARETO.csv',training),('CAPS.csv',caps)]:save(name,rows)
save('N32_32KiB_NINE_POINTS.csv',[x for x in records if x['cache']=='32KiB' and x['N']==32])
plotrows=[]
for x in records:
 f=next(y for y in records if (y['cache'],y['N'],y['phi'],y['kind'])==(x['cache'],x['N'],x['phi'],'fixed'))
 plotrows.append({'N':x['N'],'cache':x['cache'],'phi':x['phi'],'policy':x['kind'],'J':x['J'],'WU':x['WU'],'paired_fixed_J':f['J'],'paired_fixed_WU':f['WU'],'pareto_among_frozen_triple':x['pareto_among_frozen_triple'],'origin':x['origin']})
save('PARETO.csv',plotrows)
def signs(name):
 vals=[r[name] for r in pairs];return {'negative':sum(v<0 for v in vals),'zero':sum(v==0 for v in vals),'positive':sum(v>0 for v in vals),'min':min(vals),'max':max(vals)}
audit={'records':72,'old_records':66,'new_post_selection_records':6,'same_offset_pairs':24,'epoch_rows':288,'epoch_delta_rows':192,'all_epoch_sums_exact':True,'matched_guest_command_and_validation_epoch_equal':True,'new_checksums':d['new_six']['checksums'],'input_sha256':{n:sha(F/n) for n in ['MEASUREMENTS.json','FROZEN_RULES.json','TRAIN_CANDIDATES.json','FROZEN_FASTEST_ANCHORS.json']},'signed_pair_counts':{x:signs(x) for x in pairs[0] if x.startswith('phase_minus_') and not x.endswith('_pct')},'caps':caps,'frozen_policies_unchanged':True,'scope':'whole-system deterministic counters; neither per-consumer attribution nor timer-only causal isolation nor WCET'}
audit['signed_epoch_counts']={comparison:{m:{'negative':sum(x[m]<0 for x in deltas if x['comparison']==comparison),'zero':sum(x[m]==0 for x in deltas if x['comparison']==comparison),'positive':sum(x[m]>0 for x in deltas if x['comparison']==comparison)} for m in ['J',*metrics]} for comparison in ['phase-minus-fixed','phase-minus-suppress']}
write('AUDIT.json',audit)
lines=['# R23 same-offset native tradeoffs','','Six preregistered N16 post-selection matched-suppression cases completed; all six pass checksum 1099140816896, terminal/marker/invariant checks. Binary/config/ELF and private source hashes match before/after. Original R20 frozen candidates and policies are unchanged. Replay uses only Python stdlib: `python -B -X utf8 replay.py --out replay-output`.','','## Complete six-case ablation','','| cache | phi | phase J / WU | suppression J / WU | phase minus suppression cycles / WU |','|---|---:|---:|---:|---:|']
for p in pairs:
 if p['N']==16:lines.append(f"| {p['cache']} | {p['phi']} | {p['phase_J']:,.0f} / {p['phase_WU']:,.0f} | {p['suppress_J']:,.0f} / {p['suppress_WU']:,.0f} | {p['phase_minus_suppress_J']:+,.0f} / {p['phase_minus_suppress_WU']:+,.0f} |")
lines+=['','## Cap identities and all outcomes','','The original training cap is the max over the three declared offsets, multiplied by 1.001. The objective first rejects over-cap candidates, then minimizes max-WU, max-J and lexicographic K. Suppression was not a training candidate; applying that cap to the new measurements is explicitly retrospective. Heldout caps below reuse the frozen fastest-time K on each same-N input; no heldout choice is selected. They are different absolute caps and no admission/WCET guarantees.','','| cache | N | cap | fixed maxJ / fits | phase maxJ / fits | suppression maxJ / fits |','|---|---:|---:|---:|---:|---:|']
for r in caps:lines.append(f"| {r['cache']} | {r['N']} | {r['cap_cycles']:,.3f} | {r['fixed_maxJ']:,.0f} / {r['fixed_fits_cap']} | {r['phase_maxJ']:,.0f} / {r['phase_fits_cap']} | {r['suppress_maxJ']:,.0f} / {r['suppress_fits_cap']} |")
lines+=['','At N16/32KiB the new suppression max479417 exceeds the original cap478204.727, while phase477808 fits and reduces max-WU638→550 versus the eligible fixed. This retrospectively explains the measured tradeoff against suppression under that cap, without adding suppression to the original search. At64KiB suppression476664 and phase475486 both exceed475416.942, so the original fixed deployment remains appropriate under the frozen rule.']
lines+=['','## Same-offset Pareto comparison','','PARETO_INPUTS.csv retains every one of 72 selected-policy points, PAIRED.csv all 24 matched triples, and N32_32KiB_NINE_POINTS.csv the requested nine primary points. Pareto flags compare actual J/WU from the same offset only. Different maxima are never joined into a measured point. TRAINING_PARETO.csv separately retains all 558 original candidate aggregates; suppression is absent from that original search.','','| phi | fixed J / WU | phase J / WU | suppression J / WU |','|---:|---:|---:|---:|']
for p in pairs:
 if p['cache']=='32KiB' and p['N']==32:lines.append(f"| {p['phi']} | {p['fixed_J']:,.0f} / {p['fixed_WU']:,.0f} | {p['phase_J']:,.0f} / {p['phase_WU']:,.0f} | {p['suppress_J']:,.0f} / {p['suppress_WU']:,.0f} |")
lines+=['','## Intervention and attribution limits','','The config initializes all caches with the first K (K1 for both phase and suppression), keeps the identical guest stage-load environment and helper work, and suppresses calls to hushSetPhaseTimeout at changed boundaries. Source cache.cc242-261 shows that this removes prospective default changes and the corresponding configuration-edge receiver hold trigger. The independent late-fill/expiry/capture hold condition remains (cache.cc2113-2117). Suppression remains coherent HUSH with expiry; it is neither no-coherence nor a pure timer-only intervention. Equal guest commands and first cumulative epochs are checked, but later instructions, memory accesses and schedules can diverge. Phase-minus-suppression therefore measures the whole future-timeout intervention, including its event/scheduling effects.','','EPOCHS.csv provides validation/FIR/features/join whole-system hits, misses, WU, instructions, replacements and J for all 72 points; all 288 rows reconcile exactly. EPOCH_DELTAS.csv retains all 192 phase-minus-fixed/suppression signed epoch comparisons. These epochs include the concurrent writer, readers, barriers and helpers; they do not isolate an individual consumer. Nominal helper quiesce is 8 cycles per changed marker: two calls (16 cycles) for 32KiB phase/suppression and one call (8 cycles) for 64KiB phase/suppression, zero for fixed. Marker1 helper belongs to FIR, marker2 helper to features. The nominal guest stalls cannot be subtracted as an exact joint-time cost because other cores progress concurrently.','','At 32KiB N32, phase trades fewer cycles for substantially more WU than suppression; both lie on a measured time/traffic tradeoff. Phase itself also misses the same-N frozen-fastest diagnostic cap. The frozen decision to deploy phase is justified by the original eligible-family N16 objective; it does not establish unconditional superiority over suppression. At64KiB the frozen deployment remains fixed; phase is diagnostic. All signs, including zero and adverse deltas, are retained in the CSVs and AUDIT.json.']
lines+=['','## Primary epoch example:32KiB N32 phi0','','| epoch | policy | hits | misses | WU | J | nominal helper cycles |','|---|---|---:|---:|---:|---:|---:|']
for e in epochs:
 if (e['cache'],e['N'],e['phi'])==('32KiB',32,0):lines.append(f"| {e['epoch']} | {e['kind']} | {e['hits']:,.0f} | {e['misses']:,.0f} | {e['WU']:,.0f} | {e['J']:,.0f} | {e['nominal_helper_quiesce_cycles']} |")
lines+=['','Compared with fixed at this offset, phase saves101 WU during validation and226 during features, but adds128 during FIR and1 at join (net−198). FIR misses rise120; features misses fall214. These observations support a phase-dependent whole-system traffic redistribution; they do not support a claim that the long FIR setting universally improves hit rate or that every phase gets faster. Compared with suppression, phase FIR is1525cycles faster with1375 moreWU and1294 moremisses; features is217cycles slower. Scheduling/instruction differences preclude interpreting these deltas as a timer-only causal benefit.']
(O/'RESULTS.md').write_text('\n'.join(lines)+'\n',encoding='utf-8',newline='\n')
print(json.dumps({'records':len(records),'pairs':len(pairs),'epochs':len(epochs),'caps':caps,'signed_J':{x:signs(x) for x in ['phase_minus_fixed_J','phase_minus_suppress_J']}}))
