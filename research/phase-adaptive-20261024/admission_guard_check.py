from pathlib import Path
import json
import closed_loop as c
ops=[('phase',0),('read',0)]
new=c.simulate(ops,(32,32,32),0,0,writer_count=16)
detected=False
try:c.simulate(ops,(32,32,32),0,0,writer_count=16,admission_guard=False)
except AssertionError:detected=True
assert detected
result={'case':'single cold read, 16 zero-compute private writer stores',
        'guarded_reader_cycles':new['reader_cycles'],'reader_bound':new['reader_bound'],
        'guarded_max_read_service':new['max_read_service'],
        'unguarded_bound_violation_detected':detected,
        'scope':'service-admission counterexample, not a rerun of legacy gem5 40/204 bounds'}
(Path(__file__).parent/'ADMISSION_GUARD_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result))
