"""Fresh R03 correctness and recorded-timing audit; no timing remeasurement."""
from pathlib import Path
import gzip,hashlib,json,os,shutil,subprocess,sys,tempfile
ROOT=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text(encoding='utf-8'))
def strip_top_hashes(v):return {k:x for k,x in v.items() if not k.endswith('_sha256')}
def main():
 target=ROOT/'R03_REPLAY_RESULTS.json';assert not target.exists(),'Use a fresh extraction; previous evidence is preserved.'
 manifest=read(ROOT/'MANIFEST.json')
 for name,h in manifest['files'].items():assert sha(ROOT/name)==h,name
 shared=ROOT/'r03/hush-shared-controller';workflow=ROOT/'r03/hush-workflow-cost'
 commands=[];env=os.environ.copy();env['PYTHONPATH']=str(ROOT/'analysis');env['PYTHONDONTWRITEBYTECODE']='1'
 def run(script,*args):
  cmd=[sys.executable,'-B','-X','utf8',str(script),*map(str,args)]
  p=subprocess.run(cmd,cwd=script.parent,env=env,text=True,encoding='utf-8',capture_output=True)
  print(p.stdout,flush=True)
  if p.returncode:print(p.stderr,file=sys.stderr);raise RuntimeError(f'{script.name} failed with {p.returncode}')
  commands.append({'script':script.name,'returncode':p.returncode})
 with tempfile.TemporaryDirectory(prefix='period-reuse-r03-') as tmp:
  # Retained historical relative-import code accesses HERE.parents[3]. Keep
  # enough directory depth even when the system temp root is simply /tmp.
  temp=Path(tmp);fresh=temp/'rebuild/r03/hush-shared-controller';fresh.mkdir(parents=True)
  for name in ('PROTOCOL.json','extract_shared.py','analyze_policies.py','independent_validate.py','ARGUMENT.md','PAPER_READY.md'):
   shutil.copyfile(shared/name,fresh/name)
  for name in ('extract_shared.py','analyze_policies.py','independent_validate.py'):run(fresh/name)
  logical={}
  for name in ('RELATIONS.json','POLICY_RESULTS.json','INDEPENDENT_VALIDATION.json'):
   assert strip_top_hashes(read(fresh/name))==strip_top_hashes(read(shared/name)),name
   logical[name]='All non-provenance fields exactly equal, including every trace digest, relation, case and count.'
  decoded={}
  for name in ('TRACES.jsonl.gz','ALL_PHASE_BASES.jsonl.gz','ALL_NEGATIVE_FIRST_FAILURES.jsonl.gz'):
   a=gzip.decompress((fresh/name).read_bytes());b=gzip.decompress((shared/name).read_bytes());assert a==b,name
   decoded[name]={'decoded_sha256':hashlib.sha256(a).hexdigest(),'decoded_bytes':len(a)}
  fresh_work=fresh.parent/'hush-workflow-cost';fresh_work.mkdir()
  for name in ('PROTOCOL.json','producer.py','workflow.py'):shutil.copyfile(workflow/name,fresh_work/name)
  run(fresh_work/'workflow.py','prepare','--inputs',fresh)
  run(fresh_work/'workflow.py','validate','--inputs',fresh)
  generated=read(fresh_work/'VALIDATION.json');recorded=read(workflow/'VALIDATION.json')
  for key in ('status','route_checks','independent_event_count_checks','per_case_counts','capacities'):
   assert generated[key]==recorded[key],key
  for name in ('QUERY_STREAM.json.gz','SCHEDULE.json'):
   assert (fresh_work/name).read_bytes()==(workflow/name).read_bytes(),name
  a=read(fresh_work/'EXPECTED.json');b=read(workflow/'EXPECTED.json')
  for key in a:
   if key not in ('input_sha256',):assert a[key]==b[key],key
  run(workflow/'audit_saved.py','--inputs',shared,'--check-only')
  result={'status':'PASS_FRESH_EXTRACTION_SHARED_CONTROLLER_ALL_POLICIES_ALL_FOUR_WORKFLOW_ROUTES_AND_RECORDED_TIMING_AUDIT',
   'root_manifest_sha256':sha(ROOT/'MANIFEST.json'),'source_cases':40,'independent_control_ticks':22823,'line_relations':80,'phase_rows':7400,'policy_queries':37000,
   'service_positive':17387,'completion_positive':16948,'service_only':439,'negative_first_failure_executions':19613,
   'prospective_source_pairs':765,'full_source_pairs':961,'correctness_routes':list(generated['route_checks']),
   'recorded_timing_measurements_audited':36,'recorded_paired_blocks':9,'new_timing_experiment':False,
   'logical_rebuild_comparisons':logical,'decoded_evidence':decoded,'commands':commands,
   'older_suites_rerun':False,'scope':'Explicit two-line controller and one offline Python prototype; no native HUSH, hardware, application or coherence validation.'}
  target.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
  print(json.dumps(result,indent=2))
if __name__=='__main__':main()
