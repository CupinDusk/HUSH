# R29 additive scientific evidence

Run with standard-library Python:

```text
python -B -X utf8 replay_native_cost.py
python -B -X utf8 replay_parameter_bundle.py
```

Both bootstraps check their same-directory ZIP and extract into an independent temporary directory. Default execution verifies the recorded science and does not start a native simulation or a new SAT solver run.

The native package contains 135 new command-delay sensitivity runs and 27 exact cost-8 observations reused from R28: 162 cases, 648 epochs and 54 cost × size × policy summary rows. All conditions, signed comparisons and N24 failures are retained. The three measured policies are Phase(1,128,1), fixed K3 and frozen K253 at 32 KiB, N20/24/28 and offsets 0/64/127, for costs 0/4/8/16/32/64. Each near-speed guard uses K253 at the same cost, size and offset; this is an empirical objective, not an externally specified deadline.

The parameter is an additional `m5_quiesce_cycle(c)` request by reader0 at each changed boundary. Helper instructions, markers and barriers are already part of measured time. The eight configuration API invocations are four private L1 controllers × two changed markers, not eight guest MMIO stores. Cost 0 skips the quiesce call and corresponding instruction path but retains the native next-edge configuration and coincident-input interlock. The results are not a pure linear delay estimate, actual MMIO latency measurement or an MMIO upper bound. No new-cost full-128-offset claim is made.

The original seven native policies are documented separately in the native ZIP. WI uses write-invalidate; WU uses write-update with forwarding without HUSH expiry. Suppression keeps the phase CLI and its helper/comparison branches while disabling configuration writes, leaving the initial K1 timer. Fixed K1 has an unchanged CLI and no changed-boundary guest pause. These are different control paths. The 64 KiB Phase remains an undeployed diagnostic. The other four policies were not newly executed at every R29 cost.

The parameter proof package preserves arbitrary-line temporal induction at N4/N64/N512, the original queue/K logic, mutation counterexamples, original kernel/reference dependency-cone checks and uniform N-independent loop-body checks. These support the stated structural, line-wise composition argument. Full-bank N4 induction was proved; full-bank N64 and N512 remain `timeout_unknown` after their recorded limits. They are never relabeled monolithic SAT passes. See PARAMETER_BUNDLE_README.md for an optional fresh `--yosys` rerun and the separately limited `--full-bank` diagnostic.

The actual HUSH-enabled native simulator overlay and executable remain excluded. The included configuration, guest workload and generic runner are byte-identical to the previously authorized R20 scientific release; their original commit paths, sizes, SHA256 and Git blob SHA1 are recorded in NATIVE_BUNDLE_MANIFEST.json. There are no local server/account/credential details. `.gitattributes` disables text conversion so publication preserves exact bytes.
