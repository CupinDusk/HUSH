# Bounded new RTL evidence; independent gate pending

Suggested bounded result statement after independent validation:

“We additionally implemented the specified two-client receiver as synthesizable RTL. Yosys 0.70 generated a CXXRTL netlist, which was compiled and executed against all frozen controller schedules and policy tests. Its 40 complete traces agree over 22,823 logical ticks. All 37,000 one-WU minimum-edge tests reproduce the predicted 17,387 survivals and 19,613 first-failed-read witnesses. An additional 120 fixed-byte-pattern traces preserve capture identity/value under backpressure and cancel armed counters on successful capture. This is a new reference implementation of the specified component; native HUSH refinement, arbitrary-data coherence and hardware benefit remain unverified.”

Author-run details: 25,137,870 policy ticks; data controls 68,469 ticks, 9,897 captures, 9,807 emissions, 9,657 timer cancellations and 1,071 blocked-response ticks. These are logical simulation coverage counts, not measured hardware throughput. Sixteen-bit tick/ID arithmetic suffices for the tested horizon (maximum policy target 7,332); three-bit counters and eight-bit bytes are explicit.

Adverse scope to preserve: 14/40 cases have no actual backpressure; all 40 reach FIFO occupancy two but the separate R0-occupied-with-queued-head grant-block condition is unexercised. All 19,613 negatives remain failures, not repaired misses. Positive one-WU tests do not exhaust arbitrary WU schedules. Only three predetermined data words were tested; no replacement, ownership, coherent memory, revocation recovery, changing-clock behavior or hardware measurements are established. No gate result should be called full native HUSH validation.

Current gate: author synthesis/compile/generated-netlist execution **passed**; separate checker and fresh portable rebuild **pending**. Do not quote an independent-validation result until its actual evidence exists. The initial generator path failure is preserved in `failure-01-generator-path/` and described in README; no RTL synthesis or simulation failure occurred in build-01.
