"""Record final checker execution, local environment, exact facts and manifest."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,platform,subprocess,sys

HERE=Path(__file__).resolve().parent
ROOT=HERE.parent.parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,data):p.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')

def main():
    argv=[sys.executable,'-B','-X','utf8',str(HERE/'check_independent.py')]
    r=subprocess.run(argv,capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=600)
    (HERE/'checker.stdout.log').write_text(r.stdout,encoding='utf-8')
    (HERE/'checker.stderr.log').write_text(r.stderr,encoding='utf-8')
    dump(HERE/'CHECKER_EXECUTION.json',dict(argv=argv,returncode=r.returncode,checker_sha256=sha(HERE/'check_independent.py')))
    assert r.returncode==0,r.stderr
    result=json.loads((HERE/'INDEPENDENT_AUDIT.json').read_text())
    mutations=json.loads((HERE/'mutation-tests-01'/'MUTATION_RESULTS.json').read_text())
    assert mutations['status']=='ALL_FOUR_SEMANTIC_MUTANTS_REJECTED'
    zig=ROOT/'.tools/zig-0.14.1/zig-x86_64-windows-0.14.1/zig.exe'
    zv=subprocess.run([str(zig),'version'],capture_output=True,text=True,encoding='utf-8',timeout=60)
    assert zv.returncode==0
    (HERE/'zig-version.stdout.log').write_text(zv.stdout,encoding='utf-8')
    (HERE/'zig-version.stderr.log').write_text(zv.stderr,encoding='utf-8')
    headers=ROOT/'.tools/iscas-rtl-20261023/yowasp_yosys/share/include/backends/cxxrtl/runtime'
    dump(HERE/'ENVIRONMENT.json',dict(python_executable=sys.executable,python_sha256=sha(Path(sys.executable)),
         python_version=sys.version,python_flags=dict(dont_write_bytecode=sys.dont_write_bytecode,utf8_mode=sys.flags.utf8_mode),
         platform=platform.platform(),architecture=platform.machine(),zig_argv=[str(zig),'version'],
         zig_version=zv.stdout.strip(),zig_sha256=sha(zig),
         actual_yosys_version=(HERE/'fresh-replay-01'/'yosys_version.stdout.log').read_text().strip(),
         cxxrtl_runtime_files={p.relative_to(headers).as_posix():dict(bytes=p.stat().st_size,sha256=sha(p)) for p in sorted(headers.rglob('*')) if p.is_file()},
         no_remote_operations=True,no_environment_dump=True,no_performance_benchmark=True))
    facts=dict(status=result['status'],scope=result['scope'],counts=result['counts'],
               phase_reconstruction=result['phase_reconstruction'],
               no_service_gain_cases=result['no_service_gain_cases'],
               exercised_coverage=result['exercised_coverage'],
               exact_evidence=dict(audit='INDEPENDENT_AUDIT.json',checker='check_independent.py',
                 checker_execution='CHECKER_EXECUTION.json',source_review='INDEPENDENT_AUDIT.md',
                 fresh_replay='fresh-replay-01/PORTABLE_REPLAY.json',
                 generated_netlist_sha256=sha(HERE/'fresh-replay-01'/'netlist.cpp'),
                 fresh_executable_sha256=sha(HERE/'fresh-replay-01'/'simulate.exe'),
                 RTL_protocol_sha256=sha(HERE/'portable-source'/'PROTOCOL.json'),
                 frozen_reference_protocol_sha256=sha(HERE/'portable-source'/'reference-inputs'/'PROTOCOL.json'),
                 semantic_mutants='mutation-tests-01/MUTATION_RESULTS.json',environment='ENVIRONMENT.json'),
               mutation_sensitivity=dict(status=mutations['status'],mutants=[dict(name=m['name'],rejection=m['actual_rejection']) for m in mutations['mutants']]),
               limits=result['limits'],
               publication_gate='Independent author-side finite RTL gate passed; this is not external peer review or a manuscript/publication change.',
               suggested_statement='We implemented the specified two-client receiver as new synthesizable RTL. A fresh Yosys 0.70 CXXRTL build reproduced all 40 frozen schedules over 22,823 ticks and all 37,000 declared one-WU tests (17,387 survivals; 19,613 first-failed-grant witnesses). A separate checker reconstructed every phase decision and observed control/data field. Across 120 fixed-pattern runs, 9,897 captures and 9,807 emissions preserve request identity and snapshot bytes, including 1,071 response-backpressure ticks and 9,657 timer cancellations. These finite constructed-component results do not establish native HUSH/gem5 refinement, arbitrary WU-word or coherent-data correctness, or hardware benefit.')
    dump(HERE/'PAPER_READY_FACTS.json',facts)
    manifest=dict(kind='independent_author_side_new_reference_RTL_evidence',status=result['status'],
        generated_utc=datetime.now(timezone.utc).isoformat(),
        checker_sha256=sha(HERE/'check_independent.py'),
        scope='Local audit artifacts. Tools and executables stay local; minimal public packages should select source/reference/results only.',
        files={p.relative_to(HERE).as_posix():dict(bytes=p.stat().st_size,sha256=sha(p)) for p in sorted(HERE.rglob('*')) if p.is_file() and p.name!='MANIFEST_INDEPENDENT.json'})
    dump(HERE/'MANIFEST_INDEPENDENT.json',manifest)
    print(json.dumps(dict(status=result['status'],manifest_files=len(manifest['files']),mutants=len(mutations['mutants'])),indent=2))

if __name__=='__main__':main()
