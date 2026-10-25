# Phase-Adaptive HUSH: receiver composition supplement

The [pinned preceding index](https://github.com/CupinDusk/HUSH/tree/89cb4e5f2d797b124237d515067d646c2c1a9448/research/phase-adaptive-20261024/revised-story-r35-v1) retains the cost-aware source search, common read bank, all original whole-bank proof timeouts, native measurements and mapped-cell reductions. Those files remain unchanged.

Use Python3.12+ with the standard library:

```text
python -B -X utf8 replay.py --quick
python -B -X utf8 replay.py --quick --output ./verified-quick
```

The quick command verifies every archive member, checks retained solver outcomes and independently replays frozen RTL waveforms. It does not launch a formal solver, simulator, native program or synthesis tool. The component documentation gives the finite registered proof and simulation schedule, every attempted outcome, assumptions, exact RTL/observer bindings and optional full tool commands. An integrity PASS is separate from a proved property.

The component decomposes the default64bit data property into separately scheduled bit obligations on the actual N4 timer/queue/data RTL. Only the conjunction of all64 proved obligations establishes the full64bit property for that configuration; no representative-bit or all-size inference is used. Read-only observer reversal is byte-bound to the original functional RTL. Authoritative request-time fill snapshots, stable blocked requests/source payloads and phase events between completed requests are explicit environment contracts. Strengthening invariants are asserted, not assumed. All unknown, counterexample, fixture/tool and mutation outcomes remain recorded.

Tick-enabled finite tests and their independent scalar waveform replay retain their exact tested configurations and coverage. Tags/LRU/dirty ownership, a global source-write completion protocol, processor timing, routed timing and mapped data-bank area are outside this local component. The historical38FF difference remains metadata only. This supplement adds zero native measurements; the historical total remains4308.

All scientific files retain their recorded bytes. No manuscript, review report, private server/simulator material or credentials are included. Prior signed and infeasible outcomes remain accessible through the pinned indexes. Third-party notices retain their effect.
