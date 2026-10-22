"""Optional actual fresh generated-RTL execution; supplied tools remain external."""
from pathlib import Path
import argparse,hashlib,json,subprocess,sys
ROOT=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--out',required=True,type=Path);ap.add_argument('--yosys',default='yosys');ap.add_argument('--yosys-python-wrapper',type=Path);ap.add_argument('--cxx',default='c++');ap.add_argument('--zig',action='store_true');ap.add_argument('--include',required=True,type=Path);a=ap.parse_args()
 rtl=ROOT/'r04-analysis/hush-rtl';out=a.out.resolve()
 manifest=json.loads((ROOT/'MANIFEST.json').read_text(encoding='utf-8'))
 for n,h in manifest['files'].items():assert sha(ROOT/n)==h,n
 argv=[sys.executable,'-B','-X','utf8',str(rtl/'replay_portable.py'),'--out',str(out),'--reference',str(rtl/'reference-inputs'),'--include',str(a.include.resolve()),'--cxx',a.cxx]
 if a.yosys_python_wrapper:argv+=['--yosys-python-wrapper',str(a.yosys_python_wrapper.resolve())]
 else:argv+=['--yosys',a.yosys]
 if a.zig:argv+=['--zig']
 subprocess.run(argv,cwd=ROOT,check=True)
 expected='b41df947e115fbe3502773c81e9993e6dafeb07db3e459cea91f01a586beed2f'
 assert sha(out/'netlist.cpp')==expected,'Generated-netlist hash differs from the pinned admitted toolchain.'
 for n in ['CONTROL_TICKS.csv','DATA_TICKS.csv','CASE_CHECKS.csv','POLICY_CHECKS.csv','RTL_RESULTS.json']:
  assert sha(out/n)==sha(rtl/'build-01'/n),n
 subprocess.run([sys.executable,'-B','-X','utf8',str(rtl/'independent/check_public.py'),'--replay',str(out),'--out',str(out/'PUBLIC_INDEPENDENT_AUDIT.json')],cwd=ROOT,check=True)
 result=dict(status='PASS_ACTUAL_FRESH_YOSYS_CXXRTL_COMPILE_EXECUTION_ALL_40_37000_120_AND_INDEPENDENT_AUDIT',expected_netlist_sha256=expected,
  semantic_outputs_byte_exact=True,new_timing_experiment=False,tools_external=True,native_historical_HUSH_run=False,
  tool_versions='See actual yosys_version.stdout.log; frozen environment records Yosys 0.70 git 28ba3cb92, Zig 0.14.1, Python 3.12.14. Operational tool durations are not performance evidence.')
 (out/'R04_NATIVE_REPLAY_RESULT.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps(result,indent=2))
if __name__=='__main__':main()
