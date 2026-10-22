# Evidence schemas

`PROTOCOL.json` is the original literal protocol. Amendments 01 and 02 take
priority, in order. `PROTOCOL_INITIAL_LITERAL.json` and build-01 preserve the
initial bytes. The parent plan also records both amendments. They distinguish
the pre-execution F=40 multiset clarification from the post-observation full-key
experiment after the F=56 frame gate failed.

`CONTROL_TICKS.csv` / `DATA_TICKS.csv`: exact integer columns named in the
header. Each row includes configuration, absolute physical t, WU mask and four
little-endian packed WU bytes; complete before/after state; every event flag
and event owner/ID/byte. `evenq` is a count 0,1,2. Slot one precedes slot two;
both slots have independent IDs. Stale event payloads are retained while
their flag is zero. `qowners` packs eight two-bit owners, oldest in low bits;
`qid0..7` retain all slots. Only indices below qlen are live. `outstanding`
packs four four-bit counts; tag bytes pack four eight-bit words. Timers have
four separate sixteen-bit counts. R0/R1 fields are live iff their valid bit
is one. Each row's before state equals the preceding after state in its run.
Counters are ordinary unsigned integers; negative sentinel fields occur only
in derived witness/result CSV files. Dead fields remain in raw evidence.

Original build-03 runs control [0,3F) and each data pattern [0,3F). Full-key
extension build-04 controls [0,4F), while data still covers exactly [0,3F).
`RUN_COUNTERS.csv` keeps per-run maxima, counts and final outstanding state.
The F=56 run's incomplete retirement is not treated as token loss or hidden.

`RELATIONS.json`: one row per fixed case, original frame-gate status plus
distinct extension status, cycle entry/repeat/ID translation and complete
raw entry state. Each line lists actual initial capture, prefix and cycle
triples (s,c,h), actual completion residues C0, and tight J,A. Every repeated
cycle relation is checked against the next two periods in the actual trace.

`ALL_PHASES.jsonl.gz`: lossless gzip JSON lines. Header describes fields. Each
case/P row has all phi rows, exact fresh physical prefix base, global cycle
base, per-line bases, completion base, global earliest witness, complete
16-bit admission masks and nested 5-bit masks. A K=1 base receives (K-1)P.
Witness `[line,s,c,h,kind,n]`; n counts F translations from that cycle edge.
Selection key is (base,s,line,c,h,kind,n), so ties choose earliest physical s.

`policies.txt`: N=130112 then rows
`query case K P phi line s c h arm start n slack expiry`.
`arm=s+1`; `slack=expiry-h`. The input includes every fixed case/P/phi/K.
`POLICY_RESULTS.csv` binds every input and adds physical start phase, actual
expiry/first miss/owner/ID, actual executed tick count and full counters/maxima.
Negative first-miss/expiry sentinels -1 mean no event before the tested h.
`POLICY_INITIALIZATION.csv` records all clock residues, reset/physical ID
origins, omitted physical prehistory (explicitly NOT executed), and actual ticks.

`POLICY_TICKS.delta` is a lossless binary encoding of EVERY executed policy tick,
including the failing tick. Magic eight bytes `HCR5DT01`. Each query begins
little-endian uint32 query ID, uint32 tick count. Its tick count equals h-start+1.
Every query resets the payload delta baseline to 61 zeros. Each tick stores
uint8 number-of-changes, then strictly increasing uint8 payload index followed
by canonical unsigned 32-bit base128 varint new value (low 7 bits first, bit7
continuation, at most five bytes). Unchanged values carry forward. Full payload
order is `STATE[5:] + EVENT` in decode_trace.py; these are all after-state fields
except tick/cp/rp/fp/pp, followed by every event field. The omitted deterministic
five fields equal `(t+1,(t+1)%p,(t+1)%r,(t+1)%F,(t+1)%P)` for
`t=start+tick_index`. Before state is the declared reset state for first tick,
otherwise previous after state. WU input is exactly target bit at arm, zero
elsewhere, WU bytes zero. Thus no executed tick or full state is discarded.
Gzip may wrap this byte stream without changing it; the decoder accepts both.

`TUNING.json` retains every tied optimum, selected policy, empty original5
feasible sets and no-gain controller. Objective KP-1 is a model retention proxy.
`RESULTS.json` is producer arithmetic; final `EVIDENCE_SUMMARY.json` also binds
actual executions and explicitly leaves the independent publication gate open.
