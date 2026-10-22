"""Independent trace-derived complete-key, physical-prefix and exact grid oracle.
No producer checker is imported or executed by this program.
"""
from pathlib import Path
from collections import defaultdict, Counter
import csv, gzip, hashlib, json, math
HERE=Path(__file__).resolve().parent
SOURCE=HERE.parent
BUILD=HERE/'frozen-input/fresh-build'
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def dump(name,data): (HERE/name).write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
def rows(p):
 with p.open(newline='',encoding='utf-8') as f:
  return [{k:int(v) for k,v in r.items()} for r in csv.DictReader(f)]
def livekey(r,side='before_'):
 s={k[len(side):]:v for k,v in r.items() if k.startswith(side)}
 origin=s['nextid']
 queue=tuple(((s['qowners']>>(2*i))&3,s[f'qid{i}']-origin) for i in range(s['qlen']))
 snap=lambda n: (s[n+'owner'],s[n+'id']-origin,s[n+'byte']) if s[n+'v'] else None
 return (s['cp'],s['rp'],s['fp'],s['pp'],queue,snap('R0'),snap('R1'),s['outstanding'],s['valid'],s['enabled'],s['bytes'],*(s[f'count{i}'] for i in range(4)),s['failed'],s['fault'])
def events(r):
 e=[];origin=r['before_nextid']
 for name in ['enq','attempt','grant','emit','transfer','callback','block']:
  flag=r['evenq' if name=='enq' else 'ev'+name]
  if flag:
   e.append((name,r[name+'owner'],r[name+'id']-origin,r.get(name+'byte',0)))
   if name=='enq' and flag==2:e.append((name,r['enqowner2'],r['enqid2']-origin,0))
 return tuple(e)
