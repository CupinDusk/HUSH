"""Canonical circular-sawtooth profile and a fair recomparison of R22 routes."""
from pathlib import Path
from collections import Counter
import hashlib,itertools,json
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def canonical(pairs,g):
    assert pairs and len({r for r,v in pairs})==len(pairs)
    return tuple(sorted((r,v) for r,v in pairs if not any(q!=r and w-v>=(r-q)%g for q,w in pairs)))
def envelope(pairs,g):return tuple(min((phi-r-1)%g-v for r,v in pairs) for phi in range(g))
def reconstruct(values):
    g=len(values)
    return tuple(sorted(((phi-1)%g,-v) for phi,v in enumerate(values) if v<values[(phi-1)%g]+1))
def finite_audit():
    reports=[]
    for g in range(1,5):
        n=0;groups={};deleted=0;necessity=0
        for ages in itertools.product([None]+list(range(2*g+2)),repeat=g):
            pairs=tuple((r,v) for r,v in enumerate(ages) if v is not None)
            if not pairs:continue
            n+=1;core=canonical(pairs,g);values=envelope(pairs,g)
            assert envelope(core,g)==values and reconstruct(values)==core
            deleted+=len(pairs)-len(core)
            for r,v in core:
                phi=(r+1)%g
                assert all((phi-r-1)%g-v<(phi-q-1)%g-w for q,w in pairs if q!=r)
                if len(core)>1:assert envelope(tuple(z for z in core if z!=(r,v)),g)!=values
                necessity+=1
            if values in groups:
                entry=groups[values];assert entry['canonical']==core
                entry['minimum_terms']=min(entry['minimum_terms'],len(pairs))
            else:groups[values]={'canonical':core,'minimum_terms':len(pairs)}
        assert all(len(v['canonical'])==v['minimum_terms'] for v in groups.values())
        reports.append({'g':g,'profiles':n,'query_equivalence_classes':len(groups),'dominated_terms_removed':deleted,'necessary_core_term_checks':necessity,'all_alternative_profiles_in_grid_share_unique_minimum':True})
    assert sum(r['profiles'] for r in reports)==15420
    return reports
def key(r):return (r['P'],r['g'],r['J'],r['A'],tuple(r['completion_residues_g']),tuple(map(tuple,r['profile_g'])))
def audit(rows):
    size_hist=Counter();exact_hist=Counter();core_hist=Counter();routes=Counter();reductions=0;before=after=0
    records=[]
    for r in rows:
        pairs=tuple(map(tuple,r['profile_g']));g=r['g'];core=canonical(pairs,g)
        assert envelope(core,g)==envelope(pairs,g) and reconstruct(envelope(pairs,g))==core
        m,w,t,k=len(r['completion_residues_g']),len(r['joint_witness_residues_g']),len(pairs),len(core)
        size_hist[(m,w,t)]+=1;core_hist[(t,k)]+=1;reductions+=k<t;before+=t;after+=k
        if r['exact']:
            witnesses=tuple(sorted(((c-r['J'])%g,r['J']+r['A']) for c in r['completion_residues_g']))
            assert core==witnesses and len(core)==m and m==w
            exact_hist[(m,w,t,k)]+=1
            routes['old_full_completion_wins']+=m+w+5<2*t+1
            routes['old_incremental_completion_wins']+=w+2<2*t+1
            routes['completion_wins_vs_canonical_pairs_full']+=m+w+5<2*k+1
            routes['completion_wins_vs_canonical_pairs_incremental']+=w+2<2*k+1
            routes['completion_ties_canonical_pairs_incremental']+=w+2==2*k+1
            assert m+w+5>m+2 # canonical common-span encoding: m residues+span+length
        records.append({'key':key(r),'exact_completion':r['exact'],'canonical_profile':core,'unpruned_terms':t,'canonical_terms':k})
    def hist(c):return [{'sizes':list(k),'interfaces':v} for k,v in sorted(c.items())]
    result={'interfaces':len(rows),'original_m_w_t_distribution':hist(size_hist),'exact_m_w_t_core_distribution':hist(exact_hist),
      't_to_core_distribution':hist(core_hist),'profiles_reduced':reductions,'original_terms':before,'canonical_terms':after,
      'routing_comparison':dict(routes),'context_aware_exact_route_information_advantage':False,'cases':records}
    assert routes['completion_wins_vs_canonical_pairs_full']==0 and routes['completion_wins_vs_canonical_pairs_incremental']==0
    assert all(k[0]==k[1]==k[3]==1 for k in exact_hist)
    return result
def main():
    out=HERE/'R23_CANONICAL_RESULTS.json';assert not out.exists()
    source=HERE/'R21_LIFT_RESULTS.json';oldhandoff=HERE/'R22_HANDOFF_RESULTS.json'
    rows=json.loads(source.read_text(encoding='utf-8'))['cases'];distinct={key(r):r for r in rows}
    assert len(rows)==11904 and len(distinct)==2510
    reports={'raw':audit(rows),'distinct':audit(list(distinct.values()))}
    old=json.loads(oldhandoff.read_text(encoding='utf-8'))
    for label,oldlabel in [('raw','raw_cycle_period'),('distinct','deduplicated_interface')]:
        assert reports[label]['routing_comparison']['old_full_completion_wins']==old['reports'][oldlabel]['routing']['complete_new']['completion']
        assert reports[label]['routing_comparison']['old_incremental_completion_wins']==old['reports'][oldlabel]['routing']['existing_completion']['completion']
    toy=((0,3),(2,3));assert canonical(toy,5)==toy and reconstruct(envelope(toy,5))==toy
    result={'result':'PASS_CANONICAL_PROFILE_AND_CORRECTED_ROUTING','protocol_sha256':sha(HERE/'R23_CANONICAL_PROTOCOL.json'),
      'argument_sha256':sha(HERE/'R23_CANONICAL_ARGUMENT.md'),'script_sha256':sha(Path(__file__)),'input_lift_sha256':sha(source),'input_old_handoff_sha256':sha(oldhandoff),
      'finite_profile_audit':finite_audit(),'reports':reports,'synthetic_two_term_exact_profile':{'pairs':toy,'g':5,'query_vector':envelope(toy,5)},
      'new_native_measurements':0,'new_source_execution':False,'scope':'unique minimum term profile within this observer family; no intrinsic completion-payload saving over a fair reduced/context-aware comparator'}
    out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'result':result['result'],'finite':result['finite_profile_audit'],'reports':{label:{k:v for k,v in r.items() if k not in ['cases','original_m_w_t_distribution','exact_m_w_t_core_distribution','t_to_core_distribution']} for label,r in reports.items()},'exact_compressed_m_values':sorted({x['sizes'][0] for x in reports['distinct']['exact_m_w_t_core_distribution']})},indent=2))
if __name__=='__main__':main()
