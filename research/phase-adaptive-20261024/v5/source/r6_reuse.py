"""Freeze selections from the tight-budget study and change only held-out inputs."""
from pathlib import Path
from itertools import product
import hashlib
import json
import time
import interlocked_model as c

HERE = Path(__file__).resolve().parent
source = HERE / 'INTERLOCKED_TIGHT_BUDGET_RESULTS.json'
if (HERE / 'expected/INTERLOCKED_TIGHT_BUDGET_RESULTS.json').exists():
    source = HERE / 'expected/INTERLOCKED_TIGHT_BUDGET_RESULTS.json'
protocol = HERE / 'r6_reuse_protocol.json'
proto = json.loads(protocol.read_text())
old = json.loads(source.read_text())
start = time.perf_counter()
rows = []
for i, case in enumerate(old['rows']):
    c.P.clear()
    c.P.update(case['parameters'])
    ops = c.instructions(case['spec']['family'], 512)
    for p in case['points']:
        phase = p['phase']
        fixed = p['fixed_maintenance']
        pk = tuple(phase['execution']['K'])
        fk = tuple(fixed['execution']['K'])
        mask = tuple(fixed.get('flush_boundaries', ()))
        pa = c.analyze(ops, pk)
        fa = c.analyze(ops, fk, flush_at_boundaries=mask)
        assert pa['bound'] == phase['bound'] <= p['budget']
        assert fa['bound'] == fixed['bound'] <= p['budget']
        for gap, phi in product(proto['writer_gaps'], (0, c.P['period'] - 1)):
            pr = c.simulate(ops, pk, gap, phi, pa, flush_at_finish=True)
            fr = c.simulate(ops, fk, gap, phi, fa,
                            flush_at_boundaries=mask, flush_at_finish=True)
            assert pr['reader_cycles'] <= p['budget'] and fr['reader_cycles'] <= p['budget']
            rows.append({'case': i, 'spec': case['spec'], 'slack': p['slack'],
                         'budget': p['budget'], 'writer_gap': gap, 'phi': phi,
                         'fixed_flush_boundaries': list(mask), 'phase': pr, 'fixed': fr})
    if (i + 1) % 10 == 0:
        print(f"{i+1}/{len(old['rows'])} cases; {time.perf_counter()-start:.1f}s", flush=True)

def summarize(xs):
    gains = [1 - r['phase']['makespan'] / r['fixed']['makespan'] for r in xs]
    return {'runs': len(xs), 'wins': sum(g > 0 for g in gains),
            'ties': sum(g == 0 for g in gains), 'losses': sum(g < 0 for g in gains),
            'max_gain_fraction': max(gains), 'max_regression_fraction': -min(gains),
            'all_deadlines_met': all(r[n]['reader_cycles'] <= r['budget'] for r in xs for n in ['phase', 'fixed']),
            'unsafe_hits': sum(r[n]['unsafe_hits'] for r in xs for n in ['phase', 'fixed'])}

out = {'protocol_sha256': hashlib.sha256(protocol.read_bytes()).hexdigest(),
       'selection_source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
       'model_sha256': hashlib.sha256((HERE/'interlocked_model.py').read_bytes()).hexdigest(),
       'script_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
       'summary': summarize(rows),
       'by_slack': {str(s): summarize([r for r in rows if r['slack'] == s]) for s in sorted({r['slack'] for r in rows})},
       'rows': rows, 'elapsed_seconds': time.perf_counter() - start}
(HERE/'R6_REUSE_RESULTS.json').write_text(json.dumps(out, indent=2)+'\n')
print(json.dumps({k: v for k, v in out.items() if k != 'rows'}, indent=2))
