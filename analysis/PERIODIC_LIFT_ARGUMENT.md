# Conditional periodic lifting and complete handoff accounting

This is secondary mathematical analysis prompted by R20 reviews and the divisor-only audit. It adds no native/cache/queue execution. Existing source/stub cycles, all negative results and predecessor protocols remain immutable.

Let T0 be a nonempty finite cycle of (s,c,h) triples, with a positive translation period d. Its future relation contains every triple translated by n*d for n>=0. This premise is separate from a finite trace: for the declared deterministic client, the service-phase state and branch recurrence repeat and d is divisible by the cache clock p. Valid cycle entry, epoch/residency and receiver semantics remain premises. Transients or changed future inputs need their own proof.

For any receiver period P>=1, put g=gcd(P,d) and B=(K-1)*P. The P/g translations n=0,...,P/g-1 visit exactly the residues congruent to each event's original residue modulo g. This follows because d/g and P/g are coprime. Their total shift d*P/g is divisible by P, so they are a phase fundamental domain for all future iterations. This is an analytic expansion, not additional source execution.

For one base triple, minimizing (phi-s-1-n*d) mod P over translations gives (phi-s-1) mod g. Therefore the infinite-cycle worst slack is

    Delta = B+1+min_base_triples(((phi-s-1) mod g)-(h-s)).

The completion enclosure bound has the same reduction:

    D = B-J+1+min_base_completion_residues((phi+J-1-c) mod g)-A.

The receiver retention term remains B=(K-1)*P. Replacing it by (K-1)*g would change the physical counter and is incorrect. Let Cg denote the base completion residues modulo g, and Wg those of base triples jointly attaining c-s=J and h-c=A. The lifted sets modulo P are the full corresponding congruence classes. They are equal iff Cg=Wg. Applying the existing finite joint-witness iff to the phase fundamental domain proves all-policy exactness iff Cg=Wg. Profile buckets also compress modulo g. One scan of the base triples constructs both interfaces; later queries need no P/g-fold unrolling. Common proof bindings must include the periodicity premise when it is used.

Worked example fixed before expanded audit: T0={(3,10,11),(11,20,28)},d=25,P=15 gives g=5 and three copies. The expanded triples are (3,10,11),(11,20,28),(28,35,36),(36,45,53),(53,60,61),(61,70,78). Completion residues modulo15 are0,5,10; each has a jointly extremal triple (delay9,age8). Compressed Cg=Wg={0}. The compressed service profile is nu1=17,nu3=8. At K2, exact slack is -1+((phi+8) mod5); safe phases modulo5 are0,1,4. The actual-gap uniform rule requires K3 because gap17 exceeds retention16. This remains conditional expiry safety, not physical counter-area or application benefit.

Two predeclared secondary audits execute separately. The divisor-only audit retains all2,204 (cycle,P) pairs with P|d;354 are inexact. The expanded audit retains all11,904 pairs from372 cycles and P1..32, including569 inexact pairs and9,645 exact pairs with multiple lifted completion residues. All785,664 phase/K1..4 comparisons agree with direct expanded-triple arithmetic and witness equality. Deduplicating (P,g,J,A,Cg,profile_g) yields2,510 interfaces,2,183 exact and327 inexact. These are policy and duplicate-start counts, not independent programs, new callbacks or prevalence in applications. The proofs cover arbitrary K/P; finite enumeration only checks the declared finite grid.

Complete field accounting uses abstract scalar slots, not an empirical byte/time model. Let H stand for required common identity/epoch/horizon/P and, when applicable, periodicity bindings; these may have their own variable-width representation. An explicit completion payload contains J,A, one length and m residues, one length and w reported joint-witness residues, and one exactness status: H+m+w+5 slots. A profile contains one length and t pairs: H+2t+1. Reported witness sets/status remain trusted reachability claims, not independently checkable proofs. For the main compressed case (m,w,t)=(1,1,2), these are H+7 versus H+5; completion is not the smaller complete payload. If C,J,A already cross the interface, its additional witness list/status costs3 slots versus5 for a new profile. This reuse observation and the one-versus-two query-term counts do not establish total runtime/transport/storage savings. Applying periodic compression fairly to both alternatives is mandatory.

No manuscript, private overlay, server data, identifiers or credentials belong to this public mathematical/model package. Codex assisted the arguments, implementation, checks and documentation. Existing upstream licenses remain in force.
