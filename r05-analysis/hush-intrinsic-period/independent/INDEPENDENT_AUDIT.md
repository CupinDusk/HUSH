# Author-side independent exact-period audit

**PASS, restricted to the stated exact integer observer and trusted-registry contract.** No counterexample to the conditional characterization, lift, or physical-query identity was found. This is an author-side mathematical and encoding audit, not a blind review, novelty acceptance, scientific-reproduction certificate, or hardware result. The hypothesis is a new posthoc extension of the old experiment, whose unfavorable results remain intact.

The original forty controllers get larger: **36,560 to 39,584 bytes**, with all forty new records larger, despite reducing 961 pairs to 950. Eleven of eighty lines reduce; sixty-nine do not. Keeping the original full record adaptively would retain 36,560 bytes, a separate fallback rather than a favorable result for the new encoding. The original portfolio totals 33,424 bytes.

## Independent implementation and scope

`check_independent.py` imports no producer mathematical function. It reconstructs canonical sets from strict resets of the directly evaluated envelope, enumerates translation stabilizers, finds repeating word blocks by exhaustive divisor tests instead of KMP, implements its own binary reader/writer, and checks source-cycle triples against every original full profile. For the large equal-span size family it sweeps reset events and unit-slope segments; it does not pretend to take the minimum over all p terms at every one of the large cases' phases. The proof below establishes why that sweep equals the full envelope.

`parser_probe.py` separately imports the producer module solely to call its actual `decode_new` decoder. This is implementation testing of the codec under test; no producer science function supplies the independent oracle. Normal Python with `-B -X utf8` was used. No timing, remote experiment, native source run, or performance mode was used. Only this `independent/` directory was written.

The audited domain is d a positive integer, a finite nonempty set of residue/span pairs, residues in 0..d−1 and nonnegative integer spans. Ordinary source spans are positive; the small census deliberately includes zero. Empty profiles, non-unit-slope kernels, arbitrary signed-query encodings and real-time hardware refinements are outside this claim.

## Proof with the missing details made explicit

Write f_(r,v)(x)=((x−r−1) mod d)−v and H_d(x)=min f_(r,v)(x). First combine equal residues by retaining their greatest span. For different residues s and r put delta=(r−s) mod d. The modular triangle inequality gives f_(s,w)(x)≤f_(r,v)(x) whenever w−v≥delta. Conversely, if this domination inequality fails for every other pair, then at x=r+1 the term's value −v is strictly below every competitor's delta−w. Thus a canonical term has a strict exposed reset at its own residue; equality is domination and removes the tied term.

Every kernel has slope +1 between its reset phases. Consequently the canonical set has the exact inverse

    Q_d = { ((x−1) mod d, −H_d(x)) : H_d(x)<H_d(x−1)+1 }.

All phases and predecessor phases are cyclic. A reset at x=0 is therefore included. For d=1 the single phase still satisfies H(0)<H(0)+1; a zero span also causes no exception. Ties away from exposed resets do not affect this inverse. This proves uniqueness of the canonical envelope representation rather than assuming it from the implementation.

For any divisor e of d, pair translation by e preserves Q_d if and only if H_d(x+e)=H_d(x) for every integer x. Sufficiency permutes the terms. Necessity applies the reset inverse to H_d(x+e), so both reset positions and their exact heights must translate. Repeated support without repeated spans is insufficient. The set of all cyclic translations preserving H_d is a subgroup of Z/dZ. Its least positive representative e divides d; all other integer periods are multiples of e modulo d. In particular every admitted divisor period e′ is a multiple of e. This is a statement about integer phases, including constant profiles whose least positive integer period is one.

Order the n canonical residues around the circle. Label residue i by its span and its positive clockwise gap to residue i+1, including the wrap gap. An orientation-preserving translation carries every ordered reset to the reset h positions ahead for the same h. It preserves the profile precisely when the n-symbol decorated gap word consists of copies of its first h symbols; the corresponding time displacement is the sum of those h gaps. The smallest repeating block therefore yields the least e. The standard prefix-function formula h=n−pi[n−1], with h replaced by n when h does not divide n, correctly finds this block. A one-symbol word has the full gap d. There is no novel generic string algorithm here.

Let Q_e be the canonical projection to residues modulo e. If pair translation by e has actually been checked on the expanded Q_d, then residues/spans form complete equal-span e-orbits, and

    Q_d = union_{0≤k<d/e} (Q_e + k e).

One way to see canonicality of Q_e is to minimize the d-kernels over a complete e-orbit: their minimum is exactly the e-kernel. This produces H_e=H_d on integer phases, and its reset inverse gives Q_e. Lifting the inverse gives exactly Q_d, including all span values. An arbitrary projected profile does not establish this equality.

