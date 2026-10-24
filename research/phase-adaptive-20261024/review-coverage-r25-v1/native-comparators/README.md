# Matched native comparator completion

This is a retrospective derivation from the original R20 recorded native
measurements, with no new simulation, source change, or heldout reselection.
Run standard-library Python:

```text
python -B -X utf8 replay.py
python -B -X utf8 independent_check.py
```

The minimal inputs retain all 1,674 N16 fixed/phase training measurements,
126 policy-by-heldout measurements, and all 324 heldout fixed measurements
(16 prespecified diagnostics plus the two frozen winners at each point).
The selected fixed records occur in both heldout inputs for convenience;
their original-record hashes identify the duplication. The original public
archive/member/frozen-selection/protocol hashes and the minimal-input hashes
are in INPUT_BINDINGS.json. The extractor validates every retained terminal
and marker result, phase/suppression common command and pre-intervention epoch,
and fixed simulator, ELF, configuration, and driver hashes. It also cross-checks
54 corresponding R24 heldout records. Each retained record has a SHA256 of its
complete original canonical JSON object. To re-extract or check original data:

```text
python -B -X utf8 extract_inputs.py --r20 PUBLIC_R20_DIRECTORY --r24 R24_NATIVE_DIRECTORY
python -B -X utf8 independent_check.py --r20 PUBLIC_R20_DIRECTORY
```

The seven policy identities are K1, predictable WI, ordinary WU, matched
suppression, the original frozen phase vector, frozen eligible fixed, and
frozen fastest fixed. The N16 selection is independently recomputed across
all 255 fixed loads and 24 phase vectors at all three offsets per geometry.
The fastest fixed is K253 in both geometries. The eligible fixed is K3 in
32KiB and K106 in 64KiB. The phase vector is (1,128,1) in 32KiB and the
original fallback diagnostic (1,128,128) in 64KiB. No 64KiB phase candidate
met the N16 0.1% objective; the original deployment rule therefore uses fixed
there. This diagnostic identity must not be called a deployed phase policy.

The empirical allowance at a heldout point is exactly
`1000*J_policy(N,phi) <= 1001*J_K253(N,phi)` using the same geometry, N and phi.
K253 is frozen from N16; it is not reoptimized on heldout inputs. This
describes heldout measured time and is not a WCET or heldout admission
guarantee. The original 0.1% parameter remains unchanged.

Outputs:

- PER_OFFSET.csv: all 126 paired measurements, signed exact admission
  thresholds, and Pareto labels against the seven frozen identities.
- WORST_OFFSET.csv: 42 separate maxima of J and WU across phi=0,64,127,
  count of same-offset admissions out of three, both max-J and robust
  same-offset thresholds. The J and WU maxima may occur at different offsets.
- TABLE_SIX_ROWS.csv and table-six-rows.tex: six geometry/input rows and
  seven policy cells, each giving worst-offset million cycles / WU /
  admissions out of three. CSV preserves integer cycles; TeX rounds J.
- PAIRED_PARETO.csv and PAIRED_WORST_OFFSET.csv: respectively 378 and 126
  unordered paired comparisons; signed differences and both dominance
  directions are retained. A zero-WU percentage denominator is undefined.
- TOLERANCE_INTERVALS.csv: 192 exact, half-open eligibility intervals for
  each point and each three-offset robust group. Negative thresholds are
  retained when an alternative is faster than frozen K253. Minimum-WU labels
  are retrospective descriptions, never deployed heldout selections.
- PHASE_USEFUL_INTERVALS.csv: exact phase unique-minimum-WU intervals against
  the seven frozen policy identities; these do not include all diagnostics.
- FIXED_DIAGNOSTIC_PARETO.csv: phase checks against all 16 prespecified
  diagnostics, both extra frozen fixed winners, WI/WU/suppression; includes
  the fastest of 16 as a distinct posthoc diagnostic, not an all-255 oracle.
- EXTENDED_PHASE_USEFUL_INTERVALS.csv: exact phase unique-minimum-WU intervals
  against all 18 measured fixed loads plus WI/WU/suppression. At a robust
  group, each identity must meet the allowance at every same-offset point
  and WU is its maximum over the three offsets. Nonnegative intervals and
  the unclipped signed lower bounds are both retained; `nonempty=False`
  means the reported lower/upper pair does not define a usable interval.
- PHASE_SIMPLE_CONTRASTS.csv and PHASE_SIMPLE_RANGES.json: all signed phase
  comparisons with K1/suppression, separately summarized for 18 and 9 points.
- AUDIT.json: selection checks, policy admission/dominance counts and hashes.
- INDEPENDENT_CHECK.json: separate arithmetic and optional original-source
  extraction check. Its checker imports neither replay nor extraction code.

The result is a tradeoff. Phase is faster than K1 and suppression in all
18 paired conditions, but sends about 3.82–4.61 times their WU traffic.
At the original 0.1% allowance, K1, suppression and phase each admit 15/18;
the three phase failures are all 32KiB,N32 offsets. Where phase is admitted,
K1/suppression already provide lower WU within the same allowance. Phase
is therefore never the minimum-WU eligible member of the seven at 0.1%.

Phase is nondominated at 15/18 conditions against the expanded measured
set. Fixed K2 dominates phase at 64KiB,N40 for all three offsets. Against
all measured alternatives, four of six robust groups have a nonempty
nonnegative tolerance interval where phase uniquely minimizes WU; none
contains 0.1%. The 32KiB,N40 signed interval lies below zero because K2
is already faster than frozen K253. This is a conditional operating regime,
not a general superiority result. The 64KiB phase results remain diagnostic.

The suppression ablation disables the complete future-timeout intervention,
including its receiver interlock, while preserving descriptors/helper/stall
costs. It is not a pure TTL-only intervention. Measurements use one native
system and deterministic conditions; offsets are not stochastic replicates.
Whole-system WU is not frame-attributed traffic or application energy.
The simulator overlay/binary is unavailable in this portable data-only replay;
this package reproduces arithmetic over recorded measurements, not execution.
