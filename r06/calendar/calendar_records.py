"""Versioned complete four-line calendar codec and exact observer utilities.

Normal-Python reference code, not a hardened hostile-input library.
"""
from pathlib import Path
import hashlib,json,math,struct
MAGIC=b'HUCALR06';SCHEMA=1;PROOF=1
KINDS={0:'full_raw_profile',1:'grouped_master',2:'canonical_master',3:'portfolio',4:'raw_relation',5:'dense_portfolio'}
def canonical_json(x):return json.dumps(x,sort_keys=True,separators=(',',':'),ensure_ascii=False).encode('utf8')
def sha_bytes(b):return hashlib.sha256(b).hexdigest()
def sha_file(p):return sha_bytes(Path(p).read_bytes())
def require(ok,why):
 if not ok:raise ValueError(why)
def grouped(pairs,g):
 out={}
 for r,b in pairs:out[r%g]=max(b,out.get(r%g,-1))
 return sorted(out.items())
def value(pairs,g,q):return min((q-r-1)%g-b for r,b in pairs)
def core(pairs,g):
 a=grouped(pairs,g)
 return [(r,b) for r,b in a if not any(t!=r and c-b>=(r-t)%g for t,c in a)]
def reset_value(pairs,g,q):
 # Canonical pairs form a unit-slope envelope; most recent reset suffices.
 from bisect import bisect_right
 resets=sorted(((r+1)%g,b) for r,b in pairs);q%=g
 i=bisect_right([r for r,b in resets],q)-1;r,b=resets[i]
 return (q-r)%g-b
def normalized_key(state):
 s={k.removeprefix('before_'):v for k,v in state.items()};origin=s['nextid']
 snap=lambda n:[s[n+'owner'],s[n+'id']-origin,s[n+'byte']] if s[n+'v'] else None
 return {'phases':[s[k] for k in ['cp','rp','fp','pp']],
 'live_queue':[[s['qowners']>>(2*i)&3,s['qid'+str(i)]-origin] for i in range(s['qlen'])],
 'R0':snap('R0'),'R1':snap('R1'),'outstanding':s['outstanding'],'valid':s['valid'],
 'enabled':s['enabled'],'bytes':s['bytes'],'counts':[s['count'+str(i)] for i in range(4)],
 'failed':s['failed'],'fault':s['fault']}
def make_expected(case,bindings,source_evidence):
 cfg=case['configuration'];d=case['period'];targets=[cfg['p']*a for a in range(1,5)]
 g=math.lcm(*(math.gcd(P,d) for P in targets))
 meta={'producer':'R06-matched-calendar-reference','schema':SCHEMA,'proof':PROOF,'case':case['case'],
 'configuration':cfg,'period':d,'entry':case['entry'],'repeat':case['repeat'],
 'entry_state':case['entry_state'],'normalized_entry_key':normalized_key(case['entry_state']),
 'ID_translation':case['ID_translation'],'original_empty_frame_gate':case['original_empty_frame_gate'],
 'full_key_extension':case['full_key_extension'],'bindings':bindings,'source_evidence':source_evidence,'portfolio_P':targets,'portfolio_g':g,
 'guards':{'line_count':4,'line_IDs':[0,1,2,3],'tags':[0,1,2,3],'FIFO':8,'phase_bits':16,
 'count_bits':16,'byte_bits':8,'tick_ID_bits':32,'tick_ID_exclusive':2**31-2,
 'K_min':1,'K_max':65535,'P_min':1,'P_max':68,'strict_WU':'t>initial_capture_cutpoint',
 'epoch':'fixed clocks/source/no refill, unrelated invalidation, reset or retuning inside run'},
 'lines':[{'owner':l['line'],'initial_capture_cutpoint':l['initial_capture_cutpoint'],'J':l['J'],'A':l['A'],
 'C0':l['C0'],'completion_domain':l['completion_domain'],'prefix':l['prefix'],
 'prefix_crosses_entry':[h>=case['entry'] for s,c,h in l['prefix']]} for l in case['lines']]}
 forms={k:[] for k in KINDS}
 for l in case['lines']:
  raw=[(s%d,h-s) for s,c,h in l['cycle']];group=grouped(raw,d);master=core(raw,d);port=core(raw,g)
  forms[0].append((d,raw));forms[1].append((d,group));forms[2].append((d,master));forms[3].append((g,port))
  forms[4].append((d,[tuple(t) for t in l['cycle']]));forms[5].append((g,[value(port,g,q) for q in range(g)]))
 return {'metadata':meta,'forms':forms}
