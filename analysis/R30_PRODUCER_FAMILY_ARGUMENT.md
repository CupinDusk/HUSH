# Parameterized source-coupled producer family

This argument is saved before the grid. The same two response registers,
dedicated lane/sink, serialized one-address read source and event ordering
are retained. Only positive cache period p, positive client interval q and
nonnegative entry s0 vary. No historical/native conformance is asserted.

For an accepted read, the unchanged register transitions give
c(s)=p*ceil(s/p)+p independently of WU and later validity. Let
lambda(rho)=p+(-rho mod p), where rho=s mod p. The public client functions
give h=s+q if lambda(rho)<q, or h=c(s)+q if lambda(rho)>q. A reachable
equality is excluded because poll/receipt same-tick event order is not
admitted. These branches follow the source event/response flags; no read
or response target is injected into the executing source.

The next service phase is therefore (rho+q) mod p in the early-receipt
branch, and q mod p in the waiting branch. This finite deterministic map
decides tie admission exactly after at most p visited distinct phases.
Without a reachable tie it has a prefix of length <p and a nonempty cycle
of length <=p. A repeated phase returns the same normalized source flags:
at a send there is one fresh outstanding request, a poll at send+q, no
older accepted snapshot, and the same packet/RNG/clock conditions. The
response-poll inequality fixes the following event order. Translation
by the accumulated cycle shift d, a positive multiple of p, preserves all
these transitions and gives the exact recurrent triple relation. Prefix
edges must still be checked at their original absolute times.

If q<p, every response is late; after at most one edge the service phase
is q, the cycle has one edge and d=2p. If q>=2p, every response precedes
the poll; the cycle has p/gcd(p,q) edges and d=lcm(p,q). For
p<=q<2p the same p-state map, with reachable ties rejected, characterizes
mixed/tie cases completely. These are meaningful waiting/polling regimes
of one producer family, not claims of multiple independent mechanisms.

For any policy whose prefix and recurrent exact observer slacks are both
positive, the accepted-request pipeline lemma and first-failure induction
give WU-independent source timing and expiry-safe reads. Thus the relation
is policy-independent within its admitted installations. An unconditional
safe witness exists: choose K=2,P=q+2p,phi=0. Each h-s<=q+2p-1 whereas
F(s+1)-s >= P+1; all prefix/cycle slacks are strictly positive. This safe
witness is not claimed to minimize retention or improve a policy.

The finite grid will execute the actual source and unchanged receiver for
three selected WU words per admitted entry, then independently compare
canonical master/gcd queries to explicit phase expansion for every tested
target period and phase. The proof covers the parameterized family;
these executions corroborate it without establishing independent program
breadth or exhaustive WU control coverage for each new parameter.