def expiry_one(s,P,phi):
 # Absolute first decrement, independently implemented as ceiling division.
 return phi + ((s+1-phi+P-1)//P)*P
def main():
 source_hashes={p.name:sha(p) for p in (HERE/'frozen-input').iterdir() if p.is_file()}
 controls=defaultdict(list)
 for r in rows(HERE/'INDEPENDENT_CONTROL_5F.csv'):controls[r['case']].append(r)
 # Fresh producer-driver streams, but independent actual netlist execution.
 semantic_equal={n:sha(BUILD/n)==sha(SOURCE/'build-04'/n) for n in ['CONTROL_TICKS.csv','DATA_TICKS.csv','RUN_COUNTERS.csv']}
 assert all(semantic_equal.values()),semantic_equal
 expected_rel=json.loads((SOURCE/'analysis-01/RELATIONS.json').read_text())['records']
 expected_tune=json.loads((SOURCE/'analysis-01/TUNING.json').read_text())['records']
 expected_ph=gzip.open(SOURCE/'analysis-01/ALL_PHASES.jsonl.gz','rt',encoding='utf-8');next(expected_ph)
 policy=(HERE/'INDEPENDENT_policies.txt').open('w',encoding='utf-8',newline='\n');policy.write('130112\n')
 phases=gzip.open(HERE/'INDEPENDENT_ALL_PHASES.jsonl.gz','wt',encoding='utf-8',newline='\n')
 records=[];tunings=[];totals=Counter();qi=0
 for ci,tr in sorted(controls.items()):
  p,r,F=(tr[0][x] for x in ['p','r','F']);assert len(tr)==5*F
  seen={}
  for t,row in enumerate(tr):
   assert row['t']==t and row['after_fault']==row['after_failed']==0
   k=livekey(row)
   if k in seen:entry=seen[k];repeat=t;break
   seen[k]=t
  else:raise AssertionError(('no full-key repeat',ci))
  d=repeat-entry;assert d==F and tr[repeat]['before_nextid']-tr[entry]['before_nextid']==8
  assert entry+3*d<=len(tr)
  for t in range(entry,entry+2*d):
   a,b=tr[t],tr[t+d]
   assert livekey(a)==livekey(b) and livekey(a,'after_')==livekey(b,'after_')
   assert b['before_nextid']-a['before_nextid']==8 and events(a)==events(b)
  empty=lambda row:all(row['before_'+k]==0 for k in ['qlen','R0v','R1v','outstanding'])
  original=all(empty(tr[t]) for t in [0,F,2*F,3*F]) and livekey(tr[0])==livekey(tr[F])
  grants=defaultdict(list);callbacks={}
  for row in tr:
   if row['evgrant']:grants[row['grantowner']].append((row['t'],row['grantid']))
   if row['evcallback']:
    ident=row['callbackid'];assert ident not in callbacks;callbacks[ident]=(row['callbackowner'],row['t'])
  lines=[]
  for j in range(4):
   gl=grants[j];full=[]
   for (s,ident),(h,nid) in zip(gl,gl[1:]):
    if s>=entry+d:break
    jj,c=callbacks[ident];assert jj==j and s<c<=h
    full.append([s,c,h])
    if s>=entry:
     for n in [1,2]:
      assert (s+n*d,ident+8*n) in gl and (h+n*d,nid+8*n) in gl
      assert callbacks[ident+8*n]==(j,c+n*d)
   pre=[e for e in full if e[0]<entry];cyc=[e for e in full if e[0]>=entry]
   assert len(cyc)==2
   lines.append(dict(line=j,initial_capture_cutpoint=gl[0][0],prefix=pre,cycle=cyc,C0=sorted(set(c%d for s,c,h in cyc)),J=max(c-s for s,c,h in cyc),A=max(h-c for s,c,h in cyc),completion_domain=True))
  rel=dict(case=ci,configuration=dict(p=p,r=r,F=F),original_empty_frame_gate='PASS' if original else 'FAILED_UNKNOWN',full_key_extension='VALIDATED_FULL_KEY_CYCLE',entry=entry,repeat=repeat,period=d,physical_validation_end_exclusive=entry+3*d,ID_translation=8,cycle_entry_empty=empty(tr[entry]),entry_state={k:v for k,v in tr[entry].items() if k.startswith('before_')},completion_domain=True,lines=lines)
  assert rel==expected_rel[ci],('relations',ci);records.append(rel)
  local=Counter();opts={k:[] for k in ['service','completion','original5_service','original5_completion']}
  for P in range(1,4*p+1):
   g=math.gcd(P,d);orbit=P//g;phase_rows=[]
   for phi in range(P):
    candidates=[];prefix=[];line_bases=[];cb=[]
    for line in lines:
     j=line['line'];cycle=[];pre=[]
     for s,c,h in line['cycle']:
      for n in range(orbit):
       ss,cc,hh=s+n*d,c+n*d,h+n*d
       cycle.append((expiry_one(ss,P,phi)-hh,ss,j,cc,hh,'cycle',n))
     for s,c,h in line['prefix']:
      # Literal physical-P prefix: no inherited admission bit or reduced modulus.
      first=next(t for t in range(s+1,s+P+1) if t%P==phi)
      pre.append((first-h,s,j,c,h,'prefix',0))
     # Derive completion bound from concrete translated completion edges.
     comp=min(expiry_one(c+n*d-line['J'],P,phi)-(c+n*d+line['A']) for c in line['C0'] for n in range(orbit))
     closed=1-line['J']-line['A']+min((phi+line['J']-1-c)%g for c in line['C0'])
     assert comp==closed and comp<=min(cycle)[0]
     cb.append(comp);candidates+=cycle+pre;prefix+=pre
     line_bases.append(dict(line=j,prefix_base=min(pre)[0] if pre else None,cycle_base=min(cycle)[0],completion_cycle_base=comp))
    base,s,j,c,h,kind,n=min(candidates);pb=min(prefix)[0] if prefix else None
    cyclebase=min(x[0] for x in candidates if x[5]=='cycle');compbase=min(cb+([pb] if pb is not None else []))
    masks=[sum(1<<(K-1) for K in range(1,17) if b+(K-1)*P>0) for b in [base,compbase]]
    assert masks[1]&~masks[0]==0
    phase_rows.append(dict(phi=phi,service_base=base,prefix_base=pb,cycle_base=cyclebase,completion_base=compbase,witness=[j,s,c,h,kind,n],line_bases=line_bases,service_mask_K1to16=masks[0],completion_mask_K1to16=masks[1],original5_service_mask=masks[0]&31,original5_completion_mask=masks[1]&31))
    for K in range(1,17):
     slack=base+(K-1)*P;expiry=expiry_one(s,P,phi)+(K-1)*P
     start=entry+n*d if kind=='cycle' and rel['cycle_entry_empty'] else 0
     nd=(h-phi)//P-(s-phi)//P;assert (slack>0)==(K>nd)
     vals=[qi,ci,K,P,phi,j,s,c,h,s+1,start,n,slack,expiry]
     policy.write(' '.join(map(str,vals))+'\n');qi+=1
     for key,yes in [('policy_queries',True),('service_positive',slack>0),('completion_positive',compbase+(K-1)*P>0),('service_only',slack>0>=compbase+(K-1)*P),('original5_queries',K<=5),('original5_service_positive',K<=5 and slack>0),('original5_completion_positive',K<=5 and compbase+(K-1)*P>0)]:local[key]+=yes
     for route,b in [('service',slack),('completion',compbase+(K-1)*P)]:
      if b>0:
       opts[route].append((K*P-1,K,P,phi))
       if K<=5:opts['original5_'+route].append((K*P-1,K,P,phi))
   record=dict(case=ci,P=P,gcd=g,physical_cycle_entry=entry,physical_repeat=entry+math.lcm(P,d),rows=phase_rows)
   assert record==json.loads(next(expected_ph)),('all phases',ci,P)
   phases.write(json.dumps(record,separators=(',',':'))+'\n')
  optrec={}
  for route,ls in opts.items():
   value=min((e[0] for e in ls),default=None);ties=sorted([list(e[1:]) for e in ls if e[0]==value]);optrec[route]=dict(minimum_KP_minus1=value,all_ties_K_P_phi=ties,selected_K_P_phi=ties[0] if ties else None,empty=not ties)
  gain=None if optrec['service']['empty'] or optrec['completion']['empty'] else optrec['completion']['minimum_KP_minus1']-optrec['service']['minimum_KP_minus1']
  tuning=dict(case=ci,original_empty_frame_gate=rel['original_empty_frame_gate'],extension_status=rel['full_key_extension'],counts=dict(local),optima=optrec,gain_ticks=gain,no_gain=gain==0)
  assert tuning==expected_tune[ci],('optima/all ties',ci);tunings.append(tuning);totals.update(local)
 policy.close();phases.close();assert qi==130112 and next(expected_ph,None) is None
 assert sha(HERE/'INDEPENDENT_policies.txt')==sha(SOURCE/'analysis-01/policies.txt')
 dump('INDEPENDENT_RELATIONS.json',dict(records=records));dump('INDEPENDENT_TUNING.json',dict(records=tunings))
 dump('INDEPENDENT_ARITHMETIC.json',dict(status='PASS_INDEPENDENT_ALL_CASES_PREFIX_CYCLE_GRID_OPTIMA_TIES',counts=dict(totals),policy_queries=qi,semantic_streams_identical=semantic_equal,cycle_entries=[[r['case'],r['entry'],r['repeat']] for r in records],prefix_edges=sum(len(l['prefix']) for r in records for l in r['lines']),cycle_edges=sum(len(l['cycle']) for r in records for l in r['lines']),gains=[r['gain_ticks'] for r in tunings],no_gain_cases=[r['case'] for r in tunings if r['no_gain']],source_hashes=source_hashes))
 print(json.dumps(dict(queries=qi,counts=dict(totals)),indent=2))
if __name__=='__main__':main()
