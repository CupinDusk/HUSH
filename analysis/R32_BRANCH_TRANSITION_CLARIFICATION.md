# Exact existing branch semantics and quotient relation

No transition system changes. Input e is one external bit on an actual
callback. Use OLD mode M to choose tau=(a if M=0 else b)+e*p; then set
M'=M xor(1-e). Thus the four rows (M,e,tau,M') are (0,0,a,1),
(0,1,a+p,0), (1,0,b,0), (1,1,b+p,1).

At the start of a concrete tick, A=t-s is age since most recent accepted
service s, or -1 before first service. W is waiting for callback, D is
the source's remaining computation delay, and G is the planned age of
the next service, or -1 while that next age is not yet determined.
Initial M=1,W=false,D=0,A=G=-1 and t=a. When not waiting, decrement
positive D at tick start and send when it reaches zero. An accepted read
sets W=true,D=0,A=0,G=-1. A callback at the same tick's pipeline boundary
computes tau from old M and e, then sets W=false,D=tau,G=A+tau and updates
M. At tick end, increment nonnegative A. No callback is possible on the
tick of a just accepted read. At the next service A=G before resetting.
G is an observation/check ghost and does not control scheduling.

Abstraction alpha takes t mod L, the exact endpoint valid/enabled/count
and occupied/id/snapshot registers, M,W,D,A,G, fixes data zero for the
control domain, and renames the sole live ID to1. A=t-s and G=h-s
are translation invariant; D is already relative. L=lcm(p,P) preserves
all periodic guards. Each read/callback transition and each e/WU input
depends only on the represented fields. IDs are renamed only after the
previous callback, so no two live requests alias. Thus an abstract
successor is the alpha-image of every concrete representative's successor,
with the same read/callback/expiry observation, and every concrete input
has a represented successor. This manual congruence supplies completeness.
Independent per-edge replay checks arithmetic/state outcomes conditional
on that relation; it does not independently prove the quotient. Data
control independence is not arbitrary payload-coherence validation.
