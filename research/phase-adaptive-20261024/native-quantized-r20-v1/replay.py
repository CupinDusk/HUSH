from pathlib import Path
import json,hashlib,base64,zipfile,io,subprocess,sys
P=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
m=json.loads((P/'RECORDED_DATA.json').read_text())
assert all(n.startswith('DATA-') and n.endswith('.b64') and '/' not in n and '\\' not in n for n in m['parts'])
raw=base64.b64decode(''.join((P/n).read_text().strip() for n in m['parts']),validate=True)
assert hashlib.sha256(raw).hexdigest()==m['zip_sha256']
with zipfile.ZipFile(io.BytesIO(raw)) as z:
 assert z.namelist()==['DATA.json']
 item=z.getinfo('DATA.json');assert item.file_size==m['member_bytes']<100_000_000
 data=z.read(item);assert hashlib.sha256(data).hexdigest()==m['member_sha256']
 (P/'DATA.json').write_bytes(data)
b=json.loads((P/'ORIGINAL_BYTE_BINDING.json').read_text())
assert json.loads((P/'FROZEN_SELECTION.json').read_text())['protocol_sha256']==b['PROTOCOL.json']
assert json.loads((P/'VALIDATION_MANIFEST.json').read_text())['frozen_selection_sha256']==b['FROZEN_SELECTION.json']
assert sha(P/'config_quantized.py')==b['config_public_LF_sha256']
r=subprocess.run([sys.executable,'-B','-X','utf8',str(P/'reduce.py')],cwd=P,capture_output=True)
assert r.returncode==0,r.stderr.decode(errors='replace')
for n,h in json.loads((P/'EXPECTED_SCIENTIFIC_HASHES.json').read_text()).items():assert sha(P/n)==h,n
print('All recorded discrete-timer cases, frozen selection, heldout contrasts,128 tick offsets and epoch sums replayed; exact scientific hashes match.')
