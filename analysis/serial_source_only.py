"""Re-execute the five unchanged callback functions without legacy timer tests."""
from pathlib import Path
import argparse,hashlib,json,subprocess
from source_producer import extract,NAMES
HERE=Path(__file__).resolve().parent


def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--zig',type=Path,required=True);a=parser.parse_args()
    predictions={}
    for p in range(2,7):
        for ell in range(1,5):
            for start in range(2*p):
                c0=((start+p-1)//p+ell)*p;H=(ell+1)*p
                predictions[p,ell,start]={'s':(start,)+tuple(c0+n*H+1 for n in range(12)),
                    'c':tuple(c0+n*H for n in range(12))}
    source=HERE/'upstream-memtest.cc';text=source.read_text(encoding='utf-8');definitions=[(n,*extract(text,n)) for n in NAMES]
    build=HERE/'serial-client-build';assert not (build/'events.json').exists(),'Use a fresh extraction directory';build.mkdir(exist_ok=True)
    cpp=build/'serial_client.cpp';cpp.write_text(text[:text.index('*/')+2]+'\n'+(HERE/'serial_client.prefix.cpp').read_text(encoding='utf-8')+'\n'+
        '\n\n'.join(d[1] for d in definitions)+'\n'+(HERE/'serial_client.suffix.cpp').read_text(encoding='utf-8')+'\n'+
        (HERE/'serial_client.main.cpp').read_text(encoding='utf-8'),encoding='utf-8')
    for name,d,_,_ in definitions:assert extract(cpp.read_text(encoding='utf-8'),name)[0]==d
    binary=build/'serial_client.exe';c=subprocess.run([str(a.zig),'c++','-std=c++17','-O2','-UNDEBUG',str(cpp),'-o',str(binary)],capture_output=True,text=True,timeout=120)
    (build/'compiler.log').write_text(c.stdout+c.stderr,encoding='utf-8');assert c.returncode==0,c.stderr
    r=subprocess.run([str(binary)],capture_output=True,text=True,timeout=60)
    (build/'execution.log').write_text(r.stdout+'\n'+r.stderr,encoding='utf-8');assert r.returncode==0,r.stderr
    rows=json.loads(r.stdout);(build/'events.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8')
    cases=edges=pairs=rejects=0
    for row in rows:
        if row['variant']:
            assert (not row['all_reads']) if row['variant']==1 else (not row['no_retry']);rejects+=1;continue
        p,ell,s0=(row[k] for k in ['p','ell','initial_service']);s,c=row['services'],row['receipts']
        assert tuple(s)==predictions[p,ell,s0]['s'] and tuple(c)==predictions[p,ell,s0]['c']
        assert tuple(row['waiting_polls'])==tuple(t+1 for t in s[:12]) and all(s[n]+1<c[n] for n in range(12))
        assert all(c[n]-s[n]==(ell+1)*p-1 for n in range(1,12))
        cases+=1;edges+=12;pairs+=11
    assert (cases,edges,pairs,rejects)==(160,1920,1760,2)
    result={'source_cases':cases,'callback_edges':edges,'maximum_delay_pairs':pairs,'rejected_variants':rejects,
            'public_source_sha256':sha(source),'source_events_sha256':sha(build/'events.json'),
            'function_bindings':[{'name':d[0],'first_line':d[2],'last_line':d[3],'sha256':hashlib.sha256(d[1].encode()).hexdigest()} for d in definitions],
            'scope':'Five functions in declared stubs, not native cache or full gem5; no legacy interval-timer assertions executed.'}
    (HERE/'SERIAL_CLIENT_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps(result))


if __name__=='__main__':main()
