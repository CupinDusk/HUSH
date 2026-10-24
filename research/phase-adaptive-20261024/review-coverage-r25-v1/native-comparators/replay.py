"""Stdlib replay of fixed, frozen policies at every original heldout point.

The tolerance sweep is descriptive; no policy is selected using heldout data.
"""
from pathlib import Path
from fractions import Fraction
from itertools import combinations
import argparse, csv, hashlib, json

P = Path(__file__).resolve().parent
ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path);a=ap.parse_args()
O=a.out or P;O.mkdir(parents=True,exist_ok=True)
policies=['K1','WI','WU','suppress','phase','frozen_fixed','frozen_fastest']
allowance=Fraction(1,10)  # percent
sha=lambda b:hashlib.sha256(b).hexdigest()
bindings=json.loads((P/'INPUT_BINDINGS.json').read_text())
for n,b in bindings['inputs'].items():
    raw=(P/n).read_bytes();assert sha(raw)==b['sha256'] and len(raw)==b['bytes']
def load(n):
    rows=list(csv.DictReader((P/n).open(encoding='utf-8',newline='')))
    for r in rows:
        for k in ['N','phi','J_cycles','WU']:r[k]=int(r[k])
        r['K']=tuple(map(int,r['K'].split(',')))
    return rows
train=load('TRAINING_ROWS.csv');held=load('HELDOUT_ROWS.csv');diagnostics=load('FIXED_DIAGNOSTICS.csv')
freeze=json.loads((P/'FROZEN_RULES.json').read_text())
assert freeze['heldout_rows_seen']==0
selection_checks=[]
for s in freeze['selection']:
    assert not s['heldout_seen']
    rr=[r for r in train if r['cache']==s['cache']];assert len(rr)==837
    groups={}
    for r in rr:groups.setdefault((r['kind'],r['K']),[]).append(r)
    assert len(groups)==279
    aa=[]
    for (kind,K),gg in groups.items():
        assert len(gg)==3 and {r['phi'] for r in gg}=={0,64,127}
        aa.append({'kind':kind,'K':K,'J':max(r['J_cycles'] for r in gg),'WU':max(r['WU'] for r in gg)})
    assert {x['K'][0] for x in aa if x['kind']=='fixed'}==set(range(1,256))
    ff=min((x for x in aa if x['kind']=='fixed'),key=lambda x:(x['J'],x['K']))
    ef=[x for x in aa if x['kind']=='fixed' and x['J']*1000<=ff['J']*1001]
    ep=[x for x in aa if x['kind']=='phase' and x['J']*1000<=ff['J']*1001]
    bf=min(ef,key=lambda x:(x['WU'],x['J'],x['K']))
    bp=min(ep,key=lambda x:(x['WU'],x['J'],x['K'])) if ep else min((x for x in aa if x['kind']=='phase'),key=lambda x:(x['J'],x['K']))
    for k,x in [('fastest_fixed',ff),('fixed',bf),('phase',bp)]:
        assert tuple(s[k]['K'])==x['K'] and s[k]['max_J']==x['J'] and s[k]['max_WU']==x['WU']
    assert s['eligible_fixed_candidates']==len(ef) and s['eligible_phase_candidates']==len(ep)
    assert s['deployed_mode']==('phase' if ep and bp['WU']<bf['WU'] else 'fixed')
    selection_checks.append({'cache':s['cache'],'fastest_fixed_K':ff['K'],'fixed_K':bf['K'],'phase_K':bp['K'],'eligible_fixed':len(ef),'eligible_phase':len(ep),'N16_only':True})
def save(name,rows):
    with (O/name).open('w',encoding='utf-8',newline='') as f:
        w=csv.DictWriter(f,fieldnames=list(rows[0]),lineterminator='\n');w.writeheader();w.writerows(rows)
