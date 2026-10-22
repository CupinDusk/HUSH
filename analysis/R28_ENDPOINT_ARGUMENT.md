# Complete constructed endpoint, prospective implementation refinement

This addresses an R27 applicability blocker by constructing and checking ONE
specified endpoint. It does not retrospectively prove native HUSH/gem5.
The implementation must not assign response time using c(s)'s formula.

State: valid clean readable byte/tag; disabled/enabled countdown0..K;
two pending-response registers with request ID and snapshotted byte;
fixed cache clock periodp; separately configurable expiry K/P/phi.
At a tick perform revoke, valid-only WU, decrement, read/cancel/latch,
then (if cache boundary) output register1 and shift register0 to1.
There is no timer queue; stale generations cannot survive a disabled
single register. The WU port and response output have dedicated capacity.
These are architectural choices of this new endpoint, not assumed facts
about the historical native implementation.

Timer refinement invariant: after the latest uncancelled WU at r, count
is K minus the number of decrements since r, including a decrement at r.
Before K decrements the copy stays valid absent revocation; the Kth is
at F(r)=r+((phi-r) modP)+(K-1)P. A read hit disables the timer after that
tick's decrement, cancelling same-tick/older WUs. A WU on invalid does
nothing. The code's control is independent of the byte value. The concrete
single countdown implements the specified arm/deadline observer exactly.

Pipeline invariant: every occupied register holds the accepted read's ID
and byte snapshot. At service s, register0 receives it before the boundary
action. If a=p*ceil(s/p), register0 moves to1 at a and is emitted at a+p.
This proves c(s)=p*ceil(s/p)+p from two register transitions. The
one-outstanding client prevents another acceptance before emission, so no
register can be overwritten. The response sink consumes every output.
WU changes only line byte/timer and cannot delay the pipeline; even later
invalidation cannot change an accepted read's snapshotted response.

Client composition uses the five unchanged public MemTest definitions and
its already justified no-tie control: a poll before receipt waits and a
receipt then schedules c+q; a receipt before the poll leaves s+q intact.
For p9/q16/s0=5 this gives the known recurrent four-edge relation, d81.
On fresh valid entry the first read is accepted. Assume a first failed
read: before it the actual source/control path supplies exactly one
admitted edge, and the pipeline lemma holds under EVERY admitted WU word.
Positive observer slack excludes timer expiry by that read, with other
causes absent/revoked, a contradiction. Thus all later reads hit and the
relation/receiver obligations compose, rather than mutually assume one
another. This proof concerns this specified endpoint only.

Immutable analysis record: line/tag, epoch, receiver time scale, cache p9,
two response stages, independent WU lane/dedicated sink, d81 and source
g27/profile {(5,16),(10,33)}, evidence IDs and finite overflow horizon.
Queried counter parameters are separate. Old K2/P27/phi6 yields slack12;
new K3/P18/phi2 projects the same g27 payload to g9 and yields slack4.
Both runtime demonstrations start from fresh admitted entry. Changing p,
lane coupling, clock/epoch or validity invalidates the analysis binding;
changing counter policy mid-interval needs an additional transition proof.
The record does not assert a safe hot transition or reuse revoked tokens.

The finite state exploration quotients logical time by lcm(81,P), retaining
timer, valid bit and both response-register identities/occupancy. All WU
bits are explored on every reachable state. Data values have no control
effect, so zero-data control checking is justified by the code dependency
invariant, not extrapolated from a successful constant-data test. Cyclic
IDs are only a model-check quotient; the source-coupled executions use
fresh monotone IDs and check every outstanding request/response binding.
Mathematical induction is unbounded; uint64 implementation correspondence
is bounded by the enforced non-overflow tick/ID horizon.
