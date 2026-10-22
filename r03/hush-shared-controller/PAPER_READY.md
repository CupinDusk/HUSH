# Shared-controller evidence for HUSH R03

All results below refer only to a **new specified bounded two-client/two-line digital controller**. They are independently replayed. Do not describe them as native HUSH, arbitrary-payload coherence, hardware or application validation. The prospective protocol and all negative outcomes remain in this directory.

## Compact methods paragraph

We also construct a bounded shared-response producer: two fixed-line clients, one pending request each, a two-entry FIFO, one grant per p ticks, and one-slot R0/R1 response registers. Periodic sink stalls hold immutable snapshots. With p=2..6, intervals 2p+1 and 3p+1, all second-client offsets 0..p−1, and ready-off periods 3 or 5, all 40 predeclared control instances reach an exact cycle within 575 ticks. The complete key binds relative polls, pending/wait bits, FIFO order, register ownership and clock phase. Poll/enqueue precedes grant, old-R1 emission, R0 transfer and callback. One pending token per line proves the two-entry bound; the all-hit schedule is independent of counters until a first failed tag read. Each line starts after its guaranteed first capture. Monotone rearm and a first-failure induction extend positive prefix-and-cycle slack to every optional zero-byte WU word under these bindings.

## Compact results paragraph

Two independent control drivers match 22,823 ticks and all 80 line relations: 416 prefix and 961 cycle edges. All cases reach FIFO occupancy two; 26/40 exercise response backpressure. Of 37,000 correlated policy queries, service evidence admits 17,387 and the line-aware tight (C,J,A) baseline with the identical exact prefix admits 16,948. The 439 extras (1.186 percentage points; 2.590% relative) occur in 27/40 cases; 13 gain none. Every rejected query has a retained one-WU first-failure witness. Prospective all-period support stores 765 versus 961 master pairs (20.4% fewer); no end-to-end timing or native HUSH claim follows.

## Table data

| Measure | Value | Denominator/meaning |
|---|---:|---|
| Prospective source configurations | 40 | All declared, none replaced |
| Closed exact-control cycles | 40 | No cap failures |
| Total initial cycle-detection ticks | 9,549 | Max 575/source |
| Independently matched validation ticks | 22,823 | Includes two post-detection cycles |
| Actual backpressure cases | 26 | 14 cases have no ready-off boundary hit |
| Two queued requests reached | 40 | FIFO bound always two |
| Prefix/cycle edges | 416 / 961 | 80 per-line records; 36 sources have a prefix |
| Complete service positive / unknown | 17,387 / 19,613 | 37,000 total |
| Strong line-aware completion positive | 16,948 | Same exact prefix, per-line tight J/A/C0 |
| Additional complete admissions | 439 | 1.186% of all; 2.590% relative baseline |
| Source cases with / without extras | 27 / 13 | Not independent workloads |
| Full d-master pairs | 961 | Canonicalization does not prune masters |
| Prospective all-P g* pairs | 765 | All 37,000 supported; 20.4% pair reduction |
| Posthoc g=d/gcd(d,3) pairs | 636 | 7,425/37,000 unsupported (20.1%) |
| Posthoc supported positive / unknown | 13,883 / 15,692 | 29,575 supported queries |
| Posthoc supported service-only extras | 333 | Do not confuse with full/prospective 439 |
| Recurrent positives removed by prefix | 0 | New family only; original family remains 5,200 |

## Independently verified example (not selected to replace any family member)

First service-only query in the declared traversal is `p=2,b=0,r=5`, `P=5,phi=0,K=3`: exact complete slack 2, strongest completion slack −1. Its minimum actual edge is line B `(s,c,h)=(28,30,38)`. One WU at 29 produces only two decrement events through h=38, so load3 survives. All earlier/no other WUs preserve control. This is illustrative; all forty cases and all 37,000 outcomes remain in the aggregate.

## Integration obligations

1. Define initial entry as immediately after each guaranteed successful capture; no arbitrary pre-WU start tick guarantee.
2. Bind FIFO, register capacities, ready function, arbitration and exact event order. The new controller resolves same-tick poll/receipt by poll-first; old single-source tie-rejected results remain unchanged.
3. Give the key and token-conservation reason timing is candidate-policy independent up to first failure. A captured response remains immutable even if its line later expires.
4. Keep zero-byte/no other invalidation scope. Real/native cache refinement and payload coherence remain unexecuted.
5. Use the same physical-period prefix in both routes and retain line IDs in the completion baseline.
6. If space requires one storage number, 961→765 is the **prospective all-period, fully supported** result. The 636-pair posthoc alternative requires the explicit 20.1% unsupported caveat.
7. Do not turn 9,549 detection ticks or input/operation counts into native wallclock performance. No full-workflow timing was measured here.

## Files

`RELATIONS.json` has all configurations, source-state closure/digests, per-line prefix/cycle, master/compact/prospective pairs, J/A/C0 and cycle translation. `TRACES.jsonl.gz` retains full deterministic event/control traces. `ALL_PHASE_BASES.jsonl.gz` retains every phase's exact/full/baseline slack, witness and K1..5 masks. `ALL_NEGATIVE_FIRST_FAILURES.jsonl.gz` retains every negative query's actual independent control/countdown witness. `INDEPENDENT_VALIDATION.json` records all replay counts and SHA bindings. `ARGUMENT.md` supplies the complete bounded-control and arbitrary-WU proof.
