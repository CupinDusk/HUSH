"""Measure only existing bound transfer calls; no execution simulation occurs."""
from pathlib import Path
from itertools import product
import csv,ctypes,hashlib,json,os,platform,sys,time,zipfile
import replacement_model as m
from recorded_data import load_expected
HERE=Path(__file__).resolve().parent
P=json.loads((HERE/'PROTOCOL.json').read_text(encoding='utf-8'))
base=dict(m.P)
assert hashlib.sha256(Path(m.__file__).read_bytes()).hexdigest()==P['model_sha256']

from platform_memory import memory

phase=sorted(set(product(P['phase_domain'],repeat=3))|{(k,k,k) for k in range(1,256)})
assert len(phase)==591
descriptors=[('fixed',(k,k,k),f) for k,f in product(range(1,256),[(),(1,),(2,),(1,2)])]
descriptors += [('phase',ks,()) for ks in phase]
paths={};path_meta=[]
for q in P['path_shared_blocks']:
    m.P.clear();m.P.update(base,shared_blocks=q,receiver_dense_reads=8*q,
        receiver_compute_gap=P['receiver_compute_gap'],writer_store_count=64*q,period=P['period'])
    fixed=m.instructions(P['path_family'],P['quiet_compute'])
    dynamic=[]
    for op,v in fixed:
        if op=='phase' and v>0:dynamic.append(('compute',P['helper_delta']))
        dynamic.append((op,v))
    paths[q]={'fixed':fixed,'phase':dynamic}
    path_meta.append({'q':q,'shared_reads':sum(op=='read' for op,v in fixed),
        'fixed_events':len(fixed),'phase_events':len(dynamic),
        'Cbase':sum(v for op,v in fixed if op=='compute'),
        'Cphase':sum(v for op,v in dynamic if op=='compute')})

# Make any accidental use of the execution engine fail loudly.
def no_simulation(*args,**kwargs):raise AssertionError('simulation excluded from timing')
m.simulate=no_simulation
before=memory();start=time.perf_counter();rows=[];event_visits=0
for mode,ks,flush in descriptors:
    candidate_id=f"{mode}-{'-'.join(map(str,ks))}-flush{''.join(map(str,flush)) or 'none'}"
    row={'candidate_id':candidate_id,'mode':mode,'K':list(ks),'flush':list(flush),'paths':[]}
    for q in P['path_shared_blocks']:
        m.P.clear();m.P.update(base,shared_blocks=q,receiver_dense_reads=8*q,
            receiver_compute_gap=P['receiver_compute_gap'],writer_store_count=64*q,period=P['period'])
        ops=paths[q][mode];a=m.analyze(ops,ks,flush_at_boundaries=flush)
        C=sum(v for op,v in ops if op=='compute');event_visits+=len(ops)
        row['paths'].append({'q':q,'W':a['bound'],'C':C,'M':a['bound']-C-a['switches'],
            'changed_loads':a['switches'],'analysis_hits':a['hits'],'analysis_unknown':a['unknown'],
            'budget_admitted':a['bound']<=1249})
    row['max_path_bound']=max(r['W'] for r in row['paths'])
    row['all_paths_admitted']=row['max_path_bound']<=1249;rows.append(row)
elapsed=time.perf_counter()-start;after=memory()
# Verification and serialization are deliberately outside the measured window.
expected=load_expected('bound')
assert len(rows)==len(expected)==1611
checks=0
for row,ref in zip(rows,expected):
    for key in ['candidate_id','mode','K','flush','max_path_bound','all_paths_admitted']:
        assert row[key]==ref[key],(row['candidate_id'],key);checks+=1
    for actual,prior in zip(row['paths'],ref['paths']):
        for key in actual:assert actual[key]==prior[key],(row['candidate_id'],actual['q'],key);checks+=1
run_id=sys.argv[1] if len(sys.argv)>1 else '1'
result={'scope':'Offline abstract-bound evaluation only. No simulate calls, native execution, held-out testing or source-event instrumentation in measurement.',
    'run_id':run_id,'wall_seconds':elapsed,'memory_before':before,'memory_after':after,
    'memory_method':'Windows GetProcessMemoryInfo peak working set and peak private commit; absolute Python-process values include runtime and prepared inputs/retained result rows. Verification file loading occurs after capture.',
    'platform':platform.platform(),'python':sys.version,'python_executable':Path(sys.executable).name,
    'processor':platform.processor(),'logical_cpu_count':os.cpu_count(),
    'candidate_count':len(descriptors),'fixed_candidates':1020,'phase_candidates':591,
    'path_count':len(paths),'bound_calls':len(rows)*len(paths),'path_input':path_meta,
    'total_event_visits':event_visits,'supplied_max_tracked_blocks':8,'finite_lru_stack':False,
    'equivalence_checks':checks,'equivalence_pass':True,
    'all_path_admitted_fixed':sum(r['mode']=='fixed' and r['all_paths_admitted'] for r in rows),
    'all_path_admitted_phase':sum(r['mode']=='phase' and r['all_paths_admitted'] for r in rows),
    'model_sha256':P['model_sha256'],'protocol_sha256':hashlib.sha256((HERE/'PROTOCOL.json').read_bytes()).hexdigest(),
    'script_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest()}
(HERE/f'BOUND_PROFILE_{run_id}.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(json.dumps(result,indent=2))
