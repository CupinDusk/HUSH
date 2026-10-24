"""Evaluate one common phase policy over a supplied finite bounded path set."""
from pathlib import Path
from itertools import product
import csv,hashlib,json,time
import replacement_model as m
HERE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
p=json.loads((HERE/'PROTOCOL.json').read_text(encoding='utf-8'))
assert sha(HERE/'replacement_model.py')==p['model_sha256']
assert sha(HERE/'interlocked_closed_loop_protocol.json')==p['base_protocol_sha256']
base=dict(m.P);qs=p['path_shared_blocks'];B=None

def path(q,mode):
    m.P.clear();m.P.update(base,shared_blocks=q,receiver_dense_reads=8*q,
        receiver_compute_gap=p['receiver_compute_gap'],writer_store_count=64*q,period=p['period'])
    original=m.instructions(p['path_family'],p['quiet_compute'])
    assert sum(v for op,v in original if op=='compute')==9*q+512
    assert sum(op=='read' for op,v in original)==9*q+1
    if mode=='fixed':return original
    ops=[]
    for op,v in original:
        if op=='phase' and v>0:ops.append(('compute',p['helper_delta']))
        ops.append((op,v))
    return ops

budget_rows=[]
for q in qs:
    ops=path(q,'fixed');C=sum(v for op,v in ops if op=='compute');nr=sum(op=='read' for op,v in ops)
    b0=C+q*(m.P['update_slot_cycles']+1+m.P['miss_slot_cycles'])+(nr-q)
    assert b0==88*q+513
    budget_rows.append({'q':q,'Cbase':C,'reads':nr,'B0':b0})
B=max(row['B0'] for row in budget_rows)+32;assert B==1249

def evaluate(mode,ks,flush,q,gap,phi):
    ops=path(q,mode)
    a=m.analyze(ops,ks,flush_at_boundaries=flush)
    r=m.simulate(ops,ks,gap,phi,a,writer_count=64*q,flush_at_boundaries=flush,flush_at_finish=True)
    assert r['unsafe_hits']==0 and r['reader_cycles']<=a['bound']
    C=sum(v for op,v in ops if op=='compute')
    return {'q':q,'W':a['bound'],'C':C,'M':a['bound']-C-a['switches'],
        'changed_loads':a['switches'],'analysis_hits':a['hits'],'analysis_unknown':a['unknown'],
        'budget_admitted':a['bound']<=B,'execution':r}

def selection_key(row):
    return (row['worst_training_joint'],row['worst_training_receiver'],row['worst_training_updates'],tuple(row['K']),tuple(row['flush']))

start=time.perf_counter();rows=[]
phase_tuples=sorted(set(product(p['phase_domain'],repeat=3))|{(k,k,k) for k in range(1,256)})
assert len(phase_tuples)==591
descriptors=[('fixed',(k,k,k),f) for k,f in product(range(1,256),[(),(1,),(2,),(1,2)])]
descriptors += [('phase',ks,()) for ks in phase_tuples]
for mode,ks,flush in descriptors:
    candidate_id=f"{mode}-{'-'.join(map(str,ks))}-flush{''.join(map(str,flush)) or 'none'}"
    branch_rows=[evaluate(mode,ks,flush,q,p['training_writer_gap'],p['training_tick_phase']) for q in qs]
    row={'candidate_id':candidate_id,'mode':mode,'K':list(ks),'flush':list(flush),
        'max_path_bound':max(r['W'] for r in branch_rows),
        'all_paths_admitted':all(r['budget_admitted'] for r in branch_rows),
        'worst_training_joint':max(r['execution']['makespan'] for r in branch_rows),
        'worst_training_receiver':max(r['execution']['reader_cycles'] for r in branch_rows),
        'worst_training_updates':max(r['execution']['updates'] for r in branch_rows),
        'paths':branch_rows}
    assert row['all_paths_admitted']==(row['max_path_bound']<=B)
    rows.append(row)
fixed=min((r for r in rows if r['mode']=='fixed' and r['all_paths_admitted']),key=selection_key,default=None)
phase=min((r for r in rows if r['mode']=='phase' and r['all_paths_admitted']),key=selection_key,default=None)
deployed=phase if phase and (fixed is None or phase['worst_training_joint']<fixed['worst_training_joint']) else fixed
mutants=[r for r in rows if r['paths'][0]['budget_admitted'] and not r['all_paths_admitted']]
witness=min(mutants,key=lambda r:(r['paths'][0]['execution']['makespan'],r['candidate_id']),default=None)
freeze={'protocol_sha256':sha(HERE/'PROTOCOL.json'),'budget':B,'budget_derivation':budget_rows,
    'fixed':fixed,'phase':phase,'deployed_mode':deployed and deployed['mode'],
    'deployed_candidate_id':deployed and deployed['candidate_id'],
    'mutation_q2_only_false_admission_count':len(mutants),'mutation_witness':witness,
    'held_out_executions_seen':False}
