# R06 matched four-line calendar records: prospective protocol

Status: fixed before record generation, arithmetic search, query validation or
new timing. Date: 2026-10-23. Producer owns this directory only. Frozen R04/R05,
manuscripts, reviews and public releases remain untouched. No remote execution,
native HUSH/gem5, coherence, PPA, WCET or application inference is authorized.
No new performance collection in this correctness stage. Preserve every failed
attempt, source version and log. No optimized-Python or security-hardening claim.

## Input and trust contract

Use the twelve actual independently validated R05 calendar controllers, four
lines each, full normalized state key, physical cycle entry, literal prefix and
crossers, strict initial-capture cutpoints, and exact source width guards.
Freeze the prospective parent plan, R05 receiver/driver/protocol/amendments,
producer and independent relations/tuning, independent arithmetic/facts, and
control stream hashes before parsing. The preparation manifest binds bytes.
Producer and independent complete relations must agree. Bind the original
control trace too; do not rerun it. The full-key entry37/repeat93 controller is
separate from the original empty-frame FAILED_UNKNOWN case and its original
6496 unknown grid policies. No omitted prehistory is executed here.

Four bindings in every record: source = receiver+driver+protocol/amendment
manifest digest; receiver = receiver source digest; relation = complete case
relation canonical JSON digest; epoch = fixed source and schedule/initial-state
contract digest. A trusted external registry, built from frozen expected inputs
and independently checked by a consumer, supplies expected bindings and exact
metadata. An untrusted record digest or a matching forged registry cannot
authenticate source validity. This is explicit external trust, not self-auth.

## Prospective mathematical bound, before any new search

For positive integers K,P and 0<=phi<P, E(s+1)=s+1+((phi-s-1) mod P)+(K-1)P.
For a given observer the integer total slack is (K-1)P+1+Hmin, including the
same exact physical literal prefix for both observers. Strict admission means
slack>=1. Therefore Kmin=1+ceil(max(0,-Hmin)/P). Verify independently against
direct K enumeration, especially Hmin=0,-1 and multiples of P; no zero slack
is admitted. Physical B=h-s is never reduced when residue modulus changes.

Given an admitted witness R0=K0*P0-1, every strictly better policy has KP<=R0,
and every tie has KP<=R0+1. Positive K implies P<=R0+1. Enumerate every P in
that finite range and all phi, using its minimum admissible K (or every K
inside the product bound); this is an exact global objective/tie check for
the explicitly declared domain. First reproduce the immutable old grid's
all optima and all ties, including its boundary and infeasible nested K<=5.

Pre-result root conjecture to independently verify: E(s+1)<=s+KP. Exact
service positivity implies KP-1>=max(h-s), over cycle AND physical prefix.
At P=1,K=1+that maximum, equality is admitted if source guards allow K.
Completion D<=KP-J-A implies combined lower bound
max(max_j(Jj+Aj), max_prefix(h-s)); P=1 attains it if legal. This is elementary
proxy degeneracy, not a new optimization algorithm. Report three domains:
(a) original K<=16,P<=4p;
(b) mathematical fixed K<=16, arbitrary positive P, finite product-bound exact;
(c) no design K cap, subject to K<=65535, P<=68 and actual source guards.
Also report the source-guard subset K<=16,P<=68 separately from (b).
Any b witness with P>68 is arithmetic only and illegal for this receiver.
No RTL execution claim applies to new policy arithmetic. All ties mean the
declared finite objective/product-bound search, not all possible policies.

## Portfolio and exact profile contract

For each fixed controller prospectively choose natural timer divider settings
{p,2p,3p,4p}. This is a declared design portfolio, not an observed distribution,
compression-selected set or application optimum. Let m_i=gcd(P_i,d), and
g*=lcm_i m_i. Store full raw pairs (s mod d,h-s), grouped pairs (largest
physical B at each residue), canonical master at d, and canonical portfolio
at g*. Canonical kernel H_g(q)=min_(r,B)((q-r-1) mod g)-B. Canonical pairs
are exactly the strict resets ((q-1) mod g,-H_g(q)) for
H_g(q)<H_g(q-1)+1. Independently check this inverse and every divisor target.
Projection groups/canonicalizes modulo m_i; query adds 1+(K-1)P and literal
physical prefix min E(s+1)-h. Do not inherit an old positive admission bit.
Include complete retained raw relation and dense g* H alternatives.
Every larger/no-save/zero-saving result remains in the tables. No byte-minimal,
arbitrary encoding optimum or hardware-memory claim.

