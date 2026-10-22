"""Explicit demonstration format; no optimal byte-encoding or native-ID claim."""
import struct

MAGICS = {"full": b"HUFULL04", "prospective": b"HUPORT04"}
VERSION = 1


def encode(record):
    """Encode only the fields documented in SCHEMA.md, with no padding."""
    chunks = [MAGICS[record["variant"]], struct.pack("<I", VERSION)]
    chunks.append(struct.pack("<5Q", *(record[k] for k in ("p", "b", "r", "d", "maxP"))))
    for name in ("source", "receiver", "relation", "epoch"):
        raw = bytes.fromhex(record["bindings"][name])
        if len(raw) != 32:
            raise ValueError("binding must be a SHA256 digest")
        chunks.append(raw)
    chunks.append(struct.pack("<I", len(record["lines"])))
    for line in record["lines"]:
        chunks.append(struct.pack("<5Q2I", *(line[k] for k in
            ("owner", "tag", "initial_capture", "cycle_entry", "g")),
            len(line["prefix"]), len(line["pairs"])))
        chunks.extend(struct.pack("<3Q", *row) for row in line["prefix"])
        chunks.extend(struct.pack("<2Q", *row) for row in line["pairs"])
    return b"".join(chunks)


def structural_size(record):
    return 184 + sum(48 + 24 * len(x["prefix"]) + 16 * len(x["pairs"])
                     for x in record["lines"])
