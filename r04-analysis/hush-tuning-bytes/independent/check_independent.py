"""Independent author-side R04 audit. Standard library only; no producer imports.

Starting points are the frozen protocol, R03 literal event triples and phase rows,
and the published byte schema. Producer analysis/encoder/decoder are only hashed.
This is an author-side arithmetic/encoding check, not a paper review or new run.
"""
from __future__ import annotations

import collections
import copy
import csv
import gzip
import hashlib
import json
import math
from pathlib import Path
import statistics
import struct

HERE = Path(__file__).resolve().parent
BASE = HERE.parent
OLD = BASE.parent.parent / 'r03-analysis' / 'hush-shared-controller'
CHECKS = collections.Counter()


def same(a, b, label):
    if a != b:
        raise AssertionError(f'{label}: actual={a!r}, expected={b!r}')
    CHECKS[label.split(':')[0]] += 1


def need(test, label):
    if not test:
        raise AssertionError(label)
    CHECKS[label.split(':')[0]] += 1


def sha(data):
    return hashlib.sha256(data).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding='utf-8'))


def gzrows(path):
    with gzip.open(path, 'rt', encoding='utf-8') as f:
        return [json.loads(x) for x in f]


def put(name, data):
    (HERE / name).write_text(json.dumps(data, indent=2, ensure_ascii=False) + '\n', encoding='utf-8')


def first_expiry(s, P, phi, K=1):
    # Enumerate ticks after capture until the first decrement, then K-1 periods.
    t = s + 1
    while t % P != phi:
        t += 1
    return t + (K - 1) * P


def literal_phase(rec, P, phi):
    d = rec['translation']
    orbit = P // math.gcd(P, d)
    prefix_edges = []
    recurrent_edges = []
    virtual = []
    for line in rec['lines']:
        ident = line['line']
        prefix_edges.extend((ident, *edge) for edge in line['prefix'])
        J = max(c-s for s, c, h in line['cycle'])
        A = max(h-c for s, c, h in line['cycle'])
        same(J, line['J'], 'tight_J')
        same(A, line['A'], 'tight_A')
        same([c for s, c, h in line['cycle']], line['C0'], 'literal_C0')
        for n in range(orbit):
            for s, c, h in line['cycle']:
                recurrent_edges.append((ident, s+n*d, c+n*d, h+n*d))
                virtual.append((c+n*d-J, c+n*d+A))
    pre = min((first_expiry(s, P, phi)-h for _, s, c, h in prefix_edges), default=None)
    cyc = min(first_expiry(s, P, phi)-h for _, s, c, h in recurrent_edges)
    compcyc = min(first_expiry(s, P, phi)-h for s, h in virtual)
    exact = min(cyc, pre) if pre is not None else cyc
    comp = min(compcyc, pre) if pre is not None else compcyc
    return exact, comp, pre, cyc, prefix_edges + recurrent_edges


def group(edges, modulus):
    out = {}
    for s, c, h in edges:
        out[s % modulus] = max(out.get(s % modulus, 0), h-s)
    return [[r, out[r]] for r in sorted(out)]


def envelope(pairs, modulus):
    # Direct enumeration of every integer phase; no producer pruning criterion.
    return [min(1 + ((phi-r-1) % modulus) - span for r, span in pairs)
            for phi in range(modulus)]


def canonical_by_essentiality(pairs, modulus):
    table = [[1 + ((phi-r-1) % modulus) - span for phi in range(modulus)]
             for r, span in pairs]
    essential = set()
    for phi in range(modulus):
        values = [v[phi] for v in table]
        best = min(values)
        ids = [i for i, value in enumerate(values) if value == best]
        if len(ids) == 1:
            essential.add(ids[0])
    result = [pair for i, pair in enumerate(pairs) if i in essential]
    # For this dataset every surviving profile has an exclusive minimizing phase.
    # Equality of full envelopes verifies that deleting all nonessential pairs is safe.
    same(envelope(result, modulus), envelope(pairs, modulus), 'canonical_direct_envelope')
    return result


class InvalidRecord(ValueError):
    pass


