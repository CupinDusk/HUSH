"""Exact operation accounting; preprocessing and query units stay separate."""
from pathlib import Path
from collections import Counter
from fractions import Fraction
import hashlib,json,math,sys
HERE=Path(__file__).resolve().parent
OLD=HERE
EXPECTED=HERE.parent/'expected'
sys.path.insert(0,str(OLD))
from r23_canonical import canonical
from r26_remod import profile
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def sparse(events,g):
    pairs=profile(events,g);w=[r+v for r,v in pairs];n=len(w)
    before=[];v=-math.inf
    for x in w:before.append(v);v=max(v,x)
    after=[-math.inf]*n;v=-math.inf
    for i in range(n-1,-1,-1):after[i]=v;v=max(v,w[i])
    ans=tuple(pairs[i] for i in range(n) if w[i]>before[i] and w[i]+g>after[i])
    assert ans==canonical(pairs,g)
    return ans
def main():
    out=HERE/'QUERY_COST_RESULTS.json';assert not out.exists()
    prior=EXPECTED/'R30_PRODUCER_FAMILY_RESULTS.json';agg=EXPECTED/'R35_FAMILY_AGGREGATE_RESULTS.json'
    records=json.loads(prior.read_text(encoding='utf-8'))['records']
    total=Counter();rows=[];byraw={}
    for rec in records:
        if not rec['admitted']:continue
        T=tuple(map(tuple,rec['cycle']));d=rec['translation'];p=rec['p'];g=d//math.gcd(d,3)
        events=[(s,h-s) for s,c,h in T]
        master=sparse(events,d);small=sparse(master,g)
        assert master==tuple(map(tuple,rec['master_pairs']))
        cache={};ctr=Counter(master_build_input_visits=len(T),compact_build_input_visits=len(master))
        for P in range(1,4*p+1):
            m=math.gcd(P,d);supported=g%m==0
            if m not in cache:
                Q=sparse(master,m);direct=sparse(events,m);assert Q==direct
                ctr['master_projection_input_visits']+=len(master)
                source=small if supported else master
                Qc=sparse(source,m);assert Qc==Q
                ctr['compact_projection_input_visits']+=len(source)
                ctr['distinct_target_moduli']+=1;ctr['projected_output_terms']+=len(Q)
                cache[m]=Q
            Q=cache[m]
            for phi in range(P):
                exact=1+min((phi-s-1)%m-(h-s) for s,c,h in T)
                compressed=1+min((phi-r-1)%m-v for r,v in Q)
                assert exact==compressed
                for K in range(1,6):
                    assert (K-1)*P+exact==(K-1)*P+compressed
                    ctr['queries']+=1;ctr['direct_query_terms']+=len(T)
                    ctr['profile_query_terms']+=len(Q)
                    ctr['supported_queries' if supported else 'fallback_queries']+=1
        assert ctr['profile_query_terms']<=ctr['direct_query_terms']
        row=dict(case_id=rec['case_id'],p=p,q=rec['q'],s0=rec['s0'],d=d,g=g,
                 raw_terms=len(T),master_terms=len(master),compact_terms=len(small),
                 query_term_ratio=str(Fraction(ctr['profile_query_terms'],ctr['direct_query_terms'])),**dict(ctr))
        rows.append(row);total.update(ctr)
        b=byraw.setdefault(len(T),Counter(entries=0));b['entries']+=1;b.update(ctr)
    expected=json.loads(agg.read_text(encoding='utf-8'))['grids']['expanded']['counts']
    assert total['queries']==expected['policy_queries']==6277660
    assert total['supported_queries']==expected['supported_policy_queries']
    ratios=sorted(Fraction(r['query_term_ratio']) for r in rows);n=len(rows)
    summary=dict(total= dict(total),entries=n,
       profile_over_direct_query_term_ratio=str(Fraction(total['profile_query_terms'],total['direct_query_terms'])),
       per_entry_query_term_ratio=dict(min=str(ratios[0]),median=str((ratios[(n-1)//2]+ratios[n//2])/2),max=str(ratios[-1])),
       entries_query_fewer=sum(r['profile_query_terms']<r['direct_query_terms'] for r in rows),
       entries_query_tie=sum(r['profile_query_terms']==r['direct_query_terms'] for r in rows),
       entries_query_more=sum(r['profile_query_terms']>r['direct_query_terms'] for r in rows),
       entries_compact_fewer=sum(r['compact_terms']<r['master_terms'] for r in rows),
       master_terms=sum(r['master_terms'] for r in rows),compact_terms=sum(r['compact_terms'] for r in rows),
       by_raw_terms=[dict(raw_terms=k,**dict(v)) for k,v in sorted(byraw.items())])
    result=dict(result='PASS_COMPLETE_EXPANDED_GRID_EXACT_OPERATION_ACCOUNTING',
       protocol_sha256=sha(HERE/'QUERY_COST_PROTOCOL.json'),script_sha256=sha(Path(__file__)),
       input_sha256={p.name:sha(p) for p in [prior,agg]},summary=summary,records=rows,
       scope=json.loads((HERE/'QUERY_COST_PROTOCOL.json').read_text())['nonclaims'])
    out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(summary,indent=2))
if __name__=='__main__':main()
