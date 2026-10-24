# Pipeline checksum versus changing-payload tests

The immutable protocol's `correctness` string used the phrase
"expected changing-payload checksum". The unchanged pipeline ELF actually
refreshes constant values and checks the FIR/feature checksum. Its driver
requires TEST PASSED, terminal0, markers, invariants and epoch sums; it does
not establish version freshness from that checksum. This wording is
clarified without editing the frozen protocol or changing any input,
endpoint, driver or selection rule.

Changing-payload correctness is evaluated separately by the24 C11
release/acquire runs in native-quantized-validation-r20-v1, which perform
168480 version comparisons with zero stale values. Manuscript and public
README distinguish these endpoints. Full frozen protocol provenance stays
byte-exact.
