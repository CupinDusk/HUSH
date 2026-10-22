"""Coherent WU/decrement/read/cancel order at every client read boundary."""
from pathlib import Path
from itertools import combinations
import hashlib,json
from source_producer import expiry,tick_counter
from policy_sufficiency import nonempty_subsets
HERE=Path(__file__).resolve().parent

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

def tick_reads(reads,updates,K,P,phi,trace=False):
    """Integer ticks; WU then decrement then read+cancel, at both endpoints."""
    reads=set(reads);updates=set(updates)
    valid=True;enabled=False;count=0;generation=0;hits=[];events=[]
    def log(t,slot,event,**state):
        if trace:events.append({'tick':t,'slot':slot,'event':event,'generation':generation,**state})
    for t in range(min(reads),max(reads)+1):
        if t in updates:
            if valid:
                generation+=1;enabled=True;count=K
                log(t,0,'WU_load',count=count)
            else:log(t,0,'WU_ignored_invalid')
        if (t-phi)%P==0 and enabled:
            count-=1;log(t,1,'decrement',count=count)
            if count==0:
                valid=False;enabled=False;log(t,1,'expiry')
        if t in reads:
            hits.append((t,valid));log(t,2,'read',hit=valid)
            if valid:
                enabled=False;generation+=1;log(t,3,'cancel_after_hit')
            else:break
    return {'reads':hits,'first_miss':next((t for t,v in hits if not v),None),'events':events}

def arm_reads(reads,updates,K,P,phi):
    """Independent sparse arm-deadline simulation with complete read events."""
    reads=set(reads);updates=set(updates);valid=True;deadline=None;hits=[]
    for t in sorted(reads|updates):
        if deadline is not None and deadline<t:
            valid=False;deadline=None
        if t in updates and valid:deadline=expiry(t,K,P,phi)
        if deadline is not None and deadline<=t:
            valid=False;deadline=None
        if t in reads:
            hits.append((t,valid))
            if valid:deadline=None
            else:break
    return {'reads':hits,'first_miss':next((t for t,v in hits if not v),None)}

def margin(C,J,K,P,phi,theta=1):return min(expiry(c-J+theta,K,P,phi)-c for c in C)

def historical(R,K,P,phi,theta=1):return min(expiry(s+theta,K,P,phi)-c for s,c in R)

def profile(R,K,P,phi,theta=1):
    omega={}
    for s,c in R:omega[s%P]=max(omega.get(s%P,-1),c-s)
    return (K-1)*P+theta+min((phi-r-theta)%P-j for r,j in omega.items())

def checked_step(s,h,K,P,phi):
    histories=misses=0
    for size in (0,1,2):
        for wu in combinations(range(s,h+1),size):
            one=tick_reads((s,h),wu,K,P,phi);two=arm_reads((s,h),wu,K,P,phi)
            assert one['reads']==two['reads'] and one['first_miss']==two['first_miss']
            assert one['reads'][0]==(s,True),'initial read must be admitted'
            histories+=1;misses+=one['first_miss'] is not None
    return histories,misses

def locate_events():
    local=HERE/'serial-client-build/events.json'
    if local.is_file():return local,HERE/'SERIAL_CLIENT_RESULTS.json'
    return HERE.parent/'expected/serial-client-events.json',HERE.parent/'expected/SERIAL_CLIENT_RESULTS.json'