def frac(x):return str(x)
def ratio(J,A):return 100*Fraction(J-A,A)
def dominates(x,y):return x['J_cycles']<=y['J_cycles'] and x['WU']<=y['WU'] and (x['J_cycles']<y['J_cycles'] or x['WU']<y['WU'])
points=[];summaries=[];pairs=[];worst_pairs=[];intervals=[];useful=[]
def pairrow(prefix,x,y):
    return {**prefix,'policy_a':x['policy'],'policy_b':y['policy'],'J_a':x['J_cycles'],'J_b':y['J_cycles'],'WU_a':x['WU'],'WU_b':y['WU'],'a_minus_b_J_cycles':x['J_cycles']-y['J_cycles'],'a_minus_b_J_pct_exact':frac(ratio(x['J_cycles'],y['J_cycles'])),'a_minus_b_WU':x['WU']-y['WU'],'a_minus_b_WU_pct_exact':('undefined_baseline_zero' if y['WU']==0 else frac(100*Fraction(x['WU']-y['WU'],y['WU']))),'a_dominates_b':dominates(x,y),'b_dominates_a':dominates(y,x),'equal_time_and_WU':x['J_cycles']==y['J_cycles'] and x['WU']==y['WU']}
def sweep(prefix,rows,thresholdkey):
    bounds=sorted({r[thresholdkey] for r in rows})
    # Include the empty interval below the earliest (possibly negative) event.
    for low,high in zip([None]+bounds,bounds+[None]):
        eligible=[] if low is None else [r for r in rows if r[thresholdkey]<=low]
        best=min(eligible,key=lambda r:(r['WU'],r['J_cycles'],policies.index(r['policy']))) if eligible else None
        frontier=[r['policy'] for r in eligible if not any(dominates(x,r) for x in eligible)]
        intervals.append({**prefix,'lower_pct_inclusive_exact':'-inf' if low is None else frac(low),'upper_pct_exclusive_exact':'+inf' if high is None else frac(high),'eligible_policies':';'.join(r['policy'] for r in eligible),'pareto_policies':';'.join(frontier),'posthoc_min_WU_policy':'' if best is None else best['policy'],'posthoc_min_WU':'' if best is None else best['WU'],'heldout_retuned_deployment':False})
    ph=next(r for r in rows if r['policy']=='phase')
    simple=[r for r in rows if r['policy'] in ['K1','suppress','WI']]
    assert all(ph['WU']<r['WU'] for r in rows if r['policy'] in ['frozen_fixed','frozen_fastest','WU'])
    low=max(Fraction(0),ph[thresholdkey]);high=min(r[thresholdkey] for r in simple)
    useful.append({**prefix,'lower_pct_inclusive_exact':frac(low),'upper_pct_exclusive_exact':frac(high),'lower_pct':float(low),'upper_pct':float(high),'nonempty':low<high,'contains_0_1pct':low<=allowance<high,'interpretation':'phase unique minimum WU among seven fixed identities; K1/suppression/WI inadmissible; posthoc descriptive interval'})
