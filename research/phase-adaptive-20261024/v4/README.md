# Phase-adaptive HUSH v4

Download and extract [phase-adaptive-hush-v4.zip](phase-adaptive-hush-v4.zip),
then follow its README. SHA256: `2d4f1aba078c27044ec58e82b88b6cd1fd201d619de4a9244c4c520058046aa2`.

The frozen bundle includes all v3 model/kernel/receiver inputs, expected
outputs and replay commands, plus the nonzero runtime helper-cost study.
Readable inputs are mirrored in source/; run from the extracted bundle
to obtain expected/. V3 remains immutable in the sibling v3 directory.

At helper costs0/4/16/64 cycles per noninitial marker, the runtime policy
has60/160/20,70/10/160,40/0/200,40/0/200 wins/ties/losses among240 runs
against fixed with free maintenance. All960 retain the original reader
bound; worst makespan regression93.7%. Admission protects the conditional
reader deadline, not execution speed. These are declared bounded costs,
not measured processor latencies.

The new study passes independent extracted replay with every scientific
field matching; all 53 other non-README v3 inputs remain byte-identical
to the previously independently verified bundle. Private HUSH overlays,
native server materials, the manuscript and credentials are excluded.
