from pathlib import Path
import tempfile,zipfile,subprocess,sys,json,hashlib,argparse,shutil
P=Path(__file__).resolve().parent
a=argparse.ArgumentParser();a.add_argument('--yosys');args=a.parse_args()
manifest=json.loads((P/'MANIFEST.json').read_text())
for r in manifest['files']:
 assert hashlib.sha256((P/r['path']).read_bytes()).hexdigest()==r['sha256'],r['path']
with tempfile.TemporaryDirectory(prefix='hush-native-replay-') as tmp:
 d=Path(tmp)
 with zipfile.ZipFile(P/'native-inputs.zip') as z:
  assert len(z.namelist())==60 and z.testzip() is None
  for n in z.namelist():assert not Path(n).is_absolute() and '..' not in Path(n).parts
  z.extractall(d)
 for n in ['replay.py','independent_check.py','gap-study/replay.py','gap-study/independent_check.py']:
  r=subprocess.run([sys.executable,'-B','-X','utf8',str(d/n)],cwd=d,capture_output=True,text=True)
  assert r.returncode==0,(n,r.stdout,r.stderr)
 receipt=json.loads((P/'period256/PROOF_RECEIPT.json').read_text())
 assert len(receipt['cases'])==4
 for c in receipt['cases']:
  p=P/'period256'/c['case'];assert hashlib.sha256(p.read_bytes()).hexdigest()==c['source_sha256']
  if args.yosys:
   shutil.copy2(p,d/c['case'])
   command=f"read_verilog -formal -sv {c['case']}; prep -top timer_step_induction -flatten; chformal -lower; sat -set-assumes -prove-asserts -verify"
   r=subprocess.run([args.yosys,'-p',command],cwd=d,capture_output=True,text=True)
   success=r.returncode==0 and 'SAT proof finished - no model found: SUCCESS!' in r.stdout
   assert success==c['expected_success'],(c['case'],r.stdout[-3000:],r.stderr[-1000:])
 print(json.dumps({'all294_native_cases_replayed':True,'all882_signed_pairs_checked':True,'original_training_selection_unchanged':True,'all_four_period256_sources_verified':True,'fresh_yosys_four_case_rerun':bool(args.yosys)}))
