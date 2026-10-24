# Producer-locality training extension, before heldout timing

Earlier52+108 training-only runs remain intact. They motivate controlling
the refresh process's spatial locality: one word per cache line versus
all words in each complete frame. The latter is a dense frame refresh;
both write identical values for exact full-pipeline checksums.
This extension is exploratory training, not an unseen replication.

One new common binary has runtime pattern0/1; original kernels/stages,
preloaded descriptors, idempotent-write suppression, completion markers,
and changedT helper8 are unchanged. Full5x5 grid atN8 only for each
cache4/16KiB ×64/256 storesperline ×sparse/dense pattern. All five fixed
diagonals,20 phase entries and WI/WU included:216cases total. Keepall.
Freeze separate bestfixed/bestphase for each of8 settings before first
N12/N16 timing. Validation: allfivefixed, selectedphase8/0/16 andWI/WU;
same complete self-check and all-program ROI, tasktimes, updates,
misses/evictions, invariant counters. Native timing only; complete-kernel
static source-accounting experiment is reported separately.
