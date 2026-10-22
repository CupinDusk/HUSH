"""Untimed, read-only consistency audit of the frozen workflow/timing artifacts."""
from pathlib import Path
import argparse, gzip, hashlib, json, statistics

HERE=Path(__file__).resolve().parent


def read(name):return json.loads((HERE/name).read_text(encoding='utf-8'))
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs',type=Path,default=HERE.parent/'hush-shared-controller')
    parser.add_argument('--check-only',action='store_true')
    args=parser.parse_args()
    expected=read('EXPECTED.json');schedule=read('SCHEDULE.json')
    validation=read('VALIDATION.json');raw=read('ALL_TIMINGS.json');summary=read('RESULTS.json')
    assert expected['query_stream_sha256']==sha(HERE/'QUERY_STREAM.json.gz')
    assert expected['schedule_sha256']==sha(HERE/'SCHEDULE.json')
    for name,value in expected['source_bindings'].items():assert sha(HERE/name)==value,name
    for name,value in expected['input_sha256'].items():assert sha(args.inputs/name)==value,name
    assert validation['expected_sha256']==sha(HERE/'EXPECTED.json')
    assert raw['metadata']['expected_sha256']==sha(HERE/'EXPECTED.json')
    assert raw['metadata']['validation_sha256']==sha(HERE/'VALIDATION.json')
    assert raw['metadata']['status']=='COMPLETE_ALL_NINE_PAIRED_BLOCKS'
    assert summary['all_timings_sha256']==sha(HERE/'ALL_TIMINGS.json')
    stream=json.loads(gzip.decompress((HERE/'QUERY_STREAM.json.gz').read_bytes()))
    assert len(stream)==len({tuple(q) for q in stream})==37000
    reference=json.loads((args.inputs/'RELATIONS.json').read_text(encoding='utf-8'))
    grid={(ci,P,phi,K) for ci,case in enumerate(reference['records'])
          for P in range(1,4*case['configuration']['p']+1) for phi in range(P) for K in range(1,6)}
    assert grid=={tuple(q) for q in stream}
    measurements=raw['measurements'];assert len(measurements)==36
    assert [x['route'] for x in raw['warmup']]==schedule['warmup']
    journal=[json.loads(row) for row in (HERE/'ALL_TIMINGS.jsonl').read_text(encoding='utf-8').splitlines()]
    assert [row['measurement'] for row in journal if 'measurement' in row]==measurements
    for block in schedule['paired_blocks']:
        observed=[r for r in measurements if r['block']==block['block']]
        assert [r['route'] for r in observed]==block['order']
        assert [r['position'] for r in observed]==[1,2,3,4]
    stages=('producer_extraction','prefix_and_bind','representation_construction',
            'target_projection_and_cache','queries','consume_hash')
    for row in measurements:
        for field in ('slack_sum','positive','unknown','output_sha256'):assert row[field]==expected[field]
        times=row['timings_ns']
        assert all(times[s]>0 for s in stages)
        assert times['stage_sum']==sum(times[s] for s in stages)
        assert times['end_to_end']-times['stage_sum']==times['control_overhead']>=0
    for route,result in summary['routes'].items():
        selected=[r for r in measurements if r['route']==route];assert len(selected)==9
        for stage,reported in result.items():
            values=[r['timings_ns'][stage] for r in selected]
            assert reported=={'median':statistics.median(values),'min':min(values),'max':max(values)}
    assert summary['capacities']==validation['capacities']
    assert summary['correctness']==validation['route_checks']
    out={'status':'PASS_FROZEN_BINDINGS_COMPLETE_GRID_SCHEDULE_ALL36_OUTPUTS_AND_REPORTED_SUMMARIES',
         'script_sha256':sha(Path(__file__)),'all_timings_sha256':sha(HERE/'ALL_TIMINGS.json'),
         'results_sha256':sha(HERE/'RESULTS.json'),'queries':37000,'measurements':36,
         'independent_timing_run':False,'repeated_timing_run':False}
    if not args.check_only:
        target=HERE/'SAVED_AUDIT.json';assert not target.exists()
        target.write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(out,indent=2))


if __name__=='__main__':main()
