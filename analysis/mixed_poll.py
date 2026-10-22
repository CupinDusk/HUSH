"""Unchanged public callback code, mixed polling paths, joint extremal witnesses."""
from pathlib import Path
from itertools import combinations
import argparse,hashlib,json,subprocess
from source_producer import NAMES,extract,expiry
from read_boundary import margin,historical,profile,checked_step,tick_reads,arm_reads
HERE=Path(__file__).resolve().parent


def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()


def target(s,p,ell):return ((s+p-1)//p+ell)*p


def derive(p,ell,s0,q):
    seen={};records=[];s=s0
    while s%p not in seen:
        seen[s%p]=len(records);c=target(s,p,ell)
        if c==s+q:return {'admitted':False,'tie_service':s,'tie_phase':s%p}
        nxt=s+q if c<s+q else c+q
        records.append((s,c,nxt));s=nxt
    index=seen[s%p];cycle=tuple(records[index:]);D=s-cycle[0][0]
    assert D%p==0 and D>0
    ss=[s0];cc=[];polls=[]
    for n in range(60):
        s=ss[-1];c=target(s,p,ell);assert c!=s+q;cc.append(c)
        if c>s+q:polls.append(s+q)
        ss.append(s+q if c<s+q else c+q)
    return {'admitted':True,'prefix':tuple(records[:index]),'cycle':cycle,'shift':D,
            'services':tuple(ss),'receipts':tuple(cc),'waiting_polls':tuple(polls)}


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--zig',type=Path,required=True);a=parser.parse_args()
    spec=json.loads((HERE/'MIXED_POLL_PROTOCOL.json').read_text(encoding='utf-8'))
    # Complete static admission and predictions are fixed before new source execution.
    static={};rejected=[]
    for p in range(3,10):
        for ell in range(1,4):
            for q in range(ell*p+1,(ell+1)*p-1):
                for s0 in range(p):
                    item=derive(p,ell,s0,q)
                    if item['admitted']:static[p,ell,s0,q]=item
                    else:rejected.append({'p':p,'ell':ell,'s0':s0,'q':q,**item})
    assert len(static)+len(rejected)==spec['domain']['total_configurations']==588
    key=(5,1,3,8);worked=static[key];assert worked['cycle']==((3,10,11),(11,20,28)) and worked['shift']==25
    assert worked['services'][:5]==tuple(spec['predicted_main_case']['service_prefix'])
    build=HERE/'mixed-poll-build';assert not (build/'events.json').exists(),'Preserve executed results; use a fresh directory'
    build.mkdir(exist_ok=True)
    (build/'STATIC_CASES.json').write_text(json.dumps({'admitted':[list(k) for k in static],'rejected':rejected},indent=2)+'\n',encoding='utf-8')
    source=HERE/'upstream-memtest.cc';text=source.read_text(encoding='utf-8');defs=[(n,*extract(text,n)) for n in NAMES]
    driver='int main(){bool comma=false;std::cout<<"[";\n'+''.join(f'mixed_scenario({p},{ell},{s0},{q},comma);\n' for p,ell,s0,q in static)+'std::cout<<"]\\n";}\n'
    cpp=build/'mixed_poll.cpp';cpp.write_text(text[:text.index('*/')+2]+'\n'+(HERE/'serial_client.prefix.cpp').read_text(encoding='utf-8')+'\n'+
        '\n\n'.join(d[1] for d in defs)+'\n'+(HERE/'serial_client.suffix.cpp').read_text(encoding='utf-8')+'\n'+
        (HERE/'mixed_poll.main.cpp').read_text(encoding='utf-8')+'\n'+driver,encoding='utf-8')
    for name,d,_,_ in defs:assert extract(cpp.read_text(encoding='utf-8'),name)[0]==d
    binary=build/'mixed_poll.exe';c=subprocess.run([str(a.zig),'c++','-std=c++17','-O2','-UNDEBUG',str(cpp),'-o',str(binary)],capture_output=True,text=True,timeout=120)
    (build/'compiler.log').write_text(c.stdout+c.stderr,encoding='utf-8');assert c.returncode==0,c.stderr
    r=subprocess.run([str(binary)],capture_output=True,text=True,timeout=60)
    (build/'execution.log').write_text(r.stdout+'\n'+r.stderr,encoding='utf-8');assert r.returncode==0,r.stderr
    rows=json.loads(r.stdout);(build/'events.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8')
    counts={'source_configurations':len(rows),'source_callback_edges':0,'joint_extremal_cycles':0,'other_cycles':0,
            'policy_queries':0,'RP_certified':0,'RU_certified':0,'PP_certified':0,'history_certified':0,
            'actual_phase_certified':0,'strong_service_uniform_certified':0,'RP_gain_both':0,
            'RP_gain_over_strong_service_uniform':0,'class_or_formula_mismatches':0}
    per_config=[]
    for row in rows:
        p,ell,s0,q=(row[n] for n in ['p','ell','s0','q']);prediction=static[p,ell,s0,q]
        assert tuple(row['services'])==prediction['services'] and tuple(row['receipts'])==prediction['receipts']
        assert tuple(row['waiting_polls'])==prediction['waiting_polls'];counts['source_callback_edges']+=60
        cycle=prediction['cycle'];J=max(c-s for s,c,nxt in cycle);G=max(nxt-c for s,c,nxt in cycle)
        if J<=q:counts['other_cycles']+=1;continue
        counts['joint_extremal_cycles']+=1;assert G==q
        R=tuple((s,c) for s,c,nxt in cycle);C=tuple(c for s,c in R);gmax=max(nxt-s for s,c,nxt in cycle)
        assert gmax==J+q and {c%p for c in C}=={0}
        local={'p':p,'ell':ell,'s0':s0,'q':q,'J':J,'G':G,'cycle':cycle,'shift':prediction['shift'],'gain_queries':0}
        for K in range(1,J+q+3):
            base=(K-1)*p
            for phi in range(p):
                M=margin(C,J,K,p,phi);gamma=historical(R,K,p,phi);pr=profile(R,K,p,phi)
                actual=min(expiry(s+1,K,p,phi)-nxt for s,c,nxt in cycle)
                RU=base-J+1;PP=expiry(min(C)-J+1,K,p,phi)-max(C)
                assert M==gamma==pr==base-J+1+(phi+J-1)%p
                assert actual==M-q
                rp=G<M;ru=G<RU;pp=G<PP;hp=G<gamma;ap=actual>0;su=gmax<base+1
                assert rp==hp==ap and (not ru or rp) and (not pp or rp) and ru==su
                gain=rp and not ru and not pp
                expected=(J+q)%p!=0 and K==(J+q)//p+1 and (phi+J-1)%p>=(J+q)%p
                assert (rp and not su)==expected
                counts['policy_queries']+=1
                for name,flag in [('RP_certified',rp),('RU_certified',ru),('PP_certified',pp),('history_certified',hp),('actual_phase_certified',ap),('strong_service_uniform_certified',su),('RP_gain_both',gain),('RP_gain_over_strong_service_uniform',rp and not su)]:counts[name]+=int(flag)
                local['gain_queries']+=int(gain)
        per_config.append(local)
    assert counts['source_configurations']==len(static)
    histories=misses=0
    for s,h in [(3,11),(11,28)]:
        n,m=checked_step(s,h,4,5,0);histories+=n;misses+=m
    assert misses==0
    controls={}
    for name,updates in [('wrong_phase',(12,)),('boundary_cancel',(11,))]:
        one=tick_reads((3,11,28,36),updates,4,5,2,trace=True);two=arm_reads((3,11,28,36),updates,4,5,2)
        assert one['reads']==two['reads'] and one['first_miss']==two['first_miss']
        assert one['first_miss']==(28 if name=='wrong_phase' else None)
        controls[name]=one
    result={'result':'PASS_MIXED_SOURCE_AND_JOINT_EXTREMAL_CYCLE_AUDIT','scope':spec['scientific_boundary'],
        'protocol_sha256':sha(HERE/'MIXED_POLL_PROTOCOL.json'),'script_sha256':sha(Path(__file__)),
        'public_source_sha256':sha(source),'source_events_sha256':sha(build/'events.json'),
        'generated_source_sha256':sha(cpp),'binary_sha256':sha(binary),
        'function_bindings':[{'name':d[0],'first_line':d[2],'last_line':d[3],'sha256':hashlib.sha256(d[1].encode()).hexdigest()} for d in defs],
        'static_admission_and_predictions_before_execution':True,'total_configurations':588,
        'tie_contract_rejections':len(rejected),'rejected_configurations':rejected,'counts':counts,
        'cycles':per_config,'main_example':spec['predicted_main_case'],'main_local_histories':histories,'main_local_misses':misses,'controls':controls}
    (HERE/'MIXED_POLL_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:result[k] for k in ['result','total_configurations','tie_contract_rejections','counts','main_local_histories','main_local_misses']}))


if __name__=='__main__':main()
