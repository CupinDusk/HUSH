# Independent author-side audit of the new reference RTL

The finite RTL gate passes. This is a separate author-side validation of newly constructed RTL, not external peer review, native HUSH/gem5 refinement, a hardware result, or a manuscript edit. No implementation bug was found in the admitted tests. Important unexercised states and negative results remain below.

## Actual fresh build and provenance

`portable-source/` is a byte-exact fresh copy of the selected producer sources and public frozen references. `fresh-replay-01/PORTABLE_REPLAY.json` records actual successful vector generation, Yosys version query, `read_verilog; hierarchy -check; prep; check -assert; write_cxxrtl`, Zig C++17 compilation, and generated-model execution. All five stages returned zero. No historical HUSH source or private overlay was inspected or incorporated.

The rebuilt `netlist.cpp` is byte-identical to the original generated model, SHA256 `b41df947e115fbe3502773c81e9993e6dafeb07db3e459cea91f01a586beed2f`. All four semantic CSVs and `RTL_RESULTS.json` are also byte-identical. The independently built executable has a different hash, `8def58078f5b1e01f875d1ac11dcb1681196a2a059ace7cd63701257f9af84c9`; binary reproducibility is not claimed. Its actual execution reproduces every semantic output.

`check_independent.py` checks all 45 original producer-manifest file hashes/lengths, six public-reference copies against the frozen R03 source files, all five pinned external tool file hashes, original build input/output bindings, and fresh replay input/output bindings. `ENVIRONMENT.json` records the actual Python executable/version/hash, flags, OS, Zig/Yosys versions and all CXXRTL runtime-header file hashes. It contains no environment-variable dump, credentials or server settings.

The RTL protocol hash is `2b01630e8cd2c70860dcd821052dc3a745a2d3b7ade8e2ec4745baf625ffcc33`; the frozen R03 reference protocol hash is `536a35c9d37ca727028609c8a742fb9454b6942fb64d5b1d8e2640de807dcaba`. The initial generator-path failure remains in the producer's `failure-01-generator-path/`; `vectors-v1/` remains empty. The checker verifies that the retained original generator differs only in default reference-path resolution. No case, phase, negative witness or data outcome was replaced.

## Independently reconstructed checks

The checker imports no producer generator, controller implementation or C++ driver. Its own per-client records, deque and immutable snapshot tuples implement the public event contract. It independently reproduces all frozen normalized keys and ordered events, then compares every serialized raw CSV column, including stale payload latches when their valid bit is clear. It checks every control and policy vector field and every case/policy aggregate. Exact equality of fresh and original output files transfers these checks to the author run as well.

From the events it separately reconstructs the first repeated complete key, all 416 prefix edges and 961 recurrent edges, initial capture cutpoints, adjacent same-line grants and matching request emissions. It verifies complete-key translation through the retained extra cycles. No source poll, simultaneous enqueue, grant, emission, transfer, backpressure or callback mismatch was found.

For each physical phase, the auditor independently computes the first decrement after `s+1`, uses `gcd(P,d)` for recurrent translations, and adds `(K-1)P` for later decrements. It reconstructs exact prefix/recurrence minima, tight per-line completion bounds, physical minimizer edges, exact/completion policy masks, compression support status and every public negative witness. The literal one-WU expiry is `s+1 + ((phi-(s+1)) mod P) + (K-1)P`; safety through the attempted grant requires expiry strictly after `h`. The checker independently counts expected grant/emission totals from the frozen translated event sequence, including suppression of same-tick emission when the negative grant fails.

| Evidence | Independently checked result |
|---|---:|
| Complete control cases / logical ticks | 40 / 22,823 |
| Declared one-WU policies / logical ticks | 37,000 / 25,137,870 |
| Positive survivals / negative first failures | 17,387 / 19,613 |
| Fixed-pattern snapshot runs / logical ticks | 120 / 68,469 |
| Snapshot captures / emissions | 9,897 / 9,807 |
| Armed-timer cancellations | 9,657 |
| Snapshot response-backpressure ticks | 1,071 |
| Frozen cases reaching FIFO occupancy two | 40 |
| Cases with actual response backpressure | 26 |
| Poll-before-callback ties / simultaneous enqueue ticks | 119 / 158 |
| Data WU/decrement coincidences / WU/capture coincidences | 2,799 / 9,777 |

All 91,292 serialized control/data ticks are checked in full. Policy outputs retain every query and observed first-failure/expiry/count aggregate, rather than a raw per-tick policy dump. The actual C++ driver executes all 25,137,870 policy ticks and its DUT fault/snapshot checks; the independent auditor verifies every serialized policy result and reconstructs its expected event totals and witness from the frozen schedule. It does not claim that absent per-tick policy CSV fields were independently observed.

The service observer admits 17,387 physical policies versus 16,948 for the fair per-line completion observer: 439 service-only and zero completion-only outcomes. Thirteen cases have no service admission gain; their exact IDs are retained in `INDEPENDENT_AUDIT.json`. The 7,425 unsupported compressed queries remain unsupported; the 29,575 supported queries include 13,883 exact positives, 15,692 negatives and 333 service-only admissions. These are correlated calculations over fixed cases, not independent workload samples or an application speedup.

## RTL source review

