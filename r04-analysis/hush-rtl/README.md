# New reference RTL for the R03 bounded receiver

This is a newly implemented synthesizable Verilog controller, **not historical/native HUSH**. Yosys read the RTL, prepared and checked its netlist, emitted CXXRTL, and the compiled generated model actually executed all frozen tests. The author run passed; independent validation and fresh portable rebuild are still pending the separately assigned checker.

The RTL contains the two sources, FIFO capacity two, R0/R1 immutable 8-bit captures, two valid bits and phased load/decrement/cancel counters. A clock edge advances one integer model tick. Configurations are fixed during each run. The tick order is WU, decrement, A/B polls, grant using entry R0 occupancy, old R1 emission, R0 transfer, callback. No equation computes a response deadline in the driver or RTL.

The unchanged prospective `PROTOCOL.json` is authoritative. Frozen public R03 inputs are copied byte-exact into `reference-inputs/`, bound by `REFERENCE_INPUTS.json`; `generate_vectors.py` only serializes their schedules/phase minima/independent counterexamples. It imports no producer, private simulator or native HUSH source. The driver includes **Yosys-generated** `netlist.cpp` and only drives/checks that model; it contains no independent controller state-transition implementation.

`build-01/RTL_RESULTS.json` records the actual author result:

- All 40 full control traces, 22,823 logical ticks, including detection plus two additional cycles, match every frozen normalized control key and ordered source/enqueue/grant/emission/block/transfer/callback event.
- All 37,000 one-WU minimum-edge queries execute from reset: 17,387 survive through h, and all 19,613 negatives first fail at the specified line/grant h with the independently recorded expiry. These runs executed 25,137,870 logical ticks.
- All 120 fixed data-word runs execute 68,469 ticks. Their 9,897 captures, 9,807 emissions, 9,657 timer cancellations and 1,071 backpressure ticks preserve matching request identity and byte snapshots; zero mismatches or RTL fault flags were observed.

Every case reaches FIFO occupancy two. Actual response backpressure occurs in 26 cases; 14 remain in the study without a backpressure stall. The separate state “R0 already occupied while a queue waits at grant” is not exercised in this bounded one-pending family; queue occupancy two is not evidence for that condition.

`CONTROL_TICKS.csv` and `DATA_TICKS.csv` expose the pre-tick normalized key, full ordered-event identities, WU input/acceptance, expiry/cancellation, line values, counter state and post-tick response-register identity/value. `CASE_CHECKS.csv` keeps every control/data run; `POLICY_CHECKS.csv` keeps all policies, expectations and observed first-failure/expiry/counts, including all negatives. Category 0 means no-WU control; category 1 means data-word controls, with pattern 0/1/2 = 0/255/(t*17+owner*73) mod 256. Case numbering follows `vectors-v2/VECTORS.json`.

Widths are explicit: tick/poll/request sequence fields 16 bits, K/counters three bits, expiry phase/period five bits, byte eight bits. All selected policy targets are at most tick 7,332, below the pre-simulation 65,000 limit; the DUT raises a sticky fault before unsafe tick/sequence arithmetic. It checks token conservation, two-token capacity, wait/poll consistency and counter-zero misuse on every admitted tick. Passing finite inputs is not a formal proof of every finite-width state or arbitrary unbounded operation. Invalid-configuration, overflow, hot-policy change and revocation recovery are not claimed as tested.

## Reproduce

Use Python 3.12, Yosys 0.70 (YoWASP 0.70.0.0.post1259 / git 28ba3cb92), and a C++17 compiler. Tool provenance and hashes are in `TOOLCHAIN_SOURCES.md` and `TOOL_HASHES.json`; no tool binaries belong in a public research package.

From a portable copy of this directory with external compatible tools installed:

```text
python -B -X utf8 replay_portable.py --out FRESH_OUTPUT --reference reference-inputs --yosys yosys --cxx c++ --include PATH_TO_CXXRTL_RUNTIME
```

For the existing local Windows wrapper and Zig, pass `--yosys-python-wrapper ABSOLUTE_PATH_TO_run_iscas_yosys.py --cxx ABSOLUTE_PATH_TO_zig.exe --zig` instead of `--yosys yosys --cxx c++`. `PATH_TO_CXXRTL_RUNTIME` is the include directory containing `cxxrtl/cxxrtl.h`. The script creates a fresh output directory, regenerates vectors, records actual commands and logs, synthesizes CXXRTL, compiles and executes it. It never removes a prior output.

The initial task-local execution used bundled Python `-B -X utf8 run_build.py --attempt build-01 --vectors .../vectors-v2`; exact executable paths and commands are retained in `build-01/BUILD.json`. Generated model, executable and raw result hashes are bound there and in `MANIFEST.json`. Build elapsed times are operational logs, not a performance comparison or hardware throughput measurement.

## Failures, scope and publication boundary

Initial vector generation failed because its default path pointed at a nonexistent R04 reference directory. The original source and diagnosis remain under `failure-01-generator-path/`; the empty `vectors-v1/` remains. Fix 01 changed only path resolution, then all vectors generated in fresh `vectors-v2/`. The first actual RTL synthesis, compile and execution succeeded; no adverse policy/case was removed and no favorable retuning occurred.

One-WU tests do not exhaust arbitrary WU words. The paper's conditional first-failure argument supplies its universal statement. The data study tests three bounded patterns with K=5/P=24/phi=0, WUs every tick only after each line's first capture; it is not arbitrary coherent-data validation. There is no full gem5/native-HUSH refinement, physical implementation, timing closure, area/energy/PPA, application result or hardware benefit here. Preserve these limits and all negative results in any paper-ready description. Paper/publication use additionally needs the independent checker and a fresh portable rebuild; none is silently inferred from this author run.
