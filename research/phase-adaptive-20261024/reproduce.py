from pathlib import Path
import json,subprocess,sys
HERE=Path(__file__).resolve().parent
def canonical(value):
 if isinstance(value,dict):return {k:canonical(v) for k,v in value.items() if k!='elapsed_seconds'}
 if isinstance(value,list):return [canonical(v) for v in value]
 return value
for script,result in [('closed_loop.py','CLOSED_LOOP_RESULTS.json'),('closed_loop_ablation.py','CLOSED_LOOP_ABLATION.json'),('sensitivity.py','SENSITIVITY_RESULTS.json'),('bootstrap_invariant.py','BOOTSTRAP_INVARIANT_RESULTS.json'),('admission_guard_check.py','ADMISSION_GUARD_RESULTS.json')]:
 p=subprocess.run([sys.executable,'-B',str(HERE/script)],cwd=HERE,capture_output=True,text=True,timeout=600)
 if p.returncode:raise RuntimeError(p.stdout+p.stderr)
 observed=json.loads((HERE/result).read_text())
 expected=json.loads((HERE/'expected'/result).read_text())
 assert canonical(observed)==canonical(expected),result
 print(result+': scientific fields match')
print('PASS: standalone program-model replay. This does not run RTL synthesis or establish full-system correctness.')
