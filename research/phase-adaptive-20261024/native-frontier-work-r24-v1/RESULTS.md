# R24 retrospective native normalization and tolerance exploration

Original R23 manuscript, publication, candidates and deployment policies remain frozen. This is author-side retrospective analysis. Suppression remains the six R23 post-selection ablations, never an original selectable policy. Nine new runs of a retrospectively identified zero-tolerance policy are explicitly posthoc transfer diagnostics on inputs previously seen under other policies.

## What the producer actually executes

The immutable public C source sets `STORES=ceil(N*N/8)*64`; the producer uses a finite `for(t=0;t<STORES;t++)` loop with one relaxed atomic frame store per iteration. There is no early-stop or time-driven termination. For PATTERN1, index=t mod N²: every studied N² is divisible by8, and the stream traverses the entire frame eight times. Consequently each64-byte line receives64 explicit8-byte frame stores. Each store refreshes `value(index)`, the same value used at initialization; it is not necessarily a changed payload.

All four workers cross a first start barrier, reader0 emits marker0, and all workers cross a second start barrier before entering their producer/consumer paths. The writer cannot enter its loop before marker0/reset. Marker99 follows all pthread joins, so the whole producer loop is inside the WU measurement ROI. This order is verified in the exact ELF: writer second barrier at0x40205c precedes its branch to0x402216; reader0 marker0 call0x4022e1 precedes its second barrier0x4022eb; the sole frame store is0x402291 and the loop compares against STORES at0x4022c0. Source/ELF hashes and retained disassembly bind this claim.

All72 retained run stdout records confirm the formula and checksum: N16=2048, N32=8192, N36=10368, N40=12800 explicit producer frame stores. Retrieved committed per-core counters are different quantities: CPU3 `numStoreInsts` is exactly the frame-loop count plus44 in every one of72 runs. Those extra committed stores are not relabeled producer data writes. Per-core counters reconcile to total committed instructions and load+store memory references; four cumulative CPU epochs reconcile exactly.

NORMALIZED.csv reports whole-system accepted WU per explicit producer frame store over this common ROI. It does not attribute all accepted WU to frame addresses or CPU3, nor isolate polling work. CPU_EPOCHS.csv preserves per-core instructions, loads, stores and memory references. Exact polling-PC or address-attributed WU analysis needs a PC/address-tagged event trace or dedicated counters in a separately bound instrumented binary. No such instrumentation or rebuild was performed.

For32KiB/N32/phi0, fixed/phase/suppression have totalWU2139/1941/505 and WU/frame-store0.2611083984/0.2369384766/0.0616455078. All three have CPU3 committed store counter8236 and CPU3 committed instructions426256. Epoch-specific instruction distribution can still vary. This normalized traffic comparison retains the whole future-timeout intervention/scheduling interpretation from R23; it is not a pure-TTL causal estimate.

## Tolerance robustness

TRAINING_FRONTIER.csv contains all255 fixed and24 nonconstant phase candidates per cache, aggregated by each candidate's own maxJ and maxWU over the three declared offsets, plus the one matching suppression schedule as a post-selection diagnostic. These aggregates are robust-objective coordinates, not a claim that J and WU were jointly observed at the same maximizing offset. TOLERANCE_KEY_TABLE.csv recomputes the unchanged objective at0/0.05/0.1/0.2/0.5 percent. TOLERANCE_STEPS.csv retains every winner-changing interval through0.5percent using exact rational breakpoints. Its cap and eligible counts are evaluated at the interval's inclusive left boundary; candidate counts can change within an interval without changing its winner. The final upper endpoint0.5 is included.

| cache | tolerance | best eligible fixed K / WU | best eligible phase K / WU | suppression eligible |
|---|---:|---|---|---|
|32KiB|0%|253 /660|128,16,1 /582|no|
|32KiB|0.05%|253 /660|1,128,1 /550|no|
|32KiB|0.1%|3 /638|1,128,1 /550|no|
|32KiB|0.2%|3 /638|1,128,1 /550|no|
|32KiB|0.5%|1 /197|128,1,1 /232|yes:WU196|
|64KiB|0%|253 /665|none|no|
|64KiB|0.05%|253 /665|none|no|
|64KiB|0.1%|106 /663|none|no|
|64KiB|0.2%|106 /663|1,128,1 /553|no|
|64KiB|0.5%|1 /197|16,1,1 /228|yes:WU195|

At32KiB zero tolerance, phase(128,16,1) has maxJ477672 and maxWU582, versus fastest-fixed477727/660:11.818% lower maxWU without positive measured maxJ slack. This is retrospective evidence of a family-level advantage at zero slack, not proof that the originally deployed vector is zero-slack eligible. The originally selected phase(1,128,1) becomes eligible at0.01695529036%. Phase remains the preferred original family through tolerances below0.29389169965%; fixedK2 then wins on maxWU208, and fixedK1 starts at0.34894406219%. Suppression first fits at0.35375852736% and has lowerWU196 than fixed197. Thus the traffic-first preference changes at loose tolerances; phase is not uniformly best.

At64KiB no phase is eligible at the original0.1% cap; the first phase becomes eligible at0.11454030176%. Suppression fits at0.36257058757%. The original deployment remains fixed106 regardless of these retrospective alternatives. Tolerance is an empirical QoS exploration, not an application deadline, task admission certificate or WCET guarantee.

## Nine new posthoc transfer diagnostics

Policy(128,16,1), selected by the retrospective zero-tolerance N16 exploration, was frozen in TRANSFER_PROTOCOL.json before these nine runs. The existing immutable binary/config/ELF were reused; no rebuild, retuning or process stop occurred. All9 runs pass checksum, marker, terminal and invariant checks; all36 epochs reconcile. Inputs N32/36/40 were previously evaluated under other policies, so these are not sealed heldout tests.

| N | new phase maxJ / maxWU | frozen fixed maxJ / maxWU |
|---:|---:|---:|
|32|2233331 /2059|2233539 /2158|
|36|2880129 /2546|2879881 /2705|
|40|3600187 /3104|3600441 /3253|

Against same-offset frozen fixedK3, new phase is faster in2/9 cases and slower in7/9, spanning−254..+2578cycles. Against frozen-fastestK253 it is slower in all9, by302..3656cycles. WU is lower in all9 against both comparators. POSTHOC_TRANSFER.csv and POSTHOC_TRANSFER_EPOCHS.csv retain every signed result. Zero-slack training advantage does not imply uniformly faster transfer.
