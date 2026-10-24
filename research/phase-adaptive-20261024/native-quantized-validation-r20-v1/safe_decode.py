"""Decode one allowlisted gzip after validating every base64 part and output."""
from pathlib import Path,PurePosixPath
import json,base64,hashlib,re
R=Path(__file__).resolve().parent
ALLOWLIST={'recorded/NATIVE_RECEIVER_TRACES.json.gz'}
def checked_path(rel):
 p=PurePosixPath(rel)
 if p.is_absolute() or any(x in ('..','.') for x in p.parts):raise ValueError('unsafe relative path')
 q=R.joinpath(*p.parts)
 if not q.resolve().is_relative_to(R):raise ValueError('outside package')
 for parent in [q,*q.parents]:
  if parent==R:break
  if parent.is_symlink():raise ValueError('symlinks not accepted')
 return q
def digest(b):return hashlib.sha256(b).hexdigest()
def decode():
 m=json.loads((R/'RAW_TO_PUBLIC_MAPPING.json').read_text())
 if m.get('format')!=1 or len(m['decoded_files'])!=1:raise ValueError('unexpected decoder mapping')
 outputs=[]
 for item in m['decoded_files']:
  if item['output'] not in ALLOWLIST:raise ValueError('output not allowlisted')
  chunks=[]
  for index,part in enumerate(item['base64_parts'],1):
   expected=f'encoded/NATIVE_RECEIVER_TRACES.json.gz.part{index:04d}.b64'
   if part['path']!=expected:raise ValueError('unexpected base64 part name')
   b=checked_path(part['path']).read_bytes()
   if len(b)!=part['bytes'] or digest(b)!=part['sha256']:raise ValueError('base64 part hash/size mismatch')
   if len(b)>61440 or re.fullmatch(rb'[A-Za-z0-9+/=]*',b) is None:raise ValueError('invalid base64 part')
   chunks.append(b)
  data=base64.b64decode(b''.join(chunks),validate=True)
  if len(data)!=item['bytes'] or digest(data)!=item['sha256']:raise ValueError('decoded gzip hash/size mismatch')
  target=checked_path(item['output'])
  if not target.parent.is_dir():raise ValueError('missing allowlisted directory')
  target.write_bytes(data);outputs.append(item['output'])
 return outputs
if __name__=='__main__':print(json.dumps({'decoded':decode()}))
