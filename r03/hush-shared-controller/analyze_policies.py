"""Complete admissions, physical-period prefix, line-aware strongest baseline."""
from pathlib import Path
from collections import Counter
import gzip,hashlib,json,math,sys
HERE=Path(__file__).resolve().parent
OLD=HERE.parents[3]/'outputs/iscas-review-loop-20261021/editor-analysis'
sys.path.insert(0,str(OLD))
from r23_canonical import canonical
from r26_remod import profile,project
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def mask(v,P):return sum((1<<(K-1)) for K in range(1,6) if v+(K-1)*P>0)
def main():
    assert not (HERE/'POLICY_RESULTS.json').exists()
    relations=json.loads((HERE/'RELATIONS.json').read_text())
    total=Counter(); records=[]; examples={}; counts=Counter()
    phasepath=HERE/'ALL_PHASE_BASES.jsonl.gz'
    with gzip.open(phasepath,'wt',encoding='utf-8',compresslevel=9,newline='\n') as out:
      out.write(json.dumps({'schema':'Each phase row = [phi, exact_full_base, shared_exact_prefix_completion_base, exact_prefix_base_or_null_inf, recurrence_base, line_minimizer,s,c,h,posthoc_supported, exact_policy_mask_K1to5, completion_policy_mask_K1to5]. Add (K-1)*P to bases. Prefix is physical P; recurrence uses gcd(P,d). Completing baseline retains each line identity and uses separately tight recurrent J/A/C0; same exact prefix. All zero and negative outcomes retained.'})+'\n')
      for rec in relations['records']:
        if rec['status']!='EXACT_CYCLE':
            records.append({'case_id':rec['case_id'],'status':rec['status']});continue
        local=Counter();d=rec['translation'];p=rec['configuration']['p']
        for P in range(1,4*p+1):
          m=math.gcd(P,d);lineinfo=[]
          for line in rec['lines']:
            T=line['cycle']; copies=[(s+n*d,c+n*d,h+n*d) for s,c,h in T for n in range(P//m)]
            Q=project(tuple(map(tuple,line['master'])),m)
            assert Q==canonical(profile([(s,h-s) for s,c,h in T],m),m)
            counts['projected_canonical_pairs']+=len(Q)
            counts['projection_group_input_pairs']+=len(line['master'])
            counts['prefix_edges_per_interface']+=len(line['prefix'])
            lineinfo.append((line,copies,Q))
          supported=all(line['posthoc_g']%m==0 for line in rec['lines'])
          if supported:
            for line,copies,Q in lineinfo:
              assert project(tuple(map(tuple,line['posthoc_pairs'])),m)==Q
          rows=[]
          for phi in range(P):
            minima=[];prefix=[];recurrent=[];completion=[]
            for line,copies,Q in lineinfo:
              j=line['line'];T=line['cycle'];pre=line['prefix']
              vals=[(s+1+(phi-s-1)%P-h,j,s,c,h) for s,c,h in copies]
              rv=min(vals);recurrent.append(rv)
              assert rv[0]==1+min((phi-r-1)%m-v for r,v in Q)
              minima+=vals
              if pre:
                pv=[(s+1+(phi-s-1)%P-h,j,s,c,h) for s,c,h in pre]
                minima+=pv;prefix+=pv
              cr=1-line['J']-line['A']+min((phi+line['J']-1-c)%m for c in line['C0'])
              assert cr<=rv[0];completion.append(cr)
            full,j,s,c,h=min(minima);prebase=min(prefix)[0] if prefix else None
            recbase=min(recurrent)[0]
            shared=min(completion+[prebase] if prebase is not None else completion)
            assert shared<=full and full==min([recbase,prebase] if prebase is not None else [recbase])
            # Direct tick countdown on the minimizing physical edge, independently
            # of the profile and expiry formula. One immediate later WU is sharp.
            n=0
            for t in range(s+1,h+1): n+=t%P==phi
            me,mc=mask(full,P),mask(shared,P)
            assert mc&~me==0
            for K in range(1,6):
              counter=K;valid=True
              for t in range(s+1,h+1):
                if valid and t%P==phi:
                  counter-=1
                  if counter==0:valid=False
              assert valid==bool(me&(1<<(K-1)))== (K>n)
              counts['literal_countdown_load_checks']+=1
            vals={'policy_queries':5,'full_service_positive':me.bit_count(),
                  'full_service_unknown':5-me.bit_count(),
                  'full_completion_positive':mc.bit_count(),
                  'full_service_only':(me&~mc).bit_count(),
                  'recurrent_positive_but_prefix_rejects':(mask(recbase,P)&~me).bit_count(),
                  'posthoc_supported_queries':5 if supported else 0,
                  'posthoc_unsupported_queries':0 if supported else 5,
                  'posthoc_supported_full_positive':me.bit_count() if supported else 0,
                  'posthoc_supported_full_unknown':5-me.bit_count() if supported else 0,
                  'posthoc_supported_service_only':(me&~mc).bit_count() if supported else 0}
            local.update(vals);total.update(vals)
            rows.append([phi,full,shared,prebase,recbase,j,s,c,h,supported,me,mc])
            for label,found in [('service_only',me&~mc),('negative',31&~me),('prefix_reject',mask(recbase,P)&~me)]:
              if found and label not in examples:
                K=next(k for k in range(1,6) if found&(1<<(k-1)))
                examples[label]={'case_id':rec['case_id'],'P':P,'phi':phi,'K':K,'full_slack':full+(K-1)*P,'completion_slack':shared+(K-1)*P,'witness':[j,s,c,h],'decrements':n,'WU_tick':s+1,'supported':supported}
            counts['phase_rows']+=1
          out.write(json.dumps({'case_id':rec['case_id'],'P':P,'m':m,'rows':rows},separators=(',',':'))+'\n')
          counts['controller_policy_interfaces']+=1
        records.append({'case_id':rec['case_id'],'status':'ALL_GRID_QUERIES_RETAINED',
                        'counts':dict(local),'lines':[{k:v for k,v in line.items() if k not in ['prefix','cycle','C0','raw_master','master','posthoc_pairs','prospective_pairs']} for line in rec['lines']]})
    ctrls=[r for r in relations['records'] if r['status']=='EXACT_CYCLE']
    study={'source_cases':len(relations['records']),'cycle_cases':len(ctrls),
           'cap_failures':len(relations['records'])-len(ctrls),
           'backpressure_exercised_cases':sum(r['stats_over_detection_plus_two_cycles'].get('response_backpressure_stalls',0)>0 for r in ctrls),
           'two_queued_exercised_cases':sum(r['stats_over_detection_plus_two_cycles'].get('max_queue',0)==2 for r in ctrls),
           'nonempty_prefix_cases':sum(any(line['prefix'] for line in r['lines']) for r in ctrls),
           'prefix_edges':sum(len(line['prefix']) for r in ctrls for line in r['lines']),
           'cycle_edges':sum(len(line['cycle']) for r in ctrls for line in r['lines']),
           'raw_master_pairs':sum(len(line['raw_master']) for r in ctrls for line in r['lines']),
           'canonical_master_pairs':sum(len(line['master']) for r in ctrls for line in r['lines']),
           'posthoc_pairs':sum(len(line['posthoc_pairs']) for r in ctrls for line in r['lines']),
           'prospective_all_grid_pairs':sum(len(line['prospective_pairs']) for r in ctrls for line in r['lines']),
           'total_detection_ticks':sum(r['repeat_tick'] for r in ctrls),
           'max_detection_ticks':max(r['repeat_tick'] for r in ctrls),
           'translation_min_max':[min(r['translation'] for r in ctrls),max(r['translation'] for r in ctrls)],
           'source_case_service_only_positive':sum(r.get('counts',{}).get('full_service_only',0)>0 for r in records),
           'source_case_service_only_zero':sum(r.get('counts',{}).get('full_service_only',0)==0 for r in records)}
    result={'status':'PASS_ALL_40_DECLARED_CONTROLLER_POLICY_GRIDS','protocol_sha256':sha(HERE/'PROTOCOL.json'),
            'relations_sha256':sha(HERE/'RELATIONS.json'),'script_sha256':sha(Path(__file__)),
            'phase_file_sha256':sha(phasepath),'study':study,'counts':dict(total),'checks':dict(counts),
            'examples':examples,'records':records,
            'boundary':'Specified bounded two-line controller, not native HUSH/coherence/hardware or independent workload observations. No wallclock timing result.'}
    (HERE/'POLICY_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:result[k] for k in ('status','study','counts','checks','examples')},indent=2),flush=True)
if __name__=='__main__':main()