def run():
    protocol=HERE/'READ_BOUNDARY_PROTOCOL.json';spec=json.loads(protocol.read_text(encoding='utf-8'))
    # Static source-flow predictions and corrected receiver queries first.
    static={}
    for p in range(2,7):
        for ell in range(1,5):
            H=(ell+1)*p;J=H-1
            for start in range(2*p):
                c0=((start+p-1)//p+ell)*p;C=tuple(c0+n*H for n in range(1,12))
                assert margin(C,J,ell+2,p,0)==p
                static[(p,ell,start)]={'C':C,'J':J,'RP1_margin':p,'RU1_margin':2,'G':1}
    finite={'C':(20,32),'J':11,'G':1,'K':3,'P':5,'phi':4}
    finite['M1']=margin(finite['C'],11,3,5,4)
    finite['Gamma1']=historical(((9,20),(21,32)),3,5,4)
    finite['RU1_margin']=10-11+1
    finite['PP1_margin']=expiry(20-11+1,3,5,4)-32
    assert [finite[k] for k in ['M1','Gamma1','RU1_margin','PP1_margin']]==[2,2,0,-8]
    events_path,old_report=locate_events()
    provenance=json.loads(old_report.read_text(encoding='utf-8'))
    assert sha(events_path)==provenance['source_events_sha256']
    rows=json.loads(events_path.read_text(encoding='utf-8'))
    counts={'reused_source_scenarios':0,'shifted_source_policy_queries':0,'aligned_complete_boundary_histories':0,
            'aligned_actual_misses':0,'finite_phase_histories':0,'finite_phase_misses':0,
            'shifted_residue_inputs':0,'shifted_residue_phase_queries':0,'shifted_relation_inputs':0,
            'shifted_relation_phase_queries':0,'shifted_all_phase_equalities':0}
    for row in rows:
        if row['variant']:continue
        p,ell,start=(row[k] for k in ['p','ell','initial_service']);decision=static[(p,ell,start)]
        s,c=row['services'],row['receipts'];J=decision['J']
        assert tuple(c[1:12])==decision['C'] and all(c[n]-s[n]==J for n in range(1,12))
        counts['reused_source_scenarios']+=1
        R=tuple(zip(s[1:12],c[1:12]))
        for P in range(1,9):
            for phi in range(P):
                for K in (1,J+2):
                    assert margin(decision['C'],J,K,P,phi)==historical(R,K,P,phi)==profile(R,K,P,phi)
                    counts['shifted_source_policy_queries']+=1
        if start==0:
            for n in range(12):
                number,miss=checked_step(s[n],s[n+1],ell+2,p,0)
                counts['aligned_complete_boundary_histories']+=number;counts['aligned_actual_misses']+=miss
    for s,h in spec['finite_phase_example']['local_steps']:
        number,miss=checked_step(s,h,3,5,4)
        counts['finite_phase_histories']+=number;counts['finite_phase_misses']+=miss
    assert counts['reused_source_scenarios']==160 and counts['shifted_source_policy_queries']==11520
    assert counts['aligned_complete_boundary_histories']==33720 and counts['aligned_actual_misses']==0
    assert counts['finite_phase_histories']==240 and counts['finite_phase_misses']==0
    # Directly check shifted observation algebra and witness iff, without
    # rewriting or rerunning the original theta0 result files.
    for P in range(1,7):
        for J in range(4):
            K=J+2;lift=(J+2)*P
            for A in nonempty_subsets(range(P)):
                C=tuple(lift+r for r in A);values=[]
                for phi in range(P):
                    direct=margin(C,J,K,P,phi)
                    assert direct==(K-1)*P-J+1+min((phi+J-1-c)%P for c in C)
                    values.append(direct-(K-1)*P-1);counts['shifted_residue_phase_queries']+=1
                recovered={r for r in range(P) if values[(r-J+1)%P]==-J}
                assert recovered==set(A);counts['shifted_residue_inputs']+=1
    for P in range(1,5):
        for J in range(3):
            K=J+2;lift=(J+2)*P
            for A in nonempty_subsets(range(P)):
                C=tuple(lift+r for r in A)
                for R in nonempty_subsets(tuple((c-j,c) for c in C for j in range(J+1))):
                    criterion={c%P for s,c in R if c-s==J}==set(A);equal=True
                    for phi in range(P):
                        gamma=historical(R,K,P,phi);m=margin(C,J,K,P,phi)
                        assert gamma==profile(R,K,P,phi) and gamma>=m
                        equal &= gamma==m;counts['shifted_relation_phase_queries']+=1
                    assert equal==criterion
                    counts['shifted_relation_inputs']+=1;counts['shifted_all_phase_equalities']+=int(equal)
    assert counts['shifted_relation_inputs']==8190 and counts['shifted_relation_phase_queries']==31664
    assert counts['shifted_all_phase_equalities']==918
    controls={}
    addendum=HERE/'READ_BOUNDARY_CONTROL_ADDENDUM.json'
    extras=json.loads(addendum.read_text(encoding='utf-8'))['controls']
    for item in spec['full_prefix_controls']+extras:
        one=tick_reads(item['reads'],item['WU'],item['K'],item['P'],item['phi'],trace=True)
        two=arm_reads(item['reads'],item['WU'],item['K'],item['P'],item['phi'])
        assert one['reads']==two['reads'] and one['first_miss']==two['first_miss']
        if 'expected_first_miss' in item:assert one['first_miss']==item['expected_first_miss']
        else:assert one['first_miss'] is None
        controls[item['name']]={'configuration':item,'trace':one}
    controls['withdraw_old_false_miss']['legacy_interval_model_hit']=tick_counter(9,21,(9,),4,4,1)
    assert not controls['withdraw_old_false_miss']['legacy_interval_model_hit']
    assert margin((20,32),11,3,5,1)==1 and margin((20,32,44),11,3,5,4)==0
    result={'scope':spec['scope'],'protocol_sha256':sha(protocol),'script_sha256':sha(Path(__file__)),
            'argument_sha256':sha(HERE/'READ_BOUNDARY_ARGUMENT.md'),'control_addendum_sha256':sha(addendum),'reused_source_events_sha256':sha(events_path),
            'new_source_function_execution':False,'static_queries_precede_reused_event_read':True,
            'order':spec['total_order'],'counts':counts,'finite_phase_case':finite,'controls':controls,
            'all_model_or_theorem_disagreements':0,'legacy_false_miss_interpretation_withdrawn':True}
    (HERE/'READ_BOUNDARY_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'counts':counts,'finite_phase_case':finite,'controls':{k:v['trace']['first_miss'] for k,v in controls.items()}}))

if __name__=='__main__':run()
