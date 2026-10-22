"""Fresh portable rebuild of the new reference RTL; tools stay external."""
from pathlib import Path
import argparse,hashlib,json,shutil,subprocess,sys
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path,required=True);ap.add_argument('--reference',type=Path,default=HERE/'reference-inputs');ap.add_argument('--yosys',default='yosys');ap.add_argument('--yosys-python-wrapper',type=Path);ap.add_argument('--cxx',default='c++');ap.add_argument('--zig',action='store_true');ap.add_argument('--include',type=Path,required=True);a=ap.parse_args()
 out=a.out.resolve();out.mkdir(parents=True,exist_ok=False)
 for n in ['receiver.v','driver.cpp','PROTOCOL.json']:shutil.copyfile(HERE/n,out/n)
 y=[sys.executable,'-B','-X','utf8',str(a.yosys_python_wrapper.resolve())] if a.yosys_python_wrapper else [a.yosys]
 c=[a.cxx]+(['c++'] if a.zig else [])
 commands=[('vectors',[sys.executable,'-B','-X','utf8',str(HERE/'generate_vectors.py'),'--reference',str(a.reference.resolve()),'--out',str(out/'vectors')]),('yosys_version',y+['-V']),('synthesis',y+['-p','read_verilog receiver.v; hierarchy -check -top receiver; prep -top receiver; check -assert; write_cxxrtl netlist.cpp']),('compile',c+['-std=c++17','-O3','-UNDEBUG','-I',str(a.include.resolve()),'driver.cpp','-o','simulate.exe']),('simulation',[str(out/'simulate.exe'),str(out/'vectors'),str(out)])]
 result={'kind':'fresh_portable_reference_RTL_rebuild','commands':[],'inputs':{n:sha(HERE/n) for n in ['receiver.v','driver.cpp','PROTOCOL.json','generate_vectors.py','replay_portable.py']},'status':'IN_PROGRESS'}
 for name,cmd in commands:
  r=subprocess.run(cmd,cwd=out,capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=600)
  (out/(name+'.stdout.log')).write_text(r.stdout,encoding='utf-8');(out/(name+'.stderr.log')).write_text(r.stderr,encoding='utf-8');result['commands'].append({'name':name,'argv':cmd,'returncode':r.returncode})
  result['status']='FAILED_'+name.upper() if r.returncode else 'IN_PROGRESS';(out/'PORTABLE_REPLAY.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
  print(name,r.returncode,flush=True)
  if r.returncode:return r.returncode
 result['status']='EXECUTED_GENERATED_REFERENCE_RTL';result['outputs']={n:sha(out/n) for n in ['netlist.cpp','simulate.exe','RTL_RESULTS.json','CONTROL_TICKS.csv','DATA_TICKS.csv','CASE_CHECKS.csv','POLICY_CHECKS.csv']};(out/'PORTABLE_REPLAY.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');return 0
if __name__=='__main__':raise SystemExit(main())
