"""Strict format parser and guarded scalar evaluator. Does not import encoder."""
import math
import struct


def decode(payload):
    pos = 0

    def take(n):
        nonlocal pos
        if n < 0 or pos + n > len(payload):
            raise ValueError("truncated payload")
        data = payload[pos:pos+n]
        pos += n
        return data

    def unpack(fmt):
        return struct.unpack(fmt, take(struct.calcsize(fmt)))

    magic = take(8)
    if magic == b"HUFULL04":
        variant = "full"
    elif magic == b"HUPORT04":
        variant = "prospective"
    else:
        raise ValueError("unknown magic / query guard")
    if unpack("<I")[0] != 1:
        raise ValueError("unsupported schema version")
    p, b, r, d, maxP = unpack("<5Q")
    if not (p > 0 and b < p and r > 0 and d > 0 and maxP == 4*p):
        raise ValueError("invalid controller header")
    bindings = {name: take(32).hex() for name in ("source", "receiver", "relation", "epoch")}
    count = unpack("<I")[0]
    if count != 2:
        raise ValueError("this schema version requires exactly two lines")
    lines = []
    for _ in range(count):
        owner, tag, capture, entry, g, npre, npairs = unpack("<5Q2I")
        if g == 0 or d % g or (variant == "full" and g != d):
            raise ValueError("invalid support modulus")
        # This lower bound also prevents untrusted counts causing huge loops.
        if 24*npre + 16*npairs > len(payload)-pos or npairs == 0:
            raise ValueError("invalid array counts")
        prefix = [list(unpack("<3Q")) for _ in range(npre)]
        pairs = [list(unpack("<2Q")) for _ in range(npairs)]
        if any(not (capture <= s < entry and s < c < h) for s, c, h in prefix):
            raise ValueError("invalid physical prefix")
        if pairs != sorted(pairs) or len({row[0] for row in pairs}) != npairs:
            raise ValueError("pairs must be sorted with unique residues")
        if any(not (residue < g and span > 0) for residue, span in pairs):
            raise ValueError("invalid residue/span")
        lines.append(dict(owner=owner, tag=tag, initial_capture=capture,
                          cycle_entry=entry, g=g, prefix=prefix, pairs=pairs))
    if pos != len(payload):
        raise ValueError("trailing payload bytes")
    if [(x["owner"], x["tag"]) for x in lines] != [(0, 64), (1, 128)]:
        raise ValueError("incorrect fixed model line identities")
    return dict(variant=variant, p=p, b=b, r=r, d=d, maxP=maxP,
                bindings=bindings, lines=lines)


def complete_slack(record, P, K, phi, expected_bindings):
    if record["bindings"] != expected_bindings:
        raise ValueError("model binding mismatch")
    if P < 1 or K < 1 or phi < 0 or phi >= P:
        raise ValueError("invalid query")
    if record["variant"] == "prospective" and P > record["maxP"]:
        raise ValueError("query is outside the declared portfolio")
    m = math.gcd(P, record["d"])
    values = []
    for line in record["lines"]:
        if line["g"] % m:
            raise ValueError("query gcd is unsupported by payload")
        # Projecting implicitly inside this expression preserves the envelope.
        values.append(1 + min((phi-residue-1) % m - span
                              for residue, span in line["pairs"]))
        values.extend(s+1+(phi-s-1) % P-h for s, c, h in line["prefix"])
    return min(values) + (K-1)*P
