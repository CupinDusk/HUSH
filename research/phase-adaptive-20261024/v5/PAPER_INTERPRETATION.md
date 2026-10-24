# Interpreting the phase-adaptive evidence

The mechanism separates a long bootstrap lifetime from the shorter warm
reuse interval. Prospective loading does not retime active counters;
carry-in keeps validity evidence through the transition. Runtime choices
are limited to admitted paths. The reported performance policy is offline.

The worked BSQ model case has2 shared lines,gap1,P2 and reader budget690.
Best fixed K74 has bound689,completion1103,40WU packets and2 misses.
Phase path254/4/4 has bound690,completion806,7WU packets and2 misses.
The same phase path with reset analysis has bound1880 and is not admitted.
Both get free end release; fixed also searches free boundary-flush subsets.
This explains the26.9% completion and82.5% packet reductions in that case.

Complete strong-control sweep:79 architecture configurations by8 slack
values; phase241wins/366ties/25losses; median improvement0, maximum26.9%,
maximum regression6.5%. Carry-in beats reset172times. The1..64-cycle
subset is a retrospective operating-region characterization, not a new
prospective trial. At128/512 slack free flushing can admit more misses.

V5 freezes selected configurations and changes writer behavior. This
tests reuse of a chosen policy pair; it does not compare phase settings
against a retuned optimum at every held-out condition. All3792 runs per
policy meet their unchanged reader budgets;1168wins/2382ties/242losses.

Other retained controls: all9 FIR access-order cases tie under free end
release. At runtime helper costs0/4/16/64, the simple admitted selector
has60/160/20,70/10/160,40/0/200,40/0/200 win/tie/loss counts per240 runs;
all960 reader bounds hold, worst completion regression93.7%. Thus neither
general application speedup nor a runtime performance guarantee is claimed.
All raw summaries and replay scripts remain in this bundle.

Evidence scope: independently written cycle-level architecture model;
receiver-only inductive/refinement checks and prelayout mapping. These
do not establish full-system coherence, native application WCET, software
latency measurements or complete-system PPA. Native gem5 directed checks
use continuous expiry and are recorded separately, outside this minimal
public package. No private HUSH overlay or server material is included.
