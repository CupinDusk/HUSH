# Ordered phase-call sensitivity

Run `python -B -X utf8 verify.py` with Python 3.12 or later. It checks file hashes, replays all 24 cases in a fresh temporary directory, and compares every result byte for byte.

The predeclared sweep uses the frozen FIR4 ordered path, Fixed K=100 with boundary-2/final release, and Future/Cap K=(254,16,1). Two equal non-partition caller delays are placed immediately before the phase changes. Each delay is 0, 8, 16, 32, 48, 64, 96, or 128 cycles. These are frozen-plan comparisons; Fixed is not reoptimized at each delay.

Every caller advances retention at its actual path position before reads are classified. All 24 executions pass the independent line-version observer, safe-hit checks, and recomputed reader-bound checks. The complete CSV and raw predictions, captures and writer commits are included. No outcome is filtered by budget feasibility.

This is a two-client independent Python event model, not an RTL or gem5 run. Its response scheduling and measured R/WU/J form their own evidence series. The hardware-contract proof and original RTL/gem5 results remain separate in the parent research collection. The inherited source identities and parent archive hash are recorded in SUMMARY.json.

The fixed receiver budget used in the paper figure is 5840 cycles. Future and Cap have the same static certificate; their runtime update counts are retained separately. The figure uses W/budget, not observed speedup. At two 32-cycle callers the phase certificate meets the budget. Every 48/64/96/128-cycle outcome is retained too.

Archive: [hush-ordered-caller-sensitivity-r62-v1.zip](hush-ordered-caller-sensitivity-r62-v1.zip)

SHA-256: `e9ad7cac6c9fb122304110a41f228cd9c569a404bfed36eeddf4e091d40d7757`
