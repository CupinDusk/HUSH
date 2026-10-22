# Pre-execution source-calendar clarification and compile correction

The initial PROTOCOL.json and source/driver copied in build-01 remain byte-exact.
Yosys 0.70 synthesis completed, but C++ compilation failed before any model
execution: `cxxrtl::wire<64>` has no `.data` member. Access must read
`counts.curr.data`. The numbered failed build preserves the compiler log.

During implementation, before execution, p=r=5 was found to have F=40, so the
literal offsets 40..43 are outside [0,F). The initial literal in-frame design
would reject that domain and cannot silently be claimed to implement eight
requests. This finding is retained.

Parent authorized and appended the pre-execution clarification to the prospective
plan: the periodic source is the MULTISET of eight jobs at offsets modulo F,
retaining multiplicity and original offset order on ties. Consequently p=r=5
enqueues two distinct same-owner IDs at each of ticks 0,1,2,3 of EVERY frame.
All other fixed cases keep the original release phases. No case or parameter
is removed, replaced, deduplicated, or chosen using execution results.

This amendment takes priority over the initial protocol statements that each
tick enqueues at most one request and that F>=44. `evenq` now counts 0,1,2;
two event slots preserve exact enqueue order/IDs. FIFO capacity remains eight,
enqueue precedes grant, overflow is an observed failure rather than a reason
to change a case. Active protocol is PROTOCOL.json plus this amendment.
Source/driver are corrected only after this amendment is written.
