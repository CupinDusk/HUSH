# Complete native FIR/feature pipeline experiment

This is an original controlled four-thread application, not unmodified
TACLeBench FIR2DIM. It validates the executable phase interface and complete
worker-region timing. Three consumers validate input, compute 3x3 weighted FIR,
normalize and autocorrelate16 lags; one atomic producer refreshes identical
input values with sparse/dense spatial locality. The reference/checksum
verifies completed arithmetic. Identical-valued refresh is not an independent
stale-version oracle; checked HUSH transport/invariant counters are separate.

All216 N8 training runs and160 heldout N12/N16 runs pass program completion,
phase/task-marker checks and recorded invariants. Policies were frozen before
heldout timings. All five fixed loads are retained, along with selected phase
plans at added-write stalls0/8/16 and WI/WU controls. Initial setup/reference
computation is before ROI; timing spans worker start through all joins. Native
expiry is continuous, unlike the quantized analytical model. Source marker
callbacks apply future-arm loads to four L1s; this is a gem5 API prototype,
not a measured production CSR. Guest marker/table/barrier instructions execute
normally; m5_quiesce_cycle supplies the declared changed-load stall.

The best tested fixed comparator is the heldout minimum of five loads
8/64/512/4096/65536. Selected-phase normalized timing ranges0.99897698–1.00058431;
the native experiment supports implementation feasibility, not a material
application speedup. Full signed records remain available. The dedicated-slot
model and source-event bound studies are separate evidence packages.

Re-execution requires a HUSH-enabled gem5 binary exposing the Cache and XBar
parameters and hushSetPhaseTimeout API used in config_v2.py. The private
research overlay and simulator binary are not included in this package.
The recorded binary SHA256 is
9765649c8c8336e1d784ff7fbe239b643c37c068cc936cc9b70e80d02ec75fbd.
For an available compatible build, compile the C source with gcc -static
-pthread -O2 -std=c11 -fno-pie -no-pie, include gem5/include and link
gem5/util/m5/src/abi/x86/m5op.S. Set HUSH_GEM5_BINARY and
HUSH_PIPELINE_BINARY to local absolute executable paths, then run
python -B run_native.py VALIDATION_V3_MANIFEST.json. Output uses a new
round directory and two parallel jobs; no process termination is used.
No server address, account, credential, paper or review is included.
