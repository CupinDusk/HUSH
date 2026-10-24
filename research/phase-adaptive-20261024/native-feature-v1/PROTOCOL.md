# Native feature-work sensitivity before new heldout timing

Purpose: test the causal hypothesis that the relative amount of real private
feature computation determines whether phase-specific T improves complete
program time. This is an exploratory extension after prior near-zero native
results, not an unseen replication of those results. Workload/binary stays
unchanged; the existing autocorrelation lag parameter varies1/16/64. These
are actual signal-feature computations, not added delay or busy-loop padding.

Freeze before new timing: N16 training,16KiB two-way unified L1,64B lines,
producer64/256 storesperline and sparse/dense patterns, lag1/16/64. All5x5
active/private loads8/64/512/4096/65536 and WI/WU controls:324cases. Same
preloaded descriptor interface, extra changed-load stall8, four1GHz cores.
Select the minimum-J nonconstant phase and minimum-J constant for each12
settings, with deterministic lexicographic ties. Preserve every outcome.

Freeze each setting's phase before any native N28/N32 timing. Validation
uses those two unseen sizes and all15 fixed loads from the prior strengthened
control grid, frozen phase, WI and WU:432cases. No retuning after validation.
All program/marker/invariant checks and task times remain required.
Primary outcome is phase J / best of all15 measured constant J separately
per heldout input; retain signed results. Check fixed-mode selection as a
separate deployed-mode view, frozen from training, not chosen after heldout.
No native WCET claim; analyze runtime opportunity, keeping all older data.
Two simulation jobs maximum;20billion tick natural limit; no termination.

## Execution-budget amendment before training outcomes/validation

Before inspecting new training performance or any N28/N32 native timing,
prioritize the complete N28 heldout matrix (all12 settings×18policies=216runs)
to meet the user two-hour work limit. N32 remains planned but deferred; it
will not be reported as executed. This is a time-budget decision, not an
outcome-dependent exclusion. The primary rule, all15 fixed controls and all
three lag conditions are unchanged.
