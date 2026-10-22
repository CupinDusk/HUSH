"""Actual-slack witness iff, mixed-client load bound and deduplicated decisions."""
from pathlib import Path
from itertools import combinations
import hashlib,json,math
from source_producer import expiry
from read_boundary import margin,tick_reads,arm_reads
HERE=Path(__file__).resolve().parent


def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()


def subsets(items):
    for size in range(1,len(items)+1):yield from combinations(items,size)


def actual_profile(R,K,P,phi):
    omega={}
    for s,c,h in R:omega[s%P]=max(omega.get(s%P,-1),h-s)
    return (K-1)*P+1+min((phi-r-1)%P-w for r,w in omega.items())


def main():
    spec=json.loads((HERE/'JOINT_WITNESS_PROTOCOL.json').read_text(encoding='utf-8'))
    totals={'triple_relations':0,'phase_load_queries':0,'all_policy_equal_relations':0,'disagreements':0}
    for P in range(1,4):
        for J in range(2):
            for A in range(2):
                lift=(J+A+2)*P
                for residues in subsets(tuple(range(P))):
                    C=tuple(lift+r for r in residues)
                    candidates=tuple((c-j,c,c+a) for c in C for j in range(J+1) for a in range(A+1))
                    for R in subsets(candidates):
                        witness={c%P for s,c,h in R if c-s==J and h-c==A}==set(residues);equal=True
                        for phi in range(P):
                            for K in (1,J+A+2):
                                abstract=margin(C,J,K,P,phi)-A
                                exact=min(expiry(s+1,K,P,phi)-h for s,c,h in R)
                                assert exact==actual_profile(R,K,P,phi) and exact>=abstract
                                equal &= exact==abstract;totals['phase_load_queries']+=1
                        assert equal==witness;totals['triple_relations']+=1;totals['all_policy_equal_relations']+=int(equal)
    example=spec['predicted_nonjoint_example'];R=example['triples'];m=margin(example['C'],3,2,4,2)
    exact=min(expiry(s+1,2,4,2)-h for s,c,h in R)
    assert (m,m-3,exact)==(2,-1,2)
    mixed=HERE/'MIXED_POLL_RESULTS.json';old=json.loads(mixed.read_text(encoding='utf-8'))
    unique={};unique_interfaces=set();raw=0;load_checks=0;gain_configs=0
    keys=['RP','PP','RU','history','actual_phase','strong_service_uniform','gain_both','gain_strong_uniform']
    def outcome(C,J,G,R,K,P,phi):
        base=(K-1)*P;M=margin(C,J,K,P,phi);PP=expiry(min(C)-J+1,K,P,phi)-max(C);RU=base-J+1
        exact=min(expiry(s+1,K,P,phi)-h for s,c,h in R)
        gmax=max(h-s for s,c,h in R)
        rp=G<M;pp=G<PP;ru=G<RU;hp=G<min(expiry(s+1,K,P,phi)-c for s,c,h in R);ap=exact>0;su=gmax<base+1
        return (rp,pp,ru,hp,ap,su,rp and not pp and not ru,rp and not su)
    for row in old['cycles']:
        P,J,G=(row[k] for k in ['p','J','G']);R=tuple(map(tuple,row['cycle']));C=tuple(c for s,c,h in R)
        omega={}
        for s,c,h in R:omega[s%P]=max(omega.get(s%P,-1),h-s)
        basekey=(P,J,G,tuple(sorted(c-min(C) for c in C)),tuple(sorted(omega.items())))
        unique_interfaces.add(basekey);n=J+G;best=1+n//P;uniform=1+math.ceil(n/P)
        expected_safe_phases={phi for phi in range(P) if (phi+J-1)%P>=n%P}
        observed={phi for phi in range(P) if min(expiry(s+1,best,P,phi)-h for s,c,h in R)>0}
        assert observed==expected_safe_phases
        assert not any(min(expiry(s+1,best-1,P,phi)-h for s,c,h in R)>0 for phi in range(P))
        assert uniform-best==int(n%P!=0);load_checks+=1;gain_configs+=int(uniform>best)
        for K in range(1,n+3):
            for phi in range(P):
                result=outcome(C,J,G,R,K,P,phi);signature=basekey+(K,phi)
                if signature in unique:assert unique[signature]==result
                else:unique[signature]=result
                raw+=1
    assert raw==old['counts']['policy_queries']==118083
    dedup={k:sum(v[i] for v in unique.values()) for i,k in enumerate(keys)}
    assert dedup['RP']==dedup['history']==dedup['actual_phase']
    assert dedup['RU']==dedup['strong_service_uniform']
    controls={}
    for phi,expected in [(2,28),(3,28)]:
        one=tick_reads((3,11,28,36),(12,),4,5,phi,trace=True);two=arm_reads((3,11,28,36),(12,),4,5,phi)
        assert one['reads']==two['reads'] and one['first_miss']==two['first_miss']==expected
        controls[str(phi)]=one
    result={'result':'PASS_JOINT_SLACK_WITNESSES_AND_POLICY_DECISIONS','scope':spec['scope'],
        'protocol_sha256':sha(HERE/'JOINT_WITNESS_PROTOCOL.json'),'script_sha256':sha(Path(__file__)),
        'mixed_source_result_sha256':sha(mixed),'counts':totals,'nonjoint_example':example,
        'mixed_load_bound_checks':load_checks,'mixed_configs_with_one_count_gain':gain_configs,
        'raw_policy_queries':raw,'unique_compared_interfaces':len(unique_interfaces),'unique_policy_queries':len(unique),
        'unique_certification_counts':dedup,'main_safe_phases':[0,1,4],'controls':controls}
    (HERE/'JOINT_WITNESS_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:result[k] for k in ['result','counts','mixed_load_bound_checks','mixed_configs_with_one_count_gain','raw_policy_queries','unique_compared_interfaces','unique_policy_queries','unique_certification_counts','main_safe_phases']}))


if __name__=='__main__':main()
