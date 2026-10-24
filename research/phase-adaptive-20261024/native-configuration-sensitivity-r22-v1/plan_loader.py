"""Emit a frozen native plan only for its exact declared platform profile.

The plan is empirical, not a WCET admission certificate. The profile check
prevents silently transferring descriptors to a new timer/cost/platform.
"""
import json,argparse
PROFILE_FIELDS=('P','cache','ways','line_bytes','cores','clock_Hz','extra_cycles_per_change','gates')
def emit_arguments(plan,profile):
    if plan['evidence_kind']!='empirical-native':
        raise ValueError('unsupported evidence kind; this loader emits native experiment plans')
    mismatch=[key for key in PROFILE_FIELDS if profile.get(key)!=plan['profile'].get(key)]
    if mismatch:raise ValueError('profile mismatch; offline reselection required: '+','.join(mismatch))
    ks=plan['loads']
    if len(ks)!=3 or any(type(k) is not int or not 1<=k<=255 for k in ks):
        raise ValueError('three positive eight-bit loads required;255 denotes infinity')
    p=profile['P']
    if type(p) is not int or p<=0:raise ValueError('positive fixed period required')
    return ['--mode','hush','--timer-period',str(p),'--cache-size',profile['cache'],
            '--schedule',','.join(str(k*p) for k in ks)]
def examples():
    common={'P':128,'ways':2,'line_bytes':64,'cores':4,'clock_Hz':1000000000,
            'extra_cycles_per_change':8,'gates':[4,10,50]}
    return [{'evidence_kind':'empirical-native','profile':{**common,'cache':cache},'loads':ks}
            for cache,ks in [('32KiB',[1,128,1]),('64KiB',[106,106,106])]]
def check():
    import copy
    cases=[]
    for plan in examples():
        profile=copy.deepcopy(plan['profile']);args=emit_arguments(plan,profile)
        cases.append({'cache':profile['cache'],'kind':'exact_profile','accepted':True,'args':args})
        for field,values in [('P',[64,256]),('extra_cycles_per_change',[0,16]),('ways',[4]),('gates',[[4,20,50]])]:
            for value in values:
                changed=copy.deepcopy(profile);changed[field]=value
                try:emit_arguments(plan,changed)
                except ValueError as e:cases.append({'cache':profile['cache'],'kind':'mismatch','field':field,'value':value,'accepted':False,'reason':str(e)})
                else:raise AssertionError('mismatched profile accepted')
        for load in [0,256]:
            bad=copy.deepcopy(plan);bad['loads'][1]=load
            try:emit_arguments(bad,profile)
            except ValueError:cases.append({'cache':profile['cache'],'kind':'invalid_load','value':load,'accepted':False})
            else:raise AssertionError('unencodable load accepted')
    return {'cases':cases,'count':len(cases),'all_expected_outcomes_pass':True,
            'native_simulations_launched':0,'scope':'preload profile and encoding guard; not a WCET certificate'}
if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('--self-check',action='store_true');ap.add_argument('--plan');ap.add_argument('--profile')
    args=ap.parse_args()
    if args.self_check:print(json.dumps(check(),indent=2))
    else:
        try:print(json.dumps(emit_arguments(json.load(open(args.plan)),json.load(open(args.profile)))))
        except ValueError as e:ap.exit(2,str(e)+'\n')
