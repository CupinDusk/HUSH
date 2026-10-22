"""All new stdlib model/record/trace audits; immutable inputs, external output."""
from pathlib import Path
import argparse,hashlib,json,subprocess,sys
sys.path.insert(0,str(Path(__file__).resolve().parent))
from r05_portable import materialize,load,sha
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path,required=True);a=ap.parse_args()
 out=a.out.resolve();out.mkdir(parents=True,exist_ok=False)
 tree,manifest=materialize(out/'materialized');cal=tree/'r05-analysis/hush-calendar-rtl';intr=tree/'r05-analysis/hush-intrinsic-period'
 jobs=[]
 def run(name,path,args=()):
  argv=[sys.executable,'-I','-S','-B','-X','utf8','-c',"import runpy,sys; from pathlib import Path; p=Path(sys.argv[1]); sys.path.insert(0,str(p.parent)); sys.argv=[str(p),*sys.argv[2:]]; runpy.run_path(str(p),run_name='__main__')",str(path),*map(str,args)]
  p=subprocess.run(argv,cwd=tree,capture_output=True,text=True,encoding='utf-8',errors='replace')
  (out/(name+'.stdout.log')).write_text(p.stdout,encoding='utf-8');(out/(name+'.stderr.log')).write_text(p.stderr,encoding='utf-8')
  jobs.append(dict(name=name,argv=argv,returncode=p.returncode));(out/'COMMANDS.json').write_text(json.dumps(jobs,indent=2)+'\n',encoding='utf-8');print(name,p.returncode,flush=True)
  assert p.returncode==0,(name,p.stderr)
 run('calendar-transitions',cal/'check_transitions.py')
 run('calendar-primary-all-ticks',cal/'verify_policy.py',['--ticks'])
 run('calendar-supplement-all-ticks',cal/'verify_policy.py',['--build','build-06-cycle-supplement','--analysis','cycle-supplement-01','--expected-queries','6496','--ticks'])
 run('calendar-independent-arithmetic',cal/'independent/independent_analysis.py')
 run('calendar-independent-bindings-peaks',cal/'independent/verify_evidence.py')
 run('calendar-exact-peaks',cal/'derive_peaks.py')
 fresh=out/'fresh-intrinsic-producer';run('intrinsic-producer',intr/'research.py',['--out',fresh])
 for sub in ['records','size-records']:
  expected={p.name:sha(p) for p in (intr/'attempt-002'/sub).glob('*.bin')};actual={p.name:sha(p) for p in (fresh/sub).glob('*.bin')};assert expected==actual,sub
 for name in ['SMALL_CHECKS.json','OLD_RELATION_RESULTS.json','SIZE_RESULTS.json','RESULTS.json','MUTATION_CONTROLS.json']:
  assert load(fresh/name)==load(intr/'attempt-002'/name),name
 run('intrinsic-independent',intr/'independent/check_independent.py')
 run('intrinsic-actual-parser-probes',intr/'independent/parser_probe.py')
 # Earlier unbound 48B format: run only its valid producer in a clean folder.
 simple=out/'fresh-simple-size';simple.mkdir();(simple/'check.py').write_bytes((tree/'r05-analysis/hush-periodic-size/check.py').read_bytes())
 run('earlier-size-source',simple/'check.py')
 old=tree/'r05-analysis/hush-periodic-size'
 for p in (old/'inputs').iterdir():assert sha(simple/'inputs'/p.name)==sha(p),p.name
 assert load(simple/'RESULTS.json')['cases']==load(old/'RESULTS.json')['cases']
 primary=load(cal/'build-05-policy/PRODUCER_POLICY_CHECK.json');sup=load(cal/'build-06-cycle-supplement/PRODUCER_POLICY_CHECK.json')
 assert primary['counts']['executed_ticks']+sup['counts']['executed_ticks']==84725776
 report=dict(status='PASS_ALL_NEW_STDLIB_MODEL_BYTE_TRACE_RECORD_AND_INDEPENDENT_CHECKS',manifest=manifest,isolated_python_flags=['-I','-S','-B','-X','utf8'],commands=jobs,actual_primary_timer_ticks=primary['counts']['executed_ticks'],actual_supplement_timer_ticks=sup['counts']['executed_ticks'],intrinsic_independent=load(intr/'independent/CHECK_RESULTS.json'),parser_probes=load(intr/'independent/PARSER_PROBES.json'),old_suites_rerun=False,new_timing_experiment=False,scope='All new stdlib audits; prior nine timing blocks unchanged. No SciPy/native/coherence/hardware/application/performance claim.')
 (out/'R05_REPLAY_RESULTS.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');print(report['status'],flush=True)
if __name__=='__main__':main()
