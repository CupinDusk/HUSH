# R48 local phase-transfer analysis checks

This package preserves the original `check_analysis.py`, registered `PLAN.md`, original `SUMMARY.json`, and all four original CSVs byte for byte. It contains no paper, third-party paper PDF, credentials, simulator executable, or generated hardware. Python 3.12 or later and the standard library suffice.

## What 7,680,000 counts

The timer enumeration has **960 groups** = four old loads × four new loads × two Future/Cap modes × three post-WRITE WU options × ten tick phases. Each group combines ten old-arm edges × twenty WRITE distances, yielding **192,000 single-line timer trajectories** overall. Each trajectory supplies forty independent hypothetical read probes after WRITE, totaling **7,680,000 read probes**. A probe observes validity; it does not perform a read cancellation that changes later probes. Consequently these probes are neither independent application executions nor a traversal of all finite-cache/LRU states.

The historical CSV keys `joint_exact_H` and `joint_unknown_phase_H` are preserved. Within this particular script, those columns combine old/new timer-deadline conditions (exact known tick phase or conservative unknown phase); the word `joint` is **not evidence that the timer enumeration includes LRU state**. The explicit finite-capacity check is a separate, single seven-step two-way/three-address worked trace in `capacity-worked-trace.csv`. Its one H/two U classification and supplied analytical costs give 173 time units. The final timer-only classifier would falsely claim a hit after replacement. This is a worked counterexample and joint timer/residency demonstration, not exhaustive LRU proof.

`tail-pair.csv` is one separate paired reference-model example at specified delivery edges: Future has two WU transactions/one valid word application, Cap has one/zero. It does not measure a guest program, elapsed application time, physical bus latency or worst-case execution time.

The enumeration records zero unsafe claims for the two conservative timer classifiers and counterexamples for two incomplete classifiers over exactly the registered finite domain. A finite check and replay do not establish a general theorem, full receiver refinement, independent benchmark result or statistical acceptance probability. Source-level cost observations are in `SOURCE_COST_AUDIT.md`.

## Verify without altering originals

From an extracted package, run:

```text
python -B -X utf8 verify_replay.py --output VERIFY_REPLAY.json
```

The verification helper hashes all packaged inputs, creates a fresh temporary ZIP, extracts only the seven original scientific files into a new temporary directory, executes `check_analysis.py` **once**, compares all four generated CSVs and the generated summary byte for byte, and rechecks the original inputs. It does not execute gem5, RTL or hardware tools. A successful replay is **one additional verification model execution**, separate from the original **one scientific model execution** recorded in the unchanged summary. That historical summary's execution counter is not rewritten or reused as a claim about aggregate verification work.

`INPUT_MANIFEST.json` binds all payload files inside this package. The delivery directory's `SOURCE_CONFIG_LEDGER.json` additionally binds this ZIP and the externally produced `VERIFY_REPLAY.json`; the original files and original key names remain unchanged. The archive/receipt SHA values concern packaging and deterministic replay, not new scientific evidence.
