# Independent-stage native follow-up
Exploratory mechanism-family extension after the540-run lag sensitivity.
Three phases choose independently from128/2048/16384, all finite encodable
atP128 withK1/16/128.41 N16training cases freeze the best nonconstant phase
before18 N32timings;36 N36/N40 replication cases follow with no retuning.
All95 runs and all15fixed controls per input are included, including the
training-selected fixed mode and all signed outcomes. This evaluates a
frozen phase candidate, not a native WCET or cost-aware deployment proof.

Run python -B reduce_stage3.py to audit selection, inputfreeze, encoding,
controls and results. Git LF and Windows CRLF representations are accepted
only when they reproduce the original training-input bytes.
Native reexecution uses a compatible HUSH-enabled gem5 build (private overlay
and binary excluded), HUSH_GEM5_BINARY and HUSH_PIPELINE_BINARY. Compile
fir_pipeline_v3.c with gcc -static -pthread -O2 -std=c11 -fno-pie -no-pie,
public gem5/include and gem5/util/m5/src/abi/x86/m5op.S, then use
run_native.py MANIFEST.json. Same binary, real64lag work; no added delayloop.
No paper/reviews/server identity/credentials are included.
