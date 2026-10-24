"""Decode verified recorded JSON inputs with a fixed-name allowlist; never exec."""
from pathlib import Path,PurePosixPath
import base64,hashlib,io,json,stat,zipfile
HERE=Path(__file__).resolve().parent
ARCHIVES = {'bound': ('EXPECTED_BOUND_ROWS.zip', 'EXPECTED_BOUND_ROWS.json', 'a98b5a5ec9e9478b4a6a37c50c85de900ccb4ae182ad8955ac916bfb482daa02'), 'full': ('EXPECTED_FULL_TRAINING.zip', 'ALL_CANDIDATES.json', '3514ef82ffee027a82671ea5ab7d252adabdbbf5c6c372292e85f2508d0e1717')}
def load_expected(kind):
    archive_name,member_name,archive_sha=ARCHIVES[kind]
    encoded=''.join((HERE/(archive_name+'.b64')).read_text(encoding='ascii').split())
    raw=base64.b64decode(encoded,validate=True)
    assert hashlib.sha256(raw).hexdigest()==archive_sha,'Recorded archive checksum mismatch'
    with zipfile.ZipFile(io.BytesIO(raw)) as archive:
        members=archive.infolist()
        assert len(members)==1 and members[0].filename==member_name,'Unexpected archive member'
        info=members[0];member=PurePosixPath(info.filename)
        assert not member.is_absolute() and len(member.parts)==1 and member.name==member_name
        assert member_name not in ('','.','..') and '/' not in member_name and '\\' not in member_name
        assert not info.is_dir() and stat.S_IFMT(info.external_attr>>16)!=stat.S_IFLNK
        assert info.file_size<10*1024*1024,'Recorded input too large'
        payload=archive.read(info)
    # Only these fixed, nonexecutable relative JSON filenames may be written.
    destination=HERE/'recorded-data';destination.mkdir(exist_ok=True)
    target=destination/member_name
    assert target.resolve().parent==destination.resolve()
    target.write_bytes(payload)
    return json.loads(payload)
