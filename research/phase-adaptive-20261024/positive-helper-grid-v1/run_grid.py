"""Frozen positive-helper grid; exact, unchanged analytical execution model."""
from pathlib import Path
from itertools import product
import json,hashlib,time,gzip,csv,statistics,traceback
import replacement_model as m
HERE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
P=json.loads((HERE/'PROTOCOL.json').read_text())
assert sha(HERE/'replacement_model.py')==P['model_sha256']
base=dict(m.P);paths=sorted(set(product(P['phase_domain'],repeat=3))|{(k,k,k) for k in range(1,256)})
assert len(paths)==591 and len(P['settings'])==79
RAW=HERE/'candidate-records';RAW.mkdir(exist_ok=True)
CASES=HERE/'case-records';CASES.mkdir(exist_ok=True)
start=time.perf_counter();errors=[];cases=[];executions=0;candidate_count=0;rawhashes={}

def dump(p,obj):p.write_text(json.dumps(obj,indent=2)+'\n')
def helper_ops(original,delta):
 ops=[]
 for op,v in original:
  if op=='phase' and v>0:ops.append(('compute',delta))
  ops.append((op,v))
 return ops
def best(xs,B):
 vals=[x for x in xs if x['W']<=B and x['execution'] is not None]
 return min(vals,key=lambda x:(x['execution']['makespan'],x['execution']['reader_cycles'],x['execution']['updates'],x['K'],x['flush'])) if vals else None

for ci,spec in enumerate(P['settings']):
 m.P.clear();m.P.update(base);m.P.update({k:v for k,v in spec.items() if k in base})
 q=m.P['shared_blocks'];m.P.update(receiver_dense_reads=8*q,writer_store_count=64*q)
 m.P['analytic_unknown_read_bound_cycles']=m.P['update_slot_cycles']+1+m.P['miss_slot_cycles']
 original=m.instructions(spec['family'],P['quiet']);training_gap=spec.get('writer_gap',P['writer_gap_default'])
 Cbase=sum(v for op,v in original if op=='compute');nr=sum(op=='read' for op,v in original)
 B0=Cbase+q*m.P['analytic_unknown_read_bound_cycles']+(nr-q)
 maxB=B0+max(P['budget_margins']);opsmap={0:original,**{d:helper_ops(original,d) for d in P['helper_costs']}}
 fixed=[];phase={d:[] for d in P['helper_costs']};train_cache={};validate_cache={};case_errors=[]
 rawsha=hashlib.sha256();rawpath=RAW/f'case-{ci:03d}.jsonl.gz'

 def execute(ops,ks,flush,a,gap,phi,tag):
  global executions
  executions+=1
  try:
   r=m.simulate(ops,ks,gap,phi,a,writer_count=64*q,flush_at_boundaries=flush,flush_at_finish=True)
   assert r['unsafe_hits']==0 and r['reader_cycles']<=a['bound']
   return r
  except Exception as exc:
   err={'case':ci,'tag':tag,'K':ks,'flush':flush,'gap':gap,'phi':phi,
        'error':repr(exc),'traceback':traceback.format_exc()}
   errors.append(err);case_errors.append(err);dump(HERE/'ERRORS.json',errors)
   return None

 with rawpath.open('wb') as rawfile,gzip.GzipFile(filename='',fileobj=rawfile,mode='wb',mtime=0) as raw:
  def candidate(mode,delta,ks,flush):
   global candidate_count
   ops=opsmap[delta] if mode=='phase' else original
   a=m.analyze(ops,ks,flush_at_boundaries=flush)
   C=sum(v for op,v in ops if op=='compute');S=a['switches'];Lsw=m.P['switch_cycles']
   row={'case':ci,'mode':mode,'helper_delta':delta,'K':ks,'flush':flush,
        'W':a['bound'],'C':C,'M':a['bound']-C-S*Lsw,'S':S,'Lsw':Lsw,
        'helper_total':2*delta if mode=='phase' else 0,'H':a['hits'],'U':a['unknown'],
        'admitted':{str(d):a['bound']<=B0+d for d in P['budget_margins']},'execution':None}
   if a['bound']<=maxB:
    row['execution']=execute(ops,ks,flush,a,training_gap,0,'training')
   blob=(json.dumps(row,sort_keys=True,separators=(',',':'))+'\n').encode()
   rawsha.update(blob);raw.write(blob);candidate_count+=1
   return row
  for k,flush in product(range(1,256),[(),(1,),(2,),(1,2)]):fixed.append(candidate('fixed',0,(k,k,k),flush))
  for delta in P['helper_costs']:
   for ks in paths:phase[delta].append(candidate('phase',delta,ks,()))
 rawhashes[f'case-{ci:03d}.jsonl']=rawsha.hexdigest()

 def validation(item,gap,phi):
  delta=item['helper_delta'] if item['mode']=='phase' else 0
  key=(item['mode'],delta,tuple(item['K']),tuple(item['flush']),gap,phi)
  if key not in validate_cache:
   ops=opsmap[delta] if item['mode']=='phase' else original
   a=m.analyze(ops,item['K'],flush_at_boundaries=item['flush'])
   validate_cache[key]=execute(ops,item['K'],item['flush'],a,gap,phi,'validation')
  return validate_cache[key]

 selections=[]
 # Primary margin is generated first. The remaining margins reuse identical
 # candidate runs; no post-validation policy selection or load tuning occurs.
 for margin,delta in product([32,0,16,64],P['helper_costs']):
  B=B0+margin;f=best(fixed,B);p=best(phase[delta],B)
  chosen=p if p and (not f or p['execution']['makespan']<f['execution']['makespan']) else f
  row={'case':ci,'margin':margin,'delta':delta,'budget':B,'B0':B0,
       'fixed_admitted':sum(x['W']<=B for x in fixed),'phase_admitted':sum(x['W']<=B for x in phase[delta]),
       'fixed':f,'phase':p,'selected':chosen,'mode':chosen and chosen['mode'],
       'offline_fixed_fallback':bool(f and chosen is f),'validation':[],'valid':not case_errors}
  if chosen and f:
   row['training_signed_gain']=(f['execution']['makespan']-chosen['execution']['makespan'])/f['execution']['makespan']
   for gap,phi in product(P['validation_writer_gaps'],sorted(set([0,m.P['period']-1]))):
    fr=validation(f,gap,phi);sr=validation(chosen,gap,phi)
    vr={'writer_gap':gap,'phi':phi,'fixed':fr,'selected':sr,'valid':bool(fr and sr)}
    if fr and sr:vr['signed_gain']=(fr['makespan']-sr['makespan'])/fr['makespan']
    else:row['valid']=False
    row['validation'].append(vr)
  else:row['valid']=False
  selections.append(row)
 case={'index':ci,'spec':spec,'parameters':dict(m.P),'training_gap':training_gap,'Cbase':Cbase,'nreads':nr,'B0':B0,
       'candidate_rows':1020+591*3,'raw_scientific_jsonl_sha256':rawsha.hexdigest(),
       'selections':selections,'errors':case_errors}
 cases.append(case);dump(CASES/f'case-{ci:03d}.json',case)
 dump(HERE/'STATUS.json',{'cases_complete':len(cases),'cases_planned':79,'selected_settings':len(cases)*12,
   'primary237_complete':len(cases)*3,'executions':executions,'candidate_rows':candidate_count,
   'errors':len(errors),'elapsed_seconds':time.perf_counter()-start})
 print('case',len(cases),'/79 elapsed',round(time.perf_counter()-start,1),'exec',executions,'errors',len(errors),flush=True)

