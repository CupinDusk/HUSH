# R18 native phase/cost decomposition protocol

Fix the previous N16-selected nonconstant plan16384/16384/2048. No plan
selection from these timings. Inputs N32/36/40,64lags,dense refresh,
64storesperline,16KiB unified two-way caches and same native ELF.

Per size run15 fixed loads, phase apply and matched suppressed-write
ablation at extra changed-load stalls0/8/16/32/64, WI/WU controls, and two
legacy-layout instrumented replays (phase8 and previous best15fixed):
29 cases per size,87 total. Apply/suppress pairs have identical binary,
descriptors, guest control instructions and leader stall. Suppression
changes only whether the host callback applies future-arm timeout writes;
its actual timeout remains the initial16384 throughout. This isolates the
timeout mechanism from the guest helper path. Suppression is an ablation,
not a replacement for the full fixed-family baseline.

For new-layout cases all COST argv/env strings have exactly five digits,
keeping the initial stack layout constant across costs. The six legacy
replays retain old argv/env bytes. Zero-time stats dumps at phase1,phase2,
last worker completion and join yield cumulative counters. First validate
that all six legacy replays match prior joint times, task markers, miss,
WU and replacement counts; these establish that observation did not alter
the reported runs. Preserve all failures and signed effects.

Four system epochs are validation,FIR,features-to-last-worker,join tail.
Counters describe the whole concurrent system over these intervals, not
only one consumer. Subtraction of cumulative counters must recover total
ROI counters. Record WU,miss/replacements,instructions and worker times.
Extra leader stall is an experimental parameter, not a measured CSR bound.
The native prototype and the analytical2client contract remain distinct.

Two ordinary-user workers,20billion-tick natural limit, no process kills.
All raw rows, protocol, executable/source hashes and reduction stay bound.
