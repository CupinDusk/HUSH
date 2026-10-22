# Compilation and positive-path execution coverage

The v1/v2/v3 packages and earlier PDFs retain five byte-exact upstream MemTest definitions in their generated translation units: tick, sendPkt, recvRetry, completeRequest and CpuPort::recvTimingResp. Earlier prose that says five functions execute over the positive configurations is too broad.

All five definitions are included and compiled. The ordinary accepting-port positive path exercises tick/sendPkt and the response callback/completeRequest path. Its no-retry guard means recvRetry is not exercised by those positive configurations. Inclusion and hashing are not per-function execution coverage. No instrumentation-based function coverage was collected, and this correction does not claim such a report. The existing source traces, configuration outcomes, event hashes and arithmetic results are unchanged.

The 372 admitted configurations are the mixed-poll study's admitted parameter domain, not 372 recurrent two-branch cycles. Reusing and matching the existing source traces confirms 90 recurrent cycles with both response-before-poll and wait branches, and 282 with only the wait branch. Their populated service-phase counts are 1:282, 2:63, 3:12, 4:15. Transient branch behavior is separate from this recurrent census.

The minimal-load theorem is conditional on all receiver-model WU schedules admitting the earliest subsequent arm r=s+1, with the timing/residency premises held fixed. A restricted WU language can admit a smaller safe load. No receiver, queue, cache or hardware execution is added by this clarification.

Earlier archives, publication notes, frozen PDFs and reviewer scores remain immutable. This erratum and the v4 documentation supersede their broader coverage wording; they do not change a failed or weak recommendation to Accept.
