# Native feature work and conservative retention connection

Author-side source/mathematical audit, 2026-10-24. No native execution, source
changes, paper edits, server calls or reviewer agents. Derived counts do not
assert that an N32 native experiment was executed; the local protocol amendment
defers N32 and prioritizes N28.

## Real feature-work counts

The inspected source is the existing `fir_pipeline_v3.c`. Local Windows-byte SHA
is4d093a2397216e2ead4c9a25ec9601f3cd57d333fb213fe496859ec2a87e8917;
normalizing only CRLF to LF gives the remote source binding
ba5235c13df956dd5c02de195de169271738d4176c1dd09a98951c25d263042c.
The feature launch retains native binary SHA
2240805a3edaceb2741e7b0285f9dd1cdd07188395705322a8ca088206300096.
The driver changes its existing LAGS argument; it does not recompile or modify
the FIR/feature binary. The new sensitivity therefore changes a real algorithm
parameter, rather than inserting a delay loop.

For N by N input, let M=(N-2)^2 be the number of valid filtered outputs and
ell=min(LAGS,M-1). Each consumer executes9M FIR tap accumulations, M normalization
divisions, and

    A(N,LAGS) = sum_{lag=1}^{ell}(M-lag)
              = ell*M - ell*(ell+1)/2

autocorrelation product/accumulation iterations. Each autocorrelation iteration
reads two normalized elements at source level and adds their product to the
feature result. Each source FIR tap has two weight multiplications and one
accumulation; optimizing compilation can simplify them. These are executed
algorithmic loop counts, not claims about retired instructions, cache requests,
cycle counts or a compute WCET.

| N | Outputs/normalization divisions M | FIR taps9M | Autocorrelation pairs L1 | L16 | L64 |
| ---: | ---: | ---: | ---: | ---: | ---: |
|16|196|1764|195|3000|10464|
|28|676|6084|675|10680|41184|
|32|900|8100|899|14264|55520|

All counts are per reader; there are three readers. Shared frame reads per
reader are N^2 validation reads +9M FIR reads +one calibration read:2021,6869,
9125 respectively. The normalization and autocorrelation arrays are private;
their actual allocation, instruction/data cache interference and computation
remain part of the native program. The producer's existing fixed GAP4 loop is
unchanged; increasing LAGS adds no producer delay or new padding.

The serial reference before ROI also calls the same feature function, so its
pre-ROI work changes with LAGS. Comparisons pair fixed/phase policies at the
same LAGS and common binary, preserving that initialization condition. This is
a real-work sensitivity across algorithm parameters, rather than a claim that
only one isolated machine-level cost changes. `WORK_COUNTS.json` contains all
nine derived rows, source/binary bindings and independently computed integer
reference checksums.

## Retention-only domination lemma

Let P be fixed, K in1..254, T=KP, and use a common time unit. A quantized timer
armed at r has expiry

    F_K(r) = r + delta + (K-1)P,
    delta = (phi-r) mod P.

For integer-cycle arms,0<=delta<=P-1. Hence

    r + R_K <= F_K(r) <= r+KP-1 < r+T,
    R_K=(K-1)P.

Thus continuous expiry E_T(r)=r+T never expires earlier than the corresponding
quantized arm, for every tick phase. In a real-time formulation delta is in
[0,P), yielding the same strict upper inequality without an integer one-cycle
gap. This is an expiry-function order, not equality of timer states or execution
traces.

For a receiver with prospective phase updates that do not retime existing arms,
this order supports the same conservative temporal lower-bound recurrence:
capture establishes a validity guarantee, elapsed bounded work decreases it,
and a phase boundary caps it by the new R_K. Every old arm retains its old
bound; every future arm has at least the new retention guarantee. Taking the
minimum covers both. The argument is made on the actual event times and does
not assume that continuous and quantized systems have identical traffic or
execution timing.

Transferring a complete rho-based access/budget result additionally requires:

1. The same accepted-WU, valid-only rearm, capture/cancellation and phase-update
   ordering premises; no unmodeled invalidation/reset shortens the guarantee.
2. An independently valid residency argument for every allocating reference,
   including any instruction, stack, private-data or dirty replacement effects
   in the native cache organization.
3. Independent read-service, compute/private-access and controller upper bounds
   for the native architecture; these bound the elapsed intervals subtracted
   from rho and the costs in W.

Only the first timing-function comparison is established here. The four-core
native unified caches do not inherit the two-client Lm71 service contract or
the clean shared-partition residency proof merely because the expiry order
holds. In particular this lemma does not establish native WCET, a native safe-hit
classification, queue/liveness correctness or exact quantized-RTL equivalence.

## Selected native plans and encoding domain

With P=8, both selected native plans have finite exact nominal-load mappings:

| Native T sequence | K sequence | R_K sequence |
| --- | --- | --- |
|512,512,64|64,64,8|504,504,56|
|512,512,8|64,64,1|504,504,0|

The K1 final phase has zero unknown-phase quantized retention lower bound even
though the native continuous timer retains for eight cycles; the mapping is
deliberately conservative. No equality of actual expiry instants is claimed.

The full continuous native sweep8..65536 is not an exact fixed-P realization of
the finite eight-bit load domain. Representing the minimum8 requires P<=8,
while the largest finite load254 would then represent at most2032, not65536.
At P8,4096/65536 would require K512/8192. Encoding255 denotes actual disabled
expiry, and must not be reused as a finite K255 or treated as finite65536.
Conservative coarsening of larger native values is mathematically possible,
but is not the same candidate grid and has not been used to infer native WCET.

## Check coverage

`derive_work_and_retention.py` enumerates all254 finite loads, periods1..255 and
every distinct relative offset delta=0..P-1:8,290,560 checks, zero failures.
Every (phi,r modP) pair maps to one of these offsets, and arm-time translation
cancels. This finite check supports the elementary algebra; it is not a protocol
model check. The smallest continuous-minus-quantized gap is one cycle and the
largest255 cycles in the integer enumeration. Results are retained in
`RETENTION_INEQUALITY_CHECK.json`.
