"""Prospective second specified source: actual endpoint BFS and independent replay."""
from pathlib import Path
from collections import Counter
import argparse,hashlib,json,math,subprocess
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

def replay(key,wu,branch,p,a,b,K,P,phi):
 t,V,E,k,v,b0,id0,v0,b1,id1,v1,mode,waiting,due,age,target=key
 deadline=t+(phi-t)%P+(k-1)*P if E else None
 if wu and V:deadline=t+(phi-t)%P+(K-1)*P;v=0
 expired=int(deadline==t)
 if expired:V=0;deadline=None
 read=int(not waiting and due<=1)
 if not waiting and due>0:due-=1
 if read:
  assert V and not b0 and not b1
  if age>=0:assert age==target
  assert t%p in (a,b)
  deadline=None;waiting=1;age=0;target=-1
 last_s=t-age if age>=0 else None
 completion=p*(-(-last_s//p))+p if last_s is not None else None
 reply=int(waiting and t==completion)
 if reply:
  assert b1 and id1==1 and v1==0 and branch in (0,1)
  waiting=0;due=(b if mode else a)+branch*p
  if not branch:mode=1-mode
  target=age+due
 else:assert branch==-1
 # Independent ceil-based pipeline reconstruction, not a register-shift replay.
 b0=id0=v0=b1=id1=v1=0
 if waiting:
  assert completion>t
  first=completion-p
  if t<first:b0=id0=1
  else:b1=id1=1
 if deadline is None:E=k=0
 else:
  E=1;first=t+1+(phi-t-1)%P
  assert deadline>=first and (deadline-first)%P==0
  k=1+(deadline-first)//P
 if age>=0:age+=1
 return [(t+1)%math.lcm(p,P),V,E,k,v,b0,id0,v0,b1,id1,v1,mode,waiting,due,age,target],read,reply,expired

def scalar(p,a,b):
 triples=[(s,2*p,2*p+x+e*p) for s in (a,b) for x in (a,b) for e in (0,1)]
 nu=3*p+b-a
 assert nu-3*p==(b-a)%p
 n=nonpositive=0
 for P in range(1,3*p+1):
  g=math.gcd(P,p)
  for phi in range(P):
   explicit=min((phi-s-i*p-1)%P-(h-s) for s,_,h in triples for i in range(P//g))
   projected=(phi-a-1)%g-nu
   assert explicit==projected
   for K in (1,2,3):n+=1;nonpositive+=int((K-1)*P+1+projected<=0)
 for K,P,phi,expected in [(2,3*p,a,p-b+a),(3,2*p,a+1,p+1-b+a)]:
  assert (K-1)*P+1+(phi-a-1)%p-nu==expected>0
 return n,nonpositive

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--zig',type=Path,required=True);args=ap.parse_args()
 build=HERE/'branch-endpoint-build';out=HERE/'R31_BRANCH_RESULTS.json'
 assert not build.exists() and not out.exists();build.mkdir()
 protocol=HERE/'R31_BRANCH_PROTOCOL.json';assert json.loads(protocol.read_text())['status']=='prospective_before_execution'
 cases=[(p,a,b) for p in range(3,13) for a in range(1,p) for b in range(a+1,p)];assert len(cases)==220
 binary=build/'branch_endpoint.exe'
 compile_run=subprocess.run([str(args.zig),'c++','-std=c++17','-O2','-UNDEBUG','-I',str(HERE),str(HERE/'branch_endpoint.cpp'),'-o',str(binary)],capture_output=True,text=True,timeout=120)
 (build/'compiler.log').write_text(compile_run.stdout+compile_run.stderr,encoding='utf-8');assert compile_run.returncode==0,compile_run.stderr
 inputs=''.join(f'{i} {p} {a} {b}\n' for i,(p,a,b) in enumerate(cases))
 graph=build/'graphs.jsonl'
 with graph.open('w',encoding='utf-8',newline='\n') as f:
  run=subprocess.run([str(binary)],input=inputs,stdout=f,stderr=subprocess.PIPE,text=True,timeout=300)
 (build/'execution.stderr').write_text(run.stderr,encoding='utf-8');assert run.returncode==0,run.stderr
 counts=Counter();summaries=[];states={};edges=[];negative=[]
 for line in graph.open(encoding='utf-8'):
  row=json.loads(line);kind=row['kind']
  if kind=='state':states[row['id']]=row['key']
  elif kind=='edge':edges.append(row)
  elif kind=='summary':
   cid,policy=row['case'],row['policy'];p,a,b=cases[cid];K,P,phi=(2,3*p,a) if policy==0 else (3,2*p,a+1)
   assert len(states)==row['states'] and len(edges)==row['edges']
   assert set(states)==set(range(len(states))) and states[0]==[a,1,0,0,0,0,0,0,0,0,0,1,0,0,-1,-1]
   succ=Counter()
   for e in edges:
    assert e['case']==cid and e['policy']==policy
    pred,read,reply,expiry=replay(states[e['from']],e['wu'],e['branch'],p,a,b,K,P,phi)
    assert pred==states[e['to']] and read==e['read'] and reply==e['reply'] and expiry==e['expired']==0,(row,e,pred,states[e['to']])
    succ[(e['from'],e['wu'],e['branch'])]+=1
    counts['edges']+=1;counts['reads']+=read;counts['callbacks']+=reply
   for i in states:
    for wu in (0,1):
     branches={e[2] for e in succ if e[:2]==(i,wu)}
     assert branches in ({-1},{0,1}) and all(succ[(i,wu,bit)]==1 for bit in branches)
   counts['states']+=len(states);summaries.append(row);states={};edges=[]
  elif kind=='negative':negative.append(row)
  else:raise AssertionError(kind)
 assert len(summaries)==440 and not states and not edges
 assert negative==[{'kind':'negative','expiry':21,'miss':34,'invalid_entry_read':2}]
 scalar_count=nonpositive=0
 for p,a,b in cases:
  n,z=scalar(p,a,b);scalar_count+=n;nonpositive+=z
 result={'result':'PASS_SECOND_SPECIFIED_BRANCH_PRODUCER_JOINT_WU_BRANCH_GRAPHS','protocol_sha256':sha(protocol),'argument_sha256':sha(HERE/'R31_BRANCH_ARGUMENT.md'),'script_sha256':sha(Path(__file__)),'source_sha256':sha(HERE/'branch_endpoint.cpp'),'unchanged_endpoint_sha256':sha(HERE/'endpoint_implementation.hpp'),'graph_sha256':sha(graph),'graph_bytes':graph.stat().st_size,'parameter_cases':len(cases),'complete_joint_graphs':len(summaries),'totals':dict(counts),'p9_a2_b7_graphs':[r for r in summaries if cases[r['case']]==(9,2,7)],'scalar_queries':scalar_count,'nonpositive_scalar_answers_retained':nonpositive,'canonical_master_count':1,'raw_phase_count':2,'equal_information_completion_payload':'same one pair','graphs':summaries,'negative_controls':negative,'relation':'sound periodic enclosure, not asserted exact reachability','implementation_scope':'same own logical endpoint, second own specified control structure, not independent native application/hardware','measured_analysis_or_hardware_benefit':False}
 out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
 print(json.dumps({k:v for k,v in result.items() if k!='graphs'},indent=2))
if __name__=='__main__':main()
