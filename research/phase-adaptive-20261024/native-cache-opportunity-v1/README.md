# Native cache-residency opportunity study

Run `python -B -X utf8 replay.py`. This unpacks the compact measurement
records, checks the frozen protocol/selection, recomputes all196 native cases
and contrasts, runs9 directed invalid-way checks, and verifies output hashes.
Only the Python standard library is needed for recorded-data reproduction.

The prespecified extension tests32/64KiB private unified caches with the same
native ELF, config, producer and three-consumer FIR/feature program as the
16KiB study. Each geometry runs41 N16 training cases:15 fixed loads,
24 nonconstant phase tuples from{128,2048,16384}^3, and WI/WU controls.
Choose best phase versus best fixed strictly by training joint time; ties
choose fixed. Freeze before all N32/36/40 heldout measurements. Each of the
six points runs15 fixed loads, frozen phase, matched suppressed writes,
WI and WU (114 measurements). Both geometries and all signed outcomes remain.

Joint time includes executed helper instructions/barriers and an extra8cycle
leader stall for changed descriptors. Five-digit COST strings preserve width.
Fixed training selection, the stronger best15heldout oracle, actual deployed
mode, and forced-phase diagnostics are separate columns. Suppression changes
only future-timeout API writes; it retains the guest path, initial timeout,
descriptors and extra stalls. All epochs are whole-system time intervals;
counters include four unified instruction/data caches. No CPU/whole-program
WCET certification or independent statistical sampling is inferred.

The record DATA.json is losslessly ZIP/base64 encoded for compact text-only
Git publication; raw-record canonical SHA256 and selected cumulative counters
are retained. Environment-specific argv0 is replaced by the benchmark name.
No server identity, credentials, simulator overlay/binary, paper or reviews
are included. Source binding distinguishes original Windows byte hashes from
canonical LF export hashes without changing the prespecified protocol.

New native execution needs an independently available compatible HUSH-enabled
gem5 exposing the documented API/counters. Set HUSH_GEM5_SOURCE,
HUSH_GEM5_BINARY,HUSH_PIPELINE_BINARY and run the public native_driver.py
against TRAIN_MANIFEST.json or VALIDATION_MANIFEST.json in fresh rounds.
The included config/benchmark/portable driver are unchanged from the earlier
public study. Stock gem5 does not provide the private HUSH extensions.
Two workers and natural20billion-tick limit; no process-kill timeout.

The directed allocation check isolates one residency premise: an expiry hole
is used before a valid line is evicted. Correct2/3/4-way cases preserve the
predicted live line; the deliberately wrong fill rule fails two2-way cases.
It supplements the earlier complete finite-state residency check.
