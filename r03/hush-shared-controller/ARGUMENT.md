# Bounded shared-response producer and complete admission

This is a new, fully specified digital controller, not an implementation claim for native HUSH or arbitrary-payload coherence. `PROTOCOL.json` was saved before source extraction or policy outcomes. The domain remains all 40 predeclared cases, including all failures and cases where ready-off phases do not intersect cache boundaries. No case was replaced. The source/control and analysis programs perform no remote operations or native timing measurements.

## State and within-tick semantics

Two clients address fixed, distinct zero-byte lines with tags 64 and 128. Each has at most one pending request. They use intervals `qA=2p+1`, `qB=3p+1`, starting polls 0 and `b`, respectively. A send schedules its next poll `q` ticks later. If that poll encounters a pending request, it clears the scheduled event and sets a wait bit. A response clears pending; if waiting, it schedules a new poll `q` ticks after the response; otherwise it retains the previously scheduled poll. Poll precedes response callback, resolving same-tick ties explicitly.

The controller has one shared FIFO of capacity two, one-slot capture register R0, one-slot response register R1, and one grant opportunity per `p` ticks. FIFO order resolves simultaneous enqueue A before B. Grant tests **tick-entry** R0 occupancy. The response sink is ready iff `t mod r != 1`, with predeclared `r` 3 or 5. The exact tick order is:

| Stage | Transition |
|---:|---|
| 1 | Optional valid-only zero-byte WU independently on each line. No WU for a line before its guaranteed initial successful grant/capture. |
| 2 | Enabled counters decrement at physical phase `t mod P=phi`; zero invalidates/disables. |
| 3 | Scheduled source polls run A then B; a free source enqueues one request and a pending source sets wait. |
| 4 | At a `p` boundary, grant the FIFO head iff R0 was empty at tick entry. Read the tag, capture immutable `(client,request identity,zero byte)` into R0, and cancel that line's counter. |
| 5 | At a boundary, emit old R1 iff ready, otherwise retain it. |
| 6 | At a boundary, transfer R0 to R1 iff R1 is empty. No overwrite or double emission is allowed. |
| 7 | Run the emitted response callback, updating pending/wait/poll state. |

Moving stage 6 to every tick is behaviorally equivalent here: a nonempty R0 always has a nonempty R1 after the previous boundary, and R1 can only empty at a boundary. The implementation fixes the boundary version. No tag miss is repaired: candidate execution halts at its first failed tag-read attempt, which is the observation the certificate excludes.

## Bounded queue and snapshot invariant

For each client, exactly one of the following holds: no pending request and no live token; or pending with exactly one token in the FIFO, R0, or R1. An enqueue changes the first state to a FIFO token. A grant moves that token to R0, transfer moves it to R1, and emission/callback consumes it. A pending client cannot enqueue another token. Every transition preserves the invariant, so total live tokens and FIFO occupancy are at most two. R0/R1 hold their immutable snapshots whenever blocked; an in-flight response is therefore independent of later counter expiry or zero-byte WUs. Tags are distinct and fixed, so line ownership is unambiguous.

The finite identity quotient replaces the concrete fresh request identity by its client label. No identity can alias another live request from the same client because of the one-pending invariant. All guards and callbacks use token ownership/equality, never numeric ID arithmetic. Thus consistent renaming of fresh request identities preserves the transition and every observation; this is not an assertion about an unmodeled finite-width native ID implementation.

The controller has grant-stage sharing and a shared response pipeline, but only **one outstanding request per client**. It is not a multi-outstanding client model. With two total live tokens, R0 and R1 both occupied imply an empty FIFO. Accordingly the specific counter `grant_blocked_R0_with_queue` is zero throughout: the evidence for sharing is FIFO contention and one-grant arbitration, while response backpressure stalls actually exercise occupied response storage. No stronger queue-saturation behavior is inferred.

## Exact finite control key and recurrence

At the beginning of tick `t`, the key is `(t mod lcm(p,r), scheduled-poll delays or None, pending bits, wait bits, FIFO client order, R0 client-or-empty, R1 client-or-empty)`. Poll delays are bounded by the source intervals; wait implies a pending request and no scheduled poll. Queue/register state is bounded by the invariant above. A conservative finite key-space bound is `lcm(p,r)*(qA+2)*(qB+2)*3^2*5*3^2`; conservation makes most of this bound unreachable.

