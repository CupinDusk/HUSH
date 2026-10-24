"""Directed residency obligation: fill an expiry hole before evicting valid data."""
from pathlib import Path
import json,hashlib
V=Path(__file__).resolve().parent
rows=[]
for ways in [2,3,4]:
 for keep in range(ways):
  # Fill the set, then capture the line whose safe hit will be predicted.
  refs=list(range(ways))+[keep];shadow=[];concrete=[]
  for block in refs:
   for stack in [shadow,concrete]:
    if block in stack:stack.remove(block)
    stack.insert(0,block);del stack[ways:]
  victim=next(x for x in reversed(concrete) if x!=keep)
  concrete.remove(victim) # expiry leaves an invalid physical way
  before=concrete.copy();new=ways
  assert len(concrete)<ways
  # Correct allocation uses the vacant way; only a full set evicts LRU.
  if len(concrete)==ways:concrete.pop()
  concrete.insert(0,new)
  shadow.insert(0,new);del shadow[ways:]
  predicted=keep in shadow
  assert predicted and keep in concrete
  # Deliberately discard a valid line despite the expiry hole. For 2 ways
  # this breaks the predicted hit, making the premise experimentally visible.
  mutated=before.copy();mutated.pop();mutated.insert(0,new)
  rows.append({'ways':ways,'kept_line':keep,'expired_line':victim,'before_fill_valid_mru':before,'after_fill_valid_mru':concrete,'shadow_mru':shadow,'kept_line_hit_predicted':predicted,'correct_fill_preserves_hit':keep in concrete,'mutant_hit_lost':keep not in mutated})
assert len(rows)==9 and all(r['correct_fill_preserves_hit'] for r in rows)
assert sum(r['mutant_hit_lost'] for r in rows)==2
a={'cases':len(rows),'all_correct_pass':True,'invalid_way_priority_mutant_failures':2,'scope':'Directed clean-set allocation obligation, not a whole-processor timing test. Expiry removes the valid-stack entry; a short valid stack represents available invalid ways.','rows':rows}
(V/'INVALID_WAY_DIRECTED_CHECK.json').write_text(json.dumps(a,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps({k:v for k,v in a.items() if k!='rows'}))
