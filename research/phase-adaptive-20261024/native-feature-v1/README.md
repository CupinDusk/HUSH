# Native FIR/feature real-work sensitivity v1

Same native pipeline binary; lags1/16/64 change actual autocorrelation work.
324 N16 training runs select phase plans before216 N28 heldout runs with all
15 fixed controls. N32 is explicitly deferred by the pre-outcome budget
amendment in PROTOCOL.md; its algebraic loop counts are not execution claims.
All signed results are retained. The primary comparison uses best15 fixed
per heldout input; deployed mode separately follows training-only selection.

Recompute task-time, selection, baseline and bottleneck checks with
python -B reduce_results.py. Recompute source-loop/reference and elementary
retention inequality checks with python -B derive_work_and_retention.py.
The latter is a timer-function domination check; cache-residency and native
service/compute contracts are separate premises, as detailed in the audit.

To rerun simulation, use a compatible continuous-expiry HUSH-enabled gem5
build. The private simulator overlay and binary are excluded. Compile the
benchmark with gcc -static -pthread -O2 -std=c11 -fno-pie -no-pie using public
gem5/include and gem5/util/m5/src/abi/x86/m5op.S. Set HUSH_GEM5_BINARY and
HUSH_PIPELINE_BINARY, then python -B run_native.py TRAINING_MANIFEST.json or
VALIDATION_MANIFEST.json. Each manifest round writes a new output directory.
Two workers and a natural20billion-tick simulator limit are used.

No paper, reviews, account, host address, credential or private overlay is
included. Cycles are deterministic simulator observations.
