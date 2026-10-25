# Phase-Adaptive HUSH: matched RTL execution evidence

The preceding pinned collection retains all earlier scientific bytes:
https://github.com/CupinDusk/HUSH/tree/75c45061e8765ccf6694ab25b3b4e5d224c16736/research/phase-adaptive-20261024/revised-story-r43-v1

Run Python 3.12 with its standard library:

    python -B -X utf8 replay.py --quick

The default verifies every archive hash in a fresh directory and independently
reconstructs saved results. It runs no CXXRTL executable, compiler, native
simulator, cycle model, SAT solver, synthesis or STA tool. The matched-rtl
component retains source/protocol/tool bindings, registered experiments,
final gates, failed intermediate executions and separate build records.

The finalized execution ledger is:

{
  "cxxrtl_main_current": 2272,
  "cxxrtl_gates_current": 14,
  "cxxrtl_historical_executions": 33,
  "cxxrtl_executions_total": 2319,
  "cxxrtl_generation_attempts": 13,
  "cxxrtl_generation_successes": 12,
  "cxxrtl_generation_failures": 1,
  "cxxrtl_compile_attempts": 12,
  "cxxrtl_compile_successes": 12,
  "cxxrtl_compile_failures": 0,
  "synthesis_attempts": 0,
  "sta_attempts": 0,
  "native_cpu_executions": 0,
  "cycle_model_executions": 0,
  "formal_executions": 0
}

CXXRTL executions, generation/build attempts, failures, and any separately
registered synthesis/STA attempts are distinct counts. A compiled RTL run
is not a native CPU benchmark or a gem5 execution. Final experiments and
gates remain separate from historical intermediate attempts. MANIFEST binds
every configured count to both SUMMARY and LEDGER through JSON pointers.

This release adds zero gem5/native, cycle-model or formal executions.
Historical and cumulative gem5/native attempts remain 8,325.
R43 WI/native components remain in the preceding pin and are not recounted.
Functional, model, gem5, mapped-bank and wrapper timing evidence retain
their separately declared contract and platform scopes.

No manuscript, peer-review report, private overlay, simulator binary,
credentials, SSH configuration or local server materials are included.
No earlier release is replaced.
