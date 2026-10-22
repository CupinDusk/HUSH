"""Exact predecessor validation and byte-bound inputs for the local benchmark."""
from pathlib import Path
from collections import Counter
from itertools import product
from bisect import bisect_right
import hashlib,json,math,random,sys
HERE=Path(__file__).resolve().parent;PACKAGE=HERE.parents[1]
OLD=PACKAGE/'expected';sys.path.insert(0,str(PACKAGE/'analysis'))
from sparse_canonical_check import canonical as sparse
from r26_remod import profile
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def objsha(v):return hashlib.sha256(json.dumps(v).encode()).hexdigest()
def H(rows,g,z):return min((z-r-1)%g-v for r,v in rows)
def resets(rows,g):return sorted(((r+1)%g,-v) for r,v in rows)
def lookup(R,g,z):
 z%=g;i=bisect_right([a for a,h in R],z)-1;a,h=R[i]
 return h+(z-a)%g
def main():
 out=HERE/'VALIDATION_RESULTS.json';inp=HERE/'PROFILES.txt';assert not out.exists() and not inp.exists()
 small=checks=0
 for g in range(1,5):
  for ages in product(range(-1,2*g+2),repeat=g):
   raw=[(r,v) for r,v in enumerate(ages) if v>=0]
   if not raw:continue
   Q=sparse(g,raw);R=resets(Q,g)
   for z in range(g):assert H(raw,g,z)==lookup(R,g,z);checks+=1
   small+=1
 assert small==15420
 records=json.loads((OLD/'R30_PRODUCER_FAMILY_RESULTS.json').read_text())['records']
 cases=[];phasechecks=0;portfolios={k:Counter() for k in ['all_1_to4p','single2p','pair2p3p']};worked=None
 for rec in records:
  if not rec['admitted']:continue
  T=[tuple(t) for t in rec['cycle']];events=[(s,h-s) for s,c,h in T];d=rec['translation'];p=rec['p'];cache={}
  for P in range(1,4*p+1):
   m=math.gcd(P,d)
   if m not in cache:
    raw=profile(events,m);Q=sparse(m,raw);R=resets(Q,m);cache[m]=(raw,Q,R)
   raw,Q,R=cache[m]
   for z in range(P):
    direct=min((z-s-1)%m-(h-s) for s,c,h in T)
    assert direct==H(raw,m,z)==lookup(R,m,z);phasechecks+=1
  for m,(raw,Q,R) in sorted(cache.items()):cases.append(dict(id=f"family_{rec['case_id']}_m{m}",corpus='family',m=m,grouped=raw,canonical=Q))
  master=sparse(d,profile(events,d))
  for label,ps in [('all_1_to4p',range(1,4*p+1)),('single2p',[2*p]),('pair2p3p',[2*p,3*p])]:
   ms={math.gcd(P,d) for P in ps};g=math.lcm(*ms);assert d%g==0
   Q=sparse(g,profile(events,g));valid=[h for h in range(1,d+1) if d%h==0 and all(h%m==0 for m in ms)]
   assert min(valid)==g and all(h%g==0 for h in valid)
   assert all(len(Q)<=len(sparse(h,profile(events,h))) for h in valid)
   c=portfolios[label];c['entries']+=1;c['forced_full_modulus']+=g==d;c['smaller_modulus']+=g<d
   c['master_terms']+=len(master);c['selected_terms']+=len(Q);c['term_reduced_entries']+=len(Q)<len(master)
  if (p,rec['q'],rec['s0'])==(9,16,5):
   J=max(c-s for s,c,h in T);A=max(h-c for s,c,h in T);C={c for s,c,h in T};queries=[]
   for K,P,z in [(2,27,2),(3,18,2)]:
    m=math.gcd(P,d);Q=sparse(m,profile(events,m));D=(K-1)*P+1-J-A+min((z+J-1-c)%m for c in C)
    queries.append(dict(K=K,P=P,phi=z,m=m,profile=Q,slack=(K-1)*P+1+lookup(resets(Q,m),m,z),completion_D=D))
   worked=dict(triples=T,d=d,master=master,stored_g27=sparse(27,profile(events,27)),queries=queries,J=J,A=A,
    actual_completion_phases27=sorted(c%27 for c in C),joint_witness_phases27=sorted({c%27 for s,c,h in T if c-s==J and h-c==A}))
 assert len(cases)==10454 and worked is not None
 old=json.loads((OLD/'R32_SPARSE_RESULTS.json').read_text());rng=random.Random(20261022);g=2**61-1;widechecks=0;i=0;prng=random.Random(20261023)
 for t in [1,2,3,8,32,128,512]:
  for rep in range(16):
   raw=list(zip(rng.sample(range(g),t),[rng.randrange(4*g+1) for _ in range(t)]));Q=sparse(g,raw);R=resets(Q,g)
   assert objsha(raw)==old['sparse_cases'][i]['input_sha256'] and objsha(Q)==old['sparse_cases'][i]['canonical_sha256'];i+=1
   phases={0,*[(a+offset)%g for a,h in R for offset in [-1,0,1]],*[prng.randrange(g) for _ in range(256)]}
   for z in phases:assert H(raw,g,z)==lookup(R,g,z);widechecks+=1
   cases.append(dict(id=f'random_{t}_{rep}',corpus=f'random_t{t}',m=g,grouped=sorted(raw),canonical=Q))
 j=0
 for t in [1024,4096,16384]:
  residues=sorted(rng.sample(range(g),t))
  for kind in ['all_survive','one_survives']:
   raw=[(r,10*g if k==0 and kind=='one_survives' else 0) for k,r in enumerate(residues)];Q=sparse(g,raw);R=resets(Q,g)
   assert objsha(Q)==old['large_analytic_families'][j]['canonical_sha256'];j+=1
   phases={0,1,g-1,*[(r+offset)%g for r in residues[:16]+residues[-16:] for offset in [-1,0,1]],*[prng.randrange(g) for _ in range(256)]}
   for z in phases:assert H(raw,g,z)==lookup(R,g,z);widechecks+=1
   cases.append(dict(id=f'analytic_{t}_{kind}',corpus=f'analytic_t{t}_{kind}',m=g,grouped=raw,canonical=Q))
 with inp.open('w',encoding='ascii',newline='\n') as f:
  f.write(str(len(cases))+'\n')
  for c in cases:
   f.write(f"{c['id']} {c['corpus']} {c['m']} {len(c['grouped'])} {len(c['canonical'])}\n")
   for r,v in list(c['grouped'])+list(c['canonical']):f.write(f'{r} {v}\n')
 result=dict(result='PASS_EXACT_PREDECESSOR_LOOKUP_ALL_DECLARED_DOMAINS',protocol_sha256=sha(HERE/'PROTOCOL.json'),
  script_sha256=sha(Path(__file__)),input_sha256=sha(inp),small_profiles=small,small_phase_checks=checks,
  source_family_target_profiles=10454,source_family_physical_phase_checks=phasechecks,wide_profiles=118,wide_checks=widechecks,
  portfolios={k:dict(v) for k,v in portfolios.items()},worked_unequal_span=worked,
  corpora=dict(Counter(c['corpus'] for c in cases)),scope='Exact mathematical checks only; native benchmark has not yet executed. No timing/byte/application claim from this validation.')
 out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps(result,indent=2))
if __name__=='__main__':main()
