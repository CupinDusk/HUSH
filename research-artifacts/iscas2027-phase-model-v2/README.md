# Corrected current public-source/model reproducer v2

The repository owner explicitly authorized publication of this exact 25-input candidate on 2026-10-21. Preparation-time statements inside the immutable archive that publication was pending are superseded by this note. Archive SHA-256: `e2dd204df045d0889d089feca0448528490766a813e7ae34753d7720d9fa1a06` (70,212 bytes).

Unzip `hush-public-model-v2.zip`, then from its root run:

```text
python -B -X utf8 run_checks.py --zig /absolute/path/to/zig
```

Python 3.12 and Zig 0.14.1 are the verified environment. All 25 input hashes and four check suites passed again in a fresh extraction before publication. Five unchanged public MemTest functions are recompiled in explicit stubs; current read-boundary cancellation, policy-margin/witness checks, both-priority interval checks and a nonconstant-delay polling branch are included. Fixed expected outputs and the exact allowlist are inside the archive. Cross-path binary hashes alone are excluded from output identity, with generated source/events and all meaningful results still checked.

This corrects the earlier same-tick boundary interpretation: a successful read cancels a surviving same-tick WU, so a subsequent surviving arm is at least one integer tick after service. The old WU9/read21 miss interpretation is withdrawn; v1 remains immutable historical evidence. The aligned seed margin is at least p (2p for cache-edge seeds). The periodic example illustrates both lossless completion projection and required profile/history fallback at the same independent age query.

Only public upstream source with original notices and new author model/stub/check material is included. No private HUSH native overlay, manuscript, GPU results, server configuration or credentials were published. This is function-level/model reproducibility, not full gem5, native cache/hardware, data-coherence, whole-program correlation or application-performance validation. Existing repository and upstream licenses apply; no new license grant is asserted. OpenAI Codex assisted preparation.
