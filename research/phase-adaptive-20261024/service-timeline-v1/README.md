# Directed two-client service timelines

Run `python -B probe_service71.py`. The result must match `EXPECTED_TRACES.json`.
The script uses read-only Python tracing of the unchanged bounded model; it
does not edit the model. One outstanding reader operation and writer operation,
60-cycle miss service, 10-cycle write-update service, one-cycle private stores
and nonpreemptive round robin are the contract.

The conservative read envelope is 1+10+60=71: one already admitted private store
and at most one other-client WU can precede the miss. A pending miss prevents
later private-store admission. A reader cannot issue a configuration while its
read is outstanding. Therefore the configuration-delivery collision can occur
only when a WU is completing at the miss-issue cycle; it adds one residual cycle,
not an independent extra cycle to a full ten-cycle WU wait. That writer cannot
also have a private store in flight. This collision case is bounded by 1+60.

The three directed examples show service61 for private-store admission,
service70 for a full WU wait, and service61 when config extends a finishing WU.
These examples illustrate the argument, not an exhaustive state-space proof or
a witness that71 is attained. This is a two-client analytical architecture
model, not gem5 or a four-core native-system service-bound claim.

All inputs and expected events are retained. The finite cache geometry is not
selected in these timing examples; replacement does not change the service
classes within the separate clean-receiver contract.
