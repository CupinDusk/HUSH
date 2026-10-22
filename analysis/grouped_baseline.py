from pathlib import Path
from collections import Counter
import hashlib,json,math,sys
HERE=Path(__file__).resolve().parent
OLD=HERE;EXPECTED=HERE.parent/'expected';sys.path.insert(0,str(OLD))
from r23_canonical import canonical
from r26_remod import profile
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 out=HERE/'GROUPED_BASELINE_RESULTS.json';assert not out.exists()
 p=EXPECTED/'R30_PRODUCER_FAMILY_RESULTS.json';total=Counter();byraw={};rows=[]
 for r in json.loads(p.read_text(encoding='utf-8'))['records']:
  if not r['admitted']:continue
  T=r['cycle'];d=r['translation'];c=Counter();cache={}
  for P in range(1,4*r['p']+1):
   m=math.gcd(P,d)
   if m not in cache:
    raw=profile([(s,h-s) for s,cc,h in T],m);Q=canonical(raw,m);cache[m]=(raw,Q)
   raw,Q=cache[m]
   for phi in range(P):assert min((phi-x-1)%m-v for x,v in raw)==min((phi-x-1)%m-v for x,v in Q)
   c['queries']+=5*P;c['direct_terms']+=len(T)*5*P;c['grouped_terms']+=len(raw)*5*P;c['canonical_terms']+=len(Q)*5*P
  c['entries']=1;total.update(c);byraw.setdefault(len(T),Counter()).update(c)
  rows.append(dict(case_id=r['case_id'],**dict(c)))
 cost=json.loads((EXPECTED/'QUERY_COST_RESULTS.json').read_text())['summary']['total']
 assert total['direct_terms']==cost['direct_query_terms'] and total['canonical_terms']==cost['profile_query_terms']
 result=dict(result='PASS_GROUPED_AND_CANONICAL_ALL_TARGET_PHASES',protocol_sha256=sha(HERE/'GROUPED_BASELINE_PROTOCOL.json'),
  script_sha256=sha(Path(__file__)),input_sha256=sha(p),total=dict(total),
  entries_canonical_fewer_than_grouped=sum(r['canonical_terms']<r['grouped_terms'] for r in rows),
  entries_canonical_equal_grouped=sum(r['canonical_terms']==r['grouped_terms'] for r in rows),
  by_raw_terms=[dict(raw_terms=k,**dict(v)) for k,v in sorted(byraw.items())],records=rows)
 out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps({k:v for k,v in result.items() if k not in ['records','by_raw_terms']},indent=2))
if __name__=='__main__':main()
