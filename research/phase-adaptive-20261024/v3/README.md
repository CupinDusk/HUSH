# Phase-adaptive HUSH, v3

Download [phase-adaptive-hush-v3.zip](phase-adaptive-hush-v3.zip), extract it,
then follow its README. The bundle contains all code, fixed protocols,
expected outputs, receiver formal miters and pinned upstream provenance.
SHA256: `904f3f006dcc36314b7bd91b8143fa0bb7d35632c8db7e25068d9e01c115e283`.

The `source/` directory mirrors the readable inputs. Expected study outputs
are distributed inside the frozen bundle; run from its extracted directory.
Python 3.12+ and a C99 compiler reproduce eight model/kernel studies.
Native Yosys/ABC is optional for receiver proofs and Nangate45 mapping.

This revision uses registered timeout configuration and one-cycle WU
backpressure on a coincident write. Existing arms keep their remainder.
It adds free task-end release and optional free boundary-flush controls,
uniform tight-budget margins, the compiled FIR2DIM access-order control,
receiver step/refinement miters and matched mapped hardware estimates.
The 632-point tight sweep retains 241 wins, 366 ties and 25 losses against
the stronger fixed maintenance control. Carry-in beats reset at 172 points.
All nine FIR scenarios tie when both policies release copies at reader end.

Independent extraction reproduced all scientific result fields in all
eight studies, two receiver proof obligations, seven rejected fault
mutations and all six mapped area/delay rows. The initial portable proof
command omitted `-set-assumes`; the published command includes it, matching
the original invariant proof. The scientific miters were unchanged.

These are declared architecture-model and receiver-component results.
They do not establish native application performance, full coherence,
complete WCET implementation or system PPA. Private HUSH overlays, the
paper and server materials are excluded. Earlier v1/v2 research remains
available in the parent directory and Git history.
