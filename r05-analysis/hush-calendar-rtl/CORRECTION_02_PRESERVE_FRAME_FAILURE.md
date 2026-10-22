# Observed frame-domain failure, unchanged controller

build-02 is the first actually executed generated netlist. It preserved
p=r=7,F=56 with 24 enqueues and only 22 captures/callbacks over [0,168).
Two queued requests remain at t=168; no invariant/width fault occurred.
The driver stopped after saving that run because its frame-clear assertion
was unconditional. This is an actual fixed-case negative result, not a
reason to change the calendar or controller.

Correct the reporting driver to record FRAME_NOT_CLEAR_CERTIFICATE_UNKNOWN
and continue the rest of all 12 control/36 data runs. The RTL is unchanged.
The empty-frame composition/admission certificate will be withheld for this
case. Any separately computed diagnostics must retain that unknown status.
This correction does not turn the frame failure into a pass.
