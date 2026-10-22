# Four-line calendar reference RTL: producer evidence

All twelve fixed controllers and 36 fixed data runs were actually synthesized
with Yosys0.70, compiled from generated CXXRTL with Zig C++17, and executed.
All130,112 one-WU policy witnesses completed;84,379,472 ticks were executed.
The strict lossless decoder checked the timer state/event semantics on every
one of those policy ticks. This directory is audit-ready producer evidence;
independent fresh synthesis/execution, separate transition/arithmetic checks
and meaningful compiled mutants remain required before paper/publication use.

An additional 6,496 cycle-only case7 witnesses execute another 346,304 ticks,
so every policy has explicit earliest-cycle-minimum coverage even where the
full prefix gives a different witness. This supplement's local survivals are
kept separate from full admissions. Total policy ticks including it: 84,725,776.

Read [AUDIT_READY_FACTS.md](AUDIT_READY_FACTS.md), [EVIDENCE_SUMMARY.json](EVIDENCE_SUMMARY.json),
[SCHEMA.md](SCHEMA.md), [COMPOSITION_ARGUMENT.md](COMPOSITION_ARGUMENT.md) and
the original protocol plus both amendments. This is new own reference RTL,
not native/private HUSH, a coherent memory system, hardware/PPA, application,
or CPU-performance evidence. Finite words do not exhaust arbitrary WUs.

The two preserved adverse findings are essential. Before execution F=40 made
literal offsets40..43 invalid; the prospective parent clarified a multiset of
eight modulo-F jobs, with distinct same-owner IDs on duplicate phases. The
original protocol/design and failed compile remain in build-01. First actual
execution build-02 found p=r=7,F=56 does not clear at frame end. The original
empty-frame gate stays UNKNOWN for that controller. The separately authorized
full-key experiment finds entry37/repeat93, four exact prefix edges and an
empty entry state. Its result is never relabeled an original frame-gate pass.

`build-03` preserves original three-frame control/data evidence. `build-04`
contains the separate four-frame control-key extension and unchanged three-frame
data runs. `analysis-01` contains all relations, all physical prefix/phase rows,
the complete grid and every optimum/tie including original K<=5 empty sets.
`build-05-policy` contains actual policy outputs and the complete lossless
per-tick binary transcript. `trace-archives` contains byte-exact gzip copies;
raw files are retained. `MANIFEST.json` and `TOOL_HASHES.json` bind all evidence.
`build-06-cycle-supplement` preserves the separate cycle-only executions.
Original maxima in run/policy CSV are after-tick samples; exact enqueue-before-
callback peaks are separately in `PEAK_*` files, without rewriting raw counters.

The fixed three-frame byte runs have858 captures/858 emissions,714 cancels,
1,116 backpressure ticks and135,792 WUs. Their F56 runs retain two FIFO tokens
at end, explicitly recorded. Multiple pending per line occurs in cases4,7,10,11;
case4 reaches two for every line. Policy executions also actually retain
snapshots after tag expiry; no snapshot bytes are overwritten by tag changes.

For fresh portable execution with existing bundled tools, use Python3.12 and
pass the workspace containing `.tools` explicitly. From this directory:

```powershell
& '<BUNDLED_RUNTIME>/python/python.exe' -B -X utf8 replay_portable.py --tool-root '<WORKSPACE>' --out 'C:/path/to/new-empty-replay-directory' --all-tick-check
```

This copies only own source/protocol/checker files and performs fresh Yosys
synthesis, CXXRTL C++ compilation and execution. It creates separate numbered
logs. It does not copy a precompiled executable or derived expectations. Both
CXXRTL include roots are supplied by run_build.py. Replay does not establish
checker authorship independence; a separately authored validator must gate use.
No download, remote, historical launcher, process termination, global runtime
change, affinity/power change, push, or publication is performed.

Individual checks on existing evidence:

```powershell
python -B -X utf8 check_transitions.py --build build-04
python -B -X utf8 verify_policy.py --build build-05-policy --ticks
python -B -X utf8 derive_peaks.py
```

`analyze.py --out NEW_DIRECTORY` derives all policy inputs from actual traces,
first writing a source/input hash binding. It refuses to overwrite its output
directory. `decode_trace.py` can expand the complete policy transcript to CSV
but that text would be much larger. `finalize_evidence.py` verifies lossless
gzip round trips and writes the current inventory. Build durations are not
collected or reported as performance measurements.
