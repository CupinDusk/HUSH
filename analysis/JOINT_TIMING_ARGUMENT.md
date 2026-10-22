# Joint timing witnesses and mixed polling

This is a secondary mathematical argument, after the first mixed-source run. It is not an external preregistration, native cache validation or a new performance experiment. The fixed event order is WU, decrement, read/cancel. Earlier PDFs and negative results remain unchanged.

## Receiver and selected observation

Let all times be integer ticks. A successful service at s cancels any arm at or before s, including a same-tick WU. A subsequent arm that can affect the next decision h therefore has r >= s+1. For load K>=1, period P>=1, phase phi, with WU before decrement,

    F(r) = r + ((phi-r) mod P) + (K-1)P.

F is nondecreasing. A still-valid WU rearms but cannot resurrect an invalid line. No WU means no timer expiry; rearming cannot cause expiry before F(s+1). With no other invalidation, replacement, maintenance or epoch change, F(s+1)>h guarantees the next hit against timer expiry. If F(s+1)<=h and a WU at s+1 is admitted, that one WU demonstrates sharpness. Expiry at h precedes the read, so the inequality is strict. These are receiver premises, not properties implemented by the public cache used for the timing argument.

For a nonempty finite timed relation T of triples (s,c,h), suppose 0<=c-s<=J, 0<=h-c<=A and pi_c(T) subseteq C, where C is a nonempty finite sound completion enclosure. Define

    M(C,J) = min_{c in C} (F(c-J+1)-c),
    D(C,J,A) = M(C,J)-A,
    Delta(T) = min_{(s,c,h) in T} (F(s+1)-h).

The completion interface is alpha(T)=(C,J,A). D is its selected expiry-slack query. Full-history and phase-profile queries below are equally strong when they retain the required information; no cost or whole-program superiority is claimed.

## Joint witness theorem

For every load and phase, Delta>=D. Equality holds for every load/phase if and only if each residue r in C mod P has a SINGLE triple with c mod P=r, c-s=J AND h-c=A.

Sufficiency: choose a completion residue attaining M and that residue's joint witness. Periodicity makes F(s+1)-h=M-A. The reverse inequality holds for every triple by monotonicity and the two bounds.

Necessity: suppose r lacks a joint witness. Choose phi=(r-J+1) mod P. Because r is represented in C, D=(K-1)P+1-J-A. For any triple, subtract D from its exact slack:

    ((phi-s-1) mod P) + (J-(c-s)) + (A-(h-c)).

Every term is a nonnegative integer. Equality requires both extrema and the aligned service phase, which implies completion residue r. The missing joint witness makes every difference positive, hence Delta>D. This argument does not require an erroneous inference from separately tight maxima. It characterizes slack equivalence, not necessarily sign-decision equivalence over a restricted policy family.

An exact fallback at fixed P retains nu_r=max{h-s : s mod P=r}. Then

    Delta=(K-1)P+1+min_r (((phi-r-1) mod P)-nu_r),

over populated service phases. Re-bucket from history when P changes. The older service/completion pair-margin criterion is obtained by taking a completed relation where age A is independently available for every pair. It does not by itself preserve a correlated actual next-decision slack.

Separately tight but nonjoint example: C={12}, J=A=3, T={(9,12,12),(11,12,15)}, K=2,P=4,phi=2. M=2, D=-1 but Delta=2. The completion test is unknown and the exact profile certifies. Neither marginal maximum is loose.

## Source-function mixed path and periodic lift

Under the pinned public source and the stated ready-hit timing premises,

    c(s) = p*ceil(s/p)+ell*p.

With one client address, one outstanding ordinary read, accepting ports and interval q, the unchanged MemTest functions produce

    h=s+q if c(s)<s+q,
    h=c(s)+q if c(s)>s+q.

The first branch receives the response before its scheduled poll. The second poll observes the outstanding address and the callback reschedules it. A reached equality c(s)=s+q is statically rejected because the native callback/poll tie priority is not established. Cache c(s), queue receipt and read cancellation are source arguments or declared stubs/premises, not native executions of those components.

The service phase graph modulo p is finite and deterministic. After any transient, it repeats with shift D that is a positive multiple of p. For a counter P=p, F(r+D)=F(r)+D. A finite cycle therefore establishes the timing relation for all recurrent iterations, conditional on valid cycle entry. Transients require their own safety checks. The main example starts directly in the cycle.

Let J be the maximum delay on an admitted recurrent cycle with J>q and set A=q. All completions have residue zero modulo p. Every maximum-delay event is in the wait branch, so its next-decision age equals q; all other ages are at most q. A joint witness exists. Thus for EVERY load and phase,

    Delta = M-q = (K-1)p-J+1+((phi+J-1) mod p)-q.

The actual maximum service gap is n=J+q. Maximizing the residue term over phase shows that some phase is safe exactly when Kp>n, hence

    K_best = 1+floor(n/p).

At this minimum load the safe phases satisfy ((phi+J-1) mod p)>=n mod p. The stronger uniform comparison uses the SAME actual maximum service gap and the minimum physical retention (K-1)p+1. Strict safety is n<(K-1)p+1, equivalently

    K_uniform = 1+ceil(n/p).

The load advantage is exactly one if n mod p is nonzero, and zero otherwise. This is an arithmetic certificate and parameter-selection result, not a measured counter implementation, area, energy, speed or application benefit. A full phase-history analyzer attains the same best load.

## Main cycle and negative controls

p=5,ell=1,q=8,s0=3 yields triples (3,10,11),(11,20,28), repeated after 25 ticks. Delays are 7/9 and actual service gaps 8/17. J=9,A=8. With K=4,P=5,phi=0, M=10 and Delta=2. Completion-uniform margin is 7, below age 8; the stronger actual-service uniform retention is 16, below gap 17. The independent-interval completion margin for C={10,20} is zero. The exact profile and completion query both certify every cycle. K<=3 has no safe phase; K=4 safe phases are 0,1,4; uniform needs K=5.

For actual phase 2, a WU at 12 expires at 27 before read28. For phase3 it expires at28 before the same-tick read. Read3 and read11 must both execute and cancel older arms before these events. A WU at11 is canceled by read11. No-WU control preserves all reads. Prefix models stop at the first miss. Independent tick and sparse models test all size-0/1/2 WU subsets on both inclusive main intervals: 218 local histories. This finite check is separate from the monotonicity/periodic induction proof for arbitrary WU schedules.

## Executed coverage and provenance

MIXED_POLL_PROTOCOL.json was fixed before the mixed execution, after inspecting earlier research. Of 588 declared configurations, all 216 reached equality cases are retained as contract rejections. Every remaining 372 case executes 60 callbacks (22,320 total) in five unchanged public functions with explicit stubs. Its recurrent cycle has J>q. The policy grid contains 118,083 raw queries. Deduplication uses every compared input: p,J,A,C normalized by a whole-p translation, the actual service-span phase profile, K and phi. It yields 93 unique interface inputs and 28,581 policy queries; 165 certify only with phase against both uniform and independent-interval comparisons. This is a chosen finite grid, not workload prevalence or statistical sampling.

The separate JOINT_WITNESS_PROTOCOL.json is explicitly a secondary addendum after the mixed run and before its own checker. Every nonempty triple relation in its declared small domain is audited: 5,512 relations, 32,320 load/phase queries, 899 all-policy-equal relations, zero disagreements. All 372 source cycles agree with the best-load formula; 90 input configurations have the one-count difference. Source, scripts, protocols, events and expected outputs are separately hashed. Cross-path executable hashes can differ and do not stand in for event equivalence.
