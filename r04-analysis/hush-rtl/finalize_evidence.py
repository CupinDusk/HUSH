"""Collect immutable input/tool/output bindings, not scientific calculations."""
from pathlib import Path
import hashlib,json,shutil
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 ref=HERE.parents[1]/'r03-analysis/hush-shared-controller';dest=HERE/'reference-inputs';dest.mkdir(exist_ok=False)
 names=['PROTOCOL.json','RELATIONS.json','TRACES.jsonl.gz','ALL_PHASE_BASES.jsonl.gz','ALL_NEGATIVE_FIRST_FAILURES.jsonl.gz','INDEPENDENT_VALIDATION.json']
 binding={}
 for n in names:shutil.copyfile(ref/n,dest/n);binding[n]={'source':'outputs/iscas-final-polish-20261022/r03-analysis/hush-shared-controller/'+n,'sha256':sha(dest/n),'bytes':(dest/n).stat().st_size};assert sha(ref/n)==sha(dest/n)
 (HERE/'REFERENCE_INPUTS.json').write_text(json.dumps({'kind':'byte_exact_copy_of_authorized_public_R03_inputs','inputs':binding},indent=2)+'\n',encoding='utf-8')
 tools=[ROOT/'.tools/run_iscas_yosys.py',ROOT/'.tools/iscas-rtl-20261023/yowasp_yosys/yosys.wasm',ROOT/'.tools/iscas-rtl-20261023/yowasp_yosys/__init__.py',ROOT/'.tools/iscas-rtl-20261023/yowasp_yosys/share/include/backends/cxxrtl/runtime/cxxrtl/cxxrtl.h',ROOT/'.tools/zig-0.14.1/zig-x86_64-windows-0.14.1/zig.exe']
 toolbind={str(p.relative_to(ROOT)).replace('\\','/'):{'sha256':sha(p),'bytes':p.stat().st_size} for p in tools}
 (HERE/'TOOL_HASHES.json').write_text(json.dumps({'yowasp_yosys_package':'0.70.0.0.post1259','actual_yosys':'Yosys 0.70 git 28ba3cb92','compiler':'Existing Zig 0.14.1 C++17 -O3 -UNDEBUG','tools_external_not_bundled':True,'files':toolbind},indent=2)+'\n',encoding='utf-8')
 files={}
 for p in sorted(HERE.rglob('*')):
  if p.is_file() and p.name!='MANIFEST.json' and 'independent' not in p.relative_to(HERE).parts:
   files[str(p.relative_to(HERE)).replace('\\','/')]={'bytes':p.stat().st_size,'sha256':sha(p)}
 manifest={'kind':'new_reference_RTL_evidence_manifest','protocol_sha256':sha(HERE/'PROTOCOL.json'),'author_result':'PASS_EXECUTED_YOSYS_GENERATED_REFERENCE_RTL','independent_validation':'PENDING_ROOT_ASSIGNED_CHECKER_AND_FRESH_REBUILD','source_scope':'Own new reference RTL and public R03 data only; no historical/native HUSH overlay.','files':files}
 (HERE/'MANIFEST.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8');print(json.dumps({'files':len(files),'total_bytes':sum(v['bytes'] for v in files.values()),'manifest_sha256':sha(HERE/'MANIFEST.json')},indent=2))
if __name__=='__main__':main()
