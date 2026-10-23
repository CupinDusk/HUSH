# Amendment 01: explicit source ranges and matched cold build boundary

This amendment is written after attempt-001 generation and its passing
separately formulated producer checks. That attempt is retained unchanged.
It is not a new independent-role audit, and no performance collection occurred.
No input controller, target portfolio, period, policy, optimum objective,
schedule seed, Q, block count or result selection changes.

The initial record metadata bound full source/receiver/relation/epoch, complete
entry/key, all four prefixes/crossers and guards, but raw stream source ranges
and the exact guard source line receipt were not explicit enough. Attempt-002
adds a shared metadata source-evidence block: actual producer control stream
hash and range [0,4F); independent control stream hash and range [0,5F);
validated recurrence range [entry,entry+3d); receiver source hash and exact
numbered width/reset/horizon guard lines. All formats receive identical added
metadata. These bytes add overhead and do not change profile pair counts.
Source lines include the explicit P<=68 guard and 16-bit nonzero K field.

The cost source's cold boundary is clarified before any timing. Every method
starts from the same complete retained raw relation record plus the same frozen
source/expected-registry visibility and binding validation. It builds its own
required representation, serializes it, parses/validates the resulting complete
record, sets up the exact prefix, performs Q complete portfolio sweeps including
target projection/reset/dense target build, hashes results and cleans up. Raw
relation does not construct unrelated dense/master forms. Warm reuse retains
that method's prepared representation, with its precomputation separately
reported; query work still includes its necessary target projection and prefix.
The externally trusted expected registry holds all expected forms; loading and
validating that same registry/input is shared acquisition, not source-profile
extraction performed on behalf of the raw method. One warmup/nine paired blocks,
seed2026102306 and Q={1,4,16,64,256} remain unchanged.

Actual prefix bytes are JSON metadata value bytes (with separate crossing-flag
value bytes) in this schema. The equivalent uint32 triple payload is reported
only as a logical payload size; it is not claimed as the actual on-wire prefix
size. Complete record totals always count every metadata/header byte.