Two equal keys have identical boundary/ready conditions, source guards, queue order, snapshot ownership and next poll times relative to the current tick. Applying the same WU input to both states preserves the same counter-independent control transition and consistently renamed observations **provided no failed tag read has yet occurred**. The all-hit producer has no counter state and therefore evolves deterministically on this key. A first repeat at times `a<b` establishes an exact translated infinite continuation of period `d=b-a`, not an approximate trace fit. `d` is a multiple of `lcm(p,r)`.

A per-case cap of one million ticks was prospectively fixed; all forty sources repeat before the cap. For every case, the extractor continues two more cycles and checks complete service and response event sequences under translation. For each client, a triple `(s,c,h)` records grant/capture `s`, its matching response emission `c`, and its next same-client grant `h`. These may cross a cycle boundary; the extra continuation closes them before export. Edges with `s<a` form the finite prefix, and `a<=s<b` form one recurrent block. There is no dropped cross-boundary edge.

An independent implementation with different dict-based source/stage state, no imports from the extraction/profile/expiry code, reproduces every recorded tick and key, the first repeat, all 80 per-line prefix/cycle relations, and all 40 trace digests.

## Candidate-policy independence and all-WU composition

Each line's validity contract begins **immediately after its guaranteed initial successful tag read/capture**. It does not begin at the start of an arbitrary tick. That cutpoint cancels any arm; the specified initialization forbids earlier WUs for that line. Thereafter, independently optional zero-byte WUs can arm its dedicated counter, but cannot alter arbitration, FIFO eligibility, sink readiness, source scheduling, response ownership or the immutable snapshots. There are no other invalidations, revocations, evictions, memory/refill paths, watchdogs or payload changes in the model.

For physical policy `(K,P,phi)`, put `B=(K-1)P` and `F(x)=x+((phi-x) mod P)+B`. A WU at tick `x` loads K before that tick's decrement; F is exactly its expiry tick if not canceled/rearmed. F is nondecreasing in x. A successful grant at s cancels the line timer including a same-tick WU. Hence every later arm before the next same-line grant h has `x>=s+1`, and rearming cannot advance expiry before `F(s+1)`.

Suppose every actual prefix and translated recurrent edge has `F(s+1)>h`. From each guaranteed initial cutpoint, assume a first failed grant. All earlier grants succeeded, so key/ownership closure gives precisely the all-hit producer's prefix/cycle edge from that line's previous service s to this attempted service h. No alternative failure cause is admitted. Any WUs on either line preserve control up to this point, and every WU on the failed line expires strictly after h by monotonicity; no WU leaves it disabled. This contradicts a first failure. Thus strict positive complete slack proves all subsequent tag reads succeed for **every** independent two-line optional-WU word, under the stated bindings.

Conversely, if complete exact slack is nonpositive, take its minimizing physical edge. Use no earlier WUs on either line, one WU on the edge's line at `s+1`, and no other WUs. All earlier reads hit. Its immutable captured response and the other line preserve the schedule through the next same-line attempt h, but the literal counter expires before or at h, yielding the first failed tag read at h. This witnesses necessity for this explicitly specified controller and input alphabet. It does not claim sharpness of an arbitrary upstream overapproximation.

Every one of the 19,613 nonpositive policy queries has such a retained independent control/counter replay, not merely a sampled counterexample. The independent program checks the actual scheduled service attempts in `[s,h]` are exactly s and h for the target line, decrements a literal enabled counter tick by tick, and records its first failure at h. For positive policies, minimum-edge one-WU survivals corroborate the formula; arbitrary-WU completeness follows from the proof above, not from treating those tests as exhaustive input words.

## Full policy slack and fair completion observer

For each line j, use the exact exported finite prefix `Tpre_j`, recurrence `Tj` and common translation d. Let `m=gcd(P,d)` and `Qjm` be the canonical service/span profile from Tj at modulus m. The exact prefix, including both lines and physical P, is

`Epre=min_{j,(s,c,h) in Tpre_j} [s+1+((phi-s-1) mod P)+B-h]`, or infinity for an empty combined prefix.