The exact reviewed source is `portable-source/receiver.v`; the fresh generated model is `fresh-replay-01/netlist.cpp`. Yosys successfully lowers this single synchronous sequential block into the generated CXXRTL design. No hand-written C++ controller replaces the DUT.

| Obligation | Source observation and exercised evidence |
|---|---|
| Initial entry | Lines 34-46 synchronously reset initial valid tags, zero bytes, disabled counters, empty queue/registers, polls at 0/b and phase zero. The driver holds configuration during a run and supplies no line WU before its initial capture. Initial cutpoints are independently re-extracted from actual frozen events. |
| WU/load/decrement/read priority | Lines 50-63 preserve entry R0 occupancy, apply valid-only byte/WU loads, then phase decrement and invalidate/disable on zero. Lines 87-99 attempt the real FIFO-head tag read after these effects. A failed read records tick/owner before suppressing later boundary pipeline work. All K/P/phi cases and exact negative expiry boundaries are retained. |
| Source and tie order | Lines 65-86 poll A then B. Pending polls enter wait before callbacks at lines 112-120; callbacks only replace the poll time when wait is set. All 119 same-client poll/callback ties and 158 simultaneous enqueue ticks agree with the independent model. |
| FIFO/token ownership | Lines 69-84 append in A/B order; lines 89-99 capture the oldest owner/ID only when tick-entry R0 was empty. Lines 124-132 check per-client token conservation, capacity and wait/poll discipline. The separate auditor reconstructs all live identities from its own deque/register state. |
| Emission/transfer/callback | Lines 101-122 emit the old R1 only if ready, transfer R0 into empty R1, and finally clear the emitted client's pending token. A blocked R1 keeps its snapshot; the checker verifies byte/identity and future source state on every raw tick. |
| Counter cancellation | Lines 96-97 disable and zero the captured line's counter. All raw data counter/enable/cancel fields and 9,657 armed cancellations agree with the independent model. |
| Data/snapshot order | Lines 52-53 update line bytes before a successful read; lines 94-95 capture the byte into R0, lines 105/109 emit/transfer only the saved register byte. Three predeclared patterns cover zero, 255, and `(17*t+73*owner) mod 256`. The later WU cannot alter a pending saved response in the observed runs. |
| Finite widths | Lines 5-18 and 29-32 declare 16-bit ticks/polls/IDs, 3-bit K/counters/p/ready phases, 5-bit expiry period/phase and 8-bit bytes. Lines 46/68/79/118/133 guard configuration, sequence and tick arithmetic; flags are checked on every admitted driver tick. Control/data observed maximum tick is 1,214, next poll 1,217, request ID 103 and counter 5. Policy maximum target tick is 7,332. Even a newly scheduled largest `3p+1=19` poll at that horizon is below 7,352, far below 65,515; at most one new request per client per tick gives a conservative ID bound below 7,334. |

The source includes entry-R0 grant gating, but **R0 already occupied with a queued head at grant is exercised zero times**. It receives no coverage credit. FIFO occupancy two is a different event, and ready-based response backpressure is separately observed. In this one-pending-per-client two-token family, occupied R0 normally accompanies occupied R1 and leaves no third token for a queued request; no generalized queue-block validation is inferred.

## Actual mutation sensitivity

Four deliberately altered RTL copies under `mutation-tests-01/` were each freshly read/prepared/checked/generated by Yosys, compiled by Zig, and run against unchanged frozen vectors and driver. They all synthesize and compile successfully, then fail semantically:

| Copy-only mutation | Actual rejection |
|---|---|
| Decrement before WU load | Policy 0 negative first-failure/expiry witness mismatch |
| B poll before A poll | Case 0, tick 0 grant owner is 1 instead of 0 |
| Missing counter-enable cancellation | Data case 0: successful capture did not cancel timer |
| Emission reads live line data | Data case 0, pattern 1: emitted snapshot changed |

Their changed source/netlist/executable hashes, actual commands, rejection logs and partial outputs are retained. These probes show sensitivity to the four specified errors; they are not a correctness proof and do not alter the accepted baseline.

## Limits and paper-use boundary

All 19,613 negatives remain failed tag attempts at the predicted first `h`; they are not repaired misses. Fourteen of the 40 cases have no actual response backpressure. Thirteen have no service admission gain. No adverse case was removed.

The declared one-WU words are all executed; arbitrary WU words are not exhausted. Any universal positive guarantee still requires the separately stated conditional first-failure/monotone-rearm argument. The data runs use only three fixed patterns with K=5/P=24/phi=0, independently on two dedicated lines, and WUs every tick only after initial capture. They do not establish arbitrary coherence, replacement, refill, memory ordering, revocation recovery or native data behavior.

No invalid configuration, overflow boundary, hot configuration change or changing clock was tested. Configuration inputs are not latched by the RTL and must remain epoch-stable as specified. Finite-width success is not an unbounded formal proof. No physical implementation, timing closure, area, power, energy, throughput, application benefit, or native HUSH/gem5 refinement has been established. Build-tool operational timing text is not a performance benchmark. No remote operation or process termination was performed.

The independently validated finite result may be described using `PAPER_READY_FACTS.json` and `PAPER_READY_FACTS.md`. This audit changed only this `independent/` directory; producer sources, manuscript, figures, existing reviews, release artifacts and root README remain untouched by this auditor.
