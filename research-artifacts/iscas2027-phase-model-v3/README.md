# Joint timing and mixed polling reproducer v3

Published with explicit human authorization on 2026-10-21. This release note supersedes preparation-time authorization wording inside the immutable archive.

Archive: `hush-public-model-v3.zip` (96,892 bytes).
SHA-256: `ccb4db5be9535595aad7e91202276e50e64ad60b076ad03506b5ff6fa8e03132`.
Inputs: 34 files plus the exact allowlist manifest.

Extract into a fresh folder and run with Python 3.12 and Zig 0.14.1:

    python -B -X utf8 run_checks.py --zig /absolute/path/to/zig

Fresh extraction and all six checks passed locally before publication. The archive includes pinned public gem5 source and explicit client stubs, the corrected complete read-boundary model, prior wait/slow-poll suites, the mixed-poll source driver, joint timing-witness checker, protocols, expected outputs and mathematical/source-premise explanations.

The new mixed suite retains all 216 reached callback/poll-tie contract rejections out of 588 configurations and executes all 372 admitted configurations (22,320 callbacks). The secondary joint audit checks 5,512 relations and 32,320 load/phase queries. The 118,083 raw mixed queries reduce to 28,581 distinct compared inputs; 165 certify with phase while both uniform and independent-interval comparisons return unknown. These are chosen finite grids, not workload frequencies. The minimal-load difference is mathematical, not a hardware-performance result.

Only five unchanged public client functions execute in declared packet/RNG/clock/event/port stubs. Cache response timing and queue receipt are source arguments; WU cancellation and expiry are declared receiver models. No native cache/queue/receiver, full-system coherence, application performance, area or energy validation is asserted. New analyses are secondary research, not external preregistration or unseen empirical tests. A full phase-history analysis attains the same precision.

No private HUSH overlay, manuscript, server material or credentials are included. Earlier v1/v2 releases and their limitations remain preserved. Upstream notices are retained, and applicable upstream/repository licensing remains in force. Codex assistance is disclosed in the archive.
