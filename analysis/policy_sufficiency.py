"""Direct finite checks of policy-parametric equivalence and its witness criterion."""
from pathlib import Path
import hashlib,itertools,json

HERE=Path(__file__).resolve().parent

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def expiry(s,K,P,phi):
    return s+((phi-s)%P)+(K-1)*P

def completion_direct(C,J,K,P,phi):
    return min(expiry(c-J,K,P,phi)-c for c in C)

def completion_residue(C,J,K,P,phi):
    return (K-1)*P-J+min((phi+J-r)%P for r in {c%P for c in C})

def historical_direct(R,K,P,phi):
    return min(expiry(s,K,P,phi)-c for s,c in R)

def historical_profile(R,K,P,phi):
    delays={}
    for s,c in R:
        delays[s%P]=max(delays.get(s%P,-1),c-s)
    return (K-1)*P+min((phi-r)%P-j for r,j in delays.items())

def nonempty_subsets(values):
    values=tuple(values)
    for mask in range(1,1<<len(values)):
        yield tuple(v for i,v in enumerate(values) if mask&(1<<i))

def run():
    protocol=HERE/'POLICY_SUFFICIENCY_PROTOCOL.json'
    assert json.loads(protocol.read_text(encoding='utf-8'))['written_before_execution']
    counts={'completion_inputs':0,'direct_residue_queries':0,'residue_reconstructions':0,
            'distinct_set_separations':0,'historical_relations':0,'historical_phase_queries':0,
            'exactness_criterion_relations':0,'clock_components':0,'clock_policy_queries':0}
    state_classes={}
    for P in range(1,7):
        subsets=list(nonempty_subsets(range(P)))
        state_classes[str(P)]={'nonempty_residue_classes':len(subsets),
                               'minimum_fixed_binary_bits':(len(subsets)-1).bit_length()}
        for J in range(4):
            lift=(J+2)*P
            K=J+2
            for A in subsets:
                C=tuple(lift+r for r in A)
                values=[]
                for phi in range(P):
                    direct=completion_direct(C,J,K,P,phi)
                    assert direct==completion_residue(C,J,K,P,phi)
                    values.append(direct-(K-1)*P)
                    counts['direct_residue_queries']+=1
                recovered={r for r in range(P) if values[(r-J)%P]==-J}
                assert recovered==set(A)
                counts['residue_reconstructions']+=1
                counts['completion_inputs']+=1
            for A,B in itertools.combinations(subsets,2):
                residue=min(set(A)^set(B))
                phi=(residue-J)%P
                ma=completion_direct(tuple(lift+r for r in A),J,K,P,phi)
                mb=completion_direct(tuple(lift+r for r in B),J,K,P,phi)
                gap=min(ma,mb)
                assert gap>=0 and ma!=mb and (gap<ma)!=(gap<mb)
                counts['distinct_set_separations']+=1
    # Enumerate all joint relations inside each sound completion contract.
    for P in range(1,5):
        for J in range(3):
            K=J+2
            lift=(J+2)*P
            for A in nonempty_subsets(range(P)):
                C=tuple(lift+r for r in A)
                universe=tuple((c-j,c) for c in C for j in range(J+1))
                for R in nonempty_subsets(universe):
                    witnesses={c%P for s,c in R if c-s==J}
                    criterion=witnesses==set(A)
                    equal_all=True
                    for phi in range(P):
                        dr=historical_direct(R,K,P,phi)
                        mc=completion_direct(C,J,K,P,phi)
                        assert dr==historical_profile(R,K,P,phi) and dr>=mc
                        equal_all &= dr==mc
                        counts['historical_phase_queries']+=1
                    assert equal_all==criterion
                    counts['historical_relations']+=1
                    counts['exactness_criterion_relations']+=int(criterion)
    # Source-derived full-first-cell timing class; all phases, many periods.
    for p in range(1,6):
        for ell in range(1,5):
            J=(ell+1)*p-1
            for k in (2,3):
                l=1+k*p
                for length in range(2*p+1):
                    S=range(l,l+length+1)
                    R=tuple((s,p*((s+p-1)//p)+ell*p) for s in S)
                    C=tuple(sorted({c for s,c in R}))
                    assert {c for s,c in R if c-s==J}==set(C)
                    counts['clock_components']+=1
                    for P in range(1,9):
                        for phi in range(P):
                            for K in (1,J+2):
                                assert historical_direct(R,K,P,phi)==completion_direct(C,J,K,P,phi)
                                counts['clock_policy_queries']+=1
    # Fixed negative control: first cell not full, no maximum-delay witness.
    p,ell,l,u,J,P,K,phi=4,2,104,104,11,4,4,1
    R=((104,112),);C=(112,)
    mc=completion_direct(C,J,K,P,phi);dr=historical_direct(R,K,P,phi)
    assert mc==1 and dr==5 and not(2<mc) and 2<dr
    negative={'entry':[l,u],'p':p,'ell':ell,'J':J,'P':P,'K':K,'phi':phi,
              'C':list(C),'historical_delay':8,'completion_margin':mc,
              'historical_margin':dr,'gap':2,'completion_certifies':False,
              'historical_certifies':True,'maximum_delay_witness_missing':True}
    # The paper's actual full-cell entry window retains *all* policy margins.
    R=tuple((s,4*((s+3)//4)+8) for s in range(101,121));C=tuple(sorted({c for s,c in R}))
    worked=[]
    for phi in range(4):
        mc=completion_direct(C,11,4,4,phi);dr=historical_direct(R,4,4,phi)
        assert mc==dr
        worked.append({'phi':phi,'M':mc,'D':dr})
    assert [x['M'] for x in worked]==[4,1,2,3]
    result={'scope':'Finite audits of the independently derived policy-sufficiency/minimality theorems; no native or workload evidence',
            'protocol_sha256':sha(protocol),'script_sha256':sha(Path(__file__)),
            'checks':counts,'all_mismatches':0,'residue_equivalence_classes':state_classes,
            'partial_first_cell_negative_control':negative,'worked_all_phases':worked}
    (HERE/'POLICY_SUFFICIENCY_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result,indent=2))

if __name__=='__main__':
    run()
