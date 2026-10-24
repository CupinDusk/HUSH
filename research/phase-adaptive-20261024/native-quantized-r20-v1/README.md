# Discrete-timer native experiment

Run `python -B -X utf8 replay.py` using standard-library Python. The safe,
allowlisted data-only loader verifies chunk/archive/member hashes and size,
then recomputes selection, all measured contrasts and epoch sums. This is
recorded-measurement reproduction, not a new simulator execution.

Before any new performance observations, the protocol froze P128,
phi0/64/127,32/64KiB,N16training,N32/36/40heldout, the unchanged executable
and four independent host workers. All255 legal fixed loads (255=infinity),
24 nonconstant{1,16,128}^3 tuples and WI/WU give1686training measurements.
Both fixed and phase families minimize worst-offset WU within0.1% of the
fastest fixed worst-offset measured time, then time/lexicographic loads.
Deploy phase only if it strictly reduces WU; otherwise fixed. The0.1%
cap is an empirical selection objective, not an application WCET bound.

Freeze choices before heldout. Each heldout point retains the16predeclared
fixed diagnostics plus frozen fixed winners if absent, phase, matched
suppression and WI/WU. Diagnostic heldout fixed minima are not all255-load
oracles. The32KiB,N32sweep covers every128tick offset, reusing9records at
the three declared offsets and executing375new cases. All signed effects,
both geometries, all inputs and four whole-system epochs remain.

The staged gem5 receiver adapter uses the exact Eq1 arm deadline and
prospective loads, invalid-way-first allocation and expiry-before-capture.
Configuration-coincident/late WU is held one cycle with bus delay. It is
not a literal RTL counter, full RTL equivalence, production CSR measurement,
or a proof of four-client WCET. Native joint time includes real helpers,
barriers and the declared extra8cycle changed-descriptor stall. Callbacks
consume zero simulated time. Matched suppression disables the entire
future-timeout intervention (including its receiver interlock) with the
same ELF, inputs, descriptors and helper/stall costs; it is not a pure-TTL
factor. Dynamic instruction counts can diverge with synchronization.

Reexecution needs a compatible HUSH-enabled gem5 binary plus the included
configuration/benchmark/driver and frozen manifests. Pass --binary,
--benchmark,--config,--sim-cwd to native_driver.py in a fresh output tree.
The simulator overlay and binary are private and excluded; stock gem5
does not expose these APIs. Source/binary/ELF fingerprints accompany the
records. No server/user identity, credentials, paper or reviews is included.
The separate receiver-validation package preserves failed attempts, the
invalid-first repair, synthetic receiver checks and actual changing-payload
release/acquire tests. The CPU checksum pipeline refreshes constant values
and is not described as a changing-payload correctness experiment.