## Schema fixed before encoding (HUCALR06 version 1, proof version 1)

All integers little endian. Header: 8-byte magic HUCALR06, uint32 schema,
uint32 proof, uint32 format, uint32 canonical metadata UTF8 byte length,
then metadata bytes, then uint32 line count (exactly four). Each line has
uint32 owner, uint32 stored modulus, uint32 element count. Formats:
0 full raw (uint32 residue,uint32 physical span) pairs;
1 grouped master same pairs; 2 canonical master same pairs;
3 canonical portfolio same pairs; 4 retained raw (uint32 s,c,h) triples;
5 dense portfolio int32 H values (count=g*).
Each format has byte-identical metadata and equal fixed header/line-header
overhead. Metadata includes the four bindings, case p/r/F/d, full entry state,
complete normalized key, ID translation, epoch/producer/proof identifiers,
initialization/capture/WU guards, all four line IDs, J/A/C0, full literal
prefix triples including crossing flags, entry/repeat and original gate.
Triple/profile values are nonnegative uint32 except signed dense H. Strict
integer source guards: K1..65535, P1..68, phi<P; ticks/IDs<2^31;
4 lines/tags, FIFO8, 16-bit phases/counters, 8-bit bytes; p/r/F exactly
one expected controller. The arithmetic b-domain is explicitly wider in P.

Parser rejects wrong magic/version/proof/format, truncation/trailing bytes,
invalid counts, illegal moduli/residue/domain, wrong/duplicate/out-of-order
line IDs, incompatible J/A/cutpoints/entry/full state/key/epoch, stale binding,
malformed prefix/crossers, nongrouped or noncanonical pairs as applicable,
wrong physical B or mismatched expected profile, and unsupported target m
which does not divide stored g. Reject K/P/phi beyond source guards in the
portable receiver-query API. No assert-only safety claim: use explicit errors
for parser conditions, normal Python only.

Prospective negative controls: each header/version/proof/format/count/binding
class; each line ID and stored modulus; prefix/cutpoint/entry metadata changes;
rebound epoch; altered span; duplicate/noncanonical pairs; truncation/trailing;
unsupported target modulus; K=0/65536,P=0/69,phi=P; and zero slack remains
rejected. Recomputed untrusted digest cannot defeat trusted expected registry.
Include matching-forged-registry acceptance as an external-trust limitation.

## Correctness outputs, no timing yet

Validate all twelve times four line records and all portfolio P/phi/K1..16
queries against raw physical cycle lifts and literal prefix. All six formats
must agree. Independently formulated arithmetic checks use ceiling-decrement
count rather than producer min-convolution. Verify Kmin exhaustive small
integer grid, both observers, all old-grid records/ties, and bounded new
domain optima/ties. Preserve old original K<=5 empties and unknown gate.
Write absolute optima, representative K/P/phi, all ties, absolute and relative
increment, admission denominators, query checks/digests, complete record bytes,
and a changed-period example with actual physical prefix and cycle numbers.

## Prospective matched workflow cost plan (source only, collection deferred)

Same twelve controllers and frozen input visibility. Methods: retained raw
relation scan; grouped/master extraction then projection; canonical portfolio
projection plus reset query; dense build/lookup. Every cold workflow includes
identical frozen source acquisition, parse, binding validation, prefix setup,
required representation build, all queries, result hashing and cleanup.
Warm reuse boundary: parsed, source-validated prepared representation retained;
queries still include target projection/reset as required, exact physical
prefix, admission, result hashing and cleanup. Report both precompute and
reuse costs, never hide extraction/reset. Reuse Q per controller is fixed
at 1,4,16,64,256; Q is count of complete portfolio sweeps (all phi,K1..16),
not cherry-picked favorable phase queries. One untimed warmup then exactly
nine paired blocks, order shuffled by Python Random seed 2026102306, fixed
before first collection. Do not rerun based on ranking or modify inputs/order.
Expected semantic hashes for every method/Q are verified and frozen before
first timing. Root coordinates a short ordinary-Windows collection only after
an independent correctness gate and CPU-heavy synthesis ends. No isolated-host
or generic speedup claim. No old timings touched or rerun.
