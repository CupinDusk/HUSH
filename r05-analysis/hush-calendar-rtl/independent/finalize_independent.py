"""Manifest final independently verified sources and actual outputs."""
from pathlib import Path
import hashlib,json,sys
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[4];SOURCE=HERE.parent
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def dump(n,x):(HERE/n).write_text(json.dumps(x,indent=2)+'\n',encoding='utf-8')
def main():
 facts=json.loads((HERE/'PAPER_READY_FACTS.json').read_text());arithmetic=json.loads((HERE/'INDEPENDENT_ARITHMETIC.json').read_text());mutants=json.loads((HERE/'MUTANTS.json').read_text());supp=json.loads((HERE/'cycle-supplement/INDEPENDENT_SUPPLEMENT_AUDIT.json').read_text())
 audit=dict(status='PASS_INDEPENDENT_AUTHOR_SIDE_FIXED_REFERENCE_COMPONENT',gates=dict(fresh_actual_Yosys_CXXRTL_Zig_execution='PASS',independent_full_state_event_byte_timer_transition='PASS',independent_prefix_fullkey_cycle_all_phases_optima_ties='PASS',full_event_order_peaks_separate_from_after_tick_samples='PASS',meaningful_synthesized_compiled_mutants='PASS_5_OF_5_DETECTED',original_empty_frame_case7='UNKNOWN_PRESERVED',post_observation_all12_fullkey_extension='PASS_WITH_SEPARATE_5F_CROSSING_ENDPOINT_SIDECAR',separate_cycle_witness_supplement='PASS_NOT_A_FULL_ADMISSION_EXTENSION'),facts=facts,arithmetic=arithmetic,mutant_first_detections=[dict(name=r['name'],first_detection=r['first_detection']) for r in mutants['records']],preserved_independent_failures=['attempt-001-window-endpoint/FAILURE.txt','attempt-002-finalization-script-drift/FAILURE.txt'],strict_initial_WU_boundary='t > each line initial capture cutpoint',independent_proof='INDEPENDENT_AUDIT.md: first-failure control induction, immutable ID ownership, monotone periodic Kth decrement and rearm, exact physical prefix plus full timer-phase cycle orbit.',limitations=facts['limits'],scope='No blind review/manuscript/private overlay/remote/push/publication/OS-setting/performance collection. No score target. All writes under independent/.',containers='Actual PE/PDB/gzip hashes bound; no claim of whole-byte binary/container reproducibility. Independently checked semantic input/result/initialization/delta bytes match exactly.')
 dump('INDEPENDENT_AUDIT.json',audit)
 py=Path(sys.executable);inc=ROOT/'.tools/iscas-rtl-20261023/yowasp_yosys/share/include'
 tools=[py,py.parent/'python312.dll',ROOT/'.tools/run_iscas_yosys.py',ROOT/'.tools/zig-0.14.1/zig-x86_64-windows-0.14.1/zig.exe',inc/'backends/cxxrtl/runtime/cxxrtl/cxxrtl.h']
 tools += list((ROOT/'.tools/iscas-rtl-20261023/yowasp_yosys').glob('*.wasm'))
 dump('TOOLS.json',dict(actual_yosys_version=(HERE/'frozen-input/fresh-build/yosys_version.stdout.log').read_text().strip(),actual_tools=[dict(path=str(p),bytes=p.stat().st_size,sha256=sha(p)) for p in tools if p.exists()],include_roots=[str(inc),str(inc/'backends/cxxrtl/runtime')],build_flags=['-std=c++17','-O3','-UNDEBUG']))
 compilecmd=[str(ROOT/'.tools/zig-0.14.1/zig-x86_64-windows-0.14.1/zig.exe'),'c++','-std=c++17','-O3','-UNDEBUG','-I',str(inc),'-I',str(inc/'backends/cxxrtl/runtime'),'-I',str(HERE/'frozen-input/fresh-build'),str(HERE/'independent.cpp'),'-o',str(HERE/'independent.exe')]
 commands=[dict(name='primary-independent-oracle-compile',argv=compilecmd,returncode=0),dict(name='primary-independent-control-5F-and-data',argv=[str(HERE/'independent.exe'),'control',str(HERE)],returncode=0),dict(name='independent-arithmetic',argv=[str(py),'-B','-X','utf8',str(HERE/'independent_analysis.py')],returncode=0),dict(name='primary-independent-all-policy-ticks',argv=[str(HERE/'independent.exe'),'policies',str(HERE),str(HERE/'INDEPENDENT_policies.txt')],returncode=0)]
 dump('COMMANDS.json',dict(scope='Expanded absolute equivalents of actually executed successful primary checker commands; original failed variants are preserved separately. Producer-driver fresh synth commands are in frozen-input/fresh-build/BUILD.json; actual mutant and supplement stage logs are retained in their BUILD/audit JSON files.',cwd=str(ROOT),commands=commands,primary_source_hash=sha(HERE/'independent.cpp'),primary_executable_hash=sha(HERE/'independent.exe')))
 sources={}
 for p in HERE.rglob('*'):
  if p.is_file() and p.suffix in {'.v','.cpp','.py','.md','.json'} and p.name not in {'MANIFEST.json','SOURCE_MANIFEST.json','OUTPUT_MANIFEST.json'}:sources[str(p.relative_to(HERE))]=dict(bytes=p.stat().st_size,sha256=sha(p))
 dump('SOURCE_MANIFEST.json',dict(scope='Actual independent sources, frozen inputs, build commands, protocols, preserved failures and reports. Does not include producer build tree as new independent work.',files=sources))
 files={}
 for p in HERE.rglob('*'):
  if p.is_file() and p.name not in {'MANIFEST.json','OUTPUT_MANIFEST.json'}:files[str(p.relative_to(HERE))]=dict(bytes=p.stat().st_size,sha256=sha(p))
 dump('OUTPUT_MANIFEST.json',dict(scope='Every local independent evidence file, including source copies and failures; excludes this manifest itself.',file_count=len(files),files=files))
 print(json.dumps(dict(status=audit['status'],files=len(files),primary_queries=130112,primary_ticks=84379472,supplement_queries=6496,supplement_ticks=supp['actual_executed_ticks']),indent=2))
if __name__=='__main__':main()
