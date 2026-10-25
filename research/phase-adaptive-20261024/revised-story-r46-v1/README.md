# Phase-Adaptive HUSH: R46 supplemental evidence

This collection supplements the frozen [R45 controlled-memory-system evidence](https://github.com/CupinDusk/HUSH/tree/2ef3deacec7c23c723d63dc25f9483a78857e58d/research/phase-adaptive-20261024/revised-story-r45-v1).

It contains the concrete-to-control-state mapping and source-expression checks, and the compiled DSP deployment study with its registered configurations, saved outcomes, failures and result checks. The compiled program belongs to the same FIR/normalization/autocorrelation algorithm family; frame sizes are not independent applications. The controlled model's memory-service certificate is not transferred to the gem5 deployment.

Download all files in this directory and run `python -B -X utf8 replay.py --quick`. The default command verifies every input hash and independently checks saved source/graph/results. It does not compile a simulator, execute a CPU or RTL simulation, invoke formal tools, synthesis or STA, access a remote machine, or contact the network. Scientific execution counts in the manifest describe recorded original attempts, including retained failures; the replay adds no such attempts.

For method and scope details, inspect the extracted `service-mapping` and `compiled-deployment` component READMEs. The former separates the manual initial-state/transition-preservation argument from its automatic supporting checks. The latter records actual compiled workload and phase/maintenance costs separately from supplied simulation-interface costs. All signed comparisons and unsuccessful configurations are retained. Optional fresh re-execution requires the documented simulator/toolchain; compiled binaries and personal environment configuration are not distributed.

Code and evidence are public for reproducibility. This package contains no manuscript, author response or review report.
