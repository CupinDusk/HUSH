"""Default stdlib-only evidence and derivation audit. No timing or old suites."""
from pathlib import Path
import hashlib,json,os,subprocess,sys,tempfile
ROOT=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 out=ROOT/'R04_REPLAY_RESULTS.json'
 assert not out.exists(),'Use a fresh extraction; preserve prior replay evidence.'
 manifest=json.loads((ROOT/'MANIFEST.json').read_text(encoding='utf-8'))
 for n,h in manifest['files'].items():assert sha(ROOT/n)==h,n
 rtl=ROOT/'r04-analysis/hush-rtl';commands=[]
 env=os.environ.copy();env['PYTHONDONTWRITEBYTECODE']='1'
 with tempfile.TemporaryDirectory(prefix='period-r04-') as tmp:
  tmp=Path(tmp)
  jobs=[('rtl-independent-saved-evidence',[str(rtl/'independent/check_public.py'),'--out',str(tmp/'RTL_AUDIT.json')]),
        ('tuning-independent-and-derivation',[str(ROOT/'r04_tuning_replay.py'),'--out',str(tmp/'TUNING_REPLAY.json')])]
  for name,args in jobs:
   p=subprocess.run([sys.executable,'-B','-X','utf8',*args],cwd=ROOT,env=env,capture_output=True,text=True,encoding='utf-8')
   print(p.stdout,flush=True)
   if p.returncode:print(p.stderr,file=sys.stderr);raise RuntimeError(name+' failed')
   commands.append(dict(name=name,returncode=p.returncode))
  a=json.loads((tmp/'RTL_AUDIT.json').read_text(encoding='utf-8'));b=json.loads((tmp/'TUNING_REPLAY.json').read_text(encoding='utf-8'))
  old=json.loads((rtl/'independent/INDEPENDENT_AUDIT.json').read_text(encoding='utf-8'))
  for key in ['counts','phase_reconstruction','per_case_phase_counts','exercised_coverage','width_observations','no_service_gain_cases','reextracted_relation_counts']:
   assert a[key]==old[key],key
  result=dict(status='PASS_FRESH_EXTRACTION_R04_SAVED_RTL_EVIDENCE_AND_INDEPENDENT_TUNING_ENCODING_DERIVATION',input_files=len(manifest['files']),
   root_manifest_sha256=sha(ROOT/'MANIFEST.json'),rtl_counts=a['counts'],tuning_replay=b,commands=commands,
   fresh_rtl_synthesis_compile_execution=False,rtl_saved_evidence_independently_reconstructed=True,
   older_suites_rerun=False,new_timing_experiment=False,native_historical_HUSH_or_private_overlay_run=False,
   scope='Finite constructed reference receiver; saved semantic evidence plus fresh numerical/encoding derivation. Optional run_r04_rtl.py is required for a new generated-RTL execution. No performance measurement.')
  out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps(result,indent=2))
 for n,h in manifest['files'].items():assert sha(ROOT/n)==h,'Input changed: '+n
if __name__=='__main__':main()
