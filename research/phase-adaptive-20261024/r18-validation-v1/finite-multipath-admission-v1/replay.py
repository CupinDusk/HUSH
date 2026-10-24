"""Losslessly unpack retained research data, rerun analysis, verify result bytes."""
from pathlib import Path
import base64,hashlib,io,json,subprocess,sys,zipfile
HERE=Path(__file__).resolve().parent
blob=base64.b64decode((HERE/'RECORDED_DATA.zip.b64').read_bytes())
assert hashlib.sha256(blob).hexdigest()=='4938ff352b6d1fc98b91eb1053ddb29366e4f95190a88053b6883576dff9323f'
with zipfile.ZipFile(io.BytesIO(blob)) as archive:
    assert all(not Path(name).is_absolute() and '..' not in Path(name).parts for name in archive.namelist())
    archive.extractall(HERE)
for name in ['run_multipath.py']:
    subprocess.run([sys.executable,'-B','-X','utf8',str(HERE/name)],cwd=HERE,check=True)
expected=json.loads((HERE/'EXPECTED_SCIENTIFIC_HASHES.json').read_text(encoding='utf-8'))
actual={name:hashlib.sha256((HERE/name).read_bytes()).hexdigest() for name in expected}
assert actual==expected,(expected,actual)
print('Research data unpacked and all scientific output hashes reproduced.')
