# Complete policy admission for the existing specified family

This analysis fills a reporting gap in the recurrent-only R35 study. The mathematical family, physical-policy grids and fixed compact-storage rule are unchanged. A **timing-admitted source** has no reachable response/poll tie. A **fully admitted counter policy** additionally has a valid initial read, exact finite-prefix and recurrent safety, current bindings and all stated receiver/source obligations. These are different admissions.

The prospective protocol was saved before the new enumeration. The first execution stopped at a rejected-tie record-format assertion before computing any aggregate. `ATTEMPT1_FAILURE.log` and the partial gzip remain; the independent reconstruction had recorded the simultaneous poll time where the old record stored a nominal late-branch successor. No timing-tie source is admitted in either convention. The correction preserves the old rejected record and does not select or alter the domain.

## Complete slack and fair baselines

For physical policy `(K,P,phi)`, let `B=(K-1)P` and `F_P(r)=r+((phi-r) mod P)+B`. Let `Tpre` be the original finite prefix, `T0` one cycle and `d` its translation. The complete exact observer slack is

```
Epre = min_{(s,c,h) in Tpre} (F_P(s+1)-h), or +infinity if Tpre is empty;
Erec = B+1+min_{(s,c,h) in T0} (((phi-s-1) mod gcd(P,d))-(h-s));
Efull = min(Epre,Erec).
```

The prefix uses original absolute times and **physical P**, not the recurrent gcd. Only the recurrence's remainder changes to `m=gcd(P,d)`; the physical load remains `B`. Every query uses these same edge relations, including negative and zero outcomes. Initial read `s0` needs a fresh valid/disabled line and has no preceding modeled edge.

The primary completion comparison certifies **exactly the same prefix** as the service route. Set `Jr=max_T0(c-s)`, `Ar=max_T0(h-c)` and use actual `C0={c:(s,c,h) in T0}`. Its tight recurrence is

```
Drec = B+1-Jr-Ar+min_{c in C0} ((phi+Jr-1-c) mod gcd(P,d));
Dshared = min(Epre,Drec).
```

Thus a full service-only admission cannot be attributed to making the completion route forget prefix correlations. Both routes pay for/bind the identical exact-prefix result. Secondary diagnostics retain (a) segment-tight completion bounds using separately tight prefix and recurrence extrema, and (b) one global `Jall/Aall` over both segments. Pointwise,

`Dglobal <= Dsegment <= Dshared <= Efull`.

Only the strongest `Dshared` comparison should lead the paper's admission result. Prefix grouping or reuse costs are not quantified here, and this computation is not a performance experiment. The complete outputs and phase-base file permit reconstruction of every original/expanded query outcome.

## Why positive complete slack implies arbitrary-WU validity

At a successful service `s`, the read cancels all earlier arms including a same-tick WU. If a later optional WU exists before `h`, its arm time satisfies `r>=s+1`. Counter refinement gives expiry `F_P(r)`, and `F_P` is nondecreasing. Rearming cannot make expiry earlier. Consequently `F_P(s+1)>h` excludes expiry before/at the next read for **every** optional WU word. With no WU, the timer stays disabled. No other invalidation/revocation is admitted.

Start from the fresh valid initial read. Suppose a first failed matching read occurred. All earlier reads succeeded; source/control closure and immutable response snapshots therefore supply its predecessor edge in the finite prefix or translated cycle. `Efull>0` gives `F_P(s+1)>h`, contradicting expiry; all other failure causes are excluded by bindings. This is a first-failure induction, not an empirical claim that sampled WU words cover an infinite language. The result concerns validity/control and optional **zero-byte** WUs, not arbitrary-payload coherence.

