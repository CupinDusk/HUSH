"""Sparse canonical scan, checked against pairwise domination and envelopes."""
from pathlib import Path
from itertools import product
import hashlib,json,random
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def canonical(g,pairs):
 assert g>0 and pairs and all(0<=r<g and v>=0 for r,v in pairs)
 merged={}
 for r,v in pairs:merged[r]=max(v,merged.get(r,0))
 rows=sorted(merged.items());w=[r+v for r,v in rows];suffix=[-1]*(len(w)+1)
 for i in range(len(w)-1,-1,-1):suffix[i]=max(w[i],suffix[i+1])
 out=[];prefix=-1
 for i,pair in enumerate(rows):
  if w[i]>prefix and w[i]+g>suffix[i+1]:out.append(pair)
  prefix=max(prefix,w[i])
 assert out;return out
def pairwise(g,rows):
 return [(r,v) for r,v in sorted(rows) if not any(q!=r and u-v>=(r-q)%g for q,u in rows)]
def H(g,rows,phi):return min((phi-r-1)%g-v for r,v in rows)
def main():
 out=HERE/'R32_SPARSE_RESULTS.json';assert not out.exists()
 assert json.loads((HERE/'R32_SPARSE_PROTOCOL.json').read_text())['status']=='prospective_before_execution'
 n=phases=0
 for g in range(1,5):
  for values in product(range(-1,2*g+2),repeat=g):
   rows=[(r,v) for r,v in enumerate(values) if v>=0]
   if not rows:continue
   got=canonical(g,rows);assert got==pairwise(g,rows)
   for phi in range(g):assert H(g,got,phi)==H(g,rows,phi);phases+=1
   n+=1
 assert n==15420
 rng=random.Random(20261022);g=2**61-1;records=[];checks=0
 for t in [1,2,3,8,32,128,512]:
  for rep in range(16):
   rows=list(zip(rng.sample(range(g),t),[rng.randrange(4*g+1) for _ in range(t)]))
   got=canonical(g,rows);assert got==pairwise(g,rows)
   for phi in {0,*((r+1)%g for r,_ in rows)}:assert H(g,got,phi)==H(g,rows,phi);checks+=1
   records.append({'t':t,'replicate':rep,'retained':len(got),'input_sha256':hashlib.sha256(json.dumps(rows).encode()).hexdigest(),'canonical_sha256':hashlib.sha256(json.dumps(got).encode()).hexdigest()})
 large=[]
 for t in [1024,4096,16384]:
  residues=sorted(rng.sample(range(g),t))
  for kind in ['all_survive','one_survives']:
   rows=[(r,10*g if i==0 and kind=='one_survives' else 0) for i,r in enumerate(residues)]
   got=canonical(g,rows);expected=rows if kind=='all_survive' else rows[:1];assert got==expected
   for phi in [0,1,g-1,residues[0],residues[-1]]:assert H(g,got,phi)==H(g,rows,phi)
   large.append({'t':t,'kind':kind,'retained':len(got),'canonical_sha256':hashlib.sha256(json.dumps(got).encode()).hexdigest()})
 result={'result':'PASS_SPARSE_CANONICAL_PREFIX_SUFFIX_SCAN','protocol_sha256':sha(HERE/'R32_SPARSE_PROTOCOL.json'),'argument_sha256':sha(HERE/'R32_SPARSE_ARGUMENT.md'),'script_sha256':sha(Path(__file__)),'exhaustive_small_profiles':n,'exhaustive_small_phase_checks':phases,'large_modulus':g,'sparse_pairwise_cases':len(records),'sparse_reset_boundary_checks':checks,'sparse_cases':records,'large_analytic_families':large,'phase_domain_enumerated_for_large_modulus':False,'arithmetic_complexity':'O(t log t) sorting, O(t) scans/storage; arbitrary precision bit cost separate','measured_runtime_or_byte_benefit':False}
 out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps({k:v for k,v in result.items() if k!='sparse_cases'},indent=2))
if __name__=='__main__':main()
