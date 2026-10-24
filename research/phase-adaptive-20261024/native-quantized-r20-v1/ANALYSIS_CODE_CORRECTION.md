# Selection aggregation correction

2026-10-24T17:53:58UTC, before training completion/collection and before any
performance outcomes or selected values were read: corrected the aggregation
implementation to group only the fixed and phase families eligible for the
already frozen selection rule. WI and WU controls have the same `kind` and
K tuple, so grouping them together would incorrectly fail the three-offset
assertion. Each geometry must have837 selectable records (255fixed plus
24nonconstant phase tuples, times3offsets). All12 training controls remain
in the1686 measurement/reduction rows. No candidate, selection objective,
measured data, driver, binary, configuration or frozen protocol changed.
