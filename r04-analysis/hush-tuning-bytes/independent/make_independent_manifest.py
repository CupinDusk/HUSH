"""Bind author-side checker evidence only; never edit producer evidence."""
import hashlib
import json
from pathlib import Path

root = Path(__file__).resolve().parent


def digest(path):
    blob = path.read_bytes()
    return dict(bytes=len(blob), sha256=hashlib.sha256(blob).hexdigest())


files = {p.relative_to(root).as_posix(): digest(p) for p in sorted(root.rglob('*'))
         if p.is_file() and p.name != 'MANIFEST.json'}
manifest = dict(
    status='INDEPENDENT_AUTHOR_SIDE_AUDIT_EVIDENCE_MANIFEST',
    scope='Only independently authored checker evidence; producer 97-file manifest remains separate and unchanged.',
    producer_manifest=digest(root.parent / 'MANIFEST.json'),
    frozen_protocol=digest(root.parent / 'PROTOCOL.json'),
    precomputation_input_binding=digest(root.parent / 'PRECOMPUTATION_INPUT_BINDING.json'),
    files=files,
)
(root / 'MANIFEST.json').write_text(json.dumps(manifest, indent=2) + '\n', encoding='utf-8')
print(json.dumps(dict(status=manifest['status'], files=len(files)), indent=2))
