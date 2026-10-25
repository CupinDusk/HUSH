"""Portable checks of registered search, clean read data, and mapped cells."""
from pathlib import Path,PurePosixPath
import argparse,hashlib,json,subprocess,sys,tempfile,zipfile
def main():
 ap=argparse.ArgumentParser(description=__doc__)
 ap.add_argument('--quick',action='store_true');ap.add_argument('--output',type=Path)
 args=ap.parse_args();base=Path(__file__).resolve().parent
 manifest=json.loads((base/'MANIFEST.json').read_text(encoding='utf-8'))
 for row in manifest['files']:
  b=(base/row['path']).read_bytes()
  assert len(b)==row['bytes'] and hashlib.sha256(b).hexdigest()==row['sha256']
 with tempfile.TemporaryDirectory(prefix='hush-research-check-') as tmp:
  root=Path(tmp)
  with zipfile.ZipFile(base/'reporting-inputs.zip') as z:
   assert sorted(z.namelist())==sorted(r['path'] for r in manifest['archive_members'])
   for row in manifest['archive_members']:
    n=PurePosixPath(row['path']);assert not n.is_absolute() and '..' not in n.parts and '\\' not in row['path']
    b=z.read(row['path']);assert len(b)==row['bytes'] and hashlib.sha256(b).hexdigest()==row['sha256']
    p=root/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(b)
  checks=[]
  commands=[('source-adapter','cost-search/verify_source.py'),
            ('source-search-quick','cost-search/check_search.py'),
            ('read-data-integrity','data/check.py'),
            ('mapped-cell-reduction','area/derive_area_breakdown.py')]
  area_before=(root/'area/AREA_CELL_BREAKDOWN.json').read_bytes()
  logs={}
  for label,script in commands:
   run=subprocess.run([sys.executable,'-B','-X','utf8',str(root/script)],cwd=(root/script).parent,capture_output=True,text=True,encoding='utf-8')
   log=run.stdout+run.stderr;assert run.returncode==0,(label,log[-6000:])
   logs[label]=log;checks.append({'label':label,'script':script,'returncode':run.returncode,'stdout':run.stdout})
  assert (root/'area/AREA_CELL_BREAKDOWN.json').read_bytes()==area_before
  result={'status':'pass','mode':'quick','archive_members_verified':len(manifest['archive_members']),
          'checks':checks,'scope':'Component quick checks and exact mapped-cell reduction; not a new complete search or formal proof',
          'new_native_executions':0,'new_SAT_or_mapping_runs':0,
          'prior_index_commit':manifest['earlier_index_commit']}
  if args.output:
   assert not args.output.exists(),'Choose a fresh output directory'
   args.output.mkdir(parents=True)
   for label,log in logs.items():(args.output/(label+'.log')).write_text(log,encoding='utf-8')
   (args.output/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
  print(json.dumps(result,indent=2))
if __name__=='__main__':main()
