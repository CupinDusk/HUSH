# Independently verified facts for the calendar reference

All claims below concern the new own four-line/FIFO8/two-snapshot reference
receiver. They do not establish native HUSH, coherent memory, PPA, silicon,
application benefit or performance. WUs are permitted only at t STRICTLY
GREATER than each line's guaranteed first capture cutpoint.

- Fresh actual Yosys0.70 -> CXXRTL -> Zig0.14.1 C++ execution; independent
  state/event/byte/timer/ownership oracle and separate arithmetic.
- 12 fixed calendars, K1..16, P1..4p, every phi, one common policy over all four
  lines. Original K<=5 results remain separately available.
- Primary 130,112 one-WU tests actually execute 84,379,472 ticks: 21,257 service
  admits, 21,019 completion admits, 238 service-only admits. All optimum ties
  and no-gain cases retained. Original K<=5: 40,660 tests, 1,269 versus1,264.
- 49,712 primary control/data ticks; 36 data runs on three declared patterns:
  858 capture/emits,714 cancellations,1,116 blocks,135,792 WUs.
- Original empty-frame gate: 11 pass, p7/r7,F56 UNKNOWN with two queue tokens
  at 3F. Separate full-key experiment: all12 cycles; entry0/repeatF except
  p7/r7 entry37/repeat93,d56. Four crossing prefix edges remain literal.
- Independent actual 5F continuation sidecar executes19,120 control ticks,
  including3,824 extra beyond the original4F. This closes every +2d crossing
  endpoint without altering the original gate or traces.
- Snapshots remain immutable across expiry:9,428 actual policy ticks hold a
  snapshot after its tag expires,9,356 with blocking. Five meaningful actually
  synthesized/compiled RTL mutants are detected independently.
- Original maxima are after-tick samples. Exact event-order peaks are stored
  separately and independently verified. Observed peakFIFO7, global7; p5/r5
  reaches two outstanding requests on each line, preserving duplicate calendar
  jobs with distinct request IDs.

**Prefix matters:271 cycle-local positive policies still fail fresh admission.**
The separate p7/r7 cycle-witness supplement executes6,496 additional tests and
346,304 actual ticks. It yields5,498 cycle-local positives/998 negatives, but
271 positives fail the exact physical prefix. Full p7/r7 admission remains
5,227; the original full-grid total remains21,257. No supplement count repairs
the original empty-frame UNKNOWN.

A completely specified example is p=r=7,F56,K15,P2,phi0 (KP-1=29), the minimum
proxy among those271, then ordered by K,P,phi. Line1's first capture cutpoint
is7. The fresh physical prefix edge is (s,c,h)=(7,8,49). Put a single WU at8;
decrements8,10,...,36 expire the tag at36, giving slack36-49=-13 and an actual
first miss at49, owner1/requestID6. No WU occurs at/before cutpoint7.

The SAME policy's separate cycle-local test starts at validated empty entry37,
with cache phase2, sink phase2, calendar phase37, physical timer phase1 and
the explicit affine ID origin. Its earliest
minimizing cycle edge is (49,50,77). A single WU at50 would expire at78, giving
slack+1; actual grant77 succeeds and cancels the timer, so no expiry occurs.
This is a distinct WU execution from the prefix example. Local survival is
insufficient for a fresh-policy decision. The four required prefix triples
are(0,1,42),(7,8,49),(14,15,56),(21,22,63), each crossing entry37.

The arbitrary-zero-byte-WU statement is a conditional first-failure/rearm
proof under fixed epoch/source/readiness, strict cutpoints, initial validity,
immutable snapshots and no other invalidation, while tick/ID width guards
hold. It is not an assertion that finite one-WU tests exhausted all words.
Omitted primary prehistory440,303,104 ticks is NOT actual execution.

Per-case proxy gains are[0,4,0,0,0,4,1,0,9,0,16,8]; cases0,2,3,4,7,9 have no
gain. Exact s/c/h,C0,J,A, admissions, optimum ties, starts, hashes, original
failures, supplemental scope and the numerical counterexample are in the
accompanying JSON and independent tables.
