# Complete offline HUSH shared-controller workflow cost

All four exact service routes reproduced all 37,000 frozen slacks and statuses. For this complete local Python job, the dense phase cache was fastest in 8/9 paired blocks. The prospective canonical route was faster than cached raw in all nine blocks, but lost to ordinary grouped scanning in three blocks and to dense caching in eight. This evidence does not support a universal end-to-end advantage for canonical records.

This is one Python 3.12.14 prototype on a Windows 11 Intel Core i9-14900HX, using the newly specified bounded two-line controller. It is not a native HUSH/cache implementation, hardware throughput measurement, application workload, or coherence experiment.

## Frozen design and correctness

`PROTOCOL.json` was saved before new workflow cost results. `QUERY_STREAM.json.gz`, `SCHEDULE.json`, and `EXPECTED.json` were saved before validation/timing. The stream is a seeded uniform shuffle of every member of the fixed policy grid: all 40 predeclared cases, physical `P=1..4p`, every `phi=0..P-1`, and `K=1..5`. These are correlated parameter calculations, not independent applications or scientific replicates.

Each route/block independently re-extracts all forty producers using the verified `Producer` and `cases` source segments. Those segments are byte-identical to the original (`PRODUCER_COPY_BINDING.json`). Extraction detects the first full control-key repeat, continues two periods, checks translated grant/response schedules, records matching prefix/cycle triples and computes the trace digest. The common extractor deliberately excludes the original script's route-specific canonical/posthoc construction. Every extracted case, complete trace digest, actual joint translation `d`, line identity, tag, initial successful-service cutpoint, finite prefix and recurrent triple matched frozen `../hush-shared-controller/RELATIONS.json` in untimed validation.

All routes use the same exact physical-period finite-prefix method. They cache its 7,400 physical `(case,P,phi)` base values once, reusing each across all five K values. `gcd(P,d)`, the 720 physical period bindings, 276 distinct `(case,m)` targets, and prospective `g*` are computed outside the hot query loop. Every route caches its target representation once per distinct `m`. No route regenerates raw source relations or checks the prefix five times per physical phase.

The independently frozen phase bases supply the exact numeric slack reference. In addition, a count-only validator reconstructs every service and completion admission from periodic decrement events on literal prefix edges and translated recurrent orbits, without using any route's profile, canonicalization, predecessor or expiry routine. It reproduces 17,387 complete service admissions, 19,613 unknowns, 16,948 line-aware completion admissions, and 439 service-only admissions. The completion observer is a correctness reference; all four timed routes return the same exact service slack.

Every measured invocation consumed all outputs: slack sum **94,695**, and SHA-256 **`cc127f21521f9daf0782c2f026d5b23366a3e529b8daf1531248c9db906d4674`** over the ordered `struct.pack('<q?', slack, slack>0)` sequence. The separately frozen query-stream digest binds each position to its query identity.

## Routes and charged work

All routes preserve separate records for both lines. Their scalar minima combine only when evaluating the shared-policy query.

| Route | Source representation and target cache | Hot recurrent query |
|---|---|---|
| Cached raw | Cache each line's raw `(service,span)` once; cache every residue/span term for each distinct m, including duplicate residues | Scan all raw terms |
| Ordinary grouped | Same raw source; group each line's residues to maximum span once per distinct m | Scan the grouped terms |
| Prospective canonical | Construct each line's canonical record directly at `g*=lcm_{P=1..4p} gcd(P,d)` from newly observed triples; project/regroup/canonicalize once per distinct m and cache sorted reset arrays | Binary-search the predecessor reset and evaluate its wrapped value |
| Dense phase | Same raw source and ordinary grouped profiles; explicitly construct the complete envelope at every phase of each distinct m | Two direct per-line phase lookups |

The dense comparator fully exploits repeated K/phase result work. Its grouped-profile construction and phase-envelope construction are charged. Canonical construction reads no precomputed favorable canonical payload: the frozen payload is used only afterward as an untimed correctness check. All 37,000 queries are supported by prospective g*, so there is no unsupported query/fallback branch in this fixed portfolio.

Each timed invocation includes fresh producer extraction, exact finite-prefix/bind work, source representation construction, distinct-m projection/cache construction, all 37,000 queries, sum/status consumption, and ordered output hashing. Input parsing/imports, initial expected-output construction, untimed validation, process startup, report serialization and post-return object cleanup are excluded for every route.

## Measured times

Exactly one **untimed** complete warmup block preceded **nine** paired blocks. All ten route orders were seeded and saved before timing; no block was dropped, trimmed, repeated, replaced or stopped selectively. Ordinary Python garbage collection remained enabled. Routes ran serially in one process. Root confirmed no other agent benchmark was running; unrelated operating-system activity was not controlled. No affinity or frequency control was applied.

Clock: `time.perf_counter_ns`, Windows `QueryPerformanceCounter()`, reported resolution 100 ns. Each cell below is median **[min, max] milliseconds** across the nine blocks. Raw nanosecond values and exact route orders are in `ALL_TIMINGS.json` and the append-only `ALL_TIMINGS.jsonl` journal.

