# HUSH: phase-adaptive retention and reproducibility

HUSH is a time-bounded write-update coherence protocol for predictable shared-memory access. Its receiver timers retain useful copies and silently expire idle sharers. The phase-adaptive extension selects retention windows from the program's reuse pattern and carries timer and LRU facts across phase boundaries.

## Research collections

The links below separate the receiver model, static analysis, and native gem5 experiments. Each collection retains its inputs, numerical outcomes, source bindings, and replay checks. Start with the collection matching the experiment of interest.

| Question | Collection | Replay entry point |
|---|---|---|
| Phase-varying FIR reuse, timing bounds and update traffic | [Cropped FIR](cropped-fir-r50-v1/README.md) | Extract the collection and run `python -B -X utf8 VERIFY.py` |
| Matrix reuse intervals and carried timer bounds | [Matrix operand reuse](matrix-reuse-r52-v1/README.md) | Extract the collection and run `python -B -X utf8 VERIFY.py` |
| Complete budget sweeps | [Budget envelopes](budget-envelopes-r53-v1/) | Use the included verification script and protocols |
| Phase transitions and retention diagnostics | [Phase diagnostics](phase-diagnostics-r53-v1/) | Use the included verification script and protocols |
| Ordered timer/LRU transfer and native application integration | [Ordered analysis and applications](r55/README.md) | Follow the independent archive instructions |
| Finite-cache capacity, private-reference timing and quantized gem5 results | [Current cache and quantized native collections](r58/README.md) | Follow the three archive-specific replay instructions |
| Positioned phase-call computation | [24-case caller sweep](r62/README.md) | Extract the archive and run its verifier |

The collection READMEs identify the relevant simulator, service contract, benchmark port, and scope. Offline replay checks recompute the published tables or validate retained traces; a new gem5 simulation requires the documented simulator build and configuration. Earlier and current implementations are retained separately so that the original result provenance remains inspectable.

## gem5 implementation

The [HUSH repository](https://github.com/CupinDusk/HUSH) includes the simulator source. Native phase-adaptive runs, application sources, model changes and sanitized receipts are indexed in [R58](r58/README.md), with earlier prospective-retention application experiments in [R55](r55/README.md). The original HUSH core-protocol experiments and the phase-adaptive receiver study have distinct configurations, as recorded in their protocols.

## Initial prototype (historical)

The following instructions describe the initial dedicated-slot receiver prototype. The collections indexed above contain the subsequent finite-cache analysis and native gem5 work.

This package contains newly written receiver-timer RTL, a cycle-level
single-writer two-core HUSH subset, a conservative program-bound analyzer,
and finite phase-configuration experiments. It does not contain a gem5
checkout, private overlays, application measurements, or a full multicore
coherence implementation. The writer retains authoritative data; the
receiver has dedicated clean slots and no replacement. The sensitivity study varies their count from 2 to 16.

## Reproduce the program results

Use Python 3.12 or newer, with no third-party Python dependencies:

    python -B reproduce.py

The command reruns the program studies, bootstrap invariant and admission guard and compares every saved scientific field,
excluding elapsed wall-clock time. Input protocols and source hashes are
included. The fixed comparator scans all 255 legal loads (255 is infinity).
The dynamic domain is finite; no global configuration optimum is claimed.

The architecture model uses one outstanding request per core, round-robin
nonpreemptive service, a 10-cycle update slot and a 60-cycle miss slot.
A pending miss blocks admission of new private stores. One existing private store delays its grant by at most one cycle.
Thus an unknown read is bounded by 71 cycles. These are declared design
parameters, not measured timings of a commercial processor. Misses and
responses delay subsequent program issue, and register changes cost one
cycle. See the JSON protocols for all workloads and admission rules.

## Receiver RTL and independent checks

The RTL has positive eight-bit loads with 255 encoding infinity. A phase
write changes future WU loads; existing counters keep their remainder.
The formal harness in phase_timer.v independently checks absolute-expiry
conformance as well as conservative-hit safety. With Yosys 0.70 (the
retained run used yowasp-yosys 0.70.0.0.post1259):

    read_verilog -formal -sv phase_timer.v
    prep -top phase_safety -flatten
    chformal -lower
    sat -seq 48 -prove-asserts -verify

This is a bounded receiver check, not an unbounded full-protocol proof.
Load values in the formal harness are 1,2,4 and infinity, with period3.
The expected result includes the three separately rejected fault mutations.

Compile buffered_cutpoint.cpp with a C++17 compiler and execute it to replay
160 capture/response cases. The independent deadline_oracle.cpp is a stream
oracle: first provide period and phase, then rows of time, config_write,
new_load, WU_bitmask and read_bitmask. It emits pre-read valid masks.
Expected generated-run digests and 86,016-cycle agreement are retained.

Generic synthesis compares fixed and dynamic controllers at 4,64,512 lines.
Commands use synth -top phase_timer -flatten -noabc, or top
fixed_timer_controller, after setting N with chparam. Counts are generic
cells and sequential elements; they are not mapped PPA or frequency.
For native mapped synthesis, run map_controller.py with the Nangate45 library path and native Yosys executable path. See LIBRARY_SOURCE.json for pinned download and hash. This uses the same commands and checks MAPPED_COMPARISON.json. The native tool is OSS CAD Suite Windows 20261022 (Yosys 0.70+190, git485b63564); ABC estimates combinational delay with BUF_X1 input driver and 5-fF output load, without placement, clock or extracted wire RC. Logic area excludes system queues and buffers.

The whole processor, configuration-signal producer and software are not
included in these timer-controller counts.

## Interpreting the results

The timer safety result is conditional on explicit cancellation/capture,
fixed clock/granularity and no replacement. The relative-lifetime analyzer
uses the program's bounded compute intervals and the declared service bound.
All source/response behavior is confined to this single-writer model.
Online prefix admission preserves the reader budget, not cost optimality.
Unfavorable online outcomes are included. The worked 620-cycle bootstrap
budget is an illustrative query of the retained configuration table, not a
prespecified new workload or a measured deadline.

The earlier normalized-cost study and its failures are retained locally as
research history; they are not pooled with these cycle-level results.


## Ordered phase-call sensitivity (R62)

The [24-case frozen-plan caller sweep](r62/README.md) extends the positioned-caller study through 128 cycles per call. Its standalone archive checks all source hashes and replays every result byte for byte. This is independent event-model evidence, separate from the RTL and quantized gem5 series.
