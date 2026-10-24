"""Verify the R30 analysis ZIP and replay its offline standard-library checks."""
from pathlib import Path,PurePosixPath
import hashlib,json,subprocess,sys,tempfile,zipfile

BASE=Path(__file__).resolve().parent
manifest=json.loads((BASE/'MANIFEST.json').read_text(encoding='utf-8'))
for row in manifest['files']:
    name=PurePosixPath(row['path'])
    assert not name.is_absolute() and '..' not in name.parts and len(name.parts)==1
    data=(BASE/row['path']).read_bytes()
    assert len(data)==row['bytes'] and hashlib.sha256(data).hexdigest()==row['sha256'],row['path']
    assert hashlib.sha1(b'blob '+str(len(data)).encode()+b'\0'+data).hexdigest()==row['git_blob_sha1'],row['path']
archive=BASE/manifest['archive']
with tempfile.TemporaryDirectory(prefix='hush-r30-public-') as temp:
    target=Path(temp)
    with zipfile.ZipFile(archive) as z:
        assert z.testzip() is None
        for name in z.namelist():
            path=PurePosixPath(name)
            assert not path.is_absolute() and '..' not in path.parts and '\\' not in name
            assert all(':' not in part for part in path.parts),'Unsafe ZIP member'
        z.extractall(target)
    command=[sys.executable,'-B','-X','utf8',str(target/'analysis/replay_analysis.py'),*sys.argv[1:]]
    raise SystemExit(subprocess.run(command).returncode)
