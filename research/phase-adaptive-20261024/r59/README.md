# Positioned caller-time analysis

The archive contains the complete 18-case phase-caller sensitivity study, source bindings, ordered timer/LRU analysis, version observer, regression and deterministic offline verifier.

After extraction, run `python -B -X utf8 verify.py`. Caller time is advanced at its program position before reclassifying reads and charged once in the path bound. All outcomes and an additive-only mutation control are retained. These are independent two-client event-model results; they do not replace compiled RTL timing or four-core gem5 data. No peer reviews, manuscript or server material is included.
