"""Execute unchanged public MemTest functions in declared stubs; model counters.

This is not a complete gem5/cache execution. The static query is computed
before the emitted realized timestamps are loaded and uses only source-derived
clock/cost contracts and the supplied modular entry window.
"""
from pathlib import Path
import argparse,hashlib,itertools,json,re,subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
NAMES=['MemTest::tick','MemTest::sendPkt','MemTest::recvRetry',
       'MemTest::completeRequest','MemTest::CpuPort::recvTimingResp']


def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def extract(text,name):
    match=re.search(r'(?:void|bool)\s+'+re.escape(name)+r'\([^)]*\)\s*\{',text)
    assert match,name
    pos=text.index('{',match.start())+1;depth=1
    while depth:depth+=(text[pos]=='{')-(text[pos]=='}');pos+=1
    return text[match.start():pos],text.count('\n',0,match.start())+1,text.count('\n',0,pos)+1


def expiry(r,K,P,phi):return r+(phi-r)%P+(K-1)*P


def margin(C,J,K,P,phi):return min(expiry(c-J,K,P,phi)-c for c in C)


def tick_counter(s,h,updates,K,P,phi):
    valid=True;enabled=False;value=0
    for t in range(s,h+1):
        # Load-before-decrement: a WU at an old deadline may postpone it.
        if t in updates and valid:value=K;enabled=True
        if (t-phi)%P==0 and enabled:
            value-=1
            if value==0:enabled=False;valid=False
    return valid


