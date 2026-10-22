"""Exhaustive full-policy admission, with an identical exact prefix in both routes.

Only existing mathematical relations are reanalyzed. No native executable,
historical launcher, remote access, timing benchmark, or result memoization.
All physical-query outcomes are recoverable from compressed phase-base rows.
"""
from pathlib import Path
from collections import Counter
import gzip, hashlib, json, math, sys

HERE = Path(__file__).resolve().parent
PACKAGE = HERE.parents[1]
OLD = PACKAGE / 'expected'
sys.path.insert(0, str(PACKAGE / 'analysis'))
from r23_canonical import canonical
from r26_remod import profile, project


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def source_relation(p, q, s0):
    """Independent finite phase-map reconstruction; no old producer import."""
    seen, rows, s = {}, [], s0
    while s % p not in seen:
        seen[s % p] = len(rows)
        # Find first p-boundary at/after s by stepping, not ceil formula.
        transfer = s
        while transfer % p:
            transfer += 1
        c = transfer + p
        if c == s + q:
            # Keep the original rejected record's nominal late-branch h;
            # equality itself is rejected, so no actual next service is asserted.
            return {'admitted': False, 'tie': [s, c, c+q], 'poll': s+q}
        h = s+q if c < s+q else c+q
        rows.append([s, c, h])
        s = h
    cut = seen[s % p]
    return {'admitted': True, 'prefix': rows[:cut], 'cycle': rows[cut:],
            'translation': s-rows[cut][0]}


def positive_mask(base, P, nK):
    if base is None:  # +infinity, empty prefix
        return (1 << nK)-1
    first = 1 if base > 0 else (-base)//P+2
    return 0 if first > nK else ((1 << nK)-1) ^ ((1 << (first-1))-1)


def lower(a, b):
    return b if a is None else a if b is None else min(a, b)


def bump(counts, bases, P, phi, support, nK):
    pre, rec, drec, full, shared, segment, global_ = bases
    all_ = (1 << nK)-1
    mp, mr, mf, ms, mt, mg = [positive_mask(v, P, nK)
                             for v in (pre, rec, full, shared, segment, global_)]
    vals = {
        'policy_queries': nK,
        'exact_prefix_positive': mp.bit_count(),
        'recurrent_service_positive': mr.bit_count(),
        'recurrent_service_unknown': (all_ ^ mr).bit_count(),
        'full_service_positive': mf.bit_count(),
        'full_service_unknown': (all_ ^ mf).bit_count(),
        'recurrent_positive_but_prefix_rejects': (mr & (all_ ^ mp)).bit_count(),
        'prefix_positive_but_recurrence_rejects': (mp & (all_ ^ mr)).bit_count(),
        'both_prefix_and_recurrence_reject': ((all_ ^ mp) & (all_ ^ mr)).bit_count(),
        'full_shared_prefix_completion_positive': ms.bit_count(),
        'full_shared_prefix_completion_unknown': (all_ ^ ms).bit_count(),
        'full_service_only_vs_shared_completion': (mf & (all_ ^ ms)).bit_count(),
        'full_segment_tight_completion_positive': mt.bit_count(),
        'full_service_only_vs_segment_completion': (mf & (all_ ^ mt)).bit_count(),
        'full_global_completion_positive': mg.bit_count(),
        'full_service_only_vs_global_completion': (mf & (all_ ^ mg)).bit_count(),
        'supported_queries': nK if support else 0,
        'unsupported_queries': 0 if support else nK,
        'supported_full_service_positive': mf.bit_count() if support else 0,
        'supported_full_service_unknown': (all_ ^ mf).bit_count() if support else 0,
        'supported_full_service_only_vs_shared_completion': (mf & (all_ ^ ms)).bit_count() if support else 0,
        'unsupported_full_service_positive_needs_fallback': 0 if support else mf.bit_count(),
        'unsupported_service_only_vs_shared_completion_needs_fallback': 0 if support else (mf & (all_ ^ ms)).bit_count(),
    }
    assert mf == (mp & mr)
    assert mg & ~mt == mt & ~ms == ms & ~mf == 0
    counts.update(vals)
    return vals


def check_counter_witness(s, h, P, phi, full_base):
    """One WU immediately after a hit; literal tick/decrement simulation.

    Each K is monotone. Count the decrement events, then test all five loads.
    No formula F or modulo-reduced profile is used to predict event count.
    No earlier WU is needed, so every earlier read hits the initially valid tag.
    """
    decrements = 0
    for tick in range(s+1, h+1):
        if tick % P == phi:
            decrements += 1
    for K in range(1, 6):
        count, valid, enabled = K, True, True  # valid-only WU at s+1
        # This event loop is the literal enabled decrement transition;
        # steps after invalidity cannot resurrect the line.
        for _ in range(decrements):
            if enabled:
                count -= 1
                if count == 0:
                    enabled, valid = False, False
        assert valid == ((K-1)*P + full_base > 0)
    return decrements