for cache in ['32KiB','64KiB']:
    for N in [32,36,40]:
        group=[]
        for phi in [0,64,127]:
            rr=[r.copy() for r in held if (r['cache'],r['N'],r['phi'])==(cache,N,phi)]
            assert len(rr)==7 and {r['policy'] for r in rr}==set(policies)
            rr.sort(key=lambda r:policies.index(r['policy']))
            anchor=next(r for r in rr if r['policy']=='frozen_fastest')
            for r in rr:
                r['threshold']=ratio(r['J_cycles'],anchor['J_cycles'])
                r['admitted']=r['J_cycles']*1000<=anchor['J_cycles']*1001
                r['pareto']=not any(dominates(x,r) for x in rr)
                points.append({'cache':cache,'N':N,'phi':phi,'policy':r['policy'],'K':','.join(map(str,r['K'])),'J_cycles':r['J_cycles'],'WU':r['WU'],'anchor_J_cycles':anchor['J_cycles'],'anchor_WU':anchor['WU'],'time_change_vs_anchor_pct':float(r['threshold']),'min_tolerance_pct_exact':frac(r['threshold']),'admitted_at_0_1pct':r['admitted'],'pareto_all_7':r['pareto'],'dominated_by':';'.join(x['policy'] for x in rr if dominates(x,r)),'original_id':r['id']})
            for x,y in combinations(rr,2):pairs.append(pairrow({'cache':cache,'N':N,'phi':phi},x,y))
            sweep({'scope':'same_offset','cache':cache,'N':N,'phi':phi},rr,'threshold')
            group.extend(rr)
        aggregate=[]
        anchor_rows=[r for r in group if r['policy']=='frozen_fastest']
        anchor_max=max(r['J_cycles'] for r in anchor_rows)
        for policy in policies:
            rr=[r for r in group if r['policy']==policy]
            assert len(rr)==3
            J=max(r['J_cycles'] for r in rr);WU=max(r['WU'] for r in rr)
            robust=max(r['threshold'] for r in rr)
            x={'cache':cache,'N':N,'policy':policy,'K':','.join(map(str,rr[0]['K'])),'J_cycles':J,'WU':WU,'J_worst_phi':';'.join(str(r['phi']) for r in rr if r['J_cycles']==J),'WU_worst_phi':';'.join(str(r['phi']) for r in rr if r['WU']==WU),'admission_count':sum(r['admitted'] for r in rr),'offset_count':3,'robust_threshold':robust,'robust_all_offsets_min_tolerance_pct_exact':frac(robust),'maxJ_vs_anchor_maxJ_min_tolerance_pct_exact':frac(ratio(J,anchor_max)),'maxJ_admitted_at_0_1pct':J*1000<=anchor_max*1001,'pareto_offset_count':sum(r['pareto'] for r in rr)}
            aggregate.append(x)
        for x in aggregate:
            x['pareto_worst_offsets']=not any(dominates(y,x) for y in aggregate)
            x['dominated_by_worst_offsets']=';'.join(y['policy'] for y in aggregate if dominates(y,x))
            summaries.append({k:v for k,v in x.items() if k!='robust_threshold'})
        for x,y in combinations(aggregate,2):worst_pairs.append(pairrow({'cache':cache,'N':N},x,y))
        sweep({'scope':'all_three_offsets','cache':cache,'N':N,'phi':'all'},aggregate,'robust_threshold')
save('PER_OFFSET.csv',points);save('WORST_OFFSET.csv',summaries)
save('PAIRED_PARETO.csv',pairs);save('PAIRED_WORST_OFFSET.csv',worst_pairs)
save('TOLERANCE_INTERVALS.csv',intervals)
save('PHASE_USEFUL_INTERVALS.csv',useful)
diagnostic_comparisons=[]
for cache in ['32KiB','64KiB']:
    for N in [32,36,40]:
        for phi in [0,64,127]:
            ph=next(r for r in held if (r['cache'],r['N'],r['phi'],r['policy'])==(cache,N,phi,'phase'))
            fixed=[r.copy() for r in diagnostics if (r['cache'],r['N'],r['phi'])==(cache,N,phi)]
            assert len(fixed)==18 and sum(r['predeclared_16']=='True' for r in fixed)==16
            others=[r for r in held if (r['cache'],r['N'],r['phi'])==(cache,N,phi) and r['policy'] in ['WI','WU','suppress']]
            dominators=[r for r in fixed if dominates(r,ph)]
            diagnostic16=[r for r in fixed if r['predeclared_16']=='True']
            fastest=min(diagnostic16,key=lambda r:(r['J_cycles'],r['K']))
            diagnostic_comparisons.append({'cache':cache,'N':N,'phi':phi,'phase_J_cycles':ph['J_cycles'],'phase_WU':ph['WU'],'diagnostic16_count':16,'all_measured_fixed_count':18,'diagnostic16_dominating_K':';'.join(str(r['K'][0]) for r in dominators if r['predeclared_16']=='True'),'all_measured_fixed_dominating_K':';'.join(str(r['K'][0]) for r in dominators),'phase_nondominated_vs_16_and_WI_WU_suppression':not any(dominates(r,ph) for r in diagnostic16+others),'phase_nondominated_vs_all18_and_WI_WU_suppression':not any(dominates(r,ph) for r in fixed+others),'fastest_diagnostic16_K_posthoc':fastest['K'][0],'fastest_diagnostic16_J_cycles_posthoc':fastest['J_cycles'],'fastest_diagnostic16_WU_posthoc':fastest['WU'],'phase_minus_fastest_diagnostic16_J_cycles':ph['J_cycles']-fastest['J_cycles'],'fastest_diagnostic16_dominates_phase':dominates(fastest,ph),'diagnostic_scope':'posthoc heldout diagnostic, not frozen selection or exhaustive 255-load oracle'})
