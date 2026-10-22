# Exact quotient reuse of canonical timing profiles

Recorded before executing R26 remodularization checks. This is a query-family
statement; general quotient abstraction and envelope reasoning are not new.

For a finite nonempty collection A={(s,v)}, with integer service s and
nonnegative span v, let nu_g retain maximum v at each s mod g. Let kappa_g
be the canonical undominated profile from R23/Theorem3. Its envelope is
H_g(phi)=min_r(((phi-r-1) mod g)-nu_g(r)). A target projection first reduces
residues modulo h, retains maximum span at collisions, then applies kappa_h.

If h divides g, every g-dominance survives projection: if w-v >=(r-q) mod g,
then w-v >=(r-q) mod h, since reduction modulo a divisor can only lower the
nonnegative directed distance. When projected residues collide, w>=v makes
the deleted term unnecessary under max aggregation. Every discarded g-term
has a final retained g-dominator, so retaining only kappa_g before projection
does not change the h-envelope. Uniqueness of the canonical form gives

    kappa_h(nu_h(A)) = kappa_h(project_h(kappa_g(nu_g(A)))).

This map also composes along divisor chains. A physical period change with
the same quotient g needs no change to the payload; a proper divisor can
derive the exact coarser payload without the producer's event relation.

The divisor condition is necessary for universal recovery from only the
source payload. If h does not divide g, A={(0,v)} and A'={(g,v)} have the
same g-profile but different h-envelopes at phi=1. This is an actual periodic
timing-relation counterexample: take d=lcm(g,h), v=d and completion c=s.
The recurrent relations have consecutive services s+n*d and h=s+(n+1)*d.
They share translation d, J=0,A=d, old completion residue0 modulo g and the
same canonical source payload {(0,d)}. At target h, the phase1 remainders
are0 and(-g mod h)>0, so exact slacks differ. Identity/epoch labels may be
the same, but no extra exact service timestamp is supplied in the payload.
This proves non-determination of all scalar slacks, not necessarily a
safe/unsafe policy separation. Extra producer information can of course
distinguish these relations; it is excluded from the only-payload claim.

For a fixed relation T0+n*d, the existing periodic-lift theorem gives target
g=gcd(P,d). Every such g divides d. Therefore one master kappa_d(T0) can
derive the exact canonical payload for EVERY physical P, with exact slack

    (K-1)*P + 1 + H_g(phi mod g).

The physical P is not replaced by g. Existing source modulus g0 can always
serve a new P when gcd(P,d) divides g0, even if the physical new P does not
divide the old P. For example d81,oldP27 yields g27, while newP18 yields g9.
The source summary remains valid only for the same admitted relation,
clock/epoch/identity/response premises. Offline querying a new period does
not preserve a runtime token whose configuration binding has been revoked.

Among same-modulus circular service-span master profiles preserving every
physical-period query, kappa_d is the unique minimum exact profile: period
P=d is among those queries, so R23's forced-reset necessity applies. This
is not a universal minimum encoding across representations, a minimum
payload for an arbitrary finite subset of target periods, or a cost win.
The universal master can retain more terms than a fixed-period profile.

The existing four-event d81 example has raw master pairs
(5,16),(21,16),(37,33),(70,16), all necessary at modulus81. Projection to27
gives the previously demonstrated canonical pairs(5,16),(10,33); projection
of those pairs to9 yields(1,33). Direct extraction from the same event
relation must give the same forms. At physicalP18,K3, phi2, slack is
36+1-33=4; the physical load term is36, not18 or a quotient-period load.

R25 clarification obligations remain: the completion-induced common-span
profile always exists for its abstract query D. Joint extrema characterize
its exact equality with the true service-span canonical profile, not its
existence. A reset-revealing step means H(phi)<H(phi-1 mod g)+1, including a
flat step; for g1 the unique profile is(0,-H(0)). The actual-gap uniform
slack is U=(K-1)P+1-max(h-s), distinct from the completion M-A bound.
