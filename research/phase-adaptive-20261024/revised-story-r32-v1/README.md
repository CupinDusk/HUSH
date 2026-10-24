# HUSH unified artifact entry: native reporting, FIR plans and versioned correctness

This is the current entry point for the new R32 portable checks. It combines exact reductions of previously public native observations, a registered conditional FIR plan comparison, and the sanitized evidence for 84 new changing-value native correctness cases. The five-file bundle contains no manuscript, accepted-paper PDF, reviewer material, private source excerpt, simulator overlay/binary, server configuration or credentials.

With Python 3.12 or later and its standard library:

```text
python -B -X utf8 replay.py
python -B -X utf8 replay.py --output ./verified-results
```

The bootstrap verifies all file/member hashes, safely extracts to a fresh temporary directory, and runs the checks below. Replaying invokes no native simulator, compiler, network command or SAT engine. It repeats 3128 small conditional model executions, typically taking several seconds. The optional output directory receives verified results. Both native and FIR changed-input rejection tests run by default.

## Current offline checks

**Native reporting (`analysis/native-reporting/`).** All nine scientific output files, plus the public reduction receipt, reproduce byte-for-byte. These include nine absolute Table II time rows, an independent separable-FIR scalar reference, retained checksum checks, and every exact tolerance interval for 420 observations/140 candidates in 20 cache/N groups. All 1278 distinct Table II A/B records match the numerical reference. The broader endpoint audit distinguishes 1680 unique later numerical records from 2457 older reduced valid/normal-exit records; 87 of the historical 4224 records are outside that endpoint audit. Raw stdout bytes are absent from those reduced inputs, so this is not a fresh stdout or numerical recheck of all 4224.

The exact primary Phase preference ranges are `[2700/46897,181800/797249)%` at N20 and `[2500/1423221,45600/474407)%` at N26. At eta=0.1%, N20 selects Phase and N26 selects suppression among the seven recorded controls. All intervals, empty cases, negative excess values and undeployed 64KiB diagnostics remain. These descriptive thresholds are not application deadlines, a new deployment selector, or optimality over unmeasured plans/offsets.

The public copy omits only the redundant private manuscript-format substring check and replaces a private source-package audit with numeric historical context. Raw measurement-to-public-summary comparisons remain intact. All nine scientific outputs match the original study. The public receipt explicitly records its own changed script/input-binding hashes and 25 checked inputs. `analysis/PORTABILITY_PATCHES.json` records exact substitutions, original/public hashes and the three receipt provenance differences.

**Registered FIR source-plan study (`analysis/fir-study/`).** The replay repeats all 2712 candidate executions and 416 frozen fixed/fallback validations under the unchanged registered protocol, original public model and source-address inputs. Candidate CSV, choices and validation CSV match exactly. All stable RESULT fields match; `elapsed_s` is excluded openly, and the runner hash identifies the declared filesystem-anchor patch. This is a bounded two-client model with supplied timing maps, not native execution or target-binary WCET extraction.

All 13 feasible map/budget pairs choose fixed mode; three admit neither mode. At c4/p1/h4, B=4250, fixed K25 has C3765/W4190/J4155/WU104, while Phase (32,32,1) has C3773/W4199/J4164/WU104. At c1/p1/h4, B=2000, fixed K15 has C1419/W1844/J2180/WU70, while Phase (16,16,1) has C1427/W1853/J2186/WU71. No phase speedup is claimed. B constrains receiver completion, so joint completion can exceed B. Fixed exhausts all 255 loads and four free flush subsets; Phase uses the registered 336 nonconstant triples and pays its helpers/changes. Losing candidates and infeasible budgets are retained.

`HELPER_COUNT_CORRECTION.json` preserves the initial string-zero helper-count error and unchanged protocol hash. The corrected runner uses integer phase IDs and asserts two noninitial helpers. The initial attempt's scientific CSVs, choices, RESULT, protocol and runner remain byte-exact under `superseded-v1/`; its old prose README is represented by its original hash. Superseded outcomes are separate from current results and are not rerun by the bootstrap.

**Versioned native correctness (`analysis/probe/`).** All 15 original sanitized public files are preserved. The offline checker validates complete 84-case coverage, bindings and retained endpoints: 10483200 comparisons, 3440640 changing-version stores, and zero regressions, range errors or final-value errors. These are seven original policies, three offsets, N16/N32 and 32/64KiB. The runtime guest checks were performed once per case; the replay validates their retained evidence without reobserving individual loads. This is neither an all-interleaving proof nor a performance experiment. The historical native count is 4224 prior runs plus 84 correctness cases, or 4308; the two evidence scopes remain distinct. Native re-execution requires the compatible implementation identified by its hash and is outside this bootstrap.

## Earlier artifacts and mechanism context

The immutable [R31 research index](https://github.com/CupinDusk/HUSH/tree/8d81b3346bd7716af5f597f50babff823a79d9dc/research/phase-adaptive-20261024) retains the earlier evidence. Select the artifact matching the claim:

| Claim or check | Pinned earlier artifact |
|---|---|
| Original exact native frontier/training metric audit | [native-metric-audit-r31-v1](https://github.com/CupinDusk/HUSH/tree/8d81b3346bd7716af5f597f50babff823a79d9dc/research/phase-adaptive-20261024/native-metric-audit-r31-v1) |
| Complete declared source paths and formal reporting | [source-contract-frontier-r30-v1](https://github.com/CupinDusk/HUSH/tree/8d81b3346bd7716af5f597f50babff823a79d9dc/research/phase-adaptive-20261024/source-contract-frontier-r30-v1) |
| Native command-cost records and receiver/transport proof evidence | [native-command-cost-parameter-proof-r29-v1](https://github.com/CupinDusk/HUSH/tree/8d81b3346bd7716af5f597f50babff823a79d9dc/research/phase-adaptive-20261024/native-command-cost-parameter-proof-r29-v1) |
| Native all-offset/new-size records and transport | [native-robustness-transport-r28-v1](https://github.com/CupinDusk/HUSH/tree/8d81b3346bd7716af5f597f50babff823a79d9dc/research/phase-adaptive-20261024/native-robustness-transport-r28-v1) |
| Earlier FIR source-address model and budgets | [budget-tradeoff-r23-v1](https://github.com/CupinDusk/HUSH/tree/8d81b3346bd7716af5f597f50babff823a79d9dc/research/phase-adaptive-20261024/budget-tradeoff-r23-v1) |

Configurable timer/cache analysis and runtime protocol adaptation have predecessors: [PENDULUM*, DATE 2024](https://doi.org/10.23919/DATE58400.2024.10546818) and [CoHoRT, DATE 2025](https://doi.org/10.23919/DATE64628.2025.10992758). This supplement makes no first-adaptation claim. Native observations, the conditional clean-cache memory bound and the receiver/transport correspondence have separate contracts.

Original input bytes and the earlier contributed-code MIT notice are retained. The accompanying license applies to contributed analysis code/documentation and does not replace an upstream notice. No external code was added. `analysis/PROVENANCE.json` and the outer manifest bind every bundled file to its prior-public input or new registered-analysis status.
