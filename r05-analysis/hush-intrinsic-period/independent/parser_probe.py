"""Adversarial tests of the ACTUAL producer parser, not its science oracle.

The runpy-loaded producer namespace is used solely for decode_new. All
expected registry objects, altered records and profile hashes come from the
independent checker. Normal Python, matching the authorized -B -X utf8 run.
"""
from pathlib import Path
from collections import Counter
import json,runpy,struct,hashlib
from check_independent import ROOT,OUT,INPUT,readj,parse,encode,profhash,save

module=runpy.run_path(str(ROOT/'research.py'),run_name='producer_codec_under_test')
decoder=module['decode_new']

def replace(data,offset,fmt,*args):
    b=bytearray(data);struct.pack_into(fmt,b,offset,*args);return bytes(b)

def main():
    examples=[];accepted=Counter();rejected=Counter();paths=[];compromised_registry_accepts=0
    for r in readj(INPUT/'RELATIONS.json')['records']:
        cid=r['case_id'];expected=parse((INPUT/f'{cid}.full.bin').read_bytes())
        paths.append((cid,ROOT/'attempt-002/records'/f'{cid}.period.bin',expected))
    for p in (16,32,64,128,256,512,1024):
        full=ROOT/'attempt-002/size-records'/f'p{p}.full.bin';expected=parse(full.read_bytes())
        paths.extend([(f'size{p}-full',full,expected),(f'size{p}-period',full.with_name(f'p{p}.period.bin'),expected)])

    def deny(name,cid,data,expected):
        try:decoder(data,expected)
        except (AssertionError,ValueError,struct.error,IndexError) as ex:
            rejected[name]+=1
            if not any(x['mutation']==name for x in examples):examples.append(dict(mutation=name,case_id=cid,error_type=type(ex).__name__,error=str(ex),mutant_sha256=hashlib.sha256(data).hexdigest()))
        else:raise AssertionError(('producer parser accepted malformed',cid,name))

    for cid,path,expected in paths:
        data=path.read_bytes();decoder(data,expected);accepted[data[:8].decode()]+=1
        period=data[:8]==b'HUPERD05';first=parse(data,expected)['lines'][0]
        for cut in sorted({0,1,7,8,11,12,51,52,179,180,183,184,215,216,223,224,231,232,239,240,271,272,len(data)-1}):
            if cut<len(data):deny('truncation',cid,data[:cut],expected)
        deny('trailing_byte',cid,data+b'\0',expected)
        deny('wrong_magic',cid,b'BADMAGIC'+data[8:],expected)
        deny('wrong_version',cid,replace(data,8,'<I',2),expected)
        for k in range(5):deny('header_registry_mismatch',cid,replace(data,12+8*k,'<Q',expected[('p','b','r','d','maxP')[k]]+1),expected)
        for k in range(4):
            b=bytearray(data);b[52+32*k]^=1;deny(('source','receiver','relation','epoch')[k]+'_binding_mismatch',cid,bytes(b),expected)
        deny('line_count_mismatch',cid,replace(data,180,'<I',len(expected['lines'])+1),expected)
        for k,name in enumerate(('owner','tag','initial_capture','cycle_entry','g')):
            deny('line_metadata_registry_mismatch',cid,replace(data,184+8*k,'<Q',first[name]+1),expected)
        npoff=232 if period else 224;nqoff=npoff+4;body=272 if period else 232
        deny('prefix_count_huge',cid,replace(data,npoff,'<I',2**32-1),expected)
        deny('pair_count_zero',cid,replace(data,nqoff,'<I',0),expected)
        deny('pair_count_huge',cid,replace(data,nqoff,'<I',2**32-1),expected)
        if first['prefix']:
            deny('changed_physical_prefix',cid,replace(data,body,'<Q',first['prefix'][0][0]+1),expected)
        pairbody=body+24*len(first['prefix'])
        deny('residue_out_of_range',cid,replace(data,pairbody,'<Q',first['e']),expected)
        deny('span_changed',cid,replace(data,pairbody+8,'<Q',first['pairs'][0][1]+1),expected)
        if len(first['pairs'])>1:
            deny('duplicate_residue',cid,replace(data,pairbody+16,'<Q',first['pairs'][0][0]),expected)
        if period:
            deny('zero_e',cid,replace(data,224,'<Q',0),expected)
            deny('e_not_divisor',cid,replace(data,224,'<Q',first['g']+1),expected)
            b=bytearray(data);b[240]^=1;deny('expanded_digest_changed',cid,bytes(b),expected)
            # Make a coherent attacker-chosen profile, digest and lift that
            # match each other. Expected producer registry remains original.
            forged=json.loads(json.dumps(expected))
            for l in forged['lines']:l['pairs']=[(0,0)]
            forms=[(l['g'],[(0,0)]) for l in forged['lines']]
            deny('self_consistent_untrusted_digest',cid,encode(forged,'HUPERD05',forms),expected)
            # A matching forged registry is accepted: this is the expected
            # trust boundary, not cryptographic source authentication.
            decoder(encode(forged,'HUPERD05',forms),forged)
            compromised_registry_accepts+=1
            # If a genuine smaller period exists, a correctly lifted but
            # nonfundamental expanded form must still be rejected by v05.
            if any(l['e']<l['g'] for l in parse(data,expected)['lines']):
                forms=[(l['g'],l['pairs']) for l in expected['lines']]
                deny('nonfundamental_exact_lift',cid,encode(expected,'HUPERD05',forms),expected)
    result=dict(status='PASS_ACTUAL_PRODUCER_DECODER_PROBES',accepted_valid_records=dict(accepted),rejected_mutant_counts=dict(rejected),rejected_total=sum(rejected.values()),examples=examples,compromised_registry_acceptance_controls=compromised_registry_accepts,scope='Executed only actual decode_new under normal Python matching requested runtime. Expected full profiles/bindings are independently read from bound source registry. Header/metadata/count guards partly use assert; no optimized-Python hardening claim. Matching forged expected registries accept fabricated profiles, as expected: a digest is not source authentication.')
    save('PARSER_PROBES.json',result);print(json.dumps({k:v for k,v in result.items() if k!='examples'},indent=2))
if __name__=='__main__':main()
