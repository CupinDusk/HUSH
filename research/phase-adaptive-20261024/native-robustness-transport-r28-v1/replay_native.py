from pathlib import Path,PurePosixPath
import tempfile,zipfile,subprocess,sys,json,hashlib
P=Path(__file__).resolve().parent
r=json.loads((P/'NATIVE_MANIFEST.json').read_text());archive=P/'native-inputs.zip'
assert archive.stat().st_size==r['archive_bytes']
assert hashlib.sha256(archive.read_bytes()).hexdigest()==r['archive_sha256']
steps=['all-offsets/replay.py','all-offsets/decompose_n24.py','all-offsets/independent_check.py','new-sizes/replay.py','new-sizes/independent_check.py','r26-guard-sensitivity/sensitivity.py','r26-guard-sensitivity/independent_check_sensitivity.py']
with tempfile.TemporaryDirectory(prefix='hush-r28-native-') as tmp:
 d=Path(tmp)
 with zipfile.ZipFile(archive) as z:
  assert z.testzip() is None and len(z.namelist())==r['files']
  for n in z.namelist():
   p=PurePosixPath(n);assert not p.is_absolute() and '..' not in p.parts and chr(92) not in n
  z.extractall(d)
 manifest=json.loads((d/'PUBLIC_MANIFEST.json').read_text())['files']
 for n,x in manifest.items():
  assert (d/n).stat().st_size==x['bytes'] and hashlib.sha256((d/n).read_bytes()).hexdigest()==x['sha256']
 for n in steps:
  rr=subprocess.run([sys.executable,'-B','-X','utf8',str(d/n)],cwd=(d/n).parent,capture_output=True,text=True)
  assert rr.returncode==0,(n,rr.stdout,rr.stderr)
 for n,x in manifest.items():assert hashlib.sha256((d/n).read_bytes()).hexdigest()==x['sha256'],n
 print(json.dumps({'all1251_new_native_cases_replayed':True,'exact27_reused_rows_bound':True,'three_policy128offset_scope':True,'seven_policy3offset_scope':True,'posthoc_guard_sensitivity_separate':True,'all_seven_stdlib_steps':True}))
