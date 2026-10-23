"""Separately formulated producer cross-check. Not an external independent audit.

Science checks below do not import producer arithmetic or canonicalization.
The producer API is loaded only by the explicit adversarial parser tests.
"""
from pathlib import Path
from collections import Counter
import argparse,gzip,hashlib,json,math,struct,traceback
HERE=Path(__file__).resolve().parent
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save(p,x):p.write_text(json.dumps(x,indent=2)+'\n',encoding='utf8')
def independent_parse(data,reg):
 pos=0
 def field(fmt):
  nonlocal pos
  n=struct.calcsize(fmt)
  if pos+n>len(data):raise ValueError('short')
  vals=struct.unpack_from(fmt,data,pos);pos+=n;return vals
 if data[:8]!=b'HUCALR06':raise ValueError('magic')
 pos=8;schema,proof,kind,n=field('<4I')
 if schema!=1 or proof!=1 or kind not in range(6):raise ValueError('schema')
 raw=data[pos:pos+n];pos+=n;meta=json.loads(raw)
 if meta!=reg['metadata'] or raw!=json.dumps(meta,sort_keys=True,separators=(',',':'),ensure_ascii=False).encode():raise ValueError('registry metadata')
 if field('<I')!=(4,):raise ValueError('lines')
 lines=[]
 for j in range(4):
  owner,g,count=field('<3I');eg,expect=reg['forms'][str(kind)][j]
  if owner!=j or g!=eg or count!=len(expect):raise ValueError('line header')
  rows=[list(field('<3I')) if kind==4 else field('<i')[0] if kind==5 else list(field('<2I')) for _ in range(count)]
  if rows!=expect:raise ValueError('data')
  lines.append((g,rows))
 if pos!=len(data):raise ValueError('trailing')
 return meta,kind,lines
