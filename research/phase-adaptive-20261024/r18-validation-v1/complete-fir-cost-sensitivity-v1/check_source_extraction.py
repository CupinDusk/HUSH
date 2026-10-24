"""Optionally recompile unchanged C and match the full source event sequence."""
from pathlib import Path
import hashlib, json, os, subprocess
HERE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
compiler=json.loads(os.environ.get('HUSH_C_COMPILER_JSON','["cc"]'))
assert isinstance(compiler,list) and compiler and all(isinstance(x,str) for x in compiler)
version=subprocess.check_output([*compiler,'--version'],text=True).splitlines()[0]
rows=[]
build=HERE/'source-compile-check';build.mkdir(exist_ok=True)
for name in ['fir2dim-original.c','fir2dim-all-data.c']:
    source=HERE/name;binary=build/(Path(name).stem+('.exe' if os.name=='nt' else ''))
    compile_run=subprocess.run([*compiler,'-O2','-std=c99','-Wno-unknown-pragmas',str(source),'-o',str(binary)],capture_output=True,text=True,timeout=120)
    assert compile_run.returncode==0,compile_run.stderr
    execution=subprocess.run([str(binary)],capture_output=True,text=True,timeout=30)
    assert execution.returncode==0,execution.stderr
    row={'source':name,'source_sha256':sha(source),'compiler_version':version,
         'compile_return_code':compile_run.returncode,'program_return_code':execution.returncode,
         'stdout_sha256':hashlib.sha256(execution.stdout.encode()).hexdigest()}
    if name=='fir2dim-all-data.c':
        events=[line.split() for line in execution.stdout.splitlines()]
        expected=json.loads((HERE/'ALL_DATA_TRACE.json').read_text(encoding='utf-8'))
        assert events==expected
        assert ['RESULT','14'] in events
        row.update(trace_exact=True,global_data_events=sum(e[0]=='D' for e in events),checksum=14)
    rows.append(row)
(HERE/'FRESH_SOURCE_EXTRACTION_AUDIT.json').write_text(json.dumps({'checks':rows,'all_passed':True},indent=2)+'\n',encoding='utf-8')
print('Both original and instrumented C passed; regenerated full event trace is byte-structure exact; checksum14.')