If `Efull<=0`, choose a minimizing physical edge, omit all earlier WUs, and issue one WU at its service plus one tick. Earlier reads remain valid because their timers never arm. The literal counter can then expire before/at this next read. Captured response timing survives invalidation, so the next read is still at its stated `h`. The checker independently counts actual decrement events and applies the enabled/count transition for each load 1..5; it does not use the slack formula as a counter implementation. This sharpness witness is specific to this specified receiver and unrestricted optional zero-byte-WU alphabet, not an unconditional theorem for any upstream timing abstraction.

## Complete within-tick event order

This table specifies the implementation order read in the unchanged `endpoint_implementation.hpp`, `endpoint_family_main.cpp` and `endpoint_port.cpp`. It adds the previously implicit source/pipeline phases to the core counter order.

| Order | Event | State effect |
|---:|---|---|
| 1 | Revocation, if present | Invalidates and disables; excluded in admitted safe runs. |
| 2 | Optional valid-only WU | Updates zero byte and loads `K`; invalid WU cannot resurrect. |
| 3 | Decrement at physical phase | Decrements an enabled count, invalidating at zero. |
| 4 | Scheduled source poll/read | Outstanding poll sets the source wait flag; otherwise a successful read cancels the timer and captures immutable `(ID,byte)` into `R0`. |
| 5 | Cache boundary, if `t mod p=0` | Save/emit old `R1`, transfer `R0` to `R1`, then clear `R0`. The new service capture is already visible to this transfer. |
| 6 | Emitted response callback | Completes/removes the outstanding request. A waiting source schedules its next poll at `c+q`; otherwise its existing `s+q` poll remains. |

Therefore service exactly at a boundary transfers its new `R0` that same tick and emits at the following boundary `s+p`. A nonboundary service transfers at the first boundary at/after `s`. Both cases give `c(s)=p*ceil(s/p)+p`. Poll/receipt equality is rejected throughout the timing family; this study does not invent a tie-resolution behavior.

## Source information represented by the two worked-policy graph keys

For the `p=12,q=35,s0=0` example, every delay is at most 23, so every receipt precedes the next scheduled source poll. There is never an outstanding request when the poll at the next multiple of 35 fires. `waitResponse` is always false; retry is never entered under the accepted always-ready receiver guard. At the **beginning** of tick `t`, its scheduled poll is `t+((-t) mod 35)` (including the current tick when `t mod 35=0`). An early response leaves that event scheduled. Immediately after a service tick the following poll is 35 ticks later.

Before the current service stage, source outstanding status is exactly `R0.occupied or R1.occupied`: successful read creates both one pending packet and one snapshot; the boundary callback removes that packet exactly when old `R1` emits. No other packet is created or removed. When occupied, the register's ID identifies the pending packet. The **finite quotient labels** a service at `s=35k` by `1+(k mod 12)`; receipt occurs before label reuse. The source adapter's actual IDs increase monotonically; translation simultaneously renames the sole pending-map ID and register ID to this quotient label. Source guards use identity equality/freshness, not numeric ID arithmetic, so this renaming preserves behavior without aliasing within the bound no-overflow horizon. `t mod L`, with `L=lcm(420,P)`, determines the service/poll phase, cache boundary, timer phase and quotient-ID schedule. The record's occupied/ID/snapshot fields determine remaining response state. These facts recover the omitted source guards and pending event, making equal keys/input WU produce equal next keys and observations under translation. Fixed address/byte/RNG and an adequate nonfiring watchdog remain explicit source bindings.

The five pinned public method bodies are `MemTest::tick`, `MemTest::sendPkt`, `MemTest::recvRetry`, `MemTest::completeRequest` and `MemTest::CpuPort::recvTimingResp`. They compile byte-exact within declared adapters; `recvRetry` is compiled but not exercised on the accepted always-ready path. Neither byte equality nor these control invariants establish native cache/queue conformance.

The two graph sizes are **not** 3,618/7,236 each. Unchanged R34 summaries give:

| Physical policy | Time quotient L | States | WU edges |
|---|---:|---:|---:|
| `(K,P,phi)=(2,40,1)` | 840 | 2,034 | 4,068 |
| `(5,10,1)` | 420 | 1,584 | 3,168 |
| Aggregate across both graphs | — | 3,618 | 7,236 |

