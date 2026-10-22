"""Offline model-conditional consumer: only explicit context/payload/query JSON."""
import argparse,json
from pathlib import Path
import math

def consume(context,payload,query):
    required={'identity','epoch','horizon','P','d'}
    binding=context['bindings']
    assert set(binding)==required and payload['bindings']==binding,'binding mismatch'
    assert isinstance(binding['P'],int) and binding['P']>0 and isinstance(binding['d'],int) and binding['d']>0
    P=binding['P'];g=math.gcd(P,binding['d'])
    assert query['P']==P and isinstance(query['K'],int) and query['K']>=1 and isinstance(query['phi'],int) and 0<=query['phi']<P
    K,phi=query['K'],query['phi'];B=(K-1)*P
    if payload['kind']=='completion':
        base=payload.get('completion',context.get('existing_completion'))
        assert base and payload['exact_status'] is True,'no exactness contract'
        C=base['C_g'];W=payload['joint_witness_residues_g']
        assert C and C==sorted(set(C)) and W==C and all(isinstance(r,int) and 0<=r<g for r in C),'witness mismatch'
        J,A=base['J'],base['A'];assert isinstance(J,int) and J>=0 and isinstance(A,int) and A>=0
        slack=B-J+1+min((phi+J-1-c)%g for c in C)-A
        slots=len(C)+len(W)+5 if 'completion' in payload else len(W)+2;terms=len(C)
    else:
        assert payload['kind']=='profile'
        pairs=payload['profile_g'];assert pairs and pairs==sorted(pairs) and len({r for r,v in pairs})==len(pairs)
        assert all(isinstance(r,int) and 0<=r<g and isinstance(v,int) and v>=0 for r,v in pairs)
        slack=B+1+min((phi-r-1)%g-v for r,v in pairs);slots=2*len(pairs)+1;terms=len(pairs)
    return {'kind':payload['kind'],'slack':slack,'certifies_against_model_expiry':slack>0,'new_scalar_slots_excluding_common_bindings':slots,
            'query_entries':terms,'independent_reachability_verification':False,'native_conformance_established':False}

def main():
    p=argparse.ArgumentParser();p.add_argument('--context',required=True);p.add_argument('--payload',required=True);p.add_argument('--query',required=True);a=p.parse_args()
    read=lambda name:json.loads(Path(name).read_text(encoding='utf-8'))
    print(json.dumps(consume(read(a.context),read(a.payload),read(a.query))))
if __name__=='__main__':main()