def first_decrement(s,P,phi):return phi+((s+1-phi+P-1)//P)*P
def direct_cycle(line,d,P,phi):
 return min(first_decrement(s+n*d,P,phi)-(h+n*d) for s,c,h in line['cycle'] for n in range(P//math.gcd(P,d)))
def direct_prefix(line,P,phi):return [first_decrement(s,P,phi)-h for s,c,h in line['prefix']]
def count_for_lifted_interval(s,h,P,phi,d):
 # Each complete P-block contributes floor(span/P) decrements. Remaining
 # interval is hit iff the start-residue orbit reaches the remainder range.
 q,rem=divmod(h-s,P);m=math.gcd(P,d)
 return q+int((phi-s-1)%m<rem)
def independent_min_K(case,P,phi):
 d=case['period'];service=[];comp=[]
 for l in case['lines']:
  service.extend(count_for_lifted_interval(s,h,P,phi,d) for s,c,h in l['cycle'])
  comp.extend(count_for_lifted_interval(c-l['J'],c+l['A'],P,phi,d) for c in l['C0'])
  pre=[(h-phi)//P-(s-phi)//P for s,c,h in l['prefix']]
  service+=pre;comp+=pre
 return max(service)+1,max(comp)+1
def independent_bases(case,P,phi):
 d=case['period'];m=math.gcd(P,d);service=[];comp=[]
 for l in case['lines']:
  service.extend(first_decrement(s,m,phi%m)-h for s,c,h in l['cycle'])
  comp.extend(first_decrement(c-l['J'],m,phi%m)-(c+l['A']) for c in l['C0'])
  pre=direct_prefix(l,P,phi);service+=pre;comp+=pre
 return min(service),min(comp)
def opt(rows):
 obj=min(x[0] for x in rows);return obj,sorted(x[1:] for x in rows if x[0]==obj)
def run():
 binding=json.loads((OUT/'PRE_EXECUTION_BINDING.json').read_text())
 for n,h in binding['sources'].items():
  if digest(HERE/n)!=h or digest(OUT/'source'/n)!=h:raise RuntimeError('source drift')
 cases=json.loads((HERE/'frozen-input/analysis-01/RELATIONS.json').read_text())['records'];regs=json.loads((OUT/'TRUSTED_EXPECTED_REGISTRY.json').read_text())['records'];opts=json.loads((OUT/'OPTIMA_ALL_TIES.json').read_text())['records']
 counters=Counter();semantic=hashlib.sha256();b_candidates={ci:{o:[] for o in ['service','completion']} for ci in range(12)};g_candidates={ci:{o:[] for o in ['service','completion']} for ci in range(12)}
 for case,reg in zip(cases,regs):
  ci=case['case'];d=case['period'];decoded=[]
  for p in sorted((OUT/'records').glob(f'case-{ci:02d}.*.bin')):decoded.append(independent_parse(p.read_bytes(),reg));counters['independently_parsed_records']+=1
  for P in reg['metadata']['portfolio_P']:
   m=math.gcd(P,d)
   for phi in range(P):
    direct=[]
    for j,l in enumerate(case['lines']):
     cyc=direct_cycle(l,d,P,phi);pre=direct_prefix(l,P,phi);lb=min([cyc]+pre);direct.append(lb)
     # Each line/format is compared independently, so a global min cannot
     # conceal a wrong non-minimizing line profile.
     for meta,kind,lines in decoded:
      g,items=lines[j]
      if kind==4:cb=min(first_decrement(s+n*d,P,phi)-(h+n*d) for s,c,h in items for n in range(P//m))
      elif kind==5:cb=1+min(items[x] for x in range(phi%m,g,m))
      else:cb=1+min((phi-r-1)%m-span for r,span in items)
      if cb!=cyc or min([cb]+direct_prefix(l,P,phi))!=lb:raise RuntimeError(('line query',ci,j,P,phi,kind))
      counters['independent_line_format_phase_checks']+=1
    base=min(direct);comp=independent_bases(case,P,phi)[1]
    for K in range(1,17):
     slack=(K-1)*P+base
     # Every actual lifted interval is tested by counting decrements too.
     required=max([max((h+n*d-phi)//P-(s+n*d-phi)//P for s,c,h in l['cycle'] for n in range(P//m)) for l in case['lines']]+[(h-phi)//P-(s-phi)//P for l in case['lines'] for s,c,h in l['prefix']])+1
     if (slack>0)!=(K>=required):raise RuntimeError('strict decrement control')
     semantic.update(json.dumps([ci,K,P,phi,slack,(K-1)*P+comp],sort_keys=True,separators=(',',':')).encode());counters['joint_portfolio_queries']+=1
  # Old-grid checks use all actual physical translations (no producer gcd
  # arithmetic). Compare the original immutable optimum records and counts.
  oldrows={o:[] for o in ['service','completion','original5_service','original5_completion']};oldcounts=Counter()
  for P in range(1,4*case['configuration']['p']+1):
   m=math.gcd(P,d)
   for phi in range(P):
    sb=min([direct_cycle(l,d,P,phi) for l in case['lines']]+[v for l in case['lines'] for v in direct_prefix(l,P,phi)])
    cb=min([min(first_decrement(c-l['J']+n*d,P,phi)-(c+l['A']+n*d) for c in l['C0'] for n in range(P//m)) for l in case['lines']]+[v for l in case['lines'] for v in direct_prefix(l,P,phi)])
    for K in range(1,17):
     for o,b in [('service',sb),('completion',cb)]:
      if (K-1)*P+b>0:
       oldrows[o].append([K*P-1,K,P,phi])
       if K<=5:oldrows['original5_'+o].append([K*P-1,K,P,phi])
     counters['independent_old_grid_policies']+=1
  for o,rows in oldrows.items():
   wanted=opts[ci]['old_grid'][o]
   if rows:
    objective,ties=opt(rows)
    if [objective,ties]!=[wanted['minimum_KP_minus1'],wanted['all_ties_K_P_phi']]:raise RuntimeError(('old ties',ci,o))
   elif not wanted['empty']:raise RuntimeError('lost empty old domain')
  for l in case['lines']:
   # Reconstruct canonical inverses directly from dense strict resets.
   for kind in [2,3]:
    g,pairs=reg['forms'][str(kind)][l['line']];raw=l['cycle']
    vals=[min((q-s-1)%g-(h-s) for s,c,h in raw) for q in range(g)]
    resets=sorted([[(q-1)%g,-vals[q]] for q in range(g) if vals[q]<vals[q-1]+1])
    if resets!=pairs:raise RuntimeError(('reset inverse',ci,l['line'],kind))
    counters['independent_reset_inverses']+=1
  print('separate-formulation checks case',ci,flush=True)
 # Every phase in the witness-bounded expanded search is rechecked with an
 # independent decrement-count expression and ceiling-event expression.
 with gzip.open(OUT/'SEARCH_PHASES.jsonl.gz','rt',encoding='utf8') as f:
  for line in f:
   ci,P,phi,sb,cb,ks,kc=json.loads(line);case=cases[ci];ik=independent_min_K(case,P,phi);ib=independent_bases(case,P,phi)
   if ik!=(ks,kc) or ib!=(sb,cb):raise RuntimeError(('expanded phase',ci,P,phi,ik,ks,kc,ib,sb,cb))
   for o,K in zip(['service','completion'],ik):
    bound=opts[ci]['old_grid'][o]['minimum_KP_minus1']+1
    if K<=16 and K*P<=bound:
     b_candidates[ci][o].append([K*P-1,K,P,phi])
     if P<=68:g_candidates[ci][o].append([K*P-1,K,P,phi])
   counters['independent_expanded_search_phase_queries']+=1
 for ci in range(12):
  for o in ['service','completion']:
   for rows,domain in [(b_candidates[ci][o],'fixed_K16_arbitrary_P'),(g_candidates[ci][o],'fixed_K16_source_P68')]:
    objective,ties=opt(rows);want=opts[ci][domain][o]
    if objective!=want['minimum_KP_minus1'] or ties!=want['all_ties_K_P_phi']:raise RuntimeError('expanded ties')
   # Prove the no-cap minimum with raw spans/tight J+A and literal prefix,
   # then enumerate every exact-product factor/phase allowed by source.
   case=cases[ci];pre=[h-s for l in case['lines'] for s,c,h in l['prefix']]
   lb=max([h-s for l in case['lines'] for s,c,h in l['cycle']]+pre) if o=='service' else max([l['J']+l['A'] for l in case['lines']]+pre)
   rows=[]
   for P in range(1,min(68,lb+1)+1):
    if (lb+1)%P:continue
    K=(lb+1)//P
    if K>65535:continue
    for phi in range(P):
     if K>=independent_min_K(case,P,phi)[0 if o=='service' else 1]:rows.append([lb,K,P,phi])
   _,ties=opt(rows);want=opts[ci]['uncapped_K_source_guards'][o]
   if lb!=want['minimum_KP_minus1'] or ties!=want['all_ties_K_P_phi']:raise RuntimeError('P1/ties/source guard')
 # General Kmin off-by-one census, without producer helper.
 import calendar_records as api
 for P in range(1,20):
  for base in range(-80,81):
   expected=next(K for K in range(1,200) if (K-1)*P+base>0)
   if api.min_K(base,P)!=expected:raise RuntimeError('Kmin off-by-one')
   counters['small_Kmin_cases']+=1
 # Targeted actual decoder probes fixed in the protocol.
 mutant_report=[]
 def rejected(label,data,expected):
  try:api.decode(data,expected)
  except (ValueError,struct.error,UnicodeDecodeError,json.JSONDecodeError):mutant_report.append({'control':label,'rejected':True});return
  raise RuntimeError('accepted mutant '+label)
 for ci,reg in enumerate(regs):
  expected={'metadata':reg['metadata'],'forms':{int(k):[(g,[tuple(v) if isinstance(v,list) else v for v in items]) for g,items in rows] for k,rows in reg['forms'].items()}}
  data=(OUT/'records'/f'case-{ci:02d}.portfolio.bin').read_bytes();nmeta=struct.unpack_from('<I',data,20)[0];linepos=24+nmeta+4
  for label,offset,fmt,new in [('magic',0,'<Q',0),('schema',8,'<I',2),('proof',12,'<I',2),('format',16,'<I',9),('metadata_length',20,'<I',2**32-1),('line_count',24+nmeta,'<I',3),('lineID',linepos,'<I',3),('modulus',linepos+4,'<I',0),('count',linepos+8,'<I',2**32-1),('span',linepos+16,'<I',0)]:
   b=bytearray(data);struct.pack_into(fmt,b,offset,new);rejected(f'{ci}:{label}',bytes(b),expected)
  rejected(f'{ci}:truncated',data[:-1],expected);rejected(f'{ci}:trailing',data+b'\0',expected)
  for field in ['source','receiver','relation','epoch']:
   forged=json.loads(json.dumps(expected));forged['forms']=expected['forms'];forged['metadata']['bindings'][field]='0'*64
   b=api.encode(forged,3);rejected(f'{ci}:binding_{field}',b,expected)
  for field in ['entry','repeat','ID_translation']:
   forged=json.loads(json.dumps(expected));forged['forms']=expected['forms'];forged['metadata'][field]+=1
   rejected(f'{ci}:metadata_{field}',api.encode(forged,3),expected)
  forged=json.loads(json.dumps(expected));forged['forms']=expected['forms'];forged['metadata']['lines'][0]['initial_capture_cutpoint']+=1
  rejected(f'{ci}:cutpoint',api.encode(forged,3),expected)
  forged=json.loads(json.dumps(expected));forged['forms']=expected['forms'];forged['metadata']['lines'][0]['prefix'].append([0,1,2])
  rejected(f'{ci}:prefix',api.encode(forged,3),expected)
  # Matching forged registry acceptance exposes external trust explicitly.
  forged=json.loads(json.dumps(expected));forged['forms']=expected['forms'];forged['metadata']['bindings']['epoch']='f'*64
  api.decode(api.encode(forged,3),forged);counters['matching_forged_registry_acceptance_controls']+=1
  rec=api.decode(data,expected);unsupported=next(P for P in range(1,69) if rec['lines'][0]['g']%math.gcd(P,rec['metadata']['period']))
  try:api.query(rec,16,unsupported,0)
  except ValueError:counters['unsupported_modulus_rejections']+=1
  else:raise RuntimeError('unsupported modulus accepted')
  for K,P,phi in [(0,1,0),(65536,1,0),(1,0,0),(1,69,0),(1,1,1)]:
   try:api.query(rec,K,P,phi)
   except ValueError:counters['policy_guard_rejections']+=1
   else:raise RuntimeError('policy guard accepted')
 want=json.loads((OUT/'QUERY_VALIDATION.json').read_text())['semantic_sha256']
 if semantic.hexdigest()!=want:raise RuntimeError('full query semantic digest mismatch')
 counters['targeted_record_mutants_rejected']=len(mutant_report)
 save(OUT/'SELF_CHECK.json',{'status':'PASS_SEPARATE_FORMULATION_PRODUCER_CROSSCHECK_PENDING_EXTERNAL_GATE','counts':dict(counters),'query_semantic_sha256':semantic.hexdigest(),'external_independent_role':False,'normal_Python_only':True,'mutants':mutant_report})
 print(json.dumps(dict(counters),indent=2))
if __name__=='__main__':
 ap=argparse.ArgumentParser();ap.add_argument('--attempt',required=True);a=ap.parse_args();OUT=HERE/a.attempt
 try:run()
 except Exception:
  (OUT/'SELF_CHECK_FAILURE.txt').write_text(traceback.format_exc(),encoding='utf8');raise
