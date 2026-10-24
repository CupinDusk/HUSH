# Native interface validation v2

This extends the previous complete FIR/feature pipeline package:
https://github.com/CupinDusk/HUSH/tree/95a97af6adf99acba0cd96860cbb7e1b871d4f11/research/phase-adaptive-20261024/native-pipeline-v1
The same continuous-expiry four-core HUSH build and config are used. This
package excludes the private simulator overlay and binary; re-execution needs
a compatible HUSH-enabled gem5 build. It is not a native WCET proof.

freshness/ is a changing-payload correctness regression, not a speed benchmark.
One producer writes monotone epochs and publishes with C11 release; three
consumers acquire the publication then assert every observed line version is
at least that publication. The final round32 must be read exactly. All24
cache/load cases pass168,480 data comparisons, zero stale reads, including
53–4,977 actual cache replacements. The protocol defines all allowed values.
Compile freshness.c with gcc -static -pthread -O2 -std=c11 -fno-pie -no-pie,
gem5/include and gem5/util/m5/src/abi/x86/m5op.S. Set HUSH_GEM5_BINARY and
HUSH_PIPELINE_BINARY to the compatible gem5 and freshly compiled benchmark;
run python -B run_native.py MANIFEST.json from freshness/.

pareto/ retains exploratory N8 full-grid analysis followed by frozen N20/N24
replication. All192 runs pass. Ten extra constant loads strengthen controls
fromfive tofifteen before heldout timings; the frozen phase plan stays512/512/8.
R is maximum measured consumer completion, not a WCET guarantee. All12 heldout
settings and all15 fixed points are retained, including regressions; there is
no material reproducible native speedup. Use the original FIR pipeline C,
set both executable environment variables, then run the portable driver with
VALIDATION_MANIFEST.json. No source/workload changes followed validation.

The bounded source-event receiver analysis and its paired1854 bound/1818
observation use their separate explicitly supplied service/compute contract.
No paper, reviews, server account, address, credential or private overlay is
included. All durations are deterministic simulator observations.
