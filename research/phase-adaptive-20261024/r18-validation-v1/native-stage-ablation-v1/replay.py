"""Losslessly unpack retained research data, rerun analysis, verify result bytes."""
from pathlib import Path
import base64,hashlib,io,json,subprocess,sys,zipfile
HERE=Path(__file__).resolve().parent
blob=base64.b64decode((HERE/'RECORDED_DATA.zip.b64').read_bytes())
assert hashlib.sha256(blob).hexdigest()=='2c7bb606fb5be78d2833c37e0551db8af8bf634e7dbec1f2d132b9c798b79b53'
with zipfile.ZipFile(io.BytesIO(blob)) as archive:
    assert all(not Path(name).is_absolute() and '..' not in Path(name).parts for name in archive.namelist())
    archive.extractall(HERE)
for name in ['reduce.py', 'reduce_legacy_pairs.py']:
    subprocess.run([sys.executable,'-B','-X','utf8',str(HERE/name)],cwd=HERE,check=True)
expected=json.loads((HERE/'EXPECTED_SCIENTIFIC_HASHES.json').read_text(encoding='utf-8'))
actual={name:hashlib.sha256((HERE/name).read_bytes()).hexdigest() for name in expected}
assert actual==expected,(expected,actual)
print('Research data unpacked and all scientific output hashes reproduced.')
