"""Reference load-payload encoding and exact enumeration-size arithmetic.

No simulator or timing guarantee. Metadata/profile guards remain separate.
"""
from itertools import product
import json

def pack_loads(loads):
    values=tuple(loads)
    if not values or any(type(x) is not int or not 1 <= x <= 255 for x in values):
        raise ValueError('nonempty sequence of finite 1..254 or infinity=255 required')
    return bytes(values)

def unpack_loads(payload, phases):
    if type(phases) is not int or phases < 1 or len(payload) != phases:
        raise ValueError('descriptor count mismatch')
    values=tuple(payload)
    pack_loads(values)
    return values

def candidate_counts(phases, alphabet=7):
    if type(phases) is not int or phases < 1 or type(alphabet) is not int or not 1 <= alphabet <= 255:
        raise ValueError('positive phase count and legal alphabet size required')
    # A constant vector from the alphabet is already one of all255 fixed vectors.
    phase_family=alphabet**phases+255-alphabet
    # Fixed baseline independently permits a free reset at each boundary.
    fixed_maintenance=255*2**(phases-1)
    return {'phases':phases,'alphabet':alphabet,'load_payload_bytes':phases,
            'phase_family':phase_family,'fixed_maintenance':fixed_maintenance,
            'combined_evaluations_per_path':phase_family+fixed_maintenance}

def self_check():
    accepted=rejected=0
    for loads in [(1,), (255,), (1,128,1), (254,16,1), tuple(range(1,256))]:
        assert unpack_loads(pack_loads(loads),len(loads))==loads
        accepted+=1
    for loads in [(), (0,), (256,), (-1,), (1.0,), (True,)]:
        try: pack_loads(loads)
        except ValueError: rejected+=1
        else: raise AssertionError(loads)
    for payload,phases in [(b'\x01',2),(b'\x00',1),(b'',0)]:
        try: unpack_loads(payload,phases)
        except ValueError: rejected+=1
        else: raise AssertionError((payload,phases))
    for m in [1,2,3,4]:
        a=[1,4,16,32,64,254,255]
        actual=set(product(a,repeat=m)) | {tuple([k]*m) for k in range(1,256)}
        assert len(actual)==candidate_counts(m)['phase_family']
    assert candidate_counts(3)['combined_evaluations_per_path']==1611
    return {'roundtrips':accepted,'invalid_inputs_rejected':rejected,
            'enumerated_formula_checks':4,'sizes':[candidate_counts(m) for m in [3,4,8]],
            'pruning_claimed':False,'native_descriptor_memory_claimed':False}

if __name__=='__main__':
    print(json.dumps(self_check(),indent=2))
