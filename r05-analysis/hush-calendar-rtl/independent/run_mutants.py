"""Actual synthesis and compilation for independently checked RTL mutants."""
from pathlib import Path
import subprocess,sys,json,hashlib
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[4]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 src=(HERE/'frozen-input/receiver.v').read_text()
 cancel='evcancel[qo[0]]=enabled[qo[0]];enabled[qo[0]]=0;counts[16*qo[0]+:16]=0;'
 wu_start=src.index('   for(j=0;j<4;j=j+1)begin\n    if(wu[j]')
 decr_start=src.index('   if(pp==cfgphi)',wu_start)
 calendar_start=src.index('   // Two groups',decr_start)
 reorder=src[:wu_start]+src[decr_start:calendar_start]+src[wu_start:decr_start]+src[calendar_start:]
 mutations=[('missing-capture-cancel',src.replace(cancel,'evcancel[qo[0]]=enabled[qo[0]];')),
 ('live-byte-emission',src.replace('emitbyte=byteone;','emitbyte=bytes[8*ownerone+:8];')),
 ('decrement-before-WU',reorder),
 ('drop-duplicate-calendar-job',src.replace('if(k==1 && cfgf==40 && fp<4)','if(1\'b0)')),
 ('wrong-FIFO-grant-ID',src.replace('grantid=qi[0];','grantid=qi[1];'))]
 inc=ROOT/'.tools/iscas-rtl-20261023/yowasp_yosys/share/include'
 zig=ROOT/'.tools/zig-0.14.1/zig-x86_64-windows-0.14.1/zig.exe'
 wrapper=ROOT/'.tools/run_iscas_yosys.py'
 report=[]
 for i,(name,text) in enumerate(mutations,1):
  assert text!=src
  out=HERE/'mutants'/f'{i:02d}-{name}';out.mkdir(parents=True,exist_ok=False);(out/'receiver.v').write_text(text,encoding='utf-8')
  stages=[('synthesis',[sys.executable,'-B','-X','utf8',str(wrapper),'-p','read_verilog receiver.v; hierarchy -check -top receiver; prep -top receiver; check -assert; write_cxxrtl netlist.cpp']),('compile',[str(zig),'c++','-std=c++17','-O3','-UNDEBUG','-I',str(inc),'-I',str(inc/'backends/cxxrtl/runtime'),'-I',str(out),str(HERE/'independent.cpp'),'-o',str(out/'check.exe')]),('execution',[str(out/'check.exe'),'control',str(out)])]
  rec=dict(name=name,input_sha256=sha(out/'receiver.v'),oracle_sha256=sha(HERE/'independent.cpp'),commands=[])
  for stage,cmd in stages:
   p=subprocess.run(cmd,cwd=out,capture_output=True,text=True,encoding='utf-8',errors='replace');(out/(stage+'.stdout.log')).write_text(p.stdout,encoding='utf-8');(out/(stage+'.stderr.log')).write_text(p.stderr,encoding='utf-8');rec['commands'].append(dict(stage=stage,argv=cmd,returncode=p.returncode))
   if stage!='execution':assert p.returncode==0,(name,stage,p.stderr)
   else:assert p.returncode!=0 and (out/'INDEPENDENT_FAILURE.txt').exists(),('mutant survived',name)
  rec['first_detection']=(out/'INDEPENDENT_FAILURE.txt').read_text().strip();rec['generated_sha256']={n:sha(out/n) for n in ['netlist.cpp','check.exe']};rec['status']='DETECTED_BY_INDEPENDENT_ORACLE_AFTER_ACTUAL_COMPILE_EXECUTION';(out/'BUILD.json').write_text(json.dumps(rec,indent=2)+'\n',encoding='utf-8');report.append(rec);print(name,rec['first_detection'],flush=True)
 (HERE/'MUTANTS.json').write_text(json.dumps(dict(status='PASS_ALL_FIVE_MEANINGFUL_COMPILED_RTL_MUTANTS_DETECTED',records=report),indent=2)+'\n',encoding='utf-8')
if __name__=='__main__':main()