def decode(blob):
    """Own cursor-based little-endian parser, written from SCHEMA.md."""
    pos = 0

    def take(n):
        nonlocal pos
        if n < 0 or pos+n > len(blob):
            raise InvalidRecord('truncated')
        v = blob[pos:pos+n]
        pos += n
        return v

    def ints(fmt):
        return list(struct.unpack('<'+fmt, take(struct.calcsize('<'+fmt))))

    magic = take(8)
    if magic not in (b'HUFULL04', b'HUPORT04'):
        raise InvalidRecord('magic')
    if ints('I') != [1]:
        raise InvalidRecord('version')
    p, b, r, d, maxP = ints('5Q')
    if not (p > 0 and b < p and r in (3, 5) and d > 0 and maxP == 4*p):
        raise InvalidRecord('configuration')
    bindings = dict(zip(('source', 'receiver', 'relation', 'epoch'), (take(32).hex() for _ in range(4))))
    if ints('I') != [2]:
        raise InvalidRecord('line_count')
    lines = []
    offsets = []
    for ident in range(2):
        start = pos
        owner, tag, initial, entry, g = ints('5Q')
        np, nq = ints('2I')
        if owner != ident or tag != (64, 128)[ident] or g == 0 or d % g:
            raise InvalidRecord('line_identity_or_modulus')
        if magic == b'HUFULL04' and g != d:
            raise InvalidRecord('full_master_modulus')
        if np > len(blob)//24 or nq == 0 or nq > len(blob)//16:
            raise InvalidRecord('array_counts')
        prefix = [ints('3Q') for _ in range(np)]
        pairs_start = pos
        pairs = [ints('2Q') for _ in range(nq)]
        if any(not (initial <= s < entry and s < c <= h) for s, c, h in prefix):
            raise InvalidRecord('prefix_cutpoint')
        if prefix and prefix[0][0] != initial:
            raise InvalidRecord('initial_capture')
        if any(prefix[i][2] != prefix[i+1][0] for i in range(len(prefix)-1)):
            raise InvalidRecord('prefix_chain')
        if any(not (0 <= rr < g and span > 0) for rr, span in pairs):
            raise InvalidRecord('pair_values')
        if any(pairs[i][0] >= pairs[i+1][0] for i in range(len(pairs)-1)):
            raise InvalidRecord('pair_order')
        lines.append(dict(owner=owner, tag=tag, initial=initial, entry=entry, g=g, prefix=prefix, pairs=pairs))
        offsets.append(dict(start=start, pairs_start=pairs_start))
    if pos != len(blob):
        raise InvalidRecord('trailing_bytes')
    return dict(magic=magic, version=1, p=p, b=b, r=r, d=d, maxP=maxP, bindings=bindings, lines=lines), offsets


def encode_own(record):
    out = bytearray(record['magic'])
    out.extend(struct.pack('<I5Q', 1, *(record[k] for k in ('p','b','r','d','maxP'))))
    for key in ('source','receiver','relation','epoch'):
        out.extend(bytes.fromhex(record['bindings'][key]))
    out.extend(struct.pack('<I', len(record['lines'])))
    for line in record['lines']:
        out.extend(struct.pack('<5Q2I', *(line[k] for k in ('owner','tag','initial','entry','g')), len(line['prefix']), len(line['pairs'])))
        for edge in line['prefix']:
            out.extend(struct.pack('<3Q', *edge))
        for pair in line['pairs']:
            out.extend(struct.pack('<2Q', *pair))
    return bytes(out)


def query(record, P, phi, K, expected_bindings):
    if expected_bindings != record['bindings']:
        raise InvalidRecord('binding_mismatch')
    if not (isinstance(P,int) and isinstance(K,int) and isinstance(phi,int) and P > 0 and K > 0 and 0 <= phi < P):
        raise InvalidRecord('query_domain')
    if record['magic'] == b'HUPORT04' and P > record['maxP']:
        raise InvalidRecord('outside_portfolio')
    m = math.gcd(P, record['d'])
    if any(line['g'] % m for line in record['lines']):
        raise InvalidRecord('unsupported_gcd')
    values = []
    for line in record['lines']:
        values.extend(first_expiry(s,P,phi,K)-h for s,c,h in line['prefix'])
        values.extend((K-1)*P + 1 + ((phi-r-1)%m) - span for r,span in line['pairs'])
    return min(values)


def rejects(fn, label):
    try:
        fn()
    except InvalidRecord:
        CHECKS[label] += 1
        return
    raise AssertionError(f'mutation accepted: {label}')


def changed(blob, offset, fmt, value):
    fresh = bytearray(blob)
    struct.pack_into('<'+fmt, fresh, offset, value)
    return bytes(fresh)


