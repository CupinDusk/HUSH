# Frozen-policy native transfer and period-256 timer check

126 new size cases and168 new producer-compute-gap cases, all294 valid,
1176 epochs. Protocols frozen before each new experiment. Original N16
training identities and0.1% same-offset guards are unchanged. Allseven
policies, alloutcomes, original-training reanalysis and labeled reused
gap4controls are in native-inputs.zip (60 text inputs). Its README,
METHODS and RESULTS describe the sharing program, controls, source/binary
bindings, counters, earlier exposure and exact interpretation. Gap means
arithmetic-loop iterations/store, not prescribed cycles.

Run python -B replay.py for four independent stdlib replay/check steps.
It verifies allscalars, signed comparisons, maxima and training selection.
No native simulator/compiler/executable or private overlay is included.
These observations do not prove a four-client WCET service bound.

period256 contains a9-bit constant external tick model, no additional
receiver state: correct one-step timer induction and three mutation
controls. All256 offsets and legal8-bit loads/counters are covered.
Run python -B replay.py --yosys /path/to/yosys to rerun allfour SATchecks.
The stored receipt used Yosys0.70+190485b63564. Ready-mask refinement
remains the original proof; this is not a full coherence/arbitration proof.

No author manuscript, reviews, host/account/credentials, binaries or private
implementation source are published in this package.