Now take **any** physical integer P≥1, integer K≥1, and phase phi (in particular 0≤phi<P). Put m=gcd(P,d) and h=gcd(P,e)=gcd(m,e). For each base residue r in Q_e, its d/e lifts visit a complete coset of the subgroup generated by e modulo m. The orbit length is m/h. It divides d/e: from m=h m′, e=h e′, gcd(m′,e′)=1 and m|d, e|d, one obtains m′|d/e. Therefore

    min_k ((phi−r−ke−1) mod m) = (phi−r−1) mod h.

Minimizing over base pairs and canonicalizing yields H_m(projected Q_d)=H_h(projected Q_e). By the same inverse, the canonical m-profile is the exact lift of the canonical h-profile. The recurrent slack identity is consequently

    (K−1)P + 1 + H_m(phi) = (K−1)P + 1 + H_h(phi).

P remains physical in the load term, even when m does not divide e. The theorem does not need a finite P ceiling; the census is finite corroboration, not the source of that quantifier.

Every physical prefix triple (s,c,h_src) retains its exact term

    (K−1)P + s+1 + ((phi−s−1) mod P) − h_src.

Taking the minimum of unchanged prefix terms and equal recurrent terms preserves the complete answer. A fresh policy must still satisfy initialization, capture/cycle-entry and epoch conditions. This audit recomputes the exact period/lift of the declared source-cycle relations and preserves all their prefixes and four bindings. It does not prove that a changed producer or an actual machine obeys those source relations. An epoch/source change needs a valid new source proof and trusted registry; byte hashes cannot supply it by themselves.

Finally, for any other divisor e′ admitted by an exact period lift of this same H_d, e divides e′ and its canonical reset set has (e′/e)|Q_e| pairs. Thus e minimizes **pair count within the exact period-lift family**. This does not minimize arbitrary bits, complete record bytes against unrelated formats, sign-only queries, or hardware memory. In particular it does not turn an arbitrary old projection into a sufficient master.

## Established concepts and novelty boundary

