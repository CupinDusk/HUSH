"""Exact intrinsic-period characterization, record extension and full censuses."""
from pathlib import Path
from collections import Counter
from itertools import product
import argparse,hashlib,json,math,struct,sys
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE/'inputs'))
import v4_decoder

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save(p,x):p.write_text(json.dumps(x,indent=2)+'\n',encoding='utf-8')
def group(q,g):
    a={}
    for r,v in q:a[r%g]=max(v,a.get(r%g,-1))
    return sorted(a.items())
def core(q,g):
    a=group(q,g)
    return [(r,v) for r,v in a if not any(s!=r and w-v>=(r-s)%g for s,w in a)]
def value(q,g,phi):return min((phi-r-1)%g-v for r,v in q)
def fundamental(q,g):
    # Standard word-period prefix function; word entries include BOTH height/gap.
    t=len(q);word=[(q[i][1],(q[i+1][0] if i+1<t else q[0][0]+g)-q[i][0]) for i in range(t)]
    pi=[0]*t
    for i in range(1,t):
        k=pi[i-1]
        while k and word[i]!=word[k]:k=pi[k-1]
        if word[i]==word[k]:k+=1
        pi[i]=k
    h=t-pi[-1]
    if t%h:h=t
    e=sum(x[1] for x in word[:h]);assert e>0 and g%e==0
    return e
