"""Independent separately bound p7/r7 cycle-witness extension, no retuning."""
from pathlib import Path
import csv,json,hashlib,math,shutil,subprocess,sys
HERE=Path(__file__).resolve().parent;SOURCE=HERE.parent;ROOT=HERE.parents[4]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):
 with p.open(newline='') as f:return [{k:int(v) for k,v in r.items()} for r in csv.DictReader(f)]
def main():
 out=HERE/'cycle-supplement';out.mkdir(exist_ok=False)
 primary=['analysis-01/policies.txt','analysis-01/TUNING.json','analysis-01/ALL_PHASES.jsonl.gz','build-05-policy/POLICY_RESULTS.csv','build-05-policy/POLICY_TICKS.delta']
 before={n:sha(SOURCE/n) for n in primary}
 for name in ['SUPPLEMENT_03_CYCLE_WITNESS_COVERAGE.md','generate_cycle_supplement.py','verify_policy.py','replay_portable.py','derive_peaks.py']:
  shutil.copyfile(SOURCE/name,out/name)
 (out/'PRE_EXECUTION_BINDING.json').write_text(json.dumps(dict(primary_preserved=before,supplement_inputs={p.name:sha(p) for p in out.iterdir() if p.is_file()},oracle_sha256=sha(HERE/'independent.cpp')),indent=2)+'\n')
 rec=json.loads((HERE/'INDEPENDENT_RELATIONS.json').read_text())['records'][7];assert rec['entry']==37 and rec['period']==56 and rec['cycle_entry_empty']
 policies=[]
 for P in range(1,29):
  copies=[]
  for line in rec['lines']:
   for s,c,h in line['cycle']:
    for n in range(P//math.gcd(P,56)):copies.append((s+56*n,line['line'],c+56*n,h+56*n,n))
  for phi in range(P):
   choices=[]
   for s,j,c,h,n in copies:
    first=phi+((s+1-phi+P-1)//P)*P
    choices.append((first-h,s,j,c,h,n))
   base,s,j,c,h,n=min(choices)
   for K in range(1,17):
    expiry=phi+((s+1-phi+P-1)//P)*P+(K-1)*P
    nd=(h-phi)//P-(s-phi)//P;assert (expiry>h)==(K>nd)
    policies.append([len(policies),7,K,P,phi,j,s,c,h,s+1,37+56*n,n,expiry-h,expiry])
 assert len(policies)==6496
 with (out/'policies.txt').open('w',newline='\n') as f:
  f.write('6496\n')
  for row in policies:f.write(' '.join(map(str,row))+'\n')
 assert sha(out/'policies.txt')==sha(SOURCE/'cycle-supplement-01/policies.txt')
 shutil.copyfile(HERE/'frozen-input/receiver.v',out/'receiver.v')
 checker=(HERE/'independent.cpp').read_text();assert checker.count('require(N==130112,"complete grid")')==1
 checker=checker.replace('require(N==130112,"complete grid")','require(N==6496,"complete separately declared cycle supplement")')
 (out/'independent_supplement.cpp').write_text(checker,encoding='utf-8')
 inc=ROOT/'.tools/iscas-rtl-20261023/yowasp_yosys/share/include';zig=ROOT/'.tools/zig-0.14.1/zig-x86_64-windows-0.14.1/zig.exe';wrapper=ROOT/'.tools/run_iscas_yosys.py'
 commands=[('yosys_version',[sys.executable,'-B','-X','utf8',str(wrapper),'-V']),('synthesis',[sys.executable,'-B','-X','utf8',str(wrapper),'-p','read_verilog receiver.v; hierarchy -check -top receiver; prep -top receiver; check -assert; write_cxxrtl netlist.cpp']),('compile',[str(zig),'c++','-std=c++17','-O3','-UNDEBUG','-I',str(inc),'-I',str(inc/'backends/cxxrtl/runtime'),'independent_supplement.cpp','-o','check.exe']),('execution',[str(out/'check.exe'),'policies',str(out),str(out/'policies.txt')])]
 stages=[]
 for name,cmd in commands:
  p=subprocess.run(cmd,cwd=out,capture_output=True,text=True,encoding='utf-8',errors='replace');(out/(name+'.stdout.log')).write_text(p.stdout,encoding='utf-8');(out/(name+'.stderr.log')).write_text(p.stderr,encoding='utf-8');stages.append(dict(name=name,argv=cmd,returncode=p.returncode));assert p.returncode==0,(name,p.stderr)
 streams={}
 for a,b in [('INDEPENDENT_POLICY_RESULTS.csv','POLICY_RESULTS.csv'),('INDEPENDENT_POLICY_TICKS.delta','POLICY_TICKS.delta')]:
  streams[a]=dict(independent_sha256=sha(out/a),producer_sha256=sha(SOURCE/'build-06-cycle-supplement'/b));assert streams[a]['independent_sha256']==streams[a]['producer_sha256']
 results=read(out/'INDEPENDENT_POLICY_RESULTS.csv');counts=read(out/'INDEPENDENT_policies_COUNTERS.csv')
 full=read(HERE/'INDEPENDENT_POLICY_RESULTS.csv');full={(r['K'],r['P'],r['phi']):r for r in full if r['case']==7}
 cyclepositive=sum(r['firstFail']<0 for r in results);fullpositive=sum(r['firstFail']<0 for r in full.values())
 local_only=sum(r['firstFail']<0 and full[(r['K'],r['P'],r['phi'])]['firstFail']>=0 for r in results)
 assert fullpositive+local_only==cyclepositive
 initialization=[]
 for r in results:
  start=r['start'];n=r['translationFrames'];P=r['P'];origin=5+8*n
  assert start==37+56*n and r['startPhase']==start%P
  initialization.append([r['query'],7,start,37,n,start%7,start%7,start%56,start%P,origin,1,1-origin,start,r['ticks']])
 with (out/'INDEPENDENT_INITIALIZATION.csv').open('w',newline='') as f:
  w=csv.writer(f);w.writerow(['query','case','start','entry','translationFrames','cachePhase','readyPhase','calendarPhase','physicalPPhase','physicalNextIdAtEntry','resetNextId','IDTranslation','omittedPrehistoryTicksNOTExecuted','actualExecutedTicks']);w.writerows(initialization)
 assert sha(out/'INDEPENDENT_INITIALIZATION.csv')==sha(SOURCE/'cycle-supplement-01/POLICY_INITIALIZATION.csv')
 assert all(sha(SOURCE/n)==h for n,h in before.items())
 report=dict(status='PASS_SEPARATE_INDEPENDENT_CYCLE_WITNESS_EXTENSION',queries=6496,actual_executed_ticks=sum(r['ticks'] for r in counts),cycle_local_positive=cyclepositive,cycle_local_negative=6496-cyclepositive,full_admitted_unchanged=fullpositive,cycle_local_positive_but_prefix_rejects=local_only,omitted_prehistory_NOT_executed=sum(r['start'] for r in results),actual_counts={k:sum(r[k] for r in counts) for k in ['ticks','captures','emissions','transfers','backpressure','cancels','expiries','WUs','heldExpired','heldExpiredBlock']},source_primary_unchanged=before,streams=streams,commands=stages,generated_hashes={n:sha(out/n) for n in ['receiver.v','independent_supplement.cpp','netlist.cpp','check.exe','policies.txt','INDEPENDENT_INITIALIZATION.csv']},scope='Cycle-only local tests do not grant full admission when the exact physical prefix rejects. Original 130112 full decisions and original p7/r7 empty-frame UNKNOWN remain unchanged.')
 (out/'INDEPENDENT_SUPPLEMENT_AUDIT.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');print(json.dumps({k:report[k] for k in ['status','queries','actual_executed_ticks','cycle_local_positive','cycle_local_negative','full_admitted_unchanged','cycle_local_positive_but_prefix_rejects','actual_counts']},indent=2))
if __name__=='__main__':main()
