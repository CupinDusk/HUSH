"""Second algorithm: count decrement events, not expiry slacks/profile algebra.

Validate every exported physical-policy status and aggregate. In addition,
enumerate all optional-WU successor states for each distinct minimizing-edge
configuration. Memoization here avoids repeating mathematical checks and is
not included in any performance/cost comparison.
"""
from pathlib import Path
from collections import Counter
from functools import lru_cache
import gzip, hashlib, json, math

HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

@lru_cache(None)
def all_wu_words_safe(span,P,relphi,K):
    states={(True,False,0)}
    for dt in range(1,span+1):
        new=set()
        for valid,enabled,count in states:
            for wu in (0,1):
                v,e,k=valid,enabled,count
                if wu and v:e,k=True,K
                if e and dt%P==relphi:
                    k-=1
                    if not k:v,e=False,False
                new.add((v,e,k))
        states=new
    return all(v for v,e,k in states)

def positive(n,nK):return max(0,nK-n)
def tally(np,nr,ncr,nseg,nglobal,P,support,nK):
    pf,pr,pp=positive(max(np,nr),nK),positive(nr,nK),positive(np,nK)
    ps,pt,pg=positive(max(np,ncr),nK),positive(nseg,nK),positive(nglobal,nK)
    return {'policy_queries':nK,'exact_prefix_positive':pp,
        'recurrent_service_positive':pr,'recurrent_service_unknown':nK-pr,
        'full_service_positive':pf,'full_service_unknown':nK-pf,
        'recurrent_positive_but_prefix_rejects':pr-pf,
        'prefix_positive_but_recurrence_rejects':pp-pf,
        'both_prefix_and_recurrence_reject':nK-pp-pr+pf,
        'full_shared_prefix_completion_positive':ps,'full_shared_prefix_completion_unknown':nK-ps,
        'full_service_only_vs_shared_completion':pf-ps,
        'full_segment_tight_completion_positive':pt,'full_service_only_vs_segment_completion':pf-pt,
        'full_global_completion_positive':pg,'full_service_only_vs_global_completion':pf-pg,
        'supported_queries':nK if support else 0,'unsupported_queries':0 if support else nK,
        'supported_full_service_positive':pf if support else 0,
        'supported_full_service_unknown':nK-pf if support else 0,
        'supported_full_service_only_vs_shared_completion':pf-ps if support else 0,
        'unsupported_full_service_positive_needs_fallback':0 if support else pf,
        'unsupported_service_only_vs_shared_completion_needs_fallback':0 if support else pf-ps}

def main():
    out=HERE/'INDEPENDENT_VALIDATION.json';assert not out.exists()
    result_path=HERE/'RESULTS.json';result=json.loads(result_path.read_text(encoding='utf-8'))
    recs={r['case_id']:r for r in result['records']}
    reports={g:{s:Counter() for s in ('all','nonempty_prefix','empty_prefix')} for g in ('primary','expanded')}
    checked=Counter();interfaces=set()
    with gzip.open(HERE/'ALL_PHASE_BASES.jsonl.gz','rt',encoding='utf-8') as f:
        schema=json.loads(next(f));assert 'schema' in schema
        for line in f:
            row=json.loads(line);r=recs[row['case_id']];P=row['P'];m=math.gcd(P,r['d'])
            key=(r['case_id'],P);assert key not in interfaces;interfaces.add(key)
            assert row['m']==m and row['supported']==(r['g']%m==0)
            assert len(row['rows'])==P
            cyc=r['cycle_triples'];pre=r['prefix_triples'];b=r['bounds']
            # Count periodic decrement events in each (s,h] directly. This
            # algorithm never evaluates F or canonical/profile projections.
            expanded=[(s+n*r['d'],c+n*r['d'],h+n*r['d'])
                      for s,c,h in cyc for n in range(P//m)]
            for phi,vals in enumerate(row['rows']):
                ep,er,drec,full,shared,segment,global_,sw,hw=vals
                ndecr=lambda s,h:(h-phi)//P-(s-phi)//P
                np=max((ndecr(s,h) for s,c,h in pre),default=0)
                nr=max(ndecr(s,h) for s,c,h in expanded)
                ncr=max(ndecr(c-b['recurrent_J'],c+b['recurrent_A']) for s,c,h in expanded)
                ncp=max((ndecr(c-b['prefix_J'],c+b['prefix_A']) for s,c,h in pre),default=0)
                ngp=max((ndecr(c-b['global_J'],c+b['global_A']) for s,c,h in pre),default=0)
                ngr=max(ndecr(c-b['global_J'],c+b['global_A']) for s,c,h in expanded)
                nf,ns,nt,ng=max(np,nr),max(np,ncr),max(ncp,ncr),max(ngp,ngr)
                assert nf<=ns<=nt<=ng
                for K in range(1,6):
                    B=(K-1)*P
                    assert (ep is None or ep+B>0)==(K>np)
                    assert (er+B>0)==(K>nr)
                    assert (drec+B>0)==(K>ncr)
                    assert (full+B>0)==(K>nf)
                    assert (shared+B>0)==(K>ns)
                    assert (segment+B>0)==(K>nt)
                    assert (global_+B>0)==(K>ng)
                    assert all_wu_words_safe(hw-sw,P,(phi-sw)%P,K)==(full+B>0)
                    checked['phase_load_statuses']+=1
                checked['phase_rows']+=1
                for name,nK in (('primary',2),('expanded',5)):
                    if name=='primary' and P>2*r['p']:continue
                    values=tally(np,nr,ncr,nt,ng,P,row['supported'],nK)
                    for st in ('all','nonempty_prefix' if pre else 'empty_prefix'):
                        reports[name][st].update(values)
                    checked['physical_queries']+=nK
            if len(interfaces)%10000==0:print(json.dumps({'interfaces_checked':len(interfaces),'dp_unique':all_wu_words_safe.cache_info().currsize}),flush=True)
    for name,strata in reports.items():
        for st,c in strata.items():
            assert dict(c)==result['grids'][name][st],(name,st,c,result['grids'][name][st])
    expected={(r['case_id'],P) for r in recs.values() for P in range(1,4*r['p']+1)}
    assert interfaces==expected
    final={'result':'PASS_INDEPENDENT_DECREMENT_EVENT_COUNTS_AND_ALL_WU_STATE_DP',
           'results_sha256':sha(result_path),'script_sha256':sha(Path(__file__)),
           'phase_bases_sha256':sha(HERE/'ALL_PHASE_BASES.jsonl.gz'),
           'checks':dict(checked),'interfaces':len(interfaces),
           'all_wu_dp_distinct_configs':all_wu_words_safe.cache_info().currsize,
           'all_wu_dp_cache_info':str(all_wu_words_safe.cache_info()),
           'scope':'Independent event-count algorithm validates every exported admission status/aggregate. Finite successor-state DP covers every optional WU word in each distinct minimizing-edge configuration; source/control closure and general first-failure induction are separately stated in ARGUMENT.md. This is mathematical corroboration, not source/native execution or a performance comparison.'}
    out.write_text(json.dumps(final,indent=2)+'\n',encoding='utf-8');print(json.dumps(final,indent=2))

if __name__=='__main__':main()
