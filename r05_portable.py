"""Stdlib manifest verification and lossless materialization into a NEW output."""
from pathlib import Path
import gzip,hashlib,json,shutil
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def load(p):return json.loads(p.read_text(encoding='utf-8'))
def verify(tree=HERE):
 m=load(tree/'MANIFEST.json');actual={p.relative_to(tree).as_posix() for p in tree.rglob('*') if p.is_file()}
 assert actual==set(m['files'])|{'MANIFEST.json'}
 for n,h in m['files'].items():assert sha(tree/n)==h,n
 payload=load(tree/'R05_PORTABLE_PAYLOADS.json')
 for n,r in payload['containers'].items():
  b=(tree/n).read_bytes();assert len(b)==r['bytes'] and hashlib.sha256(b).hexdigest()==r['sha256'];raw=gzip.decompress(b)
  assert len(raw)==r['uncompressed_bytes'] and hashlib.sha256(raw).hexdigest()==r['uncompressed_sha256'],n
 return dict(status='PASS_ALL_PUBLIC_BYTES_AND_LOSSLESS_STREAMS',input_files=len(m['files']),all_files=len(actual),containers=len(payload['containers']),materialized_streams=len(payload['files']))
def materialize(out):
 out=Path(out).resolve();assert not out.exists();assert out!=HERE and HERE not in out.parents,'Output must be outside the immutable input tree'
 report=verify();shutil.copytree(HERE,out)
 for n,r in load(HERE/'R05_PORTABLE_PAYLOADS.json')['files'].items():
  p=out/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(gzip.decompress((HERE/r['container']).read_bytes()));assert sha(p)==r['uncompressed_sha256']
 return out,report
