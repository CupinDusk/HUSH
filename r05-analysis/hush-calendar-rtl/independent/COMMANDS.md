# Actual commands and verification sources

Commands were run from <WORKSPACE> using the bundled
Python executable at
`<BUNDLED_RUNTIME>/python/python.exe`,
always with `-B -X utf8`. Let I denote
`outputs/iscas-final-polish-20261022/r05-analysis/hush-calendar-rtl/independent`.

1. Freeze the producer source/protocol/amendment files under I/frozen-input and
   bind INPUT_HASHES_INITIAL.json before independent execution.
2. `python -B -X utf8 I/frozen-input/run_build.py --root . --attempt fresh-build`
   produces a new actual Yosys/CXXRTL/compiled-driver control/data run. Exact
   expanded command arrays, return codes, stdout and stderr are preserved in
   I/frozen-input/fresh-build/BUILD.json and stage log files.
3. Compile I/independent.cpp with the task-local Zig:
   `zig.exe c++ -std=c++17 -O3 -UNDEBUG -I INCLUDE -I INCLUDE/backends/cxxrtl/runtime -I I/frozen-input/fresh-build I/independent.cpp -o I/independent.exe`,
   where INCLUDE is `.tools/iscas-rtl-20261023/yowasp_yosys/share/include`.
4. `I/independent.exe control I` executes actual netlist transitions alongside
   the independent oracle, with 5F no-WU control and 3F per data pattern. The
   sidecar is INDEPENDENT_CONTROL_5F.csv; 4F primary rows are compared exactly.
5. `python -B -X utf8 I/independent_analysis.py` independently derives complete
   live keys, ID translations, prefix/cycle relations, C0,J,A, complete physical
   phase tables, admissions, all optima/ties and INDEPENDENT_policies.txt.
6. `I/independent.exe policies I I/INDEPENDENT_policies.txt` actually executes
   all130112 policy witnesses against all66 state/event fields per tick.
7. `python -B -X utf8 I/run_mutants.py` creates five distinct RTL mutations;
   actual synthesis/compilation/execution logs and command arrays are retained
   separately for each under I/mutants/*/BUILD.json. Each fails the independent
   state/event oracle at the reported first discrepancy.
8. `python -B -X utf8 I/audit_supplement.py` independently regenerates the6496
   cycle-only witnesses and performs another actual Yosys/CXXRTL/compile/run.
   Exact commands, hashes and results are in the supplement audit JSON.
9. `python -B -X utf8 I/verify_evidence.py` verifies primary/supplement scope,
   every peak row, stream equality, all initialization rows, stable core
   sources and separately inspected producer-finalization scripts.
10. `python -B -X utf8 I/finalize_independent.py` binds the final audit and all
    source/output/tool hashes. Manifests intentionally exclude themselves.

Do not rerun creation steps into existing build/mutant/supplement directories;
they deliberately refuse replacement. For a new audit use a new numbered
independent directory and preserve these inputs/failures. Timing is not an
experimental output or a performance claim.

The independently written oracle and arithmetic do not import producer
checkers. The producer portable replay and verify_policy.py --ticks were read
for protocol/serialization review; their existing producer PASS is not treated
as an independent oracle. Actual independent semantic delta bytes equal the
producer's full primary and supplemental streams, rather than merely matching
its aggregate counts.
