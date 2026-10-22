"""Preserved actual Yosys/CXXRTL attempts; no elapsed-time performance claim."""
from pathlib import Path
import argparse,hashlib,json,shutil,subprocess,sys
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--root',type=Path,default=HERE.parents[3]);ap.add_argument('--attempt',required=True);ap.add_argument('--mode',choices=['control','policies'],default='control');ap.add_argument('--input',type=Path);a=ap.parse_args()
 build=HERE/a.attempt;build.mkdir(exist_ok=False)
 for n in ['receiver.v','driver.cpp','PROTOCOL.json','AMENDMENT_01_PRE_EXECUTION.md','AMENDMENT_02_FULL_KEY_EXTENSION.md','run_build.py']:shutil.copyfile(HERE/n,build/n)
 root=a.root.resolve();zig=root/'.tools/zig-0.14.1/zig-x86_64-windows-0.14.1/zig.exe';wrapper=root/'.tools/run_iscas_yosys.py';inc=root/'.tools/iscas-rtl-20261023/yowasp_yosys/share/include'
 commands=[('yosys_version',[sys.executable,'-B','-X','utf8',str(wrapper),'-V']),('synthesis',[sys.executable,'-B','-X','utf8',str(wrapper),'-p','read_verilog receiver.v; hierarchy -check -top receiver; prep -top receiver; check -assert; write_cxxrtl netlist.cpp']),('compile',[str(zig),'c++','-std=c++17','-O3','-UNDEBUG','-I',str(inc),'-I',str(inc/'backends/cxxrtl/runtime'),'driver.cpp','-o','simulate.exe']),('execution',[str(build/'simulate.exe'),a.mode,str(build.resolve()),str(a.input.resolve()) if a.input else '-'])]
 report={'status':'IN_PROGRESS','tool_hashes':{'zig':sha(zig),'yosys_wrapper':sha(wrapper)},'input_sha256':{n:sha(build/n) for n in ['receiver.v','driver.cpp','PROTOCOL.json','AMENDMENT_01_PRE_EXECUTION.md','AMENDMENT_02_FULL_KEY_EXTENSION.md','run_build.py']},'policy_input_sha256_before_execution':sha(a.input.resolve()) if a.input else None,'commands':[],'scope':'Build durations are not measured or used as performance evidence.'}
 for name,cmd in commands:
  p=subprocess.run(cmd,cwd=build,capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=1800)
  (build/(name+'.stdout.log')).write_text(p.stdout,encoding='utf-8');(build/(name+'.stderr.log')).write_text(p.stderr,encoding='utf-8')
  report['commands'].append({'name':name,'argv':cmd,'returncode':p.returncode});report['status']='FAILED_'+name if p.returncode else 'IN_PROGRESS'
  (build/'BUILD.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');print(name,p.returncode,flush=True)
  if p.returncode:return p.returncode
 report['status']='EXECUTED_GENERATED_RTL';report['generated_sha256']={n:sha(build/n) for n in ['netlist.cpp','simulate.exe']};(build/'BUILD.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
 return 0
if __name__=='__main__':raise SystemExit(main())
