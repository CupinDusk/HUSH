"""Matched complete-workflow cost source. Correctness validation only for now.

No clock, timer, measurement, collection or host-setting API is present.
"""
from pathlib import Path
import argparse,hashlib,json,math,random
import calendar_records as cr
HERE=Path(__file__).resolve().parent
METHODS={'raw_relation':'raw_relation','grouped_master':'grouped_master','portfolio_reset':'portfolio','dense':'dense_portfolio'}
QS=[1,4,16,64,256];SEED=2026102306;BLOCKS=9
def load_expected(caseid):
 # Shared frozen source acquisition and input visibility for every method.
 b=json.loads((HERE/'INPUT_BINDING.json').read_text());source=HERE/'frozen-input/analysis-01/RELATIONS.json'
 expectedhash=next(x['sha256'] for x in b['inputs'] if x['name']=='analysis-01/RELATIONS.json')
 raw=source.read_bytes();cr.require(cr.sha_bytes(raw)==expectedhash,'frozen source binding')
 cases=json.loads(raw)['records'];case=cases[caseid]
 reg=json.loads((OUT/'TRUSTED_EXPECTED_REGISTRY.json').read_text())['records'][caseid]
 cr.require(reg['metadata']['bindings']['relation']==cr.sha_bytes(cr.canonical_json(case)),'relation registry binding')
 expected={'metadata':reg['metadata'],'forms':{int(k):[(g,[tuple(x) if isinstance(x,list) else x for x in items]) for g,items in rows] for k,rows in reg['forms'].items()}}
 return expected
def prepare(caseid,method):
 expected=load_expected(caseid)
 # Same raw source artifact and source acquisition for every cold method.
 data=(OUT/'records'/f'case-{caseid:02d}.raw_relation.bin').read_bytes()
 raw=cr.decode(data,expected);d=raw['metadata']['period'];g=raw['metadata']['portfolio_g']
 kind={'raw_relation':4,'grouped_master':1,'portfolio_reset':3,'dense':5}[method];forms=[]
 for line in raw['lines']:
  triples=line['items'];pairs=[(s%d,h-s) for s,c,h in triples]
  if kind==4:forms.append((d,triples))
  elif kind==1:forms.append((d,cr.grouped(pairs,d)))
  elif kind==3:forms.append((g,cr.core(pairs,g)))
  else:
   canonical=cr.core(pairs,g);forms.append((g,[cr.value(canonical,g,q) for q in range(g)]))
 build={'metadata':expected['metadata'],'forms':{kind:forms}}
 encoded=cr.encode(build,kind);decoded=cr.decode(encoded,expected)
 # Prefix metadata has identical visibility and source/trust overhead.
 prefixes=[[tuple(x) for x in l['prefix']] for l in decoded['metadata']['lines']]
 return decoded,prefixes
def sweep(prepared,method):
 decoded,prefixes=prepared;meta=decoded['metadata'];d=meta['period'];result=[]
 for P in meta['portfolio_P']:
  m=math.gcd(P,d)
  projected=None if method=='raw_relation' else cr.project(decoded,P)
  for phi in range(P):
   # Physical prefix binding is recomputed for every changed period/phase.
   prefix=[s+1+(phi-s-1)%P-h for rows in prefixes for s,c,h in rows]
   if method=='raw_relation':
    recurrent=min(s+n*d+1+(phi-s-n*d-1)%P-(h+n*d) for line in decoded['lines'] for s,c,h in line['items'] for n in range(P//m))
    base=min([recurrent]+prefix)
   else:base=cr.projected_base(decoded,P,phi,projected)
   for K in range(1,17):result.append([K,P,phi,(K-1)*P+base])
 return cr.canonical_json(result)
def semantic_for_Q(payload,Q):
 h=hashlib.sha256()
 for _ in range(Q):h.update(payload)
 return h.hexdigest()
def frozen_schedule():
 rng=random.Random(SEED);rows=[]
 for block in range(1,BLOCKS+1):
  cases=list(range(12));rng.shuffle(cases)
  for mode in ['cold_complete','warm_reuse']:
   for Q in QS:
    methods=list(METHODS);rng.shuffle(methods)
    rows.append({'block':block,'mode':mode,'Q':Q,'case_order':cases,'method_order':methods})
 return {'seed':SEED,'paired_blocks':BLOCKS,'warmup':'exactly one untimed complete Q1 sweep of each case/method before nine paired blocks','Q_semantics':'Q complete four-period sweeps per controller, all phi and K1..16','cold_boundary':'source acquisition + source parse/binding + record read/parse/binding + prefix setup + Q sweeps including every target projection/reset/dense build/raw scan + semantic hash + cleanup','warm_boundary':'source-validated parsed representation retained from precomputation; Q sweeps include every target projection/reset/dense build/raw scan, exact prefix, semantic hash, cleanup; precompute separately reported','rows':rows}
def validate():
 report=[]
 for ci in range(12):
  payloads={}
  for method in METHODS:
   prepared=prepare(ci,method);payload=sweep(prepared,method);payloads[method]=payload
   # Cold source/record parse is performed separately for every method;
   # read-only expected-Q construction follows exact pure repeated sweeps.
   del prepared
  cr.require(len(set(payloads.values()))==1,'workflow semantic mismatch')
  payload=next(iter(payloads.values()))
  report.append({'case':ci,'one_sweep_queries':len(json.loads(payload)),'one_sweep_payload_bytes':len(payload),'expected_semantic_hashes':{str(Q):semantic_for_Q(payload,Q) for Q in QS},'methods':list(METHODS),'Q_hash_validation':'All four actual one-sweep implementations byte-equal; Q is exact deterministic payload repetition. No timings.'})
 schedule=frozen_schedule()
 (OUT/'WORKFLOW_SCHEDULE.json').write_text(json.dumps(schedule,indent=2)+'\n',encoding='utf8')
 manifest={'status':'CORRECTNESS_ONLY_EXPECTED_HASHES_FIXED_BEFORE_ANY_TIMING','Q':QS,'source_sha256':cr.sha_file(Path(__file__)),'codec_sha256':cr.sha_file(HERE/'calendar_records.py'),'registry_sha256':cr.sha_file(OUT/'TRUSTED_EXPECTED_REGISTRY.json'),'schedule_sha256':cr.sha_file(OUT/'WORKFLOW_SCHEDULE.json'),'cases':report,'performance_collections':0}
 (OUT/'WORKFLOW_EXPECTED_HASHES.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf8')
 print(json.dumps({'status':manifest['status'],'cases':12,'methods':4,'Q':QS,'paired_blocks':BLOCKS,'performance_collections':0}))
if __name__=='__main__':
 ap=argparse.ArgumentParser();ap.add_argument('--validate',action='store_true',required=True);ap.parse_args();validate()
