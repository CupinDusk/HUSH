# HUSH source definitions, exact policy frontiers and formal-property reporting

This additive package contains new offline analyses of previously published research inputs. It includes no private simulator overlay, native binary, server configuration, credentials, manuscript or review. All original source and recorded-data bytes retain SHA256 and content-blob SHA1 provenance. The earlier R29 proof archive is referenced by immutable URL and member hashes rather than copied again.

With Python 3.12 or later and its standard library:

```text
python -B -X utf8 replay.py
python -B -X utf8 replay.py --output ./fresh-analysis
```

The bootstrap checks all top-level file hashes, safely extracts `analysis-inputs.zip` to a temporary directory, and runs three offline checks:

1. **All recorded native policy frontiers.** Four previously public CSV inputs contain 420 observations: 20 cache/size groups, seven policies and three offsets. An independent checker validates the paired anchor at every offset, recomputes all 140 policy objectives with exact `Fraction` arithmetic, checks all 980 ordered policy pairs, and rebuilds the complete frontier CSV byte-for-byte. The derived frontier is a posthoc summary of these recorded three-offset observations; it does not introduce new measurements or retune a policy. All signed outcomes and ties are retained.
2. **Four complete declared source paths.** Unchanged new reconstruction scripts replay FIR2DIM, IIR, matrix1 and complex_updates from the pinned, previously public C sources and source-order instrumentation. They reconstruct all 5311 global-data events, default numerical results, exact marker/shared/private counts and 96 conditional analysis maps. All stable expected tables are compared byte-for-byte. IIR's middle marker is f=2; matrix1's is k=5. FIR preparation/cleanup remains serial accounting outside the concurrent shared-cache history; it is not a physical change of an object's partition or address. See the ZIP's `source/expected/README.md` for the exact selected scopes, block geometry and supplied timing-input meanings.
3. **Formal-property reporting.** The public clarification defines the reference receiver, queue handshakes, modulo-256 ghost-counter invariant, event order, assumptions and conditional first-unblocked-edge progress. It binds the relevant original R29 public proof-source/log members. It introduces no new proof execution or claim. Optional prior-archive verification is available with `--previous-parameter-zip /path/to/parameter-proof-inputs.zip`. The earlier full-bank N=64/512 SAT timeouts remain unknown; arbitrary-line induction plus separately checked uniform product structure is reported distinctly.

The source timing model and empirical native frontend are separate evidence scopes. Compute/private/helper envelopes in the source analysis are supplied bounds; these scripts do not extract a platform WCET instance, run a native simulator, or compile C programs. The debit checker separates three abstract-horizon tests from three reachable executions of the unchanged published two-client cycle model. A miss fills at61, one WU is delivered at71, and K10/P10/offset1 yields uncancelled expiry161. Private delays90/91/92 produce reads160/161/162 and hit/miss/miss. The healthy analysis stays conservative; omitting private elapsed-time debit causes two concrete safety-assertion rejections. These are model tests, not native performance measurements.

The initial abstract-only checker and receipt remain author-side superseded evidence and are not included. The original v2 checker is retained byte-for-byte. Its temporary replay copy replaces only two historical superseded-file SHA lookups with the same literal digest values already recorded in the v2 receipt; `source/PORTABILITY_PATCH.json` specifies both substitutions and before/after script hashes. No oracle, analysis or simulation calculation is modified.

`PROVENANCE.json` and `PRIVACY_AUDIT.json` inside the ZIP document each input's published origin or new-analysis status and the exact-byte privacy scan. Original TACLeBench file headers and license notices are retained. The accompanying MIT license applies to the contributed research/analysis code and documentation; it does not replace an upstream file's own license notice.
