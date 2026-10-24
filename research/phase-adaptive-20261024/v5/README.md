# Phase-adaptive HUSH v5

Download [phase-adaptive-hush-v5.zip](phase-adaptive-hush-v5.zip), extract it,
and follow README.md. SHA256:`cc27da33d4d27eb06925c8ae36c3a22913ed63467b0f5bb4d34cddc036a325b6`.

This self-contained bundle retains all v4 inputs, controls and expected
results and adds frozen configuration reuse under changed writer gaps
and tick phase. All3792 executions per policy meet unchanged reader bounds;
comparisons yield1168wins/2382ties/242losses. The fixed comparison is the
previously selected load/flush mask, not a retuned held-out optimum.

The new addition passes independent extracted replay, and56 prior
non-README inputs are byte-identical to verified v4. Read
[PAPER_INTERPRETATION.md](PAPER_INTERPRETATION.md) for the operating region,
all controls, negative results and the precise scope of the positive case.
Private HUSH overlays, manuscript and server configuration are excluded.
V4 and earlier versions remain immutable in sibling directories.
