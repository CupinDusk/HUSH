"""Emit a full FIR input-to-budget certificate from the unchanged R22 model."""
from pathlib import Path
from collections import Counter
import csv,hashlib,json
import replacement_model as m
HERE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
A=json.loads((HERE/'ASSUMPTIONS.json').read_text());T=json.loads((HERE/'ALL_DATA_TRACE.json').read_text())
B=json.loads((HERE/'INPUT_BINDING.json').read_text())
for name,row in B['inputs'].items():assert sha(HERE/name)==row['sha256'],name
trace=[];stage='prepare';phase=None;counts=Counter();body=[]
for i,e in enumerate(T):
    if e[0]=='S':stage=e[1]
    elif e[0]=='P':stage='body';phase=int(e[1]);body.append((i,e))
    elif e[0]=='D':
        shared=stage=='body' and e[1:3]==['R','array']
        label=f'phase{phase}' if stage=='body' else stage
        counts[(label,'data')]+=1;counts[(label,'shared' if shared else 'private')]+=1
        counts[('global',e[1]+'/'+e[2])]+=1
        if stage=='body':body.append((i,e))
sc=A['service_contract'];Lm=max(sc['private_store_cycles']+sc['update_slot_cycles']+sc['miss_slot_cycles'],sc['configuration_collision_residual_cycles']+sc['miss_slot_cycles'])
m.P.update(shared_blocks=A['geometry']['shared_blocks'],writer_store_count=A['writer']['stores'],period=A['period_cycles'])
assert m.P['analytic_unknown_read_bound_cycles']==Lm==71
assert m.P['switch_cycles']==sc['configuration_write_cycles']==1
cert={'schema':'hush-fir-budget-certificate-v1','input_binding_sha256':sha(HERE/'INPUT_BINDING.json'),
      'assumptions_sha256':sha(HERE/'ASSUMPTIONS.json'),'source_event_rows':len(T),
      'source_counts':{label:{kind:counts[(label,kind)] for kind in ['data','private','shared']} for label in ['prepare','phase0','phase1','phase2','cleanup']},
      'access_kind_counts':{kind:count for (label,kind),count in counts.items() if label=='global'},
      'service_bound':{'ordinary':1+10+60,'configuration_collision':1+60,'unknown_read_bound':Lm,'tightness':'conservative envelope; no 71-cycle reachable witness claimed'},'maps':[]}
for mapping in [A['primary_map'],A['additional_check_map']]:
    c=mapping['compute_cycles_per_explicit_data_event'];p=mapping['private_data_service_cycles'];h=mapping['noninitial_marker_helper_cycles']
    ops=[];op_to_trace={}
    for i,e in body:
        if e[0]=='P':
            if int(e[1]):ops.append(('compute',h))
            ops.append(('phase',int(e[1])))
        else:
            ops.append(('compute',c))
            if e[1:3]==['R','array']:
                op_to_trace[len(ops)]=i;ops.append(('read',(int(e[3])*4)//64))
            else:ops.append(('compute',p))
    serial=186*(c+p);common=782*c+637*p+2*h+2
    row={'cell_id':f'c{c}-p{p}-h{h}','map':mapping,'components':{'compute':782*c,'private_service':637*p,'marker_helpers':2*h,'configuration_writes':2,'common_work':common,'serial_prepare_cleanup':serial},'analyses':{},'observations':[]}
    for mode in ['carry','reset']:
        r=m.analyze(ops,tuple(A['phase_loads']),reset=mode=='reset',cache_sets=1,cache_ways=2)
        preds=[{'trace_index':op_to_trace[i],'guaranteed_hit':hit,'residency_guaranteed':r['residency_predictions'][i]} for i,hit in r['predictions'].items()]
        row['analyses'][mode]={'H':r['hits'],'U':r['unknown'],'switches':r['switches'],'shared_service':r['hits']+Lm*r['unknown'],'W':serial+r['bound'],'predictions':preds}
        assert row['analyses'][mode]['W']==common+row['analyses'][mode]['shared_service']
    carry=m.analyze(ops,tuple(A['phase_loads']),cache_sets=1,cache_ways=2)
    for phi in A['decrement_phases']:
        r=m.simulate(ops,tuple(A['phase_loads']),A['writer']['compute_gap'],phi,carry,keep_trace=True,writer_count=A['writer']['stores'],flush_at_finish=True,cache_sets=1,cache_ways=2)
        row['observations'].append({'phi':phi,'complete_receiver_work':serial+r['reader_cycles'],'complete_joint_completion':serial+r['makespan'],'execution':r})
    row['derived_receiver_only_budget_interval']=[row['analyses']['carry']['W'],row['analyses']['reset']['W']-1]
    cert['maps'].append(row)
(HERE/'CERTIFICATE.json').write_text(json.dumps(cert,indent=2)+'\n',encoding='utf-8')
print(json.dumps({'maps':[{k:r[k] for k in ['cell_id','components','derived_receiver_only_budget_interval']}|{'carry':{k:v for k,v in r['analyses']['carry'].items() if k!='predictions'},'reset':{k:v for k,v in r['analyses']['reset'].items() if k!='predictions'},'observed':[x['complete_receiver_work'] for x in r['observations']]} for r in cert['maps']]},indent=2))
