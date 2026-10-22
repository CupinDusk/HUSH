# R04 explicit demonstration record, version 1

This is one uncompressed little-endian file format. All integer fields are unsigned. There is no alignment padding, deduplication across files, string table, variable-length integer encoding, implicit prefix regeneration, or compression. It is not a minimum-byte encoding. Source scripts are ordinary text, not a native executable or hardware implementation.

The frozen `PROTOCOL.json` declares the field layout. The choices below instantiate that layout without changing that protocol. The only variant differences are the eight-byte magic/query guard, support modulus, pair count, and pair array; metadata, all four actual bindings, cutpoints, and exact physical prefix remain the same.

| Field in order | Width | Value/meaning |
|---|---:|---|
| Magic | 8 bytes | ASCII `HUFULL04` for universal full master; `HUPORT04` for the declared portfolio |
| Version | u32 | 1 |
| p, b, r, d, maxP | 5 × u64 | Original configuration, exact recurrence translation, and `maxP=4p` |
| Source binding | 32 bytes | SHA256 of frozen `extract_shared.py` |
| Receiver binding | 32 bytes | SHA256 of frozen R03 `PROTOCOL.json`, including receiver/callback order |
| Relation binding | 32 bytes | SHA256 of the complete frozen `RELATIONS.json` |
| Epoch binding | 32 bytes | SHA256 of the explicit stipulated epoch text in `SERIALIZED_RECORDS.json` |
| Number of lines | u32 | 2 in this version |
| Per-line owner, tag, initial capture, cycle entry, g | 5 × u64 | Owner 0/1 and tags 64/128; original physical cutpoints; support modulus |
| Per-line prefix count, pair count | 2 × u32 | Lengths of the following arrays |
| Prefix entries `(s,c,h)` | 3 × u64 per entry | Absolute ticks, unchanged; never reduced modulo g |
| Profile entries `(residue,span)` | 2 × u64 per entry | Sorted canonical profile at g; positive span |

The controller header occupies 184 bytes. Each line adds 48 metadata bytes, 24 bytes per exact prefix edge, and 16 bytes per profile pair. With two lines, total size is `280 + 24×prefix_edges + 16×pairs` bytes. Every controller is a separate complete record and pays its own header and bindings. File names and the JSON index are outside these record byte counts; the reported totals measure exactly the `.bin` payloads. They do not measure Python objects, runtime memory residency, disk allocation, or an entire packaged archive.

The epoch text is an explicit **stipulated component-model epoch**. These hashes are file/model bindings for this demonstration. They do not establish a native runtime identifier, epoch management, revocation protocol, or correspondence with historical native HUSH. `qA=2p+1`, `qB=3p+1`, all other constant controller rules, initial zero payload and callback order are bound through the frozen source/protocol. The payload cannot be used as an unbound safety result: its scalar evaluator requires the expected four bindings to match exactly.

`HUFULL04` is a universal full-master representation at `g=d`. Its scalar arithmetic supports positive P, positive K, and `0≤phi<P` under the bound relation. The 37,000 frozen queries are its tested grid. `HUPORT04` additionally rejects `P>maxP`; it is the declared-portfolio representation. Both guards reject a query if `gcd(P,d)` does not divide each stored g. A caller may not treat a portfolio payload as universal just because an extra P happens to have a compatible gcd. No exact slack is returned for a rejected query; a complete full record is the available fallback.

The decoder checks magic, version, fixed line identities, sizes, positive/dividing moduli, prefix cutpoints, sorted unique residues, positive spans, truncation, and trailing bytes. Its evaluator checks bindings and query guards, computes the unchanged physical-P prefix, and combines it with the gcd recurrence envelope. Strict round trips compare every decoded field with the producer's intended record. Malformed-record and wrong-binding tests are retained in `RESULTS.json`; these are producer tests, not a claim of independent implementation validation.
