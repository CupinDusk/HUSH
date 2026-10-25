# Phase-Adaptive HUSH: service contract and phase sensitivity

The preceding pinned collection retains all earlier scientific bytes:
https://github.com/CupinDusk/HUSH/tree/590243dc4c2ac9a40fdda0f2a6bbeab9972339ca/research/phase-adaptive-20261024/revised-story-r44-v1

Run Python 3.12 with its standard library:

    python -B -X utf8 replay.py --quick

The default verifies every archive hash in a fresh directory and independently
reconstructs saved results. It runs no CXXRTL executable, compiler, native
simulator, cycle model, SAT solver, synthesis or STA tool. The service-contract
component retains the control projection, its explicit abstraction boundary,
state/edge checks and wait decomposition. The phase-sensitivity component
retains algorithm-derived paths, preregistered comparisons, returned-word
checks, all signed outcomes and separate build/execution records.
The compute-density component separately varies supplied validation-stage
compute envelopes on the original address path; these inputs are a
parametric sensitivity study, not measured CPU instruction timings.
Keep all reporting-inputs.zip.part-* files together. replay.py verifies
and concatenates them in a temporary directory, then verifies the complete
archive hash. Transport parts do not alter or omit any research byte.

The finalized execution ledger is:

{
  "cxxrtl_main_current": 10026,
  "cxxrtl_gates_current": 3,
  "cxxrtl_historical_executions": 0,
  "cxxrtl_executions_total": 10029,
  "cxxrtl_generation_attempts": 0,
  "cxxrtl_generation_successes": 0,
  "cxxrtl_generation_failures": 0,
  "cxxrtl_compile_attempts": 3,
  "cxxrtl_compile_successes": 3,
  "cxxrtl_compile_failures": 0,
  "sta_attempts": 0,
  "synthesis_attempts": 0,
  "native_cpu_executions": 0,
  "cycle_model_executions": 0,
  "formal_executions": 0,
  "control_reachability_runs": 1
}

CXXRTL executions, generation/build attempts, failures, and any separately
registered synthesis/STA attempts are distinct counts. A compiled RTL run
is not a native CPU benchmark or a gem5 execution. Final experiments and
gates remain separate from historical intermediate attempts. MANIFEST binds
every configured count to both SUMMARY and LEDGER through JSON pointers.

This release adds no gem5/native, scalar transaction-model or RTL-formal
executions. Control-projection reachability is counted separately and is
not a proof of the full RTL data path.
Historical and cumulative gem5/native attempts remain 8,325.
Earlier WI/native and matched-interface components remain in the preceding pin
and are not recounted. The new configurations vary one DSP algorithm; they
are not independent benchmark programs. Directed long-arm stress, if included,
is reported separately from those algorithm-derived configurations.
Functional, model, gem5, mapped-bank and wrapper timing evidence retain
their separately declared contract and platform scopes.

The service component includes one method-only TeX table/proof fragment.
No complete manuscript, peer-review report, private overlay, simulator binary,
credentials, SSH configuration or local server materials are included.
No earlier release is replaced.
