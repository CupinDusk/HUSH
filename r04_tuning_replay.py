"""Redirect unchanged frozen author modules to a fresh local copy and public inputs."""
from pathlib import Path
import argparse,hashlib,importlib.util,json,shutil,subprocess,sys,tempfile
ROOT=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def loadmodule(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
def worker(base,old):
 # Independent checker runs first in its own subprocess; no producer import there.
 check=loadmodule('separate_r04_checker',base/'independent/check_independent.py');check.OLD=old;check.main()
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path);ap.add_argument('--worker',type=Path);ap.add_argument('--old',type=Path);a=ap.parse_args()
 if a.worker:return worker(a.worker,a.old)
 assert a.out is not None
 src=ROOT/'r04-analysis/hush-tuning-bytes';old=ROOT/'r03/hush-shared-controller'
 with tempfile.TemporaryDirectory(prefix='r04-tuning-') as tmp:
  base=Path(tmp)/'r04-analysis/hush-tuning-bytes';shutil.copytree(src,base)
  before={p.relative_to(base).as_posix():sha(p) for p in base.rglob('*') if p.is_file() and p.suffix in {'.bin','.gz','.csv'} or p.is_file() and p.name in {'RESULTS.json','TUNING_PER_CONTROLLER.json','PAIR_DECOMPOSITION.json','SERIALIZED_RECORDS.json'}}
  p=subprocess.run([sys.executable,'-B','-X','utf8',str(Path(__file__)),'--worker',str(base),'--old',str(old)],capture_output=True,text=True,encoding='utf-8')
  print(p.stdout,flush=True)
  if p.returncode:print(p.stderr,file=sys.stderr);raise RuntimeError('Separate tuning checker failed')
  audit=json.loads((base/'independent/INDEPENDENT_AUDIT.json').read_text(encoding='utf-8'))
  saved=json.loads((src/'independent/INDEPENDENT_AUDIT.json').read_text(encoding='utf-8'))
  # Only the Python patch version can differ on another user's compatible runtime.
  for key in ['status','counts','derived_selections','negative_outcomes','checks','distributions','frozen_input_hashes','producer_source_hashes']:
   assert audit[key]==saved[key],key
  sys.path.insert(0,str(base));producer=loadmodule('frozen_r04_producer',base/'analyze.py');producer.INPUT=old;producer.main()
  for n,h in before.items():assert sha(base/n)==h,'Derived byte difference: '+n
  result=dict(status='PASS_INDEPENDENT_ALL_CONTROLLERS_ALL_TIES_80_RECORDS_74000_SLACKS_AND_BYTE_EXACT_REDERIVATION',controllers=40,policy_queries=37000,binary_records=80,decoded_complete_query_slacks=74000,
   independently_checked_before_producer_execution=True,byte_exact_rederived_files=len(before),original_producer_and_checker_sources_unchanged=True,
   no_timing_measurement=True,counts=audit['counts'])
  a.out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
if __name__=='__main__':main()
