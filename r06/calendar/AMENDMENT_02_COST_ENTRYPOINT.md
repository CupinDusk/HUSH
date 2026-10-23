# Amendment 02: cost validation entry point

After attempt-002 generation, static inspection found that workflow_cost.py's
new attempt parameter had not been connected to its command-line entry point.
No invocation of that defective entry point occurred, and no timings occurred.
The frozen source remains in both attempt source snapshots. workflow_cost_v2.py
is identical except for accepting --attempt and assigning OUT before validation.
It binds its exact source/codec/record-registry/input/schedule receipts before
validation. No scientific policy, representation, input or cost boundary changes.
