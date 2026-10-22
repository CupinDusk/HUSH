"""Fresh actual synthesis/compile/run, with explicit external tool root."""
from pathlib import Path
import argparse,hashlib,json,shutil,subprocess,sys
HERE=Path(__file__).resolve().parent
SOURCES=['receiver.v','driver.cpp','PROTOCOL.json','PROTOCOL_INITIAL_LITERAL.json','AMENDMENT_01_PRE_EXECUTION.md','AMENDMENT_02_FULL_KEY_EXTENSION.md','CORRECTION_02_PRESERVE_FRAME_FAILURE.md','SUPPLEMENT_03_CYCLE_WITNESS_COVERAGE.md','run_build.py','analyze.py','decode_trace.py','check_transitions.py','verify_policy.py','derive_peaks.py','generate_cycle_supplement.py','COMPOSITION_ARGUMENT.md','SCHEMA.md']
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--tool-root',type=Path,required=True);ap.add_argument('--out',type=Path,required=True);ap.add_argument('--all-tick-check',action='store_true');a=ap.parse_args();dest=a.out.resolve();dest.mkdir(parents=True,exist_ok=False)
 for n in SOURCES:shutil.copyfile(HERE/n,dest/n)
 (dest/'REPLAY_INPUT_BINDING.json').write_text(json.dumps({n:sha(dest/n) for n in SOURCES},indent=2)+'\n',encoding='utf-8')
 commands=[['run_build.py','--root',str(a.tool_root.resolve()),'--attempt','build-control'],['check_transitions.py','--build','build-control'],['analyze.py','--build','build-control','--out','analysis-01'],['run_build.py','--root',str(a.tool_root.resolve()),'--attempt','build-policy','--mode','policies','--input',str(dest/'analysis-01/policies.txt')],['verify_policy.py','--build','build-policy']+(['--ticks'] if a.all_tick_check else []),['generate_cycle_supplement.py'],['run_build.py','--root',str(a.tool_root.resolve()),'--attempt','build-cycle-supplement','--mode','policies','--input',str(dest/'cycle-supplement-01/policies.txt')],['verify_policy.py','--build','build-cycle-supplement','--analysis','cycle-supplement-01','--expected-queries','6496']+(['--ticks'] if a.all_tick_check else []),['derive_peaks.py','--control','build-control','--policy','build-policy']]
 report=[]
 for cmd in commands:
  p=subprocess.run([sys.executable,'-B','-X','utf8',*cmd],cwd=dest,capture_output=True,text=True,encoding='utf-8',errors='replace');idx=len(report)+1;(dest/f'replay-{idx}.stdout.log').write_text(p.stdout,encoding='utf-8');(dest/f'replay-{idx}.stderr.log').write_text(p.stderr,encoding='utf-8');report.append({'argv':cmd,'returncode':p.returncode});(dest/'REPLAY.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');print(cmd[0],p.returncode,flush=True)
  if p.returncode:return p.returncode
 return 0
if __name__=='__main__':raise SystemExit(main())