def lift(q,e,g):
    assert g%e==0
    return sorted((r+k*e,v) for k in range(g//e) for r,v in q)
def profile_hash(q,g):
    return hashlib.sha256(struct.pack('<QQ',g,len(q))+b''.join(struct.pack('<QQ',r,v) for r,v in q)).digest()

def small(out):
    census=Counter();reductions=Counter();digest=hashlib.sha256()
    for g in range(1,7):
        for vec in product([None,0,1,2,3],repeat=g):
            raw=[(r,v) for r,v in enumerate(vec) if v is not None]
            if not raw:continue
            q=core(raw,g);hv=[value(raw,g,x) for x in range(g)]
            assert hv==[value(q,g,x) for x in range(g)]
            reset=sorted(((x-1)%g,-hv[x]) for x in range(g) if hv[x]<hv[(x-1)%g]+1)
            assert reset==q
            e=fundamental(q,g)
            byfunc=[d for d in range(1,g+1) if g%d==0 and all(hv[(x+d)%g]==hv[x] for x in range(g))]
            bypairs=[d for d in range(1,g+1) if g%d==0 and sorted(((r+d)%g,v) for r,v in q)==q]
            assert byfunc==bypairs and e==min(byfunc)
            qe=core(q,e);assert lift(qe,e,g)==q
            for m in range(1,g+1):
                if g%m:continue
                qm=core(q,m);h=math.gcd(e,m);qh=core(qe,h)
                assert all(value(qm,m,x)==value(qh,h,x) for x in range(m))
                assert lift(qh,h,m)==qm
                census['target_divisor_profiles']+=1
            for P in range(1,2*g+1):
                m=math.gcd(P,g);h=math.gcd(P,e)
                for phi in range(P):
                    a=value(q,m,phi);b=value(qe,h,phi);assert a==b
                    for K in [1,2,4]:
                        assert (K-1)*P+1+a==(K-1)*P+1+b
                        census['physical_policy_slacks']+=1
            census['profiles']+=1;census['reduced_profiles']+=e<g
            census['original_pairs']+=len(q);census['period_reduced_pairs']+=len(qe)
            reductions[f'{g}:{e}']+=1
            digest.update(json.dumps([g,vec,q,e,qe],separators=(',',':')).encode())
        print('small completed modulus',g,flush=True)
    assert census['profiles']==19524
    result=dict(counts=dict(census),modulus_period_counts=dict(reductions),canonical_case_digest=digest.hexdigest())
    save(out/'SMALL_CHECKS.json',result);return result

def encode_new(old,forms):
    chunks=[b'HUPERD05',struct.pack('<I',1),struct.pack('<5Q',*(old[k] for k in ['p','b','r','d','maxP']))]
    chunks.extend(bytes.fromhex(old['bindings'][k]) for k in ['source','receiver','relation','epoch'])
    chunks.append(struct.pack('<I',len(old['lines'])))
    for line,(e,qe) in zip(old['lines'],forms):
        chunks.append(struct.pack('<6Q2I',line['owner'],line['tag'],line['initial_capture'],line['cycle_entry'],line['g'],e,len(line['prefix']),len(qe)))
        chunks.append(profile_hash([tuple(v) for v in line['pairs']],line['g']))
        chunks.extend(struct.pack('<3Q',*row) for row in line['prefix'])
        chunks.extend(struct.pack('<2Q',*row) for row in qe)
    return b''.join(chunks)

def decode_new(data,expected):
    pos=0
    def take(n):
        nonlocal pos
        if pos+n>len(data):raise ValueError('truncated')
        v=data[pos:pos+n];pos+=n;return v
    def un(f):return struct.unpack(f,take(struct.calcsize(f)))
    if take(8)!=b'HUPERD05' or un('<I')[0]!=1:raise ValueError('schema')
    p,b,r,d,maxP=un('<5Q');assert [p,b,r,d,maxP]==[expected[k] for k in ['p','b','r','d','maxP']]
    binds={k:take(32).hex() for k in ['source','receiver','relation','epoch']}
    if binds!=expected['bindings']:raise ValueError('binding')
    count=un('<I')[0];assert count==2
    lines=[]
    for base in expected['lines']:
        owner,tag,capture,entry,g,e,npre,nq=un('<6Q2I');bound=take(32)
        assert [owner,tag,capture,entry,g]==[base[k] for k in ['owner','tag','initial_capture','cycle_entry','g']]
        if not e or g%e or nq<1 or 24*npre+16*nq>len(data)-pos:raise ValueError('support/count')
        prefix=[list(un('<3Q')) for _ in range(npre)]
        qe=[un('<2Q') for _ in range(nq)]
        if prefix!=base['prefix'] or qe!=core(qe,e):raise ValueError('prefix/canonical')
        original=[tuple(v) for v in base['pairs']]
        if bound!=profile_hash(original,g) or profile_hash(lift(qe,e,g),g)!=bound:raise ValueError('period-lift binding')
        if fundamental(qe,e)!=e:raise ValueError('nonfundamental encoding')
        lines.append(dict(e=e,pairs=qe,prefix=prefix))
    if pos!=len(data):raise ValueError('trailing')
    return dict(lines=lines,d=d)

def old_records(out):
    relations=json.loads((HERE/'inputs/RELATIONS.json').read_text(encoding='utf-8'))['records']
    counts=Counter();rows=[];(out/'records').mkdir()
    for rec in relations:
        cid=rec['case_id'];oldfile=HERE/'inputs'/f'{cid}.full.bin'
        old=v4_decoder.decode(oldfile.read_bytes());forms=[];line_stats=[]
        for base,line in zip(old['lines'],rec['lines']):
            q=core([(s,h-s) for s,c,h in line['cycle']],rec['translation'])
            assert q==[tuple(v) for v in base['pairs']]
            e=fundamental(q,rec['translation']);qe=core(q,e)
            assert lift(qe,e,rec['translation'])==q
            forms.append((e,qe));line_stats.append(dict(owner=base['owner'],d=rec['translation'],e=e,full_pairs=len(q),reduced_pairs=len(qe)))
            counts['lines']+=1;counts['reduced_lines']+=e<rec['translation']
            counts['full_pairs']+=len(q);counts['new_pairs']+=len(qe)
        data=encode_new(old,forms);new=decode_new(data,old)
        (out/'records'/f'{cid}.period.bin').write_bytes(data)
        assert len(data)==184+sum(88+24*len(l['prefix'])+16*len(l['pairs']) for l in new['lines'])
        for P in range(1,old['maxP']+1):
            m=math.gcd(P,old['d'])
            for phi in range(P):
                for K in range(1,6):
                    B=(K-1)*P;new_values=[]
                    for line,(e,qe),source in zip(new['lines'],forms,rec['lines']):
                        a=B+1+min((phi-s-1)%m-(h-s) for s,c,h in source['cycle'])
                        b=B+1+value(qe,math.gcd(P,e),phi)
                        assert a==b
                        pre=[B+s+1+(phi-s-1)%P-h for s,c,h in source['prefix']]
                        assert source['prefix']==line['prefix']
                        new_values.append(min([b,*pre]));counts['per_line_slacks']+=1
                    assert min(new_values)==v4_decoder.complete_slack(old,P,K,phi,old['bindings'])
                    counts['complete_policy_slacks']+=1
        full_bytes=oldfile.stat().st_size;port_bytes=(HERE/'inputs'/f'{cid}.prospective.bin').stat().st_size
        counts['old_full_bytes']+=full_bytes;counts['old_portfolio_bytes']+=port_bytes;counts['new_bytes']+=len(data)
        counts['net_smaller_than_full_cases']+=len(data)<full_bytes
        counts['net_equal_full_cases']+=len(data)==full_bytes
        counts['net_larger_than_full_cases']+=len(data)>full_bytes
        rows.append(dict(case_id=cid,lines=line_stats,old_full_bytes=full_bytes,old_portfolio_bytes=port_bytes,new_bytes=len(data),sha256=hashlib.sha256(data).hexdigest()))
    assert counts['lines']==80 and counts['per_line_slacks']==74000 and counts['complete_policy_slacks']==37000
    result=dict(counts=dict(counts),cases=rows);save(out/'OLD_RELATION_RESULTS.json',result);return result

def controls(out):
    tests=[]
    q=[(0,0),(1,1)];assert fundamental(core(q,2),2)==2
    assert value(q,2,1)!=value(core(q,1),1,1)
    tests.append(dict(mutant='period test ignores spans',d=2,pairs=q,phase=1,true=value(q,2,1),mutant=value(core(q,1),1,1)))
    # A true period reduces the remainder, never the physical load.
    P,K,e=6,3,2;q=[(0,1)]
    a=(K-1)*P+1+value(q,math.gcd(P,e),1);b=(K-1)*e+1+value(q,math.gcd(P,e),1);assert a!=b
    tests.append(dict(mutant='replace physical P in load',P=P,K=K,e=e,true=a,mutant=b))
    q1=[(0,12)];q2=[(4,12)];assert core(q1,4)==core(q2,4)
    assert fundamental(q1,12)==fundamental(q2,12)==12
    assert value(q1,6,1)!=value(q2,6,1)
    tests.append(dict(mutant='omit exact-lift gate',d=12,projected_g=4,target_m=6,phase=1,source1=value(q1,6,1),source2=value(q2,6,1)))
    P,e,K,s,h,phi=7,1,3,0,10,0
    a=(K-1)*P+s+1+(phi-s-1)%P-h;b=(K-1)*P+s+1+(phi-s-1)%e-h;assert a!=b
    tests.append(dict(mutant='reduce physical prefix',P=P,e=e,K=K,prefix=[s,1,h],phase=phi,true=a,mutant=b))
    save(out/'MUTATION_CONTROLS.json',tests);return tests

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path,default=HERE/'attempt-001');a=ap.parse_args()
    out=a.out.resolve();out.mkdir(parents=True,exist_ok=False)
    binding=json.loads((HERE/'INPUT_BINDING_BEFORE_PARSE.json').read_text(encoding='utf-8'))
    assert all(sha(HERE/'inputs'/r['name'])==r['sha256'] for r in binding['inputs'])
    save(out/'START_BINDING.json',dict(protocol_sha256=sha(HERE/'PROTOCOL.md'),argument_sha256=sha(HERE/'ARGUMENT.md'),research_sha256=sha(Path(__file__)),input_binding_sha256=sha(HERE/'INPUT_BINDING_BEFORE_PARSE.json')))
    sm=small(out);old=old_records(out);mut=controls(out)
    result=dict(status='PASS_AUTHOR_NEW_INTRINSIC_PERIOD_GATE_PENDING_INDEPENDENT_AUDIT',small=sm['counts'],old=old['counts'],mutation_controls=len(mut),
        scope='Posthoc new conditional exact-period lift. Extra source evidence, all prefixes/bindings retained; not arbitrary projected master support, native refinement, generic minimum encoding or runtime/hardware benefit.')
    save(out/'RESULTS.json',result);print(json.dumps(result,indent=2))
if __name__=='__main__':main()
