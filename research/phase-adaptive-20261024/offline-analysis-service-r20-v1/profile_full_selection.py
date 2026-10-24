"""Time the unchanged 4833 analyze+simulate calls and training selection."""
from pathlib import Path
from itertools import product
import ctypes,hashlib,json,platform,sys,time,zipfile
import replacement_model as m
from recorded_data import load_expected
HERE=Path(__file__).resolve().parent
p=json.loads((HERE/'PROTOCOL.json').read_text(encoding='utf-8'))
assert hashlib.sha256(Path(m.__file__).read_bytes()).hexdigest()==p['model_sha256']
base=dict(m.P);qs=p['path_shared_blocks']
from platform_memory import memory
def path(q,mode):
    m.P.clear();m.P.update(base,shared_blocks=q,receiver_dense_reads=8*q,receiver_compute_gap=p['receiver_compute_gap'],writer_store_count=64*q,period=p['period'])
    original=m.instructions(p['path_family'],p['quiet_compute'])
    if mode=='fixed':return original
    ops=[]
    for op,v in original:
        if op=='phase' and v>0:ops.append(('compute',p['helper_delta']))
        ops.append((op,v))
    return ops
def evaluate(mode,ks,flush,q,gap,phi):
    ops=path(q,mode);a=m.analyze(ops,ks,flush_at_boundaries=flush)
    r=m.simulate(ops,ks,gap,phi,a,writer_count=64*q,flush_at_boundaries=flush,flush_at_finish=True)
    assert r['unsafe_hits']==0 and r['reader_cycles']<=a['bound']
    C=sum(v for op,v in ops if op=='compute')
    return {'q':q,'W':a['bound'],'C':C,'M':a['bound']-C-a['switches'],'changed_loads':a['switches'],
        'analysis_hits':a['hits'],'analysis_unknown':a['unknown'],'budget_admitted':a['bound']<=B,'execution':r}
def key(row):return (row['worst_training_joint'],row['worst_training_receiver'],row['worst_training_updates'],tuple(row['K']),tuple(row['flush']))

before=memory();start=time.perf_counter()
budget_rows=[]
for q in qs:
    ops=path(q,'fixed');C=sum(v for op,v in ops if op=='compute');nr=sum(op=='read' for op,v in ops)
    B0=C+q*(m.P['update_slot_cycles']+1+m.P['miss_slot_cycles'])+(nr-q)
    budget_rows.append({'q':q,'Cbase':C,'reads':nr,'B0':B0})
B=max(r['B0'] for r in budget_rows)+32;assert B==1249
phase_tuples=sorted(set(product(p['phase_domain'],repeat=3))|{(k,k,k) for k in range(1,256)})
descriptors=[('fixed',(k,k,k),f) for k,f in product(range(1,256),[(),(1,),(2,),(1,2)])]
descriptors += [('phase',ks,()) for ks in phase_tuples]
rows=[]
for mode,ks,flush in descriptors:
    cid=f"{mode}-{'-'.join(map(str,ks))}-flush{''.join(map(str,flush)) or 'none'}"
    branches=[evaluate(mode,ks,flush,q,p['training_writer_gap'],p['training_tick_phase']) for q in qs]
    rows.append({'candidate_id':cid,'mode':mode,'K':list(ks),'flush':list(flush),
        'max_path_bound':max(r['W'] for r in branches),'all_paths_admitted':all(r['budget_admitted'] for r in branches),
        'worst_training_joint':max(r['execution']['makespan'] for r in branches),
        'worst_training_receiver':max(r['execution']['reader_cycles'] for r in branches),
        'worst_training_updates':max(r['execution']['updates'] for r in branches),'paths':branches})
fixed=min((r for r in rows if r['mode']=='fixed' and r['all_paths_admitted']),key=key,default=None)
phase=min((r for r in rows if r['mode']=='phase' and r['all_paths_admitted']),key=key,default=None)
deployed=phase if phase and (fixed is None or phase['worst_training_joint']<fixed['worst_training_joint']) else fixed
elapsed=time.perf_counter()-start;after=memory()
# This reference read/verification is outside the measured window.
expected=load_expected('full')
assert rows==expected
result={'scope':'Complete prescribed offline training selection: candidate/input construction, 4833 analyze+simulate training executions, max-path admission and minimum-training-joint selection. No held-out tests or native runs.',
    'wall_seconds':elapsed,'memory_before':before,'memory_after':after,'run_id':sys.argv[1] if len(sys.argv)>1 else '1',
    'python':sys.version,'platform':platform.platform(),'candidate_count':len(rows),'training_executions':len(rows)*len(qs),
    'budget':B,'budget_inputs':budget_rows,'all_candidate_rows_exactly_match_frozen':True,
    'selected_fixed':{k:fixed[k] for k in ['K','flush','worst_training_joint','worst_training_receiver','worst_training_updates']},
    'selected_phase':{k:phase[k] for k in ['K','flush','worst_training_joint','worst_training_receiver','worst_training_updates']},
    'deployed_candidate_id':deployed['candidate_id'],
    'measurement_excludes':'Python startup/import, protocol file I/O, verification/reference reading, serialization, held-out executions. The simulated cycle loops and data-dependent request execution are included.',
    'memory_method':'Absolute Windows process peak before loading expected results; includes Python/model and all retained full candidate observations.',
    'model_sha256':p['model_sha256'],'script_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest()}
(HERE/f"FULL_SELECTION_PROFILE_{result['run_id']}.json").write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(json.dumps(result,indent=2))
