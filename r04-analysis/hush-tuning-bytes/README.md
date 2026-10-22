# HUSH R04 posthoc tuning and encoded bytes

The producer completed the declared analysis of the unchanged R03 constructed two-line controller family. All 40 controllers and 37,000 correlated policy queries remain. The result is `PRODUCER_CHECKS_PASS_PENDING_SEPARATE_CHECKER`; a separately authored checker must pass the frozen protocol's independence gate before paper use. This directory does not supply native HUSH, arbitrary-payload coherence, hardware, application, traffic, energy, WCET, or timing evidence.

Within each controller's original `P=1..4p`, `K=1..5`, `phi=0..P−1` grid, the objective is the minimum `KP−1` ticks among strictly positive **complete** policies. This worst arm-to-expiry quantity is an explicit model retention proxy. The exact-service route and per-line tight `(C,J,A)` completion route use the same frozen physical prefix. Every optimum tie is retained; selection then uses K, P, phi in that order. Both feasible sets happen to be nonempty in all 40 controllers, and the code explicitly represents an empty set if one occurs.

Service minimizes this proxy more tightly in 21/40 controllers; 19/40 have no proxy gain. Gains of 0, 1, 2, and 5 ticks occur in 19, 7, 5, and 9 controllers. The mean gain is 1.55 ticks and median 1 tick; these are descriptive summaries of specified correlated controller cases. Admission totals remain the frozen 17,387 service and 16,948 completion positives, with 439 extras. Thirteen controllers have no extra admissions, and six others have extras but no improvement of the minimum proxy.

Pair counts decompose as follows. Grouping at full d stores 961 pairs; canonicalization deletes **zero**. Grouping after prospective support projection stores 838 pairs, a reduction of 123. Canonicalization at that prospective modulus deletes a further 73, leaving 765. Therefore the complete 196-pair reduction is not all attributable to canonical deletion. All line identities and exact physical prefixes remain.

The explicit binary format stores 40 full and 40 prospective records. Full records total 36,560 bytes and prospective records total 33,424 bytes: 3,136 bytes or 8.58% saved. The pair arrays alone fall from 15,376 to 12,240 bytes (20.40%). Each alternative also pays the same 21,184 bytes for headers, bindings, line metadata and 416 physical prefix triples. Thirty-three controllers save no bytes. Their zero outcomes remain; the per-controller saving median is zero and the unweighted mean saving fraction is 5.97% (different from the 8.58% aggregate byte ratio). This is one demonstration format, not a minimum encoded-byte result.

The producer strictly decoded all 80 records, compared all decoded fields, checked parsed structural sizes, and matched all 37,000 complete-query service slacks from **each** variant to the frozen literal phase bases. Its parser rejected the tested truncations, extra bytes, unknown magic/version and wrong epoch bindings; each prospective record rejected an out-of-portfolio P. The producer also compared direct full/projected group envelopes to canonical envelopes at 23,812 phase positions. These are self-checks pending the separate checker. No new source/controller execution or timing experiment was run.

The frozen R04 `PROTOCOL.json` is byte-exact. `PRECOMPUTATION_INPUT_BINDING.json` was written before the first derived computation and binds the five frozen R03 inputs plus all three producer source files. Those hashes are checked again after analysis. All inputs are read-only. The separate checker may add its own evidence without relabeling these producer checks as independent.

Files:

- `RESULTS.json`: aggregate counts and complete per-controller histograms.
- `TUNING_PER_CONTROLLER.json`: both optimum values, every tied policy, deterministic selected policy, frozen minimizer fields, empties and no-gain flags for every controller.
- `PAIR_DECOMPOSITION.json`: all four exact per-line pair arrays, projection/pruning counts and moduli.
- `SERIALIZED_RECORDS.json` and `records/*.bin`: all 80 exact records, lengths, hashes, overhead accounting and stipulated bindings.
- `ALL_QUERY_DERIVATIONS.jsonl.gz`: all 7,400 original frozen phase rows verbatim as arrays, including each original minimizer, plus all five K queries (37,000 total); zero/negative slacks retained. It is a deterministic gzip derivative, not a new workload collection.
- `PER_CONTROLLER_STATS.csv`: one raw derived row for every controller; no favorable subset.
- `encoder.py`, `decoder.py`, `analyze.py`: source, strict parser/evaluator, and complete analysis. The decoder does not import the encoder; they are nevertheless from the same producer.
- `SCHEMA.md`: exact field layout and query guard; `PAPER_READY.md`: narrowly scoped candidate prose pending independent checking.
- `MANIFEST.json`: file sizes/SHA256, frozen input hashes, precomputation binding hash, and limits of the checks.
- `verify_reproduction.py` and `REPRODUCIBILITY_CHECK.json`: same-producer rerun reproduced all 86 data files byte for byte; this is not independent validation.

From this directory with Python 3.12 or later, run `python -B -X utf8 analyze.py`. It reuses and verifies the existing precomputation binding, refuses changed producer/input bytes, and reproduces the derived outputs without measuring serialization time. `python -B -X utf8 verify_reproduction.py` additionally compares the 86 output hashes before and after the rerun; `python -B -X utf8 make_manifest.py` refreshes the file manifest. It does not rebuild frozen R03 inputs or rewrite the frozen R04 protocol. For a fresh isolated replay, copy the directory and preserve its relative `../../r03-analysis/hush-shared-controller/` input location. This directory is not published by this task.
