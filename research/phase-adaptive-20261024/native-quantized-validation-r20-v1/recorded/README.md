# Quantized native receiver validation

Run `python -B replay.py --output replay-result.json` with Python3.9+ and no
external libraries. This package checks immutable recorded native traces;
the private simulator overlay and simulator/guest binaries are excluded.
The benchmark C sources and gem5 configurations document the native inputs.
The compiled source and binary SHA256 values bind the observations.

The native receiver uses fixedP, globalphi, finiteK1--254 and tagged infinity
255. Configuration affects future arms. The adapter orders input, fill52,
expiry55 and local hit capture60, and holds configuration-conflicting input
one receiver cycle. A host API write takes effect at the next receiver edge.
The 4-client CPU pipeline uses the same previously retained guest ELF and
five-digit nominal-cycle fields `T=K*P`, with strict representability checks.
The native control is a simulator event-stage implementation; this package
does not supply a formal full-system or RTL-equivalence proof.

The data include9 compiled Cache receiver processes, one ordinary four-core
pipeline checksum smoke,24 version-changing C11 release/acquire runs
(168480 version comparisons, zero stale values), and4 controlled bus tests.
An independent oracle enumerates global counter ticks for every one of46017
arms and checks23311 expiry generations. It separately verifies the integer
receiver stamp `ceil(arrival_tick/clock_period)`;15 sub-cycle arms in the
4KiB/Q64 freshness stress have exactly the same global expiry after this
stamp. The main pipeline smoke has no sub-cycle arms. The data are exact
simulation observations and have no statistical speedup endpoint.

The original receiver test8 exposed a valid/invalid LRU timestamp-zero tie.
The final native tag selector chooses an eligible invalid way first, then
uses the configured replacement policy for live candidates. The exact same
zero-time witness changes fromA_invalid/B_valid toA_valid/B_valid. The old
failed binary hash, original result, and new source bindings are retained.
All protocol rows of the subsequent performance study use the same final
binary and this selector.

The legacy C1-S3 oracle was originally designed for WU-O's slow response;
HUSH forwarding completed before its fixed ten-cycle probe. These attempts
are recorded in `FIXTURE_HISTORY.json`. The final controlled stimulus clock
is20GHz, so its unchanged ten-cycle old-data probe occurs after0.5ns,
strictly before the cache's positive1ns forwarding delay. Cache and bus
remain1GHz. No predicates were relaxed. The main CPU experiment config
remains unchanged. The response20 attempt did not slow the snoop path and
was retained as an unsuitable fixture, rather than used as evidence.

`FILE_MANIFEST.json` checks every input byte. `replay.py` recomputes the
counter oracle and checks all recorded receiver, freshness, pipeline, bus,
and before/after allocation results. Native reruns additionally require the
author's bound simulator binary or a separately reconstructed implementation.
