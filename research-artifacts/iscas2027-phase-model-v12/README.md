# Minimal public reproducer v12: sparse canonical scan

Standing-authorized same-scope own research update. MANIFEST is the whole
input allowlist; no manuscript, private overlay/acquisition/kernel/server
materials or credentials. All previous input models and negative results
are preserved. The README history records their original scope.

For sorted distinct residues r_i and nonnegative spans nu_i, w_i=r_i+nu_i.
Keep i iff w_i exceeds the prefix maximum and w_i+g exceeds the suffix
maximum (empty maximum is minus infinity). This follows the existing
own-reset criterion. Sorting is O(t log t), two scans/storage O(t), without
a modulus-sized array. These are arithmetic/comparison bounds; arbitrary
precision bit costs depend on modulus/spans. This is a specialization of
established envelope machinery, not a generic new transform algorithm.

Prospective checks include all 15420 profiles at g=1..4/spans0..2g+1,
60844 complete phases, and 112 seeded sparse profiles at g=2^61-1 with
11088 reset-boundary checks against independently written pairwise rules.
Between raw resets every term rises by one, so the boundary argument
supports whole-envelope comparison. Large analytic controls through
16384 terms retain every term or one term as expected. Large moduli are
not fully phase-enumerated; no measured runtime/byte benefit is asserted.

R32_BRANCH_TRANSITION_CLARIFICATION spells out existing old-mode/input-bit
semantics, source ages/ghost and the concrete-to-key congruence. The actual
endpoint/branch implementation and all 440 graph counts are unchanged.
Independent edge replay checks transitions conditional on the manual
quotient proof; it does not independently prove quotient completeness or
validate arbitrary data-coherence behavior.

Fresh extraction with Python3.12 and Zig0.14.1:

    python -B -X utf8 run_checks.py --zig /absolute/path/to/zig

All 17 stages reproduce hashes/aggregates, with prior path-dependent
binary hashes the sole old exception. Windows verified, other OS/toolchains
unverified. Fair equally reduced exact baselines still coincide. No native
HUSH/gem5, independent real workload, hardware, global coherence, actual
application/policy/runtime/byte gain or deployment claim. Codex assisted.
