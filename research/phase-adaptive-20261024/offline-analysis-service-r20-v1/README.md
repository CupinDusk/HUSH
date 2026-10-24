# Offline bound cost and two-client service cases

This package supplements the existing bounded two-client analytical model.
It does not run gem5, contact servers, or infer processor WCET.

Run on 64-bit Windows Python3.12:

```
python -B -X utf8 profile_bound.py replay
python -B -X utf8 profile_full_selection.py replay
python -B -X utf8 probe_service71.py
python -B -X utf8 check_service_cases.py
```

`profile_bound.py` calls only the unchanged abstract-bound transfer for
1,611 candidates and three supplied paths. The execution simulator is
disabled. All4,833 results are checked against a lossless reduced copy of
the original frozen bounds in EXPECTED_BOUND_ROWS.zip. The timer excludes
verification and serialization. Process memory includes Python/runtime,
prepared inputs and retained results, measured by GetProcessMemoryInfo.
The expected-results ZIP is read after memory capture.

`profile_full_selection.py` reruns all4,833 original analyze+simulate
training evaluations and minimum-training-joint selection. Its three
fresh-process runs take a median5.249543s and at most25.140625MiB absolute
process peak working set. All full candidate observations exactly match
EXPECTED_FULL_TRAINING.zip. Reference loading and checks occur after the
measured window. This complete-search cost is separate from the0.170s
bound-only cost. No held-out or native execution is included.

PROFILE_SUMMARY.json records the final three serial fresh-process runs4–6.
Initial runs1–3 used a nonportable old-location verification read and are
also retained. They used the same timed algorithm; the final script reads
the portable expected-results ZIP after the measurement window.

The unchanged service tracer produces61/70/61-cycle directed reads.
check_service_cases.py checks both the ordinary71-cycle envelope and the
configuration-collision61-cycle envelope. The latter has one remaining
WU cycle, with no simultaneous private store. The arithmetic envelope
does not assert that71 is attained or constitute an exhaustive proof.

EVIDENCE_REPORT.md contains detailed time lines, input examples, source
bindings, exact scope and draft manuscript sentences. Old experiment
outputs are not modified. No private simulator source/binary is included.

## Public export and portability

Original timings and scientific records are preserved. Only the executable
identity field is reduced to a basename in public bound-profile JSON. The
original independent-run transcript is excluded; a new clean replay audit
is supplied. RAW_TO_PUBLIC_MAPPING.json records relative names and hashes,
never local account paths. Source hashes in historical timing records bind
the original script; the mapping binds these public wrapper changes.

The public profilers use platform_memory.py. Wall timing and scientific
checks run on other operating systems; Windows process-memory values are
explicitly unavailable there and no substitute metric is reported.

The public source requires its bundled expected-results ZIPs and does not
read the original local experiment tree. Python startup/import, expected
record loading, checks, and output serialization remain outside timing.

## Text-only distribution

The two recorded archives are distributed as `.zip.b64` text. The standard-
library recorded_data.py loader verifies archive SHA256, requires exactly
one allowlisted JSON member, rejects absolute/traversal/symlink names and
limits the member size. It writes only recorded-data/EXPECTED_BOUND_ROWS.json
or recorded-data/ALL_CANDIDATES.json, then parses JSON. It never executes
archive contents. Decoding and verification remain outside timing windows.

No whole-package ZIP, old independent-run transcript or old self-referential
manifest is copied into this text tree. FILE_SHA256.json lists payload files
without hashing itself. PUBLIC_TEXT_REPLAY_AUDIT.json records a new clean
directory replay; historical timing observations remain unchanged.
