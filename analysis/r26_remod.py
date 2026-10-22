"""Exact divisor projection from canonical payloads; no new source execution."""
from pathlib import Path
from itertools import product
from collections import Counter
import hashlib,json,math
from r23_canonical import canonical,envelope
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def profile(events,g):
 spans={}
 for s,v in events:spans[s%g]=max(v,spans.get(s%g,-1))
 return tuple(sorted(spans.items()))
def project(pairs,h):return canonical(profile(pairs,h),h)
def main():
 out=HERE/'R26_REMOD_RESULTS.json';assert not out.exists()
 finite=[];finite_queries=0
 for g in range(1,5):
  profiles=projections=0
  for ages in product([None]+list(range(2*g+2)),repeat=g):
   raw=tuple((r,v) for r,v in enumerate(ages) if v is not None)
   if not raw:continue
   profiles+=1;core=canonical(raw,g)
   for h in range(1,g+1):
    if g%h:continue
    direct=canonical(profile(raw,h),h);reused=project(core,h)
    assert direct==reused
    assert envelope(direct,h)==envelope(profile(raw,h),h)
    finite_queries+=h;projections+=1
  finite.append({'g':g,'profiles':profiles,'divisor_projections':projections})
 assert sum(r['profiles'] for r in finite)==15420
 counterexamples=[]
 for g in range(1,17):
  for h in range(1,17):
   if g%h==0:continue
   d=math.lcm(g,h);a=((0,d),);b=((g,d),)
   source_a=canonical(profile(a,g),g);source_b=canonical(profile(b,g),g)
   target_a=project(a,h);target_b=project(b,h)
   assert source_a==source_b and envelope(target_a,h)[1%h]!=envelope(target_b,h)[1%h]
   counterexamples.append({'source_modulus':g,'target_modulus':h,'translation':d,'first_services':[0,g],'span':d,'source_payload':source_a,'target_payloads':[target_a,target_b],'phase1_envelopes':[envelope(target_a,h)[1%h],envelope(target_b,h)[1%h]],'separates':'exact slack, not necessarily the restricted safe/unsafe predicate'})
 path=HERE/'MIXED_POLL_RESULTS.json';mixed=json.loads(path.read_text(encoding='utf-8'));cycles=mixed['cycles'];assert len(cycles)==372
 events=HERE/'mixed-poll-build/events.json';assert sha(events)==mixed['source_events_sha256']
 raw=json.loads(events.read_text(encoding='utf-8'));bound={tuple(r[k] for k in ['p','ell','s0','q']):r for r in raw}
 cases=[];queries=projections=reuse_pairs=total_pairs=distinct_reuse=0;hist=Counter();worked=None
 for cyc in cycles:
  key=tuple(cyc[k] for k in ['p','ell','s0','q']);T=tuple(map(tuple,cyc['cycle']));d=cyc['shift'];assert d==T[-1][2]-T[0][0]
  trace=bound[key];observed=set(zip(trace['services'],trace['receipts'],trace['services'][1:]));assert all(t in observed for t in T)
  spans=tuple((s,h-s) for s,c,h in T);raw_master=profile(spans,d);master=canonical(raw_master,d);forms={};gcds={}
  for P in range(1,65):
   g=math.gcd(P,d);gcds[P]=g;direct=canonical(profile(spans,g),g);reused=project(master,g);assert direct==reused
   if g in forms:assert forms[g]==direct
   forms[g]=direct;projections+=1;hist[(len(master),len(direct))]+=1
   expanded=[(s+n*d,h+n*d) for n in range(P//g) for s,c,h in T]
   for phi in range(P):
    explicit0=min(s+1+(phi-s-1)%P-h for s,h in expanded)
    consumer0=1+min((phi-r-1)%g-v for r,v in reused)
    for K in range(1,5):
     physical_B=(K-1)*P;assert explicit0+physical_B==consumer0+physical_B;queries+=1
  cached={}
  for old in range(1,65):
   for new in range(1,65):
    total_pairs+=1;g,h=gcds[old],gcds[new]
    if g%h:continue
    reuse_pairs+=1
    if (g,h) not in cached:
     cached[g,h]=project(forms[g],h);assert cached[g,h]==forms[h];distinct_reuse+=1
    assert cached[g,h]==forms[h]
  rec={'client':key,'translation':d,'source_triples':T,'raw_master':raw_master,'canonical_master':master,'profiles_by_target_gcd':{str(g):p for g,p in sorted(forms.items())},'distinct_divisor_reuse_pairs':len(cached)};cases.append(rec)
  if key==(9,1,5,16):
   assert d==81 and master==((5,16),(21,16),(37,33),(70,16))
   assert forms[27]==((5,16),(10,33)) and project(forms[27],9)==forms[9]==((1,33),)
   P=18;K=3;phi=2;slack=(K-1)*P+1+min((phi-r-1)%9-v for r,v in forms[9]);assert slack==4
   worked={**rec,'old_P':27,'old_g':27,'new_P':18,'new_g':9,'new_K':K,'new_phi':phi,'physical_B':36,'exact_slack':slack,'old_to_new_payload_reuse':True,'physical_new_period_divides_old':False,'target_g81_not_universally_determined_from_g27':True}
 assert queries==3095040 and projections==372*64 and total_pairs==372*64*64 and worked
 result={'result':'PASS_EXACT_CANONICAL_DIVISOR_REUSE_AND_UNIVERSAL_PERIOD_MASTER','protocol_sha256':sha(HERE/'R26_REMOD_PROTOCOL.json'),'argument_sha256':sha(HERE/'R26_REMOD_ARGUMENT.md'),'script_sha256':sha(Path(__file__)),'input_mixed_sha256':sha(path),'input_source_events_sha256':sha(events),'finite_profile_checks':finite,'finite_target_phase_queries':finite_queries,'nondivisor_counterexamples':counterexamples,'source_audit':{'already_executed_cycles':len(cases),'new_physical_periods':'1..64','master_to_target_projections':projections,'K1_to4_all_physical_phase_queries':queries,'ordered_physical_old_new_pairs':total_pairs,'divisibility_admitted_reuse_pairs':reuse_pairs,'distinct_source_target_modulus_checks':distinct_reuse,'master_to_fixed_term_distribution':[{'master_terms':a,'fixed_terms':b,'cycle_period_pairs':n} for (a,b),n in sorted(hist.items())],'disagreements':0},'worked_d81':worked,'cases':cases,'new_source_execution':False,'new_native_measurements':0,'boundary':'Payload-only preservation of exact scalar slacks under unchanged admitted relation/bindings. Not arbitrary safe-predicate necessity, extra-information impossibility, runtime token validity, minimum encoded bytes or physical conformance.'}
 out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
 print(json.dumps({'result':result['result'],'finite':finite,'finite_target_phases':finite_queries,'nondivisor_cases':len(counterexamples),'source':result['source_audit'],'worked':worked},indent=2))
if __name__=='__main__':main()
