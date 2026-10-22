# Exact periodic-source profile encoding check

Declared in R05_HUSH_PROSPECTIVE_RESPONSE_PLAN.md before input generation;
the pre-generation algebra finding about fundamental period q is binding.
Seven p=16,32,64,128,256,512,1024, q=2p+1, d=pq. Exact source s=qk,
c=p ceil(s/p)+p, h=s+q, 0<=k<p. Evaluate every phase 0..d-1, recover all
essential resets, and compare fixed-d sparse, dense and period-aware formats.
No time measurement, hardware memory, application or general superiority claim.

Common format header is 32 bytes: eight-byte type magic, original d (u64),
stored modulus (u64), count (u64), little endian. Dense body has d signed
64-bit values; fixed-d sparse body has p (u64 residue,u64 span) pairs;
the period-aware body has a single pair (0,q) at stored modulus q.
Original d and its source binding remain in every header. This is an explicit
format comparison, not a minimum arbitrary encoding. Dense streams may be
hashed without retaining large derived arrays. All sparse/period inputs and
every phase equality count must be retained. The smaller period alternative
invalidates any broad inference from the naive dense-versus-fixed-d ratio.
