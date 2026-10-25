"""Portable cost robustness entry. Standard-library quick/full checks."""
from pathlib import Path,PurePosixPath
import argparse,hashlib,json,subprocess,sys,tempfile,zipfile
def main():
 ap=argparse.ArgumentParser(description=__doc__);m=ap.add_mutually_exclusive_group()
 m.add_argument('--quick',action='store_true');m.add_argument('--full',action='store_true')
 ap.add_argument('--output',type=Path);args=ap.parse_args();base=Path(__file__).resolve().parent
 manifest=json.loads((base/'MANIFEST.json').read_text(encoding='utf-8'))
 for r in manifest['files']:
  b=(base/r['path']).read_bytes();assert len(b)==r['bytes'] and hashlib.sha256(b).hexdigest()==r['sha256']
 with tempfile.TemporaryDirectory(prefix='hush-r34-') as tmp:
  root=Path(tmp)
  with zipfile.ZipFile(base/'reporting-inputs.zip') as z:
   assert sorted(z.namelist())==sorted(r['path'] for r in manifest['archive_members'])
   for r in manifest['archive_members']:
    n=PurePosixPath(r['path']);assert not n.is_absolute() and '..' not in n.parts and '\\' not in r['path']
    b=z.read(r['path']);assert len(b)==r['bytes'] and hashlib.sha256(b).hexdigest()==r['sha256']
    p=root/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(b)
  cmd=[sys.executable,'-B','-X','utf8',str(root/'cost/check_costs.py'),'--full' if args.full else '--quick']
  run=subprocess.run(cmd,cwd=root/'cost',capture_output=True,text=True,encoding='utf-8')
  log=run.stdout+run.stderr;assert run.returncode==0,log[-6000:]
  check=json.loads(run.stdout)
  result={'status':'pass','mode':check['mode'],'archive_members_verified':len(manifest['archive_members']),
          'cost_check':check,'new_native_executions':0,'new_SAT_or_mapping_runs':0,
          'old_grids_and_native_records_indexed_by_prior_commit':manifest['earlier_index_commit']}
  if args.output:
   assert not args.output.exists(),'Choose a fresh output directory'
   args.output.mkdir(parents=True)
   (args.output/'cost-check.log').write_text(log,encoding='utf-8')
   (args.output/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
  print(json.dumps(result,indent=2))
if __name__=='__main__':main()
