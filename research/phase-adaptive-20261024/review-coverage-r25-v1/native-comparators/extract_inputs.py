"""Extract allowlisted scalars from the immutable, public R20 measurements.

No simulator execution. Run with --r20 pointing at public-native-quantized-v1;
--r24 optionally cross-checks its MEASUREMENTS.json projection independently.
"""
from pathlib import Path
import argparse, base64, csv, hashlib, io, json, zipfile

P = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--r20', type=Path, required=True)
ap.add_argument('--r24', type=Path)
ap.add_argument('--out', type=Path, default=P)
a = ap.parse_args()
a.out.mkdir(parents=True, exist_ok=True)
sha = lambda b: hashlib.sha256(b).hexdigest()
canonical = lambda x: json.dumps(x, sort_keys=True, separators=(',', ':')).encode()
m = json.loads((a.r20/'RECORDED_DATA.json').read_text())
assert all('/' not in n and '\\' not in n and n.startswith('DATA-') and n.endswith('.b64') for n in m['parts'])
raw = base64.b64decode(''.join((a.r20/n).read_text().strip() for n in m['parts']), validate=True)
assert sha(raw) == m['zip_sha256']
with zipfile.ZipFile(io.BytesIO(raw)) as z:
    assert z.namelist() == ['DATA.json']
    b = z.read('DATA.json')
assert len(b) == m['member_bytes'] and sha(b) == m['member_sha256']
data = json.loads(b)
rr = data['rows']
assert len(rr) == 2457
assert [sum(r['group'] == g for r in rr) for g in ['train', 'validation', 'offset']] == [1686, 396, 375]
protocol = json.loads((a.r20/'PROTOCOL.json').read_text())
assert protocol['heldout_fixed_loads_K'] == [1,2,4,6,8,12,16,24,32,64,96,128,160,192,254,255]
fraw = (a.r20/'FROZEN_SELECTION.json').read_bytes()
f = json.loads(fraw)
assert f['heldout_rows_seen'] == 0
freeze = [{k: v for k, v in s.items() if k != 'all_training_aggregates'} for s in f['selection']]
fmap = {s['cache']: s for s in freeze}
def role(c):
    s = fmap[c['cache']]
    if c['kind'] == 'fixed':
        for role_name, K in [('K1', [1,1,1]), ('frozen_fixed', s['fixed']['K']), ('frozen_fastest', s['fastest_fixed']['K'])]:
            if c['K'] == K: return role_name
    if c['kind'] in ['phase', 'suppress']: return c['kind']
    return {'predictable-wi': 'WI', 'wu-of': 'WU'}.get(c['mode'])
