"""Retain selected native counters from the completed legacy-pair observation."""
from pathlib import Path
import argparse,hashlib,json
F=Path(__file__).resolve().parent
ap=argparse.ArgumentParser();ap.add_argument('--input',type=Path,default=F/'legacy-status1-client.json');ap.add_argument('--output',type=Path,default=F/'DATA_LEGACY_PAIRS.json');a=ap.parse_args()
original=json.loads(a.input.read_text(encoding='utf-8'));source=original.get('observation',original);raw=source['rows']
assert len(raw)==30 and all(x['valid'] for x in raw)
def metrics(s):
    return {'instructions':s['simInsts'],'WU':s['system.membus.hushUpdateAccepted'],
        'misses':sum(v for k,v in s.items() if k.startswith('system.l1s') and k.endswith('overallMisses::total')),
        'hits':sum(v for k,v in s.items() if k.startswith('system.l1s') and k.endswith('overallHits::total')),
        'replacements':sum(v for k,v in s.items() if k.startswith('system.l1s') and k.endswith('.replacements')),
        'timer_starts':sum(v for k,v in s.items() if k.startswith('system.l1s') and k.endswith('.hushTimerStarts')),
        'timer_restarts':sum(v for k,v in s.items() if k.startswith('system.l1s') and k.endswith('.hushTimerRestarts')),
        'timer_expiries':sum(v for k,v in s.items() if k.startswith('system.l1s') and k.endswith('.hushTimerLiveExpiries')),
        'commit_instructions_per_core':[s[f'system.cpu{i}.commitStats0.numInsts'] for i in range(4)]}
rows=[]
for x in raw:
    assert x['test_pass'] and x['returncode']==0 and not x['invariant_failures']
    rows.append({**{k:x[k] for k in ['case','valid','returncode','test_pass','summary','config_sha256','benchmark_sha256']},
        'total_metrics':metrics(x['statistics']),
        'epoch_cumulative_metrics':[{k:v for k,v in e.items() if k!='statistics'}|{'metrics':metrics(e['statistics'])} for e in x['epoch_statistics']],
        'source_record_canonical_sha256':hashlib.sha256(json.dumps(x,sort_keys=True,separators=(',',':')).encode()).hexdigest()})
out={'rows':rows,'raw_input_sha256':hashlib.sha256(a.input.read_bytes()).hexdigest()}
a.output.write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps({'valid_rows':len(rows),'output_bytes':a.output.stat().st_size}))
