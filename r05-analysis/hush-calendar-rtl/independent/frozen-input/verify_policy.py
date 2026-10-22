"""Producer policy binding/arithmetic and strict all-tick timer transcript check."""
from pathlib import Path
from collections import Counter
import argparse,csv,gzip,hashlib,json,struct
from decode_trace import PAYLOAD,openbin,readvar
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--build',default='build-05-policy');ap.add_argument('--analysis',default='analysis-01');ap.add_argument('--ticks',action='store_true');a=ap.parse_args();bd=HERE/a.build;ad=HERE/a.analysis
 relations=json.loads((ad/'RELATIONS.json').read_text());rr={x['case']:x for x in relations['records']};counts=Counter();policies=[];initial=[]
 with (ad/'policies.txt').open() as inp,(bd/'POLICY_RESULTS.csv').open(newline='') as res:
  N=int(inp.readline());reader=csv.DictReader(res)
  for qi,row in enumerate(reader):
   x=list(map(int,inp.readline().split()));r={k:int(v) for k,v in row.items()};policies.append(r)
   id,ci,K,P,phi,j,s,c,h,arm,start,n,slack,expiry=x;assert id==qi==r['query'];assert x[:5]==[r[k] for k in ['query','case','K','P','phi']]
   assert [j,s,c,h,arm,start,n,slack,expiry]==[r[k] for k in ['line','s','c','h','arm','start','translationFrames','expectedSlack','expectedExpiry']]
   assert expiry==arm+((phi-arm)%P)+(K-1)*P and slack==expiry-h
   # Floor decrement count does not use the expiry formula.
   nd=(h-phi)//P-(s-phi)//P;assert (K>nd)==(slack>0)
   assert r['fault']==0 and r['ticks']==h-start+1 and r['WUs']==1 and r['startPhase']==start%P
   if slack>0:assert r['firstFail']==r['failOwner']==r['actualExpiry']==-1 and r['cancels']==1
   else:assert r['firstFail']==h and r['failOwner']==j and r['actualExpiry']==expiry and r['expiries']==1
   rel=rr[ci];cfg=rel['configuration'];entry=rel['entry'];physicalnext=1 if start==0 else rel['entry_state']['before_nextid']+8*n
   if start:assert rel['cycle_entry_empty'] and start==entry+n*cfg['F']
   initial.append([qi,ci,start,entry,n,start%cfg['p'],start%cfg['r'],start%cfg['F'],start%P,physicalnext,1,1-physicalnext,start,r['ticks']])
   counts['queries']+=1;counts['positive']+=slack>0;counts['negative']+=slack<=0;counts['executed_ticks']+=r['ticks'];counts['omitted_physical_prehistory_ticks_NOT_executed']+=start
   for k in ['captures','emissions','cancels','expiries','WUs']:counts[k]+=r[k]
  assert qi+1==N==130112 and inp.read()==''
 with (ad/'POLICY_INITIALIZATION.csv').open('w',newline='') as f:
  w=csv.writer(f);w.writerow(['query','case','start','entry','translationFrames','cachePhase','readyPhase','calendarPhase','physicalPPhase','physicalNextIdAtEntry','resetNextId','IDTranslation','omittedPrehistoryTicksNOTExecuted','actualExecutedTicks']);w.writerows(initial)
 tickcounts=Counter()
 if a.ticks:
  path=bd/'POLICY_TICKS.delta';path=path if path.exists() else path.with_suffix('.delta.gz')
  # Each tick is decoded and checked, with a zero-baseline at each query.
  with openbin(path) as f:
   assert f.read(8)==b'HCR5DT01'
   for qi,p in enumerate(policies):
    q,n=struct.unpack('<II',f.read(8));assert q==qi and n==p['ticks'];prev=[0]*len(PAYLOAD);j=p['line'];P=p['P'];phi=p['phi'];K=p['K'];arm=p['arm'];h=p['h'];E=p['expectedExpiry'];start=p['start'];mask=1<<j
    for z in range(n):
     nb=f.read(1);assert nb;nc=nb[0];assert nc<=len(prev);last=-1
     for _ in range(nc):
      b=f.read(1);assert b;k=b[0];assert last<k<len(prev);last=k;v=readvar(f);assert v!=prev[k];prev[k]=v
     t=start+z
     if t<arm:valid=15;enabled=0;targetcount=0
     elif t>=E:valid=15^mask;enabled=0;targetcount=0
     elif t==h:valid=15;enabled=0;targetcount=0
     else:valid=15;enabled=mask;targetcount=K-((t-phi)//P-((arm-1-phi)//P))
     assert prev[20]==valid and prev[21]==enabled and prev[22]==0 and prev[23+j]==targetcount
     assert all(prev[23+k]==0 for k in range(4) if k!=j)
     assert prev[27]==int(t==h and E<=h) and prev[28]==0
     assert prev[29]==(mask if t==arm else 0) and prev[30]==(mask if t==E and E<=h else 0) and prev[31]==(mask if t==h and E>h else 0)
     if valid!=15:
      held=(prev[11] and prev[12]==j) or (prev[15] and prev[16]==j)
      tickcounts['snapshot_held_after_tag_expiry_ticks']+=bool(held)
      tickcounts['backpressure_with_expired_tag_snapshot_ticks']+=bool(held and prev[55])
     tickcounts['strictly_decoded_timer_checked_ticks']+=1
   assert f.read(1)==b''
  assert tickcounts['strictly_decoded_timer_checked_ticks']==counts['executed_ticks']
 result={'status':'PASS_PRODUCER_POLICY_BINDINGS_AND_ARITHMETIC'+('_ALL_TICK_TIMER_TRANSCRIPT' if a.ticks else ''),'counts':dict(counts),'tick_counts':dict(tickcounts),'input_hashes':{'policies':sha(ad/'policies.txt'),'results':sha(bd/'POLICY_RESULTS.csv')},'scope':'Same producer; no independent gate claim; finite one-WU words only.'}
 (bd/'PRODUCER_POLICY_CHECK.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps(result,indent=2))
if __name__=='__main__':main()
