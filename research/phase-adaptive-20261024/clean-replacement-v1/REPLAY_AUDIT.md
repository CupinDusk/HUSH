# Independent clean-replacement-v1 replay audit

Status: **PASS**. The explicit-file ZIP was extracted into a newly created,
separate directory. All four packaged entry points completed with return
code 0 using CPython 3.12.14 with assertions enabled and `-B -X utf8`.
No source or study-driver file was changed during replay.

- Archive: `clean-replacement-v1.zip`, 25200 bytes, 16 UTF-8 source/input files.
- Archive SHA-256: `aaab08c513db0cba36f60702c21776d53c7068152ec521af0000e6d0757ea95c`.
- Final replacement model SHA-256: `6270a7fa1c79a81dab99f9712e170c60c1ded14dd5052f3b987ba421a1b99e10`.
- Compared all 1,776 ordered scientific rows, all 26 fields per row
  (46,176 field entries), the exact summary and source bindings.
- Every non-`elapsed_seconds` field in the full regenerated result JSON
  equals the frozen reference. This comparison is stronger than a summary
  or hash-only check.
- Canonical rows SHA-256: `fdbb5cc78a0563d77496f449a0743f324dc4faca45081d251ccfa69396d766f8`.
- Both small checker outputs match the reference, excluding wall-clock
  elapsed time. Original-model parity passes in 48 configurations.
- The residency checker covers 1,278 reachable states and 15,336 edges;
  its WU-allocation, WU-touch and missing-expiry-cleanup mutants fail.

The replay records 1,344 synthetic and 432 FIR2DIM input-trace executions,
713 executions with clean replacement, 23,402 evictions, 62,032 predicted-hit
checks and zero unsafe hits or reader/service bound violations. The 436
carry-in/reset improvements compare the same policy and cache geometry.

The package is conditional on a clean shared-input receiver partition,
complete allocation declaration, WUs that neither allocate nor touch LRU,
stale-positive sharing after silent eviction, fixed authoritative writer
ownership, and known compute upper bounds. FIR2DIM contributes 145 ordered
input reads under a 64-byte-aligned three-line scenario. This is not a
complete native kernel trace or a native application budget-admission
result. The service bound is inherited under the stated model contract;
dirty writebacks and LLC behavior are outside its scope.

`PACKAGE_MANIFEST.json` lists exact packaged input hashes;
`EXPECTED_RESULTS.json` records canonicalization and compact expected outputs.
The UTF-8 publishing tree contains the source files plus compact manifest
and audit files. Full result JSON/CSV can be regenerated and are omitted.
