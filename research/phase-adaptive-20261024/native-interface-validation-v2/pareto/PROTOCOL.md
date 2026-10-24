# Exploratory complete-program Pareto analysis, followed by frozen replication

The R14 native216-row N8 training table is already available; this analysis is
exploratory and will be identified as such. No N20/N24 native timing exists.
Compute the complete fixed/phase Pareto fronts for two actual metrics:
whole-worker-region completion J and maximum completion of three consumers R.
Compare every nonconstant phase plan with all five constant loads. A fixed
point is feasible at Rphase when Rfixed <= Rphase; choose its minimum J.
Select the phase with greatest fractional J reduction in that feasible set,
requiring a strict positive reduction and deterministic lexical tie breaks.
If no fixed point meets Rphase, classify it separately and do not call it a
speedup. Keep all25 training points for all8 settings, not only positive ones.

Before first N20/N24 timing, freeze one selected phase for each setting with
a valid improvement. Replicate the selected phase (changed-load stall8) and
allfive fixed loads on N20/N24. Primary endpoint is whether the frozen phase
lies beyond the measured fixed Pareto front and its J reduction at the same
or smaller measured consumer completion. Retain all outcomes, including
regressions and absence of Pareto improvement. The constraint is measured
consumer latency, not certified WCET; the static proof remains separate.
If training shows no improvement, stop with the full exploratory record.
Do not change workload, core/cache, producer or costs after this protocol.

Before N20/N24 timing, ten additional fixed controls128/256/768/1024/1536/2048/3072/8192/16384/32768 strengthen the baseline to15 values. This does not change frozen phase choices. Compare against all15 as a robustness endpoint as well as the originalfive.
