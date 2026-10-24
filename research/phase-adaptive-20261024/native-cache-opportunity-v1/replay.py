from pathlib import Path
import json,hashlib,base64,zipfile,io,subprocess,sys
P=Path(__file__).resolve().parent
with zipfile.ZipFile(io.BytesIO(base64.b64decode((P/'RECORDED_DATA.zip.b64').read_bytes()))) as z:
 assert z.namelist()==['DATA.json']
 (P/'DATA.json').write_bytes(z.read('DATA.json'))
binding=json.loads((P/'SOURCE_BINDING.json').read_text())
canonical=lambda p:hashlib.sha256(p.read_text(encoding='utf-8-sig').encode()).hexdigest()
assert canonical(P/'PROTOCOL.json')==binding['protocol_canonical_LF_sha256']
assert canonical(P/'FROZEN_SELECTION.json')==binding['freeze_canonical_LF_sha256']
assert json.loads((P/'FROZEN_SELECTION.json').read_text())['protocol_sha256']==binding['protocol_original_bytes_sha256']
assert json.loads((P/'VALIDATION_MANIFEST.json').read_text())['frozen_selection_sha256']==binding['freeze_original_bytes_sha256']
for n in ['reduce_cache.py','check_invalid_way.py']:
 r=subprocess.run([sys.executable,'-B','-X','utf8',str(P/n)],cwd=P,capture_output=True)
 assert r.returncode==0,(n,r.stderr.decode(errors='replace'))
for n,h in json.loads((P/'EXPECTED_SCIENTIFIC_HASHES.json').read_text()).items():assert hashlib.sha256((P/n).read_bytes()).hexdigest()==h,n
print('196 recorded native cases, frozen selection, all contrasts and9 invalid-way checks replayed with exact output hashes.')
