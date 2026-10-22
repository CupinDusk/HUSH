"""Re-query every admissible periodic lift of the retained mixed-source cycles."""
from pathlib import Path
from collections import Counter
import hashlib,json,math
from r20_interface import profile
HERE=Path(__file__).resolve().parent

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def divisors(d):return sorted({v for a in range(1,math.isqrt(d)+1) if d%a==0 for v in (a,d//a)})

def main():
    protocol=HERE/'R21_PERIOD_PROTOCOL.json'
    spec=json.loads(protocol.read_text(encoding='utf-8'))
    source=HERE/'mixed-poll-build/events.json';mixedpath=HERE/'MIXED_POLL_RESULTS.json'
    mixed=json.loads(mixedpath.read_text(encoding='utf-8'))
    assert sha(source)==mixed['source_events_sha256']
    raw=json.loads(source.read_text(encoding='utf-8'))
    binding={(r['p'],r['ell'],r['s0'],r['q']):r for r in raw}
    summaries={};rows=[];queries=sign_differences=0
    for r in mixed['cycles']:
        key=tuple(r[n] for n in ['p','ell','s0','q']);T=tuple(map(tuple,r['cycle']))
        trace=binding[key];observed=list(zip(trace['services'],trace['receipts'],trace['services'][1:]))
        assert all(v in observed for v in T)
        d=T[-1][2]-T[0][0]
        assert d>0 and d%r['p']==0
        J=max(c-s for s,c,h in T);A=max(h-c for s,c,h in T)
        branch='both_branches' if len({'response_first' if c<s+r['q'] else 'wait' for s,c,h in T})==2 else 'wait_only'
        for P in divisors(d):
            C=sorted({c%P for s,c,h in T});W=sorted({c%P for s,c,h in T if c-s==J and h-c==A});nu=profile(T,P)
            witness=C==W;equal=True;dif=0;worstloss=0
            for K in range(1,5):
                for phi in range(P):
                    F=lambda a:a+(phi-a)%P+(K-1)*P
                    direct=min(F(s+1)-h for s,c,h in T)
                    abstract=(K-1)*P-J+1+min((phi+J-1-c)%P for c in C)-A
                    prof=(K-1)*P+1+min((phi-s-1)%P-v for s,v in nu.items())
                    assert direct==prof and direct>=abstract
                    equal &= direct==abstract;worstloss=max(worstloss,direct-abstract)
                    if (direct>0)!=(abstract>0):dif+=1
                    queries+=1
            assert equal==witness
            item={'client':key,'cycle_shift':d,'triples':T,'P':P,'J':J,'A':A,'branch':branch,'baseline_P_equals_p':P==r['p'],
                  'completion_residues':C,'joint_witness_residues':W,'service_span_profile':sorted(nu.items()),
                  'N':len(T),'m':len(C),'w':len(W),'t':len(nu),'witness_exact':witness,
                  'maximum_slack_loss':worstloss,'finite_K1_to4_phase_sign_differences':dif,
                  'completion_payload_scalar_slots_excluding_H':len(C)+len(W)+5,
                  'profile_payload_scalar_slots_excluding_H':2*len(nu)+1,
                  'extra_witness_slots_if_CJA_already_available':len(W)+2}
            rows.append(item);sign_differences+=dif
    assert len(mixed['cycles'])==372
    for name,pred in [('all',lambda r:True),('P_equals_p',lambda r:r['baseline_P_equals_p']),('other_periods',lambda r:not r['baseline_P_equals_p']),('both_branches',lambda r:r['branch']=='both_branches'),('wait_only',lambda r:r['branch']=='wait_only')]:
        group=[r for r in rows if pred(r)];unique={}
        for r in group:
            k=(r['P'],r['J'],r['A'],tuple(r['completion_residues']),tuple(map(tuple,r['service_span_profile'])))
            if k in unique:assert unique[k]['witness_exact']==r['witness_exact']
            unique[k]=r
        groups={'cycle_period_pairs':len(group),'exact':sum(r['witness_exact'] for r in group),'inexact':sum(not r['witness_exact'] for r in group),
                'multi_completion_residue_pairs':sum(r['m']>1 for r in group),
                'query_entries_m_vs_t':dict(Counter('m<t' if r['m']<r['t'] else 'm=t' if r['m']==r['t'] else 'm>t' for r in group)),
                'full_payload_completion_vs_profile':dict(Counter('completion_smaller' if r['m']+r['w']+5<2*r['t']+1 else 'equal' if r['m']+r['w']+5==2*r['t']+1 else 'profile_smaller' for r in group)),
                'distinct_interfaces':len(unique),'distinct_exact':sum(r['witness_exact'] for r in unique.values()),'distinct_inexact':sum(not r['witness_exact'] for r in unique.values())}
        summaries[name]=groups
    out={'result':'PASS_R21_ALL_DIVISOR_PERIOD_REQUERY','protocol_sha256':sha(protocol),'script_sha256':sha(Path(__file__)),
         'existing_mixed_results_sha256':sha(mixedpath),'existing_source_events_sha256':sha(source),
         'new_source_execution':False,'new_native_measurements':0,'all_phase_queries_K1_to4':queries,
         'finite_sign_differences':sign_differences,'summaries':summaries,'cases':rows,'scientific_boundary':spec['scientific_boundary']}
    (HERE/'R21_PERIOD_RESULTS.json').write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:out[k] for k in ['result','all_phase_queries_K1_to4','finite_sign_differences','summaries']}))

if __name__=='__main__':main()
