# Reset-predecessor queries on the same canonical payload

2026-10-23. Derived after the first new PDF-only panel. This is a specialization of ordinary sorted-breakpoint/envelope lookup, not a new generic search algorithm.

For a nonempty canonical modulus-m profile Q, convert each (r,nu) into (a,h)=((r+1) mod m,-nu) and sort by a. At a retained term's reset a, its value is strictly below every other term: otherwise another term dominates it by the existing reset criterion. Between consecutive retained resets, every surviving term increases by one. Deleted resets cannot change the lower envelope. Hence, if a is the cyclic predecessor of z=phi mod m, the exact envelope is

H(phi)=h_a+((z-a) mod m).

One predecessor search is O(log|Q|), followed by constant arithmetic. The existing canonical pairs are sufficient; a cyclic reordering changes the coordinate, not the number of pairs. At |Q|=1 this is constant work. The physical load stays B=(K-1)P, so Delta=B+1+H(phi). No array proportional to m is required. This does not make binary search or lower-envelope evaluation a generic new algorithm, and does not by itself establish runtime benefit.

Dense phase-minimum tables are a genuine comparator: they store m envelope values and answer a query with one indexed access. For small moduli they may beat predecessor search. A workload may also memoize the particular phases it repeatedly requests; no universal superiority or break-even follows from asymptotic costs. The proposed benchmark compares equal pre-generated query streams, includes dense tables where the fixed memory cap admits them, and reports construction separately from hot queries.

For a predeclared finite set of future physical periods P_i with unchanged relation translation d, g*=lcm_i gcd(P_i,d) is the least divisor of d supporting every query modulus. It divides every supporting divisor, and divisor projection cannot increase the number of canonical pairs, so it minimizes term count among such universally supporting divisor records (ties allowed). It is not minimum encoded bytes or necessary for a particular producer/sign-only question. A full requested period domain may force g*=d; that negative case must be kept. This simple corollary offers a prospective alternative to choosing g after favorable examples.
