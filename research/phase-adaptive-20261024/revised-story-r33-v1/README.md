# Phase-Adaptive HUSH: bounded phase control and complete source-task study

This pinned research entry contains the new local phase controller and the complete source-task analysis. It supplements the [earlier R32 reproducibility index](https://github.com/CupinDusk/HUSH/tree/277e6737efd0e1fc0b6255c469c66790c4d38ac0/research/phase-adaptive-20261024/revised-story-r32-v1), which retains the native observations, four kernel paths, historical proofs and every earlier outcome. All earlier files and results remain unchanged.

With Python 3.12+ and the standard library:

```text
python -B -X utf8 replay.py --quick
python -B -X utf8 replay.py --full --output ./verified-full
```

The default/`--quick` check verifies every member hash, source/scalar/path contracts, registered candidate coverage, C/W formulas, scientific reductions, frozen validations, RTL proof/mapping log bindings and the preserved unknown proof outcome. It **does not rerun the source timing simulations, a native simulator, SAT or mapping**. `--full` additionally repeats the registered source simulations in fresh temporary directories; these can take several minutes. Both modes run offline. Choose a new output directory to export the check logs and receipt.

## Contents and evidence scope

`source/` preserves the complete v1 source-task study, its eleven fixed selections/five infeasible cases, worked lifetime/LRU transfer and planner audit. The separate v2 preregistration varies two source-supported writer-pass inputs and two clean partition capacities in a 2x2 design. It reuses the exact frozen v1 baseline and retains all three new groups, all candidates, budgets and validation outcomes. The source algorithm and timing model are unchanged. Computation/private-service/call envelopes are supplied analysis inputs, not extracted platform-binary WCETs. Source reconstruction and two-client cycle-model results are distinct from native gem5 measurements. See its protocol, manifest and README for complete inputs and results.

`control/` contains the three-byte descriptor bank, sequencer and reader fence with the original queue/receiver, formal scripts, matched configurable-once baseline and Nangate45 mapping. The accepted-event contract is two cycles for unchanged loads and three for changed loads (delta_hw=2, Lsw=1), adding 38 state bits. Controller/transport induction passes N=4/16/32/64/512; full-bank receiver composition passes N=4. Full N=16 SAT timed out and remains unknown; N=32 full-bank SAT was not attempted. Phase acknowledgment is neither queue emptiness nor global write completion. The enclosing coherence controller waits for required deliveries; the physical data array must apply/forward the delivered WU before local capture. Data arrays, LRU, owner state, tick and CPU event generation are outside this local block. The original 44-file public v1 control evidence remains byte-exact in the v2 supplement.

The inherited index includes 4224 earlier native runs plus 84 changing-value correctness cases (4308 total); this new supplement executes **zero additional native cases**. No native implementation overlay/binary, private source excerpt, server configuration, manuscript or reviewer material is included here. Upstream notices and the public library provenance are retained; contributed code does not replace third-party licenses.
