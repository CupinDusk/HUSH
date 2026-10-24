# R22 recorded native sensitivity replay

Run `python -B replay.py` with Python3.10 or later. Standard library only; no simulator, network, private source or native binary is included. This checks recorded data, bindings,72 checksums/288 epoch sums,24 matched conditions and10 aggregate rows including the separately labelled18 existing baseline measurements. It does not rerun native simulation.

72 new preregistered conditions: N32, both32/64KiB, frozen fixed K3/106 and phase(1,128,1)/(1,128,128), matched suppression; settings(P64,cost8),(P256,cost8),(P128,cost0),(P128,cost16), offsets0/P//2/P-1. All outcomes remain.64KiB phase is an undeployed diagnostic. P64/P256 deliberately transfer frozen K outside its P128 profile; no retuning. Cost is guest helper quiesce cycles per changed noninitial stage, not a changed bus service gate or native controller/WCET measurement.

MEASUREMENTS.json retains normalized72 records, full selected native counters, markers, checksums and epoch deltas with hashes binding original records/stdout. BASELINE_MEASUREMENTS.json is the18 preexisting P128/cost8 rows; it is not new data. PAIRED.csv supports per-offset plotting; AGGREGATES.csv reports independent maxima of J and WU over the three offsets. J is ROI ticks/1000 at1GHz. Conditions are deterministic, not stochastic replications or all-offset worst cases.

The negative P64/32KiB result is deliberate and retained: max WU fixed506 versus phase1941 (phase/fixed3.836), while phase is0.04977% faster. P256/32KiB cuts WU14.818% but is0.03618% slower. Therefore traffic benefit depends on timer period and frozen-plan compatibility. No WCET, whole-cache RTL equivalence or general speedup follows.

No raw host logs, private paths, accounts, overlay source or executable files are included. Protocol binds its original preregistration SHA256. FILE_MANIFEST.json checks all other package files.

The large measurement JSON is stored losslessly as gzip/base64 text.
replay.py decodes it, verifies the original SHA256 and runs the same checks.
No scientific bytes or outcomes were removed. plan_loader.py --self-check
also verifies18 profile/encoding cases; it emits arguments only for exact
P/cache/ways/line/core/clock/gate/helper profiles and rejects mismatches.
These plans are empirical-native records, not WCET admission certificates.
The transfer diagnostic intentionally bypasses deployment of a mismatched
profile; original P128 plans were not retuned for the P64/P256 results.
