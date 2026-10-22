"""Compile a specified receiver, couple original client bodies, replay its BFS."""
from pathlib import Path
from collections import Counter,defaultdict
import argparse,hashlib,json,math,subprocess
from source_producer import NAMES,extract
HERE=Path(__file__).resolve().parent

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

def expected_client():
 services=[5];receipts=[];polls=[]
 for _ in range(8):
  s=services[-1];c=9*((s+8)//9)+9;assert c!=s+16
  receipts.append(c)
  if c>s+16:polls.append(s+16)
  services.append(s+16 if c<s+16 else c+16)
 return services,receipts,polls

def independent_deadline_successor(state,wu,K,P,phi):
 # The C++ implementation stores a countdown. This replay instead reconstructs
 # the absolute expiry of its remaining arm and converts back only at the end.
 t,valid,enabled,count,value,b0,id0,v0,b1,id1,v1=state
 deadline=t+(phi-t)%P+(count-1)*P if enabled else None
 if wu and valid:value=0;deadline=t+(phi-t)%P+(K-1)*P
 expired=deadline==t
 if expired:valid=0;deadline=None
 request={5:1,21:2,37:3,70:4}.get(t%81,0)
 if request:
  assert valid and not b0 and not b1
  deadline=None;b0,id0,v0=1,request,value
 response=0
 if t%9==0:
  if b1:response=id1
  b1,id1,v1=b0,id0,v0;b0,id0,v0=0,0,0
 assert response=={18:1,36:2,54:3,0:4}.get(t%81,0)
 if deadline is None:enabled=count=0
 else:
  enabled=1;next_boundary=t+1+(phi-t-1)%P
  assert deadline>=next_boundary and (deadline-next_boundary)%P==0
  count=1+(deadline-next_boundary)//P
 result=[(t+1)%math.lcm(81,P),valid,enabled,count,value,b0,id0,v0,b1,id1,v1]
 return result,request,response,int(expired)

def admit(record,actual,query,*,fresh_entry=True,valid_entry=True,revoked=False,end_tick=1000):
 immutable=['tag','epoch','cache_period','response_stages','independent_WU_lane','dedicated_ready_sink','implementation_sha256']
 if revoked:return {'accepted':False,'reason':'revoked'}
 if not fresh_entry:return {'accepted':False,'reason':'unproved_hot_policy_transition'}
 if not valid_entry:return {'accepted':False,'reason':'invalid_entry'}
 if end_tick>record['horizon']:return {'accepted':False,'reason':'horizon_exceeded'}
 for k in immutable:
  if actual[k]!=record[k]:return {'accepted':False,'reason':'binding_mismatch:'+k}
 K,P,phi=query;g=math.gcd(P,record['translation'])
 if record['source_modulus']%g:return {'accepted':False,'reason':'source_modulus_not_sufficient'}
 pairs=record['pairs'];slack=(K-1)*P+1+min((phi-r-1)%g-v for r,v in pairs)
 return {'accepted':slack>0,'reason':'positive_observer_slack' if slack>0 else 'unknown_nonpositive_slack','g':g,'slack':slack,'runtime_policy':query,'fresh_runtime_entry':True}

def main():
 parser=argparse.ArgumentParser();parser.add_argument('--zig',type=Path,required=True);args=parser.parse_args()
 result_path=HERE/'R28_ENDPOINT_RESULTS.json';build=HERE/'endpoint-build';assert not result_path.exists() and not build.exists();build.mkdir()
 public=HERE/'upstream-memtest.cc';text=public.read_text(encoding='utf-8');defs=[(n,*extract(text,n)) for n in NAMES]
 code=text[:text.index('*/')+2]+'\n'+(HERE/'serial_client.prefix.cpp').read_text(encoding='utf-8')+'\n'+'\n\n'.join(d[1] for d in defs)+'\n'+(HERE/'endpoint_port.cpp').read_text(encoding='utf-8')+'\n'+(HERE/'endpoint_main.cpp').read_text(encoding='utf-8')
 assert 'const Tick target=' not in code and 'memtest.lat_cycles)*memtest.cache_period' not in code
 for n,body,_,_ in defs:assert extract(code,n)[0]==body
 cpp=build/'endpoint_client.cpp';cpp.write_text(code,encoding='utf-8');binary=build/'endpoint_client.exe'
 compiled=subprocess.run([str(args.zig),'c++','-std=c++17','-O2','-UNDEBUG','-I',str(HERE),str(cpp),'-o',str(binary)],capture_output=True,text=True,timeout=120)
 (build/'compiler.log').write_text(compiled.stdout+compiled.stderr,encoding='utf-8');assert compiled.returncode==0,compiled.stderr
 runs={}
 for name,extra in [('coupled',[]),('bfs',['--bfs'])]:
  run=subprocess.run([str(binary),*extra],capture_output=True,text=True,timeout=120)
  (build/(name+'.jsonl')).write_text(run.stdout,encoding='utf-8');(build/(name+'.stderr')).write_text(run.stderr,encoding='utf-8')
  assert run.returncode==0,run.stderr
  runs[name]=[json.loads(line) for line in run.stdout.splitlines()]
 expected=expected_client();counts=Counter();negative=[];controls=[]
 for r in runs['coupled']:
  if r['kind']=='value_revocation_controls':controls.append(r);continue
  if r['policy'] in ['old','new']:
   assert (r['services'],r['receipts'],r['waiting_polls'])==expected,r
   assert r['first_miss'] is None and r['first_expiry'] is None and r['pending_snapshots']==1
   counts[(r['policy'],r['family'])]+=1
  else:negative.append(r)
 assert counts=={('old','mask'):4096,('old','finite'):3404,('new','mask'):4096,('new','finite'):3404}
 assert len(controls)==1 and all(controls[0][k] for k in ['snapshot_preserved_under_updates','revocation_first','invalid_WU_no_resurrection'])
 assert len(negative)==2 and negative[0]['policy']=='unsafe' and negative[0]['first_expiry']==56 and negative[0]['first_miss']==70
 assert negative[1]['policy']=='invalid_entry' and negative[1]['first_miss']==5 and negative[1]['services']==[]
 graphs={};replayed=0
 for policy,K,P,phi in [('old',2,27,6),('new',3,18,2)]:
  rows=[r for r in runs['bfs'] if r['policy']==policy];states={r['id']:r['state'] for r in rows if r['kind']=='bfs_state'}
  edges=[r for r in rows if r['kind']=='bfs_edge'];summary=next(r for r in rows if r['kind']=='bfs_summary')
  assert len(states)==summary['states'] and len(edges)==summary['transitions']==2*len(states)
  assert set(states)==set(range(len(states))) and states[0]==[5,1,0,0,0,0,0,0,0,0,0]
  successors=Counter()
  for r in edges:
   pred,request,response,expired=independent_deadline_successor(states[r['from']],r['wu'],K,P,phi)
   assert pred==states[r['to']] and request==r['read_id'] and response==r['response_id'] and expired==r['expired']==0
   successors[(r['from'],r['wu'])]+=1;replayed+=1
  assert all(successors[(i,b)]==1 for i in states for b in [0,1])
  graphs[policy]=summary
 record={'tag':64,'epoch':7,'cache_period':9,'response_stages':2,'independent_WU_lane':True,'dedicated_ready_sink':True,'implementation_sha256':sha(HERE/'endpoint_implementation.hpp'),'horizon':1000000,'translation':81,'source_modulus':27,'pairs':[[5,16],[10,33]],'evidence':'new endpoint register/countdown refinement and checked source/control relation'}
 binding_cases=[{'name':'old_policy','result':admit(record,record,(2,27,6))},{'name':'new_policy','result':admit(record,record,(3,18,2))}]
 assert [x['result']['slack'] for x in binding_cases]==[12,4] and all(x['result']['accepted'] for x in binding_cases)
 for name,changed,kwargs in [('clock',{'cache_period':10},{}),('epoch',{'epoch':8},{}),('WU_lane',{'independent_WU_lane':False},{}),('revoked',{},dict(revoked=True)),('horizon',{},dict(end_tick=1000001)),('invalid_entry',{},dict(valid_entry=False)),('hot_transition',{},dict(fresh_entry=False))]:
  verdict=admit(record,{**record,**changed},(3,18,2),**kwargs);assert not verdict['accepted'];binding_cases.append({'name':name,'result':verdict})
 result={'result':'PASS_CONSTRUCTED_ENDPOINT_CLIENT_REFINEMENT_AND_ALL_WU_CONTROL_GRAPH','protocol_sha256':sha(HERE/'R28_ENDPOINT_PROTOCOL.json'),'argument_sha256':sha(HERE/'R28_ENDPOINT_ARGUMENT.md'),'script_sha256':sha(Path(__file__)),'source_input_sha256':{n:sha(HERE/n) for n in ['endpoint_implementation.hpp','endpoint_port.cpp','endpoint_main.cpp','serial_client.prefix.cpp','upstream-memtest.cc']},'function_bindings':[{'name':n,'sha256':hashlib.sha256(body.encode()).hexdigest(),'first_line':first,'last_line':last} for n,body,first,last in defs],'generated_source_sha256':sha(cpp),'binary_sha256':sha(binary),'coupled_records_sha256':sha(build/'coupled.jsonl'),'BFS_records_sha256':sha(build/'bfs.jsonl'),'source_coupled_executions':sum(counts.values()),'source_coupled_cases':[{'policy':p,'family':f,'executions':n} for (p,f),n in sorted(counts.items())],'accepted_source_reads':sum(counts.values())*9,'completed_source_callbacks':sum(counts.values())*8,'graphs':graphs,'independently_replayed_countdown_to_deadline_edges':replayed,'analysis_record':record,'binding_cases':binding_cases,'negative_source_traces':negative,'data_revocation_controls':controls,'new_native_cache_execution':False,'new_GPU_measurements':0,'scope':'New explicitly specified executable receiver; source-function harness/packet/clock environment still declared. Two pipeline registers produce callbacks, not a response-time formula. Independent complete finite control exploration and refinement argument cover every admitted WU bit word for this endpoint under no-overflow horizon. This does not establish historical native HUSH/gem5, physical hardware timing or global data coherence.'}
 result_path.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
 print(json.dumps({k:v for k,v in result.items() if k not in ['function_bindings','analysis_record','binding_cases','negative_source_traces','source_input_sha256']},indent=2))
if __name__=='__main__':main()