Each key has both WU successors. Existing independent replay checks edge arithmetic; completeness additionally relies on the source invariant above and work-list closure. No additional native or source execution was performed for this prefix reanalysis.

## What a reusable record must bind

A recurrent compact payload alone is not a complete admission certificate for an entry with a prefix. Bind line/tag/epoch, source and receiver digests, clock/tick order, lane/sink capacity, horizon/no-overflow, source entry `(s0,p,q)`, recurrence `(T0 digest,d,g,Qg)`, and either (i) a separately justified valid cycle entry, or (ii) `Tpre` digest and a positive exact-prefix result under the **actual queried `(K,P,phi)`**. The prefix certificate includes its first/last edge and cycle-entry boundary; a new policy needs its own checked prefix slack, even if the recurrent `Qg` supports projection. No old prefix-positive bit carries over without this policy binding.

Consumer procedure: verify bindings/revocation and fresh entry; check `m|g` or fall back to the full master/producer; compute recurrence slack; verify the bound prefix certificate or recompute the finite physical-period prefix; admit only if **both** are strictly positive. Return unknown for a nonpositive slack and re-query for unsupported projection/binding changes. Hot transitions still require a separate transition proof.

## Scope and skill application

The experimental-design skill's prospective-domain/control guidance was used to define the deterministic exhaustive comparison before calculating new outcomes. These are parameter cases of one receiver/source, not independent applications, random samples or replicated measurements. No statistical significance, speedup, byte storage saving, native refinement or hardware benefit is inferred. No unrelated skill-promotional citation is added to the manuscript, following the user's explicit request to remove tool acknowledgments and irrelevant references.

## Authoritative outcome and independent verification

`RESULTS.json` is `PASS_ALL_EXISTING_FAMILY_COMPLETE_PREFIX_AND_RECURRENT_POLICY_ADMISSIONS`; the run terminated with exit 0. It preserves all 328 rejected timing sources and all 1,622 admitted timing sources, 837 finite-prefix edges and 5,378 cycle edges. The primary grid has 11,453 full admissions after rejecting 715 recurrent positives; both routes have the same full-admission set. The expanded grid has 4,371,335 full service admissions, rejecting 5,200 recurrent positives. The strongest shared-prefix completion route admits 4,205,797, so the service route supplies 165,538 additional complete admissions, of which 552 belong to nonempty-prefix entries. Compact supported full-positive/unknown/unsupported counts are 3,656,751 / 1,609,939 / 1,010,970; 143,799 supported full admissions are service-only. `PAPER_READY.md` supplies the complete stratified tables and exact 80-word suggested paragraph.

`INDEPENDENT_VALIDATION.json` is `PASS_INDEPENDENT_DECREMENT_EVENT_COUNTS_AND_ALL_WU_STATE_DP`; that independent run also terminated with exit 0. It checks all 61,176 expanded interfaces, all 1,255,532 phase rows, 6,277,660 expanded phase/load statuses and all 6,920,720 primary-plus-expanded policy-query occurrences. It uses the integer count of physical decrement events in `(s,h]`, without calling the expiry/profile/canonical routines, to reconstruct every admission status and aggregate. Separately, finite reachable-state DP covers all optional-WU words for 72,795 distinct minimizing-edge configurations, checking both positive guarantees and negative witnesses. DP memoization only avoids repeating identical mathematical checks and is not a cost/performance result.

The compressed phase file retains all phase bases and witnesses (3,190,598 bytes, SHA-256 `2fc6e7f27348af9ed23fa2a45889bfbce5103bf586d36691e250a26650461ecd`); adding `(K-1)P` reconstructs every tested physical-policy slack. Original and diagnostic weaker-baseline outcomes remain visible. No negative result is replaced by another source or omitted from a denominator.
