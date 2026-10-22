# Independent author-side HUSH R04 arithmetic and encoding audit

Result: **PASS_INDEPENDENT_AUTHOR_SIDE_ARITHMETIC_AND_ENCODING_CHECK**. This is a separate author-side checker, not an external review, a new controller execution, or a new workload experiment. The frozen R04 protocol and the 97 producer manifest payload files were read without modification. All checker outputs stay in this `independent/` directory.

`check_independent.py` uses only the Python standard library. It never imports or executes producer analysis, encoder, decoder, replay, or R03 extraction functions. It reads their bytes only to verify the declared hashes. It starts from the frozen R03 literal prefix/cycle event triples, original phase rows, frozen protocol, serialized binary files and published field schema. It separately reconstructs the following.

| Check | Independently verified outcome |
|---|---:|
| Complete declared controller grid | 40/40 retained |
| Original physical-phase rows / policy queries | 7,400 / 37,000 |
| Service admissions / unknowns | 17,387 / 19,613 |
| Line-aware tight completion admissions / unknowns | 16,948 / 20,052 |
| Additional service admissions | 439 |
| Posthoc diagnostic unsupported queries | 7,425 retained |
| Full / prospective binary records independently decoded | 40 / 40 |
| Decoded complete-query slacks matched | 37,000 from each format |
| Full/projected direct-envelope integer phase positions | 23,812 |
| Producer manifest payload hashes and lengths | 97/97 |

For every original physical `(P,phi)`, the checker enumerates all translated literal recurrent edges over `P/gcd(P,d)` copies and searches integer ticks for the first decrement after capture. The completion comparator separately constructs each line's virtual intervals using that line's tight `J=max(c-s)`, `A=max(h-c)`, and literal completions. Both routes retain the identical physical-period finite prefix. This reproduces all frozen bases, admission masks, and original minimizing witnesses. Every zero and negative query is retained. It also reconstructs every derived policy row, all per-controller counts, every tied optimum, K/P/phi selection, all CSV fields, and every result histogram. No favorable subset is selected.

For pair decomposition, grouping starts directly from literal `(s,c,h)` triples. For each full or prospective modulus, the checker enumerates the envelope at every integer phase and retains a profile only if it has an exclusive minimizing phase. It then checks equality of the complete before/after envelopes. All four pair arrays match for all 80 lines: full grouping/canonicalization **961→961**, prospective grouping/canonicalization **838→765**. Support projection removes 123 pairs; prospective canonical deletion removes another 73. Full-modulus canonical deletion is zero.

The independent cursor parser reads all little-endian fields without producer modules. Every decoded value is compared with the raw relation and independently rebuilt canonical arrays, including all four actual SHA256 bindings, p/b/r/d/maxP, both line identities, initial captures, cycle entries, moduli and exact physical prefix triples. An independent encoder reconstructs every original byte. Parsed sizes agree with `280 + 24×prefix_edges + 16×pairs`; index hashes, file lengths, overhead and saved fractions also match. The checker evaluates all frozen complete-query service slacks from each decoded variant.

Fresh byte copies test truncation, trailing data, unknown magic/version, line count, owner/tag, zero modulus/span and out-of-range residues. Separate guard tests reject each of the four mismatched expected bindings, invalid query domains, unsupported gcd, and every portfolio's outside-grid period even when its gcd is compatible. The full record accepts the tested compatible outside-grid period. These tests exercise the independent parser and evaluator; they are not tests of the producer decoder implementation. Synthetic tests exercise an explicitly represented empty feasible set and strict positivity plus all-tie K/P/phi ordering. The actual 40 cases have no empty feasible set.

Service lowers the stipulated `KP−1` retention proxy in 21 controllers and yields no improvement in 19. Those 19 comprise 13 with no additional admissions and six with additional admissions but no optimum improvement. Gains are 0 ticks in 19 cases, 1 in seven, 2 in five, and 5 in nine. All tied optima and negative-case identifiers are retained in the JSON evidence.

Full records total 36,560 bytes; prospective records total 33,424 bytes. The 3,136-byte difference is **8.577680525164111%** of full-record bytes. Both alternatives pay the same 21,184 bytes for headers, bindings, line metadata, cutpoints and 416 exact prefix triples. Pair arrays alone fall from 15,376 to 12,240 bytes (**20.395421436004157%**). Thirty-three controllers save zero bytes; two save 288 and five save 512. The median controller saving is zero. The unweighted mean individual saving fraction is about 5.966889874928752%, which differs from the aggregate ratio of summed bytes.

The initial strict distribution comparison stopped on the independently computed floating mean `0.05966889874928752` versus the producer's `0.05966889874928751` (difference `6.938893903907228e-18`). The initial stop is retained in `INITIAL_STRICT_FLOAT_COMPARISON.json`. The final checker compares all non-mean distribution fields exactly and bounds floating-mean differences with relative tolerance `1e-14` and absolute tolerance `1e-15`; this sole harmless roundoff difference is explicitly retained in the final JSON. No integer, pair, policy, binary-field, binary-byte, or slack discrepancy was found.

Hash bindings confirm that the current frozen protocol, precomputation binding, R03 inputs and producer sources match each other and the manifest. Matching current bytes and self-reported timestamps do not independently prove historical wallclock creation order. R04 remains explicitly **posthoc over the existing R03 family**, not a newly prospective experiment. No frozen protocol or source was rewritten by this checker.

The result is limited to the specified constructed two-client/two-line component model and one explicit uncompressed LE format. It establishes no measured traffic, power, energy, WCET, speed, hardware, native HUSH, arbitrary-payload coherence, population inference, minimum encoding, runtime residency or native epoch lifecycle. File/model SHA256 bindings are stipulated identities. Binary payload totals exclude filenames, the JSON index, a packaging container, disk allocation and runtime object memory. No timing experiment, compiler, remote, private overlay, manuscript, figure, review, or publication operation was performed.

Re-run from this directory with Python 3.12 and the required flags:

```text
python -B -X utf8 check_independent.py
```

The script overwrites only its final JSON audit and per-controller JSON in `independent/`; it verifies producer files read-only. `MANIFEST.json` in this directory binds the final checker, audit, facts, per-controller output and retained initial floating comparison. The producer's original 97-file manifest is separately checked and remains unchanged.
