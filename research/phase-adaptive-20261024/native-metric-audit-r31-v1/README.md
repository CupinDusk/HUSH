# HUSH exact native metric supplement

This additive package independently audits previously public native observations. It contains standard-library analysis code, exact recorded-data copies, expected CSV tables, a reduction receipt, provenance, and the retained MIT notice. It adds no native experiment or policy and performs no network access.

With Python 3.12 or later:

```text
python -B -X utf8 replay.py
python -B -X utf8 replay.py --output ./fresh-metrics
```

The wrapper verifies the top-level files and every ZIP member, extracts safely to a temporary directory, runs the standalone checker, and compares all nine generated CSVs and the audit receipt byte-for-byte. It also changes an isolated input copy and verifies that the checker rejects the changed input. The optional output directory receives the verified tables and receipt. The checker accepts explicit input and output directories and has no dependency on the original project layout.

The 420 observations form 20 cache/N groups, seven policies, and three offsets `{0,64,127}`. The ten primary 32KiB groups comprise N16 training plus nine frozen-policy migrations. The ten 64KiB groups retain the undeployed phase diagnostic; fixed remains the deployed 64KiB policy. All 420 observations and 140 aggregate points remain, including dominated points, negative signed excesses, and points outside the descriptive 0.1% guard.

The original N16 selector uses `max(J_policy)/max(J_fastest_fixed) <= 1.001`. The descriptive heldout statistic is `max_phi(100*(J_policy_phi/J_K253_phi - 1))`. These are different definitions. K253 time is offset-invariant within every group here, so the two excess statistics coincide exactly for all 140 points. The checker separately computes both and replays all 1674 original N16 candidate observations, reproducing the frozen choices without heldout retuning. The seven reported controls are not the original selector search space; the N16 suppression rows were measured after the original freeze.

Using exact `Fraction` comparisons, phase is on the seven-policy aggregate frontier in 9/10 primary groups (one training group and 8/9 migrations). It aggregate-dominates frozen fixed in 9/10, but dominates fixed at every measured offset in 8/10. At 32KiB N32, phase-minus-fixed J is `+2237,-316,+2470` cycles at offsets `0,64,127`, despite smaller WU at all three offsets. At N24, K1 dominates phase. The 64KiB diagnostic is on the seven-policy frontier in 10/10 groups and aggregate-dominates fixed in 4/10.

The 0.1% tolerance is one point on the observed time–traffic tradeoff, not a supplied application deadline. This finite seven-policy, three-offset comparison does not establish a frontier over all legal policies or offsets, application WCET, energy, physical timing, or platform signoff. No simulator binary, guest ELF, private overlay, server/account configuration, manuscript, or reviewer material is bundled.

`analysis/PROVENANCE.json` inside the ZIP binds input bytes to the earlier published research packages or the prior published frontier. Original input bytes and the prior MIT notice are preserved. No external code was added; contributed analysis code and documentation use the accompanying MIT license, which does not replace any upstream notice.
