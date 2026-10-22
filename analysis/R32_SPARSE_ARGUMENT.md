# Sparse reconstruction from ordered residues

This is an algorithmic consequence for the paper's specific cyclic kernel,
not a new general min-convolution or essential-cover principle.

Normalize duplicate residues by maximum span and sort r_1<...<r_t.
Set w_i=r_i+nu_i. From the already proved own-reset domination criterion,
a smaller-residue j dominates i iff w_j>=w_i. A larger-residue j dominates
i iff w_j>=w_i+g. Thus i survives exactly when its weight strictly exceeds
the prefix maximum and its weight plus g strictly exceeds the suffix
maximum. One suffix pass and one prefix pass give every survivor without
enumerating phases or residue pairs. Sorting dominates O(t log t) arithmetic
cost, followed by O(t) scans and storage. These are arithmetic/comparison
bounds; arbitrary-precision bit costs depend on g and the spans.

Between raw reset phases every term rises by one. Equality of the two
envelopes at all raw reset phases (and phase zero) therefore implies equality
at every phase, including wrap. This permits finite sparse boundary checks
at very large g without pretending that all g phases were enumerated.

All equal spans retain every distinct residue. A single span advantage
of 10g dominates every other zero-span term. Those two analytic families
supply independently known large-output and small-output controls.

The canonical payload still preserves only fixed-modulus scalar observations.
Divisor projection and physical load must follow the existing theorem;
neither sparse construction nor its tests establish a cost benefit against
an equally informed and equally reduced baseline.
