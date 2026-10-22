"""Independent expanded-cycle and gcd-compressed query comparison."""
from pathlib import Path
from collections import Counter
import hashlib,json,math
HERE=Path(__file__).resolve().parent

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    proto=HERE/'R21_LIFT_PROTOCOL.json';spec=json.loads(proto.read_text(encoding='utf-8'))
    mixedpath=HERE/'MIXED_POLL_RESULTS.json';events=HERE/'mixed-poll-build/events.json'
    mixed=json.loads(mixedpath.read_text(encoding='utf-8'));assert sha(events)==mixed['source_events_sha256']
    raw=json.loads(events.read_text(encoding='utf-8'));bound={(r['p'],r['ell'],r['s0'],r['q']):r for r in raw}
    rows=[];queries=0;worked=None
    for cyc in mixed['cycles']:
        key=tuple(cyc[k] for k in ['p','ell','s0','q']);T=tuple(map(tuple,cyc['cycle']));d=T[-1][2]-T[0][0]
        trace=bound[key];observed=list(zip(trace['services'],trace['receipts'],trace['services'][1:]));assert all(v in observed for v in T)
        assert d>0 and d%cyc['p']==0
        J=max(c-s for s,c,h in T);A=max(h-c for s,c,h in T)
        branch='both_branches' if len({'response_first' if c<s+cyc['q'] else 'wait' for s,c,h in T})==2 else 'wait_only'
        for P in range(1,33):
            g=math.gcd(P,d);copies=P//g;expanded=tuple((s+n*d,c+n*d,h+n*d) for n in range(copies) for s,c,h in T)
            Cg=sorted({c%g for s,c,h in T});Wg=sorted({c%g for s,c,h in T if c-s==J and h-c==A})
            C=sorted({c%P for s,c,h in expanded});W=sorted({c%P for s,c,h in expanded if c-s==J and h-c==A})
            assert C==[a for a in range(P) if a%g in Cg] and W==[a for a in range(P) if a%g in Wg]
            nu={}
            for s,c,h in T:nu[s%g]=max(nu.get(s%g,-1),h-s)
            fullprofile={}
            for s,c,h in expanded:fullprofile[s%P]=max(fullprofile.get(s%P,-1),h-s)
            assert len(fullprofile)==len(nu)*copies
            assert all(fullprofile[r]==nu[r%g] for r in fullprofile)
            equal=True;sign_diff=0;maxloss=0;phase_slacks=[]
            for K in range(1,5):
                B=(K-1)*P
                for phi in range(P):
                    direct=min(s+1+(phi-s-1)%P+B-h for s,c,h in expanded)
                    compressed=B+1+min((phi-s-1)%g-v for s,v in nu.items())
                    fullcompletion=min(c-J+1+(phi-c+J-1)%P+B-c for c in C)-A
                    shortcompletion=B-J+1+min((phi+J-1-c)%g for c in Cg)-A
                    assert direct==compressed and fullcompletion==shortcompletion and direct>=shortcompletion
                    equal &= direct==shortcompletion;sign_diff+=(direct>0)!=(shortcompletion>0);maxloss=max(maxloss,direct-shortcompletion);queries+=1
                    if key==(5,1,3,8) and P==15:phase_slacks.append({'K':K,'phi':phi,'exact':direct,'completion':shortcompletion})
            assert equal==(Cg==Wg)==(C==W)
            item={'client':key,'d':d,'P':P,'g':g,'copies':copies,'J':J,'A':A,'branch':branch,'baseline_P_equals_p':P==cyc['p'],
                  'N_base':len(T),'N_lifted':len(expanded),'m_compressed':len(Cg),'t_compressed':len(nu),
                  'm_lifted':len(C),'t_lifted':len(fullprofile),'completion_residues_g':Cg,'joint_witness_residues_g':Wg,
                  'profile_g':sorted(nu.items()),'exact':equal,'finite_K1_to4_sign_differences':sign_diff,'maximum_slack_loss':maxloss}
            rows.append(item)
            if phase_slacks:worked={**item,'base_triples':T,'expanded_triples':expanded,'completion_residues_P':C,'joint_witness_residues_P':W,'all_K1to4_phase_slacks':phase_slacks}
    assert len(rows)==372*32 and worked
    summaries={}
    for name,pred in [('all',lambda r:True),('P_equals_p',lambda r:r['baseline_P_equals_p']),('other_periods',lambda r:not r['baseline_P_equals_p']),('both_branches',lambda r:r['branch']=='both_branches'),('wait_only',lambda r:r['branch']=='wait_only')]:
        group=[r for r in rows if pred(r)];unique={}
        for r in group:
            k=(r['P'],r['g'],r['J'],r['A'],tuple(r['completion_residues_g']),tuple(map(tuple,r['profile_g'])))
            if k in unique:assert unique[k]['exact']==r['exact']
            unique[k]=r
        summaries[name]={'cycle_period_pairs':len(group),'exact':sum(r['exact'] for r in group),'inexact':sum(not r['exact'] for r in group),
                         'multi_completion_residue_pairs':sum(r['m_lifted']>1 for r in group),
                         'exact_multi_completion_residue_pairs':sum(r['exact'] and r['m_lifted']>1 for r in group),
                         'compressed_query_entries':dict(Counter('m<t' if r['m_compressed']<r['t_compressed'] else 'm=t' if r['m_compressed']==r['t_compressed'] else 'm>t' for r in group)),
                         'distinct_interfaces':len(unique),'distinct_exact':sum(r['exact'] for r in unique.values()),'distinct_inexact':sum(not r['exact'] for r in unique.values())}
    result={'result':'PASS_R21_PERIODIC_LIFT_GCD_AUDIT','protocol_sha256':sha(proto),'script_sha256':sha(Path(__file__)),
            'existing_mixed_results_sha256':sha(mixedpath),'existing_source_events_sha256':sha(events),
            'new_source_execution':False,'new_native_measurements':0,'all_phase_queries_K1_to4':queries,
            'summaries':summaries,'worked_P15':worked,'cases':rows,'scientific_boundary':spec['scientific_boundary']}
    (HERE/'R21_LIFT_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:result[k] for k in ['result','all_phase_queries_K1_to4','summaries']}))
    print(json.dumps({'worked_P15':{k:v for k,v in worked.items() if k!='all_K1to4_phase_slacks'},'K2_safe_phases':[r['phi'] for r in worked['all_K1to4_phase_slacks'] if r['K']==2 and r['exact']>0]}))

if __name__=='__main__':main()
