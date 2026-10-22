"""Bind the seven predeclared public own size cases before new reduction."""
from pathlib import Path
import hashlib,json,shutil
HERE=Path(__file__).resolve().parent
SRC=HERE.parent/'hush-periodic-size'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    target=HERE/'SIZE_INPUT_BINDING_BEFORE_PARSE.json';assert not target.exists()
    items=[(SRC/'check.py','size_source.py'),(SRC/'PROTOCOL.md','size_protocol.md')]
    items.extend((SRC/'inputs'/f'p{p}.json',f'size-p{p}.json') for p in [16,32,64,128,256,512,1024])
    bind=[dict(name=n,sha256=sha(p),bytes=p.stat().st_size) for p,n in items]
    target.write_text(json.dumps(dict(protocol_sha256=sha(HERE/'PROTOCOL.md'),inputs=bind),indent=2)+'\n',encoding='utf-8')
    for p,n in items:
        dest=HERE/'inputs'/n;assert not dest.exists();shutil.copyfile(p,dest);assert sha(dest)==sha(p)
    print('Copied and bound',len(items),'size-model inputs')
if __name__=='__main__':main()
