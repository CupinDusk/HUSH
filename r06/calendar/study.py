"""Generate matched complete records and exact finite-bound optimum tables."""
from pathlib import Path
from collections import Counter
import argparse,csv,gzip,hashlib,json,math,shutil,traceback
import calendar_records as cr
HERE=Path(__file__).resolve().parent
def dump(p,x):p.write_text(json.dumps(x,indent=2,ensure_ascii=False)+'\n',encoding='utf8')
def manifest(root):return [{'path':str(p.relative_to(root)).replace('\\','/'),'bytes':p.stat().st_size,'sha256':cr.sha_file(p)} for p in sorted(root.rglob('*')) if p.is_file() and p.name!='OUTPUT_MANIFEST.json']
def optimum(rows):
 if not rows:return {'minimum_KP_minus1':None,'all_ties_K_P_phi':[],'selected_K_P_phi':None,'empty':True}
 obj=min(x[0] for x in rows);ties=sorted(x[1:] for x in rows if x[0]==obj)
 return {'minimum_KP_minus1':obj,'all_ties_K_P_phi':ties,'selected_K_P_phi':ties[0],'empty':False}
def source_binding(binding):
 names=['receiver.v','driver.cpp','PROTOCOL.json','AMENDMENT_01_PRE_EXECUTION.md','AMENDMENT_02_FULL_KEY_EXTENSION.md']
 return cr.sha_bytes(cr.canonical_json({x['name']:x['sha256'] for x in binding['inputs'] if x['name'] in names}))
