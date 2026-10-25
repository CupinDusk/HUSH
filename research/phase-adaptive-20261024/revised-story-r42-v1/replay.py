"""Verify and independently reduce saved R42 evidence; no new experiments."""
from pathlib import Path,PurePosixPath
import argparse,hashlib,json,stat,subprocess,sys,tempfile,zipfile
ap=argparse.ArgumentParser(description=__doc__)
ap.add_argument('--quick',action='store_true')
ap.add_argument('--output',type=Path)
args=ap.parse_args();base=Path(__file__).resolve().parent
m=json.loads((base/'MANIFEST.json').read_text(encoding='utf-8'))
assert m['schema']=='hush-r42-portable-v1'
assert m['new_native_executions_recorded']==0
assert m['historical_native_total']==m['native_cumulative_total']==8280
assert len(m['components'])==len(set(m['components'])) and m['components']
def safe(n):
 p=PurePosixPath(n)
 assert p.parts and not p.is_absolute() and '..' not in p.parts
 assert '\\' not in n and all(':' not in t for t in p.parts)
 return p
def verify(b,r):
 assert len(b)==r['bytes'] and hashlib.sha256(b).hexdigest()==r['sha256'],r['path']
 if 'git_blob_sha1' in r:
  assert hashlib.sha1(b'blob '+str(len(b)).encode('ascii')+b'\0'+b).hexdigest()==r['git_blob_sha1']
assert {r['path'] for r in m['files']}=={'.gitattributes','README.md','replay.py','reporting-inputs.zip'}
for r in m['files']:
 n=safe(r['path']);assert len(n.parts)==1;verify((base/n).read_bytes(),r)
checks=[]
with tempfile.TemporaryDirectory(prefix='hush-offline-evidence-') as tmp:
 root=Path(tmp)
 with zipfile.ZipFile(base/'reporting-inputs.zip') as z:
  assert z.testzip() is None
  assert len(z.namelist())==len(set(z.namelist()))
  assert sorted(z.namelist())==sorted(r['path'] for r in m['archive_members'])
  records={r['path']:r for r in m['archive_members']}
  for info in z.infolist():
   n=safe(info.filename)
   assert not info.is_dir() and not stat.S_ISLNK(info.external_attr>>16)
   assert n.parts[0] in m['components']
   d=z.read(info.filename);verify(d,records[info.filename])
   p=root/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(d)
 for component in m['components']:
  assert len(safe(component).parts)==1
  p=root/component
  r=subprocess.run([sys.executable,'-B','-X','utf8',str(p/'check.py')],cwd=p,
                   capture_output=True,text=True,encoding='utf-8',timeout=600)
  assert r.returncode==0,(component,r.stdout[-1500:],r.stderr[-4000:])
  checks.append({'component':component,'returncode':r.returncode,'stdout':r.stdout})
 for r in m['archive_members']:
  verify((root/safe(r['path'])).read_bytes(),r)
result={'status':'pass','mode':'quick','archive_members_verified':len(m['archive_members']),
 'checks':checks,'scope':'Hash verification and independent saved-result reduction; no new native, cycle-model, SAT, synthesis or STA execution',
 'new_native_executions_recorded':0,'historical_native_total':8280,'native_cumulative_total':8280,
 'packaged_member_bytes_unchanged_after_checks':True,'native_executions_during_replay':0,
 'earlier_index_commit':m['earlier_index_commit']}
if args.output:
 assert not args.output.exists();args.output.mkdir(parents=True)
 (args.output/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(json.dumps(result,indent=2))
