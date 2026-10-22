# Independent author-side audit

PASS for the declared own calendar reference component, with the strict WU
cutpoint and finite-width limits below. This is an author-side implementation
and mathematical audit, not a blind review or a score. No manuscripts or blind
reviews were read; no remote machine, private overlay, publication or push was
used. All writes are under this independent directory.

The actual fresh chain was Yosys 0.70 -> generated CXXRTL -> Zig 0.14.1 C++17
`-O3 -UNDEBUG` -> execution. Both CXXRTL include roots were supplied. The
original producer driver was freshly compiled to produce the primary 4F
control/3F data streams. A separately written typed queue/snapshot/timer oracle
was then compiled against that fresh netlist. It compared all 34 state fields
and all 32 event/persistent-failure fields after every executed tick, including
dead raw register slots, exact bytes, actual request IDs and failure ticks.
Only signal wiring and the published serialization format are shared. No
producer checker module was imported into the independent oracle or arithmetic.

## Actual primary execution and arithmetic

- 12 fixed calendars; F=8*lcm(p,r), p=2,3,5,7,11,17 and r=5,7.
- Four lines, FIFO8 and two immutable snapshot registers. The eight release
  jobs form a multiset at phases 0,1,2,3,40,41,42,43 modulo F, in original
  offset order. At p=r=5, F40, duplicate same-owner jobs remain distinct IDs.
- The independently regenerated primary control/data streams contain 49,712
  serialized ticks: 15,296 control ticks and 34,416 data ticks in 36 runs.
  The three byte patterns are 0,255,(17t+73owner) mod256, at K=F+1,P1,phi0.
  Data totals are 858 captures and emissions, 714 cancellations, 1,116 blocked
  ticks and 135,792 accepted WUs. Every state/event byte was checked.
- The complete K1..16, P1..4p, all-phi grid has 130,112 primary policies. Its
  earliest full-relation minimizing one-WU word was actually executed for each
  policy: 84,379,472 ticks; 21,257 survive and 108,855 first miss exactly at h.
  No 440,303,104 omitted physical prehistory ticks are counted as execution.
- Independent trace extraction reproduces all per-line C0,J,A and s,c,h,
  all phase records, per-line bases, strict admissions, original K<=5 subsets,
  optimum values and every tied optimum. Completion admits 21,019 policies;
  238 additional service admissions remain. Original K<=5 has 40,660 queries,
  with 1,269 service and 1,264 completion admissions.
- Gains in the declared KP-1 proxy, in case order, are
  [0,4,0,0,0,4,1,0,9,0,16,8]. Six cases have no gain. These are model retention
  proxy values, with no hardware-memory, PPA or application-performance meaning.

The primary policy input, result CSV, initialization CSV and all 191,473,772
uncompressed delta bytes match the producer byte-for-byte. The delta SHA256 is
`81e302f4cf47988abe7981c64922cef37ccc0a77ab047c35adc6fe9cda93382d`.
The equality is of semantic streams. PE files, PDB GUIDs and gzip containers
are bound by their actual hashes; their timestamp/GUID/mtime fields are not
claimed reproducible.

## Original gate and separate full-key extension

The original empty-frame gate is PASS for 11 controllers and UNKNOWN for
p=r=7,F56. At 3F that controller actually retains two queued requests. This
failure is preserved and is not converted into an empty-frame pass.

The separately declared complete-key experiment validates all 12 cases. Eleven
have entry0/repeatF. The p7/r7 first repeat is entry37/repeat93, d56; F56 itself
is not assumed to be an entry. The four literal prefix triples are
(0,1,42),(7,8,49),(14,15,56),(21,22,63). All cross the entry and remain included
at each policy's original physical P,phi. Cycle extraction checks normalized
before and after live keys and active event translations for two following
periods; edges and callbacks are checked after translations +d and +2d.

The first independent endpoint check failed because the original 4F window did
not contain every +2d crossing endpoint: (91,92,119)+112 needs h231 while 4F ends
at t223. The failed checker/source and partial outputs are retained in
attempt-001-window-endpoint. A separate actual independent 5F control sidecar
now provides 19,120 ticks, 3,824 beyond the primary 4F total. Its first 4F rows
equal the primary actual stream. It closes every two-translation endpoint
check without changing the original source, trace or gate.

The key includes ordered live queue owner/relative-ID tokens, both live
snapshot owner/relative-ID/byte tokens, source/cache/ready/timer phases,
outstanding counts, valid/enabled bits, all timers and tag bytes, and fault/
failed state. Fixed configuration is bound outside the key. IDs are translated
relative to nextid; the checked translation is 8 per F. Dead payload slots
cannot affect a future step: their use is preceded by enqueue/capture overwrite.
Inactive event payloads likewise do not feed control after flags clear. No
live field is discarded to find the repeat.

Every observed entry is empty. Its live key has valid15, enabled0, counts0 and
bytes0. A translated reset uses the actual physical p,r,F,P phases and the
recorded affine ID origin. K is irrelevant while timers are disabled. Thus
the reset matches the zero-WU physical prehistory in live state; omitted dead
payload values are intentionally outside this behavioral equivalence. The
independently regenerated initialization table matches every producer row.

## Separately bound cycle-only supplement