def run(out):
 binding=json.loads((HERE/'INPUT_BINDING.json').read_text())
 for row in binding['inputs']:
  if row['frozen_copy'] and cr.sha_file(HERE/'frozen-input'/row['name'])!=row['sha256']:raise RuntimeError('frozen input drift')
 cases=json.loads((HERE/'frozen-input/analysis-01/RELATIONS.json').read_text())['records']
 independent=json.loads((HERE/'frozen-input/independent/INDEPENDENT_RELATIONS.json').read_text())
 require_records=independent['records'] if isinstance(independent,dict) else independent
 if cases!=require_records:raise RuntimeError('independent relation mismatch')
 old=json.loads((HERE/'frozen-input/analysis-01/TUNING.json').read_text())['records']
 iold=json.loads((HERE/'frozen-input/independent/INDEPENDENT_TUNING.json').read_text())['records']
 if old!=iold:raise RuntimeError('independent tuning mismatch')
 (out/'records').mkdir();registry=[];sizes=[];optim=[];querycounts=Counter();worked=[]
 hashes=hashlib.sha256();phasepath=out/'SEARCH_PHASES.jsonl.gz'
 with gzip.open(phasepath,'wt',encoding='utf8',newline='\n') as search:
  for case,prev in zip(cases,old):
   cid=case['case'];d=case['period'];p=case['configuration']['p']
   binds={'source':source_binding(binding),'receiver':cr.sha_file(HERE/'frozen-input/receiver.v'),
    'relation':cr.sha_bytes(cr.canonical_json(case)),
    'epoch':cr.sha_bytes(cr.canonical_json({'contract':'R05 fixed controller/source/ready/reset/WU-cutpoint epoch','case':case,'source_binding':source_binding(binding)}))}
   source_rows=(HERE/'frozen-input/receiver.v').read_text().splitlines()
   guard_receipts=[{'line':i+1,'text':t.strip()} for i,t in enumerate(source_rows) if 'input [15:0]' in t or 'input [31:0]' in t or 'if(cfgp<' in t or 'if(tick>=' in t]
   source_evidence={'producer_control':{'sha256':next(x['sha256'] for x in binding['inputs'] if x['name']=='build-04/CONTROL_TICKS.csv'),'physical_range':[0,4*d]},'independent_control':{'sha256':next(x['sha256'] for x in binding['inputs'] if x['name']=='independent/INDEPENDENT_CONTROL_5F.csv'),'physical_range':[0,5*d]},'validated_recurrence_range':[case['entry'],case['physical_validation_end_exclusive']],'guard_receiver_sha256':binds['receiver'],'exact_source_lines':guard_receipts}
   expected=cr.make_expected(case,binds,source_evidence);registry.append(expected);dec={};sizerow={'case':cid,'p':p,'r':case['configuration']['r'],'d':d,'entry':case['entry'],'portfolio_P':expected['metadata']['portfolio_P'],'gstar':expected['metadata']['portfolio_g'],'lines':[]}
   for kind,name in cr.KINDS.items():
    raw=cr.encode(expected,kind);(out/'records'/f'case-{cid:02d}.{name}.bin').write_bytes(raw);dec[kind]=cr.decode(raw,expected)
    sizerow[name+'_bytes']=len(raw)
   overhead=len(cr.encode(expected,0))-sum(len(rows)*8 for g,rows in expected['forms'][0]);sizerow['common_metadata_and_headers_bytes']=overhead
   for j in range(4):
    sizerow['lines'].append({'owner':j,'prefix_count':len(case['lines'][j]['prefix']),'equivalent_uint32_triple_payload_bytes':12*len(case['lines'][j]['prefix']),'actual_prefix_JSON_value_bytes':len(cr.canonical_json(expected['metadata']['lines'][j]['prefix'])),'actual_prefix_crossing_flags_JSON_value_bytes':len(cr.canonical_json(expected['metadata']['lines'][j]['prefix_crosses_entry'])),
     'full_raw_pairs':len(expected['forms'][0][j][1]),'grouped_pairs':len(expected['forms'][1][j][1]),'canonical_master_pairs':len(expected['forms'][2][j][1]),'portfolio_pairs':len(expected['forms'][3][j][1])})
   sizerow['portfolio_saved_vs_canonical_bytes']=sizerow['canonical_master_bytes']-sizerow['portfolio_bytes']
   sizerow['portfolio_saved_vs_retained_raw_relation_bytes']=sizerow['raw_relation_bytes']-sizerow['portfolio_bytes'];sizes.append(sizerow)
   # Every target phase/K for all four lines jointly and all six formats.
   for P in expected['metadata']['portfolio_P']:
    prepared={kind:cr.project(v,P) for kind,v in dec.items()}
    for phi in range(P):
     service,comp=cr.observer_bases(case,P,phi)
     for K in range(1,17):
      val=(K-1)*P+service
      vals=[(K-1)*P+cr.projected_base(rec,P,phi,prepared[kind]) for kind,rec in dec.items()]
      if any(v!=val for v in vals):raise RuntimeError(('query mismatch',cid,K,P,phi,vals,val))
      querycounts['joint_policies']+=1;querycounts['positive']+=val>0;querycounts['nonpositive']+=val<=0;querycounts['zero_slack']+=val==0;querycounts['six_format_joint_comparisons']+=6;querycounts['four_line_policy_instances']+=4
      hashes.update(cr.canonical_json([cid,K,P,phi,val,(K-1)*P+comp]))
     # A useful worked changed P pair is fixed as case7 phi0,K15 for p and 2p.
     if cid==7 and P in [p,2*p] and phi==0:
      K=15;m=math.gcd(P,d);prefix=[];cycles=[]
      for l in case['lines']:
       for s,c,h in l['prefix']:prefix.append({'line':l['line'],'s':s,'c':c,'h':h,'first_expiry':s+1+(phi-s-1)%P+(K-1)*P,'slack':s+1+(phi-s-1)%P+(K-1)*P-h})
       vals=[((K-1)*P+1+(phi-s-1)%m-(h-s),s,c,h) for s,c,h in l['cycle']]
       v,s,c,h=min(vals);cycles.append({'line':l['line'],'m':m,'physical_B':h-s,'cycle_base_triple':[s,c,h],'cycle_slack':v,'stored_g':expected['metadata']['portfolio_g'],'stored_pairs':expected['forms'][3][l['line']][1]})
      worked.append({'case':cid,'K':K,'P':P,'phi':phi,'entry':case['entry'],'repeat':case['repeat'],'gcd':m,'prefix':prefix,'cycle':cycles,'service_slack':(K-1)*P+service,'completion_slack':(K-1)*P+comp})
   # Exact old finite grid (all K), including original K<=5 subset.
   candidates={k:[] for k in ['service','completion','original5_service','original5_completion']};counts=Counter()
   for P in range(1,4*p+1):
    for phi in range(P):
     bs=cr.observer_bases(case,P,phi)
     for K in range(1,17):
      vals=[b+(K-1)*P for b in bs];counts['policy_queries']+=1;counts['service_positive']+=vals[0]>0;counts['completion_positive']+=vals[1]>0;counts['service_only']+=vals[0]>0>=vals[1]
      counts['original5_queries']+=K<=5;counts['original5_service_positive']+=K<=5 and vals[0]>0;counts['original5_completion_positive']+=K<=5 and vals[1]>0
      for observer,val in zip(['service','completion'],vals):
       if val>0:
        candidates[observer].append([K*P-1,K,P,phi])
        if K<=5:candidates['original5_'+observer].append([K*P-1,K,P,phi])
   grid={k:optimum(v) for k,v in candidates.items()}
   if grid!=prev['optima'] or dict(counts)!=prev['counts']:raise RuntimeError(('old grid mismatch',cid))
   # Immutable old admitted witnesses fix a finite bound before new phases.
   bound=max(grid[o]['minimum_KP_minus1']+1 for o in ['service','completion'])
   arbitrary={o:[] for o in ['service','completion']};guarded={o:[] for o in ['service','completion']}
   for P in range(1,bound+1):
    for phi in range(P):
     bs=cr.observer_bases(case,P,phi);ks=[cr.min_K(b,P) for b in bs]
     search.write(json.dumps([cid,P,phi,*bs,*ks],separators=(',',':'))+'\n')
     for observer,K in zip(['service','completion'],ks):
      productbound=grid[observer]['minimum_KP_minus1']+1
      if K<=16 and K*P<=productbound:
       arbitrary[observer].append([K*P-1,K,P,phi])
       if P<=68:guarded[observer].append([K*P-1,K,P,phi])
   bopt={o:optimum(v) for o,v in arbitrary.items()};gopt={o:optimum(v) for o,v in guarded.items()}
   spans=[h-s for l in case['lines'] for s,c,h in l['cycle']+l['prefix']]
   prefixspans=[h-s for l in case['lines'] for s,c,h in l['prefix']]
   lower={'service':max(spans),'completion':max([l['J']+l['A'] for l in case['lines']]+prefixspans)};uncapped={};p1={}
   for index,o in enumerate(['service','completion']):
    K=1+lower[o];bs=cr.observer_bases(case,1,0);legal=1<=K<=65535
    if not legal or (K-1)+bs[index]!=1:raise RuntimeError(('P1 proof/width failed',cid,o,K,bs))
    p1[o]={'K':K,'P':1,'phi':0,'proxy':K-1,'slack':(K-1)+bs[index],'source_guard_legal':legal}
    rows=[];product=lower[o]+1
    for P in range(1,min(68,product)+1):
     if product%P:continue
     K=product//P
     if K>65535:continue
     for phi in range(P):
      if cr.observer_bases(case,P,phi)[index]+(K-1)*P>0:rows.append([product-1,K,P,phi])
    uncapped[o]=optimum(rows)
   def difference(opts):
    s=opts['service']['minimum_KP_minus1'];c=opts['completion']['minimum_KP_minus1']
    return {'completion_minus_service':c-s,'relative_increment_over_service':(c-s)/s if s else None}
   optim.append({'case':cid,'p':p,'r':case['configuration']['r'],'entry':case['entry'],'repeat':case['repeat'],'original_empty_frame_gate':case['original_empty_frame_gate'],
    'old_grid':grid,'old_grid_counts':dict(counts),'fixed_K16_arbitrary_P':bopt,'fixed_K16_source_P68':gopt,'uncapped_K_source_guards':uncapped,'P1_lower_bound_witnesses':p1,
    'original_witness_product_search_bound':bound,'search_all_P_phi_through_bound':True,
    'improvement_outside_old_grid':{o:grid[o]['minimum_KP_minus1']-bopt[o]['minimum_KP_minus1'] for o in arbitrary},
    'increment_by_domain':{'old_grid':difference(grid),'fixed_K16_arbitrary_P':difference(bopt),'fixed_K16_source_P68':difference(gopt),'uncapped_K_source_guards':difference(uncapped)}})
   print('completed case',cid,'records',sizerow['canonical_master_bytes'],sizerow['portfolio_bytes'],'bound',bound,flush=True)
 dump(out/'TRUSTED_EXPECTED_REGISTRY.json',{'trust':'Externally sourced expected input registry; must itself be trusted and independently checked. Digests are not source authentication.','records':registry})
 dump(out/'COMPLETE_RECORD_BYTES.json',{'cases':sizes,'total_by_format':{name:sum(x[name+'_bytes'] for x in sizes) for name in cr.KINDS.values()},'larger_or_equal_vs_master_cases':[x['case'] for x in sizes if x['portfolio_saved_vs_canonical_bytes']<=0]})
 dump(out/'OPTIMA_ALL_TIES.json',{'objective':'KP-1 model retention proxy, common four-line policy; new search arithmetic only','records':optim})
 dump(out/'QUERY_VALIDATION.json',{'status':'PRODUCER_MATCHED_ALL_FORMATS_PENDING_EXTERNAL_INDEPENDENT_GATE','counts':dict(querycounts),'semantic_sha256':hashes.hexdigest(),'metadata':'All policies including negative/zero outcomes retained in deterministic complete enumeration; no RTL rerun.'})
 dump(out/'WORKED_CHANGED_PERIOD.json',{'selection':'Prospectively fixed case7 K15 phi0 P=p and 2p, including same physical prefix and cycle','queries':worked})
 # Compact comparison table with absolute values and tie counts.
 with (out/'CASE_TABLE.csv').open('w',newline='',encoding='utf8') as f:
  fields=['case','p','r','entry','old_service','old_completion','old_service_ties','old_completion_ties','K16_anyP_service','K16_anyP_completion','K16_P68_service','K16_P68_completion','uncapped_source_service','uncapped_source_completion','fullraw_bytes','grouped_bytes','master_bytes','portfolio_bytes','raw_relation_bytes','dense_bytes'];w=csv.DictWriter(f,fieldnames=fields);w.writeheader()
  for row,size in zip(optim,sizes):
   x={k:row[k] for k in ['case','p','r','entry']}
   for label,domain in [('old','old_grid'),('K16_anyP','fixed_K16_arbitrary_P'),('K16_P68','fixed_K16_source_P68'),('uncapped_source','uncapped_K_source_guards')]:
    for o in ['service','completion']:x[label+'_'+o]=row[domain][o]['minimum_KP_minus1']
   for o in ['service','completion']:x['old_'+o+'_ties']=len(row['old_grid'][o]['all_ties_K_P_phi'])
   for col,name in [('fullraw','full_raw_profile'),('grouped','grouped_master'),('master','canonical_master'),('portfolio','portfolio'),('raw_relation','raw_relation'),('dense','dense_portfolio')]:x[col+'_bytes']=size[name+'_bytes']
   w.writerow(x)
 dump(out/'SCOPE_AND_FAILURE_METADATA.json',{'source_role':'Own R05 calendar reference component','old_evidence_untouched':True,'original_case7_empty_frame_grid_UNKNOWN':6496,'full_key_case7_entry':37,'full_key_case7_repeat':93,'new_RTL_ticks':0,'new_performance_timings':0,'omitted_prehistory_executed':False,'admission_counts':{'additional_service':sum(x['old_grid_counts']['service_only'] for x in optim),'completion_admissions':sum(x['old_grid_counts']['completion_positive'] for x in optim),'service_admissions':sum(x['old_grid_counts']['service_positive'] for x in optim),'all_grid_policies':sum(x['old_grid_counts']['policy_queries'] for x in optim)},'limitations':['No native HUSH/gem5/coherence/PPA/WCET/application measurement','Arbitrary-period fixed-K search beyond P68 is mathematical only and illegal for this receiver','Uncapped design proxy has elementary P1 optimum, not a new optimization algorithm','All ties are objective-bounded finite sets','The external expected registry is trusted input; untrusted digests authenticate nothing']})
 dump(out/'OUTPUT_MANIFEST.json',{'files':manifest(out)})
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--attempt',required=True);a=ap.parse_args()
 out=HERE/a.attempt;out.mkdir(exist_ok=False);(out/'source').mkdir()
 sources=['PROTOCOL.md','AMENDMENT_01_METADATA_AND_COST_BOUNDARY.md','prepare.py','calendar_records.py','study.py','self_check.py','workflow_cost.py']
 initial={'status':'BOUND_BEFORE_PARSE_GENERATION_OR_SEARCH','input_binding_sha256':cr.sha_file(HERE/'INPUT_BINDING.json'),'sources':{n:cr.sha_file(HERE/n) for n in sources}}
 dump(out/'PRE_EXECUTION_BINDING.json',initial)
 for n in sources:shutil.copyfile(HERE/n,out/'source'/n)
 try:run(out)
 except Exception:
  (out/'FAILURE.txt').write_text(traceback.format_exc(),encoding='utf8');raise
 for n,h in initial['sources'].items():
  if cr.sha_file(HERE/n)!=h:raise RuntimeError('producer source changed during execution')
if __name__=='__main__':main()
