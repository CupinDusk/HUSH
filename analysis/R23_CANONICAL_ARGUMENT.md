# A canonical minimum profile for this periodic scalar query

Fix modulus g>=1. A populated residue r has span nu_r>=0 and term f_r(phi)=((phi-r-1) mod g)-nu_r. The query is G(phi)=min_r f_r(phi); receiver load adds the unchanged common term (K-1)P+1. Profiles have one maximum span at each populated residue. The result below is minimum TERM count within this circular-sawtooth profile family, not a universally optimal message encoding or a new general abstract-domain kernel theorem.

## Dominance and reduction

For distinct q,r let d=(r-q) mod g in1..g-1. The difference of their remainder terms takes only d or d-g, with its maximum d attained at r's reset phase phi=(r+1) mod g. Consequently f_q<=f_r at every phase iff nu_q-nu_r>=d. If r fails this test for every q, it is strictly below every other term at its own reset. If it fails strict minimality there, a single q already dominates it globally. A dominator has strictly larger span, so repeated domination terminates at an undominated term. Removing all dominated terms therefore preserves G, while every undominated term is necessary at its reset. The pairwise test gives an O(t^2) construction from t supplied phases.

## Uniqueness and arbitrary alternative profiles

All terms increase by1 from phase phi-1 to phi, except the term at r=phi-1 mod g, which resets by g. Thus if G(phi)<G(phi-1)+1 (cyclic phase indexing), ANY exact profile of this family must contain the term that resets at phi. It must have span -G(phi); otherwise it cannot cause the observed drop. An undominated term r produces exactly this strict drop at its reset: every rival is strictly larger there and rises by1 across that step. A dominated term produces no envelope drop, since its global dominator does not reset at that phase. The envelope's reset locations and values therefore reconstruct precisely the undominated pairs. Every alternative exact profile must include all those pairs; any others are redundant. This proves one unique minimum exact profile, even allowing new residues/spans rather than only choosing a subset of the original profile. No finite enumeration is used as proof for unbounded spans.

## Completion witnesses imply a canonical common-span profile

If every c in represented Cg has a joint witness, Theorem2/3 of the paper give exact slack from Cg,J,A. Form Q={( (c-J) mod g, J+A):c in Cg}. Its scalar query is exactly the completion formula. Every term has the same span J+A, so distinct terms do not dominate each other; Q is irredundant. By uniqueness it is the canonical exact profile of the original reachable relation. Conversely equality to this Q gives the completion query for every phase/load, hence the paper's joint-witness iff applies. This also works when Cg is a sound enclosure rather than merely a projection; a spurious non-witness residue would fail the iff.

This subsumes the R22 reviewer1 witness-profile reduction. The main P5 profile {(3,8),(1,17)} reduces to {(1,17)}; the p9/q16 complete-payload example reduces to {(1,33)}. Both are3 slots/1 term in the old length-plus-pairs schema. R22 completion's supposed savings were against a query-redundant comparator. Preserve those original counts as protocol history, not competitive economy.

## Fair handoff accounting and scope

For exact completion with m=w entries, the R22 complete payload costs2m+5, versus2m+1 for its reduced profile pairs and m+2 for a length/residue/common-span encoding. Under the R22 incremental convention completion costs m+2 versus2m+1; when m=1 they tie. All successful compressed source-grid interfaces are conjectured m=1 pending the new audit; do not claim that until execution verifies it.

If Cg,J,A ALREADY exist at the consumer, both routes can use the same trusted joint-exactness status to either query completion directly or derive Q by shifting residues and using span J+A. No resend of Cg or witness-residue list is mathematically necessary. A status-only protocol still trusts the producer; it does not prove reachability. Neither route has an information advantage over the other under that same context. The value of the criterion is recognizing when an existing completion enclosure/bounds are sufficient to derive exact slack and a canonical profile; it is not an intrinsic payload advantage over the reduced profile.

The analysis applies to supplied timing relations/periodic enclosures under declared receiver premises. It does not establish native cache conformance, arbitrary-program prevalence, physical savings or a deployed producer. General correctness kernels, observed-query equivalence, dominance/envelope simplification and min-plus algebra are prior mathematical concepts. A later manuscript must compare this concrete reset-phase normal form with those frameworks and not claim their invention.
