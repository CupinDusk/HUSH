"""Complete FIR2DIM source-path sensitivity with byte-exact R14 model/trace."""
from pathlib import Path
from itertools import product
import csv, hashlib, json, time
import replacement_model as m

HERE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
p=json.loads((HERE/'PROTOCOL.json').read_text(encoding='utf-8'))
assert p['status']=='frozen_before_new_cost_grid_execution'
for name,value in p['input_sha256'].items(): assert sha(HERE/name)==value,(name,value)
trace=json.loads((HERE/'ALL_DATA_TRACE.json').read_text(encoding='utf-8'))
prepare=[];body=[];cleanup=[];stage='prepare'
for e in trace:
    if e[0]=='S': stage=e[1]
    elif e[0]=='P': stage='body';body.append(e)
    elif e[0]=='D': {'prepare':prepare,'body':body,'cleanup':cleanup}[stage].append(e)
assert len(prepare)==len(cleanup)==93
assert sum(e[0]=='D' for e in body)==596
assert sum(e[:3]==['D','R','array'] for e in body)==145
assert sum(e[0]=='P' for e in body)==3
base=dict(m.P)
m.P.update(shared_blocks=3,writer_store_count=p['writer_stores'],period=p['period'])
assert m.P['switch_cycles']==1
ks=tuple(p['phase_loads']);g=p['geometry']

def instructions(compute,private,helper):
    ops=[]
    for e in body:
        if e[0]=='P':
            phase=int(e[1])
            if phase: ops.append(('compute',helper))
            ops.append(('phase',phase))
        else:
            ops.append(('compute',compute))
            if e[1:3]==['R','array']:
                ops.append(('read',(4*int(e[3]))//g['block_bytes']))
            else: ops.append(('compute',private))
    return ops

start=time.perf_counter();cells=[];executions=[]
for compute,private,helper in product(p['compute_cycles_per_source_data_interval'],p['private_data_service_cycles'],p['marker_helper_cycles']):
    cell_id=f'c{compute}-p{private}-h{helper}'
    ops=instructions(compute,private,helper)
    serial=186*(compute+private)
    common_nonmemory=782*compute+637*private+2*helper+2*m.P['switch_cycles']
    carry=m.analyze(ops,ks,cache_sets=g['sets'],cache_ways=g['ways'])
    reset=m.analyze(ops,ks,reset=True,cache_sets=g['sets'],cache_ways=g['ways'])
    assert carry['switches']==reset['switches']==2
    carry_w=serial+carry['bound'];reset_w=serial+reset['bound']
    assert carry_w<=reset_w
    row={
        'cell_id':cell_id,'compute_gap':compute,'private_service':private,'helper_delta':helper,
        'nondata_compute_bound':782*compute,'private_access_bound':637*private,
        'helper_bound':2*helper,'configuration_write_bound':2*m.P['switch_cycles'],
        'common_nonmemory_cycles':common_nonmemory,'serial_preparation_cleanup':serial,
        'carry_receiver_work_bound':carry_w,'reset_receiver_work_bound':reset_w,
        'carry_shared_memory_bound':carry_w-common_nonmemory,
        'reset_shared_memory_bound':reset_w-common_nonmemory,
        'bound_reduction_cycles':reset_w-carry_w,
        'bound_reduction_fraction':(reset_w-carry_w)/reset_w,
        'carry_analysis_hits':carry['hits'],'reset_analysis_hits':reset['hits'],
        'carry_analysis_unknown':carry['unknown'],'reset_analysis_unknown':reset['unknown'],
        'integer_receiver_budget_interval':[carry_w,reset_w-1] if carry_w<reset_w else None,
        'execution_row_ids':[],
    }
    for phi in p['decrement_phases']:
        result=m.simulate(ops,ks,p['writer_gap'],phi,carry,writer_count=p['writer_stores'],flush_at_finish=True,cache_sets=g['sets'],cache_ways=g['ways'])
        assert result['unsafe_hits']==0
        observed=serial+result['reader_cycles']
        assert observed<=carry_w<=reset_w
        execution={'row_id':f'{cell_id}-phi{phi}','cell_id':cell_id,'phi':phi,
            'model_receiver_work':observed,'model_joint_completion':serial+result['makespan'],
            'carry_bound':carry_w,'reset_bound':reset_w,
            'carry_slack':carry_w-observed,'reset_slack':reset_w-observed,
            'execution':result}
        row['execution_row_ids'].append(execution['row_id']);executions.append(execution)
    matched=executions[-len(p['decrement_phases']):]
    row.update(model_receiver_work_min=min(x['model_receiver_work'] for x in matched),
        model_receiver_work_max=max(x['model_receiver_work'] for x in matched),
        model_joint_completion_min=min(x['model_joint_completion'] for x in matched),
        model_joint_completion_max=max(x['model_joint_completion'] for x in matched),
        replacement_evictions_min=min(x['execution']['replacement_evictions'] for x in matched),
        replacement_evictions_max=max(x['execution']['replacement_evictions'] for x in matched))
    cells.append(row)
    print(cell_id,carry_w,reset_w,'decrease',reset_w-carry_w,'model receiver',row['model_receiver_work_min'],row['model_receiver_work_max'],flush=True)
assert len(cells)==p['grid_cells'] and len(executions)==p['expected_model_executions']
canonical={'protocol_sha256':sha(HERE/'PROTOCOL.json'),'driver_sha256':sha(Path(__file__)),
    'summary':{'cells':len(cells),'executions':len(executions),
        'strict_bound_reduction_cells':sum(x['bound_reduction_cycles']>0 for x in cells),
        'equal_bound_cells':sum(x['bound_reduction_cycles']==0 for x in cells),
        'bound_reduction_cycles_min':min(x['bound_reduction_cycles'] for x in cells),
        'bound_reduction_cycles_max':max(x['bound_reduction_cycles'] for x in cells),
        'bound_reduction_fraction_min':min(x['bound_reduction_fraction'] for x in cells),
        'bound_reduction_fraction_max':max(x['bound_reduction_fraction'] for x in cells),
        'unsafe_predicted_hits':sum(x['execution']['unsafe_hits'] for x in executions),
        'receiver_bound_violations':sum(x['model_receiver_work']>x['carry_bound'] for x in executions),
        'source_events_identical':True,'source_and_model_hashes_match':True},
    'cells':cells,'executions':executions}
(HERE/'RESULTS.json').write_text(json.dumps(canonical,indent=2)+'\n',encoding='utf-8',newline='\n')
with (HERE/'COST_GRID.csv').open('w',encoding='utf-8',newline='') as f:
    columns=[k for k in cells[0] if k not in ['execution_row_ids','integer_receiver_budget_interval']]
    writer=csv.DictWriter(f,columns,extrasaction='ignore',lineterminator='\n');writer.writeheader();writer.writerows(cells)
with (HERE/'EXECUTION_GRID.csv').open('w',encoding='utf-8',newline='') as f:
    columns=[k for k in executions[0] if k!='execution']
    writer=csv.DictWriter(f,columns,extrasaction='ignore',lineterminator='\n');writer.writeheader();writer.writerows(executions)
print(json.dumps({'summary':canonical['summary'],'elapsed_seconds':time.perf_counter()-start},indent=2))