def main():
    out, phase_path = HERE/'RESULTS.json', HERE/'ALL_PHASE_BASES.jsonl.gz'
    assert not out.exists() and not phase_path.exists(), 'Preserve previous evidence; use a new directory for a new run.'
    proto = HERE/'PROTOCOL.json'
    assert json.loads(proto.read_text(encoding='utf-8'))['status'].startswith('prospective_')
    input_path = OLD/'R30_PRODUCER_FAMILY_RESULTS.json'
    prior = json.loads(input_path.read_text(encoding='utf-8'))
    r35_path = OLD/'R35_FAMILY_AGGREGATE_RESULTS.json'
    r35 = json.loads(r35_path.read_text(encoding='utf-8'))
    grids = {g: {s: Counter() for s in ('all', 'nonempty_prefix', 'empty_prefix')}
             for g in ('primary', 'expanded')}
    counts, records, rejected = Counter(), [], []
    checks = Counter()
    diagnostic_examples = {}
    with gzip.open(phase_path, 'wt', encoding='utf-8', newline='\n', compresslevel=9) as f:
        f.write(json.dumps({'schema': 'For each P, list rows in phi=0..P-1 order. Each row is [exact_prefix_base_or_null_inf,recurrent_exact_base,recurrent_completion_base,full_exact_base,shared_exact_prefix_completion_base,segment_tight_completion_base,global_completion_base,witness_s,witness_h]. Add (K-1)*P to every finite base. Fields preserve all negative and zero outcomes. No query timing is measured.'})+'\n')
        for old in prior['records']:
            p, q, s0 = old['p'], old['q'], old['s0']
            new = source_relation(p, q, s0)
            assert new['admitted'] == old['admitted']
            if not old['admitted']:
                assert new['tie'] == old['tie']
                rejected.append({'p': p, 'q': q, 's0': s0, 'tie': new['tie']})
                counts['timing_tie_rejected'] += 1
                continue
            T, pre, d = new['cycle'], new['prefix'], new['translation']
            assert (pre, T, d) == (old['prefix'], old['cycle'], old['translation'])
            case_id = old['case_id']
            g = d//math.gcd(d, 3)
            Jr = max(c-s for s,c,h in T)
            Ar = max(h-c for s,c,h in T)
            Jall = max(c-s for s,c,h in T+pre)
            Aall = max(h-c for s,c,h in T+pre)
            Jp = max((c-s for s,c,h in pre), default=None)
            Ap = max((h-c for s,c,h in pre), default=None)
            Cpre = sorted({c for s,c,h in pre})
            C0 = sorted({c for s,c,h in T})
            master = canonical(profile([(s,h-s) for s,c,h in T], d), d)
            assert master == tuple(map(tuple, old['master_pairs']))
            stored = project(master, g)
            local = {name: Counter() for name in grids}
            strata = ['all', 'nonempty_prefix' if pre else 'empty_prefix']
            counts['timing_admitted_sources'] += 1
            counts['nonempty_prefix_sources'] += bool(pre)
            counts['prefix_edges'] += len(pre)
            counts['recurrent_edges'] += len(T)
            counts['global_J_exceeds_recurrent_J'] += Jall > Jr
            counts['global_A_exceeds_recurrent_A'] += Aall > Ar
            for P in range(1, 4*p+1):
                m = math.gcd(P, d)
                supported = g % m == 0
                Q = project(master, m)
                if supported:
                    assert project(stored, m) == Q
                # Explicit finite orbit representatives, using physical P.
                copies = [(s+n*d, c+n*d, h+n*d)
                          for s,c,h in T for n in range(P//m)]
                completions = sorted({c+n*d for c in C0 for n in range(P//m)})
                phase_rows = []
                for phi in range(P):
                    rec_candidates = [(s+1+(phi-s-1)%P-h, s, h)
                                      for s,c,h in copies]
                    rec, sr, hr = min(rec_candidates)
                    from_profile = 1+min((phi-r-1)%m-v for r,v in Q)
                    assert rec == from_profile
                    checks['explicit_recurrence_phases'] += 1
                    drec = 1-Jr-Ar+min((phi+Jr-1-c)%P for c in completions)
                    assert drec == 1-Jr-Ar+min((phi+Jr-1-c)%m for c in C0)
                    assert drec <= rec
                    if pre:
                        prefix_candidates = [(s+1+(phi-s-1)%P-h,s,h)
                                             for s,c,h in pre]
                        ep, sp, hp = min(prefix_candidates)
                        dp = 1-Jp-Ap+min((phi+Jp-1-c)%P for c in Cpre)
                        dgp = 1-Jall-Aall+min((phi+Jall-1-c)%P for c in Cpre)
                        assert dgp <= dp <= ep
                        full, sw, hw = min((ep,sp,hp),(rec,sr,hr))
                    else:
                        ep = dp = dgp = None
                        full, sw, hw = rec, sr, hr
                    dgr = 1-Jall-Aall+min((phi+Jall-1-c)%P for c in completions)
                    shared, segment, global_ = lower(ep,drec), lower(dp,drec), lower(dgp,dgr)
                    assert global_ <= segment <= shared <= full
                    ndecr = check_counter_witness(sw, hw, P, phi, full)
                    checks['literal_counter_minimizer_load_checks'] += 5
                    checks['literal_counter_minimizer_phase_checks'] += 1
                    bases = (ep,rec,drec,full,shared,segment,global_)
                    phase_rows.append([*bases,sw,hw])
                    for name in grids:
                        if name == 'primary' and P > 2*p:
                            continue
                        nK = 2 if name == 'primary' else 5
                        v = bump(local[name], bases, P, phi, supported, nK)
                        for st in strata:
                            grids[name][st].update(v)
                        checks['physical_policy_queries'] += nK
                        for label, test in (
                            ('recurrent_positive_prefix_rejection', v['recurrent_positive_but_prefix_rejects']),
                            ('full_service_only_shared_prefix', v['full_service_only_vs_shared_completion']),
                            ('diagnostic_segment_weaker_than_shared', v['full_shared_prefix_completion_positive']-v['full_segment_tight_completion_positive']),
                            ('diagnostic_global_weaker_than_segment', v['full_segment_tight_completion_positive']-v['full_global_completion_positive'])):
                            if test and label not in diagnostic_examples:
                                for K in range(1,nK+1):
                                    B=(K-1)*P
                                    pre_good=ep is None or ep+B>0
                                    match={'recurrent_positive_prefix_rejection':rec+B>0 and not pre_good,
                                           'full_service_only_shared_prefix':full+B>0 and shared+B<=0,
                                           'diagnostic_segment_weaker_than_shared':shared+B>0 and segment+B<=0,
                                           'diagnostic_global_weaker_than_segment':segment+B>0 and global_+B<=0}[label]
                                    if match:
                                        diagnostic_examples[label]={'case_id':case_id,'p':p,'q':q,'s0':s0,'prefix':pre,'cycle':T,'K':K,'P':P,'phi':phi,'m':m,'g':g,'supported':supported,'prefix_exact':None if ep is None else ep+B,'recurrent_exact':rec+B,'full_exact':full+B,'shared_completion':shared+B,'segment_completion':segment+B,'global_completion':global_+B,'minimizing_witness':[sw,hw]}
                                        break
                f.write(json.dumps({'case_id':case_id,'P':P,'m':m,'supported':supported,'rows':phase_rows},separators=(',',':'))+'\n')
            rec_out = {'case_id':case_id,'p':p,'q':q,'s0':s0,'prefix_triples':pre,
                       'cycle_triples':T,'d':d,'g':g,'bounds':{'recurrent_J':Jr,'recurrent_A':Ar,'prefix_J':Jp,'prefix_A':Ap,'global_J':Jall,'global_A':Aall},
                       'grids':{name:dict(c) for name,c in local.items()}}
            records.append(rec_out)
            for name,c in local.items():
                for metric in ['full_service_positive','full_service_only_vs_shared_completion','recurrent_positive_but_prefix_rejects','supported_full_service_only_vs_shared_completion']:
                    counts[name+'_sources_with_'+metric] += c[metric] > 0
            if len(records)%200 == 0:
                print(json.dumps({'progress_timing_sources':len(records)}),flush=True)
    assert counts['timing_admitted_sources']==1622 and counts['timing_tie_rejected']==328
    assert counts['nonempty_prefix_sources']==764
    for name, strata in grids.items():
        for st,c in strata.items():
            assert c['supported_full_service_positive']+c['supported_full_service_unknown']+c['unsupported_queries']==c['policy_queries']
            assert c['full_service_positive']==c['full_shared_prefix_completion_positive']+c['full_service_only_vs_shared_completion']
            assert c['recurrent_service_positive']==c['full_service_positive']+c['recurrent_positive_but_prefix_rejects']
        for metric,value in strata['all'].items():
            assert value==strata['empty_prefix'][metric]+strata['nonempty_prefix'][metric]
        oldc=r35['grids'][name]['counts']
        assert strata['all']['policy_queries']==oldc['policy_queries']
        assert strata['all']['recurrent_service_positive']==oldc['full_master_positive']
        assert strata['all']['unsupported_queries']==oldc['unsupported_policy_queries']
    result={'result':'PASS_ALL_EXISTING_FAMILY_COMPLETE_PREFIX_AND_RECURRENT_POLICY_ADMISSIONS',
            'protocol_sha256':sha(proto),'script_sha256':sha(Path(__file__)),
            'input_r30_sha256':sha(input_path),'input_r35_sha256':sha(r35_path),
            'all_phase_bases_sha256':sha(phase_path),'all_phase_bases_bytes':phase_path.stat().st_size,
            'source_counts':dict(counts),'checks':dict(checks),
            'grids':{g:{s:dict(c) for s,c in strata.items()} for g,strata in grids.items()},
            'diagnostic_examples':diagnostic_examples,'rejected_timing_sources':rejected,'records':records,
            'scope':'Complete mathematical source/receiver-family policy admission with common exact finite-prefix check and tight actual-completion recurrent baseline; no native cache, remote execution, timing benchmark, hardware benefit, or independent application population claim. All negative outcomes remain reconstructible from phase bases. Positive proofs depend on the stated source/control bindings and first-failure induction.'}
    out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in result.items() if k not in ('records','rejected_timing_sources')},indent=2),flush=True)


if __name__=='__main__':
    main()
