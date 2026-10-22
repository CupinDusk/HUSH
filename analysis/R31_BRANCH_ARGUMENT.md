# Prospective branch-producer argument

This is a new specified logical producer, not historical MemTest or native HUSH.
Let integers 1 <= a < b < p. A callback in mode 0 selects delay a or a+p;
mode 1 selects b or b+p. Bit 0 flips mode and bit 1 preserves it.
Every delay is positive, so the next read follows receipt and no request overlaps.

The unchanged two-register endpoint gives c(s)=p*ceil(s/p)+p independently
of WU for each accepted read. Starting at s=a, every later read has phase a
or b. Writing s=np+r, r in {a,b}, its callback is (n+2)p and its next
read is (n+2)p+x+ep for x in {a,b}, e in {0,1}. Thus all actual edges
belong to the eight-triple enclosure (r,2p,2p+x+ep)+np. This is a sound
enclosure; it need not equal the reachable relation at every finite translation.
The bound is conservative and suffices for positive-slack admission.

At phase a the largest span is 3p+b-a; at b it is 3p. Their difference
b-a equals (b-a) mod p, so a dominates b. The p-master is one pair
(a,3p+b-a). J=2p-a and A=p+b jointly occur at phase a in mode 1 with
bit 1; all completion residues are zero modulo p. Fair completion-query
canonicalization therefore has the same pair. This is not an advantage
over an equally informed and reduced completion baseline.

For any physical P, m=gcd(P,p), project the master to m and retain
(K-1)P. This is the exact slack of the periodic enclosure, which is a
lower bound for the actual reachable source. K2/P3p/phi a has margin
p-b+a, and K3/P2p/phi(a+1) has margin p+1-b+a, both positive. Initial
valid/disabled entry and the first-failure induction ensure all reads hit
for all WU and branch words absent other revocation.

The joint BFS quotient has finite countdown, two finite occupied/id/byte
registers, mode, waiting flag, delay <=2p-1, service age bounded by 4p-2,
and a next-service-age ghost. Time modulo L=lcm(p,P) preserves both
periodic endpoint guards. Source delays and mode are time-translation
invariant. Reusing ID 1 only after callback is injective on live requests.
Byte=0 preserves every control branch, not arbitrary data behavior.
Hence equal keys have the same WU/branch successor and observation tuple
(read-present,read-accepted,callback-present,callback-ID,expired).
Initial state is phase a, valid/disabled, empty registers, mode 1,
not waiting, delay zero, service age and next-service ghost -1.

Python replay shares only predecessor state, branch/WU choices, config
and the stated source rule. Expiry is recomputed as an absolute deadline.
Receipt time is recomputed from ceil(last_service/p), not register shifts;
post-tick register occupancy is reconstructed from service age/next boundary.
The source is independently stepped using actual analytically predicted
receipt. This is independent transition arithmetic, not independent
source premises or hardware. Full graph coverage follows the quotient
argument; finite enumeration alone does not prove unbounded equivalence.
