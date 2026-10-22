"""Fresh actual external Yosys/CXXRTL and independent semantic execution."""
from pathlib import Path
import argparse,csv,json,os,shutil,subprocess,sys
sys.path.insert(0,str(Path(__file__).resolve().parent))
from r05_portable import materialize,sha,load
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path,required=True);ap.add_argument('--yosys-python-wrapper',type=Path,required=True);ap.add_argument('--zig',type=Path,required=True);ap.add_argument('--include',type=Path,required=True);a=ap.parse_args()
 out=a.out.resolve();out.mkdir(parents=True,exist_ok=False);tree,manifest=materialize(out/'materialized');cal=tree/'r05-analysis/hush-calendar-rtl';ind=cal/'independent'
 env=os.environ.copy();env['ZIG_GLOBAL_CACHE_DIR']=str(out/'zig-global-cache');env['ZIG_LOCAL_CACHE_DIR']=str(out/'zig-local-cache');env['PYTHONDONTWRITEBYTECODE']='1'
 commands=[]
 def run(name,argv,cwd,expected=0):
  p=subprocess.run(list(map(str,argv)),cwd=cwd,env=env,capture_output=True,text=True,encoding='utf-8',errors='replace')
  (out/(name+'.stdout.log')).write_text(p.stdout,encoding='utf-8');(out/(name+'.stderr.log')).write_text(p.stderr,encoding='utf-8');commands.append(dict(name=name,argv=list(map(str,argv)),returncode=p.returncode));(out/'COMMANDS.json').write_text(json.dumps(commands,indent=2)+'\n',encoding='utf-8');print(name,p.returncode,flush=True)
  assert (p.returncode==0) if expected==0 else (p.returncode!=0),(name,p.stderr)
 def synth(label,d,receiver):
  d.mkdir();shutil.copyfile(receiver,d/'receiver.v');run(label+'-synthesis',[sys.executable,'-B','-X','utf8',a.yosys_python_wrapper,'-p','read_verilog receiver.v; hierarchy -check -top receiver; prep -top receiver; check -assert; write_cxxrtl netlist.cpp'],d)
 def compile(label,d,src,exe):
  shutil.copyfile(src,d/src.name);run(label+'-compile',[a.zig,'c++','-std=c++17','-O3','-UNDEBUG','-I',a.include,'-I',a.include/'backends/cxxrtl/runtime',src.name,'-o',exe],d)
 def same(actual,expected):assert sha(actual)==sha(expected),(str(actual),str(expected))
 run('yosys-version',[sys.executable,'-B','-X','utf8',a.yosys_python_wrapper,'-V'],out)
 b=out/'build';synth('primary',b,cal/'receiver.v');compile('driver',b,cal/'driver.cpp','driver.exe');compile('independent',b,ind/'independent.cpp','oracle.exe')
 pc=out/'producer-control';pc.mkdir();run('producer-control',[b/'driver.exe','control',pc,'-'],b)
 for n in ['CONTROL_TICKS.csv','DATA_TICKS.csv','RUN_COUNTERS.csv']:same(pc/n,cal/'build-04'/n)
 pp=out/'producer-policy';pp.mkdir();run('producer-primary-policy',[b/'driver.exe','policies',pp,cal/'analysis-01/policies.txt'],b)
 for n in ['POLICY_RESULTS.csv','POLICY_TICKS.delta']:same(pp/n,cal/'build-05-policy'/n)
 ps=out/'producer-supplement';ps.mkdir();run('producer-cycle-supplement',[b/'driver.exe','policies',ps,cal/'cycle-supplement-01/policies.txt'],b)
 for n in ['POLICY_RESULTS.csv','POLICY_TICKS.delta']:same(ps/n,cal/'build-06-cycle-supplement'/n)
 ic=out/'independent-control';ic.mkdir();run('independent-control',[b/'oracle.exe','control',ic],b)
 for n in ['INDEPENDENT_CONTROL_5F.csv','INDEPENDENT_control_COUNTERS.csv']:same(ic/n,ind/n)
 ip=out/'independent-policy';ip.mkdir();run('independent-primary-policy',[b/'oracle.exe','policies',ip,cal/'analysis-01/policies.txt'],b)
 for n in ['INDEPENDENT_POLICY_RESULTS.csv','INDEPENDENT_POLICY_TICKS.delta','INDEPENDENT_policies_COUNTERS.csv']:same(ip/n,ind/n)
 # The separately declared supplement changes only the expected complete count.
 suppsrc=ind/'cycle-supplement/independent_supplement.cpp'
 original=(ind/'independent.cpp').read_text(encoding='utf-8');assert suppsrc.read_text(encoding='utf-8')==original.replace('require(N==130112,"complete grid")','require(N==6496,"complete separately declared cycle supplement")')
 compile('independent-supplement',b,suppsrc,'supplement.exe');isup=out/'independent-supplement';isup.mkdir();run('independent-cycle-supplement',[b/'supplement.exe','policies',isup,cal/'cycle-supplement-01/policies.txt'],b)
 for n in ['INDEPENDENT_POLICY_RESULTS.csv','INDEPENDENT_POLICY_TICKS.delta','INDEPENDENT_policies_COUNTERS.csv']:same(isup/n,ind/'cycle-supplement'/n)
 def rows(p):
  with p.open(newline='') as f:return [{k:int(v) for k,v in r.items()} for r in csv.DictReader(f)]
 full={(r['K'],r['P'],r['phi']):r for r in rows(ip/'INDEPENDENT_POLICY_RESULTS.csv') if r['case']==7};local=rows(isup/'INDEPENDENT_POLICY_RESULTS.csv')
 assert len(local)==6496 and sum(r['firstFail']<0 for r in local)==5498 and sum(r['firstFail']<0 and full[(r['K'],r['P'],r['phi'])]['firstFail']>=0 for r in local)==271
 mutants=[]
 for old in sorted((ind/'mutants').iterdir()):
  if not old.is_dir():continue
  d=out/('mutant-'+old.name);synth(old.name,d,old/'receiver.v');compile(old.name,d,ind/'independent.cpp','oracle.exe');run(old.name+'-execution',[d/'oracle.exe','control',d],d,expected=1);same(d/'INDEPENDENT_FAILURE.txt',old/'INDEPENDENT_FAILURE.txt');mutants.append(dict(name=old.name,source_sha256=sha(d/'receiver.v'),first_failure=(d/'INDEPENDENT_FAILURE.txt').read_text().strip()))
 assert len(mutants)==5
 report=dict(status='PASS_FRESH_ACTUAL_YOSYS_CXXRTL_DRIVER_AND_INDEPENDENT_ALL_TICKS_FIVE_MUTANTS',manifest=manifest,commands=commands,tool_hashes=dict(yosys_wrapper=sha(a.yosys_python_wrapper),zig=sha(a.zig)),fresh_netlist_sha256=sha(b/'netlist.cpp'),primary_queries=130112,supplement_queries=6496,actual_primary_policy_ticks=84379472,actual_supplement_policy_ticks=346304,cycle_local_positive_prefix_rejections=271,all_semantic_streams_exact=True,mutants=mutants,new_timing_experiment=False,scope='Correctness replay only; external tools not distributed; no native HUSH/coherence/hardware/performance inference.')
 (out/'R05_NATIVE_REPLAY_RESULTS.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');print(report['status'],flush=True)
if __name__=='__main__':main()