save('FIXED_DIAGNOSTIC_PARETO.csv',diagnostic_comparisons)
extended_useful=[]
for cache in ['32KiB','64KiB']:
    for N in [32,36,40]:
        pool=[]
        for phi in [0,64,127]:
            anchor=next(r for r in held if (r['cache'],r['N'],r['phi'],r['policy'])==(cache,N,phi,'frozen_fastest'))['J_cycles']
            rr=[{**r,'policy':'fixed_K'+str(r['K'][0])} for r in diagnostics if (r['cache'],r['N'],r['phi'])==(cache,N,phi)]
            rr.extend(r.copy() for r in held if (r['cache'],r['N'],r['phi'])==(cache,N,phi) and r['policy'] in ['phase','suppress','WI','WU'])
            assert len(rr)==22
            for r in rr:r['threshold']=ratio(r['J_cycles'],anchor)
            pool.extend(rr)
            ph=next(r for r in rr if r['policy']=='phase')
            competitors=[r for r in rr if r['policy']!='phase' and r['WU']<=ph['WU']]
            low=max(Fraction(0),ph['threshold']);high=min(r['threshold'] for r in competitors)
            extended_useful.append({'scope':'same_offset','cache':cache,'N':N,'phi':phi,'lower_pct_inclusive_exact':frac(low),'upper_pct_exclusive_exact':frac(high),'lower_pct':float(low),'upper_pct':float(high),'nonempty':low<high,'signed_lower_pct_inclusive_exact':frac(ph['threshold']),'signed_interval_nonempty':ph['threshold']<high,'limiting_alternatives':';'.join(r['policy'] for r in competitors if r['threshold']==high),'scope_note':'posthoc all18 measured fixed plus WI/WU/suppression; no retuning; displayed lower clipped at zero, signed lower retained'})
        aa=[]
        for policy in {r['policy'] for r in pool}:
            rr=[r for r in pool if r['policy']==policy];assert len(rr)==3
            aa.append({'policy':policy,'WU':max(r['WU'] for r in rr),'threshold':max(r['threshold'] for r in rr)})
        ph=next(r for r in aa if r['policy']=='phase')
        competitors=[r for r in aa if r['policy']!='phase' and r['WU']<=ph['WU']]
        low=max(Fraction(0),ph['threshold']);high=min(r['threshold'] for r in competitors)
        extended_useful.append({'scope':'all_three_offsets','cache':cache,'N':N,'phi':'all','lower_pct_inclusive_exact':frac(low),'upper_pct_exclusive_exact':frac(high),'lower_pct':float(low),'upper_pct':float(high),'nonempty':low<high,'signed_lower_pct_inclusive_exact':frac(ph['threshold']),'signed_interval_nonempty':ph['threshold']<high,'limiting_alternatives':';'.join(sorted(r['policy'] for r in competitors if r['threshold']==high)),'scope_note':'posthoc all18 measured fixed plus WI/WU/suppression; no retuning; displayed lower clipped at zero, signed lower retained'})
