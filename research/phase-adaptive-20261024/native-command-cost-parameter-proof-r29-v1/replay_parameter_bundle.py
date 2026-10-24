"""Check and extract the parameter proof ZIP, then run its composition replay."""
from pathlib import Path,PurePosixPath
import hashlib,json,subprocess,sys,tempfile,zipfile

BASE=Path(__file__).resolve().parent
manifest=json.loads((BASE/'PARAMETER_BUNDLE_MANIFEST.json').read_text(encoding='utf-8'))
record=manifest['archive'];archive=BASE/record['path']
assert archive.stat().st_size==record['bytes'],'ZIP size mismatch'
assert hashlib.sha256(archive.read_bytes()).hexdigest()==record['sha256'],'ZIP hash mismatch'
with tempfile.TemporaryDirectory(prefix='hush-parameter-bundle-') as tmp:
    target=Path(tmp)
    with zipfile.ZipFile(archive) as z:
        for name in z.namelist():
            path=PurePosixPath(name)
            assert not path.is_absolute() and '..' not in path.parts and '\\' not in name,'Unsafe ZIP member'
        z.extractall(target)
    command=[sys.executable,'-B','-X','utf8',str(target/'parameter-proof/replay_composition.py'),*sys.argv[1:]]
    raise SystemExit(subprocess.run(command).returncode)
