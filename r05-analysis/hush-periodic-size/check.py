"""All-phase exact source/encoding checks; no performance experiment."""
from pathlib import Path
from bisect import bisect_right
import hashlib,json,struct
HERE=Path(__file__).resolve().parent
def digest(b):return hashlib.sha256(b).hexdigest()
def header(magic,d,g,n):return struct.pack('<8sQQQ',magic,d,g,n)
def main():
    assert not (HERE/'RESULTS.json').exists()
    result=[];cases=HERE/'inputs';cases.mkdir(exist_ok=False)
    for p in [16,32,64,128,256,512,1024]:
        q=2*p+1;d=p*q
        triples=[(q*k,p*((q*k+p-1)//p)+p,q*(k+1)) for k in range(p)]
        assert all(0<=c-s<q and c<=h and h-s==q for s,c,h in triples)
        pairs=[(s%d,h-s) for s,c,h in triples]
        assert len({r for r,v in pairs})==p and all(v==q for r,v in pairs)
        # Equal spans cannot dominate distinct residues: the directed distance
        # is positive, while the span advantage is zero.
        resets=[(r+1)%d for r,v in pairs];assert resets==sorted(resets)
        dense_header=header(b'HSHDS01\0',d,d,d)
        sparse=header(b'HSHSP01\0',d,d,p)+b''.join(struct.pack('<QQ',r,v) for r,v in pairs)
        periodic=header(b'HSHPD01\0',d,q,1)+struct.pack('<QQ',0,q)
        dense_hash=hashlib.sha256(dense_header);phase_block=bytearray();recovered=[]
        previous=((d-2)%q)-q
        for phi in range(d):
            i=bisect_right(resets,phi)-1
            h_sparse=((phi-resets[i])%d)-pairs[i][1]
            h_period=((phi-1)%q)-q
            assert h_sparse==h_period
            if p<=64:
                assert h_sparse==min(((phi-r-1)%d)-v for r,v in pairs)
            if h_sparse<previous+1:recovered.append(((phi-1)%d,-h_sparse))
            previous=h_sparse
            phase_block.extend(struct.pack('<q',h_sparse))
            if len(phase_block)>=65536:dense_hash.update(phase_block);phase_block.clear()
        dense_hash.update(phase_block)
        assert sorted(recovered)==pairs
        # Decode actual serialized sparse and period-aware inputs.
        for data in [sparse,periodic]:
            magic,orig,g,n=struct.unpack('<8sQQQ',data[:32]);assert orig==d
            decoded=[struct.unpack('<QQ',data[32+16*i:48+16*i]) for i in range(n)]
            assert decoded==(pairs if g==d else [(0,q)])
        (cases/f'p{p}-sparse.bin').write_bytes(sparse)
        (cases/f'p{p}-periodic.bin').write_bytes(periodic)
        source={'p':p,'q':q,'d':d,'triples':triples,'pairs':pairs,'guarantee':'No native source/physical behavior inferred.'}
        (cases/f'p{p}.json').write_text(json.dumps(source,indent=2)+'\n',encoding='utf-8')
        result.append(dict(p=p,q=q,d=d,phases_checked=d,brute_minimum_all_phases=p<=64,
            fixed_modulus_essential_pairs=p,fundamental_period=q,
            dense_bytes=32+8*d,fixed_modulus_sparse_bytes=len(sparse),period_aware_bytes=len(periodic),
            dense_stream_sha256=dense_hash.hexdigest(),sparse_sha256=digest(sparse),periodic_sha256=digest(periodic)))
    report=dict(status='PASS_AUTHOR_EXACT_PHASE_AND_ENCODING_CHECK_PENDING_INDEPENDENT_AUDIT',
        total_phases_checked=sum(r['d'] for r in result),cases=result,
        finding='All fixed-d pairs are essential, but an exact smaller-period one-pair encoding is better. No general sparse superiority follows.',
        files={str(p.relative_to(HERE)).replace('\\','/'):digest(p.read_bytes()) for p in sorted(HERE.rglob('*')) if p.is_file()})
    (HERE/'RESULTS.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in report.items() if k not in ['files']},indent=2))
if __name__=='__main__':main()
