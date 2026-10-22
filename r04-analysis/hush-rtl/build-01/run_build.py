"""Numbered preserved Yosys/CXXRTL build attempts. No research outcome rewriting."""
from pathlib import Path
import argparse,hashlib,json,shutil,subprocess,sys,time
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--attempt',required=True);ap.add_argument('--vectors',type=Path,required=True);a=ap.parse_args()
 build=HERE/a.attempt;build.mkdir(exist_ok=False)
 for n in ['receiver.v','driver.cpp','PROTOCOL.json','run_build.py']:shutil.copyfile(HERE/n,build/n)
 python=Path(sys.executable);zig=ROOT/'.tools/zig-0.14.1/zig-x86_64-windows-0.14.1/zig.exe';wrapper=ROOT/'.tools/run_iscas_yosys.py';include=ROOT/'.tools/iscas-rtl-20261023/yowasp_yosys/share/include/backends/cxxrtl/runtime'
 cmds=[['yosys_version',[str(python),'-B','-X','utf8',str(wrapper),'-V']],['synthesis',[str(python),'-B','-X','utf8',str(wrapper),'-p','read_verilog receiver.v; hierarchy -check -top receiver; prep -top receiver; check -assert; write_cxxrtl netlist.cpp']],['compile',[str(zig),'c++','-std=c++17','-O3','-UNDEBUG','-I',str(include),'driver.cpp','-o','simulate.exe']],['simulation',[str(build/'simulate.exe'),str(a.vectors.resolve()),str(build.resolve())]]]
 report={'attempt':a.attempt,'started_unix':time.time(),'python':str(python),'zig_sha256':sha(zig),'yosys_wrapper_sha256':sha(wrapper),'inputs':{n:sha(build/n) for n in ['receiver.v','driver.cpp','PROTOCOL.json','run_build.py']},'commands':[],'claim':'New reference RTL only; actual generated CXXRTL model required.'}
 for name,cmd in cmds:
  started=time.time();p=subprocess.run(cmd,cwd=build,capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=600)
  (build/(name+'.stdout.log')).write_text(p.stdout,encoding='utf-8');(build/(name+'.stderr.log')).write_text(p.stderr,encoding='utf-8')
  report['commands'].append({'name':name,'argv':cmd,'returncode':p.returncode,'elapsed_seconds_not_performance_evidence':time.time()-started})
  report['status']='FAILED_'+name.upper() if p.returncode else 'IN_PROGRESS'
  (build/'BUILD.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');print(name,p.returncode,flush=True)
  if p.returncode:return p.returncode
 report['status']='EXECUTED_GENERATED_RTL_NETLIST';report['generated_sha256']={n:sha(build/n) for n in ['netlist.cpp','simulate.exe','RTL_RESULTS.json']};(build/'BUILD.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');return 0
if __name__=='__main__':raise SystemExit(main())
