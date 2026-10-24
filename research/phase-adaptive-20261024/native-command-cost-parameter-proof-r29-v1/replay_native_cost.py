"""Verify/extract the bound native cost ZIP and independently replay its scalars."""
from pathlib import Path,PurePosixPath
import hashlib,json,stat,subprocess,sys,tempfile,zipfile
BASE=Path(__file__).resolve().parent
EXPECTED_SHA256="a9599f5bbc2819a22bf1739549d9d35535f08b41d9fb4ce00d0f0031cc4ba710"
manifest=json.loads((BASE/'NATIVE_BUNDLE_MANIFEST.json').read_text(encoding='utf-8'))
record=manifest['archive'];archive=BASE/record['path']
assert PurePosixPath(record['path']).name==record['path'] and '\\' not in record['path'],'Unsafe archive path'
assert archive.stat().st_size==record['bytes'],'ZIP size mismatch'
assert hashlib.sha256(archive.read_bytes()).hexdigest()==record['sha256']==EXPECTED_SHA256,'ZIP hash mismatch'
with tempfile.TemporaryDirectory(prefix='hush-native-cost-r29-') as tmp:
    target=Path(tmp)
    with zipfile.ZipFile(archive) as z:
        names=z.namelist();assert len(names)==len(set(names))==record['members'],'Duplicate or missing ZIP members'
        assert sum(i.file_size for i in z.infolist())<64*1024*1024,'Unexpected archive size'
        for info in z.infolist():
            p=PurePosixPath(info.filename)
            assert not p.is_absolute() and '..' not in p.parts and '\\' not in info.filename and ':' not in info.filename,'Unsafe ZIP member'
            assert not stat.S_ISLNK(info.external_attr>>16) and not info.flag_bits&1,'Unsupported ZIP member'
        z.extractall(target)
    public=json.loads((target/'PUBLIC_MANIFEST.json').read_text(encoding='utf-8'))['files']
    assert set(names)==set(public)|{'PUBLIC_MANIFEST.json'},'Unexpected ZIP contents'
    def verify():
        for name,entry in public.items():
            p=target/name
            assert p.stat().st_size==entry['bytes'] and hashlib.sha256(p.read_bytes()).hexdigest()==entry['sha256'],name
    verify()
    for script in ['replay.py','independent_check.py']:
        result=subprocess.run([sys.executable,'-I','-B','-X','utf8',str(target/script)],cwd=target,capture_output=True,text=True,encoding='utf-8')
        if result.returncode:
            sys.stderr.write(result.stdout+result.stderr)
            raise SystemExit(result.returncode)
    verify()
    check=json.loads((target/'INDEPENDENT_CHECK.json').read_text(encoding='utf-8'))
    assert check['pass'] and check['fresh_cases']==135 and check['reused_exact_cases']==27 and check['scalar_cases']==162
print(json.dumps({'pass':True,'new_native_cases':135,'reused_cost8_cases':27,'analyzed_cases':162,'epochs':648,'summary_rows':54,'recorded_data_replay_only':True,'all_archive_members_and_replayed_bytes_verified':True}))
