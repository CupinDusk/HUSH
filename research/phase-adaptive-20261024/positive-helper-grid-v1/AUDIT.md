# Positive-helper deployment grid

The protocol was frozen before any R15 grid execution. The exact model SHA256 is
6270a7fa1c79a81dab99f9712e170c60c1ded14dd5052f3b987ba421a1b99e10 and remains
unchanged. This is a two-client architecture-model study with dedicated clean
receiver slots, bounded services and explicit controller work. It is not native
application timing or a finite-cache application experiment.

## Design and complete accounting

The original79 settings are preserved:72 combinations of BSQ/DQD, q2/4/8/16,
compute gaps1/4/16 and tick periods2/10/32, plus seven single-factor BSQ controls
at q=g4,P10 (miss slots30/120, switch cycles4/16/64, writer gaps0/16).
Default writer gap4, quiet512 and64q stores are unchanged. The per-case miss
bound is WUslot+1+missslot, matching the original one-factor study.

Each of591 phase vectors pays helper delta before both noninitial markers,
even when its load does not change; every changed load also pays its configured
registered-write cost. Fixed comparison exhausts all255 loads and every subset
of free boundary flushes. Both families have free end release. Budgets are
externally specified B0+{0,16,32,64}, with B0=Cbase+qLm+(n-q)Lh; B0 excludes
helpers. Helper costs4/8/16 are never absorbed by increasing an individual
deadline. All948 combinations are completed.

For each setting, both candidate families are selected at tick phase0 and the
specified training writer gap. Offline selection chooses the faster admitted
family, favoring fixed on joint-time ties, before paying any helper cost. That
choice is frozen at validation writer gaps1/7/16 and tick phases0/P-1. Therefore
training gains are nonnegative by selection, while held-out effects can be
negative. No reselection or runtime fallback is performed after observing a
validation result. Identical selected executions are cached within one case;
this saves computation without changing the scientific inputs.

All220,647 candidate rows are retained as per-case JSONL.gz streams. Inadmitted
candidates retain their static bounds and admission masks; every attempted
execution and all assertion failures would be recorded. There are67,834 actual
executions, zero assertion/other failures,948 valid selected settings and5,688
held-out paired timing points. Every selected and baseline execution meets the
same receiver budget through the unchanged model bound assertions.

## Predeclared primary: delta8, margin32

Across all79 settings, phase mode improves33 training points (up to26.11%) and
fixed mode is selected at46 ties. All33 phase selections occur in BSQ:33/43 BSQ
settings improve, while36/36 DQD settings choose fixed mode. The median training
gain is2.284% across all43 BSQ settings,5.223% among the33 winning training
settings, and zero across all79 settings.

Freezing these policies gives474 held-out pairs:162 wins,282 ties and30 losses.
Signed effects span -0.806% to29.752%. The median is2.175% across all258 BSQ
held-out pairs, and zero across all474 primary points. The36 DQD cases remain
fixed-mode ties. This identifies bootstrap-to-steady reuse as the useful
deployment region while retaining the helper cost and changed-writer outcomes.

## Full prespecified coverage

| Coverage | Selected settings | Phase selections | Fixed fallback | Validation wins/ties/losses |
| --- | ---: | ---: | ---: | --- |
|delta4, all margins|316|98|218|478 /1398 /20|
|delta8, all margins|316|66|250|322 /1512 /62|
|delta16, all margins|316|33|283|160 /1698 /38|
|all helpers/margins|948|197|751|960 /4608 /120|

The full-grid signed validation range is -1.301% to29.752%, with zero overall
median. At margin0, all237 selections choose fixed mode; no positive-helper
phase vector fits the compulsory-miss lower-bound budget. At margin32 across
all three helper costs,66/237 training selections use phase mode; validation
gives324 wins,1062 ties and36 losses. All controls and negative effects remain
in the raw files and summaries.

## Interpretation and replay

The study extends the single positive-helper example to the unchanged79-case
design. It establishes concrete cost-aware phase opportunities and admission
behavior under supplied helper bounds. It neither measures helper latency on a
processor nor guarantees a performance improvement under changed writer timing.
It does not close a separate requirement for full native application speedup.
These deterministic configurations are not independent application samples, so
no statistical significance, confidence interval or application-level generality
is claimed.

Run `python -B run_grid.py`. `RESULTS.json` binds protocol/model/driver hashes and
retains all selected pairs; `VALIDATION_ROWS.csv` contains all5,688 timing points.
`candidate-records/` retains every training candidate and admission outcome;
`RAW_SCIENTIFIC_HASHES.json` binds each uncompressed canonical JSONL stream.
`PRIMARY_CASE_ROWS.csv` and `PRIMARY_VALIDATION_ROWS.csv` are views of the
predeclared primary, not a selection of favorable outcomes. The minimal archive
includes source/configuration, expected scientific hashes and these primary
views; full raw output is regenerated by the same script.
