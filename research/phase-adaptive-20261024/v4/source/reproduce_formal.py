from pathlib import Path
import sys,subprocess,tempfile,shutil,os,json
H=Path(__file__).resolve().parent;y=Path(sys.argv[1]).resolve()
env=dict(os.environ);env['PATH']=str(y.parent)+os.pathsep+str(y.parent.parent/'lib')+os.pathsep+env['PATH']
rows=[]
with tempfile.TemporaryDirectory(prefix='hush-formal-') as tmp:
 p=Path(tmp)
 for f in sorted(H.glob('step_*.v'))+sorted(H.glob('refinement_*.v')):
  shutil.copy2(f,p/f.name);top='inductive_step' if f.name.startswith('step_') else 'refinement'
  if top=='inductive_step':top='timer_step_induction'
  cmd=f'read_verilog -formal -sv {f.name}; prep -top {top} -flatten; chformal -lower; sat -set-assumes -prove-asserts -verify'
  r=subprocess.run([str(y),'-Q','-T','-p',cmd],cwd=p,env=env,capture_output=True,text=True,timeout=300)
  success=r.returncode==0 and 'SUCCESS!' in r.stdout
  expected=f.stem.endswith('_correct')
  assert success==expected,(f.name,r.stdout[-1800:],r.stderr)
  rows.append({'case':f.stem,'proof_succeeded':success});print(rows[-1],flush=True)
(H/'FORMAL_REPLAY.json').write_text(json.dumps(rows,indent=2)+'\n')
