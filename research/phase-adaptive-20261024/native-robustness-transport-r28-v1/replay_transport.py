"""Verify transport ZIP bytes, extract safely, and invoke its portable replay."""
from pathlib import Path,PurePosixPath
import hashlib,json,subprocess,sys,tempfile,zipfile

BASE=Path(__file__).resolve().parent
record=json.loads((BASE/'TRANSPORT_MANIFEST.json').read_text(encoding='utf-8'))
archive=BASE/record['archive']['path']
assert archive.stat().st_size==record['archive']['bytes'],'ZIP size mismatch'
assert hashlib.sha256(archive.read_bytes()).hexdigest()==record['archive']['sha256'],'ZIP hash mismatch'
with tempfile.TemporaryDirectory(prefix='hush-transport-bundle-') as temp:
    target=Path(temp)
    with zipfile.ZipFile(archive) as z:
        for name in z.namelist():
            relative=PurePosixPath(name)
            assert not relative.is_absolute() and '..' not in relative.parts and '\\' not in name,'Unsafe ZIP member'
        z.extractall(target)
    command=[sys.executable,'-B','-X','utf8',str(target/'transport/replay_transport.py'),*sys.argv[1:]]
    raise SystemExit(subprocess.run(command).returncode)
