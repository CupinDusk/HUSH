# Reproduction artifact: Exact Period Reuse for Cache Expiry Certificates

This snapshot supplies the analysis code, explicit model assumptions, retained
numerical summaries, protocols, expected outputs, and checks for the paper.
It does not contain the manuscript, private implementation overlays, GPU
acquisition programs, server configuration, credentials, or third-party raw CSVs.

## Reproduce

Requires Python 3.12 and Zig 0.14.1.

    python -B -X utf8 run_checks.py --zig /absolute/path/to/zig

Run the checks in a fresh extraction. The manifest lists every input and SHA-256.
The calculations and expected outcomes, including unfavorable and zero results,
are unchanged from the source research snapshot. Historical release-management
READMEs are omitted; the numerical and argument history remains in analysis/
and expected/. No native hardware experiment is performed by this artifact.

Third-party source headers, copyright notices, and licenses are preserved
verbatim. External data fetching is optional and requires an explicit flag;
the default checks use only bundled numerical summaries.

The authors intend to release the research code under an open-source license
upon publication. This review snapshot is an accessible reproduction package;
it does not claim that every private project component has been released.

## Operation counts

The additional query_cost_study.py check evaluates the fixed expanded grid of
6,277,660 policies. It reports query-term evaluations, projection input visits,
and stored terms separately. These are exact mathematical operation counts,
not measured runtime, CPU instructions, memory bytes, or hardware speedup.

## Grouped residue comparator

`grouped_baseline.py` separates the term savings from ordinary gcd-residue
grouping and subsequent canonical dominance removal on every admitted family
entry and the same expanded policy grid. It verifies every target phase,
retains ties and no-gain cases, and reports exact modular-minimum term counts.
These counts do not establish hardware runtime or memory savings.

## Complete-policy and exact-query additions

The `r02/` extension supplies exact finite-prefix policy admission with the same
exact-prefix comparator, independent decrement-event/state checks, canonical
reset-predecessor lookup, prospective divisor portfolios, and a local C++17
query implementation study. All negative results remain included.

Run the new correctness and recorded-event audits from a fresh extraction:

    python -B -X utf8 run_r02_checks.py

This uses Python 3.12 and the standard library only. It writes generated
profiles, phase bases and deterministic query streams under `r02/`; these large
reproducible outputs are omitted from the download. It does not rerun the old
source/model suite; `run_checks.py` remains available for that separate suite.

To rerun native timings after correctness checks, use any compatible Clang
C++17 compiler with signed `__int128`, or Zig 0.14.1 (Clang 19.1.7):

    cd r02/lookup
    zig c++ -std=c++17 -O3 -DNDEBUG -Wall -Wextra benchmark.cpp -o benchmark
    ./benchmark new_native_events.jsonl

On Windows, use `-o benchmark.exe` and `./benchmark.exe`. The program reads the
relative `NATIVE_PROFILES.txt` and `NATIVE_CONTROL.txt` files. The frozen
protocol and nine paired block orders are unchanged. Construction timing is
separate from hot queries. Dense caching wins on the small family; predecessor
lookup loses for most small/pruned profiles. Large-modulus dense tables are
unavailable at the declared cap. Recorded results concern one local CPU
implementation; they do not establish native HUSH conformance, application
benefit, hardware speedup, or population frequencies.

`r02/expected/NATIVE_RECORDED_EVENTS.jsonl.gz` preserves every measured event
byte-for-byte after decompression. `NATIVE_RECORDED_RESULTS.json` preserves all
numerical records; only the private installation path/command executable was
generalized. Timing reproduction is checked by correctness and protocol, not
by demanding identical elapsed times on a different host.

## Shared-controller and complete offline workflow extension

The `r03/` extension specifies and independently checks all forty predeclared
two-line bounded shared-response controllers. It retains all 37,000 correlated
policy queries, all 19,613 negative first-failure executions, all no-gain cases,
the fourteen cases without a ready-off stall, and every finite prefix edge.
Prospective per-line records retain 765 pairs versus 961 full-master pairs and
support every portfolio query. Separate line identities are never quotiented.

Run the new standard-library-only correctness and recorded-evidence audit:

    python -B -X utf8 run_r03_checks.py

The runner refuses an existing `R03_REPLAY_RESULTS.json`, uses a fresh temporary
directory, independently regenerates every trace and negative execution, runs
all four complete workflow correctness routes, and checks all 36 recorded
timings, seeded orders, output hashes and numeric summaries. It performs no new
timing experiment. The older suites remain separately available through
`run_checks.py` and `run_r02_checks.py`; they are not silently rerun by this
extension. Retained original scripts find existing public mathematical helpers
through a child-process PYTHONPATH supplied by the runner.

The complete local Python prototype charges fresh extraction, physical-prefix
and binding work, representations, projection/cache construction, all queries
and output consumption. Median total milliseconds are 178.580 cached raw,
139.146 ordinary grouped, 137.271 prospective canonical and 133.451 dense.
Dense wins 8/9 complete paired blocks; canonical loses to ordinary grouped in
3/9. These are one local offline prototype's timings, not native HUSH, cache
hardware, application, throughput or coherence measurements. Full ranges,
adverse outcomes and nine block orders are retained.

`r03/PUBLICATION_PROVENANCE.json` declares the removed private interpreter path
and updated derived file hash. Every scientific/timing number is unchanged;
the old public research tree and third-party licenses/headers remain exact.
No manuscript, figure, private overlay, executable, remote configuration,
credential or third-party raw acquisition data is included.
