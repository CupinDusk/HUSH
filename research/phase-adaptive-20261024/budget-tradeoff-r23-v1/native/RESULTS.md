# R23 same-offset native tradeoffs

Six preregistered N16 post-selection matched-suppression cases completed; all six pass checksum 1099140816896, terminal/marker/invariant checks. Binary/config/ELF and private source hashes match before/after. Original R20 frozen candidates and policies are unchanged. Replay uses only Python stdlib: `python -B -X utf8 replay.py --out replay-output`.

## Complete six-case ablation

| cache | phi | phase J / WU | suppression J / WU | phase minus suppression cycles / WU |
|---|---:|---:|---:|---:|
| 32KiB | 0 | 477,808 / 550 | 479,417 / 196 | -1,609 / +354 |
| 32KiB | 64 | 477,808 / 550 | 479,417 / 194 | -1,609 / +356 |
| 32KiB | 127 | 477,808 / 550 | 479,417 / 196 | -1,609 / +354 |
| 64KiB | 0 | 475,486 / 629 | 476,664 / 195 | -1,178 / +434 |
| 64KiB | 64 | 475,486 / 629 | 476,480 / 191 | -994 / +438 |
| 64KiB | 127 | 475,486 / 629 | 476,664 / 195 | -1,178 / +434 |

## Cap identities and all outcomes

The original training cap is the max over the three declared offsets, multiplied by 1.001. The objective first rejects over-cap candidates, then minimizes max-WU, max-J and lexicographic K. Suppression was not a training candidate; applying that cap to the new measurements is explicitly retrospective. Heldout caps below reuse the frozen fastest-time K on each same-N input; no heldout choice is selected. They are different absolute caps and no admission/WCET guarantees.

| cache | N | cap | fixed maxJ / fits | phase maxJ / fits | suppression maxJ / fits |
|---|---:|---:|---:|---:|---:|
| 32KiB | 16 | 478,204.727 | 478,142 / True | 477,808 / True | 479,417 / False |
| 32KiB | 32 | 2,231,904.675 | 2,233,539 / False | 2,233,223 / False | 2,234,531 / False |
| 32KiB | 36 | 2,882,296.417 | 2,879,881 / True | 2,879,206 / True | 2,880,422 / True |
| 32KiB | 40 | 3,603,484.885 | 3,600,441 / True | 3,598,769 / True | 3,601,197 / True |
| 64KiB | 16 | 475,416.942 | 475,396 / True | 475,486 / False | 476,664 / False |
| 64KiB | 32 | 2,216,645.431 | 2,214,520 / True | 2,214,497 / True | 2,215,689 / True |
| 64KiB | 36 | 2,852,066.217 | 2,849,369 / True | 2,848,892 / True | 2,850,381 / True |
| 64KiB | 40 | 3,564,179.619 | 3,560,663 / True | 3,562,217 / True | 3,563,422 / True |

At N16/32KiB the new suppression max479417 exceeds the original cap478204.727, while phase477808 fits and reduces max-WU638→550 versus the eligible fixed. This retrospectively explains the measured tradeoff against suppression under that cap, without adding suppression to the original search. At64KiB suppression476664 and phase475486 both exceed475416.942, so the original fixed deployment remains appropriate under the frozen rule.

## Same-offset Pareto comparison

PARETO_INPUTS.csv retains every one of 72 selected-policy points, PAIRED.csv all 24 matched triples, and N32_32KiB_NINE_POINTS.csv the requested nine primary points. Pareto flags compare actual J/WU from the same offset only. Different maxima are never joined into a measured point. TRAINING_PARETO.csv separately retains all 558 original candidate aggregates; suppression is absent from that original search.

| phi | fixed J / WU | phase J / WU | suppression J / WU |
|---:|---:|---:|---:|
| 0 | 2,230,986 / 2,139 | 2,233,223 / 1,941 | 2,234,531 / 505 |
| 64 | 2,233,539 / 2,098 | 2,233,223 / 1,941 | 2,234,303 / 508 |
| 127 | 2,230,753 / 2,158 | 2,233,223 / 1,941 | 2,234,531 / 505 |

## Intervention and attribution limits

The config initializes all caches with the first K (K1 for both phase and suppression), keeps the identical guest stage-load environment and helper work, and suppresses calls to hushSetPhaseTimeout at changed boundaries. Source cache.cc242-261 shows that this removes prospective default changes and the corresponding configuration-edge receiver hold trigger. The independent late-fill/expiry/capture hold condition remains (cache.cc2113-2117). Suppression remains coherent HUSH with expiry; it is neither no-coherence nor a pure timer-only intervention. Equal guest commands and first cumulative epochs are checked, but later instructions, memory accesses and schedules can diverge. Phase-minus-suppression therefore measures the whole future-timeout intervention, including its event/scheduling effects.

EPOCHS.csv provides validation/FIR/features/join whole-system hits, misses, WU, instructions, replacements and J for all 72 points; all 288 rows reconcile exactly. EPOCH_DELTAS.csv retains all 192 phase-minus-fixed/suppression signed epoch comparisons. These epochs include the concurrent writer, readers, barriers and helpers; they do not isolate an individual consumer. Nominal helper quiesce is 8 cycles per changed marker: two calls (16 cycles) for 32KiB phase/suppression and one call (8 cycles) for 64KiB phase/suppression, zero for fixed. Marker1 helper belongs to FIR, marker2 helper to features. The nominal guest stalls cannot be subtracted as an exact joint-time cost because other cores progress concurrently.

At 32KiB N32, phase trades fewer cycles for substantially more WU than suppression; both lie on a measured time/traffic tradeoff. Phase itself also misses the same-N frozen-fastest diagnostic cap. The frozen decision to deploy phase is justified by the original eligible-family N16 objective; it does not establish unconditional superiority over suppression. At64KiB the frozen deployment remains fixed; phase is diagnostic. All signs, including zero and adverse deltas, are retained in the CSVs and AUDIT.json.

## Primary epoch example:32KiB N32 phi0

| epoch | policy | hits | misses | WU | J | nominal helper cycles |
|---|---|---:|---:|---:|---:|---:|
| validation | fixed | 39,741 | 523 | 122 | 40,808 | 0 |
| fir | fixed | 770,784 | 2,838 | 1,686 | 618,979 | 0 |
| features | fixed | 1,937,535 | 833 | 331 | 1,559,373 | 0 |
| join | fixed | 3,110 | 104 | 0 | 11,826 | 0 |
| validation | phase | 40,160 | 422 | 21 | 40,836 | 0 |
| fir | phase | 770,790 | 2,958 | 1,814 | 620,967 | 8 |
| features | phase | 1,937,358 | 619 | 105 | 1,560,194 | 8 |
| join | phase | 3,085 | 105 | 1 | 11,226 | 0 |
| validation | suppress | 40,160 | 422 | 21 | 40,836 | 0 |
| fir | suppress | 777,590 | 1,664 | 439 | 622,492 | 8 |
| features | suppress | 1,931,917 | 554 | 44 | 1,559,977 | 8 |
| join | suppress | 3,085 | 105 | 1 | 11,226 | 0 |

Compared with fixed at this offset, phase saves101 WU during validation and226 during features, but adds128 during FIR and1 at join (net−198). FIR misses rise120; features misses fall214. These observations support a phase-dependent whole-system traffic redistribution; they do not support a claim that the long FIR setting universally improves hit rate or that every phase gets faster. Compared with suppression, phase FIR is1525cycles faster with1375 moreWU and1294 moremisses; features is217cycles slower. Scheduling/instruction differences preclude interpreting these deltas as a timer-only causal benefit.
