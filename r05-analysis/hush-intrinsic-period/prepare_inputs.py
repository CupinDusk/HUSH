"""Copy only existing public research inputs, binding bytes before parsing."""
from pathlib import Path
import hashlib,json,shutil
HERE=Path(__file__).resolve().parent
OLD=HERE.parents[1]/'r04-analysis/hush-tuning-bytes'
REL=HERE.parents[1]/'r04-analysis/hush-rtl/reference-inputs/RELATIONS.json'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    dest=HERE/'inputs';dest.mkdir(exist_ok=False)
    pairs=[(OLD/'decoder.py',dest/'v4_decoder.py'),(REL,dest/'RELATIONS.json')]
    for p in range(2,7):
        for b in range(p):
            for r in [3,5]:
                for variant in ['full','prospective']:
                    name=f'p{p}_b{b}_r{r}.{variant}.bin'
                    pairs.append((OLD/'records'/name,dest/name))
    bindings=[dict(name=b.name,sha256=sha(a),bytes=a.stat().st_size) for a,b in pairs]
    (HERE/'INPUT_BINDING_BEFORE_PARSE.json').write_text(json.dumps(dict(protocol_sha256=sha(HERE/'PROTOCOL.md'),inputs=bindings),indent=2)+'\n',encoding='utf-8')
    for a,b in pairs:shutil.copyfile(a,b);assert sha(a)==sha(b)
    print('Bound and copied',len(pairs),'public inputs')
if __name__=='__main__':main()
