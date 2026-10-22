"""Prospective periodic polling branch: public functions in declared stubs."""
from pathlib import Path
import argparse,hashlib,json,math,subprocess
from source_producer import extract,NAMES,expiry
from read_boundary import margin,historical,profile,checked_step
HERE=Path(__file__).resolve().parent


def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()


def ctarget(s,p,ell):return ((s+p-1)//p+ell)*p


def relation(p,ell,s0,q,P):
    N=math.lcm(p,P)//math.gcd(q,math.lcm(p,P))
    return tuple((s0+n*q,ctarget(s0+n*q,p,ell)) for n in range(N))


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--zig',type=Path,required=True);a=parser.parse_args()
    protocol=HERE/'PERIODIC_POLL_PROTOCOL.json';spec=json.loads(protocol.read_text(encoding='utf-8'))
    # Exact predictions and relations are calculated before the new binary exists.
    static={}
    for p in range(2,7):
        for ell in range(1,5):
            for q in range((ell+1)*p,(ell+2)*p):
                for s0 in range(p):
                    assert q>(ell+1)*p-1
                    static[p,ell,s0,q]={'s':tuple(s0+n*q for n in range(61)),
                        'c':tuple(ctarget(s0+n*q,p,ell) for n in range(60)),
                        'policies':{P:relation(p,ell,s0,q,P) for P in range(1,10)}}
    assert len(static)==360
    worked=tuple((s,ctarget(s,4,1)) for s in (100,109,118,127));C=tuple(c for s,c in worked)
    assert worked==tuple(map(tuple,spec['predicted_worked_example']['R_first_four']))
    assert (margin(C,7,4,4,2),historical(worked,4,4,2))==(6,6)
    assert (margin(C,7,2,9,8),historical(worked,2,9,8))==(3,9)
    source=HERE/'upstream-memtest.cc';text=source.read_text(encoding='utf-8')
    definitions=[(name,*extract(text,name)) for name in NAMES]
    build=HERE/'periodic-poll-build';assert not (build/'events.json').exists(),'Preserve an executed run; choose another directory'
    build.mkdir(exist_ok=True);cpp=build/'periodic_poll.cpp'
    cpp.write_text(text[:text.index('*/')+2]+'\n'+(HERE/'serial_client.prefix.cpp').read_text(encoding='utf-8')+'\n'+
        '\n\n'.join(d[1] for d in definitions)+'\n'+(HERE/'serial_client.suffix.cpp').read_text(encoding='utf-8')+'\n'+
        (HERE/'periodic_poll.main.cpp').read_text(encoding='utf-8'),encoding='utf-8')
    for name,definition,_,_ in definitions:assert extract(cpp.read_text(encoding='utf-8'),name)[0]==definition
    binary=build/'periodic_poll.exe'
    compile=subprocess.run([str(a.zig),'c++','-std=c++17','-O2','-UNDEBUG',str(cpp),'-o',str(binary)],capture_output=True,text=True,timeout=120)
    (build/'compiler.log').write_text(compile.stdout+compile.stderr,encoding='utf-8');assert compile.returncode==0,compile.stderr
    run=subprocess.run([str(binary)],capture_output=True,text=True,timeout=60)
    (build/'execution.log').write_text(run.stdout+'\n'+run.stderr,encoding='utf-8');assert run.returncode==0,run.stderr
    rows=json.loads(run.stdout);(build/'events.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8')
    counts={'source_cases':0,'source_callback_edges':0,'policy_relations':0,'phase_queries':0,
            'lossless_policy_relations':0,'lossy_policy_relations':0,'margin_mismatches':0}
    for row in rows:
        p,ell,s0,q=(row[k] for k in ['p','ell','s0','q'])
        predicted=static.get((p,ell,s0,q))
        if predicted is None:
            assert (p,ell,s0,q)==(4,1,100,9)
            assert tuple(row['services'][:4])==tuple(s for s,c in worked)
            assert tuple(row['receipts'][:4])==C
            continue
        assert tuple(row['services'])==predicted['s'] and tuple(row['receipts'])==predicted['c']
        counts['source_cases']+=1;counts['source_callback_edges']+=60
        for P,R in predicted['policies'].items():
            n=len(R);assert tuple(zip(row['services'][:n],row['receipts'][:n]))==R
            shift=n*q;assert shift%p==shift%P==0
            assert all(ctarget(s+shift,p,ell)==c+shift for s,c in R)
            J=max(c-s for s,c in R);Cpolicy=tuple(c for s,c in R)
            witnessed={c%P for s,c in R if c-s==J}=={c%P for s,c in R};equal=True
            for phi in range(P):
                for K in (1,J+2):
                    m=margin(Cpolicy,J,K,P,phi);gamma=historical(R,K,P,phi)
                    assert gamma==profile(R,K,P,phi) and gamma>=m
                    equal &= gamma==m;counts['phase_queries']+=1
            assert equal==witnessed;counts['policy_relations']+=1
            counts['lossless_policy_relations' if witnessed else 'lossy_policy_relations']+=1
    assert counts['source_cases']==360 and counts['source_callback_edges']==21600
    assert counts['policy_relations']==3240 and counts['phase_queries']==32400
    histories=misses=0
    for s in (100,109,118,127):
        h,m=checked_step(s,s+9,2,9,8);histories+=h;misses+=m
    assert histories==224 and misses==0
    seeds=0
    for p in range(2,7):
        for ell in range(1,5):
            for s0 in range(2*p):
                actual=expiry(s0+1,ell+2,p,0)-ctarget(s0,p,ell)
                assert actual==(2*p if s0%p==0 else p);seeds+=1
    result={'result':'PASS_PERIODIC_POLL_SOURCE_AND_QUERY_CHECKS','scope':spec['interpretation'],
            'protocol_sha256':sha(protocol),'public_source_sha256':sha(source),'script_sha256':sha(Path(__file__)),
            'function_bindings':[{'name':d[0],'sha256':hashlib.sha256(d[1].encode()).hexdigest(),'first_line':d[2],'last_line':d[3]} for d in definitions],
            'cpp_sha256':sha(cpp),'binary_sha256':sha(binary),'events_sha256':sha(build/'events.json'),
            'static_predictions_before_execution':True,'counts':counts,'worked_example':spec['predicted_worked_example'],
            'worked_receiver_local_histories':histories,'worked_receiver_misses':misses,'original_seed_checks':seeds,
            'queue_function_execution':False,'native_cache_execution':False}
    (HERE/'PERIODIC_POLL_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps(result))


if __name__=='__main__':main()