(HERE/'FROZEN_SELECTION.json').write_text(json.dumps(freeze,indent=2)+'\n',encoding='utf-8',newline='\n')
validation=[]
for q,gap,phi in product(qs,p['validation_writer_gaps'],p['validation_tick_phases']):
    point={'q':q,'writer_gap':gap,'phi':phi}
    for name,candidate in [('fixed',fixed),('phase',phase)]:
        point[name]=evaluate(name,candidate['K'],candidate['flush'],q,gap,phi) if candidate else None
        if candidate:assert point[name]['W']<=B
    if fixed and deployed:
        fr=point['fixed']['execution'];dr=point[deployed['mode']]['execution']
        point['deployed_mode']=deployed['mode']
        point['signed_joint_improvement']=(fr['makespan']-dr['makespan'])/fr['makespan']
    validation.append(point)
mutation={
    'all_q2_only_false_admission_ids':[r['candidate_id'] for r in mutants],
    'witness':witness,
    'interpretation':'q2-only admission fails to certify every supplied path; a high bound is not by itself an actual deadline overrun.',
    'witness_training_actual_receiver_overruns':[
        {'q':r['q'],'receiver':r['execution']['reader_cycles'],'budget':B}
        for r in witness['paths'] if r['execution']['reader_cycles']>B] if witness else [],
}
all_training=[b for r in rows for b in r['paths']]
all_validation=[t[k] for t in validation for k in ['fixed','phase'] if t[k]]
summary={'paths':len(qs),'candidate_count':len(rows),'training_executions':len(all_training),
    'fixed_robust_admitted':sum(r['mode']=='fixed' and r['all_paths_admitted'] for r in rows),
    'phase_robust_admitted':sum(r['mode']=='phase' and r['all_paths_admitted'] for r in rows),
    'validation_points':len(validation),'validation_executions':len(all_validation),
    'unsafe_hits':sum(r['execution']['unsafe_hits'] for r in all_training+all_validation),
    'bound_violations':sum(r['execution']['reader_cycles']>r['W'] for r in all_training+all_validation),
    'deployed_receiver_budget_violations':sum(t[t['deployed_mode']]['execution']['reader_cycles']>B for t in validation),
    'mutation_false_admission_candidates':len(mutants),
    'deployed_mode':deployed and deployed['mode'],
    'deployed_wins':sum(t['signed_joint_improvement']>0 for t in validation),
    'deployed_ties':sum(t['signed_joint_improvement']==0 for t in validation),
    'deployed_losses':sum(t['signed_joint_improvement']<0 for t in validation),
    'deployed_signed_joint_improvement_min':min(t['signed_joint_improvement'] for t in validation),
    'deployed_signed_joint_improvement_max':max(t['signed_joint_improvement'] for t in validation)}
result={'protocol_sha256':sha(HERE/'PROTOCOL.json'),'driver_sha256':sha(Path(__file__)),
    'frozen_selection_sha256':sha(HERE/'FROZEN_SELECTION.json'),'summary':summary,'validation':validation}
(HERE/'ALL_CANDIDATES.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8',newline='\n')
(HERE/'MUTATION_CHECK.json').write_text(json.dumps(mutation,indent=2)+'\n',encoding='utf-8',newline='\n')
(HERE/'RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
flat=[]
for row in rows:
    flat.append({k:row[k] for k in ['candidate_id','mode','K','flush','max_path_bound','all_paths_admitted','worst_training_joint','worst_training_receiver','worst_training_updates']}|{f'W_q{b["q"]}':b['W'] for b in row['paths']})
with (HERE/'CANDIDATE_BOUNDS.csv').open('w',encoding='utf-8',newline='') as f:
    writer=csv.DictWriter(f,list(flat[0]),lineterminator='\n');writer.writeheader();writer.writerows(flat)
print(json.dumps({'summary':summary,'budget':B,'selected_fixed_K':fixed and fixed['K'],'selected_phase_K':phase and phase['K'],'elapsed_seconds':time.perf_counter()-start},indent=2))
