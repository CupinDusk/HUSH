# Conditional composition for this calendar component

This is a new argument for the specified own reference receiver. It is not
an automatic application of an earlier theorem to native HUSH or coherence.
The producer's argument and finite executions remain subject to independent
transition/arithmetic/fresh-netlist validation.

Fix one epoch (p,r,F,K,P,phi), the multiset calendar, distinct four line tags,
FIFO8, fixed sink readiness, exact tick order, and the reset or admitted
cycle-entry state. No other invalidation/refill/revocation/reset exists. WUs
are optional per line on each integer tick and are accepted only while valid.
No WU is permitted on a line before its guaranteed initial capture. The source
enqueues independently of callbacks; bytes and counters affect control only
at a tag-validity check on a grant attempt. R0-entry occupancy, FIFO order,
sink readiness and snapshot registers otherwise determine control.

For the all-hit execution, enumerate the actual successful captures of line j
in strict time order. Every capture s cancels its tag timer; h is the very next
capture of that same line, regardless of how many requests for that line are
outstanding. Callback c is matched by request ID, not by a one-pending flag.
FIFO/snapshot conservation and unique ID ownership preserve this matching.
Thus pending multiplicity does not invalidate the predecessor relation.

Let E(u)=u+((phi-u) mod P)+(K-1)P be the integer tick of the Kth decrement
at/after a WU at u. WU precedes decrement, so E includes a same-tick decrement.
E is nondecreasing in u: it is the Kth member at/after u of an ordered periodic
set. Between s and h a line either receives no WU and stays valid with its
timer disabled, or receives its first WU at u>=s+1. Later WUs reset to K and
cannot move expiry earlier, by monotonicity of E. Therefore E(s+1)>h suffices
for every optional WU word to keep that line valid through the read at h.
Strict positivity is required because expiry precedes a same-tick read.

Suppose every actual prefix edge and every physically lifted recurrent edge
on all four lines has E(s+1)-h>0, but there is a first missed grant. Until that
attempt, source enqueues, successful capture cancellations, immutable snapshot
transfers/emissions, and callbacks match the all-hit execution. The previous
same-line capture exists, since initial captures are guaranteed without WUs.
The missed grant is its h, contradicting the preceding monotonic bound. This
proves conditional all-WU safety for this component's epoch. It does not claim
that finite testing exhausted all WU words or arbitrary coherent data.

Conversely, a nonpositive minimizing actual edge admits a sharp one-WU word:
no earlier WUs; put exactly one accepted WU at s+1 on that line. E(s+1)<=h;
there is no intervening same-line capture to cancel it. Other tags never arm.
The all-hit control continues through h's attempt, where the target misses for
the first time. Snapshots captured earlier remain immutable even if their tag
expires before callback. The executions test precisely these finite words.

A complete normalized key contains all live FIFO/snapshot tokens, their
owner/relative ID and byte, source/cache/ready phases, tag/timer state and
fault/miss state. The only removed fields are dead queue/snapshot payloads,
whose next use is preceded by overwrite, and the affine common ID origin.
ID translation is bijective and preserves equality and queue order. Fixed
calendar control is deterministic under all-hit tags. Equal keys and checked
translated continuation therefore establish the repeated live-state control
relation. A physical P has orbit length P/gcd(P,F); lifting every actual cycle
edge through that orbit covers every physical timer phase. Prefix edges are
evaluated literally at the original physical P,phi, including crossing h.

The original empty-frame hypothesis fails at p=r=7: t=56 has two queued IDs.
It remains UNKNOWN under that first experiment. A separately authorized
post-observation complete-key experiment finds entry37/repeat93 with empty
live state and verifies two further period translations. Its four prefix
edges remain exact; none is discarded. Every observed cycle entry happens
to be empty, including t=37. Thus a translated reset at a+nF with clock phases
set to the physical residues, all tags valid, timers disabled and bytes zero
is identical to no-WU all-hit prehistory up to the recorded affine ID shift.
Only ticks actually executed after that reset are counted. A nonempty entry
would require its complete token state or executing the physical prefix.

For the completion comparator, each line has actual recurrent completion
residues C0 and tight nonnegative integers J=max(c-s), A=max(h-c); all observed
edges satisfy s<c<=h. Since s>=c-J and h<=c+A, the monotonic expiry function
makes E(c-J+1)>c+A a sufficient bound for the actual edge. For K=1 the bound
is 1-J-A+((phi+J-1-c) mod P); lifting gives the minimum modulo gcd(P,F).
Both routes share exactly the same literal prefix. This explains completion
admissions being a subset without erasing line identities. If c>h occurred,
that completion-domain claim would be withheld rather than repaired.

The RTL finite runs and producer checks substantiate the stated transition
implementation and tested witnesses. Universal-WU safety still depends on
this proof's fixed-epoch/source/no-other-invalidation assumptions. No native
HUSH refinement, coherence, PPA, hardware timing, or application benefit follows.