allrows=[r for c in cases for r in c['selections']]
def summarize(rows):
 train=[r['training_signed_gain'] for r in rows if 'training_signed_gain' in r]
 vals=[v['signed_gain'] for r in rows for v in r['validation'] if 'signed_gain' in v]
 return {'settings':len(rows),'valid_settings':sum(r['valid'] for r in rows),
   'fallback_settings':sum(r['offline_fixed_fallback'] for r in rows),
   'phase_selected':sum(r['mode']=='phase' for r in rows),
   'training_wins':sum(x>0 for x in train),'training_ties':sum(x==0 for x in train),'training_losses':sum(x<0 for x in train),
   'training_gain_range':[min(train),max(train)] if train else None,
   'training_median':statistics.median(train) if train else None,
   'validation_points':len(vals),'validation_wins':sum(x>0 for x in vals),
   'validation_ties':sum(x==0 for x in vals),'validation_losses':sum(x<0 for x in vals),
   'validation_gain_range':[min(vals),max(vals)] if vals else None,
   'validation_median':statistics.median(vals) if vals else None}
summary={'all':summarize(allrows),'primary_delta8_margin32':summarize([r for r in allrows if r['delta']==8 and r['margin']==32]),
 'margin32_all_costs':summarize([r for r in allrows if r['margin']==32]),
 'by_cost':{str(d):summarize([r for r in allrows if r['delta']==d]) for d in P['helper_costs']},
 'by_margin':{str(d):summarize([r for r in allrows if r['margin']==d]) for d in P['budget_margins']},
 'by_primary_family':{fam:summarize([r for c in cases if c['spec']['family']==fam for r in c['selections'] if r['delta']==8 and r['margin']==32]) for fam in ['BSQ','DQD']},
 'cases_complete':len(cases),'candidate_rows':candidate_count,'execution_count':executions,'assertion_or_other_failures':len(errors)}
result={'protocol_sha256':sha(HERE/'PROTOCOL.json'),'model_sha256':sha(HERE/'replacement_model.py'),
        'driver_sha256':sha(Path(__file__)),'summary':summary,'cases':cases,'errors':errors,
        'elapsed_seconds':time.perf_counter()-start}
dump(HERE/'RESULTS.json',result);dump(HERE/'SUMMARY.json',summary);dump(HERE/'RAW_SCIENTIFIC_HASHES.json',rawhashes)
flat=[]
for case in cases:
 for r in case['selections']:
  sel=r['selected']
  for v in r['validation']:
   flat.append({'case':case['index'],'family':case['spec']['family'],'q':case['parameters']['shared_blocks'],
     'g':case['parameters']['receiver_compute_gap'],'P':case['parameters']['period'],'margin':r['margin'],'delta':r['delta'],
     'budget':r['budget'],'mode':r['mode'],'K':sel and sel['K'],'W':sel and sel['W'],'M':sel and sel['M'],
     'C':sel and sel['C'],'S':sel and sel['S'],'validation_gap':v['writer_gap'],'validation_phi':v['phi'],
     'fixed_J':v['fixed'] and v['fixed']['makespan'],'selected_J':v['selected'] and v['selected']['makespan'],
     'signed_gain':v.get('signed_gain'),'valid':v['valid']})
with (HERE/'VALIDATION_ROWS.csv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(flat[0]));w.writeheader();w.writerows(flat)
dump(HERE/'STATUS.json',{'stage':'complete','cases_complete':len(cases),'settings':len(allrows),'errors':len(errors),'elapsed_seconds':time.perf_counter()-start})
print(json.dumps(summary,indent=2),flush=True)
