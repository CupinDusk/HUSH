# Read-boundary correction

R16's displayed total order is WU, decrement, read decision/cancel. A valid read at s cancels every WU already processed at that tick. Therefore a surviving later WU must have integer r>=s+1. The v13 interval models initialized cancellation before processing WU(s); interpreting their left endpoint as a complete read under the displayed total order was wrong. The WU9/P4/K4/phi1 trace is withdrawn as a client-level false-certificate example, not silently relabeled. Both original Weak Reject reviews and v13 bytes remain.

Keep this same order at **every** tick and every read. Start before a valid seed read; explicitly execute that read's cancellation. A deadline is tested before the next read, and only a valid read can cancel it. Both corrected implementations include all read events and stop the conditional hit-path interpretation after a miss.

## Earliest surviving arm

For a fixed post-service arm offset theta, every surviving arm has r>=s+theta. The original monotonicity argument gives expiry>=E(s+theta)>=E(c-J+theta). Hence define

```
M_theta(C,J) = min_c (E(c-J+theta)-c),
Gamma_R,theta = min_(s,c) (F(s+theta)-c),
G+L < M_theta.
```

Theta=0 is the earlier generic contract admitting a WU after cancellation at the same integer service time. Theta=1 is the present fixed WU/decrement/read/cancel receiver. The physical load-first timer map F(r) is unchanged. F(x+theta) occurs only as the earliest-future-arm query function; do not assert the hardware installs F(r+theta) on WU r.

For load-first periodic counters,

```
M_theta=(K-1)P-J+theta + min_(c in C)((phi+J-theta-c) mod P).
RU_theta=(K-1)P-J+theta.
Gamma_R,theta=(K-1)P+theta + min_r(((phi-r-theta) mod P)-omega_r).
```

Phase reindexing by theta preserves the fixed-(P,J) completion-residue quotient. Historical equality at every phase/load still holds iff each completion residue has a pair with delay J: sufficiency chooses its witness; necessity chooses phi=r-J+theta. This is a specialization of the old arithmetic, not a new representation or timer.

For the serial source client, the public callback relation remains c_n=c0+nH, s_n=c_n-J, H=(ell+1)p,J=H-1,G1. At P=p,K=ell+2,phi0, M1=p but **RU1=2 also certifies G1**. The older RP/RU0 comparison was merely an ablation omitting the read-order fact; it is not evidence phase is needed for this aligned infinite-loop family. Its seed and inductive validity remain sound under the stronger order. Per-iteration identities are not joined.

## A finite phase-sensitive prefix with the stronger baseline

Take p4,ell2,s0=0,c0=8. Steady pairs are (9,20),(21,32); their next decisions are21,33. At K3,P5,phi4, theta1, the earliest surviving arms are10,22. Their expiries are24,34, so M1=Gamma1=2>G1. The stronger uniform margin is0 and projected margin is24-32=-8, both unknown. The seed is safe since its earliest post-service arm at1 expires14>9. Thus the first two steady steps certify. This is a finite horizon, not an infinite-loop certificate for that policy.

Wrong phase phi1 with WU10 gives decrements11,16,21 and expiry21 before read21. The read at9 is explicitly included and cancels only earlier arms; it cannot cancel the later WU10. The correct M1=1 rejects strict G1, while stale phase4 M1=2 would falsely certify. The complete prefix stops at that miss.

Extending the phase4 horizon to include completion44 gives M1=0, so it is unknown. With earlier WUs absent, read33 is valid, WU34 decrements at34,39,44 and expires44 before read45. This exposes the finite-horizon limitation without altering the earlier two-step proof or continuing a hit trace after a miss.

The new 33,720 plus 240 histories are bounded local steps with both read endpoints present. They do not enumerate long-run WU sequences; the aligned family all-iteration statement follows separately from induction. Public callback traces are reused, with no new source-function or native execution claim.