def optimum(policies, metric):
    feasible = [q for q in policies if q[metric] > 0]
    if not feasible:
        return dict(status='EMPTY_FEASIBLE_SET', minimum_retention_proxy_ticks=None,
                    optimum_tie_count=0, all_optimum_ties=[], selected=None, feasible_policy_count=0)
    val = min(q['retention_proxy_ticks'] for q in feasible)
    ties = sorted((q for q in feasible if q['retention_proxy_ticks'] == val), key=lambda q:(q['K'],q['P'],q['phi']))
    return dict(status='FEASIBLE',minimum_retention_proxy_ticks=val,optimum_tie_count=len(ties),
                all_optimum_ties=ties, selected=ties[0], feasible_policy_count=len(feasible))


def distribution(values):
    hist = collections.Counter(values)
    return dict(count=len(values),min=min(values),max=max(values),median=statistics.median(values),
                mean=statistics.mean(values),histogram=[dict(value=v,controllers=hist[v]) for v in sorted(hist)])


def main():
    manifest = load(BASE/'MANIFEST.json')
    preblob = (BASE/'PRECOMPUTATION_INPUT_BINDING.json').read_bytes()
    pre = json.loads(preblob)
    binding = pre['binding']
    same(sha((BASE/'PROTOCOL.json').read_bytes()), binding['protocol_sha256'], 'protocol_hash')
    same(sha(preblob),manifest['precomputation_input_binding_sha256'],'prebinding_manifest_hash')
    same(binding['protocol_sha256'],manifest['frozen_r04_protocol_sha256'],'protocol_manifest_hash')
    for name, meta in binding['inputs'].items():
        blob = (OLD/name).read_bytes()
        same(dict(sha256=sha(blob),bytes=len(blob)),meta,'frozen_input_hash:'+name)
        same(meta,manifest['readonly_frozen_r03_inputs'][name],'manifest_input_binding:'+name)
    for name, digest in binding['implementation'].items():
        same(sha((BASE/name).read_bytes()),digest,'producer_source_hash:'+name)
    for name, meta in manifest['files'].items():
        blob = (BASE/name).read_bytes()
        same(dict(bytes=len(blob),sha256=sha(blob)),meta,'producer_manifest_payload:'+name)
    manifest_files = set(manifest['files'])
    actual_files = {p.relative_to(BASE).as_posix() for p in BASE.rglob('*') if p.is_file() and HERE not in p.parents}
    same(actual_files,manifest_files|{'MANIFEST.json'},'producer_manifest_coverage')

    relations = load(OLD/'RELATIONS.json')
    old_results = load(OLD/'POLICY_RESULTS.json')
    old_phases = gzrows(OLD/'ALL_PHASE_BASES.jsonl.gz')
    derived = gzrows(BASE/'ALL_QUERY_DERIVATIONS.jsonl.gz')
    tuning = load(BASE/'TUNING_PER_CONTROLLER.json')['records']
    decomp = load(BASE/'PAIR_DECOMPOSITION.json')['records']
    serial = load(BASE/'SERIALIZED_RECORDS.json')
    results = load(BASE/'RESULTS.json')
    same(relations['protocol_sha256'],binding['inputs']['PROTOCOL.json']['sha256'],'r03_protocol_chain')
    same(relations['script_sha256'],binding['inputs']['extract_shared.py']['sha256'],'r03_source_chain')
    same(old_results['relations_sha256'],binding['inputs']['RELATIONS.json']['sha256'],'r03_relation_chain')
    same(old_results['phase_file_sha256'],binding['inputs']['ALL_PHASE_BASES.jsonl.gz']['sha256'],'r03_phase_chain')
    same(serial['epoch_text'],binding['epoch_text'],'epoch_text')
    same(sha(serial['epoch_text'].encode()),binding['epoch_sha256'],'epoch_hash')
    bindings = dict(source=binding['inputs']['extract_shared.py']['sha256'],receiver=binding['inputs']['PROTOCOL.json']['sha256'],
                    relation=binding['inputs']['RELATIONS.json']['sha256'],epoch=binding['epoch_sha256'])
    same(serial['bindings'],bindings,'actual_record_bindings')
    same(results['frozen_protocol_sha256'],binding['protocol_sha256'],'result_protocol_chain')
    same(results['input_binding_sha256'],sha(preblob),'result_prebinding_chain')
    same(derived[0]['frozen_phase_schema'],old_phases[0],'phase_schema_verbatim')
    records = relations['records']
    expected_ids = [f'p{p}_b{b}_r{r}' for p in range(2,7) for b in range(p) for r in (3,5)]
    same([x['case_id'] for x in records],expected_ids,'case_grid')
    for group_rows in (tuning,decomp,serial['records'],old_results['records']):
        same([x['case_id'] for x in group_rows],expected_ids,'all_cases_retained')
    phase_index = {}
    for block in old_phases[1:]:
        key = (block['case_id'],block['P'])
        need(key not in phase_index,'unique_phase_block')
        phase_index[key] = block
    direct_derivations = []
    counts = collections.Counter()
    totals = collections.Counter()
    own_controller = []
    all_bytes = []
    envelope_phase_checks = 0
    own_pair_rows = []
    for ci, rec in enumerate(records):
        cid = rec['case_id']; p=rec['configuration']['p']; d=rec['translation']; maxP=4*p
        g = math.lcm(*(math.gcd(P,d) for P in range(1,maxP+1)))
        need(d%g==0,'prospective_divides_translation')
        pairs_by_variant = {'full':[], 'prospective':[]}
        cp = dict(full_group_pairs=0,full_canonical_pairs=0,projected_group_pairs=0,projected_canonical_pairs=0)
        pairrow = dict(case_id=cid,p=p,d=d,maxP=maxP,prospective_g=g,lines=[])
        for line in rec['lines']:
            fullgroup = group(line['cycle'],d)
            projgroup = group(line['cycle'],g)
            fullcanon = canonical_by_essentiality(fullgroup,d)
            projcanon = canonical_by_essentiality(projgroup,g)
            envelope_phase_checks += d+g
            pairs_by_variant['full'].append(fullcanon)
            pairs_by_variant['prospective'].append(projcanon)
            row = dict(line=line['line'],tag=line['tag'],full_d=d,prospective_g=g,
                       full_group=fullgroup,full_canonical=fullcanon,projected_group=projgroup,projected_canonical=projcanon,
                       full_canonical_deletions=len(fullgroup)-len(fullcanon),
                       support_projection_group_reduction=len(fullgroup)-len(projgroup),
                       prospective_canonical_deletions=len(projgroup)-len(projcanon),prefix_edges=len(line['prefix']))
            pairrow['lines'].append(row)
            for key, val in zip(cp,(fullgroup,fullcanon,projgroup,projcanon)):
                cp[key] += len(val)
            same(fullgroup,line['raw_master'],'r03_raw_group')
            same(fullcanon,line['master'],'r03_full_canonical')
            same(projcanon,line['prospective_pairs'],'r03_prospective_canonical')
            same(g,line['prospective_g'],'r03_prospective_modulus')
        same(pairrow,decomp[ci],'decomposition_all_fields:'+cid)
        own_pair_rows.append(pairrow)
        totals.update(cp)
        decoded = {}
        byteinfo = {}
        prefix_count = sum(len(line['prefix']) for line in rec['lines'])
        totals['prefix_edges'] += prefix_count
        for variant in ('full','prospective'):
            info=serial['records'][ci][variant]; blob=(BASE/info['path']).read_bytes()
            own, offsets = decode(blob)
            expected = dict(magic=b'HUFULL04' if variant=='full' else b'HUPORT04',version=1,p=p,b=rec['configuration']['b'],
                            r=rec['configuration']['r'],d=d,maxP=maxP,bindings=bindings,
                            lines=[dict(owner=line['line'],tag=line['tag'],initial=line['initial_service_cutpoint'],entry=rec['cycle_entry_tick'],
                                        g=d if variant=='full' else g,prefix=line['prefix'],pairs=pairs_by_variant[variant][j])
                                   for j,line in enumerate(rec['lines'])])
            same(own,expected,'independent_decode_all_fields:'+cid+variant)
            same(encode_own(own),blob,'own_encode_roundtrip:'+cid+variant)
            paircount=sum(len(line['pairs']) for line in own['lines'])
            expected_info=dict(path=f'records/{cid}.{variant}.bin',bytes=280+24*prefix_count+16*paircount,sha256=sha(blob),
                               controller_header_bytes=184,line_metadata_bytes=96,exact_prefix_edges=prefix_count,
                               exact_prefix_bytes=24*prefix_count,pairs=paircount,profile_pair_bytes=16*paircount,
                               non_pair_overhead_bytes=280+24*prefix_count)
            same(info,expected_info,'serialized_index_all_fields:'+cid+variant)
            same(len(blob),expected_info['bytes'],'parsed_structural_size')
            totals[variant+'_serialized_bytes']+=len(blob)
            totals[variant+'_pair_bytes']+=16*paircount
            totals[variant+'_overhead_bytes']+=280+24*prefix_count
            byteinfo[variant]=expected_info
            decoded[variant]=own
            # Fresh independent byte copies; these test this parser/guard, not producer code.
            rejects(lambda:decode(blob[:-1]),'mutation_truncated')
            rejects(lambda:decode(blob+b'X'),'mutation_trailing')
            rejects(lambda:decode(b'UNKNOWN!'+blob[8:]),'mutation_magic')
            rejects(lambda:decode(changed(blob,8,'I',2)),'mutation_version')
            rejects(lambda:decode(changed(blob,180,'I',3)),'mutation_line_count')
            rejects(lambda:decode(changed(blob,offsets[0]['start'],'Q',3)),'mutation_owner')
            rejects(lambda:decode(changed(blob,offsets[0]['start']+8,'Q',0)),'mutation_tag')
            rejects(lambda:decode(changed(blob,offsets[0]['start']+32,'Q',0)),'mutation_zero_modulus')
            rejects(lambda:decode(changed(blob,offsets[0]['pairs_start']+8,'Q',0)),'mutation_zero_span')
            rejects(lambda:decode(changed(blob,offsets[0]['pairs_start'],'Q',own['lines'][0]['g'])),'mutation_residue_range')
            for bindkey in bindings:
                wrong=dict(bindings);wrong[bindkey]='00'*32
                rejects(lambda:query(own,1,0,1,wrong),'guard_binding_mismatch_'+bindkey)
            unsupported=copy.deepcopy(own)
            unsupported['lines'][0]['g']=1
            divisor=next(v for v in range(2,d+1) if d%v==0)
            # Keep P inside maxP so divisibility, rather than portfolio limit,
            # is the reason for refusal. Every frozen d has such a small divisor.
            need(divisor<=maxP,'synthetic_small_unsupported_divisor')
            rejects(lambda:query(unsupported,divisor,0,1,bindings),'guard_unsupported_gcd')
            for invalid in ((0,0,1),(1,1,1),(1,-1,1),(1,0,0)):
                rejects(lambda q=invalid:query(own,*q,bindings),'guard_invalid_query')
            # An outside-portfolio compatible-gcd P must still be refused by portfolio magic.
            outside=d*maxP+1
            same(math.gcd(outside,d),1,'outside_compatible_gcd')
            if variant=='prospective':
                rejects(lambda:query(own,outside,0,1,bindings),'guard_portfolio_outside_compatible_gcd')
            else:
                need(isinstance(query(own,outside,0,1,bindings),int),'guard_full_outside_grid_accepted')
        saved=byteinfo['full']['bytes']-byteinfo['prospective']['bytes']
        same(serial['records'][ci]['bytes_saved'],saved,'serialized_saved')
        same(serial['records'][ci]['saved_fraction'],saved/byteinfo['full']['bytes'],'serialized_saved_fraction')
        all_bytes.append((byteinfo['full']['bytes'],byteinfo['prospective']['bytes'],saved,byteinfo['full']['non_pair_overhead_bytes']))
        policies=[]; cc=collections.Counter(dict(queries=0,service_positive=0,service_unknown=0,completion_positive=0,
                                               completion_unknown=0,service_only_admissions=0,posthoc_unsupported_queries=0))
        for P in range(1,maxP+1):
            block=phase_index[(cid,P)]
            same(block['m'],math.gcd(P,d),'phase_gcd')
            same([r[0] for r in block['rows']],list(range(P)),'all_phases_retained')
            for row in block['rows']:
                phi=row[0]
                exact,comp,prebase,recbase,edges=literal_phase(rec,P,phi)
                same(row[1:5],[exact,comp,prebase,recbase],'frozen_literal_phase_bases')
                witness=tuple(row[5:9])
                need(witness in edges,'frozen_witness_in_literal_orbit')
                same(first_expiry(witness[1],P,phi)-witness[3],exact,'frozen_witness_attains_minimum')
                supported=(d//math.gcd(d,3))%math.gcd(P,d)==0
                same(row[9],supported,'posthoc_support')
                same(row[10],sum(1<<(K-1) for K in range(1,6) if exact+(K-1)*P>0),'service_admission_mask')
                same(row[11],sum(1<<(K-1) for K in range(1,6) if comp+(K-1)*P>0),'completion_admission_mask')
                phase_policies=[]
                for K in range(1,6):
                    ss=exact+(K-1)*P;cs=comp+(K-1)*P
                    # Strict >0 is independently checked; zero is unknown.
                    q=dict(K=K,retention_proxy_ticks=K*P-1,service_slack=ss,completion_slack=cs,
                           service_positive=ss>0,completion_positive=cs>0)
                    phase_policies.append(q)
                    tq=dict(K=K,P=P,phi=phi,retention_proxy_ticks=K*P-1,service_slack=ss,completion_slack=cs,
                            frozen_minimizer=dict(zip(('line','s','c','h'),row[5:9])))
                    policies.append(tq)
                    cc['queries']+=1
                    cc['service_positive' if ss>0 else 'service_unknown']+=1
                    cc['completion_positive' if cs>0 else 'completion_unknown']+=1
                    cc['service_only_admissions']+=int(ss>0 and cs<=0)
                    cc['posthoc_unsupported_queries']+=int(not supported)
                    need(not (cs>0 and ss<=0),'completion_subset_of_service')
                    for variant in ('full','prospective'):
                        same(query(decoded[variant],P,phi,K,bindings),ss,'decoded_'+variant+'_query_slack')
                    CHECKS['zero_service_slack_queries']+=int(ss==0)
                    CHECKS['zero_completion_slack_queries']+=int(cs==0)
                direct_derivations.append(dict(case_id=cid,P=P,m=math.gcd(P,d),frozen_phase_row=row,policies=phase_policies))
        same(dict(cc),tuning[ci]['counts'],'all_per_controller_admissions:'+cid)
        service=optimum(policies,'service_slack')
        completion=optimum(policies,'completion_slack')
        same(service,tuning[ci]['service'],'service_optimum_all_fields:'+cid)
        same(completion,tuning[ci]['line_aware_tight_CJA_same_exact_prefix'],'completion_optimum_all_fields:'+cid)
        gain=completion['minimum_retention_proxy_ticks']-service['minimum_retention_proxy_ticks']
        need(gain>=0,'service_optimum_not_worse')
        expected_tune=dict(case_id=cid,configuration=rec['configuration'],counts=dict(cc),service=service,
                           line_aware_tight_CJA_same_exact_prefix=completion,retention_proxy_gain_ticks=gain,
                           optimum_comparison='SERVICE_LOWER_PROXY' if gain>0 else 'NO_PROXY_GAIN',
                           no_additional_admissions=cc['service_only_admissions']==0)
        same(expected_tune,tuning[ci],'tuning_entire_case:'+cid)
        own_controller.append(expected_tune)
        counts.update(cc)
        oc=old_results['records'][ci]['counts']
        for oldkey,key in [('policy_queries','queries'),('full_service_positive','service_positive'),('full_service_unknown','service_unknown'),
                           ('full_completion_positive','completion_positive'),('full_service_only','service_only_admissions'),
                           ('posthoc_unsupported_queries','posthoc_unsupported_queries')]:
            same(oc[oldkey],cc[key],'original_per_case_counts')

    same(direct_derivations,derived[1:],'all_7400_derivation_rows_and_37000_policies')
    same(len(phase_index),sum(4*r['configuration']['p'] for r in records),'all_controller_period_interfaces')
    same(len(direct_derivations),7400,'retained_phase_count')
    same(counts['queries'],37000,'retained_query_count')
    same(envelope_phase_checks,23812,'direct_envelope_phase_positions')
    same(results['controllers'],len(records),'controller_total')
    same(results['lines'],2*len(records),'line_total')
    compared_counts=dict(totals)
    compared_counts.pop('prefix_edges')
    compared_counts.update(counts)
    same(compared_counts,results['counts'],'all_result_counts')
    for oldkey,key in [('policy_queries','queries'),('full_service_positive','service_positive'),('full_service_unknown','service_unknown'),
                       ('full_completion_positive','completion_positive'),('full_service_only','service_only_admissions'),
                       ('posthoc_unsupported_queries','posthoc_unsupported_queries')]:
        same(old_results['counts'][oldkey],counts[key],'original_aggregate_counts')
    gains=[t['retention_proxy_gain_ticks'] for t in own_controller]
    extras=[t['counts']['service_only_admissions'] for t in own_controller]
    selections=dict(cases_with_lower_service_optimum=sum(v>0 for v in gains),cases_with_no_proxy_gain=gains.count(0),
                    cases_with_no_additional_admissions=extras.count(0),
                    service_empty_feasible_sets=sum(t['service']['status']=='EMPTY_FEASIBLE_SET' for t in own_controller),
                    completion_empty_feasible_sets=sum(t['line_aware_tight_CJA_same_exact_prefix']['status']=='EMPTY_FEASIBLE_SET' for t in own_controller),
                    cases_with_no_byte_saving=sum(x[2]==0 for x in all_bytes),
                    full_canonical_deletions=totals['full_group_pairs']-totals['full_canonical_pairs'],
                    support_projection_group_reduction=totals['full_group_pairs']-totals['projected_group_pairs'],
                    prospective_canonical_deletions=totals['projected_group_pairs']-totals['projected_canonical_pairs'],
                    pair_saving_fraction=1-totals['projected_canonical_pairs']/totals['full_canonical_pairs'],
                    serialized_total_saving_fraction=1-totals['prospective_serialized_bytes']/totals['full_serialized_bytes'])
    for k,v in selections.items():
        same(v,results[k],'result_'+k)
    distributions=dict(
        service_optimum_ticks=distribution([t['service']['minimum_retention_proxy_ticks'] for t in own_controller]),
        completion_optimum_ticks=distribution([t['line_aware_tight_CJA_same_exact_prefix']['minimum_retention_proxy_ticks'] for t in own_controller]),
        retention_proxy_gain_ticks=distribution(gains),
        service_optimum_tie_count=distribution([t['service']['optimum_tie_count'] for t in own_controller]),
        completion_optimum_tie_count=distribution([t['line_aware_tight_CJA_same_exact_prefix']['optimum_tie_count'] for t in own_controller]),
        full_total_bytes=distribution([x[0] for x in all_bytes]),prospective_total_bytes=distribution([x[1] for x in all_bytes]),
        serialized_bytes_saved=distribution([x[2] for x in all_bytes]),
        per_controller_byte_saving_fraction=distribution([x[2]/x[0] for x in all_bytes]),service_only_admissions=distribution(extras))
    roundoff_differences=[]
    same(set(distributions),set(results['distributions']),'all_distribution_names')
    for name,dist in distributions.items():
        published=results['distributions'][name]
        same({k:v for k,v in dist.items() if k!='mean'},
             {k:v for k,v in published.items() if k!='mean'},'distribution_exact_fields:'+name)
        need(math.isclose(dist['mean'],published['mean'],rel_tol=1e-14,abs_tol=1e-15),'distribution_mean_roundoff_bounded')
        if dist['mean']!=published['mean']:
            roundoff_differences.append(dict(metric=name,independent_mean=dist['mean'],producer_mean=published['mean'],
                                            absolute_difference=abs(dist['mean']-published['mean'])))
    with (BASE/'PER_CONTROLLER_STATS.csv').open(newline='',encoding='utf-8') as f:
        csv_rows=list(csv.DictReader(f))
    own_csv=[]
    for i,t in enumerate(own_controller):
        c=t['configuration']; pr=own_pair_rows[i]
        row=dict(case_id=t['case_id'],p=c['p'],b=c['b'],r=c['r'],
                 service_optimum_ticks=t['service']['minimum_retention_proxy_ticks'],
                 completion_optimum_ticks=t['line_aware_tight_CJA_same_exact_prefix']['minimum_retention_proxy_ticks'],
                 proxy_gain_ticks=gains[i],service_optimum_ties=t['service']['optimum_tie_count'],
                 completion_optimum_ties=t['line_aware_tight_CJA_same_exact_prefix']['optimum_tie_count'],
                 service_only_admissions=extras[i])
        for name,key in [('full_group_pairs','full_group'),('full_canonical_pairs','full_canonical'),
                         ('projected_group_pairs','projected_group'),('projected_canonical_pairs','projected_canonical')]:
            row[name]=sum(len(line[key]) for line in pr['lines'])
        row.update(full_bytes=all_bytes[i][0],prospective_bytes=all_bytes[i][1],bytes_saved=all_bytes[i][2],non_pair_overhead_bytes=all_bytes[i][3])
        own_csv.append({k:str(v) for k,v in row.items()})
    same(own_csv,csv_rows,'all_csv_rows_all_fields')
    # Exercise empty and objective-tie branches on own synthetic policies.
    empty=optimum([],'service_slack')
    same(empty['status'],'EMPTY_FEASIBLE_SET','synthetic_empty_status')
    same((empty['selected'],empty['optimum_tie_count'],empty['all_optimum_ties']),(None,0,[]),'synthetic_empty_explicit')
    synthetic=[dict(K=3,P=2,phi=1,retention_proxy_ticks=5,service_slack=1),
               dict(K=2,P=3,phi=2,retention_proxy_ticks=5,service_slack=1),
               dict(K=2,P=3,phi=0,retention_proxy_ticks=5,service_slack=0),
               dict(K=2,P=3,phi=1,retention_proxy_ticks=5,service_slack=1)]
    chosen=optimum(synthetic,'service_slack')
    same([(x['K'],x['P'],x['phi']) for x in chosen['all_optimum_ties']],[(2,3,1),(2,3,2),(3,2,1)],'synthetic_all_ties_and_K_P_phi_order')
    noextras=[t['case_id'] for t in own_controller if t['counts']['service_only_admissions']==0]
    extras_nogain=[t['case_id'] for t in own_controller if t['counts']['service_only_admissions']>0 and t['retention_proxy_gain_ticks']==0]
    zerobytes=[t['case_id'] for i,t in enumerate(own_controller) if all_bytes[i][2]==0]
    audit=dict(status='PASS_INDEPENDENT_AUTHOR_SIDE_ARITHMETIC_AND_ENCODING_CHECK',
               role='Separate author-side semantic checker; not a reviewer, independent workload, controller rerun or native implementation.',
               method=['Only Python standard-library imports; producer analysis/encoder/decoder/replay functions never imported or executed.',
                       'Recomputed every phase base from R03 literal prefix/cycle triples by enumerating translated physical-period orbits; completion comparator uses per-line tight virtual intervals.',
                       'Canonical arrays rebuilt by exhaustive integer-phase unique-minimum essentiality and full envelope equality, not producer dominance code.',
                       'All 80 records independently parsed, fields checked against raw relations, re-encoded byte exactly, and evaluated for all frozen complete queries.',
                       'All optimum ties, K/P/phi selection, zero/negative outcomes, per-controller CSV, decompositions, index metadata and result distributions checked.'],
               protocol_sha256=binding['protocol_sha256'],precomputation_binding_sha256=sha(preblob),
               checker_sha256=sha(Path(__file__).read_bytes()),producer_manifest_sha256=sha((BASE/'MANIFEST.json').read_bytes()),
               frozen_input_hashes=binding['inputs'],producer_source_hashes=binding['implementation'],
               manifest_payload_files_checked=len(manifest_files),counts=compared_counts,derived_selections=selections,
               run_environment=dict(python_version=__import__('platform').python_version(),required_flags=['-B','-X','utf8']),
               additional_admissions_without_optimum_gain=len(extras_nogain),prefix_edges=totals['prefix_edges'],
               negative_outcomes=dict(no_additional_admissions_cases=noextras,extra_admission_no_optimum_gain_cases=extras_nogain,zero_byte_gain_cases=zerobytes),
               distributions=distributions,checks=dict(CHECKS),
               harmless_float_mean_roundoff=roundoff_differences,
               chronology_limit='Current file hashes match the frozen protocol, precomputation binding, source bytes and manifest. This independent check cannot prove historical wallclock creation order from self-reported timestamps; R04 remains explicitly posthoc over R03, not a retrospective prospective experiment.',
               parser_test_limit='Mutation and own encode/decode tests exercise this checker and fresh copies; they are not independent testing of the producer decoder implementation.',
               claim_limits=['40 specified constructed model cases and 37000 correlated grid calculations, not population samples or new traffic/workload evidence.',
                             'KP-1 is the stipulated model retention proxy; no measured traffic, energy, power, WCET, speed, native HUSH, hardware or arbitrary-payload coherence result.',
                             'One explicit uncompressed LE record format; totals include headers, bindings, metadata, cutpoints and exact physical prefix, but exclude filenames/index/container/disk allocation/runtime object residency.',
                             'Full grouping/canonicalization 961->961; support projection removes 123 then prospective canonicalization removes 73. The 20.40% pair-array reduction is not all canonical pruning and is not the 8.58% whole-record reduction.',
                             'Full-master arithmetic supports valid positive queries under exact bindings; portfolio magic rejects P>4p even with compatible gcd. Binding hashes are stipulated file/model bindings, not native runtime identifiers or an implemented epoch lifecycle.'])
    put('INDEPENDENT_AUDIT.json',audit)
    put('INDEPENDENT_PER_CONTROLLER.json',own_controller)
    print(json.dumps(dict(status=audit['status'],checked_queries=counts['queries'],decoded_records=CHECKS['independent_decode_all_fields'],
                          decoded_complete_query_slacks=CHECKS['decoded_full_query_slack']+CHECKS['decoded_prospective_query_slack'],
                          checks=sum(CHECKS.values()),manifest_files=len(manifest_files),no_gain_cases=gains.count(0),extras_no_gain=len(extras_nogain)),indent=2))


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        put('INDEPENDENT_AUDIT.json',dict(status='FAIL',error=repr(exc),checks_completed=dict(CHECKS)))
        raise
