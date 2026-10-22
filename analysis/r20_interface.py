"""Actual-slack fallback, source-trace branch census and analytical handoff counts."""
from pathlib import Path
from collections import Counter
import hashlib,json
from source_producer import expiry
from read_boundary import margin,tick_reads,arm_reads,checked_step
HERE=Path(__file__).resolve().parent

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

def profile(T,P):
    out={}
    for s,c,h in T:out[s%P]=max(out.get(s%P,-1),h-s)
    return out

def exact_profile(T,K,P,phi):
    nu=profile(T,P)
    return (K-1)*P+1+min((phi-r-1)%P-v for r,v in nu.items())

def handoff(T,C,J,A,P):
    residues=sorted({c%P for c in C})
    witnesses=sorted({c%P for s,c,h in T if c-s==J and h-c==A})
    return {'period':P,'J':J,'A':A,'completion_residues':residues,'joint_witness_residues':witnesses,
            'producer_attested_exact':residues==witnesses,
            'identity_epoch_horizon_binding':'required trusted contract, not independent reachability proof'}

def consume(payload,K,phi):
    assert payload['producer_attested_exact'] and payload['completion_residues']==payload['joint_witness_residues']
    value=margin(payload['completion_residues'],payload['J'],K,payload['period'],phi)-payload['A']
    return {'actual_slack_if_contract_holds':value,'query_terms':len(payload['completion_residues'])}

def main():
    spec=json.loads((HERE/'R20_INTERFACE_PROTOCOL.json').read_text(encoding='utf-8'))
    mixed=json.loads((HERE/'MIXED_POLL_RESULTS.json').read_text(encoding='utf-8'))
    periodic=json.loads((HERE/'PERIODIC_POLL_RESULTS.json').read_text(encoding='utf-8'))
    mpath=HERE/'mixed-poll-build/events.json';ppath=HERE/'periodic-poll-build/events.json'
    assert sha(mpath)==mixed['source_events_sha256'] and sha(ppath)==periodic['events_sha256']
    mrows=json.loads(mpath.read_text(encoding='utf-8'));prows=json.loads(ppath.read_text(encoding='utf-8'))
    source={(r['p'],r['ell'],r['s0'],r['q']):r for r in mrows};census=Counter();phase_counts=Counter();checked=0
    for r in mixed['cycles']:
        key=tuple(r[n] for n in ['p','ell','s0','q']);raw=source[key];T=tuple(map(tuple,r['cycle']))
        observed=list(zip(raw['services'],raw['receipts'],raw['services'][1:]))
        assert all(v in observed for v in T)
        branches={'response_first' if c<s+r['q'] else 'wait' for s,c,h in T}
        assert all(c!=s+r['q'] for s,c,h in T)
        for s,c,h in T:assert h==(s+r['q'] if c<s+r['q'] else c+r['q'])
        census['both_branches' if len(branches)==2 else 'wait_only' if branches=={'wait'} else 'response_only']+=1
        phase_counts[len({s%r['p'] for s,c,h in T})]+=1;checked+=1
    assert checked==372 and census=={'both_branches':90,'wait_only':282}
    worked={};queries=histories=0
    for name in ['mixed_multiresidue_example','slow_poll_fallback_example']:
        s=spec[name];T=tuple(map(tuple,s['triples']));C=tuple(c for a,c,h in T);K,P,phi,J,A=(s[n] for n in ['K','P','phi','J','A'])
        raw=next(r for r in (mrows if name.startswith('mixed') else prows) if all(r[n]==s[n] for n in ['p','ell','q','s0']))
        observed=list(zip(raw['services'],raw['receipts'],raw['services'][1:]));assert all(t in observed for t in T)
        assert s['shift']%P==0
        assert J==max(c-a for a,c,h in T) and A==max(h-c for a,c,h in T)
        payload=handoff(T,C,J,A,P)
        assert payload['completion_residues']==s['completion_residues'] and payload['joint_witness_residues']==s['joint_witness_residues']
        nu=profile(T,P);assert {str(k):v for k,v in nu.items()}==s['profile']
        M=margin(C,J,K,P,phi);D=M-A;exact=min(expiry(a+1,K,P,phi)-h for a,c,h in T)
        assert (M,D,exact)==(s['M'],s['D'],s['actual_slack'])
        equality=True
        for load in range(1,5):
            for phase in range(P):
                direct=min(expiry(a+1,load,P,phase)-h for a,c,h in T)
                abstract=margin(C,J,load,P,phase)-A
                assert direct==exact_profile(T,load,P,phase) and direct>=abstract
                equality &= direct==abstract;queries+=1
        assert equality==payload['producer_attested_exact']
        count=miss=0
        for a,c,h in T:
            n,m=checked_step(a,h,K,P,phi);count+=n;miss+=m
        assert miss==0;histories+=count
        worked[name]={'triples':T,'handoff':payload,'M':M,'D':D,'actual_slack':exact,'service_span_profile':nu,
            'exact_profile_query_terms':len(nu),'completion_query_terms':len(payload['completion_residues']),
            'source_triples_scanned':len(T),'local_histories':count,'local_misses':miss,'consumer_returns':'unknown_then_profile' if not payload['producer_attested_exact'] else consume(payload,K,phi)}
    mainT=((3,10,11),(11,20,28));main=handoff(mainT,(10,20),9,8,5);out=consume(main,4,0)
    assert out=={'actual_slack_if_contract_holds':2,'query_terms':1}
    operation={'main_P5':{'N':2,'completion_query_terms':1,'exact_profile_query_terms':len(profile(mainT,5))},
        'main_P25':{'N':2,'completion_query_terms':2,'exact_profile_query_terms':2},
        'slow_P9':{'N':4,'completion_query_terms':4,'exact_profile_query_terms':1},'measured_cost_savings':False}
    result={'result':'PASS_R20_EXISTING_TRACE_INTERFACE_AUDIT','scope':spec['scientific_boundary'],
        'protocol_sha256':sha(HERE/'R20_INTERFACE_PROTOCOL.json'),'script_sha256':sha(Path(__file__)),
        'mixed_source_events_sha256':sha(mpath),'slow_source_events_sha256':sha(ppath),
        'new_source_execution':False,'new_native_measurements':0,'recurrent_branch_counts':dict(census),
        'populated_service_phase_count_histogram':dict(phase_counts),'worked_examples':worked,
        'phase_load_queries':queries,'local_histories':histories,'operation_accounting':operation,
        'main_handoff':main,'main_consumer':out}
    (HERE/'R20_INTERFACE_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:result[k] for k in ['result','recurrent_branch_counts','populated_service_phase_count_histogram','phase_load_queries','local_histories','operation_accounting']}))

if __name__=='__main__':main()
