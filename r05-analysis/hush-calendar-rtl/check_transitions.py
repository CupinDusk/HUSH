"""Producer check using a separate list/token representation; not independent gate."""
from pathlib import Path
from collections import Counter
import argparse,csv,gzip,json
HERE=Path(__file__).resolve().parent
def reads(p):
 op=gzip.open if str(p).endswith('.gz') else open
 with op(p,'rt',encoding='utf-8',newline='') as f:
  for r in csv.DictReader(f):yield {k:int(v) for k,v in r.items()}
def check(row):
 b={k[7:]:v for k,v in row.items() if k.startswith('before_')};after={k[6:]:v for k,v in row.items() if k.startswith('after_')};t=row['t'];assert b['tick']==t
 p,r,F,K,P,phi=[row[k] for k in ['p','r','F','K','P','phi']]
 assert [b[x] for x in ['cp','rp','fp','pp']]==[t%p,t%r,t%F,t%P]
 tags=[(bool(b['valid']&(1<<j)),bool(b['enabled']&(1<<j)),b['count'+str(j)],(b['bytes']>>(8*j))&255) for j in range(4)]
 evwu=exp=cancel=0;mut=[]
 for j,(v,en,n,word) in enumerate(tags):
  if row['WUinput']&(1<<j) and v:en=True;n=K;word=(row['WUbytes']>>(8*j))&255;evwu|=1<<j
  if en and t%P==phi:
   assert n>0;n-=1
   if n==0:v=False;en=False;exp|=1<<j
  mut.append([v,en,n,word])
 assert row['evwu']==evwu and row['evexpire']==exp
 q=[((b['qowners']>>(2*i))&3,b['qid'+str(i)]) for i in range(b['qlen'])];enqs=[];nextid=b['nextid']
 for offset,j in zip([0,1,2,3,40,41,42,43],[0,1,2,3,0,1,2,3]):
  if t%F==offset%F:enqs.append((j,nextid));q.append((j,nextid));nextid+=1
 assert row['evenq']==len(enqs)
 if enqs:assert (row['enqowner'],row['enqid'])==enqs[0]
 if len(enqs)==2:assert (row['enqowner2'],row['enqid2'])==enqs[1]
 R0=None if not b['R0v'] else (b['R0owner'],b['R0id'],b['R0byte']);R1=None if not b['R1v'] else (b['R1owner'],b['R1id'],b['R1byte'])
 attempt=grant=emit=transfer=callback=block=None;failed=False
 if t%p==0 and R0 is None and q:
  j,id=q[0];attempt=(j,id)
  if not mut[j][0]:failed=True
  else:
   q.pop(0);grant=(j,id,mut[j][3]);R0=grant;cancel|=mut[j][1]<<j;mut[j][1]=False;mut[j][2]=0
 if not failed:
  if R1 is not None:
   if t%r in [1,2]:emit=R1;callback=R1[:2];R1=None
   else:block=R1[:2]
  if R0 is not None and R1 is None:transfer=R0;R1=R0;R0=None
 for name,value in [('attempt',attempt),('grant',grant),('emit',emit),('transfer',transfer),('callback',callback),('block',block)]:
  assert bool(row['ev'+name])==(value is not None),(t,name)
  if value is not None:
   assert (row[name+'owner'],row[name+'id'])==value[:2]
   if len(value)==3:assert row[name+'byte']==value[2]
 assert row['evcancel']==cancel
 if failed:assert row['failtick']==t and (row['failowner'],row['failid'])==attempt
 assert after['failed']==failed and after['fault']==0
 assert after['nextid']==nextid and after['qlen']==len(q)<=8
 assert [((after['qowners']>>(2*i))&3,after['qid'+str(i)]) for i in range(after['qlen'])]==q
 for nm,tok in [('R0',R0),('R1',R1)]:
  assert bool(after[nm+'v'])==(tok is not None)
  if tok is not None:assert (after[nm+'owner'],after[nm+'id'],after[nm+'byte'])==tok
 for j,(v,en,n,word) in enumerate(mut):
  assert bool(after['valid']&(1<<j))==v and bool(after['enabled']&(1<<j))==en and after['count'+str(j)]==n and (after['bytes']>>(8*j))&255==word
 expected=[sum(x[0]==j for x in q)+int(R0 is not None and R0[0]==j)+int(R1 is not None and R1[0]==j) for j in range(4)]
 assert all((after['outstanding']>>(4*j))&15==expected[j] for j in range(4))
 assert [after[x] for x in ['tick','cp','rp','fp','pp']]==[t+1,(t+1)%p,(t+1)%r,(t+1)%F,(t+1)%P]
 return Counter(ticks=1,enqueues=len(enqs),captures=grant is not None,emissions=emit is not None,backpressure=block is not None,transfers=transfer is not None,WUs=evwu.bit_count(),cancels=cancel.bit_count(),expiries=exp.bit_count())
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--build',default='build-04');a=ap.parse_args();build=HERE/a.build;counts={}
 for name in ['CONTROL_TICKS.csv','DATA_TICKS.csv']:
  total=Counter();last={}
  for r in reads(build/name if (build/name).exists() else build/(name+'.gz')):
   group=(r['case'],r['mode']);pre={k[7:]:v for k,v in r.items() if k.startswith('before_')}
   if group in last:assert pre==last[group]
   else:assert r['t']==0 and pre['valid']==15 and pre['enabled']==pre['qlen']==pre['R0v']==pre['R1v']==0
   total.update(check(r));last[group]={k[6:]:v for k,v in r.items() if k.startswith('after_')}
  counts[name]=dict(total)
 (build/'PRODUCER_TRANSITION_CHECK.json').write_text(json.dumps({'status':'PASS_PRODUCER_SEPARATE_REPRESENTATION','counts':counts,'independent_validation':False},indent=2)+'\n',encoding='utf-8');print(json.dumps(counts,indent=2))
if __name__=='__main__':main()
