# Version-changing native coherence check

Freeze before execution: same four-core HUSH native binary/config as R14.
One producer writes strictly increasing round numbers to8/64 separate64B
lines, then publishes the round using a release atomic. Three consumers
acquire the publication, then read every data line. Every observed version
must be at least the acquired round; concurrent newer versions are legal.
At final published round32, all lines must equal32. This checks a changing
payload against an independent publication lower-bound oracle. Initial
zero values, repeated reads, phase transitions and finite unified cache
replacement are included. Common C11 atomics, not compiler-undefined races.

Cache sizes4/16KiB, two ways;6 schedules8/512/65536 constant,
8→65536→8,65536→8→65536,512→512→8. Consumer phases occur at
iterations16/32 of64. The producer executes32 rounds with16 integer
gap operations per store. Added changed-load stall8, global future-arm
API as before. Total24 native cases; two jobs maximum. Record every
staleness comparison and final check, program return, markers, cache
evictions and all invariant counters. No performance speedup endpoint.
Host-stub selftests precede native runs. No stop/kill operations.
