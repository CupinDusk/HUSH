"""Log every explicit global data access in the selected TACLeBench entry.

Instrumentation preserves C's source evaluation order where it is fixed. The
two multiplicands in a MAC are explicitly ordered coefficient then input; their
original order is unspecified and they do not alias. printf itself is excluded
from timing: this is a source event extractor, not instrumentation overhead data.
"""
from pathlib import Path
import hashlib,json,subprocess,os

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[3]
SOURCE=HERE/'fir2dim-original.c'
if not SOURCE.exists():SOURCE=ROOT/'hush/tcad-research/iscas-2027-followup/phase-artifact/kernel-source/fir2dim-original.c'
ZIG=ROOT/'.tools/zig-0.14.1/zig-x86_64-windows-0.14.1/zig.exe'
compiler=json.loads(os.environ.get('HUSH_C_COMPILER_JSON',json.dumps([str(ZIG),'cc'] if ZIG.exists() else ['cc'])))
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
assert sha(SOURCE)=='c0f06e2396560c61417d70950360604207f37a144b900b3bb3d186f6a51d7cec'
text=SOURCE.read_text()
helper=r'''
static void event(char op, float *p) {
  const char *name; long index;
  /* uintptr comparisons avoid relational comparison of unrelated C pointers. */
  uintptr_t a=(uintptr_t)p;
  if(a>=(uintptr_t)fir2dim_array && a<(uintptr_t)(fir2dim_array+36))
    {name="array";index=p-fir2dim_array;}
  else if(a>=(uintptr_t)fir2dim_image && a<(uintptr_t)(fir2dim_image+16))
    {name="image";index=p-fir2dim_image;}
  else if(a>=(uintptr_t)fir2dim_coefficients && a<(uintptr_t)(fir2dim_coefficients+9))
    {name="coeff";index=p-fir2dim_coefficients;}
  else {name="output";index=p-fir2dim_output;}
  printf("D %c %s %ld\n",op,name,index);
}
static float rd(float *p) {event('R',p);return *p;}
static void wr(float *p,float v) {event('W',p);*p=v;}
static void mac(float *out,float *coeff,float *input) {
  float a=rd(coeff),b=rd(input),c=rd(out);wr(out,c+a*b);
}
'''
t='#include <stdio.h>\n#include <stdint.h>\n'+text
t=t.replace('void fir2dim_init()\n{',helper+'\nvoid fir2dim_init()\n{')
for old,new in [('*pimage++ = 1','wr(pimage++,1)'),('*pcoeff++ = 1','wr(pcoeff++,1)'),
                ('*parray++ = 0','wr(parray++,0)'),('*parray++ = *pimage++','wr(parray++,rd(pimage++))'),
                ('*poutput++ = 0','wr(poutput++,0)'),('*poutput = 0','wr(poutput,0)')]:
 assert old in t,old
 t=t.replace(old,new)
for p in ['parray','parray2','parray3']:
 old='*poutput += *pcoeff++ **'+p+'++'
 assert t.count(old)==1
 t=t.replace(old,'mac(poutput,pcoeff++,'+p+'++)')
call='  fir2dim_pin_down( &fir2dim_image[ 0 ], &fir2dim_array[ 0 ],\n                    &fir2dim_coefficients[ 0 ], &fir2dim_output[ 0 ] );'
assert t.count(call)==2
first=t.index(call);t=t[:first]+'  printf("S prepare\\n");\n'+t[first:]
last=t.rindex(call);t=t[:last]+'  printf("S cleanup\\n");\n'+t[last:]
old='for ( k = 0 ; k < 4 ; k++ ) {';assert t.count(old)==1
t=t.replace(old,old+'\n    if(k<2) printf("P %d\\n",k);')
old='  fir2dim_result = fir2dim_output[ 0 ] + fir2dim_output[ 5 ] + fir2dim_array[ 9 ];'
assert t.count(old)==1
t=t.replace(old,'  printf("P 2\\n");\n  fir2dim_result = rd(&fir2dim_output[0]) + rd(&fir2dim_output[5]) + rd(&fir2dim_array[9]);\n  printf("D W result 0\\n");\n  printf("RESULT %d\\n",fir2dim_result);')
instrumented=HERE/'fir2dim-all-data.c';instrumented.write_text(t,newline='\n')
(HERE/'fir2dim-original.c').write_bytes(SOURCE.read_bytes())
runs=[]
for src in [HERE/'fir2dim-original.c',instrumented]:
 exe=src.with_suffix('.exe')
 argv=[*compiler,'-O2','-std=c99','-Wno-unknown-pragmas',str(src),'-o',str(exe)]
 build=subprocess.run(argv,capture_output=True,text=True,timeout=150)
 assert build.returncode==0,build.stderr
 r=subprocess.run([str(exe)],capture_output=True,text=True,timeout=30)
 assert r.returncode==0,(src,r.stderr)
 runs.append({'source_sha256':sha(src),'return_code':r.returncode,'stdout':r.stdout,'compiler_version':subprocess.check_output([*compiler,'--version'],text=True).splitlines()[0]})
events=[line.split() for line in runs[1]['stdout'].splitlines()]
data=[e for e in events if e[0]=='D']
assert len(data)==782,len(data)
assert sum(e[1:3]==['R','array'] for e in data)==145
assert ['RESULT','14'] in events
from collections import Counter
summary=dict(Counter('/'.join(e[1:3]) for e in data))
(HERE/'ALL_DATA_TRACE.json').write_text(json.dumps(events,indent=2)+'\n')
(HERE/'COMPILE_AUDIT.json').write_text(json.dumps({'original_sha256':sha(SOURCE),'instrumented_sha256':sha(instrumented),'trace_sha256':sha(HERE/'ALL_DATA_TRACE.json'),'runs':runs,'data_accesses':len(data),'counts':summary},indent=2)+'\n')
print(json.dumps({'events':len(events),'data_accesses':len(data),'counts':summary,'return_codes':[r['return_code'] for r in runs]},indent=2))