The word computation is standard string periodicity; [Knuth, Morris and Pratt, 1977](https://epubs.siam.org/doi/10.1137/0206024) is an appropriate primary reference. The decorated cyclic reset word is the primitive-root representation of this particular piecewise unit-slope lower envelope; its period translations form the usual cyclic stabilizer.

[Zippo and Stea, 2023, Section IV-A1, Definition 5 and Lemma 1](https://arxiv.org/pdf/2203.02497) already minimize periodic function representations by finding matching repeated breakpoint parts; their Appendix B proves period-multiple structure. Their continuous ultimately pseudo-periodic setting differs from these integer cyclic resets. The present argument is at most an observer-specific application/corollary with an explicit lift/registry contract and the stated gcd query identity. Generic period minimization or representation normalization must not be presented as new. This targeted primary-source check is not a comprehensive novelty review.

## Exhaustive small census and actual controls

All **19,524 nonempty raw assignments** for d=1..6, each residue absent or span 0..3, were checked. These are not 19,524 distinct canonical functions. Results agree exactly with producer attempt-001 and attempt-002:

| Check | Independent result |
|---|---:|
| Target-divisor profile identities | 70,916 |
| Physical slacks, P=1..2d, K=1/2/4, every phase | 4,247,436 |
| Raw assignments with a reduction | 1,012 |
| Raw assignments without a reduction | 18,512 |
| Original canonical pair total | 55,532 |
| Period-reduced pair total | 54,103 |
| Assignments whose canonical set contains span zero | 3,276 |
| d=1 assignments | 4 |

The exact semantic case digest is `4932a5b1562d163394dd60e004e617ecfa449a532b4f858d8e76090c4330ea2f`.

Four actual independent mutant branches are executed, with concrete witnesses retained in `MUTATION_CONTROLS.json`:

1. A support-only period test on canonical d=4, Q=[(0,0),(2,1)] falsely chooses e=2 instead of four; phase one gives H=0 versus −1. The producer's d=2 example starts from a noncanonical set, so it alone did not exercise a support-only test on a canonical input. The present witness closes that narrow control gap.
2. Replacing P by e in the load at P=6, K=3, e=2 and Q_e=[(0,1)] changes slack 12 to four. A valid expanded d=4 lift is [(0,1),(2,1)].
3. Dropping the lift gate: d=12 sources [(0,12)] and [(4,12)] have identical g=4 projections but target m=6, phase one envelopes −12 and −10. The actual bad query branch returns −12 for both, so it fails on the second. Both sources have intrinsic period twelve; the projected g=4 payload has no period-lift proof. This preserves the old nondivisor impossibility.
4. Reducing a physical prefix modulo e: P=7, K=3, e=1, prefix (0,1,10), phi=0 gives eleven versus five. With recurrent Q_e=[(0,1)] the recurrent slack is fourteen, so the full minimum is also incorrectly changed from eleven to five. Capture zero/cycle entry ten make the prefix placement valid for this abstract witness.

These controls detect the four named error branches. They do not establish generic mutation coverage. The producer's controls retain useful wrong-formula/information-loss witnesses, but do not by themselves execute a full mutant implementation of its checker.

## Original relations and complete binary checks

Every one of the eighty original full/portfolio binaries is parsed and reserialized byte-for-byte independently. Every canonical full profile is reconstructed from the actual corresponding cycle triples in bound `RELATIONS.json`. Each of the forty new records is independently generated byte-for-byte and matches both producer attempts. The entire original grid P=1..4p, K=1..5 and every phase is checked: **74,000 per-line slacks and 37,000 complete-policy slacks**, with full, portfolio, period and direct source answers equal.

Each new line carries eight bytes of e and 32 bytes of the expanded-profile digest, while original d, all prefix triples, owner/tag, capture/cycle-entry and the source/receiver/relation/epoch bindings remain present. Forty controllers therefore add 3,200 metadata bytes and save 176 pair bytes, for a **3,024-byte net increase**. All no-reduction lines and all forty regressions remain in `OLD_RELATION_RESULTS.json`; no adaptive replacement was made.

The actual producer decoder accepts all 47 valid HUPERD05 and seven valid one-line HUFULL05 records. It rejects **2,762 targeted malformed or registry-mismatch variants**, including 1,242 truncations, changed header/line metadata, all four stale bindings, zero/huge counts, out-of-range/duplicate residues, changed spans or prefixes, e=0/nondivisor e, altered expanded digests and eighteen nonfundamental exact lifts. This is targeted probing, not exhaustive malformed-input testing.

For each of the 47 period records, a coherent forged profile with its own matching digest is rejected against the genuine expected registry. If the expected registry is also forged to match, all 47 are accepted as expected. Thus the stored digest is **not self-authenticating**; actual source/profile proof and a trusted expected registry remain mandatory. Some current decoder header/metadata/count checks use `assert`; these probes establish normal-Python behavior only, not hardened parsing under optimized Python.

## Seven predeclared size cases

For every p below the copied source obeys q=2p+1, d=pq, s=qk, c=p ceil(s/p)+p, h_src=q(k+1). Equal spans q make every fixed-d term strictly exposed at its own reset. Its reset spacing is q, so intrinsic period q is exact and fundamental and Q_q=[(0,q)]. Every phase of the decoded full record is checked by the independent reset sweep against the decoded one-pair result: **2,798,064 phases total**. All **378** declared physical sample slacks pass. No additional sampled policies are implied.

| p | d | e=q | Full pairs | HUFULL05 bytes | HUPERD05 bytes |
|---:|---:|---:|---:|---:|---:|
| 16 | 528 | 33 | 16 | 488 | 288 |
| 32 | 2,080 | 65 | 32 | 744 | 288 |
| 64 | 8,256 | 129 | 64 | 1,256 | 288 |
| 128 | 32,896 | 257 | 128 | 2,280 | 288 |
| 256 | 131,328 | 513 | 256 | 4,328 | 288 |
| 512 | 524,800 | 1,025 | 512 | 8,424 | 288 |
| 1024 | 2,098,176 | 2,049 | 1024 | 16,616 | 288 |

All fourteen actual generalized one-line binaries independently roundtrip and match the producer hashes. HUFULL05 is a new generalized one-line baseline, not an old R04 two-line artifact. The earlier mathematical encoding already disclosed a 32-byte-header/48-byte one-pair period format. The present 288-byte format adds complete bindings/metadata and does not displace that disclosure or establish a generic encoding minimum.

## Provenance and retained failures

All 82 original inputs and nine separately prebound size inputs match their byte sizes and SHA-256s. The original input manifest's protocol hash and first attempt protocol hash are `78593ddc…cd709`; the current amended protocol and size binding use `79ed1511…e403`. They are retained as different historical versions, not retroactively relabeled as one predeclaration.

The preserved producer syntax failure still fails compilation before input parsing. Independently applying only the three recorded numeric-field renames reconstructs `research-version-001.py` byte-exactly, SHA-256 `b9afea4d053c6da441296f51e35b58a8cff957a8d657603776cfa77d78673f2e`, matching attempt-001's start binding. Current `research.py` hashes to `208978c36876e32ae2ee64a4a29310d5422b690bb2928af026a4c825b2e05fae`, matching attempt-002. Existing attempt-001 results and binaries were preserved; size/generalized-parser additions belong to the later source.

The independent checker's own first invocation also stopped at compile time on a repeated dictionary keyword before parsing inputs. Its exact source and error are retained under `failure-001-syntax/`; the numeric-field correction was then applied and the corrected complete checker passed. The final checker includes the stronger complete-prefix witness and first/second-attempt result comparisons. `AUDIT_FILE_MANIFEST.json` binds the final independent artifacts; `READ_INPUT_MANIFEST.json` binds the original/new binary inputs, and `BINDINGS.json` records the source/protocol reconciliation.

This PASS supports the conditional exact-model statement and the exact format/count findings above. It establishes no native implementation refinement, physical source periodicity beyond the declared relations, runtime benefit, hardware memory reduction, arbitrary encoding minimality, or application-level benefit.
