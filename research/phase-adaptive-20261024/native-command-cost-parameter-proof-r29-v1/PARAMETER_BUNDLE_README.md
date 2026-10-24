# Parameterized transport/receiver composition evidence

This additive evidence package extends the transport verification to the two mapped bank sizes through a symbolic arbitrary-line lemma and structural composition.

The recorded outcomes are deliberately separate:

- Full-bank N=4 temporal induction: proved; four mutation controls: counterexamples.
- Full-bank N=64 and N=512: each stopped after its 180-second limit and remains `timeout_unknown`.
- Arbitrary-line temporal induction at N=4, 64 and 512: proved; four N=4 mutations: counterexamples.
- Original kernel/reference dependency cones at all three sizes: all six checks show no cross-line state/read/WU dependence. The original loop bodies are also source-bound and checked to be uniform and N-independent; locality alone is not treated as functional equivalence.

The symbolic line index is unconstrained but time-invariant, and the original queue/K logic is retained. The lemma uses the unmodified kernel/reference at one line, whose original loop body is the same function for every line in the full bank. The checked product structure and this lemma establish the stated composition argument. This is never described as a monolithic SAT pass at N=64 or N=512.

Default standard-library integrity replay:

```text
python replay_parameter_bundle.py
```

Independent arbitrary-line SAT and structural rerun:

```text
python replay_parameter_bundle.py --yosys /absolute/path/to/yosys --output ./fresh-composition
```

Add `--full-bank` to attempt the separately reported monolithic diagnostic. An unresolved case returns nonzero and remains unknown. The ZIP contains all source, receipts, raw logs, per-process timing/memory records, the line-wise argument, manifest and MIT license. No external standard-cell library is required. No private simulator overlay, binary, manuscript, server configuration or local host path is included.
