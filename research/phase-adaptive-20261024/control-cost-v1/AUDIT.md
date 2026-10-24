# Cost-aware controller admission

The protocol was frozen before execution. This reuses the unchanged model SHA
`6270a7fa1c79a81dab99f9712e170c60c1ded14dd5052f3b987ba421a1b99e10`:
BSQ, q=2, compute gap1, P=2, quiet512, writer gap4, 128 stores. The receiver has
dedicated slots. This is an analytical architecture-model experiment, not native
processor timing or a finite-cache application experiment.

The primary budget is 721 cycles, supplied as the fixed-mode bound689 plus32.
The prior budget690 is retained as an engineering zero-extra-headroom control.
Both budgets remain unchanged for all controller costs. The external deadline
constrains receiver work W, while the objective J is both-task completion.

Every phase candidate pays helper delta before each of the two noninitial
markers, whether or not the load changes, plus one cycle per changed load.
Thus `W=Cbase+2delta+M+S`, with Cbase=530. The fixed family pays no phase helper.
All591 distinct phase paths are tested: seven-valued 3-stage vectors plus all255
constant vectors. Fixed comparison exhausts255 loads and all four subsets of
free boundary maintenance, with free reader-end release for both families.
All3,975 candidate admission rows are retained. There are1,334 admitted candidate
executions at the largest budget and20 frozen-policy timing comparisons at the
two possible decrement phases. Every execution checks its service/hit contracts.

Selection is performed only at phi0. The selected mode, K and maintenance mask
are frozen before phi1. Fixed fallback is selected offline before paying any
phase helper cost; this is not a runtime recovery after overspending. The fixed
mode is preferred when joint completion ties. Natural changes in issue times
caused by inserted helper cycles are simulated; the protocol's no-retiming
restriction means no manual rescheduling to manufacture an outcome.

| B | delta per marker | Selected mode / K | W | C including helpers | M | S | J | WUs | Reader finish |
| ---: | ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
|721|0|phase254/4/4|690|530|159|1|806|7|677|
|721|1|phase254/4/4|692|532|159|1|806|7|679|
|721|4|phase254/254/4|698|538|159|1|815|8|685|
|721|8|phase254/254/4|706|546|159|1|815|8|693|
|721|16|fixed74|689|530|159|0|1103|40|676|
|690|0|phase254/4/4|690|530|159|1|806|7|677|
|690|1/4/8/16|fixed74|689|530|159|0|1103|40|676|

The shown selected outcomes are identical at phi0 and phi1. At B721, explicit
four/eight-cycle helper bounds retain26.1% joint-time reduction relative to the
best admitted fixed J1103. At delta16, the fastest admitted phase-mode candidate
is constant82, W721, J1130; the offline selector therefore chooses fixed74.
At B690 no phase-mode path is admitted for positive tested helper cost.
Overall the deployed policies yield10 wins,10 ties and zero losses across20
timing comparisons. The raw phase candidates, including the slower delta16
candidate, remain in `ALL_CANDIDATES.json` and selected phase details remain in
`CONTROL_COST_RESULTS.json`.

This establishes a concrete cost-aware operating point and fallback rule under
the supplied controller bounds. It does not measure those bounds on a CPU or
prove performance improvement for untested workloads, costs or timing contracts.
`SELECTED_ROWS.csv` separates analytical W/M/C from observed reader and joint
completion; the main-budget result should not be presented as using B690.

Replay with `python -B run_control_cost.py`. No external package is needed.
All original evidence and zero-headroom outcomes are preserved.
