# Complete-prefix admission: paper-ready material

## Suggested result paragraph (80 words)

Both routes certify the same finite prefix under the actual counter policy. Across 6,277,660 expanded queries, service profiles admit 4,371,335 complete policies versus 4,205,797 for tight recurrent completion bounds: 165,538 additional admissions, including 552 with nonempty prefixes. Prefix checks reject 5,200 recurrent positives. Compact records supply 143,799 additional admissions; 1,010,970 queries require fallback. The original grid adds no admissions. These are exact finite-family validity/control results; native-cache conformance, arbitrary-payload coherence, measured runtime, and hardware performance remain unverified under the present model.

The paragraph's “additional” comparison gives the completion route the identical exact finite-prefix test. The 143,799 compact count is a subset of 165,538; another 21,739 service-only admissions require the full master/producer. Do not add these as independent gains. This paragraph concerns the existing grids, not an application-query-frequency estimate.

## Complete counts, with all negative outcomes

One interface is one timing-source entry and physical period P. A query additionally fixes phi and K. The timing-source family has 1,950 entries; 328 reachable ties reject, 1,622 remain, including 764 with nonempty prefixes. The expanded grid has 61,176 interfaces. These are parameter entries of the same specified source/receiver family, not independent applications.

| Grid / source stratum | Queries | Recurrent positive | Full exact positive | Shared-prefix completion positive | Full service-only | Recurrent positive rejected by prefix |
|---|---:|---:|---:|---:|---:|---:|
| Original / all | 643,060 | 12,168 | 11,453 | 11,453 | 0 | 715 |
| Original / nonempty prefix | 315,628 | 9,724 | 9,009 | 9,009 | 0 | 715 |
| Original / empty prefix | 327,432 | 2,444 | 2,444 | 2,444 | 0 | 0 |
| Expanded / all | 6,277,660 | 4,376,535 | 4,371,335 | 4,205,797 | 165,538 | 5,200 |
| Expanded / nonempty prefix | 3,082,260 | 2,165,752 | 2,160,552 | 2,160,000 | 552 | 5,200 |
| Expanded / empty prefix | 3,195,400 | 2,210,783 | 2,210,783 | 2,045,797 | 164,986 | 0 |

No-original-grid precision improvement, the small transient-only benefit and all prefix losses must remain visible. Original full-policy positives occur in 650 timing-source entries. Expanded full-policy positives occur in all 1,622, while service-only improvement occurs in 646 entries. Original/expanded prefix losses occur in 220/319 entries.

### Compact supported / unknown / unsupported are disjoint

Storage is still the disclosed posthoc rule `g=d/gcd(d,3)`. Query modulus `m=gcd(P,d)` is supported iff `m` divides `g`.

| Grid / source stratum | Supported full positive | Supported unknown | Unsupported, needs producer | Supported full service-only | Unsupported service-only, needs producer |
|---|---:|---:|---:|---:|---:|
| Original / all | 6,378 | 532,156 | 104,526 | 0 | 0 |
| Original / nonempty prefix | 4,954 | 260,304 | 50,370 | 0 | 0 |
| Original / empty prefix | 1,424 | 271,852 | 54,156 | 0 | 0 |
| Expanded / all | 3,656,751 | 1,609,939 | 1,010,970 | 143,799 | 21,739 |
| Expanded / nonempty prefix | 1,812,871 | 780,554 | 488,835 | 475 | 77 |
| Expanded / empty prefix | 1,843,880 | 829,385 | 522,135 | 143,324 | 21,662 |

The first three numeric columns sum to the query count. Unsupported policies are not failures or compact-record admissions; the full producer/master can answer them. The full exact-positive count includes 714,584 unsupported expanded positives that need that fallback.

## Fair baseline definitions, locally usable in the manuscript

Let `Epre` be the minimum physical-period `F_P(s+1)-h` over the original finite prefix, with `+infinity` for empty prefix. Recurrent service slack is `Erec`; complete service admission uses `min(Epre,Erec)>0`. Tight cycle bounds are `Jr=max_T0(c-s)` and `Ar=max_T0(h-c)`, and `C0` is the set of actual cycle completions. Compute `Drec` from these with the gcd lift. The primary completion baseline uses `min(Epre,Drec)>0`. **Both routes receive exactly the same prefix proof.**

Diagnostics: if the completion route instead approximates the prefix using its own tight `Jp/Ap`, expanded completion positives fall to 4,205,478, creating 165,857 service-only positives. A single global `Jall/Aall` over prefix+cycle lowers completion positives to 4,191,143 and creates 180,192. The stronger shared-prefix baseline has 4,205,797 positives and 165,538 service-only. Use this strongest baseline for the paper; retaining weaker diagnostics makes the potential inflation explicit.

## Small prefix-loss illustration

For existing `p=3,q=2,s0=1`, prefix `(1,6,8)` leads to cycle `(8,12,14)` translated by 6. With actual `(K,P,phi)=(4,2,0)`, recurrent slack is 2 but prefix slack is 0. A WU at tick 2 arms four decrements at 2,4,6,8. Response 6 still arrives, but expiry precedes read 8. Thus a fresh valid entry and positive recurrent slack alone do **not** admit the policy. The full check rejects it. No newly invented source instance is used.

## Replacement for the admission sentence after the consumer equation

“Admit only if the recurrent slack and a separately bound exact finite-prefix slack under the queried `(K',P',phi')` are positive, or valid cycle entry is proved directly. The prefix certificate binds the entry, prefix digest, receiver/source assumptions and actual policy; unsupported `m` needs the full master/producer.”

## Evidence locations

`PROTOCOL.json` was saved before the computation. `check_prefix_admission.py` produces `RESULTS.json` and `ALL_PHASE_BASES.jsonl.gz`, whose rows retain every phase's exact/completion bases and minimizing witness. Adding physical `(K-1)P` reconstructs every negative, zero and positive policy query. `ARGUMENT.md` contains the full first-failure proof, within-tick event table, source-key invariant and per-policy graph sizes. `independent_countdown_validation.py` independently uses decrement-event counts and finite all-WU successor-state DP; its terminal output and `INDEPENDENT_VALIDATION.json` distinguish independent mathematical corroboration from native execution.
