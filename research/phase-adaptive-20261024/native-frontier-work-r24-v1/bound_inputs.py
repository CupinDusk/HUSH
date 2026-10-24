"""Data-only, exact-bound lossless JSON loader; never executes or writes input."""
from pathlib import Path
import hashlib,gzip,base64
F=Path(__file__).resolve().parent
BOUND={'TRAIN_CANDIDATES.json': {'file': 'TRAIN_CANDIDATES.json.gz.b64', 'decoded_bytes': 252081, 'decoded_sha256': '8af30502ac722d6da4cecc6f18121f7f63197de5bc63719a120b490ed5936b78', 'encoded_bytes': 13572, 'encoded_sha256': 'e178d2d747e426d20aa8960297d65a4b6d2fc70a5fdfb6c2475714e6bd972c5f'}, 'MEASUREMENTS.json': {'file': 'MEASUREMENTS.json.gz.b64', 'decoded_bytes': 342147, 'decoded_sha256': '8fca09273cdad47dfd2b4afe11f6b30c5805ad7cdb2fccef347cc5d1d5e5e730', 'encoded_bytes': 21112, 'encoded_sha256': '517804548ebb31a07a64071b4a4ca6bd1cb9e1cee0b8ec5b9acbe3d0454b5df3'}, 'COUNTERS_MIN.json': {'file': 'COUNTERS_MIN.json.gz.b64', 'decoded_bytes': 483703, 'decoded_sha256': 'ad6e7ff7d3a495eab50c7b28902fd2e44bcac55d423863d810acf161122122c6', 'encoded_bytes': 23384, 'encoded_sha256': '20eb0af39579d943b319dcca5b1e9def7dc077a7ea150b4136f16b7b23fee15e'}}
def read_bound(name):
 if name not in BOUND:return (F/name).read_bytes()
 p=BOUND[name];b=(F/p['file']).read_bytes()
 assert len(b)==p['encoded_bytes'] and hashlib.sha256(b).hexdigest()==p['encoded_sha256']
 raw=gzip.decompress(base64.b64decode(b,validate=True))
 assert len(raw)==p['decoded_bytes'] and hashlib.sha256(raw).hexdigest()==p['decoded_sha256']
 return raw
