# Clean receiver replacement: minimal replay v1

This self-contained Python artifact extends a two-core, single-writer HUSH
model with a finite, set-associative, true-LRU receiver cache. It checks a
relative-age bound together with a conservative local reuse-distance
certificate. It requires Python 3.10 or later and only the standard library.
Run the following commands in this directory, without Python's `-O` option:

```text
python -B -X utf8 run_study.py
python -B -X utf8 check_residency.py
python -B -X utf8 check_extension.py
python -B -X utf8 verify_replay.py
```

The first command writes the complete `REPLACEMENT_RESULTS.json`,
`REPLACEMENT_ROWS.csv`, and `STUDY_PROTOCOL.json` locally. The checkers write
`RESIDENCY_CHECK.json` and `EXTENSION_CHECK.json`. The verifier compares every
field of all 1,776 scientific rows with the expected canonical digest and
checks the expected summary and both checker outputs. Wall-clock
`elapsed_seconds` is excluded from scientific comparisons. Generated full
JSON/CSV files are intentionally omitted from the minimal source package.

## Contract and scope

- The receiver holds **clean, shared input data** in an explicitly declared
  cache partition. All demand allocations and their address-to-set mapping
  are included in the local reference sequence. Code, stack, outputs, and
  other private data occupy a separate partition or otherwise cannot evict
  these inputs. This is a conditional cache contract, not an assertion about
  an unmodified application's unified cache.
- A local demand read allocates on a miss and touches true LRU on a hit.
  WU messages **neither allocate nor touch LRU**. They update a line only if
  it is resident and may arm its expiry timer. Expiry removes the concrete
  line from LRU. The analytical shadow retains expired references as ghosts;
  this can reject additional hits and is conservative for this contract.
- A silent clean eviction invalidates the receiver line and timer but can
  leave a **stale-positive sharing bit** at the writer, just as silent expiry
  can. The next WU reconciles that bit with actual residency. Eviction does
  not provide an immediate, free notification to the writer. The study also
  declares a separate free end-of-reader release (`flush_at_finish=True`);
  reported joint completion is conditional on that end-release assumption.
- The writer retains authoritative dirty ownership and does not evict its
  data. Receiver dirty stores, dirty eviction/writeback, a shared LLC,
  unlisted competing allocations, and a DRAM timing model are outside this
  extension. Clean replacement adds no bus transaction in this contract;
  lookup and victim selection must fit the declared local/service costs.
- Local computation segments have **known upper bounds**. Supplied `compute`
  values are these bounds in model cycles, not measured native execution
  times. There is one outstanding transaction per core and nonpreemptive
  two-client round-robin arbitration. A pending miss blocks new private-store
  admission. A reader request is charged at most 71 cycles under this
  admission, arbitration, and configuration-interlock contract (the WU and
  miss slots are 10 and 60 cycles). Finite cache geometry changes the hit classification, not this
  service contract. A predicted hit additionally requires positive residual
  lifetime and a local reuse-distance certificate for its set.
- `replacement_model.analyze(..., cache_sets=S, cache_ways=A, budget=B)` takes
  an optional externally supplied task budget. Omitting it returns
  `budget=None, feasible=None`; no budget is invented by the new analyzer.
  `run_study.py` evaluates declared policies and bound safety. It does not
  select a policy under an application budget or establish a native WCET.

`interlocked_closed_loop_protocol.json` is the byte-preserved **base-model
input**. Its historical `cache_model`, `budget`, `selection`, and status text
describe the original study, not the finite-cache experiment. The actual
replacement experiment and case overrides are in `run_study.py` and its
generated `STUDY_PROTOCOL.json`. The base protocol's numeric service and
timer parameters remain in use. `original_model.py` is preserved byte for
byte for the 48-case parity check; its historical auto-budget/main routine
is not the replacement-study entry point.

## FIR2DIM provenance and interpretation

`fir2dim-original.c` is the unmodified TACLeBench source from commit
`ffdc3f58c9d8f6c1d7e700f2190992c71a3276fe`,
[`bench/kernel/fir2dim/fir2dim.c`](https://github.com/tacle/tacle-bench/blob/ffdc3f58c9d8f6c1d7e700f2190992c71a3276fe/bench/kernel/fir2dim/fir2dim.c).
Its original notice permits use, modification, and redistribution freely;
the notice and original author credit are retained. See
`THIRD_PARTY_NOTICES.md` and `BUNDLE_METADATA.json` for the source hash.

`fir2dim-read-trace.json` contains 145 ordered reads of the 36-element float
input array and three source-region markers (`P=0,1,2`). The replay maps
element index `v` to line `(4*v)//64`, explicitly assuming 4-byte floats and a
64-byte-aligned array base. That is a **three-line, aligned shared-input
scenario**. It excludes coefficient reads, output writes, stack and
instruction accesses, initialization, and native computation timing. The
driver supplies one declared compute segment per input read and a synthetic
single-writer refresh stream. This is not a complete native FIR2DIM memory
trace, a native kernel run, or an application-level budget admission result.
No C compiler is needed for the replay; the original C source is provenance.

## Expected results and independent checks

The declared grid has 1,344 synthetic BSQ/DQD executions and 432 FIR2DIM
input-trace executions, for 1,776 distinct parameter/phase cases. It records
713 executions with clean replacements, 23,402 clean evictions, 62,032
predicted-hit checks, zero unsafe hits, and zero reader/service bound
violations. The 436 strict carry-in versus reset bound improvements compare
the same policy vector and geometry; they are not a performance gain over
the best fixed policy. Counts include repeated predictions across timer
phases and are not a count of independent proof states.

`check_residency.py` independently explores complete reachable-state closure
for four addresses and six geometries: 1,278 states and 15,336 transitions.
It checks the residency lemma and finds counterexamples when WUs allocate,
when WUs touch LRU, or when expiry cleanup is omitted. This finite-universe
check is separate from the timed bound and does not prove arbitrary-size
timed-system correctness.

`check_extension.py` checks equality of all original prediction/execution
metrics in 48 no-conflict configurations. It also rejects the old
protected-slot classifier on a conflicting cache and checks automatic
analysis with boundary flushing. It imports the original model; it does not
run the original model's historical main routine.

`EXPECTED_RESULTS.json` defines canonicalization, lists every row field,
and binds the scientific result and small checker outputs. Canonical rows
sort each row's JSON keys and then sort row strings lexicographically, so
neither indentation, platform line endings, nor row order affects the hash.
Source/protocol hashes are separate byte-level provenance. Generated
protocol line endings may differ across operating systems; this does not
alter scientific fields. `REPLAY_AUDIT.json` and `REPLAY_AUDIT.md`, when
present beside the public sources, record the independent extracted-package
replay. Neither timing nor successful replay extends the stated model scope.

Authored artifact code and documentation use the accompanying MIT license.
The third-party original C source retains its own notice.
