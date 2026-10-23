# Phase-adaptive HUSH: registered configuration and carry-in analysis (v3)

This minimal package contains the independently written two-core execution
model, receiver RTL, formal miters and compiled TACLeBench access-order
control used by the current phase-adaptive study. It excludes the private
HUSH overlay, gem5 checkout, manuscript and server materials.

## Replay

Python 3.12+, plus a C99 compiler on PATH:

    python -B reproduce.py

Eight studies rerun and compare every scientific field (elapsed wall time
excluded) to expected/. Default compiler is cc. For another compiler, set
HUSH_C_COMPILER_JSON to a JSON argv array, e.g. ["zig","cc"]. Compiled FIR
return codes and input-read order are checked; this is not native multicore
application timing. Original source notice and pinned upstream hash are
in kernel-source/UPSTREAM.json.

The model has one outstanding operation per core, dedicated clean receiver
slots, a single authoritative writer, no replacement, 10-cycle WU service
and 60-cycle miss service. Admission reserves sharing for a pending fill;
at most one private-store/interlock cycle gives the declared 71-cycle
unknown-read bound. A configuration write changes only future arms and
holds a coincident WU for one cycle. Register writes cost one cycle;
runtime flag/table access is zero-cost in these experiments and needs
bounded deployment cost. These are architecture parameters, not measured
commercial-processor timings.

## Controls and interpretation

The tight sweep uses 79 fixed architecture scenarios and eight margins
above compulsory misses. Fixed policies scan all 255 loads and can flush
any subset of phase boundaries for free; both policies can release all
clean receiver copies at reader completion for free. Phase policies use
343 varying paths plus every exact fixed path. Among 632 feasible points,
241 beat the stronger fixed maintenance control, 366 tie and 25 lose;
carry-in beats reset analysis at 172. Losses and the FIR release-control
ties are retained. This finite grid does not establish application
generalization or dominance over explicit cache maintenance.

## Symbolic receiver checks and mapping

Use native Yosys with ABC (retained version 0.70+190, git485b63564):

    python reproduce_formal.py /path/to/yosys
    python map_controller.py /path/to/Nangate45_typical.lib /path/to/yosys

LIBRARY_SOURCE.json pins the typical library and SHA256. Mapping uses a
BUF_X1 driver and 5-fF output load. It reproduces six matched rows at
4/64/512 lines. These are prelayout estimates, excluding wire RC,
placement, clocks, queues, buffers and software; not full-system PPA.

step_*.v are verbatim-RTL one-step invariant miters for the original
prospective receiver; positive eight-bit loads, period1..255 and all tick
offsets. refinement_*.v proves the interlocked next-state relation equals
that receiver with WUs masked by acceptance, for arbitrary bit states.
The invariant therefore covers arbitrary duration of the accepted-WU
receiver relation, not arbitration, service bounds or full coherence.
Four refinement mutations are rejected. A direct interlocked nonlinear
arithmetic attempt timed out; the successful proof is refinement to the
baseline invariant. Expected proof receipts distinguish these facts.

deadline_oracle.cpp and buffered_cutpoint.cpp are independent C++17
checks for the baseline accepted-WU timer/capture interface. The former
accepts period/phase then time/config/newload/WU/read rows; the latter
executes 160 buffered response cases. Their expected receipts are saved.

All inputs and expected outputs are listed with hashes in MANIFEST.json.
