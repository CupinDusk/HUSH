"""Separate arithmetic/extraction check; does not import replay or extractor."""
from pathlib import Path
from fractions import Fraction
import argparse,base64,csv,hashlib,io,json,zipfile
P=Path(__file__).resolve().parent
ap=argparse.ArgumentParser();ap.add_argument('--r20',type=Path);a=ap.parse_args()
read=lambda n:list(csv.DictReader((P/n).open(encoding='utf-8',newline='')))
sha=lambda b:hashlib.sha256(b).hexdigest()
b=json.loads((P/'INPUT_BINDINGS.json').read_text());audit=json.loads((P/'AUDIT.json').read_text())
for n,x in b['inputs'].items():assert sha((P/n).read_bytes())==x['sha256']
for n,h in audit['outputs'].items():assert sha((P/n).read_bytes())==h
if (P/'EXPECTED_OUTPUT_HASHES.json').exists():
    for n,h in json.loads((P/'EXPECTED_OUTPUT_HASHES.json').read_text()).items():assert sha((P/n).read_bytes())==h
orig_checks=0
if a.r20:
    m=json.loads((a.r20/'RECORDED_DATA.json').read_text())
    raw=base64.b64decode(''.join((a.r20/n).read_text().strip() for n in m['parts']))
    assert sha(raw)==b['original_archive_sha256']
    member=zipfile.ZipFile(io.BytesIO(raw)).read('DATA.json');assert sha(member)==b['original_member_sha256']
    original={r['case']['id']:r for r in json.loads(member)['rows']}
    for name in ['TRAINING_ROWS.csv','HELDOUT_ROWS.csv','FIXED_DIAGNOSTICS.csv']:
        for r in read(name):
            x=original[r['id']];c=x['case']
            assert (r['cache'],int(r['N']),int(r['phi']),r['kind'],r['mode'],r['K'],r['write_policy'])==(c['cache'],c['N'],c['phi'],c['kind'],c['mode'],','.join(map(str,c['K'])),c['write_policy'])
            assert int(r['J_cycles'])*1000==x['summary']['roi_ticks'] and int(r['WU'])==x['total_metrics']['WU']
            assert r['original_record_sha256']==sha(json.dumps(x,sort_keys=True,separators=(',',':')).encode())
            orig_checks+=1
held=read('HELDOUT_ROWS.csv');points=read('PER_OFFSET.csv');summary=read('WORST_OFFSET.csv')
lookup={(r['cache'],r['N'],r['phi'],r['policy']):r for r in held}
assert len(lookup)==len(points)==126
for r in points:
    x=lookup[(r['cache'],r['N'],r['phi'],r['policy'])];anchor=lookup[(r['cache'],r['N'],r['phi'],'frozen_fastest')]
    J,W,A=int(x['J_cycles']),int(x['WU']),int(anchor['J_cycles'])
    assert int(r['J_cycles'])==J and int(r['WU'])==W
    assert Fraction(r['min_tolerance_pct_exact'])==Fraction(100*(J-A),A)
    assert (r['admitted_at_0_1pct']=='True')==(J*1000<=A*1001)
for r in summary:
    xs=[x for x in points if (x['cache'],x['N'],x['policy'])==(r['cache'],r['N'],r['policy'])]
    assert len(xs)==3 and int(r['J_cycles'])==max(int(x['J_cycles']) for x in xs) and int(r['WU'])==max(int(x['WU']) for x in xs)
    assert int(r['admission_count'])==sum(x['admitted_at_0_1pct']=='True' for x in xs)
    assert Fraction(r['robust_all_offsets_min_tolerance_pct_exact'])==max(Fraction(x['min_tolerance_pct_exact']) for x in xs)
interval_checks=0
for r in read('TOLERANCE_INTERVALS.csv'):
    xs=[x for x in (points if r['scope']=='same_offset' else summary) if (x['cache'],x['N'])==(r['cache'],r['N']) and (r['scope']!='same_offset' or x['phi']==r['phi'])]
    key='min_tolerance_pct_exact' if r['scope']=='same_offset' else 'robust_all_offsets_min_tolerance_pct_exact'
    low,high=r['lower_pct_inclusive_exact'],r['upper_pct_exclusive_exact']
    t=Fraction(high)-1 if low=='-inf' else Fraction(low)+1 if high=='+inf' else (Fraction(low)+Fraction(high))/2
    eligible={x['policy'] for x in xs if Fraction(x[key])<=t}
    assert eligible==set(filter(None,r['eligible_policies'].split(';')))
    if eligible:
        q=min((x for x in xs if x['policy'] in eligible),key=lambda x:(int(x['WU']),int(x['J_cycles'])))
        assert int(r['posthoc_min_WU'])==int(q['WU'])
    interval_checks+=1
diagnostics=read('FIXED_DIAGNOSTICS.csv');dom=lambda x,y:int(x['J_cycles'])<=int(y['J_cycles']) and int(x['WU'])<=int(y['WU']) and (int(x['J_cycles'])<int(y['J_cycles']) or int(x['WU'])<int(y['WU']))
diagnostic_checks=0
for r in read('FIXED_DIAGNOSTIC_PARETO.csv'):
    ph=lookup[(r['cache'],r['N'],r['phi'],'phase')]
    fixed=[x for x in diagnostics if (x['cache'],x['N'],x['phi'])==(r['cache'],r['N'],r['phi'])]
    ds={x['K'].split(',')[0] for x in fixed if dom(x,ph)}
    assert ds==set(filter(None,r['all_measured_fixed_dominating_K'].split(';')))
    diagnostic_checks+=1
extended_checks=0
for r in read('EXTENDED_PHASE_USEFUL_INTERVALS.csv'):
    pool=[]
    for phi in ([r['phi']] if r['scope']=='same_offset' else ['0','64','127']):
        A=int(lookup[(r['cache'],r['N'],phi,'frozen_fastest')]['J_cycles'])
        rr=[{**x,'policy':'fixed_K'+x['K'].split(',')[0]} for x in diagnostics if (x['cache'],x['N'],x['phi'])==(r['cache'],r['N'],phi)]
        rr.extend(x.copy() for x in held if (x['cache'],x['N'],x['phi'])==(r['cache'],r['N'],phi) and x['policy'] in ['phase','WI','WU','suppress'])
        for x in rr:x['T']=Fraction(100*(int(x['J_cycles'])-A),A)
        pool.extend(rr)
    aggregates={}
    for x in pool:aggregates.setdefault(x['policy'],[]).append(x)
    aa={k:{'WU':max(int(x['WU']) for x in xx),'T':max(x['T'] for x in xx)} for k,xx in aggregates.items()}
    ph=aa.pop('phase');high=min(x['T'] for x in aa.values() if x['WU']<=ph['WU']);low=max(Fraction(0),ph['T'])
    assert Fraction(r['lower_pct_inclusive_exact'])==low and Fraction(r['upper_pct_exclusive_exact'])==high
    assert (r['nonempty']=='True')==(low<high) and Fraction(r['signed_lower_pct_inclusive_exact'])==ph['T']
    extended_checks+=1
report={'status':'PASS','original_source_projection_checks':orig_checks,'independent_point_checks':len(points),'independent_worst_offset_checks':len(summary),'independent_interval_midpoint_checks':interval_checks,'independent_expanded_diagnostic_checks':diagnostic_checks,'independent_extended_regime_checks':extended_checks,'all_input_and_output_hashes_verified':True,'no_new_native_execution':True}
(P/'INDEPENDENT_CHECK.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps(report))