save('EXTENDED_PHASE_USEFUL_INTERVALS.csv',extended_useful)
save('FIGURE_REGIMES.csv',[r for r in extended_useful if r['scope']=='all_three_offsets'])
simple_contrasts=[];simple_ranges={}
for cache_scope in ['all','32KiB','64KiB']:
    simple_ranges[cache_scope]={}
    for alternative in ['K1','suppress']:
        rows=[]
        for ph in [r for r in held if r['policy']=='phase' and (cache_scope=='all' or r['cache']==cache_scope)]:
            other=next(r for r in held if (r['cache'],r['N'],r['phi'],r['policy'])==(ph['cache'],ph['N'],ph['phi'],alternative))
            Jdelta=ratio(ph['J_cycles'],other['J_cycles']);WUdelta=100*Fraction(ph['WU']-other['WU'],other['WU'])
            x={'cache':ph['cache'],'N':ph['N'],'phi':ph['phi'],'alternative':alternative,'phase_J_cycles':ph['J_cycles'],'alternative_J_cycles':other['J_cycles'],'phase_WU':ph['WU'],'alternative_WU':other['WU'],'phase_minus_alternative_J_cycles':ph['J_cycles']-other['J_cycles'],'phase_minus_alternative_J_pct_exact':str(Jdelta),'phase_minus_alternative_J_pct':float(Jdelta),'phase_minus_alternative_WU':ph['WU']-other['WU'],'phase_minus_alternative_WU_pct_exact':str(WUdelta),'phase_minus_alternative_WU_pct':float(WUdelta),'phase_over_alternative_WU_exact':str(Fraction(ph['WU'],other['WU'])),'phase_over_alternative_WU':ph['WU']/other['WU']}
            rows.append(x)
            if cache_scope=='all':simple_contrasts.append(x)
        simple_ranges[cache_scope][alternative]={'n':len(rows),**{k:{'min':min(r[k] for r in rows),'max':max(r[k] for r in rows)} for k in ['phase_minus_alternative_J_cycles','phase_minus_alternative_J_pct','phase_minus_alternative_WU','phase_minus_alternative_WU_pct','phase_over_alternative_WU']}}
save('PHASE_SIMPLE_CONTRASTS.csv',simple_contrasts)
(O/'PHASE_SIMPLE_RANGES.json').write_text(json.dumps(simple_ranges,indent=2)+'\n',encoding='utf-8',newline='\n')
compact=[];tex=[]
for cache in ['32KiB','64KiB']:
    for N in [32,36,40]:
        row={'cache':cache,'N':N};cells=[]
        for policy in policies:
            x=next(r for r in summaries if (r['cache'],r['N'],r['policy'])==(cache,N,policy))
            row[policy+'_J_cycles']=x['J_cycles'];row[policy+'_WU']=x['WU'];row[policy+'_admitted_of_3']=x['admission_count']
            cells.append(f"{x['J_cycles']/1e6:.4f}/{x['WU']}/{x['admission_count']}")
        compact.append(row);tex.append(f"{cache[:-3]}/{N} & "+' & '.join(cells)+r' \\')
save('TABLE_SIX_ROWS.csv',compact)
table=r'''% Generated by native-comparators/replay.py. J in million cycles.
% Each cell: max-offset J / max-offset WU / same-offset admissions out of 3.
% Maxima of J and WU may occur at different offsets. Identities fixed before heldout.
% 64KiB phase is the original ineligible diagnostic fallback; deployment uses Fixed.
\begin{tabular}{@{}lrrrrrrr@{}}
\hline
KiB/$N$ & $K=1$ & WI & WU & Supp. & Phase & Fixed & Fastest \\
\hline
'''+ '\n'.join(tex)+r'''
\hline
\end{tabular}
'''
(O/'table-six-rows.tex').write_text(table,encoding='utf-8',newline='\n')
comparison_summary={}
for policy in policies:
    pp=[r for r in points if r['policy']==policy]
    comparison_summary[policy]={'admitted':sum(r['admitted_at_0_1pct'] for r in pp),'of':18,'pareto_points':sum(r['pareto_all_7'] for r in pp),'time_change_vs_frozen_fastest_pct_min':min(r['time_change_vs_anchor_pct'] for r in pp),'time_change_vs_frozen_fastest_pct_max':max(r['time_change_vs_anchor_pct'] for r in pp),'all3_admitted_groups':sum(r['policy']==policy and r['admission_count']==3 for r in summaries)}
