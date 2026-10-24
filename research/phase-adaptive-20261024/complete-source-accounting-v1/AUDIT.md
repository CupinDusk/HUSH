# Complete FIR2DIM source-event accounting

This experiment is supporting evidence for bounded analysis, not a native kernel
performance result. The protocol was written before instrumentation compilation
and model runs. The original R13 model is copied byte-for-byte and remains
unmodified (SHA256 `6270a7fa1c79a81dab99f9712e170c60c1ded14dd5052f3b987ba421a1b99e10`).

## What is complete

The selected entry is TACLeBench `fir2dim_main`, including both calls to
`fir2dim_pin_down`, all convolution operations and the checksum assignment. We
compiled the original and instrumented sources using Zig 0.14.1; both return 0,
and the instrumented checksum is 14. All 782 explicit global data accesses are
logged: 145 input reads and 637 other reads/writes. The original 145-read trace
accounted only for the input sequence, so it is not used as a complete program.

| Access | Count |
| --- | ---: |
| Input array reads / writes | 145 / 72 |
| Coefficient reads / writes | 144 / 18 |
| Image reads / writes | 32 / 32 |
| Output reads / writes | 146 / 192 |
| Result scalar write | 1 |

The timing map supplies 1 or 4 non-data cycles per source data interval and one
cycle per private access. This is an explicit assumed timing envelope including
other computation, control, stack and instruction service; it is not inferred
from host instrumentation. Shared input is a 64-byte-aligned, read-only receiver
partition with one set and one/two LRU ways. Other accesses are covered by the
private service bound and do not allocate this partition. Preparation and cleanup
each have 93 private data accesses. Preparation precedes co-runner launch;
cleanup follows the join. This preserves a clean receiver during sharing.

## Controls and costs

All 255 legal fixed loads are compared with each of four subsets of free phase
boundary flushes, plus free end release. The phase family contains all 7^3
vectors in the previously used domain. Each noninitial phase marker spends a
four-cycle helper cost even if its load does not change; each actual load change
also spends the existing one-cycle registered write. Fixed mode needs no dynamic
helper. Candidates are admitted against the same receiver-work budget, selected
at tick phase zero, then frozen and tested at all ten tick phases. This compares
the phase-domain policy family with the exhaustive fixed policy family; the
phase family does not include arbitrary fixed loads outside its seven values.

The 2,000/4,000-cycle budgets constrain the receiver's own bounded work, including
preparation and cleanup, rather than joint completion. The reported fork/join
completion is preparation + max(receiver body, writer body) + cleanup. In the
two-way case, the joint completion exceeds the 2,000-cycle receiver budget
because the writer finishes later. No claim that the whole fork/join job meets
that receiver-only deadline is made.

## All outcomes

The frozen eight settings contain four compute/cache combinations and two
budgets. Three settings admit both families; five have no admitted family. There
are 2,326 admitted candidate executions and 30 selected timing comparisons, with
zero unsafe predicted hits. Selected phase loses all 30 comparisons by 6 or 7
cycles; there are no joint-completion wins or ties. For example, two ways and
compute gap 1 give 2,180 fixed versus 2,186 phase cycles at tick phase zero. One
way gives 3,488 versus 3,495 cycles. These results do not establish a complete
kernel speedup for dynamic T.

Static memory-bound evidence remains useful. An exhaustive diagnostic comparison
of carry-in versus reset on the same 1,372 phase/cache/compute paths, added after
the first execution run, has 350 strict bound improvements and no worsening.
All rows are retained; this diagnostic does not change the frozen selection
rule. The pre-existing R13 path `(254,16,1)` in the one-set/two-way, gap-1 scenario
has memory bound 425 with carry-in versus 565 with reset (24.8% tighter). With
all other source-event costs and the eight helper cycles accounted for, its
receiver-work bound is 1,854 versus 1,994 cycles (7.0% tighter). This comparison
changes analysis only, not physical execution or deadline.

## Interpretation

Use this material to support complete cost accounting and the static-analysis
contribution. It cannot replace an actual full-kernel gem5/RTL/processor
experiment with the real phase interface, measured service contracts and unified
cache allocation, and it does not justify asserting an application speedup.
Initialization/finalization are serial in the modeled wrapper; concurrent writer
values are abstract versions, so the original checksum check verifies the source
event extractor, not the concurrent numerical result.

## Replay

Run `python -B run_complete_accounting.py` using the checked-in event trace.
`instrument_kernel.py` optionally regenerates it from the retained original C
source; set `HUSH_C_COMPILER_JSON` to a JSON argv array such as `["clang"]` or
`["zig","cc"]`. The extractor excludes printf logging from modeled time.
Results retain every admitted candidate and all held-out comparisons. The
minimal replay archive excludes compiler binaries, executables, PDB files,
private source, paper, reviews and server configuration.
