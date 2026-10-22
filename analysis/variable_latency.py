"""Execute unchanged public client definitions under explicit bounded latency choices."""
from pathlib import Path
from collections import Counter
import argparse,hashlib,json,subprocess
from source_producer import NAMES,extract,expiry
from read_boundary import checked_step,tick_reads,arm_reads
from r23_canonical import canonical,envelope
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def derive(seq):
    services=[3];receipts=[];polls=[]
    for ell in seq:
        s=services[-1];c=((s+4)//5+ell)*5;assert c!=s+8
        receipts.append(c)
        if c>s+8:polls.append(s+8)
        services.append(s+8 if c<s+8 else c+8)
    return {'services':services,'receipts':receipts,'waiting_polls':polls}
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--zig',type=Path,required=True);a=parser.parse_args()
    out=HERE/'VARIABLE_LATENCY_RESULTS.json';assert not out.exists()
    build=HERE/'variable-latency-build-r1';assert not build.exists();build.mkdir()
    spec=json.loads((HERE/'VARIABLE_LATENCY_PROTOCOL.json').read_text(encoding='utf-8'))
    edges={(3,1):(7,8,1,1),(3,2):(12,20,8,3),(1,1):(9,17,8,3),(1,2):(14,22,8,3)}
    for (phase,ell),(delay,gap,age,nxt) in edges.items():
        s=phase;c=((s+4)//5+ell)*5;h=s+8 if c<s+8 else c+8
        assert (c-s,h-s,h-c,h%5)==(delay,gap,age,nxt)
    predictions={mask:derive([1+((mask>>i)&1) for i in range(8)]) for mask in range(256)}
    (build/'STATIC_PREDICTIONS.json').write_text(json.dumps(predictions,indent=2)+'\n',encoding='utf-8')
    source=HERE/'upstream-memtest.cc';text=source.read_text(encoding='utf-8');defs=[(n,*extract(text,n)) for n in NAMES]
    prefix=(HERE/'serial_client.prefix.cpp').read_text(encoding='utf-8')
    suffix=(HERE/'serial_client.suffix.cpp').read_text(encoding='utf-8')
    target='((curTick()+memtest.cache_period-1)/memtest.cache_period+memtest.lat_cycles)*memtest.cache_period'
    assert prefix.count(target)==0 and suffix.count(target)==1
    suffix=suffix.replace(target,'((curTick()+memtest.cache_period-1)/memtest.cache_period+response_latencies.at(latency_index++))*memtest.cache_period')
    globals_text='#include <vector>\n#include <cstddef>\nstatic std::vector<unsigned> response_latencies;static size_t latency_index=0;\n'
    cpp=build/'variable_latency.cpp'
    cpp.write_text(text[:text.index('*/')+2]+'\n'+globals_text+prefix+'\n'+'\n\n'.join(d[1] for d in defs)+'\n'+
      suffix+'\n'+(HERE/'variable_latency.main.cpp').read_text(encoding='utf-8'),encoding='utf-8')
    for name,d,_,_ in defs:assert extract(cpp.read_text(encoding='utf-8'),name)[0]==d
    binary=build/'variable_latency.exe';c=subprocess.run([str(a.zig),'c++','-std=c++17','-O2','-UNDEBUG',str(cpp),'-o',str(binary)],capture_output=True,text=True,timeout=120)
    (build/'compiler.log').write_text(c.stdout+c.stderr,encoding='utf-8');assert c.returncode==0,c.stderr
    run=subprocess.run([str(binary)],capture_output=True,text=True,timeout=60)
    (build/'execution.log').write_text(run.stdout+'\n'+run.stderr,encoding='utf-8');assert run.returncode==0,run.stderr
    rows=json.loads(run.stdout);assert len(rows)==256 and {r['mask'] for r in rows}==set(range(256))
    (build/'events.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8')
    census=Counter()
    for r in rows:
        assert all(r[k]==predictions[r['mask']][k] for k in ['services','receipts','waiting_polls'])
        assert r['latencies']==[1+((r['mask']>>i)&1) for i in range(8)]
        for s,c,h,ell in zip(r['services'],r['receipts'],r['services'][1:],r['latencies']):
            k=(s%5,ell);assert (c-s,h-s,h-c,h%5)==edges[k];census[k]+=1
    assert sum(census.values())==2048 and set(census)==set(edges)
    T=((3,10,11),(3,15,23),(11,20,28),(11,25,33));pairs=((3,20),(1,22));core=canonical(pairs,5)
    assert core==((1,22),) and envelope(core,5)==envelope(pairs,5)
    checks=0
    for K in range(1,8):
        for phi in range(5):
            exact=min(expiry(s+1,K,5,phi)-h for s,c,h in T)
            compressed=(K-1)*5-21+(phi+3)%5
            assert exact==compressed==(K-1)*5+1+envelope(core,5)[phi];checks+=1
    safe=[phi for phi in range(5) if min(expiry(s+1,5,5,phi)-h for s,c,h in T)>0];assert safe==[0,1,4]
    histories=misses=0
    for s,c,h in T:
        n,m=checked_step(s,h,5,5,0);histories+=n;misses+=m
    assert histories==727 and misses==0
    controls={}
    for label,phi,wu,expected in [('safe',0,[12],None),('wrong_phase',2,[12],33),('same_tick_expiry',3,[12],33),('same_tick_cancel',2,[11],None),('no_update',2,[],None)]:
        reads=(3,11,33);one=tick_reads(reads,wu,5,5,phi,trace=True);two=arm_reads(reads,wu,5,5,phi)
        assert one['reads']==two['reads'] and one['first_miss']==two['first_miss']==expected
        controls[label]={'phi':phi,'WU':wu,'trace':one}
    result={'result':'PASS_VARIABLE_LATENCY_PUBLIC_SOURCE_AND_CLOSED_PHASE_GRAPH','protocol_sha256':sha(HERE/'VARIABLE_LATENCY_PROTOCOL.json'),
      'script_sha256':sha(Path(__file__)),'driver_sha256':sha(HERE/'variable_latency.main.cpp'),'public_source_sha256':sha(source),
      'source_events_sha256':sha(build/'events.json'),'generated_source_sha256':sha(cpp),'binary_sha256':sha(binary),
      'function_bindings':[{'name':d[0],'first_line':d[2],'last_line':d[3],'sha256':hashlib.sha256(d[1].encode()).hexdigest()} for d in defs],
      'new_source_function_execution':True,'latency_choice_strings':len(rows),'source_callback_edges':2048,'source_accepted_reads':2304,
      'relative_edge_census':[{'source_phase':k[0],'ell':k[1],'executions':v} for k,v in sorted(census.items())],
      'closed_graph_representatives':T,'J':14,'A':8,'actual_max_service_gap':22,'unpruned_profile':pairs,'canonical_profile':core,
      'safe_K5_phases':safe,'minimum_phase_load':5,'minimum_uniform_load':6,'policy_checks':checks,
      'local_complete_boundary_histories':histories,'local_model_misses':misses,'controls':controls,
      'scientific_boundary':spec['scientific_boundary']}
    out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:result[k] for k in ['result','latency_choice_strings','source_callback_edges','source_accepted_reads','relative_edge_census','J','A','canonical_profile','safe_K5_phases','minimum_phase_load','minimum_uniform_load','local_complete_boundary_histories','local_model_misses']}))
if __name__=='__main__':main()
