# Run this compact research export

Run `python -B -X utf8 replay.py`. It losslessly decodes the standard ZIP/base64
recorded-data file, restores the original LF JSON/CSV inputs and expected outputs,
runs the analysis below, and checks every scientific output SHA256. This text
transport keeps complete candidate/measurement records available without a large
plain JSON upload. The data are unchanged; no account, binary or private overlay
is included. Only the Python standard library is needed for recorded-data replay.

# Complete FIR2DIM timing-envelope sensitivity

This is a deterministic sensitivity experiment for the complete source-event
accounting used in the HUSH phase-adaptive analysis. It answers R17 reviewer 1's
request to vary supplied computation, private-data service, and control costs.

The protocol was frozen before the 24-cell run. The original TACLeBench source,
instrumented source, 782-event trace and execution-driven model were copied
byte-for-byte from R14; their hashes are in `PROTOCOL.json`. The selected source
entry is `fir2dim_main`, including both preparation/cleanup `pin_down` calls and
the checksum assignment. The source's initial setup function and outer return
wrapper are outside that entry. The upstream license notice is retained.

## Design and accounting

The full factorial grid is non-data cost C={1,4,16,64}, private-access cost
V={1,4,16}, and noninitial marker cost delta={4,8} cycles. The 24 cells share
K=(254,16,1), P=10, a clean one-set/two-way 64-byte receiver partition, and the
same 192-store refresh co-runner with gap 4. No policy or deadline is selected
from these results. Each cell executes all ten decrement phases.

Of 782 explicit global source data accesses, 145 read the concurrently shared
input partition and 637 use the supplied private service cost. The complete
work accounting adds 782*C + 637*V + 2*delta + 2 configuration-write cycles to
the analyzed shared-memory cost. Preparation and cleanup each contain 93 data
events, execute serially around the concurrent body, and are charged identically
in both analyses and in the execution model. Compute costs represent the
supplied comprehensive non-data timing envelope, including computation, control,
stack and instruction service; they are not derived from host instrumentation.

Carry and reset use the **same physical phase policy** and all the same costs.
They differ only in whether safe retained expiry state is transferred across
phase boundaries. Therefore the measured outcome here is a tighter analytical
receiver-work bound, not runtime acceleration between different executions.

## Results

All 240 model executions satisfy their carry receiver-work bound and every
predicted hit is safe. Carry gives a strictly tighter complete bound in 18 of
24 cost cells and the same bound in the other 6. The tested C<=16 cells all
retain a positive difference; C=64 makes carry and reset equal in this grid.
Across the positive cells the decrease is 70--910 cycles (0.41--17.33%).

Representative complete receiver-work bounds:

| C | V | delta | Reset | Carry | Decrease | Model receiver work, all 10 phases |
|---:|---:|---:|---:|---:|---:|---:|
| 1 | 1 | 4 | 1,994 | 1,854 | 140 (7.02%) | 1,818 |
| 4 | 1 | 4 | 5,250 | 4,340 | 910 (17.33%) | 4,165 |
| 4 | 4 | 8 | 7,519 | 7,449 | 70 (0.93%) | 6,085 |
| 16 | 16 | 8 | 30,637 | 30,217 | 420 (1.37%) | 23,104 |
| 64 | 16 | 8 | 68,243 | 68,243 | 0 | 60,639 |

For example, the original map admits this receiver-only phase policy at integer
budgets 1,854--1,993 under carry while reset requires at least 1,994. At C=4,
V=1, delta=4, the corresponding interval is 4,340--5,249. These intervals state
the exact admission difference without inventing an application deadline.
They do not constrain the co-runner's completion or imply a fork/join deadline.

All 24 cells are in `COST_GRID.csv`; all 240 deterministic executions, including
joint completion, are in `EXECUTION_GRID.csv` and `RESULTS.json`. The ten tick
phases are an exhaustive timing axis, not independent statistical replications.

## Reproduction

Run `python -B -X utf8 run_sensitivity.py`. Only the standard library is needed.
The driver checks every immutable input hash and all model safety assertions.
`EXPECTED_SCIENTIFIC_HASHES.json` binds the three deterministic result files.
The separately extracted replay must reproduce their bytes exactly.

`check_source_extraction.py` is an optional additional check. It recompiles the
unchanged original and instrumented C files using a compiler argv supplied in
`HUSH_C_COMPILER_JSON` (default `['cc']`); both must return zero and the newly
emitted source events must match `ALL_DATA_TRACE.json` exactly. Compilation and
printf instrumentation are not used as timing measurements.

These are supplied timing envelopes in the existing two-client architecture
model. A concrete processor budget additionally requires independently valid
compute/private service bounds and its matching cache/service contract. The
results here support the analysis sensitivity claim, rather than a processor
WCET certification or native application speedup claim.

## Git LF export

This copy normalizes text line endings and deterministic result serialization to LF. Input byte hashes are updated in the protocol; `git_lf_export` retains the original protocol hash. Scientific metrics and every candidate/execution are checked equal to the original experiment before independent replay.
