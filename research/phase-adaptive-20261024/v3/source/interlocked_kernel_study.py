"""Compile a public kernel, preserve its result, replay its input-read order.
The refresh writer and compute costs are explicit scenario assumptions.
"""
from pathlib import Path
import subprocess,json,hashlib,time,os
from itertools import product
import interlocked_model as c
HERE=Path(__file__).resolve().parent
compiler=json.loads(os.environ.get('HUSH_C_COMPILER_JSON','["cc"]'))
source=HERE/'kernel-source/fir2dim-original.c';text=source.read_text()
assert 'License: may be used, modified, and re-distributed freely' in text
helper='''static float hush_shared_read(float *p) {
  printf("R %ld\\n", (long)(p - fir2dim_array));
  return *p;
}
'''
t='#include <stdio.h>\n'+text
t=t.replace('void fir2dim_init()\n{',helper+'\nvoid fir2dim_init()\n{')
for name in ['parray','parray2','parray3']:
 old='*pcoeff++ **'+name+'++';assert t.count(old)==1
 t=t.replace(old,'*pcoeff++ *hush_shared_read('+name+'++)')
old='for ( k = 0 ; k < 4 ; k++ ) {';assert t.count(old)==1
t=t.replace(old,old+'\n    if (k < 2) printf("P %d\\n",k);')
old='  fir2dim_result = fir2dim_output[ 0 ] + fir2dim_output[ 5 ] + fir2dim_array[ 9 ];'
assert t.count(old)==1
t=t.replace(old,'  printf("P 2\\n");\n'+old.replace('fir2dim_array[ 9 ]','hush_shared_read(&fir2dim_array[9])'))
instrumented=HERE/'kernel-source/fir2dim-instrumented.c';instrumented.write_text(t,newline='\n')
runs=[]
for s in [source,instrumented]:
 exe=s.with_suffix('.exe')
 p=subprocess.run([*compiler,'-O2','-std=c99','-Wno-unknown-pragmas',str(s),'-o',str(exe)],capture_output=True,text=True,timeout=120)
 assert p.returncode==0,p.stderr
 p=subprocess.run([str(exe)],capture_output=True,text=True,timeout=30)
 assert p.returncode==0,p.stderr
 runs.append(p)
trace=[]
for line in runs[1].stdout.splitlines():
 kind,value=line.split();value=int(value)
 assert kind in ['P','R']
 if kind=='R':assert 0<=value<36
 trace.append((kind,value))
assert sum(k=='R' for k,v in trace)==145
assert [v for k,v in trace if k=='P']==[0,1,2]
(HERE/'kernel-source/read-trace.json').write_text(json.dumps(trace,indent=2)+'\n',newline='\n')
base=dict(c.P);c.P.update(shared_blocks=3,writer_store_count=192)
start=time.perf_counter();rows=[]
for compute,gap in product([1,4,16],[0,4,16]):
 ops=[]
 for kind,v in trace:
  if kind=='P':ops.append(('phase',v))
  else:ops.extend([('compute',compute),('read',(4*v)//64)])
 a={ks:c.analyze(ops,ks) for ks in product(base['domain'],repeat=3)}
 phase=[c.simulate(ops,ks,gap,0,b) for ks,b in a.items() if b['feasible']]
 phase_release=[c.simulate(ops,ks,gap,0,b,flush_at_finish=True) for ks,b in a.items() if b['feasible']]
 fixed=[];fixed_release=[]
 for k in range(1,256):
  ks=(k,)*3;b=c.analyze(ops,ks)
  if b['feasible']:
   fixed.append(c.simulate(ops,ks,gap,0,b))
   fixed_release.append(c.simulate(ops,ks,gap,0,b,flush_at_finish=True))
 choose=lambda xs:min(xs,key=lambda r:(r['makespan'],r['reader_cycles'],r['updates'],r['K'])) if xs else None
 f=choose(fixed);p=choose(phase);held=[]
 if f and p:
  for phi in range(1,10):held.append({'phi':phi,'fixed':c.simulate(ops,tuple(f['K']),gap,phi),
                                    'phase':c.simulate(ops,tuple(p['K']),gap,phi)})
 rows.append({'compute_gap':compute,'writer_gap':gap,'fixed':f,'phase':p,'heldout':held,
              'fixed_end_release':choose(fixed_release),'phase_end_release':choose(phase_release),
              'budget':next(iter(a.values()))['budget']})
result={'scope':'Compiled TACLeBench input-read order in a declared two-core refresh scenario; not native application cycles or multicore functional benchmarking',
 'protocol_sha256':hashlib.sha256((HERE/'kernel_protocol.json').read_bytes()).hexdigest(),
 'model_sha256':hashlib.sha256((HERE/'interlocked_model.py').read_bytes()).hexdigest(),
 'original_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
 'instrumented_sha256':hashlib.sha256(instrumented.read_bytes()).hexdigest(),
 'trace_sha256':hashlib.sha256((HERE/'kernel-source/read-trace.json').read_bytes()).hexdigest(),
 'original_and_instrumented_return_codes':[p.returncode for p in runs],
 'input_reads':145,'shared_lines':3,'records':rows,'elapsed_seconds':time.perf_counter()-start}
(HERE/'INTERLOCKED_KERNEL_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n')
for r in rows:print(r['compute_gap'],r['writer_gap'],'fixed',r['fixed'] and [r['fixed'][k] for k in ['K','makespan','reader_cycles','actual_misses','updates']],
 'phase',r['phase'] and [r['phase'][k] for k in ['K','makespan','reader_cycles','actual_misses','updates']],
 'release_control',[r['fixed_end_release']['makespan'],r['phase_end_release']['makespan']])