def project(r):
    c, s = r['case'], r['summary']
    assert r['valid'] and not s['marker_errors'] and s['terminal']['code'] == 0
    assert s['timer_period_cycles'] == c['P'] == 128 and s['tick_phase_cycles'] == c['phi']
    assert s['roi_ticks'] % 1000 == 0
    assert c['N'] in [16,32,36,40] and c['cost'] == (8 if c['mode'] == 'hush' else 0)
    assert c['lags'] == c['perline'] == 64 and c['pattern'] == 1 and not c['legacy_layout']
    assert s['schedule_cycles'] == [k*128 for k in c['K']]
    if c['mode'] == 'hush': assert s['K_schedule'] == c['K']
    WU = r['total_metrics']['WU']
    assert WU == int(WU)
    assert sum(e['metrics']['WU'] - (r['epoch_cumulative_metrics'][i-1]['metrics']['WU'] if i else 0) for i,e in enumerate(r['epoch_cumulative_metrics'])) == WU
    return {'id':c['id'], 'cache':c['cache'], 'N':c['N'], 'phi':c['phi'], 'kind':c['kind'], 'mode':c['mode'], 'K':','.join(map(str,c['K'])), 'write_policy':c['write_policy'], 'J_cycles':s['roi_ticks']//1000, 'WU':int(WU), 'original_record_sha256':sha(canonical(r))}
training = [project(r) for r in rr if r['group']=='train' and r['case']['kind'] in ['fixed','phase']]
heldout = [{**project(r), 'policy':role(r['case'])} for r in rr if r['group']=='validation' and role(r['case']) is not None]
diagnostics = [{**project(r), 'predeclared_16':r['case']['K'][0] in protocol['heldout_fixed_loads_K']} for r in rr if r['group']=='validation' and r['case']['kind']=='fixed']
assert len(training) == 1674 and len(heldout) == 126
assert len(diagnostics) == 324 and sum(r['predeclared_16'] for r in diagnostics) == 288
assert len({(r['cache'],r['N'],r['phi'],r['policy']) for r in heldout}) == 126
assert {r['policy'] for r in heldout} == {'K1','WI','WU','frozen_fixed','frozen_fastest','phase','suppress'}
source_by_id = {r['case']['id']:r for r in rr}
for r in heldout:
    if r['policy'] == 'phase':
        s = next(x for x in heldout if (x['cache'],x['N'],x['phi'],x['policy']) == (r['cache'],r['N'],r['phi'],'suppress'))
        x,y = source_by_id[r['id']],source_by_id[s['id']]
        assert x['case']['K'] == y['case']['K'] == fmap[r['cache']]['phase']['K']
        assert x['summary']['command'] == y['summary']['command']
        assert x['epoch_cumulative_metrics'][0] == y['epoch_cumulative_metrics'][0]
checks = 0
if a.r24:
    r24 = json.loads((a.r24/'MEASUREMENTS.json').read_text())['rows']
    for r in r24:
        if r['group'] == 'validation':
            old = source_by_id[r['case']['id']]
            assert r['case'] == old['case']
            assert r['summary']['roi_ticks'] == old['summary']['roi_ticks']
            assert r['total_metrics'] == old['total_metrics']
            checks += 1
    assert checks == 54
def save_csv(name, rows):
    with (a.out/name).open('w',encoding='utf-8',newline='') as o:
        w=csv.DictWriter(o,fieldnames=list(rows[0]),lineterminator='\n');w.writeheader();w.writerows(rows)
save_csv('TRAINING_ROWS.csv',training)
save_csv('HELDOUT_ROWS.csv',heldout)
save_csv('FIXED_DIAGNOSTICS.csv',diagnostics)
(a.out/'FROZEN_RULES.json').write_text(json.dumps({'heldout_rows_seen':0,'selection':freeze},indent=2)+'\n',encoding='utf-8',newline='\n')
bindings = {'source':'public R20 native-quantized-v1; recorded measurements, no new execution', 'original_archive_sha256':sha(raw), 'original_member_sha256':sha(b), 'original_member_bytes':len(b), 'original_frozen_selection_sha256':sha(fraw), 'original_protocol_sha256':sha((a.r20/'PROTOCOL.json').read_bytes()), 'original_rows':len(rr), 'training_rows_retained':len(training), 'heldout_rows_retained':len(heldout), 'fixed_diagnostic_rows_retained':len(diagnostics), 'R24_validation_rows_crosschecked':checks, 'same_ELF_simulator_config_driver': {k:next(iter({r[k] for r in rr})) for k in ['benchmark_sha256','simulator_sha256','config_sha256','driver_sha256']}, 'inputs':{n:{'sha256':sha((a.out/n).read_bytes()),'bytes':(a.out/n).stat().st_size} for n in ['TRAINING_ROWS.csv','HELDOUT_ROWS.csv','FIXED_DIAGNOSTICS.csv','FROZEN_RULES.json']}}
for k in bindings['same_ELF_simulator_config_driver']:
    assert len({r[k] for r in rr})==1
(a.out/'INPUT_BINDINGS.json').write_text(json.dumps(bindings,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps({k:v for k,v in bindings.items() if k in ['original_rows','training_rows_retained','heldout_rows_retained','R24_validation_rows_crosschecked']}))