The exact recurrence is

`Erec=B+1+min_{j,(r,nu) in Qjm} [((phi-r-1) mod m)-nu]`.

The complete service result is `Efull=min(Epre,Erec)`, admitting iff strictly positive. The gcd changes only the recurrent remainder; it does not replace physical P in B or the prefix.

For the strong baseline, retain line identity. Separately compute tight recurrent `Jj=max(c-s)`, `Aj=max(h-c)` and actual `Cj={c:(s,c,h) in Tj}` for each line. Its recurrence is

`Drec=B+1+min_j [-Jj-Aj+min_{c in Cj} ((phi+Jj-1-c) mod m)]`.

Use **the identical exact Epre** in `Dfull=min(Epre,Drec)`. Thus gains cannot arise from a worse prefix check or forgetting which line generated a completion. They measure precisely the loss of the per-line `(C,J,A)` abstraction. A richer completion-indexed relation is outside this comparator.

For every physical phase, the analysis checks the recurrence profile against explicit orbit copies `n=0..P/m-1`, retains the minimum edge, and runs five literal counter loads. A separate program reconstructs all 37,000 policy statuses using only periodic decrement counts `(h-phi)//P-(s-phi)//P`. It reconstructs the completion baseline as virtual intervals from `c-Jj` through `c+Aj`, plus the same real prefix, without importing expiry/profile routines.

## Reusable records and scope

Per-line records bind the fixed address/tag/epoch, guaranteed initial service/capture cutpoint and no-earlier-WU condition, source poll parameters and entry, queue/register capacities, arbitration, ready pattern, tick order, controller/source digests, initial finite state, relation/prefix digests, recurrence d, stored modulus/pairs, and policy-specific exact prefix result. The shared record also binds both line ownerships and the same common clock. Any real cache would additionally have to prove all-hit control refinement, absence or modeled effect of evictions/revocations/memory paths, data semantics, and relevant finite-ID/horizon rules; none is silently discharged by this controller.

For a predeclared all-query portfolio `P=1..4p`, choose `g*=lcm_{P in portfolio} gcd(P,d)` **before evaluating outcomes**. Every target m divides g*, so both line payloads support every portfolio query by divisor projection; finite prefixes still use their original physical-period edges. This reduces the summed line-record pair count 961 to 765 while retaining all 37,000 queries. It is pair storage for this producer, not a minimum encoded byte count or hardware cache reduction.

The separately declared posthoc diagnostic `g=d/gcd(d,3)` stores 636 pairs but leaves 7,425 queries unsupported; its 333 supported extra admissions must not be confused with the full/prospective 439. All full d masters retain 961 pairs. There is no universal full-master pruning claim.

## Exact outcomes, adverse cases and cost boundaries

All 40 sources close; detection uses 9,549 total ticks/unique keys, with a maximum of 575 per source. The 22,823 independently matched validation ticks include the two additional translation checks. The export contains 416 prefix triples and 961 recurrent triples across 80 line records. Every source reaches FIFO occupancy two; 26/40 actually stall an occupied R1 at a ready-off boundary. The other 14 cases are retained and have no such stall because p is a multiple of r. There is no fabricated backpressure evidence for those cases.

The 37,000 policy queries contain 17,387 complete service admissions and 19,613 unknowns. The line-aware strongest completion baseline admits 16,948. The 439 additional admissions are 1.186% of all queries and 2.590% relative to baseline admissions. They arise in 27/40 sources; 13 sources have zero gain. No recurrent positive is removed by a prefix in this new family, although all 416 prefix edges were checked. These correlated parameter queries are not independent application measurements.

The analysis visits 720 controller/period interfaces (1,440 line interfaces), 17,284 stored-master projection input pairs, 1,758 projected canonical pairs and 7,632 finite-prefix edges when counted once per controller/period interface. These are operation/input counts from this exact analysis, not wallclock performance, a cache speedup, or a break-even claim. The pipeline includes finite-state extraction, source/record bindings, full prefix certification, gcd/support, projection, lookup and explicit unsupported fallback. An implementation can cache results across K and repeated m; no native complete-tuner timing comparison was run, so this study does not establish an end-to-end acceleration.
