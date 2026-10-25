"""Independently reduce frozen endpoint, sentinel-menu, boot and region evidence."""
from pathlib import Path,PurePosixPath
import argparse,hashlib,json,subprocess,sys,tempfile,zipfile
ap=argparse.ArgumentParser(description=__doc__)
ap.add_argument('--quick',action='store_true');ap.add_argument('--output',type=Path)
args=ap.parse_args();base=Path(__file__).resolve().parent
m=json.loads((base/'MANIFEST.json').read_text())
assert m['components']==['changing-frame-fir-period128','changing-frame-fir-period10','assumption-baseline-audit']
assert m['new_native_executions_recorded']>0 and m['historical_native_total']==6816 and m['native_cumulative_total']==6816+m['new_native_executions_recorded']
for r in m['files']:
 d=(base/r['path']).read_bytes();assert len(d)==r['bytes'] and hashlib.sha256(d).hexdigest()==r['sha256']
checks=[]
with tempfile.TemporaryDirectory(prefix='hush-offline-evidence-') as tmp:
 root=Path(tmp)
 with zipfile.ZipFile(base/'reporting-inputs.zip') as z:
  assert len(z.namelist())==len(set(z.namelist()))
  assert sorted(z.namelist())==sorted(r['path'] for r in m['archive_members'])
  for r in m['archive_members']:
   n=PurePosixPath(r['path']);assert not n.is_absolute() and '..' not in n.parts and '\\' not in r['path'] and all(':' not in p for p in n.parts)
   d=z.read(r['path']);assert len(d)==r['bytes'] and hashlib.sha256(d).hexdigest()==r['sha256']
   p=root/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(d)
 for component in m['components']:
  p=root/component
  r=subprocess.run([sys.executable,'-B','-X','utf8',str(p/'check.py')],cwd=p,capture_output=True,text=True,encoding='utf-8')
  assert r.returncode==0,(component,r.stdout[-1500:],r.stderr[-4000:])
  checks.append({'component':component,'returncode':r.returncode,'stdout':r.stdout})
 for r in m['archive_members']:
  d=(root/PurePosixPath(r['path'])).read_bytes()
  assert len(d)==r['bytes'] and hashlib.sha256(d).hexdigest()==r['sha256'],('checker changed packaged member',r['path'])
result={'status':'pass','mode':'quick','archive_members_verified':len(m['archive_members']),
        'checks':checks,'scope':'Hashes and independent frozen result, oracle, selection and signed-region reductions; no new native, SAT, synthesis or CXXRTL runs',
        'new_native_executions_recorded':m['new_native_executions_recorded'],'historical_native_total':m['historical_native_total'],
        'native_cumulative_total':m['native_cumulative_total'],'packaged_member_bytes_unchanged_after_checks':True,
        'native_executions_during_replay':0,'earlier_index_commit':m['earlier_index_commit']}
if args.output:
 assert not args.output.exists();args.output.mkdir(parents=True)
 (args.output/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(json.dumps(result,indent=2))
