"""Check the derived cyclic-reuse sufficient condition against the analyzer.
This is a finite regression check, not an independent proof of the analyzer.
"""
from pathlib import Path
from itertools import product
import interlocked_model as c
import json,hashlib
def load(threshold,p):
 k=threshold//p+2
 return k if k<=254 else 255
count=0;finite=0
for n,g,lm,sw,p in product([1,2,4,8,16,32],[0,1,4,16,32],[1,31,71,121],[1,4,16,64],[1,2,10,32]):
 c.P.update(shared_blocks=n,period=p,analytic_unknown_read_bound_cycles=lm,switch_cycles=sw)
 kb=load(n*(g+lm)+sw,p)
 ks=load(n*(g+1)+max(0,sw-1),p)
 ops=[('phase',0)]
 for _ in range(n):ops.extend([('compute',g),('read',_%n)])
 ops.append(('phase',1))
 for j in range(4*n):ops.extend([('compute',g),('read',j%n)])
 a=c.analyze(ops,(kb,ks,ks))
 steady=[v for ip,v in a['predictions'].items() if ip>2*n]
 assert len(steady)==4*n and all(steady),(n,g,lm,sw,p,kb,ks,a)
 count+=1;finite+=int(kb!=255 and ks!=255)
result={'cases':count,'finite_load_pairs':finite,'failures':0,
 'statement':'Rboot > n(g+Lm)+Lsw and Rsteady > n(g+Lh)+max(0,Lsw-Lh), for Lh=1 and Lm>=Lh; all later cyclic reads are guaranteed hits',
 'source_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
 'model_sha256':hashlib.sha256((Path(__file__).parent/'interlocked_model.py').read_bytes()).hexdigest()}
(Path(__file__).parent/'INTERLOCKED_BOOTSTRAP_INVARIANT_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
