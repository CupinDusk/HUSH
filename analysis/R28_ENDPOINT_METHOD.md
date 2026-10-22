# Complete specified endpoint: results and limits

Protocol and manual refinement argument were saved before implementation
or execution. The input is new own C++ endpoint code plus the same five
byte-exact public MemTest function definitions already pinned in v8.
No historical private cache overlay or response-target stub is compiled.
The client environment still declares packet/RNG/clock/event plumbing.

The new component has one countdown, one readable preloaded byte/tag64,
two response registers and dedicated WU/response lanes. Its code has no
scheduled response deadline. A read latches register0; cache boundary a
moves it to register1; boundary a+p emits it. This proves c(s) from actual
register transitions and establishes a WU-independent enclosure for this
endpoint. The timer loop directly refines F(r), with WU before decrement
and hit cancellation last. This is a logical component implementation
and a manual refinement argument, not native gem5 or physical RTL timing.

Source-coupled safe executions:7500 per policy,15000 total. Each policy
uses all4096 repeated twelve-bit WU words and3404 distinct zero/one/two-WU
subsets of ticks5..86. Empty schedules overlap between those two families;
the execution count is not a count of independent or unique workloads.
The actual five MemTest bodies accept135000 reads and complete120000
callbacks; a ninth accepted snapshot per execution is pending at cleanup.
Services/receipts/waiting polls match the independent recurrence exactly.
Callbacks are emitted by the endpoint, not analytically placed events.
The public MemTest request constructor fixes a one-byte access.

The actual endpoint transition is explored under both WU bits at every
reachable state, quotienting time by lcm(81,P) and fresh service IDs by
the four nonoverlapping service phases. Old K2/P27/phase6 gives184 states,
368 edges; new K3/P18/phase2 gives415 states,830 edges. All1198 edges are
replayed independently using an absolute-deadline timer interpretation,
checked against every saved state and both WU successors. No expiration
or failed read occurs. Data-independent control is established by code
dependency/proof; byte-snapshot preservation under changing WU values is
also checked explicitly. Infinite WU behavior relies on the refinement/
first-failure/finite-state arguments, not the finite word sample alone.

The same retained g27 pairs yield old slack12 and new slack4. Both use
fresh runtime entry; this is offline policy re-query plus separately
admitted installation, not a safe hot change of an old runtime token.
Clock,epoch,lane-coupling,revoked,horizon,invalid-entry and hot-transition
controls all reject. An executed unsafe K2/P18/phase2 case with WU38
expires56 and rejects read70. An invalid-preload execution rejects read5.
These diagnostic executions do not pass the entry/admission guard.

Generated C++ SHA-256:
5ea81e9b3a9b7a8380b29b926330231d6b8c430a1b8d6e554f4746dd371df2d3.
All coupled records SHA-256:
2c620809fbafe1d965384cdab22deff03150d39b27612fcbc110dbbe00685a01.
All BFS states/edges SHA-256:
11c30c3fbd04520cfe665e377c71a533c1b1eafa69e0ac08eae933c4f269d784.
These generated records are regenerated, not all bundled. Compiled binary
hash is path/toolchain dependent and is retained separately in each run.

The claims cover this specified component and its declared dedicated
capacities, no-other-cause/revocation handling, one-outstanding source and
no-overflow horizon. There is no native historical HUSH/cache conformance,
hardware delay/area/power result, global data coherence, new GPU evidence,
deployment advantage or second independent client-program claim.