| Charged stage | Cached raw | Ordinary grouped | Prospective canonical | Dense phase |
|---|---:|---:|---:|---:|
| Producer extraction | 111.066 [108.790,116.203] | 110.623 [108.144,114.517] | 110.279 [107.909,111.425] | 110.462 [108.587,116.191] |
| Exact prefix and bind/gcd | 8.081 [7.840,8.890] | 8.049 [7.903,8.303] | 8.021 [7.888,8.121] | 8.081 [7.855,8.346] |
| Representation construction | 0.094 [0.073,0.119] | 0.104 [0.074,0.128] | 1.277 [1.226,1.570] | 0.089 [0.067,0.169] |
| Target projection/cache | 0.650 [0.621,0.687] | 0.654 [0.638,3.477] | 1.581 [1.529,1.611] | 2.469 [2.352,2.763] |
| 37,000 queries | 55.819 [55.243,60.465] | 15.642 [15.414,16.090] | 12.951 [12.703,13.224] | 8.560 [8.137,8.696] |
| Consume/hash | 3.532 [3.395,3.815] | 3.520 [3.377,3.613] | 3.431 [3.328,3.652] | 3.485 [3.370,3.690] |
| **Complete end-to-end** | **178.580 [177.355,189.496]** | **139.146 [136.453,142.616]** | **137.271 [135.397,139.176]** | **133.451 [130.602,139.464]** |

The end-to-end timer encloses the separately timed stages plus invocation/control overhead. The exact stage sum and overhead are retained for every invocation; control-overhead medians are 0.0104, 0.0098, 0.0102 and 0.0095 ms respectively. Sums of stage medians need not equal the median total. Common producer and prefix costs are included in each total and must not be attributed to canonicalization.

For each paired block, `other total / canonical total` has median [min,max] 1.3088 [1.2859,1.3804] for cached raw, 1.0123 [0.9889,1.0514] for ordinary grouped, and 0.9691 [0.9498,1.0160] for dense. Canonical queries beat grouped queries in 9/9 blocks, yet grouped completes the whole job faster in blocks **2, 3, 6**. Dense wins the query stage in **9/9** and the complete job in **8/9**; canonical wins the complete job only in block **7** against dense. The outlying 3.477 ms grouped-cache stage is retained. No confidence interval, break-even point, reuse extrapolation or minimum-encoded-byte claim is made.

## Prototype capacities and adverse results

| Route | Sum of per-line source representation pairs | Per-distinct-m cached pairs / phase values |
|---|---:|---:|
| Cached raw | 961 | 6,559 residue/span pairs |
| Ordinary grouped | 961 raw input pairs | 1,459 grouped pairs |
| Prospective canonical | 765 g* pairs | 812 reset pairs, held as 1,624 residue/span scalar array entries |
| Dense phase | 961 raw input pairs | 3,696 envelope scalar values; 1,459 grouped construction pairs |

There are 80 separate line records, 416 finite-prefix triples and 961 recurrent triples. The **961→765** comparison sums per-line records; it does not quotient relations across lines. The 812 target pairs count only distinct m caches; it must not be mixed with the prior analysis's 1,758 projection pairs counted once per physical P. Prefix cached values, gcd cached values, retained raw triples, Python tuple/object overhead and temporary construction data are separate costs. These counts describe this prototype's capacities and construction terms, not encoded bytes, peak resident memory, or hardware cache sizes.

All original negative and no-gain cases remain included. Thirteen cases have zero service-only admissions: `p2_b0_r3`, `p2_b1_r3`, `p3_b0_r5`, `p4_b0_r5`, `p4_b1_r5`, `p4_b2_r5`, `p4_b3_r5`, `p6_b0_r5`, `p6_b1_r5`, `p6_b2_r5`, `p6_b3_r5`, `p6_b4_r5`, `p6_b5_r5`. Per-case admission counts and per-line cutpoint/d/g*/capacity rows are in `VALIDATION.json`; the input artifact retains all 19,613 independent negative first-failure executions. No prefix rejection or response stall is invented for a case lacking one. Timing results are whole-portfolio results; no per-case runtime advantage was measured.

## Files and verification

- `producer.py`, `workflow.py`: portable standard-library implementation. The producer/control class does not import historical or native HUSH code.
- `PROTOCOL.json`, `SCHEDULE.json`, `QUERY_STREAM.json.gz`, `EXPECTED.json`: prospective design, all orders, complete shuffled stream and frozen source/expected-output bindings.
- `PRODUCER_COPY_BINDING.json`, `VALIDATION.json`: byte-identical source-class binding, all exact slack checks, independent event-count checks and prototype capacities.
- `ALL_TIMINGS.jsonl`, `ALL_TIMINGS.json`, `RESULTS.json`: original journal, all 36 invocations and complete numeric summaries, paired ratios, environment, output hashes and adverse outcomes.
- `audit_saved.py`, `SAVED_AUDIT.json`: untimed consistency audit of source/input hashes, complete grid, schedule, journal, every measured output and all reported summaries. It does not repeat timing.

Existing results can be checked without rerunning the experiment:

```powershell
python -B -X utf8 r03/hush-workflow-cost/audit_saved.py --check-only
```

For an explicitly identified independent replication, copy `producer.py`, `workflow.py`, `PROTOCOL.json` and `audit_saved.py` into a **fresh output directory**, preserving this original directory. With the frozen sibling input directory supplied by `--inputs`, run `workflow.py prepare`, then `workflow.py validate`, then `workflow.py time --lane-confirmation 'actual root lane confirmation'`, each under existing Python 3.12 with `-B -X utf8`. Prepare/validation perform no runtime measurements. Timing refuses an existing journal/result and requires lane confirmation. A replication produces its own complete nine-block run; it must not replace, trim, or selectively rerun the original measurements.

No software/dependencies were installed, no remote host was contacted, and no existing process was terminated. There were no failed correctness or timing attempts in this run. Manuscripts, figures, reviews, frozen source evidence and publishing state were not modified by this workflow study.

## Publication metadata note

The private Python executable installation path was removed from the recorded timing metadata and this command example. The derived timing-file hash in RESULTS.json was updated accordingly. Every timing number, schedule, measurement output and scientific count remains unchanged. SAVED_AUDIT.json is the original audit provenance and retains its original file hashes; the root runner performs a fresh audit of the published files.
