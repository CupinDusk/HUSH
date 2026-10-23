from pathlib import Path
import json,subprocess,sys
H=Path(__file__).resolve().parent
def canonical(v):
 if isinstance(v,dict):return {k:canonical(x) for k,x in v.items() if k!='elapsed_seconds'}
 if isinstance(v,list):return [canonical(x) for x in v]
 return v
PAIRS=[('interlocked_model.py', 'INTERLOCKED_CLOSED_LOOP_RESULTS.json'), ('interlocked_ablation.py', 'INTERLOCKED_CLOSED_LOOP_ABLATION.json'), ('interlocked_sensitivity.py', 'INTERLOCKED_SENSITIVITY_RESULTS.json'), ('interlocked_release_sensitivity.py', 'INTERLOCKED_RELEASE_INTERLOCKED_SENSITIVITY_RESULTS.json'), ('interlocked_tight_budget.py', 'INTERLOCKED_TIGHT_BUDGET_RESULTS.json'), ('interlocked_kernel_study.py', 'INTERLOCKED_KERNEL_RESULTS.json'), ('interlocked_flush_control.py', 'INTERLOCKED_FLUSH_CONTROL_RESULTS.json'), ('interlocked_bootstrap.py', 'INTERLOCKED_BOOTSTRAP_INVARIANT_RESULTS.json')]
for script,result in PAIRS:
 p=subprocess.run([sys.executable,'-B',str(H/script)],cwd=H,capture_output=True,text=True,timeout=600)
 assert p.returncode==0,p.stdout+p.stderr
 assert canonical(json.loads((H/result).read_text()))==canonical(json.loads((H/'expected'/result).read_text())),result
 print(result+': all scientific fields match',flush=True)
print('PASS: standalone model/kernel replay; not full-system validation.')