phase_relations={}
for policy in policies:
    if policy=='phase':continue
    d={'phase_dominates':0,'alternative_dominates':0,'incomparable':0,'equal':0,'phase_faster':0,'phase_slower':0,'phase_less_WU':0,'phase_more_WU':0}
    for cache in ['32KiB','64KiB']:
        for N in [32,36,40]:
            for phi in [0,64,127]:
                x=next(r for r in held if (r['cache'],r['N'],r['phi'],r['policy'])==(cache,N,phi,'phase'))
                y=next(r for r in held if (r['cache'],r['N'],r['phi'],r['policy'])==(cache,N,phi,policy))
                d['phase_faster']+=x['J_cycles']<y['J_cycles'];d['phase_slower']+=x['J_cycles']>y['J_cycles'];d['phase_less_WU']+=x['WU']<y['WU'];d['phase_more_WU']+=x['WU']>y['WU']
                key='phase_dominates' if dominates(x,y) else 'alternative_dominates' if dominates(y,x) else 'equal' if (x['J_cycles'],x['WU'])==(y['J_cycles'],y['WU']) else 'incomparable'
                d[key]+=1
    phase_relations[policy]=d
audit={'scope':'Original R20 frozen policies on original heldout N32/36/40; retrospective comparator completeness, not new validation or a heldout oracle','allowance_pct_exact':str(allowance),'admission_formula':'1000*J_policy(N,phi) <= 1001*J_frozen_fastest_from_N16(N,phi)','threshold_formula_pct':'100*(J_policy-J_frozen_fastest)/J_frozen_fastest; signed, inclusive lower bound','no_heldout_retuning':True,'training_selection_verified':selection_checks,'heldout_policy_points':len(points),'paired_unordered_policy_comparisons':len(pairs),'worst_offset_policy_rows':len(summaries),'worst_offset_unordered_comparisons':len(worst_pairs),'exact_intervals_including_empty_and_negative':len(intervals),'phase_unique_min_WU_intervals':len(useful),'phase_nondominated_vs_all18_fixed_WI_WU_suppression_count':sum(r['phase_nondominated_vs_all18_and_WI_WU_suppression'] for r in diagnostic_comparisons),'phase_dominated_by_any_of_16_fixed_count':sum(bool(r['diagnostic16_dominating_K']) for r in diagnostic_comparisons),'phase_dominated_by_fastest_of_16_fixed_count':sum(r['fastest_diagnostic16_dominates_phase'] for r in diagnostic_comparisons),'policy_summary':comparison_summary,'phase_paired_relations':phase_relations,'inputs':bindings['inputs'],'outputs':{n:sha((O/n).read_bytes()) for n in ['PER_OFFSET.csv','WORST_OFFSET.csv','PAIRED_PARETO.csv','PAIRED_WORST_OFFSET.csv','TOLERANCE_INTERVALS.csv','PHASE_USEFUL_INTERVALS.csv','FIXED_DIAGNOSTIC_PARETO.csv','TABLE_SIX_ROWS.csv','table-six-rows.tex']}}
for n in ['EXTENDED_PHASE_USEFUL_INTERVALS.csv','FIGURE_REGIMES.csv','PHASE_SIMPLE_CONTRASTS.csv','PHASE_SIMPLE_RANGES.json']:audit['outputs'][n]=sha((O/n).read_bytes())
(O/'AUDIT.json').write_text(json.dumps(audit,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps({'policy_summary':comparison_summary,'phase_paired_relations':phase_relations,'training_selection_verified':selection_checks},indent=2))
