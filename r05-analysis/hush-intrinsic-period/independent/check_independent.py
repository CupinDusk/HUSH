"""Independent envelope/period/encoding oracle. No producer science imports.

Canonicalization is reconstructed from strict envelope resets, periods are
found by exhaustive translations and word-block comparison, and every binary
is read and reserialized here. Producer codec imports occur only in the
separate parser_probe.py adversarial decoder test.
"""
from pathlib import Path
from collections import Counter
from itertools import product
import hashlib, json, math, struct

OUT=Path(__file__).resolve().parent
ROOT=OUT.parent
INPUT=ROOT/'inputs'

def readj(p): return json.loads(p.read_text(encoding='utf-8'))
def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def save(n,x): (OUT/n).write_text(json.dumps(x,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
def H(q,d,x): return min((x-r-1)%d-v for r,v in q)
def inverse(q,d):
    vals=[H(q,d,x) for x in range(d)]
    return sorted(((x-1)%d,-v) for x,v in enumerate(vals) if v<vals[x-1]+1)
def lift(q,e,d): return sorted((r+k*e,v) for r,v in q for k in range(d//e))
def divisors(d): return sorted({a for k in range(1,math.isqrt(d)+1) if d%k==0 for a in (k,d//k)})
def translations(q,d):
    return [e for e in divisors(d) if sorted(((r+e)%d,v) for r,v in q)==q]
def word_period(q,d):
    word=[(v,((q[(i+1)%len(q)][0]-r)%d) or d) for i,(r,v) in enumerate(q)]
    n=len(word)
    h=next(h for h in divisors(n) if all(word[i]==word[i%h] for i in range(n)))
    return sum(w[1] for w in word[:h])
def profhash(q,d):
    return hashlib.sha256(struct.pack('<QQ',d,len(q))+b''.join(struct.pack('<QQ',r,v) for r,v in q)).digest()

def parse(raw,expected=None):
    pos=0
    def take(n):
        nonlocal pos
        if n<0 or pos+n>len(raw): raise ValueError('truncated')
        b=raw[pos:pos+n];pos+=n;return b
    def un(f): return struct.unpack(f,take(struct.calcsize(f)))
    magic=take(8)
    if magic not in (b'HUFULL04',b'HUPORT04',b'HUFULL05',b'HUPERD05') or un('<I')!=(1,): raise ValueError('schema')
    rec=dict(zip(('p','b','r','d','maxP'),un('<5Q')))
    if not (rec['p']>0 and rec['b']<rec['p'] and rec['r']>0 and rec['d']>0 and rec['maxP']==4*rec['p']): raise ValueError('header')
    rec['magic']=magic.decode();rec['bindings']={k:take(32).hex() for k in ('source','receiver','relation','epoch')}
    nline=un('<I')[0]
    if nline not in (1,2) or magic in (b'HUFULL04',b'HUPORT04') and nline!=2: raise ValueError('line count')
    if expected:
        if any(rec[k]!=expected[k] for k in ('p','b','r','d','maxP','bindings')):raise ValueError('expected registry header/bindings')
        if nline!=len(expected['lines']):raise ValueError('expected registry line count')
    rec['lines']=[]
    for i in range(nline):
        period=magic==b'HUPERD05'
        if period:
            owner,tag,capture,entry,g,e,np,nq=un('<6Q2I');bound=take(32)
        else:
            owner,tag,capture,entry,g,np,nq=un('<5Q2I');e=g;bound=None
        if not g or rec['d']%g or not e or g%e or nq<1 or 24*np+16*nq>len(raw)-pos:raise ValueError('support/count')
        if magic in (b'HUFULL04',b'HUFULL05') and g!=rec['d']:raise ValueError('full support')
        prefix=[list(un('<3Q')) for _ in range(np)]
        q=[un('<2Q') for _ in range(nq)]
        if prefix and any(not(capture<=s<entry and s<c<h) for s,c,h in prefix):raise ValueError('physical prefix')
        if q!=sorted(set(q)) or len(set(r for r,v in q))!=len(q) or any(r>=e for r,v in q):raise ValueError('residue order/range')
        # Generalized size d reaches two million; canonicality can be checked
        # from strict reset exposure without constructing a dense vector.
        if any(any((r-s)%e-w<=-v for s,w in q if s!=r) for r,v in q):raise ValueError('noncanonical')
        line=dict(owner=owner,tag=tag,initial_capture=capture,cycle_entry=entry,g=g,prefix=prefix,pairs=q,e=e)
        if expected:
            base=expected['lines'][i]
            if any(line[k]!=base[k] for k in ('owner','tag','initial_capture','cycle_entry','g','prefix')):raise ValueError('expected registry line metadata/prefix')
            original=base['pairs']
            if period:
                if bound!=profhash(original,g) or lift(q,e,g)!=original:raise ValueError('trusted expanded profile/lift')
                if min(translations(q,e))!=e:raise ValueError('nonfundamental')
            elif q!=original:raise ValueError('full profile mismatch')
        if period:line['expanded_profile_sha256']=bound.hex()
        rec['lines'].append(line)
    if pos!=len(raw):raise ValueError('trailing')
    return rec

def encode(rec,magic=None,forms=None):
    magic=(magic or rec['magic']).encode()
    a=[magic,struct.pack('<I',1),struct.pack('<5Q',*(rec[k] for k in ('p','b','r','d','maxP')))]
    a.extend(bytes.fromhex(rec['bindings'][k]) for k in ('source','receiver','relation','epoch'))
    a.append(struct.pack('<I',len(rec['lines'])))
    for i,l in enumerate(rec['lines']):
        e,q=forms[i] if forms is not None else (l['e'],l['pairs'])
        fields=[l[k] for k in ('owner','tag','initial_capture','cycle_entry','g')]
        if magic==b'HUPERD05':
            a.extend((struct.pack('<6Q2I',*fields,e,len(l['prefix']),len(q)),profhash(l['pairs'],l['g'])))
        else:a.append(struct.pack('<5Q2I',*fields,len(l['prefix']),len(q)))
        a.extend(struct.pack('<3Q',*row) for row in l['prefix'])
        a.extend(struct.pack('<2Q',*row) for row in q)
    return b''.join(a)

def small():
    c=Counter();hist=Counter();dg=hashlib.sha256();edge=Counter()
    for d in range(1,7):
        for vec in product((None,0,1,2,3),repeat=d):
            raw=[(i,v) for i,v in enumerate(vec) if v is not None]
            if not raw:continue
            q=inverse(raw,d);vals=[H(raw,d,x) for x in range(d)]
            assert vals==[H(q,d,x) for x in range(d)]
            fp=[e for e in divisors(d) if all(vals[x]==vals[(x+e)%d] for x in range(d))]
            tp=translations(q,d);wp=word_period(q,d)
            assert fp==tp and wp==fp[0]
            e=fp[0];qe=inverse(q,e);assert lift(qe,e,d)==q
            for m in divisors(d):
                qm=inverse(q,m);h=math.gcd(m,e);qh=inverse(qe,h)
                assert lift(qh,h,m)==qm
                assert all(H(qm,m,x)==H(qh,h,x) for x in range(m))
                c['target_divisor_profiles']+=1
            for P in range(1,2*d+1):
                m=math.gcd(P,d);h=math.gcd(P,e)
                for phi in range(P):
                    original=H(raw,m,phi);reduced=H(qe,h,phi)
                    for K in (1,2,4):
                        assert (K-1)*P+1+original==(K-1)*P+1+reduced
                        c['physical_policy_slacks']+=1
            c['profiles']+=1;c['reduced_profiles']+=e<d
            c['original_pairs']+=len(q);c['period_reduced_pairs']+=len(qe)
            hist[f'{d}:{e}']+=1;edge['raw_has_zero_span']+=any(v==0 for r,v in raw)
            edge['canonical_has_zero_span']+=any(v==0 for r,v in q)
            edge['no_reduction']+=e==d;edge['modulus_one']+=d==1
            dg.update(json.dumps([d,vec,q,e,qe],separators=(',',':')).encode())
        print('independent small modulus',d,flush=True)
    result=dict(counts=dict(c),modulus_period_counts=dict(hist),canonical_case_digest=dg.hexdigest(),edge_counts=dict(edge))
    producer=readj(ROOT/'attempt-002/SMALL_CHECKS.json')
    assert all(result[k]==producer[k] for k in producer)
    assert producer==readj(ROOT/'attempt-001/SMALL_CHECKS.json')
    save('SMALL_CHECKS.json',result);return result

def binding_audit():
    paths=[]
    for name,n in [('INPUT_BINDING_BEFORE_PARSE.json',82),('SIZE_INPUT_BINDING_BEFORE_PARSE.json',9)]:
        bind=readj(ROOT/name);assert len(bind['inputs'])==n
        for x in bind['inputs']:
            p=INPUT/x['name'];assert sha(p)==x['sha256'] and p.stat().st_size==x['bytes'];paths.append(p)
    first=readj(ROOT/'attempt-001/START_BINDING.json');second=readj(ROOT/'attempt-002/START_BINDING.json')
    bad=(ROOT/'failure-001-syntax/research.py').read_bytes()
    assert bad.count(b',mutant=value(core(q,1),1,1)')==1 and bad.count(b',true=a,mutant=b')==2
    fixed=bad.replace(b',mutant=value(core(q,1),1,1)',b',mutant_value=value(core(q,1),1,1)').replace(b',true=a,mutant=b',b',true=a,mutant_value=b')
    assert fixed==(ROOT/'research-version-001.py').read_bytes()
    assert hashlib.sha256(fixed).hexdigest()==first['research_sha256']
    for k,n in [('protocol_sha256','PROTOCOL.md'),('argument_sha256','ARGUMENT.md'),('research_sha256','research.py'),('input_binding_sha256','INPUT_BINDING_BEFORE_PARSE.json')]:assert second[k]==sha(ROOT/n)
    try:compile(bad,'preserved-failure','exec')
    except SyntaxError as ex:syntax=dict(type='SyntaxError',line=ex.lineno,message=ex.msg)
    else:raise AssertionError('preserved syntax failure no longer fails')
    compile(fixed,'recovered-first','exec')
    receipt=readj(ROOT/'FIRST_SOURCE_RECOVERY.json')
    assert receipt['recovered_sha256']==hashlib.sha256(fixed).hexdigest() and receipt['source_sha256']==hashlib.sha256(bad).hexdigest()
    result=dict(status='PASS',old_input_count=82,size_input_count=9,first_source_sha256=hashlib.sha256(fixed).hexdigest(),current_source_sha256=sha(ROOT/'research.py'),current_protocol_sha256=sha(ROOT/'PROTOCOL.md'),first_protocol_sha256=first['protocol_sha256'],preparse_protocol_sha256=readj(ROOT/'INPUT_BINDING_BEFORE_PARSE.json')['protocol_sha256'],size_preparse_protocol_sha256=readj(ROOT/'SIZE_INPUT_BINDING_BEFORE_PARSE.json')['protocol_sha256'],preserved_syntax_failure=syntax,first_source_recovered_by_only_three_renames=True,protocol_hash_changes_preserved_not_retroactively_equated=True)
    save('BINDINGS.json',result);return result,paths

def old_cases():
    registry=readj(INPUT/'RELATIONS.json');relations=registry['records'];c=Counter();rows=[];paths=[]
    producer=readj(ROOT/'attempt-002/OLD_RELATION_RESULTS.json')
    for rec,prow in zip(relations,producer['cases']):
        cid=rec['case_id'];fullraw=(INPUT/f'{cid}.full.bin').read_bytes();portraw=(INPUT/f'{cid}.prospective.bin').read_bytes()
        old=parse(fullraw);port=parse(portraw);assert encode(old)==fullraw and encode(port)==portraw
        assert old['bindings']==port['bindings'] and old['d']==rec['translation']
        assert all(old[k]==rec['configuration'][k] for k in ('p','b','r')) and old['maxP']==4*old['p']
        assert old['bindings']['source']==registry['script_sha256'] and old['bindings']['receiver']==registry['protocol_sha256'] and old['bindings']['relation']==sha(INPUT/'RELATIONS.json')
        forms=[];stats=[]
        for line,src in zip(old['lines'],rec['lines']):
            q=inverse([(s,h-s) for s,c,h in src['cycle']],old['d'])
            assert q==line['pairs'] and src['prefix']==line['prefix']
            assert line['owner']==src['line'] and line['tag']==src['tag'] and line['initial_capture']==src['initial_service_cutpoint']
            assert line['cycle_entry']==rec['cycle_entry_tick']
            e=min(translations(q,old['d']));assert word_period(q,old['d'])==e
            qe=inverse(q,e);assert lift(qe,e,old['d'])==q
            forms.append((e,qe));stats.append(dict(owner=line['owner'],d=old['d'],e=e,full_pairs=len(q),reduced_pairs=len(qe)))
            c['lines']+=1;c['reduced_lines']+=e<old['d'];c['full_pairs']+=len(q);c['new_pairs']+=len(qe)
        raw=(ROOT/'attempt-002/records'/f'{cid}.period.bin').read_bytes()
        assert raw==encode(old,'HUPERD05',forms)
        new=parse(raw,old)
        assert len(raw)==184+sum(88+24*len(l['prefix'])+16*len(l['pairs']) for l in new['lines'])
        for P in range(1,old['maxP']+1):
            m=math.gcd(P,old['d'])
            for phi in range(P):
                for K in range(1,6):
                    values=[];other=[];oldvalues=[]
                    for source,base,pl,nl in zip(rec['lines'],old['lines'],port['lines'],new['lines']):
                        B=(K-1)*P
                        original=B+1+min((phi-s-1)%m-(h-s) for s,c,h in source['cycle'])
                        reduced=B+1+H(nl['pairs'],math.gcd(P,nl['e']),phi)
                        fullval=B+1+H(base['pairs'],m,phi)
                        assert pl['g']%m==0
                        portfolio=B+1+H(pl['pairs'],m,phi)
                        assert original==reduced==fullval==portfolio
                        prefix=[B+s+1+(phi-s-1)%P-h for s,c,h in source['prefix']]
                        assert base['prefix']==pl['prefix']==nl['prefix']
                        values.append(min([reduced,*prefix]));oldvalues.append(min([fullval,*prefix]));other.append(min([portfolio,*prefix]))
                        c['per_line_slacks']+=1
                    assert min(values)==min(other)==min(oldvalues);c['complete_policy_slacks']+=1
        c['old_full_bytes']+=len(fullraw);c['old_portfolio_bytes']+=len(portraw);c['new_bytes']+=len(raw)
        c['net_smaller_than_full_cases']+=len(raw)<len(fullraw);c['net_equal_full_cases']+=len(raw)==len(fullraw);c['net_larger_than_full_cases']+=len(raw)>len(fullraw)
        row=dict(case_id=cid,lines=stats,old_full_bytes=len(fullraw),old_portfolio_bytes=len(portraw),new_bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest())
        assert row==prow;rows.append(row)
        paths.extend([INPUT/f'{cid}.full.bin',INPUT/f'{cid}.prospective.bin',ROOT/'attempt-002/records'/f'{cid}.period.bin',ROOT/'attempt-001/records'/f'{cid}.period.bin'])
        assert paths[-1].read_bytes()==raw
    result=dict(counts=dict(c),cases=rows,unchanged_lines=c['lines']-c['reduced_lines'],original_binary_roundtrips=80,new_binary_roundtrips=40,adaptive_full_fallback_bytes=c['old_full_bytes'])
    assert result['counts']==producer['counts'] and len(rows)==40
    assert producer==readj(ROOT/'attempt-001/OLD_RELATION_RESULTS.json')
    save('OLD_RELATION_RESULTS.json',result);return result,paths

def sizes():
    rows=[];c=Counter();paths=[];producer=readj(ROOT/'attempt-002/SIZE_RESULTS.json')
    for p,prow in zip((16,32,64,128,256,512,1024),producer['cases']):
        sp=INPUT/f'size-p{p}.json';src=readj(sp);q=2*p+1;d=p*q
        triples=[(q*k,p*((q*k+p-1)//p)+p,q*(k+1)) for k in range(p)]
        assert src['p']==p and src['q']==q and src['d']==d and src['triples']==[list(t) for t in triples]
        pairs=[(s,h-s) for s,c0,h in triples];assert src['pairs']==[list(t) for t in pairs]
        assert all(s<c0<=h and h-s==q for s,c0,h in triples)
        # Equal spans expose every term strictly at its own reset; no dense
        # array and no producer predecessor/bisect function is used here.
        assert all(H(pairs,d,r+1)==-v and all((r-s)%d-w>-v for s,w in pairs if s!=r) for r,v in pairs)
        e=min(translations(pairs,d));assert e==q and word_period(pairs,d)==q
        base=dict(p=p,b=0,r=1,d=d,maxP=4*p,bindings=dict(source=sha(INPUT/'size_source.py'),receiver=sha(INPUT/'size_protocol.md'),relation=sha(sp),epoch=hashlib.sha256(b'R05 mathematical single-source size-model epoch').hexdigest()),lines=[dict(owner=0,tag=64,initial_capture=0,cycle_entry=0,g=d,e=d,prefix=[],pairs=pairs)])
        fullpath=ROOT/'attempt-002/size-records'/f'p{p}.full.bin';periodpath=ROOT/'attempt-002/size-records'/f'p{p}.period.bin'
        fullraw=fullpath.read_bytes();newraw=periodpath.read_bytes()
        assert fullraw==encode(base,'HUFULL05') and newraw==encode(base,'HUPERD05',[(q,[(0,q)])])
        full=parse(fullraw,base);new=parse(newraw,base)
        # Sweep unit-slope segments and exact reset events. For equal spans,
        # the most recent cyclic reset is uniquely minimal. Initialize from
        # the final reset in the preceding cycle; check every phase and inverse.
        reset_to_pair={(r+1)%d:(r,v) for r,v in pairs}
        last=max(reset_to_pair)-d;running=0-last-q;recovered=[];previous=None
        for phi in range(d):
            if phi in reset_to_pair:running=-q
            reduced=H(new['lines'][0]['pairs'],q,phi)
            assert running==reduced==((phi-1)%q)-q
            if previous is not None and running<previous+1:recovered.append(((phi-1)%d,-running))
            previous=running;running+=1;c['original_phases_checked']+=1
        # No wrap reset at phi=0 in these cases; every reset was encountered.
        assert sorted(recovered)==pairs
        for P in sorted({1,2,p,q,d,d+1,3*p}):
            for phi in sorted({0,P//2,P-1}):
                for K in (1,2,4):
                    a=(K-1)*P+1+H(full['lines'][0]['pairs'],math.gcd(P,d),phi)
                    b=(K-1)*P+1+H(new['lines'][0]['pairs'],math.gcd(P,q),phi)
                    assert a==b;c['physical_sample_slacks']+=1
        row=dict(p=p,d=d,e=e,full_pairs=p,reduced_pairs=1,baseline_bytes=len(fullraw),period_bytes=len(newraw),full_sha256=hashlib.sha256(fullraw).hexdigest(),period_sha256=hashlib.sha256(newraw).hexdigest())
        assert row==prow and len(fullraw)==232+16*p and len(newraw)==288
        rows.append(row);paths.extend([fullpath,periodpath])
        print('independent size phases',p,d,flush=True)
    result=dict(counts=dict(c),cases=rows,all_four_bindings_retained=True,original_simple_period_format_bytes=48,original_simple_header_bytes=32)
    assert result['counts']==producer['counts'];save('SIZE_RESULTS.json',result);return result,paths

def controls():
    tests=[]
    # This actual mutant decides period using support alone on a CANONICAL
    # profile. Producer's two-residue example was not canonical before core().
    def span_blind_period(q,d):
        support=sorted(r for r,v in q)
        return next(e for e in divisors(d) if sorted((r+e)%d for r in support)==support)
    q=[(0,0),(2,1)];d=4;assert inverse(q,d)==q
    e=span_blind_period(q,d);badq=inverse(q,e);phi=1
    assert e==2 and H(q,d,phi)!=H(badq,e,phi)
    tests.append(dict(mutant='span_blind_period_actual_branch',d=d,canonical_pairs=q,true_e=min(translations(q,d)),mutant_e=e,phi=phi,true=H(q,d,phi),mutant_value=H(badq,e,phi)))
    def wrong_load(P,K,e,q,phi):return (K-1)*e+1+H(q,math.gcd(P,e),phi)
    P,K,e=6,3,2;q=[(0,1)];phi=1
    a=(K-1)*P+1+H(q,math.gcd(P,e),phi);b=wrong_load(P,K,e,q,phi);assert a!=b
    tests.append(dict(mutant='physical_load_uses_e_actual_branch',P=P,K=K,e=e,pairs=q,phi=phi,true=a,mutant_value=b))
    def missing_gate(q,g,m,phi):return H(inverse(q,g),math.gcd(g,m),phi)
    q1,q2=[(0,12)],[(4,12)];d,g,m,phi=12,4,6,1
    assert inverse(q1,g)==inverse(q2,g) and min(translations(q1,d))==min(translations(q2,d))==d
    assert H(q1,m,phi)!=H(q2,m,phi)
    bad=missing_gate(q2,g,m,phi);assert bad!=H(q2,m,phi)
    tests.append(dict(mutant='no_lift_gate_actual_query_branch',d=d,projected_g=g,target_m=m,source1=q1,source2=q2,projected_pairs=inverse(q1,g),phi=phi,true_source1=H(q1,m,phi),true_source2=H(q2,m,phi),mutant_value=bad))
    def wrong_prefix(P,K,e,s,h,phi):return (K-1)*P+s+1+(phi-s-1)%e-h
    P,K,e,s,h,phi=7,3,1,0,10,0
    a=(K-1)*P+s+1+(phi-s-1)%P-h;b=wrong_prefix(P,K,e,s,h,phi);assert a!=b
    recurrent=(K-1)*P+1+H([(0,1)],e,phi)
    assert min(recurrent,a)!=min(recurrent,b)
    tests.append(dict(mutant='physical_prefix_uses_e_actual_branch',P=P,K=K,e=e,prefix=[s,1,h],phi=phi,true=a,mutant_value=b,recurrent_pairs=[(0,1)],recurrent_slack=recurrent,true_complete=min(recurrent,a),mutant_complete=min(recurrent,b),initial_capture=0,cycle_entry=10))
    save('MUTATION_CONTROLS.json',dict(actual_mutant_branches=4,counterexamples=tests,coverage='Four named errors only; not generic mutation coverage. Producer controls provide wrong-formula witnesses but do not execute a complete mutant audit suite.'))
    return tests

def main():
    bindings,paths=binding_audit();sm=small();old,op=old_cases();sz,sp=sizes();mut=controls();paths.extend(op+sp)
    receipt=dict(status='PASS_INDEPENDENT_EXACT_MODEL_AUDIT',small=sm['counts'],old=old['counts'],size=sz['counts'],actual_mutant_branches=len(mut),source_receipt=bindings)
    save('CHECK_RESULTS.json',receipt)
    unique={str(p.relative_to(ROOT)).replace('\\','/'):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in paths}
    save('READ_INPUT_MANIFEST.json',unique)
    print(json.dumps(receipt,indent=2))
if __name__=='__main__':main()