def encode(expected,kind):
 meta=canonical_json(expected['metadata']);out=[MAGIC,struct.pack('<4I',SCHEMA,PROOF,kind,len(meta)),meta,struct.pack('<I',4)]
 for owner,(g,items) in enumerate(expected['forms'][kind]):
  out.append(struct.pack('<3I',owner,g,len(items)))
  fmt='<i' if kind==5 else '<3I' if kind==4 else '<2I'
  for row in items:out.append(struct.pack(fmt,*(row if kind!=5 else [row])))
 return b''.join(out)
def decode(data,expected):
 pos=0
 def take(n):
  nonlocal pos
  require(n>=0 and pos+n<=len(data),'truncated');b=data[pos:pos+n];pos+=n;return b
 def un(fmt):return struct.unpack(fmt,take(struct.calcsize(fmt)))
 require(take(8)==MAGIC,'magic');schema,proof,kind,nmeta=un('<4I')
 require(schema==SCHEMA and proof==PROOF and kind in KINDS,'schema/proof/format')
 metabytes=take(nmeta)
 require(metabytes==canonical_json(expected['metadata']),'trusted registry metadata/bindings mismatch')
 meta=json.loads(metabytes);require(un('<I')[0]==4,'four lines required');lines=[]
 for wanted in range(4):
  owner,g,n=un('<3I');eg,ei=expected['forms'][kind][wanted]
  require(owner==wanted and g==eg and g>0,'line ID/modulus')
  width=4 if kind==5 else 12 if kind==4 else 8
  require(n==len(ei) and n>0 and n*width<=len(data)-pos,'count/domain')
  items=[un('<i')[0] if kind==5 else un('<3I') if kind==4 else un('<2I') for _ in range(n)]
  require(items==ei,'trusted expected exact profile/relation mismatch')
  if kind in (1,2,3):require(items==grouped(items,g),'sorted grouped profile')
  if kind in (2,3):require(items==core(items,g),'canonical profile')
  if kind<4:require(all(0<=r<g and 0<b<2**31 for r,b in items),'profile domain')
  if kind==4:require(all(0<=s<c<=h<2**31 for s,c,h in items),'relation domain')
  lines.append({'owner':owner,'g':g,'items':items})
 require(pos==len(data),'trailing bytes')
 return {'kind':kind,'metadata':meta,'lines':lines}
def prefix_base(meta,P,phi):
 vals=[s+1+(phi-s-1)%P-h for l in meta['lines'] for s,c,h in l['prefix']]
 return min(vals) if vals else None
def project(decoded,P):
 meta=decoded['metadata'];m=math.gcd(P,meta['period']);result=[]
 for line in decoded['lines']:
  g=line['g'];require(g%m==0,'unsupported target modulus')
  kind=decoded['kind'];items=line['items']
  if kind==4:pairs=[(s%m,h-s) for s,c,h in items];result.append(('pairs',core(pairs,m)))
  elif kind==5:
   dense=[min(items[q] for q in range(r,g,m)) for r in range(m)];result.append(('dense',dense))
  else:result.append(('pairs',core(items,m)))
 return m,result
def projected_base(decoded,P,phi,prepared=None):
 m,lines=prepared or project(decoded,P);vals=[]
 for typ,items in lines:vals.append(items[phi%m] if typ=='dense' else reset_value(items,m,phi))
 pb=prefix_base(decoded['metadata'],P,phi)
 return min([1+min(vals)]+([] if pb is None else [pb]))
def query(decoded,K,P,phi):
 guard=decoded['metadata']['guards']
 require(isinstance(K,int) and isinstance(P,int) and isinstance(phi,int),'integer policy')
 require(guard['K_min']<=K<=guard['K_max'] and guard['P_min']<=P<=guard['P_max'] and 0<=phi<P,'policy guard')
 return (K-1)*P+projected_base(decoded,P,phi)
def observer_bases(case,P,phi):
 d=case['period'];m=math.gcd(P,d);service=[];completion=[];pre=[]
 for l in case['lines']:
  service.append(1+min((phi-s-1)%m-(h-s) for s,c,h in l['cycle']))
  completion.append(1-l['J']-l['A']+min((phi+l['J']-1-c)%m for c in l['C0']))
  pre.extend(s+1+(phi-s-1)%P-h for s,c,h in l['prefix'])
 return min(service+pre),min(completion+pre)
def min_K(base,P):return 1+max(0,(1-base+P-1)//P)
