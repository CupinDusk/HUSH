# R55: ordered analysis and native application follow-up

Additive research material for Phase-Adaptive HUSH. Earlier receiver, FIR,
matrix, budget and phase-diagnostic collections remain unchanged.

* hush-ordered-transfer-r55-v1.zip: independent ordered timer/LRU transfer
  executor; 22,470 nominal certificate and per-read replays, 97 frontier
  carry/reset checks and 33 caller-cost settings. This is analysis replay,
  not a new timing measurement. Run REPLAY.py after extraction.
  SHA256 a89d6b05dd8bd8b0bcc39d023be8f922ba20c953745ef2330fc43cb92ace3fe9
* hush-native-prospective-applications-r55-v1.zip: 26 new gem5 application
  runs, all 24 phase/control comparisons, frozen plans, sanitized numerical
  outputs and source bindings. Offline VERIFY reproduces all 964 checks.
  SHA256 f4a38f03f7619761a0753ddcc6c6b5335fae8d9c7b467294df875230bb40b9db

Native runs use four 1-GHz TimingSimple CPUs, continuous prospective
deadlines and a modeled eight-cycle marker cost. They exercise application
integration; quantized Cap/Future service certificates belong to the
separate receiver study. Every control and component-bound diagnostic is
retained. Normalized (parallel ROI, WU) against each application's fastest
of six tested fixed zero-cost-marker settings is
FFT (1.0020867645, 0.6649616368), Radix (0.9998479540, 1.0947036128).

These archives contain research inputs/outputs/checks only. No manuscript,
peer reviews, remote transport implementation or authentication material
is included. Both archives passed independent extraction and recomputation.
