"""Derive relations and complete grid only from actually executed trace rows."""
from pathlib import Path
from collections import defaultdict,Counter
import argparse,csv,gzip,hashlib,json,math
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,x):p.write_text(json.dumps(x,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
def rows(p):
 with p.open(encoding='utf-8',newline='') as f:
  for r in csv.DictReader(f):yield {k:int(v) for k,v in r.items()}
def key(r,prefix='before_'):
 q=lambda x:r[prefix+x];n=q('nextid')
 return (q('cp'),q('rp'),q('fp'),q('pp'),tuple(((q('qowners')>>(2*i))&3,q('qid'+str(i))-n) for i in range(q('qlen'))),
         None if not q('R0v') else (q('R0owner'),q('R0id')-n,q('R0byte')),
         None if not q('R1v') else (q('R1owner'),q('R1id')-n,q('R1byte')),
         q('outstanding'),q('valid'),q('enabled'),q('bytes'),tuple(q('count'+str(i)) for i in range(4)),q('failed'),q('fault'))
def control_events(r):
 out=[]
 for e in ['enq','attempt','grant','emit','transfer','callback','block']:
  flag='evenq' if e=='enq' else 'ev'+e
  if r[flag]:
   out.append((e,r[e+'owner'],r[e+'id']))
   if e=='enq' and r[flag]==2:out.append((e,r['enqowner2'],r['enqid2']))
 return tuple(out)
def normal_events(r,base):return tuple((e,j,i-base) for e,j,i in control_events(r))
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--build',default='build-04');ap.add_argument('--out',default='analysis-01');a=ap.parse_args();build=HERE/a.build;out=HERE/a.out;out.mkdir(exist_ok=False)
 bound=[HERE/n for n in ['PROTOCOL.json','AMENDMENT_01_PRE_EXECUTION.md','AMENDMENT_02_FULL_KEY_EXTENSION.md','receiver.v','driver.cpp','analyze.py']]+[build/n for n in ['CONTROL_TICKS.csv','DATA_TICKS.csv','RUN_COUNTERS.csv','BUILD.json']]
 dump(out/'PRECOMPUTATION_BINDING.json',{'status':'BOUND_BEFORE_DERIVED_INPUT_GENERATION','inputs':{str(p.relative_to(HERE)):sha(p) for p in bound}})
 controls=defaultdict(list)
 for r in rows(build/'CONTROL_TICKS.csv'):controls[r['case']].append(r)
 records=[];study=Counter();allpol=[];phasefile=gzip.open(out/'ALL_PHASES.jsonl.gz','wt',encoding='utf-8',newline='\n');phasefile.write(json.dumps({'schema':'P/phi rows; full/prefix/cycle/completion bases are K=1 expiry-minus-next-grant, add (K-1)P. Witness=[line,s,c,h,kind,translation_n]. Prefix is freshly computed for actual physical P,phi. Integer strict positivity only. All K1..16 and original K1..5 masks retained.'})+'\n');aggregate=Counter();tuning=[]
 for ci,trace in sorted(controls.items()):
  cfg={k:trace[0][k] for k in ['p','r','F']};F=cfg['F'];assert len(trace)==4*F and all(r['t']==i for i,r in enumerate(trace))
  for r in trace:assert r['after_fault']==r['after_failed']==0
  seen={};entry=repeat=None
  for t,r in enumerate(trace):
   k=key(r)
   if k in seen:entry=seen[k];repeat=t;break
   seen[k]=t
  assert entry is not None and repeat is not None;d=repeat-entry;assert d==F;assert entry+3*d<=len(trace)
  delta=trace[repeat]['before_nextid']-trace[entry]['before_nextid'];assert delta==8
  # Both translated continuation periods, including every active token/event ID.
  for t in range(entry,entry+2*d):
   ra,rb=trace[t],trace[t+d];assert key(ra)==key(rb)
   assert rb['before_nextid']-ra['before_nextid']==delta
   assert normal_events(ra,ra['before_nextid'])==normal_events(rb,rb['before_nextid'])
  empty=lambda r:r['before_qlen']==r['before_R0v']==r['before_R1v']==r['before_outstanding']==0
  frameclear=all(empty(trace[t]) for t in [0,F,2*F,3*F]) and key(trace[0])==key(trace[F])
  grant={};callback={};linegrants=defaultdict(list)
  for r in trace:
   if r['evgrant']:
    id=r['grantid'];assert id not in grant;grant[id]=(r['grantowner'],r['t']);linegrants[r['grantowner']].append((r['t'],id))
   if r['evcallback']:
    id=r['callbackid'];assert id not in callback;callback[id]=(r['callbackowner'],r['t'])
  lines=[];completiondomain=True
  for j in range(4):
   gl=linegrants[j];edges=[]
   for (s,id),(h,nid) in zip(gl,gl[1:]):
    if s>=entry+d:break
    assert id in callback and callback[id][0]==j and grant[nid][0]==j
    c=callback[id][1];assert s<c and s<h
    edges.append([s,c,h]);completiondomain&=c<=h
    # Verify predecessor crossing relation on the following full control period.
    if s>=entry:
     assert (s+d,id+delta) in gl and (h+d,nid+delta) in gl
     assert callback[id+delta]==(j,c+d)
   pre=[x for x in edges if x[0]<entry];cyc=[x for x in edges if entry<=x[0]<entry+d];assert len(cyc)==2
   J=max(c-s for s,c,h in cyc);A=max(h-c for s,c,h in cyc)
   lines.append({'line':j,'initial_capture_cutpoint':gl[0][0],'prefix':pre,'cycle':cyc,'C0':sorted({c%d for s,c,h in cyc}),'J':J,'A':A,'completion_domain':all(c<=h for s,c,h in cyc)})
  rec={'case':ci,'configuration':cfg,'original_empty_frame_gate':'PASS' if frameclear else 'FAILED_UNKNOWN','full_key_extension':'VALIDATED_FULL_KEY_CYCLE','entry':entry,'repeat':repeat,'period':d,'physical_validation_end_exclusive':entry+3*d,'ID_translation':delta,'cycle_entry_empty':empty(trace[entry]),'entry_state':{k:v for k,v in trace[entry].items() if k.startswith('before_')},'completion_domain':completiondomain,'lines':lines}
  records.append(rec);study['cases']+=1;study['original_empty_frame_pass']+=frameclear;study['original_empty_frame_unknown']+=not frameclear;study['full_key_cycles']+=1;study['prefix_edges']+=sum(len(x['prefix']) for x in lines);study['cycle_edges']+=8
  local=Counter();opts={k:[] for k in ['service','completion','original5_service','original5_completion']}
  for P in range(1,4*cfg['p']+1):
   m=math.gcd(P,d);copies=[]
   for l in lines:
    copies.append([(s+n*d,c+n*d,h+n*d,n) for s,c,h in l['cycle'] for n in range(P//m)])
   ph=[]
   for phi in range(P):
    candidates=[];prevals=[];lineinfo=[];cb=[]
    for l,ls in zip(lines,copies):
     j=l['line'];cr=min((s+1+(phi-s-1)%P-h,s,j,c,h,'cycle',n) for s,c,h,n in ls)
     pv=[(s+1+(phi-s-1)%P-h,s,j,c,h,'prefix',0) for s,c,h in l['prefix']]
     candidates.append(cr);candidates+=pv;prevals+=pv
     comp=1-l['J']-l['A']+min((phi+l['J']-1-c)%m for c in l['C0'])
     assert comp<=cr[0];cb.append(comp)
     lineinfo.append({'line':j,'prefix_base':min(pv)[0] if pv else None,'cycle_base':cr[0],'completion_cycle_base':comp})
    witness=min(candidates);base,s,j,c,h,kind,n=witness;pb=min(prevals)[0] if prevals else None;cyclebase=min(x[0] for x in candidates if x[5]=='cycle');compbase=min(cb+([pb] if pb is not None else []));assert compbase<=base
    masks=[sum(1<<(K-1) for K in range(1,17) if v+(K-1)*P>0) for v in [base,compbase]]
    assert masks[1]&~masks[0]==0
    ph.append({'phi':phi,'service_base':base,'prefix_base':pb,'cycle_base':cyclebase,'completion_base':compbase,'witness':[j,s,c,h,kind,n],'line_bases':lineinfo,'service_mask_K1to16':masks[0],'completion_mask_K1to16':masks[1],'original5_service_mask':masks[0]&31,'original5_completion_mask':masks[1]&31})
    for K in range(1,17):
     slack=base+(K-1)*P;expiry=s+1+(phi-s-1)%P+(K-1)*P
     start=(entry+n*d) if kind=='cycle' and rec['cycle_entry_empty'] else 0
     assert start<=s and start<=h<start+2*F
     # Direct decrement count, separate from the expiry expression.
     decrements=sum(t%P==phi for t in range(s+1,h+1));assert (slack>0)==(K>decrements)
     allpol.append([len(allpol),ci,K,P,phi,j,s,c,h,s+1,start,n,slack,expiry])
     local['policy_queries']+=1;local['service_positive']+=slack>0;local['completion_positive']+=compbase+(K-1)*P>0;local['service_only']+=(slack>0 and compbase+(K-1)*P<=0)
     local['original5_queries']+=K<=5;local['original5_service_positive']+=K<=5 and slack>0;local['original5_completion_positive']+=K<=5 and compbase+(K-1)*P>0
     for route,val in [('service',slack),('completion',compbase+(K-1)*P)]:
      if val>0:
       opts[route].append([K*P-1,K,P,phi]);
       if K<=5:opts['original5_'+route].append([K*P-1,K,P,phi])
   phasefile.write(json.dumps({'case':ci,'P':P,'gcd':m,'physical_cycle_entry':entry,'physical_repeat':entry+math.lcm(P,d),'rows':ph},separators=(',',':'))+'\n')
  optrec={}
  for k,v in opts.items():
   value=min((x[0] for x in v),default=None);ties=sorted([x[1:] for x in v if x[0]==value]);optrec[k]={'minimum_KP_minus1':value,'all_ties_K_P_phi':ties,'selected_K_P_phi':ties[0] if ties else None,'empty':not ties}
  gain=None if optrec['service']['empty'] or optrec['completion']['empty'] else optrec['completion']['minimum_KP_minus1']-optrec['service']['minimum_KP_minus1']
  tuning.append({'case':ci,'original_empty_frame_gate':rec['original_empty_frame_gate'],'extension_status':rec['full_key_extension'],'counts':dict(local),'optima':optrec,'gain_ticks':gain,'no_gain':gain==0});aggregate.update(local)
 phasefile.close()
 with (out/'policies.txt').open('w',encoding='utf-8',newline='\n') as f:
  f.write(str(len(allpol))+'\n')
  for x in allpol:f.write(' '.join(map(str,x))+'\n')
 assert len(records)==12 and len(allpol)==130112
 dump(out/'RELATIONS.json',{'scope':'Original empty-frame gate retained separately from post-observation full-key extension. All triples extracted from generated RTL.','records':records})
 dump(out/'TUNING.json',{'objective':'minimum KP-1 retention proxy only','records':tuning})
 dump(out/'RESULTS.json',{'status':'PRODUCER_ARITHMETIC_PENDING_RTL_POLICY_RUN_AND_INDEPENDENT_GATE','study':dict(study),'counts':dict(aggregate),'policy_queries':len(allpol),'all_ties_preserved':True,'no_gain_cases':[r['case'] for r in tuning if r['no_gain']],'gains_by_case':[r['gain_ticks'] for r in tuning]})
 for p in bound:assert sha(p)==json.loads((out/'PRECOMPUTATION_BINDING.json').read_text())['inputs'][str(p.relative_to(HERE))]
 print(json.dumps({'study':dict(study),'counts':dict(aggregate),'no_gain_cases':[r['case'] for r in tuning if r['no_gain']],'entries':[[r['case'],r['entry'],r['repeat'],r['cycle_entry_empty']] for r in records]},indent=2))
if __name__=='__main__':main()
