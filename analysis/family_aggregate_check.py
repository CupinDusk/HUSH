"""All admitted existing cases, two fixed grids and fair completion baselines."""
from pathlib import Path
from collections import Counter
from fractions import Fraction as F
import hashlib,json,math
from r23_canonical import canonical
from r26_remod import profile,project
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def hist(c):return {str(k):v for k,v in sorted(c.items())}
def describe(c):
 n=sum(c.values());assert n
 def at(i):
  offset=0
  for x,k in sorted(c.items()):
   if i<offset+k:return x
   offset+=k
 return {'n':n,'min':min(c),'median':str(F(at((n-1)//2)+at(n//2),2)),'max':max(c),'histogram':hist(c)}
def bucket():return {'counts':Counter(),'query_service_terms':Counter(),'query_completion_terms':Counter(),'per_entry':[]}
def count_query(b,exact,bound,support):
 c=b['counts'];c['policy_queries']+=1
 c['full_master_positive' if exact>0 else 'full_master_unknown']+=1
 c['fair_completion_positive' if bound>0 else 'fair_completion_unknown']+=1
 c['supported_policy_queries' if support else 'unsupported_policy_queries']+=1
 c['supported_positive' if exact>0 else 'supported_unknown']+=support
 c['full_master_rescues']+=exact>0 and bound<=0
 c['supported_rescues']+=support and exact>0 and bound<=0
 assert bound<=exact
def main():
 out=HERE/'R35_FAMILY_AGGREGATE_RESULTS.json';assert not out.exists()
 proto=HERE/'R35_FAMILY_AGGREGATE_PROTOCOL.json';assert json.loads(proto.read_text())['status'].startswith('before_')
 prior_path=HERE/'R30_PRODUCER_FAMILY_RESULTS.json';prior=json.loads(prior_path.read_text(encoding='utf-8'))
 assert prior['parameter_entries']==1950 and prior['admitted_entries']==1622
 grids={'primary':bucket(),'expanded':bucket()};sizes={k:Counter() for k in ['raw','master','stored','stored_fair_completion']};case_counts=Counter();interfaces={g:Counter() for g in grids};per_entry=[]
 for rec in prior['records']:
  if not rec['admitted']:case_counts['tie_rejected']+=1;continue
  p,q=rec['p'],rec['q'];T=[tuple(t) for t in rec['cycle']];d=rec['translation'];g=d//math.gcd(d,3)
  J=max(c-s for s,c,h in T);A=max(h-c for s,c,h in T)
  raw=profile([(s,h-s) for s,c,h in T],d);master=canonical(raw,d);assert master==tuple(map(tuple,rec['master_pairs']))
  stored=project(master,g);C=sorted({c for s,c,h in T});fair_stored=canonical(profile([((c-J)%g,J+A) for c in C],g),g)
  for key,value in [('raw',raw),('master',master),('stored',stored),('stored_fair_completion',fair_stored)]:sizes[key][len(value)]+=1
  case_counts['admitted']+=1;case_counts['master_reduction']+=len(master)<len(raw);case_counts['stored_reduction_vs_master']+=len(stored)<len(master)
  case_counts['nonempty_transient']+=bool(rec['prefix']);case_counts['storage_is_full_modulus']+=g==d
  regime='waiting' if q<p else 'polling' if q>=2*p else 'mixed_band';case_counts['regime_'+regime]+=1
  local={key:bucket() for key in grids};targets=[]
  for P in range(1,4*p+1):
   m=math.gcd(P,d);Q=project(master,m);directQ=canonical(profile([(s,h-s) for s,c,h in T],m),m);assert Q==directQ
   support=g%m==0
   if support:assert project(stored,m)==Q
   C_m=sorted({c%m for c in C});fair=canonical(profile([((c-J)%m,J+A) for c in C_m],m),m)
   W_m={c%m for s,c,h in T if c-s==J and h-c==A};query_exact=set(C_m)==W_m
   for key,b in grids.items():
    if key=='primary' and P>2*p:continue
    interfaces[key]['interfaces']+=1;interfaces[key]['supported' if support else 'unsupported']+=1
    interfaces[key]['completion_query_exact']+=query_exact
    interfaces[key]['service_fewer_than_completion']+=len(Q)<len(fair)
    interfaces[key]['service_equal_to_completion']+=len(Q)==len(fair)
    interfaces[key]['service_more_than_completion']+=len(Q)>len(fair)
    b['query_service_terms'][len(Q)]+=1;b['query_completion_terms'][len(fair)]+=1
   all_equal=True
   for phi in range(P):
    direct=min(1+(phi-s-n*d-1)%P-(h-s) for s,c,h in T for n in range(P//m))
    value=1+min((phi-r-1)%m-v for r,v in Q);assert value==direct
    direct_bound=1-J-A+min((phi+J-1-c-n*d)%P for c in C for n in range(P//m))
    bound=1+min((phi-r-1)%m-v for r,v in fair);assert bound==direct_bound and bound<=value
    all_equal=all_equal and bound==value
    for K in range(1,6):
     exact=(K-1)*P+value;D=(K-1)*P+bound
     for key in grids:
      if key=='primary' and (P>2*p or K>2):continue
      count_query(grids[key],exact,D,support);count_query(local[key],exact,D,support)
   assert all_equal==query_exact
   targets.append({'P':P,'m':m,'supported':support,'service_terms':len(Q),'completion_terms':len(fair),'query_exact':query_exact})
  entry={'case_id':rec['case_id'],'p':p,'q':q,'s0':rec['s0'],'prefix_triples':len(rec['prefix']),'d':d,'g':g,'J':J,'A':A,'raw_terms':len(raw),'master_terms':len(master),'stored_terms':len(stored),'stored_completion_terms':len(fair_stored),'grids':{key:dict(b['counts']) for key,b in local.items()}}
  per_entry.append(entry)
  for key,b in local.items():
   case_counts[key+'_any_full_rescue']+=b['counts']['full_master_rescues']>0
   case_counts[key+'_any_supported_rescue']+=b['counts']['supported_rescues']>0
  if len(per_entry)%200==0:print(json.dumps({'progress_admitted_entries':len(per_entry)}),flush=True)
 assert case_counts['admitted']==1622 and case_counts['tie_rejected']==328 and case_counts['master_reduction']==0
 primary=grids['primary']['counts'];assert (primary['policy_queries'],primary['full_master_positive'],primary['full_master_unknown'])==(643060,12168,630892)
 reports={}
 for key,b in grids.items():
  c=b['counts'];assert c['supported_positive']+c['supported_unknown']+c['unsupported_policy_queries']==c['policy_queries']
  reports[key]={'counts':dict(c),'interfaces':dict(interfaces[key]),'query_service_term_distribution':describe(b['query_service_terms']),'query_completion_term_distribution':describe(b['query_completion_terms'])}
 # Disjoint outcomes for the already specified R34 grid, without reinterpretation.
 r34=json.loads((HERE/'R34_MULTIPHASE_RESULTS.json').read_text());T=r34['theory']['base_triples'];cross=Counter()
 for P in range(1,85):
  m=math.gcd(P,420);support=140%m==0
  for phi in range(P):
   for K in range(1,6):
    exact=(K-1)*P+1+min((phi-s-1)%m-(h-s) for s,c,h in T)
    cross['supported_positive' if support and exact>0 else 'supported_unknown' if support else 'unsupported']+=1
 assert dict(cross)=={'supported_unknown':2932,'supported_positive':8828,'unsupported':6090}
 result={'result':'PASS_ALL_ADMITTED_EXISTING_FAMILY_FIXED_GRIDS_AND_FAIR_COMPLETION_AGGREGATES','protocol_sha256':sha(proto),'script_sha256':sha(Path(__file__)),'input_r30_result_sha256':sha(prior_path),'input_r34_result_sha256':sha(HERE/'R34_MULTIPHASE_RESULTS.json'),'case_counts':dict(case_counts),'parameter_term_distributions':{k:describe(v) for k,v in sizes.items()},'grids':reports,'r34_disjoint_outcomes':dict(cross),'records':per_entry,'scope':'All existing admitted parameter entries in one specified source/receiver family; recurrent relations only, not transient safety. Storage/grid rules selected after prior examples and before these aggregate counts. Two finite deterministic grids are not workload-frequency or population-utility estimates. No new source/native/hardware execution or measured runtime/bytes/application gain.'}
 out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps({k:v for k,v in result.items() if k not in ['records','parameter_term_distributions']}),flush=True)
if __name__=='__main__':main()
