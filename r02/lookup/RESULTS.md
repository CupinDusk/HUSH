# Local exact-query implementation results

2026-10-23; attempt1 passed. This study measures one C++17 implementation on an Intel Core i9-14900HX / Windows11 using Zig0.14.1 Clang19.1.7, `-std=c++17 -O3 -DNDEBUG -Wall -Wextra`. It makes no application/cache-hardware or universal CPU speedup claim.

All10,572 profiles (10,454 family +118 wide), all14 corpora,1,474,560 query records and5,472,256 per-query route checks passed. Frozen Python grouped/canonical pairs and native reset conversion matched; a separate Python integer audit recomputed all profiles and all query checksums. All387 timing observations follow the frozen126 paired-block orders. One untimed warm pass preceded nine blocks per corpus. No failed attempts occurred; all frozen input hashes remained unchanged.

Median hot-query nanoseconds per query follow. Min/max, all raw per-block values/order/checksums, paired ratios, construction observations and full storage counts are in `RAW_RESULTS.json`; native events are preserved byte-exact in `native_events_attempt1.jsonl`. Wide dense tables are unavailable because their modulus exceeds the fixed2^20 cap.

| Corpus | Profiles | Grouped scan | Canonical scan | Reset predecessor | Dense table |
|---|---:|---:|---:|---:|---:|
| family | 10454 | 5.833 | 5.699 | 8.526 | 2.642 |
| random_t1 | 16 | 0.937 | 0.940 | 4.822 | unavailable |
| random_t2 | 16 | 3.998 | 1.611 | 5.255 | unavailable |
| random_t3 | 16 | 7.397 | 1.785 | 5.408 | unavailable |
| random_t8 | 16 | 12.244 | 4.202 | 7.538 | unavailable |
| random_t32 | 16 | 30.878 | 7.727 | 9.851 | unavailable |
| random_t128 | 16 | 103.735 | 13.370 | 14.062 | unavailable |
| random_t512 | 16 | 368.912 | 20.111 | 18.378 | unavailable |
| analytic_t1024_all_survive | 1 | 722.757 | 719.781 | 41.489 | unavailable |
| analytic_t1024_one_survives | 1 | 718.408 | 0.922 | 1.553 | unavailable |
| analytic_t4096_all_survive | 1 | 2880.698 | 2877.139 | 55.637 | unavailable |
| analytic_t4096_one_survives | 1 | 2890.967 | 0.925 | 1.419 | unavailable |
| analytic_t16384_all_survive | 1 | 11584.286 | 11575.995 | 72.134 | unavailable |
| analytic_t16384_one_survives | 1 | 11533.792 | 0.940 | 1.660 | unavailable |

The family is a negative result for predecessor lookup: its median8.526ns is1.50 times the canonical scan time; dense caching wins at2.642ns. Canonical-only pruning here is modest (19,544 grouped →19,131 canonical terms;320 pruned and10,134 unchanged profiles), with only1.024 ratio of grouped/canonical medians.

Predecessor also loses to canonical scan for random t=1,2,3,8,32,128 and all three one-survivor analytic cases. At random t512 it only modestly improves on the already-pruned scan; at analytic all-survive t=1024,4096,16384 it provides a large local query-time reduction while canonical scan has essentially no benefit. These selected synthetic strata do not estimate how often an application meets any of these conditions.

Persistent route payload capacities use the actual C++ array allocations: Pair=32bytes, Reset=32bytes, signed128=16bytes. For the complete family, grouped/canonical/reset payloads are respectively625,408 /612,192 /612,192bytes, while the94,937-value dense cache uses1,518,992bytes. At analytic all-survive t16384, each sparse route payload uses524,288bytes; at one-survivor t16384, grouped uses524,288 and canonical/reset each32bytes. Both canonical and reset arrays coexist in this benchmark, alongside raw/oracle/query arrays; these are per-route payload counts, not total process memory or minimum encodings. Allocator/runtime/temporary construction overhead is excluded.

Construction wall time is separate and includes output allocations; each cell below is one observation in milliseconds, without a repetition or uncertainty claim. Canonical conversion starts from the grouped rows; reset conversion starts from canonical rows; dense construction scans grouped rows at every admitted phase.

| Corpus | Grouping ms | Canonical ms | Reset ms | Dense ms |
|---|---:|---:|---:|---:|
| family | 0.892200 | 0.852600 | 0.563500 | 1.099400 |
| random_t1 | 0.002300 | 0.001300 | 0.000800 | unavailable |
| random_t2 | 0.002400 | 0.001500 | 0.000700 | unavailable |
| random_t3 | 0.002300 | 0.002200 | 0.000900 | unavailable |
| random_t8 | 0.002700 | 0.003900 | 0.001100 | unavailable |
| random_t32 | 0.005100 | 0.005900 | 0.001600 | unavailable |
| random_t128 | 0.011700 | 0.014200 | 0.001900 | unavailable |
| random_t512 | 0.111400 | 0.024000 | 0.002200 | unavailable |
| analytic_t1024_all_survive | 0.021400 | 0.016900 | 0.010800 | unavailable |
| analytic_t1024_one_survives | 0.006200 | 0.014100 | 0.000400 | unavailable |
| analytic_t4096_all_survive | 0.053100 | 0.054600 | 0.030900 | unavailable |
| analytic_t4096_one_survives | 0.018900 | 0.019100 | 0.000400 | unavailable |
| analytic_t16384_all_survive | 0.151700 | 0.163800 | 0.100700 | unavailable |
| analytic_t16384_one_survives | 0.073800 | 0.057700 | 0.000400 | unavailable |

The prospective portfolio check remains mathematical evidence from `VALIDATION_RESULTS.json`: choosing every P≤4p forces the full translation modulus in1,604/1,622 cases; singleton2p does so in650 and pair2p,3p in963. Those forced-full cases are retained, and this query benchmark does not convert storage support into a workload-frequency or application-performance claim.

Reproduce from this directory with the bundled Python using `-B -X utf8 run_native.py attempt2` (a fresh attempt identifier preserves previous logs), then `-B -X utf8 analyze_native.py attempt2` only after choosing fresh derived-output names. Exact compiler/execution commands, source/executable/input SHA256, local CPU/OS and timestamps are in `COMMAND_PROVENANCE_attempt1.json`. The first attempt executable and source remain `benchmark.exe` and `benchmark.cpp`.

The prior frozen Python validation exhausts15,420 small profiles/60,844 phases, checks1,255,532 family physical phases and32,348 wide boundary/seeded queries. The native executable validates its full generated corpus; it does not replace that mathematical coverage with timing samples.
