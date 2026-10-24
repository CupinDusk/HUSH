# Run this compact research export

Run `python -B -X utf8 replay.py`. It losslessly decodes the standard ZIP/base64
recorded-data file, restores the original LF JSON/CSV inputs and expected outputs,
runs the analysis below, and checks every scientific output SHA256. This text
transport keeps complete candidate/measurement records available without a large
plain JSON upload. The data are unchanged; no account, binary or private overlay
is included. Only the Python standard library is needed for recorded-data replay.

# Finite bounded-path admission with one common timeout policy

This executable method check applies the existing HUSH path analyzer to a
supplied finite set of bounded modeled task paths. It adds a program-level
admission wrapper: for one common phase tuple K, accept only when

`max_{pi in supplied paths} W_pi(K) <= B`.

If each per-path bound is valid and the supplied set covers every feasible
execution path, then any execution follows some pi in that set and has
receiver work at most W_pi(K), hence at most the maximum and B. This direct
enumeration requires no join of abstract timer or cache states. It does
require complete path coverage; the wrapper does not extract a CFG or certify
the completeness of an input path set.

## Frozen modeled path set

The bounded input q is one of {2,4,8}, selected before the job. The receiver and
refresher use the same q. All paths use the same two-client service contract,
P=2, and at most eight dedicated clean receiver slots (only the first q slots
are active). The pre-existing BSQ instruction generator produces:

```
phase 0: repeat q times:     compute(1); read(i mod q)
phase 1: repeat 8*q times:   compute(1); read(i mod q)
phase 2:                    read(0); compute(512)
writer:  repeat 64*q times:  store(i mod q); compute(writer_gap)
```

Phase mode additionally spends eight cycles before each noninitial marker,
and one registered-write cycle when its load changes. Fixed mode has no
helper cost and can choose any of four free boundary-flush subsets; both
modes get free final release. These are bounded modeled instruction paths,
rather than a compiled application's newly extracted control-flow graph.

The pre-existing controlled benchmark formula gives
`B0(q)=Cbase + q*(WUslot+1+missslot) + (nreads-q) = 88*q+513`.
The common experiment budget was frozen as `B=max_q B0(q)+32=1249`.
This is a controlled receiver-work budget; no actual application deadline is
asserted. It does not constrain refresher completion or total fork/join time.

## Candidates, selection and validation

All 255 legal fixed loads times four free boundary-maintenance subsets yield
1,020 fixed candidates. The union of all 7^3 phase-domain vectors and 255
constant vectors has 591 phase candidates. Every candidate uses exactly the
same tuple and maintenance subset across all three paths. All 4,833
candidate/path training executions are retained, including candidates that
cannot meet the robust budget.

Admitted fixed and phase candidates are ranked by worst joint completion over
the three paths at writer gap 4 and tick phase 0. The deterministic tie-breaks
are stated in `PROTOCOL.json`. Phase is deployed only if its worst training
joint completion is strictly lower than that of the best fixed candidate.
`FROZEN_SELECTION.json` is written before validating the selected pair at all
three paths, gaps {1,7,16}, and tick phases {0,1}: 18 points/36 executions.

## Results

The maximum-bound guard admits one fixed candidate and 30 phase candidates.
It selects K=(255,255,4), where 255 means infinite retention; its three
receiver bounds are 706, 882 and 1,234, all within B=1,249. The selected fixed
policy is K=(255,255,255), with bounds 689, 865 and 1,217. The training worst
joint completion is 3,446 fixed versus 3,266 phase. All 18 held-out points
preserve the receiver budget, with zero unsafe predicted hits or bound
violations. Their joint reductions range from 0.29% to 27.47%. These controlled
model outcomes validate the wrapper; they are not native application speedups.

The guard matters: 1,031 candidates have q2-only W<=B but fail the all-path
maximum. A frozen witness K=(254,16,1) has W=777 for q2 and W=5,785 for q8.
Its q8 training execution takes 1,210 receiver cycles, so this witness shows
missing certification rather than an observed deadline overrun. The full
candidate list and all signed validation outcomes are retained.

## Replay

Run `python -B -X utf8 run_multipath.py` using only the Python standard library.
`replacement_model.py` and its base protocol are byte-exact R14 copies. The
frozen protocol binds their SHA256 values. All scientific outputs are
deterministic; `EXPECTED_SCIENTIFIC_HASHES.json` binds them, and an independently
extracted run must match the output bytes.

## Git LF export

This copy normalizes text line endings and deterministic result serialization to LF. Input byte hashes are updated in the protocol; `git_lf_export` retains the original protocol hash. Scientific metrics and every candidate/execution are checked equal to the original experiment before independent replay.
