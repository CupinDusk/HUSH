from pathlib import Path
import zipfile,tempfile,subprocess,sys,hashlib
HERE=Path(__file__).resolve().parent
p=HERE/'source-kernels-inputs.zip'
assert hashlib.sha256(p.read_bytes()).hexdigest()=='753fc78a4d607a57a71b9a64ebd75f7f4abec29ddfcf7e21d630340d8c0ff95f'
with tempfile.TemporaryDirectory(prefix='hush-source-coverage-') as d:
    dest=Path(d)
    with zipfile.ZipFile(p) as z:
        assert len(z.namelist())==44 and sum(x.file_size for x in z.infolist())<20_000_000
        for n in z.namelist():assert not Path(n).is_absolute() and '..' not in Path(n).parts
        z.extractall(dest)
    subprocess.run([sys.executable,'-B','-X','utf8',str(dest/'replay.py')],cwd=dest,check=True)
print('PASS: source-input ZIP hash, safe unpack, source/address and bound replay')
