# FIR source-to-budget closure (R23)

This new directory closes the existing R22 FIR2DIM `c4-p1-h4` example. Prior
PDFs, source packages, measurements, and reviews are untouched. No server was
contacted and no native simulator or compiler was run.

The independently reconstructed source path contains 782 explicit global-data
accesses: preparation 93, body phases 148/444/4, cleanup 93. Body shared input
reads are 36/108/1, totaling 145; all remaining 637 accesses receive the supplied
private-service envelope. The retained instrumented C stdout and a separate
Python reconstruction of its source loops agree on every event, including
checksum14. This is not a fresh compiled-source validation. The scope includes
`fir2dim_main`, both `pin_down` calls and final checksum assignment, and excludes
`fir2dim_init` and the outer entry/return wrapper. It counts explicit global
source accesses, not every machine-level memory access.

| Component | Exact computation | Cycles |
|---|---:|---:|
| Comprehensive non-data compute (supplied per event) | 782×4 |3128|
| Private-data service (supplied per private event) |637×1|637|
| Noninitial marker helpers (supplied) |2×4|8|
| Registered configuration writes (model contract) |2×1|2|
| Common work |3128+637+8+2|3775|
| Carry shared service (derived H=139,U=6) |139×1+6×71|565|
| Complete carry work |3775+565|4340|
| Reset shared service (derived H=126,U=19) |126×1+19×71|1475|
| Complete reset work |3775+1475|5250|
| Execution-model complete receiver work, every phi0…9 |930 serial +3235 concurrent|4165|

Serial preparation/cleanup cost is 186×(4+1)=930, already included in the
complete totals. Carry versus reset saves 910 cycles (17.3333%) in the bound.
The 71-cycle unknown-read envelope is derived from the stated two-client
service premises: max(old-private1 + one-WU10 + own-miss60,
configuration-collision-residual1 + own-miss60)=71. Those mutually exclusive
branches are not added together. The envelope is conservative; no attainable
71-cycle witness or platform WCET extraction is claimed.

The same unchanged cycle model was freshly run for all ten deterministic tick
phases. Each observation has 4165 complete receiver cycles, 141 actual hits,
4 actual misses, 2 clean evictions, no unsafe predicted hit, and at most69
observed read-service cycles. These are model observations, not hardware
measurements. Reset changes only the analysis transfer at load changes, not
the physical execution policy, so there is one observed execution per phase.

For an externally supplied receiver-only budget B, carry admits iff4340≤B.
The *derived* integer interval4340…5249 admits carry and rejects reset; this is
not a predeclared application deadline or a fork/join deadline. No budget was
invented: `ASSUMPTIONS.json` leaves B null. The additional original c1-p1-h4 map
is checked as a second instance (1854/1994, observed1818).

`ASSUMPTIONS.json` makes the input boundary explicit: comprehensive compute,
private and helper upper bounds are supplied, not extracted from the platform.
The supplied compute/private envelopes must cover address/control/arithmetic,
instruction, stack and spill effects as appropriate; this artifact does not
certify them. Shared residency is analyzed in the existing disjoint clean
partition with one set/two ways/64-byte blocks. It does not infer a cache
partition or a native four-client service contract.

## Replay and checks

Run with bundled Python3.12 `-B -X utf8` in this directory:

```
python -B -X utf8 emit_certificate.py
python -B -X utf8 check_certificate.py
```

`prepare_inputs.py` is a provenance-preserving staging helper that reads the
old R22 public source bundle and writes only here. Normal replay needs only
the staged inputs. Do not run `run_sensitivity.py` here for this certificate;
it is an unchanged hash-bound provenance copy of the original map generator.

`emit_certificate.py` uses the byte-exact original analysis and execution
model. `check_certificate.py` imports neither that model nor the emitter. It
independently reconstructs source loops and checks all580 shared-read decisions
(145×carry/reset×2 maps) with absolute expiry deadlines and distinct-reference
reuse distance. It checks every component, serial subtotal, per-stage count,
service-envelope arithmetic, and the 20 newly emitted observations against
the frozen record. It is an independent transfer/accounting implementation;
execution observations use the unchanged original simulator, not a second
independent simulator. Shared premises and source scope remain assumptions.

Eight falsification checks reject an increased H count, a one-cycle-smaller W,
substituted reset transfer, deleted private event, changed service assumption,
omitted helper costs, flipped hit bit, and altered observation. These checks
are specific consistency tests, not exhaustive soundness proofs.

- `CERTIFICATE.json`: input/map hash binding, source counts, both analyses,
  every shared-read prediction and all20 execution records.
- `CHECK_REPORT.json`: independent transfer details, stage totals, boundary
  transfers, and all mutation outcomes.
- `PRIMARY_EVENT_LEDGER.csv`: every one of the782 data events with compute,
  private/shared charges, time, rho states and shadow stack.
- `BOUNDARY_WITNESS.json`: six consecutive source/marker events242…247 around
  the first load change, plus both full boundary transfers.
- `MANUSCRIPT_SNIPPET.tex`: four-row table, exact paragraph, and recurrence.

At marker1, rho[0,1]=[2479,2519] at t1345; debit helper4, cap to150, then
debit write1 gives[149,149] at t1350, with shadow[1,0] unchanged. Two private
events debit5 each, then the shared block0 event debits compute4 to[135,135].
It is a guaranteed hit; shadow becomes[0,1], rho0 reloads to150, and one-cycle
service leaves[149,134]. The cap updates conservative analysis state, not
the running hardware timers. Exact implementation order is included in the
witness and manuscript snippet.

This minimum source distribution regenerates CERTIFICATE.json,
CHECK_REPORT.json, BOUNDARY_WITNESS.json and PRIMARY_EVENT_LEDGER.csv with
the two commands above; generated large outputs are not committed.
prepare_inputs.py is not needed or included in this portable distribution.
