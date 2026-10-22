"""Complete local offline workflow comparison; Python 3.12 standard library only.

Run prepare, validate, then time only after the root confirms a free timing lane.
Parsing, validation, schedules and serialization are outside measured invocations.
"""
from pathlib import Path
from bisect import bisect_right
from collections import Counter
import argparse, datetime, gc, gzip, hashlib, json, math, os, platform
import random, statistics, struct, sys, time, traceback

from producer import cases, extract

HERE=Path(__file__).resolve().parent
ROUTES=('cached_raw','ordinary_grouped','prospective_canonical','dense_phase')
STAGES=('producer_extraction','prefix_and_bind','representation_construction',
        'target_projection_and_cache','queries','consume_hash')
INPUTS=('PROTOCOL.json','extract_shared.py','RELATIONS.json','POLICY_RESULTS.json',
        'ALL_PHASE_BASES.jsonl.gz','INDEPENDENT_VALIDATION.json','ARGUMENT.md','PAPER_READY.md')


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def write_json(path,obj):
    Path(path).write_text(json.dumps(obj,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')


def read_json(path):
    return json.loads(Path(path).read_text(encoding='utf-8'))


def packed_digest(values):
    return hashlib.sha256(b''.join(struct.pack('<q?',v,v>0) for v in values)).hexdigest()


def source_bindings():
    return {n:sha(HERE/n) for n in ('PROTOCOL.json','producer.py','workflow.py')}


def grouped(pairs,m):
    maxima={}
    for r,v in pairs:
        residue=r%m
        if residue not in maxima or v>maxima[residue]: maxima[residue]=v
    return tuple(sorted(maxima.items()))


def canonical(pairs,m):
    """Existing R23 definition; every input residue occurs at most once."""
    return tuple((r,v) for r,v in pairs
                 if not any(q!=r and w-v>=(r-q)%m for q,w in pairs))


def fresh_relations(configurations):
    return [extract(cfg) for cfg in configurations]


def prefix_and_bind(records):
    prefixes=[]; bindings=[]
    for rec in records:
        p=rec['configuration']['p']; d=rec['translation']
        gcds=[0]+[math.gcd(P,d) for P in range(1,4*p+1)]
        targets=tuple(sorted(set(gcds[1:])))
        gstar=math.lcm(*targets)
        # Line IDs/cutpoints remain in records; only their scalar prefix minima combine.
        edges=[(s,h) for line in rec['lines'] for s,c,h in line['prefix']]
        pref=[None]
        for P in range(1,4*p+1):
            pref.append(tuple(min((1+(phi-s-1)%P-(h-s) for s,h in edges),default=None)
                              for phi in range(P)))
        prefixes.append(pref)
        bindings.append({'gcds':gcds,'targets':targets,'gstar':gstar})
    return prefixes,bindings


def representations(route,records,bindings):
    result=[]
    for rec,bind in zip(records,bindings):
        lines=[]
        for line in rec['lines']:
            pairs=tuple((s,h-s) for s,c,h in line['cycle'])
            if route=='prospective_canonical':
                pairs=canonical(grouped(pairs,bind['gstar']),bind['gstar'])
            lines.append(pairs)
        result.append(tuple(lines))
    return result


def target_caches(route,reps,bindings):
    result=[]
    for lines,bind in zip(reps,bindings):
        target={}
        for m in bind['targets']:
            projected=[]
            for pairs in lines:
                if route=='cached_raw':
                    value=tuple((r%m,v) for r,v in pairs)
                elif route=='ordinary_grouped':
                    value=grouped(pairs,m)
                elif route=='prospective_canonical':
                    core=canonical(grouped(pairs,m),m)
                    value=(tuple(r for r,v in core),tuple(v for r,v in core))
                elif route=='dense_phase':
                    ordinary=grouped(pairs,m)
                    value=tuple(1+min((phi-r-1)%m-v for r,v in ordinary) for phi in range(m))
                else:
                    raise ValueError(route)
                projected.append(value)
            target[m]=tuple(projected)
        result.append(target)
    return result


def scan_queries(cache,bindings,prefixes,stream):
    values=[]; total=0; positive=0
    for ci,P,phi,K in stream:
        m=bindings[ci]['gcds'][P]
        best=None
        for line in cache[ci][m]:
            for r,v in line:
                x=1+(phi-r-1)%m-v
                if best is None or x<best: best=x
        pre=prefixes[ci][P][phi]
        if pre is not None and pre<best: best=pre
        slack=best+(K-1)*P
        values.append(slack); total+=slack; positive+=slack>0
    return values,total,positive


def predecessor_queries(cache,bindings,prefixes,stream):
    values=[]; total=0; positive=0
    for ci,P,phi,K in stream:
        m=bindings[ci]['gcds'][P]; x=(phi-1)%m
        best=None
        for residues,spans in cache[ci][m]:
            i=bisect_right(residues,x)-1
            value=1+(x-residues[i])%m-spans[i]
            if best is None or value<best: best=value
        pre=prefixes[ci][P][phi]
        if pre is not None and pre<best: best=pre
        slack=best+(K-1)*P
        values.append(slack); total+=slack; positive+=slack>0
    return values,total,positive


def dense_queries(cache,bindings,prefixes,stream):
    values=[]; total=0; positive=0
    for ci,P,phi,K in stream:
        m=bindings[ci]['gcds'][P]; phase=phi%m
        line0,line1=cache[ci][m]
        best=min(line0[phase],line1[phase])
        pre=prefixes[ci][P][phi]
        if pre is not None and pre<best: best=pre
        slack=best+(K-1)*P
        values.append(slack); total+=slack; positive+=slack>0
    return values,total,positive


def run_pipeline(route,configurations,stream,measure=False,retain=False):
    timings={}
    def stage(name,call):
        if not measure:return call()
        begin=time.perf_counter_ns(); result=call()
        timings[name]=time.perf_counter_ns()-begin
        return result
    begin=time.perf_counter_ns() if measure else None
    records=stage('producer_extraction',lambda:fresh_relations(configurations))
    prefixes,bindings=stage('prefix_and_bind',lambda:prefix_and_bind(records))
    reps=stage('representation_construction',lambda:representations(route,records,bindings))
    cache=stage('target_projection_and_cache',lambda:target_caches(route,reps,bindings))
    evaluator=(predecessor_queries if route=='prospective_canonical' else
               dense_queries if route=='dense_phase' else scan_queries)
    values,total,positive=stage('queries',lambda:evaluator(cache,bindings,prefixes,stream))
    output_hash=stage('consume_hash',lambda:packed_digest(values))
    if measure:
        timings['end_to_end']=time.perf_counter_ns()-begin
        timings['stage_sum']=sum(timings[name] for name in STAGES)
        timings['control_overhead']=timings['end_to_end']-timings['stage_sum']
    result={'route':route,'slack_sum':total,'positive':positive,
            'unknown':len(values)-positive,'output_sha256':output_hash,'timings_ns':timings}
    if retain:
        result.update(values=values,records=records,prefixes=prefixes,
                      bindings=bindings,representations=reps,target_caches=cache)
    return result


def frozen_references(input_dir):
    rel=read_json(input_dir/'RELATIONS.json'); policy=read_json(input_dir/'POLICY_RESULTS.json')
    expected={}; phase_rows=[]
    by_id={rec['case_id']:i for i,rec in enumerate(rel['records'])}
    with gzip.open(input_dir/'ALL_PHASE_BASES.jsonl.gz','rt',encoding='utf-8') as source:
        next(source)
        for text in source:
            entry=json.loads(text); ci=by_id[entry['case_id']];P=entry['P']
            for row in entry['rows']:
                phi,full,comp,pref,recbase,j,s,c,h,supported,me,mc=row
                phase_rows.append((ci,P,row))
                for K in range(1,6):expected[ci,P,phi,K]=full+(K-1)*P
    return rel,policy,expected,phase_rows


def prepare(input_dir):
    for name in ('SCHEDULE.json','QUERY_STREAM.json.gz','EXPECTED.json'):
        assert not (HERE/name).exists(),f'Refuse to replace {name}'
    protocol=read_json(HERE/'PROTOCOL.json')
    assert protocol['status'].startswith('PROSPECTIVE_FROZEN')
    configurations=cases()
    stream=[(ci,P,phi,K) for ci,cfg in enumerate(configurations)
            for P in range(1,4*cfg['p']+1) for phi in range(P) for K in range(1,6)]
    random.Random(protocol['timing']['query_stream_seed']).shuffle(stream)
    assert len(stream)==37000 and len(set(stream))==37000
    stream_bytes=json.dumps(stream,separators=(',',':')).encode()
    (HERE/'QUERY_STREAM.json.gz').write_bytes(gzip.compress(stream_bytes,mtime=0))
    rng=random.Random(protocol['timing']['route_order_seed']); orders=[]
    for i in range(10):
        order=list(ROUTES);rng.shuffle(order);orders.append(order)
    write_json(HERE/'SCHEDULE.json',{'warmup':orders[0],
        'paired_blocks':[{'block':i+1,'order':order} for i,order in enumerate(orders[1:])],
        'query_stream_uncompressed_sha256':hashlib.sha256(stream_bytes).hexdigest(),
        'query_stream_compressed_sha256':sha(HERE/'QUERY_STREAM.json.gz'),
        'query_stream_seed':protocol['timing']['query_stream_seed'],
        'route_order_seed':protocol['timing']['route_order_seed']})
    rel,policy,expected,phase_rows=frozen_references(input_dir)
    outputs=[expected[tuple(query)] for query in stream]
    write_json(HERE/'EXPECTED.json',{'status':'FROZEN_FROM_EXISTING_INDEPENDENTLY_VALIDATED_PHASE_BASES',
        'source_bindings':source_bindings(),'input_sha256':{name:sha(input_dir/name) for name in INPUTS},
        'query_stream_sha256':sha(HERE/'QUERY_STREAM.json.gz'),'schedule_sha256':sha(HERE/'SCHEDULE.json'),
        'queries':len(outputs),'phase_rows':len(phase_rows),'slack_sum':sum(outputs),
        'positive':sum(v>0 for v in outputs),'unknown':sum(v<=0 for v in outputs),
        'completion_positive':policy['counts']['full_completion_positive'],
        'output_sha256':packed_digest(outputs),'hash_encoding':"ordered struct.pack('<q?',slack,slack>0)"})
    print('Prepared and frozen 37000-query stream, ten route orders and expected output.',flush=True)


def assert_bindings(expected,input_dir):
    assert expected['source_bindings']==source_bindings(),'Source/protocol changed after prepare'
    assert expected['input_sha256']=={name:sha(input_dir/name) for name in INPUTS},'Input changed'
    assert expected['query_stream_sha256']==sha(HERE/'QUERY_STREAM.json.gz')
    assert expected['schedule_sha256']==sha(HERE/'SCHEDULE.json')


def independent_status_checks(records,phase_rows):
    """Independent count-only status check; no route/profile/expiry calls."""
    checks=Counter(); case_counts={}
    for ci,P,row in phase_rows:
        phi,full,comp,pref,recbase,j,s,c,h,supported,me,mc=row
        rec=records[ci];d=rec['translation'];m=math.gcd(P,d)
        real=[];virtual=[]
        for line in rec['lines']:
            real.extend(line['prefix']);virtual.extend(line['prefix'])
            J=max(c-s for s,c,h in line['cycle']);A=max(h-c for s,c,h in line['cycle'])
            for s,c,h in line['cycle']:
                for n in range(P//m):
                    real.append((s+n*d,c+n*d,h+n*d))
                    virtual.append((c+n*d-J,c+n*d,c+n*d+A))
        count=max((h-phi)//P-(s-phi)//P for s,c,h in real)
        comp_count=max((h-phi)//P-(s-phi)//P for s,c,h in virtual)
        expected_service=0; expected_completion=0
        local=case_counts.setdefault(rec['case_id'],Counter())
        for K in range(1,6):
            service=K>count;completion=K>comp_count
            assert service==(full+(K-1)*P>0)
            assert completion==(comp+(K-1)*P>0)
            expected_service|=int(service)<<(K-1)
            expected_completion|=int(completion)<<(K-1)
            checks['queries']+=1;checks['service_positive']+=service
            checks['service_unknown']+=not service;checks['completion_positive']+=completion
            checks['service_only']+=service and not completion
            local['queries']+=1;local['service_positive']+=service
            local['completion_positive']+=completion;local['service_only']+=service and not completion
        assert me==expected_service and mc==expected_completion
    return dict(checks),{k:dict(v) for k,v in case_counts.items()}


def capacity_counts(result,route):
    records=result['records'];bindings=result['bindings'];reps=result['representations'];cache=result['target_caches']
    base={'line_records':80,'source_cases':40,
          'prefix_triples':sum(len(line['prefix']) for r in records for line in r['lines']),
          'cycle_triples':sum(len(line['cycle']) for r in records for line in r['lines']),
          'representation_pairs':sum(len(line) for lines in reps for line in lines),
          'distinct_case_target_m':sum(len(b['targets']) for b in bindings),
          'physical_case_P_interfaces':sum(len(b['gcds'])-1 for b in bindings),
          'gcd_cached_values':sum(len(b['gcds'])-1 for b in bindings),
          'prefix_cached_physical_phase_values':sum(len(p) for pref in result['prefixes'] for p in pref[1:]),
          'query_output_slacks':37000}
    if route=='prospective_canonical':
        base['target_cached_pairs']=sum(len(line[0]) for target in cache for lines in target.values() for line in lines)
        base['target_cached_scalar_values']=2*base['target_cached_pairs']
        base['target_cache_encoding']='Two tuple arrays (residue and span) per line and distinct m'
    elif route=='dense_phase':
        base['target_dense_phase_values']=sum(len(line) for target in cache for lines in target.values() for line in lines)
        base['ordinary_grouped_construction_pairs']=sum(len(grouped(line,m)) for lines,b in zip(reps,bindings)
            for m in b['targets'] for line in lines)
        base['target_cache_encoding']='One complete envelope-value tuple per line and distinct m; grouped construction profiles temporary'
    else:
        base['target_cached_pairs']=sum(len(line) for target in cache for lines in target.values() for line in lines)
        base['target_cached_scalar_values']=2*base['target_cached_pairs']
        base['target_cache_encoding']='One residue/span tuple sequence per line and distinct m'
    base['per_line_representation_pairs']=[{'case_id':rec['case_id'],'line':line['line'],
        'initial_service_cutpoint':line['initial_service_cutpoint'],
        'd':rec['translation'],'gstar':bind['gstar'],'pairs':len(rep)}
        for rec,bind,lines in zip(records,bindings,reps) for line,rep in zip(rec['lines'],lines)]
    base['boundary']='Prototype capacities and construction terms; not minimum encoded bytes or live/peak memory measurements'
    return base


def validate(input_dir):
    assert not (HERE/'VALIDATION.json').exists(),'Refuse to replace validation'
    expected=read_json(HERE/'EXPECTED.json');assert_bindings(expected,input_dir)
    stream=json.loads(gzip.decompress((HERE/'QUERY_STREAM.json.gz').read_bytes()))
    rel,policy,lookup,phase_rows=frozen_references(input_dir)
    reference_values=[lookup[tuple(q)] for q in stream]
    route_checks={};capacities={};independent=None;case_counts=None
    for route in ROUTES:
        result=run_pipeline(route,cases(),stream,retain=True)
        assert result['values']==reference_values,f'Exact slack mismatch: {route}'
        for field in ('slack_sum','positive','unknown','output_sha256'):
            assert result[field]==expected[field],(route,field)
        for observed,frozen in zip(result['records'],rel['records']):
            for key in observed:
                if key=='lines':continue
                assert observed[key]==frozen[key],(route,observed['case_id'],key)
            for line,old_line in zip(observed['lines'],frozen['lines']):
                for key in line:assert line[key]==old_line[key],(route,observed['case_id'],key)
        if route=='prospective_canonical':
            for lines,frozen in zip(result['representations'],rel['records']):
                for line,old in zip(lines,frozen['lines']):assert line==tuple(map(tuple,old['prospective_pairs']))
        if independent is None:
            independent,case_counts=independent_status_checks(result['records'],phase_rows)
        capacities[route]=capacity_counts(result,route)
        route_checks[route]={'exact_slacks_matched':37000,'source_cases_matched':40,
            'per_line_relations_matched':80,'output_sha256':result['output_sha256'],
            'slack_sum':result['slack_sum'],'service_positive':result['positive'],'unknown':result['unknown']}
        print('PASS',route,'all 37000 exact slacks and all source relations',flush=True)
    assert independent['queries']==37000 and independent['service_positive']==17387
    assert independent['service_unknown']==19613 and independent['completion_positive']==16948
    assert capacities['prospective_canonical']['representation_pairs']==765
    assert capacities['cached_raw']['representation_pairs']==961
    write_json(HERE/'VALIDATION.json',{'status':'PASS_ALL_FOUR_ROUTES_COMPLETE_EXACT_SLACKS_AND_INDEPENDENT_EVENT_COUNTS',
        'source_bindings':source_bindings(),'expected_sha256':sha(HERE/'EXPECTED.json'),
        'route_checks':route_checks,'independent_event_count_checks':independent,
        'per_case_counts':case_counts,'capacities':capacities,
        'timing_started':False,'timing_lane_confirmation_required':True})


def host_metadata():
    cpu=platform.processor()
    if sys.platform=='win32':
        import winreg
        with winreg.OpenKey(winreg.HKEY_LOCAL_MACHINE,r'HARDWARE\DESCRIPTION\System\CentralProcessor\0') as key:
            cpu=winreg.QueryValueEx(key,'ProcessorNameString')[0].strip()
    clock=time.get_clock_info('perf_counter')
    return {'python':sys.version,'executable':sys.executable,'platform':platform.platform(),
            'cpu':cpu,'logical_cpu_count':os.cpu_count(),'timer':'time.perf_counter_ns',
            'clock_implementation':clock.implementation,'clock_resolution_seconds':clock.resolution,
            'clock_monotonic':clock.monotonic,'clock_adjustable':clock.adjustable,
            'garbage_collector_enabled':gc.isenabled(),'affinity_or_frequency_control':False,
            'command_flags':'-B -X utf8','single_process_serial_routes':True}


def measure(input_dir,lane_confirmation):
    assert lane_confirmation,'Require --lane-confirmation with root confirmation text'
    assert not (HERE/'ALL_TIMINGS.json').exists() and not (HERE/'ALL_TIMINGS.jsonl').exists(),'Refuse rerun/replacement'
    expected=read_json(HERE/'EXPECTED.json');assert_bindings(expected,input_dir)
    validated=read_json(HERE/'VALIDATION.json');assert validated['source_bindings']==source_bindings()
    assert validated['expected_sha256']==sha(HERE/'EXPECTED.json')
    assert validated['status'].startswith('PASS_ALL_FOUR')
    assert sys.version_info[:2]==(3,12),'Protocol requires Python 3.12'
    schedule=read_json(HERE/'SCHEDULE.json')
    stream=json.loads(gzip.decompress((HERE/'QUERY_STREAM.json.gz').read_bytes()))
    configurations=cases();raw=[];warm=[]
    metadata={'status':'RUNNING','started_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
        'source_bindings':source_bindings(),'expected_sha256':sha(HERE/'EXPECTED.json'),
        'validation_sha256':sha(HERE/'VALIDATION.json'),'schedule_sha256':sha(HERE/'SCHEDULE.json'),
        'lane_confirmation':lane_confirmation,'environment':host_metadata()}
    journal=HERE/'ALL_TIMINGS.jsonl'
    with journal.open('x',encoding='utf-8',newline='\n') as out:
        out.write(json.dumps({'metadata':metadata})+'\n');out.flush()
        try:
            for route in schedule['warmup']:
                result=run_pipeline(route,configurations,stream,measure=False)
                for field in ('slack_sum','positive','unknown','output_sha256'):assert result[field]==expected[field]
                warm.append({'route':route,'output_sha256':result['output_sha256']})
                out.write(json.dumps({'warmup':warm[-1]})+'\n');out.flush()
            for block in schedule['paired_blocks']:
                for position,route in enumerate(block['order'],1):
                    result=run_pipeline(route,configurations,stream,measure=True)
                    result.update(block=block['block'],position=position)
                    raw.append(result)
                    out.write(json.dumps({'measurement':result})+'\n');out.flush()
                    for field in ('slack_sum','positive','unknown','output_sha256'):assert result[field]==expected[field],(route,field)
                print('Completed paired block',block['block'],flush=True)
        except BaseException:
            metadata['status']='FAILED_PRESERVED_ATTEMPT'
            metadata['failure_traceback']=traceback.format_exc()
            write_json(HERE/'ALL_TIMINGS.json',{'metadata':metadata,'warmup':warm,'measurements':raw})
            raise
    metadata['status']='COMPLETE_ALL_NINE_PAIRED_BLOCKS'
    metadata['finished_utc']=datetime.datetime.now(datetime.timezone.utc).isoformat()
    write_json(HERE/'ALL_TIMINGS.json',{'metadata':metadata,'warmup':warm,'measurements':raw})
    summarize()


def stats(values):
    return {'median':statistics.median(values),'min':min(values),'max':max(values)}


def summarize():
    assert not (HERE/'RESULTS.json').exists(),'Refuse to replace summary'
    data=read_json(HERE/'ALL_TIMINGS.json');validated=read_json(HERE/'VALIDATION.json')
    assert data['metadata']['status']=='COMPLETE_ALL_NINE_PAIRED_BLOCKS'
    rows=data['measurements'];assert len(rows)==36
    per_route={}
    for route in ROUTES:
        chosen=[r for r in rows if r['route']==route];assert len(chosen)==9
        per_route[route]={stage:stats([r['timings_ns'][stage] for r in chosen])
                          for stage in STAGES+('end_to_end','stage_sum','control_overhead')}
    by={(r['block'],r['route']):r['timings_ns'] for r in rows}
    ratios={}
    for other in ROUTES:
        if other=='prospective_canonical':continue
        ratios[other]={}
        for stage in ('queries','end_to_end'):
            values=[by[b,other][stage]/by[b,'prospective_canonical'][stage] for b in range(1,10)]
            ratios[other][stage]={'other_time_divided_by_canonical_time':values,
                'summary':stats(values),'canonical_faster_blocks':sum(v>1 for v in values),
                'canonical_slower_blocks':sum(v<1 for v in values)}
    winners={stage:Counter(min(ROUTES,key=lambda r:by[b,r][stage]) for b in range(1,10))
             for stage in ('queries','end_to_end')}
    out={'status':'COMPLETE_FIXED_FAMILY_LOCAL_PYTHON_PROTOTYPE',
         'protocol_sha256':sha(HERE/'PROTOCOL.json'),'expected_sha256':sha(HERE/'EXPECTED.json'),
         'validation_sha256':sha(HERE/'VALIDATION.json'),'all_timings_sha256':sha(HERE/'ALL_TIMINGS.json'),
         'environment':data['metadata']['environment'],'units':'nanoseconds',
         'routes':per_route,'paired_ratios':ratios,'winner_blocks':{k:dict(v) for k,v in winners.items()},
         'capacities':validated['capacities'],'correctness':validated['route_checks'],
         'independent_event_counts':validated['independent_event_count_checks'],
         'inference_boundary':'Nine paired repetitions of one fixed 40-case/37000-query Python job; correlated parameters, not independent applications. No CI, native HUSH, hardware/cache benefit or unmeasured amortization claim.',
         'cost_boundary':'Fresh producer, physical finite prefix, bind/gcd, representation, target projection/dense construction, all queries and ordered hash included. Parsing and serialization excluded. Stage sum and end-to-end both reported.'}
    write_json(HERE/'RESULTS.json',out)
    print(json.dumps({r:per_route[r]['end_to_end'] for r in ROUTES},indent=2),flush=True)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mode',choices=('prepare','validate','time','report'))
    parser.add_argument('--inputs',type=Path,default=HERE.parent/'hush-shared-controller')
    parser.add_argument('--lane-confirmation',default='')
    args=parser.parse_args()
    if args.mode=='prepare':prepare(args.inputs)
    elif args.mode=='validate':validate(args.inputs)
    elif args.mode=='time':measure(args.inputs,args.lane_confirmation)
    else:summarize()


if __name__=='__main__':main()
