"""Recover the exact first successful source from the preserved syntax failure."""
from pathlib import Path
import hashlib,json
HERE=Path(__file__).resolve().parent
original=HERE/'failure-001-syntax/research.py'
data=original.read_bytes()
assert data.count(b',mutant=value(core(q,1),1,1)')==1
assert data.count(b',true=a,mutant=b')==2
fixed=data.replace(b',mutant=value(core(q,1),1,1)',b',mutant_value=value(core(q,1),1,1)')
fixed=fixed.replace(b',true=a,mutant=b',b',true=a,mutant_value=b')
expected=json.loads((HERE/'attempt-001/START_BINDING.json').read_text(encoding='utf-8'))['research_sha256']
actual=hashlib.sha256(fixed).hexdigest()
assert actual==expected,(actual,expected)
target=HERE/'research-version-001.py';assert not target.exists();target.write_bytes(fixed)
receipt=dict(status='EXACT_FIRST_SUCCESSFUL_SOURCE_RECOVERED',source='failure-001-syntax/research.py',
    source_sha256=hashlib.sha256(data).hexdigest(),changes='Only the three repeated dict keyword numeric fields mutant renamed mutant_value; no other byte changes.',
    recovered='research-version-001.py',recovered_sha256=actual,expected_first_run_sha256=expected)
(HERE/'FIRST_SOURCE_RECOVERY.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
print(json.dumps(receipt,indent=2))
