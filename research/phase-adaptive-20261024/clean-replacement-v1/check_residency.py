"""Independent finite-state check of the local reuse-distance certificate.

Four-address universe, all reachable states to closure; expiry may delete
any concrete line between sequential local captures. Timed safety is a
separate proof/check. Mutants deliberately violate the allocation policy.
"""
from collections import deque
from pathlib import Path
from itertools import product
import hashlib,json,time
V=Path(__file__).resolve().parent

def check(sets,ways,mutation=None):
 n=4;empty=tuple(() for _ in range(sets));initial=(empty,empty,0)
 queue=deque([initial]);parent={initial:None};edges=0
 def trace(state,last):
  out=[last]
  while parent[state] is not None:
   state0,event=parent[state];out.append(event);state=state0
  return list(reversed(out))
 while queue:
  state=queue.popleft();shadow,actual,alive=state
  for kind,b in product(['read','expire','wu'],range(n)):
   s=b%sets
   if kind=='read' and b in shadow[s] and alive&(1<<b) and b not in actual[s]:
    return {'passed':False,'states':len(parent),'edges':edges,'counterexample':trace(state,['read',b])}
   sr=[list(x) for x in shadow];ac=[list(x) for x in actual];a=alive
   def local(stack):
    if b in stack:stack.remove(b)
    stack.insert(0,b);del stack[ways:]
   if kind=='read':local(sr[s]);local(ac[s]);a|=1<<b
   elif kind=='expire':
    if b in ac[s]:ac[s].remove(b)
    if mutation!='ignore_expiry':a&=~(1<<b)
   elif mutation=='wu_allocate':local(ac[s])
   elif mutation=='wu_touch' and b in ac[s]:local(ac[s])
   nxt=(tuple(map(tuple,sr)),tuple(map(tuple,ac)),a);edges+=1
   if nxt not in parent:
    parent[nxt]=(state,[kind,b]);queue.append(nxt)
 return {'passed':True,'states':len(parent),'edges':edges}

start=time.perf_counter();rows=[]
for sets,ways in [(1,1),(1,2),(1,3),(2,1),(2,2),(4,1)]:
 r=check(sets,ways);assert r['passed'];rows.append({'sets':sets,'ways':ways,**r})
mutants=[]
for mutation in ['wu_allocate','wu_touch','ignore_expiry']:
 r=check(1,2,mutation);assert not r['passed'],mutation
 mutants.append({'mutation':mutation,**r})
result={'scope':'Complete reachable-state closure for four addresses, six geometries; residency lemma only, expiry/capture timing checked separately.',
 'source_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
 'geometries':rows,'total_states':sum(r['states'] for r in rows),
 'total_edges':sum(r['edges'] for r in rows),'mutants':mutants,'elapsed_seconds':time.perf_counter()-start}
(V/'RESIDENCY_CHECK.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
