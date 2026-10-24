# Text-only quantized native receiver validation

Run `python -B replay.py --output replay-result.json` with Python3.9+.
The wrapper verifies every text input, decodes only the allowlisted gzip,
then invokes the unchanged recorded scientific replay. All original
scientific inputs and replay outputs remain byte exact.

The gzip is base64-encoded in60KiB character chunks. The decoder checks
each part and the full decoded SHA256/size, rejects path traversal and
symlinks, and writes only `recorded/NATIVE_RECEIVER_TRACES.json.gz`.
`RAW_TO_PUBLIC_MAPPING.json` maps all original inputs to these text files.

See `recorded/README.md` for the native tests, timer oracle, source/binary
bindings and preserved failed attempts. No simulator overlay, native binary,
credentials or actual user/server paths are included. This is packaging of
the already validated recorded observations; no new native experiment,
binary/config change or alteration of scientific results is performed.