A further fresh Yosys/CXXRTL/compile/execution checks all 6,496 p7/r7 cycle-only
minimizers, for 346,304 actual ticks. Input, results, delta stream and all
initialization rows match the producer. There are 5,498 cycle-local survives
and 998 misses. **271 cycle-local survives are rejected by the exact physical
prefix; full p7/r7 admission remains 5,227.** The original 130,112 full decisions
and tuning bytes are verified unchanged. See PAPER_READY_FACTS for a complete
numeric example. These supplemental runs add finite coverage; they do not
replace the physical prefix or repair the original empty-frame gate.

## Ownership, ties, peaks and mutants

Queue/snapshot ownership is counted independently after every transition,
requiring unique live IDs, per-line token conservation, FIFO capacity and
immutable snapshot bytes. WU and decrement precede source enqueue/read;
entry-R0 occupancy guards capture; old R1 emits, R0 transfers, and callback
retires last. Raw streams exercise 52 multi-enqueue ticks, 325 enqueue/grant
ties, 91 grant/callback ties, and 195 emit/transfer ties. Primary policy runs
exercise 137 expiry=h first-miss ties. They also exercise 9,428 ticks holding
an expired tag's snapshot, 9,356 with blocking.

The original maxima are samples after a tick. The oracle separately observes
the exact pre-grant/pre-callback peak after all enqueues, and verifies EACH
tick's reconstruction FIFO=after_qlen+successful_grant and line outstanding=
after_count+callback_token. All 130,112 producer peak rows and all 48 control/
data peak rows match; both kinds remain separate. The global observed peak is
FIFO7/outstanding7; p5/r5 actually reaches two outstanding IDs on each line.
The two same-owner jobs are not deduplicated.

Five RTL mutants each underwent actual Yosys generation, independent C++
compilation and execution. All were detected by the independent oracle:

| Change | First independent detection |
|---|---|
| omit capture timer cancellation | case0 data0 t40, enabled state |
| emit current live tag byte | case0 data255 t1, emitted byte |
| decrement before applying WU | case0 data0 t1, timer count |
| drop duplicate F40 release | case4 control t0, next ID |
| take the wrong FIFO grant ID | case0 control t0, grant ID |

Their exact inputs, generated netlists, binaries, command logs and first
failures remain under mutants/. This is fault sensitivity, not a proof that
all possible RTL bugs are excluded.

## Independent lifecycle proof and exact safety scope

For every line j the WU contract is STRICT: t must exceed that line's
guaranteed first capture cutpoint. The phrase merely 'not before capture'
would leave same-tick WU-before-expiry/read ambiguous. The actual data and
witness tests use the strict contract; all safety statements here do too.

Under the fixed epoch, source calendar and sink schedule, WUs and timers only
influence control through tag validity on an attempted grant. FIFO enqueues
are independent of callbacks. Pipeline movement depends only on occupancy and
ready phase, not data bytes or counters. Therefore two executions agree in
control until the first failed grant, by induction on the stated event order.
Unique IDs in the queue and immutable snapshots preserve the mapping of each
grant to its callback even with multiple outstanding requests of one owner.

Capture at s disables that line's timer after the read. A WU at integer u>s
arms K, and its Kth decrement is E(u). E is nondecreasing in u because it is
the Kth member at or after u of the same ordered periodic decrement sequence.
Rearming cannot move expiry earlier. Consequently E(s+1)>h suffices for every
optional zero-byte WU word between consecutive same-line captures s,h; no WU
leaves the disabled timer safe. If a first failed grant existed after all
literal prefix and lifted-cycle inequalities were positive, its immediately
preceding same-line capture would contradict this bound. This establishes
conditional arbitrary-WU safety, not finite-word exhaustion. Conversely one
WU at s+1 realizes a nonpositive edge, with expiry before/equal h and no
intervening same-line cancellation. The finite runs check these sharp words.

A full-key repeat establishes the all-hit control recurrence by deterministic
transition and affine ID symmetry. Lifting by P/gcd(P,d) covers every physical
timer phase; every earlier s, including crossing h, remains in the literal
prefix. For completion, actual per-line c satisfies s>=c-J and h<=c+A, with
all c<=h. Monotonicity gives the sufficient completion bound, and independent
explicit translated-edge enumeration agrees with the gcd formula. Both routes
share the SAME exact prefix. This is why local-cycle positives cannot erase
prefix rejection.

The argument requires this epoch, fixed source/ready behavior, immutable
snapshots, valid initial tags, strict cutpoints, and no refill/reset/revocation/
other invalidation. It applies while the declared tick/ID<2^31 and width guards
hold. It does not establish infinite operation of finite 32-bit RTL, arbitrary
coherent data, native HUSH refinement, hardware timing/PPA, silicon, application
traffic/speed, power or energy. Three fixed data patterns test snapshot
semantics; they do not prove arbitrary-data coherence.

## Provenance and preserved corrections

Core receiver, driver, protocol, amendments, extraction/arithmetic and argument
bytes remain equal to the copies frozen before independent execution. An
initial all-files binding check also detected producer-finalization changes to
verify_policy.py (declared query count), derive_peaks.py (path arguments), and
replay_portable.py (separate supplement). The failure and original versions
are preserved in attempt-002-finalization-script-drift; inspected new versions
are separately frozen. They are not retroactively claimed to be the initial
files. No producer builds, initial failures or original negative gates were
overwritten. Command bindings and all actual source/output hashes accompany
this audit.
