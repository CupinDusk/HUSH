# Run this compact research export

Run `python -B -X utf8 replay.py`. It losslessly decodes the standard ZIP/base64
recorded-data file, restores the original LF JSON/CSV inputs and expected outputs,
runs the analysis below, and checks every scientific output SHA256. This text
transport keeps complete candidate/measurement records available without a large
plain JSON upload. The data are unchanged; no account, binary or private overlay
is included. Only the Python standard library is needed for recorded-data replay.

# Native stage and matched-timeout diagnostics

This package contains the public controlled FIR/feature pipeline source,
instrumented configuration, an environment-configured driver, compact selected
measurement records, and deterministic analysis for 117 completed native runs.
It contains no simulator overlay/binary, server identity, account, SSH setting,
paper, private review, or remote launcher.

## Recalculate the recorded measurements

Run `python -B -X utf8 reduce.py` then
`python -B -X utf8 reduce_legacy_pairs.py` using only the standard library.
The first script checks 87 instrumented cases and six legacy replays; the
second checks 30 additional legacy-layout matched cases. All 117 pass the
recorded functional/protocol checks. The compact data retain ROI/worker/phase
timestamps and cumulative instruction, WU, hit/miss/replacement and timer event
counts needed for these reductions, plus original raw-record canonical hashes.
They are selected raw counters, not the entire simulator statistics output.
The expected hashes bind regenerated outputs after Git LF normalization.

All four epochs are whole-system wall-clock intervals: validation-to-phase1,
FIR-to-phase2, features-to-last-worker, and last-worker-to-join ROI tail. They
include concurrent work and synchronization. L1 counters cover four unified
instruction/data caches; WU counts are bus-accepted transactions. Cumulative
subtraction must recover every total. ROI excludes earlier reference/setup
and later reporting. The 0--64-cycle injected leader stalls are experimental
parameters, rather than measured production CSR/helper WCET values.

## Matched intervention and interpretation

The phase tuple is fixed at 16384/16384/2048. Each apply/suppress pair shares
guest bytes, descriptors, helper path and stall; only host application of the
future-arm cache-timeout API writes differs. Suppression leaves actual T at
16384 throughout. There are 15 fixed-width and 15 legacy-layout pairs. All
pre-intervention epochs match within their pair; all counters reconcile.
Across both layouts, the direct completion effect lies between -0.009441%
and +0.019228%, below 0.02% in absolute value. This is an implementation
diagnostic for this conditional intervention, rather than evidence of a
material native application speedup.

The prior N32 phase-versus-best-fixed comparison reproduces exactly at 0.685639%.
Matched legacy cost8 apply/suppress times are 2251538/2251962 cycles: the later
timeout change contributes 424 cycles conditional on initial T16384. The prior
best fixed uses T32768 and has 2267082 cycles. Its remaining difference from
suppression also changes initial constant T and helper/interleaving behavior;
this experiment does not attribute that residual to any single component.
No timeout policy is retuned from the new outcomes. All signed cases remain.

## Running a newly provisioned native simulator

The driver requires an independently available compatible HUSH-enabled gem5
implementation exposing `hushSetPhaseTimeout` and the configuration's HUSH
parameters/counters. Those simulator extensions are not included in this
minimal package; stock gem5 alone does not provide them. Recorded simulator
and ELF hashes are in `SOURCE_BINDING.json` for environment comparison.

Set `HUSH_GEM5_SOURCE`, `HUSH_GEM5_BINARY`, and `HUSH_PIPELINE_BINARY` to your own
local paths, then run `python native_driver.py MANIFEST.json` or the legacy
manifest in a fresh output round directory. The driver uses two workers and
a natural 20-billion-tick simulation limit, with no process-kill timeout.

Build the benchmark with your gem5 public m5ops support object and headers:
`gcc -static -pthread -O2 -std=c11 -fno-pie -no-pie -I GEM5/include fir_pipeline_v3.c m5op.o -o fir-pipeline-v3`.
The optional `-DMARKER_STUB` build checks functional results outside gem5.
The original recorded ELF hash is not promised by an arbitrary compiler build.
Native timing is sensitive to executable argv0 path length and initial
argv/environment layout. Five-digit cost strings control width in the main
87-case study; legacy cost strings vary in width across stalls, so those
contrasts must remain paired. Recorded reduction replay is fully self-contained;
recreating native timings requires the matching simulator/build/layout.
