# R28 WU transport evidence bundle

`transport-inputs.zip` contains the complete, SHA256-manifested transport RTL, formal harness, expected proof/mapping receipts, eleven result logs, provenance record and portable replay. `TRANSPORT_MANIFEST.json` pins the ZIP and its members. Only a Python standard library is needed for the default integrity check:

```text
python replay_transport.py
```

To rerun all five SAT cases and all six matched mappings:

```text
python replay_transport.py --yosys /absolute/path/to/yosys --library /absolute/path/to/NangateOpenCellLibrary_typical.lib --output ./fresh-transport
```

The wrapper verifies the archive, safely extracts it to a temporary directory and runs its contained replay. The ZIP's `transport/README.md` explains the four-line induction assumptions, four fault-detection controls, mapped hardware boundary and pinned external library. Yosys 0.70+190 (git `485b63564`) reproduces all six recorded numeric mapping rows exactly. The mapping uses the same one-entry 64-bit address/data WU queue in fixed and phase-adaptive designs. It is a pre-layout comparison of that port and timer receiver; it does not establish software/MMIO latency or complete-system WCET.

Host-specific temporary path prefixes in mapping logs are replaced with `<local-temp>`. Original and public log hashes are retained in the ZIP's provenance record. RTL, command semantics and reported numeric results are unchanged. No simulator binaries, private protocol overlay, local runtime paths, manuscript or server configuration are included.