def arm_map(s,h,updates,K,P,phi):
    valid=True;deadline=None
    for r in updates:
        if deadline is not None and deadline<r:valid=False
        if valid:deadline=expiry(r,K,P,phi)
    if deadline is not None and deadline<=h:valid=False
    return valid


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--zig',type=Path,required=True);args=parser.parse_args()
    # Static modular source-derived facts, before reading any emitted event.
    entry=range(100,107,2);cache_tag=3;cache_data=2
    latencies={'parallel':max(cache_tag,cache_data),'sequential':cache_tag+cache_data}
    J=max(latencies.values());L=0;producer_period=2;interval_cycles=2
    G=producer_period*interval_cycles+producer_period-1
    C=sorted({s+d for s in entry for d in latencies.values()})
    K,P,phi=6,2,1
    set_margin=margin(C,J,K,P,phi);hull_margin=margin(range(C[0],C[-1]+1),J,K,P,phi)
    uniform=(K-1)*P-J;upper_h=max(C)+G
    safe=G+L<set_margin
    decisions={'set_phase_relative':safe,'hull_phase_relative':G+L<hull_margin,
               'uniform_relative':G+L<uniform,
               'best_independent':upper_h<expiry(min(entry),K,P,phi)}
    static={'entry_service_set':list(entry),'fixed_mode_latency_ticks':latencies,'J':J,'L':L,'G':G,
            'C':C,'K':K,'P':P,'phi':phi,'priority':'load-before-decrement',
            'set_margin':set_margin,'hull_margin':hull_margin,'uniform_margin':uniform,
            'h_upper':upper_h,'service_lower_expiry':expiry(min(entry),K,P,phi),'decisions':decisions}
    assert safe and sum(decisions.values())==1
    source=HERE/'upstream-memtest.cc';text=source.read_text(encoding='utf-8')
    definitions=[(n,*extract(text,n)) for n in NAMES]
    build=HERE/'source-producer-build';build.mkdir(exist_ok=True)
    notice=text[:text.index('*/')+2]+'\n'
    cpp=build/'producer.cpp'
    cpp.write_text(notice+(HERE/'memtest_stub.prefix.cpp').read_text(encoding='utf-8')+'\n'+
                   '\n\n'.join(d[1] for d in definitions)+'\n'+
                   (HERE/'memtest_stub.suffix.cpp').read_text(encoding='utf-8'),encoding='utf-8')
    generated=cpp.read_text(encoding='utf-8')
    for name,definition,_,_ in definitions:assert extract(generated,name)[0]==definition
    binary=build/'producer.exe'
    compiler=subprocess.run([str(args.zig),'c++','-std=c++17','-O2','-UNDEBUG',str(cpp),'-o',str(binary)],capture_output=True,text=True,timeout=180)
    (build/'compiler.log').write_text(compiler.stdout+compiler.stderr,encoding='utf-8')
    assert compiler.returncode==0,compiler.stderr
    run=subprocess.run([str(binary)],capture_output=True,text=True,timeout=60)
    (build/'execution.log').write_text(run.stdout+'\n'+run.stderr,encoding='utf-8')
    assert run.returncode==0,run.stderr
    rows=json.loads(run.stdout);(build/'producer_events.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8')
    assert len(rows)==24
    counts={'source_function_scenarios':len(rows),'admitted_event_traces':0,'write_contract_rejections':0,
            'retry_contract_rejections':0,'bound_violations':0,'counter_histories':0,
            'counter_model_disagreements':0,'certified_false_hits':0,
            'wrong_phase_negative_control_false_hits':0}
    observed_gaps=set();witness=None
    for row in rows:
        if row['variant']==1:
            assert not row['all_reads'];counts['write_contract_rejections']+=1;continue
        if row['variant']==2:
            assert not row['no_retry'];counts['retry_contract_rejections']+=1;continue
        counts['admitted_event_traces']+=1
        s,c,a=(row[k] for k in ['previous_service','completion_callback','next_ingress'])
        delay=latencies[row['mode']];expected_gap=1 if row['mode']=='parallel' else 5
        counts['bound_violations']+=not(s in entry and c in C and c-s==delay and a-c==expected_gap and 0<=a-c<=G)
        assert row['all_reads'] and row['no_retry']
        observed_gaps.add(a-c)
        h=a
        for number in range(3):
            for updates in itertools.combinations(range(s,h+1),number):
                one=tick_counter(s,h,updates,K,P,phi);two=arm_map(s,h,updates,K,P,phi)
                bad=tick_counter(s,h,updates,K,P,0)
                counts['counter_histories']+=1;counts['counter_model_disagreements']+=one!=two
                counts['certified_false_hits']+=safe and not one
                counts['wrong_phase_negative_control_false_hits']+=safe and not bad
                if not bad and witness is None:witness={'s':s,'c':c,'a':a,'WU_ticks':updates,'actual_phi':0,'incorrectly_assumed_phi':phi}
    assert counts['bound_violations']==counts['counter_model_disagreements']==counts['certified_false_hits']==0
    assert observed_gaps=={1,5} and counts['admitted_event_traces']==8
    assert counts['write_contract_rejections']==counts['retry_contract_rejections']==8
    assert counts['wrong_phase_negative_control_false_hits']>0
    report={'scope':'Unchanged public producer functions in packet/RNG/port/event stubs; independent behavioral counter, not a complete gem5/cache run',
            'static_analysis_before_event_read':static,'source_sha256':sha(source),'script_sha256':sha(Path(__file__)),
            'protocol_sha256':sha(HERE/'SOURCE_PRODUCER_AND_PHASE_PROTOCOL.json'),
            'functions':[{'name':d[0],'first_line':d[2],'last_line':d[3],
                          'sha256':hashlib.sha256(d[1].encode()).hexdigest()} for d in definitions],
            'compiler':'Zig 0.14.1, Windows native, C++17 -O2 -UNDEBUG; NDEBUG absence checked at preprocessing','binary_sha256':sha(binary),'cpp_sha256':sha(cpp),
            'prefix_sha256':sha(HERE/'memtest_stub.prefix.cpp'),'suffix_sha256':sha(HERE/'memtest_stub.suffix.cpp'),
            'counts':counts,'observed_admitted_gaps':sorted(observed_gaps),'negative_witness':witness,
            'not_claimed':['Full event scheduler or cache-pipeline execution','Native HUSH coarse-counter implementation',
                           'Measured instruction/WCET bounds','Real-program prevalence or performance','Unbounded retry/response-backpressure coverage']}
    (HERE/'SOURCE_PRODUCER_RESULTS.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(report))


if __name__=='__main__':main()
