"""Existing twelve-phase producer, new local policy/replay illustrations."""
from pathlib import Path
from collections import Counter
import argparse,hashlib,json,math,subprocess
from source_producer import NAMES,extract
from r23_canonical import canonical,envelope
from r26_remod import profile,project
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def scalar():
 prior=HERE/'R30_PRODUCER_FAMILY_RESULTS.json';old=json.loads(prior.read_text(encoding='utf-8'))
 candidates=[r for r in old['records'] if r['admitted']]
 selected=max(candidates,key=lambda r:(len(r['master_pairs']),r['translation'],-r['s0']))
 assert (selected['p'],selected['q'],selected['s0'])==(12,35,0)
 T=[tuple(x) for x in selected['cycle']];assert not selected['prefix'] and T==[(35*k,36*k+12,35*(k+1)) for k in range(12)]
 J=max(c-s for s,c,h in T);A=max(h-c for s,c,h in T);assert (J,A)==(23,23)
 assert not [(s,c,h) for s,c,h in T if c-s==J and h-c==A]
 raw=profile([(s,h-s) for s,c,h in T],420);master=canonical(raw,420);stored=project(master,140)
 assert len(raw)==len(master)==12 and stored==((0,35),(35,35),(70,35),(105,35))
 divisors={}
 for m in range(1,421):
  if 420%m:continue
  Q=project(master,m);assert Q==canonical(profile([(s,h-s) for s,c,h in T],m),m)
  divisors[str(m)]={'pairs':Q,'supports_g140':140%m==0}
  if 140%m==0:assert project(stored,m)==Q
 queries=unknown=positive=unsupported=0
 for P in range(1,85):
  m=math.gcd(P,420);Q=project(master,m)
  for phi in range(P):
   exact=min(1+(phi-s-n*420-1)%P-(h-s) for s,c,h in T for n in range(P//m))
   derived=1+min((phi-r-1)%m-v for r,v in Q);assert exact==derived
   if 140%m==0:assert derived==1+min((phi-r-1)%m-v for r,v in project(stored,m))
   for K in range(1,6):
    value=(K-1)*P+exact;queries+=1;unknown+=value<=0;positive+=value>0;unsupported+=140%m!=0
 policies=[]
 for K,P,phi in [(2,40,1),(5,10,1)]:
  m=math.gcd(P,420);Q=project(stored,m);C=sorted({c%m for s,c,h in T})
  fair=canonical(profile([((c-J)%m,J+A) for c in C],m),m)
  exact=(K-1)*P+1+min((phi-r-1)%m-v for r,v in Q)
  bound=(K-1)*P+1+min((phi-r-1)%m-v for r,v in fair)
  assert exact==6 and bound==(-2 if P==40 else -4) and len(fair)==5
  policies.append({'K':K,'P':P,'phi':phi,'query_m':m,'physical_B':(K-1)*P,'service_pairs':Q,'fair_completion_pairs':fair,'exact_slack':exact,'completion_bound':bound,'service_terms':len(Q),'completion_terms':len(fair)})
 # Review terminology example: raw equality is false, canonical equality holds.
 Q=((0,2),(1,1));assert canonical(Q,3)==((0,2),) and envelope(Q,3)==envelope(((0,2),),3)
 return {'prior_family_result_sha256':sha(prior),'selected_case_id':selected['case_id'],'base_triples':T,'translation':420,'J':J,'A':A,'joint_witnesses':0,'raw_terms':12,'full_master_terms':12,'stored_g':140,'stored_pairs':stored,'divisors':divisors,'illustrative_policies':policies,'new_scalar_queries':queries,'nonpositive_unknown_retained':unknown,'positive_queries':positive,'g140_unsupported_queries_need_master_or_producer':unsupported,'raw_canonical_terminology_example':'PASS'}
def replay(k,wu,K,P,L):
 t,V,E,count,v,z0,id0,b0,z1,id1,b1=k;assert E or count==0
 deadline=t+(1-t)%P+(count-1)*P if E else None
 if wu and V:v=0;deadline=t+(1-t)%P+(K-1)*P
 expired=deadline==t
 if expired:V=0;deadline=None
 rid=1+(t%420)//35 if t%35==0 else 0
 pending=[i for z,i in [(z0,id0),(z1,id1)] if z];assert len(pending)<=1
 if rid:
  assert V and not pending
  deadline=None;pending=[rid]
 out=0;R0=[0,0,0];R1=[0,0,0]
 if pending:
  i=pending[0];s=t-(t-(i-1)*35)%420;a=12*((s+11)//12);c=a+12;assert c>=t
  if c==t:out=i
  elif a<=t:R1=[1,i,0]
  else:R0=[1,i,0]
 if deadline is None:E=0;count=0
 else:
  E=1;nxt=t+1+(1-t-1)%P;assert deadline>=nxt;count=(deadline-nxt)//P+1
 return [(t+1)%L,V,E,count,v,*R0,*R1],rid,out,int(expired)
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--zig',type=Path,required=True);a=ap.parse_args()
 out=HERE/'R34_MULTIPHASE_RESULTS.json';build=HERE/'multiphase-endpoint-build';assert not out.exists() and not build.exists();build.mkdir()
 assert json.loads((HERE/'R34_MULTIPHASE_PROTOCOL.json').read_text())['status']=='prospective_before_new_execution_posthoc_existing_family_selection'
 theory=scalar();public=(HERE/'upstream-memtest.cc').read_text(encoding='utf-8');defs=[(n,extract(public,n)[0]) for n in NAMES]
 code=public[:public.index('*/')+2]+'\n'+(HERE/'serial_client.prefix.cpp').read_text(encoding='utf-8')+'\n'+'\n\n'.join(body for n,body in defs)+'\n'+(HERE/'endpoint_port.cpp').read_text(encoding='utf-8')+'\n'+(HERE/'multiphase_endpoint_main.cpp').read_text(encoding='utf-8')
 for n,body in defs:assert extract(code,n)[0]==body
 source=build/'multiphase_endpoint.cpp';source.write_text(code,encoding='utf-8');binary=build/'multiphase_endpoint.exe'
 run=subprocess.run([str(a.zig),'c++','-std=c++17','-O2','-UNDEBUG','-I',str(HERE),str(source),'-o',str(binary)],capture_output=True,text=True,timeout=120)
 (build/'compiler.log').write_text(run.stdout+'\n'+run.stderr,encoding='utf-8');assert run.returncode==0,run.stderr
 coupled=build/'source-records.jsonl'
 with coupled.open('w',encoding='utf-8',newline='\n') as f:run=subprocess.run([str(binary)],stdout=f,stderr=subprocess.PIPE,text=True,timeout=300)
 (build/'source.stderr').write_text(run.stderr,encoding='utf-8');assert run.returncode==0,run.stderr
 runs=Counter();controls=[]
 for line in coupled.open(encoding='utf-8'):
  r=json.loads(line)
  if r['negative'] or r['invalid']:controls.append(r);continue
  assert r['services']==[35*k for k in range(33)] and r['receipts']==[12*((35*k+11)//12)+12 for k in range(32)]
  runs[r['policy']]+=1
 assert dict(runs)=={0:4096,1:4096} and len(controls)==2
 assert controls[0]['last']==35 and controls[1]['last']==0
 graphs=build/'graphs.jsonl'
 with graphs.open('w',encoding='utf-8',newline='\n') as f:run=subprocess.run([str(binary),'--bfs'],stdout=f,stderr=subprocess.PIPE,text=True,timeout=300)
 (build/'bfs.stderr').write_text(run.stderr,encoding='utf-8');assert run.returncode==0,run.stderr
 summaries=[];states={};edges=[];total_states=total_edges=0
 for line in graphs.open(encoding='utf-8'):
  r=json.loads(line)
  if r['kind']=='state':states[r['id']]=r['key']
  elif r['kind']=='edge':edges.append(r)
  else:
   policy=r['policy'];K,P=(2,40) if policy==0 else (5,10);L=math.lcm(420,P)
   assert len(states)==r['states'] and len(edges)==r['edges']==2*len(states) and r['period']==L
   assert states[0]==[0,1,0,0,0,0,0,0,0,0,0]
   pairs=Counter()
   for e in edges:
    pred,rid,reply,expired=replay(states[e['from']],e['wu'],K,P,L)
    assert pred==states[e['to']] and rid==e['read'] and reply==e['reply'] and expired==e['expired']==0,(e,pred,states[e['to']])
    pairs[(e['from'],e['wu'])]+=1
   assert len(pairs)==2*len(states) and set(pairs.values())=={1}
   summaries.append(r);total_states+=len(states);total_edges+=len(edges);states={};edges=[]
 assert len(summaries)==2 and not states and not edges
 result={'result':'PASS_EXISTING_MULTIPHASE_PRODUCER_NEW_POLICY_EXECUTIONS_AND_ALL_WU_REPLAY','protocol_sha256':sha(HERE/'R34_MULTIPHASE_PROTOCOL.json'),'argument_sha256':sha(HERE/'R34_MULTIPHASE_ARGUMENT.md'),'script_sha256':sha(Path(__file__)),'driver_sha256':sha(HERE/'multiphase_endpoint_main.cpp'),'unchanged_receiver_sha256':sha(HERE/'endpoint_implementation.hpp'),'generated_source_sha256':sha(source),'source_records_sha256':sha(coupled),'graph_sha256':sha(graphs),'theory':theory,'source_coupled_runs':sum(runs.values()),'accepted_reads':sum(runs.values())*33,'callbacks':sum(runs.values())*32,'negative_controls':controls,'graphs':summaries,'states':total_states,'edges_replayed':total_edges,'scope':'Existing pinned-source family member, same authored receiver. New local policies and analyses; no new hardware/native conformance. Selected runs are samples; all-word coverage relies on manual schedule/congruence and fixed-schedule graph. Independent arithmetic replay shares predecessor/configuration/input. All unfavorable outcomes retained; no measured runtime/bytes/application gain.'}
 out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps(result,indent=2))
if __name__=='__main__':main()
