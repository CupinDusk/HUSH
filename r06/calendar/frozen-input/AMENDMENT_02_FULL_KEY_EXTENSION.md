# Separate post-observation complete-key cycle experiment

Read the parent plan's appended full-key extension before implementation.
Original build-03 contains all twelve [0,3F) control and 36 fixed data runs.
Its p=r=7 empty-frame gate remains FAILED/UNKNOWN, with two FIFO tokens;
this original result is not replaced.

The newly authorized experiment extracts the FIRST repeated complete live
control key from actual netlist traces for every one of the twelve cases.
Key: calendar/cache/ready phases, FIFO length and ordered owner/ID tokens,
R0/R1 occupancy and owner/ID/byte snapshots, outstanding counts, tag validity,
timer enabled/counts, tag bytes, fault/miss state. IDs are normalized relative
to nextid, preserving all live equality/order/ownership relationships; the
affine nextid translation is recorded and checked. Dead queue slots and dead
snapshot fields are excluded because enqueue/capture overwrites them before
any read. Epoch/configuration is unchanged. Clock carries physical P-phase
only when each concrete policy is initialized; control extraction uses P=1.

Collect [0,4F) control ticks, retaining first-three-frame traces and checking
two full translated periods after the first repeated key. Data runs remain
exactly [0,3F), 36 runs. All edges before the verified entry stay in the exact
physical prefix, including h crossing entry. Completion c>h remains unknown.
If an entry is empty, reset with its actual translated source/cache/ready/P
phases and disabled all-valid tags is equivalent to no-WU all-hit prehistory.
If nonempty, run the physical prefix from t=0 rather than silently clearing it.
The original empty-frame gate and extended full-key result are separate fields.

Every policy still receives actual edge execution. The full policy tick
transcript uses a lossless delta/varint binary representation: it stores every
after-state field other than deterministic tick/phases, plus all event fields;
tick/phases derive exactly from declared start/configuration. Each query begins
a fresh zero delta baseline, and its reset state is fully specified. A decoder
and precise schema will be delivered. This avoids bulky duplicate CSV text;
it does not omit prehistory from accounting or count initialization as execution.
