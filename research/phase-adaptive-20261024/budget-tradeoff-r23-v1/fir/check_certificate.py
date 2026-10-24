"""Independent source-loop / absolute-expiry certificate checker.

Does not import the emitter or original replacement model. Reconstructs the C
loop event sequence and uses absolute deadlines plus distinct-reference reuse
distance, unlike the original model's decrementing remainder/LRU-stack transfer.
"""
from pathlib import Path
from collections import Counter
import copy,csv,hashlib,json
HERE=Path(__file__).resolve().parent
def require(condition,message):
    if not condition:raise ValueError(message)
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def source_loop_trace():
    def d(op,name,i):return ['D',op,name,str(i)]
    def pin():
        out=[d('W','image',i) for i in range(16)]+[d('W','coeff',i) for i in range(9)]+[d('W','array',i) for i in range(6)]
        for f in range(4):
            out.append(d('W','array',6+6*f))
            for i in range(4):out.extend([d('R','image',4*f+i),d('W','array',7+6*f+i)])
            out.append(d('W','array',11+6*f))
        return out+[d('W','array',i) for i in range(30,36)]+[d('W','output',i) for i in range(16)]
    trace=[['S','prepare']]+pin()
    for k in range(4):
        if k<2:trace.append(['P',str(k)])
        for f in range(4):
            o=4*k+f;trace.append(d('W','output',o))
            for row in range(3):
                for i in range(3):trace.extend([d('R','coeff',3*row+i),d('R','array',6*k+f+6*row+i),d('R','output',o),d('W','output',o)])
    return trace+[['P','2'],d('R','output',0),d('R','output',5),d('R','array',9),d('W','result',0),['RESULT','14'],['S','cleanup']]+pin()

def replay(trace,A,mapping,mode):
    g=A['geometry'];c=mapping['compute_cycles_per_explicit_data_event'];p=mapping['private_data_service_cycles'];h=mapping['noninitial_marker_helper_cycles']
    s=A['service_contract'];unknown=max(s['private_store_cycles']+s['update_slot_cycles']+s['miss_slot_cycles'],s['configuration_collision_residual_cycles']+s['miss_slot_cycles'])
    deadlines={};reference_history=[];t=0;stage='prepare';phase=None;k=A['phase_loads'][0];H=U=switches=0
    predictions=[];ledger=[];boundaries=[];witness=[];totals=Counter();by_stage={}
    def retention(load):return 10**12 if load==255 else (load-1)*A['period_cycles']
    def rho():return {str(b):deadline-t for b,deadline in deadlines.items()}
    def shadow():
        recent=[]
        for b in reversed(reference_history):
            if b not in recent:recent.append(b)
        return recent[:g['ways']]
    for index,e in enumerate(trace):
        if e[0]=='S':stage=e[1]
        elif e[0]=='P':
            stage='body';phase=int(e[1]);load=A['phase_loads'][phase]
            state_before_helper=rho();stack=shadow();t_before_helper=t
            if phase:t+=h;totals['marker_helpers']+=h
            if load!=k:
                before=dict(deadlines);clamp=t+retention(load)
                after_helper=rho()
                deadlines={b:(min(v,clamp) if mode=='carry' else -10**20) for b,v in deadlines.items()}
                boundary={'trace_index':index,'event':'marker','phase':phase,'t_before_helper':t_before_helper,'t_before_write':t,'old_K':k,'new_K':load,'deadlines_before':before,'deadlines_after_transfer':dict(deadlines),'rho_before_helper':state_before_helper,'rho_after_helper':after_helper,'rho_after_cap_before_write':rho(),'shadow_before':stack,'shadow_after':stack}
                t+=s['configuration_write_cycles'];totals['configuration_writes']+=s['configuration_write_cycles'];switches+=1;k=load
                boundary.update(t_after_write=t,rho_after_write=rho());boundaries.append(boundary);witness.append(boundary)
        elif e[0]=='D':
            shared=stage=='body' and e[1:3]==['R','array'];label=f'phase{phase}' if stage=='body' else stage
            row={'trace_index':index,'event':'data','stage':label,'op':e[1],'object':e[2],'index':int(e[3]),'compute':c,'private_service':0,'shared_service':0,'K':k,'t_before_compute':t,'rho_before_compute':rho(),'shadow_before':shadow()}
            t+=c;totals['compute']+=c
            row['rho_after_compute_before_service']=rho()
            if shared:
                block=int(e[3])*g['float_bytes']//g['block_bytes'];previous=[j for j,b in enumerate(reference_history) if b==block]
                distinct=set(reference_history[previous[-1]+1:]) if previous else set()
                resident=bool(previous) and sum(b%g['sets']==block%g['sets'] for b in distinct)<g['ways']
                deadline=deadlines.get(block,-10**20);hit=resident and deadline>t
                service=s['local_hit_cycles'] if hit else unknown
                predictions.append({'trace_index':index,'guaranteed_hit':hit,'residency_guaranteed':resident})
                row.update(block=block,read_issue_bound=t,previous_deadline=deadline,residency_guaranteed=resident,guaranteed_hit=hit,shared_service=service)
                H+=int(hit);U+=int(not hit);deadlines[block]=t+retention(k);reference_history.append(block)
                row['rho_after_reload_before_service']=rho()
                t+=service;totals['shared_service']+=service
            else:row['private_service']=p;t+=p;totals['private_service']+=p
            row.update(t_after=t,rho_after_service=rho(),shadow_after=shadow());ledger.append(row);witness.append(row)
            by_stage.setdefault(label,Counter()).update(data=1,shared=int(shared),private=int(not shared),compute=c,private_service=row['private_service'],shared_service=row['shared_service'])
    return {'H':H,'U':U,'switches':switches,'shared_service':totals['shared_service'],'W':t,'predictions':predictions},ledger,boundaries,dict(totals),{k:dict(v) for k,v in by_stage.items()},witness

def check(cert,assumptions=None,trace=None):
    A=assumptions or json.loads((HERE/'ASSUMPTIONS.json').read_text());T=trace or json.loads((HERE/'ALL_DATA_TRACE.json').read_text())
    binding=json.loads((HERE/'INPUT_BINDING.json').read_text())
    require(cert['input_binding_sha256']==digest(HERE/'INPUT_BINDING.json'),'binding hash')
    require(cert['assumptions_sha256']==digest(HERE/'ASSUMPTIONS.json'),'assumptions hash')
    for name,row in binding['inputs'].items():require(digest(HERE/name)==row['sha256'],'input hash '+name)
    require(A==json.loads((HERE/'ASSUMPTIONS.json').read_text()),'assumption content changed')
    require(T==source_loop_trace(),'source loop trace mismatch')
    audit=json.loads((HERE/'COMPILE_AUDIT.json').read_text())
    require([line.split() for line in audit['runs'][1]['stdout'].splitlines()]==T,'retained C stdout trace mismatch')
    require(sum(e[0]=='D' for e in T)==782 and len(T)==cert['source_event_rows'],'event cardinality')
    access=Counter('/'.join(e[1:3]) for e in T if e[0]=='D');require(dict(access)==cert['access_kind_counts'],'global access-kind counts')
    s=A['service_contract'];require(s['clients']==2 and all(s[k] for k in ['one_outstanding_per_client','pending_miss_blocks_new_private_admission','round_robin','nonpreemptive']),'two-client service premises')
    require(cert['service_bound']['unknown_read_bound']==max(s['private_store_cycles']+s['update_slot_cycles']+s['miss_slot_cycles'],s['configuration_collision_residual_cycles']+s['miss_slot_cycles'])==71,'service closure')
    frozen=json.loads((HERE/'FROZEN_EXPECTED.json').read_text());details=[]
    require([r['map'] for r in cert['maps']]==[A['primary_map'],A['additional_check_map']],'certified maps')
    for row in cert['maps']:
        for mode in ['carry','reset']:
            result,ledger,boundaries,totals,stages,witness=replay(T,A,row['map'],mode)
            require(result==row['analyses'][mode],row['cell_id']+' '+mode+' independent transfer')
            require(result['H']+result['U']==145,'all shared reads classified')
            require({k:{j:v[j] for j in ['data','private','shared']} for k,v in stages.items()}==cert['source_counts'],'per-stage source accounting')
            for key in ['compute','private_service','marker_helpers','configuration_writes']:require(totals[key]==row['components'][key],'component '+key)
            require(sum(totals[k] for k in ['compute','private_service','marker_helpers','configuration_writes'])==row['components']['common_work'],'common work sum')
            require(sum(stages[label]['compute']+stages[label]['private_service'] for label in ['prepare','cleanup'])==row['components']['serial_prepare_cleanup'],'serial preparation/cleanup sum')
            require(result['W']==row['components']['common_work']+result['shared_service'],'full work sum')
            old=frozen[row['cell_id']]['cell'];prefix='carry' if mode=='carry' else 'reset'
            require(result['W']==old[prefix+'_receiver_work_bound'] and result['H']==old[prefix+'_analysis_hits'] and result['U']==old[prefix+'_analysis_unknown'],'frozen R18/R22 result')
            details.append({'cell_id':row['cell_id'],'mode':mode,'stages':stages,'boundary_transfers':boundaries,'result':{k:v for k,v in result.items() if k!='predictions'}})
            if mode=='carry' and row is cert['maps'][0]:
                selected=[x for x in witness if 242<=x['trace_index']<=247]
                (HERE/'BOUNDARY_WITNESS.json').write_text(json.dumps({'cell_id':row['cell_id'],'indexing':'zero-based ALL_DATA_TRACE.json row index; time includes serial preparation; rows242..247 are six consecutive source/marker events','events':selected,'all_boundaries':boundaries,'order':'debit helper; cap existing rho to new retention on a load change; debit one write cycle; for each data event debit compute; on shared read test rho>0 and shadow residency; update shadow stack; reload accessed rho to (K-1)P; debit 1 or71 service to all rho. A private event debits its private service after compute. Actual timers are not rewritten by this conservative analysis cap.'},indent=2)+'\n',encoding='utf-8')
                with (HERE/'PRIMARY_EVENT_LEDGER.csv').open('w',newline='',encoding='utf-8') as f:
                    keys=list(dict.fromkeys(k for x in ledger for k in x));w=csv.DictWriter(f,keys,lineterminator='\n');w.writeheader();w.writerows(ledger)
        require(row['derived_receiver_only_budget_interval']==[row['analyses']['carry']['W'],row['analyses']['reset']['W']-1],'derived budget interval')
        expected=frozen[row['cell_id']]['executions'];require(len(row['observations'])==len(expected)==10,'ten deterministic phases')
        for obs,old in zip(row['observations'],expected):
            require(obs['phi']==old['phi'] and obs['complete_receiver_work']==old['model_receiver_work'] and obs['complete_joint_completion']==old['model_joint_completion'],'frozen observation replay')
            for field in ['reader_cycles','writer_cycles','makespan','updates','deliveries','actual_misses','actual_hits','analysis_hits','analysis_unknown','max_read_service','max_update_service','unsafe_hits','config_wu_deferrals','replacement_evictions']:require(obs['execution'][field]==old['execution'][field],'execution field '+field)
            require(obs['complete_receiver_work']<=row['analyses']['carry']['W'],'observation below bound')
    return details

if __name__=='__main__':
    cert=json.loads((HERE/'CERTIFICATE.json').read_text());details=check(cert)
    mutations=[]
    def reject(name,change,assumptions=None,trace=None):
        wrong=copy.deepcopy(cert);change(wrong)
        try:check(wrong,assumptions,trace)
        except (ValueError,KeyError) as exc:mutations.append({'mutation':name,'rejected':True,'reason':str(exc)})
        else:raise RuntimeError('undetected mutation: '+name)
    reject('increase guaranteed H without reclassification',lambda x:x['maps'][0]['analyses']['carry'].__setitem__('H',140))
    reject('reduce complete carry bound by one',lambda x:x['maps'][0]['analyses']['carry'].__setitem__('W',4339))
    reject('substitute reset transfer as carry',lambda x:x['maps'][0]['analyses'].__setitem__('carry',x['maps'][0]['analyses']['reset']))
    reject('drop one private source event',lambda x:None,trace=source_loop_trace()[:1]+source_loop_trace()[2:])
    A=json.loads((HERE/'ASSUMPTIONS.json').read_text());A['service_contract']['miss_slot_cycles']=59
    reject('change miss service assumption 60 to59',lambda x:None,assumptions=A)
    reject('omit two helper charges',lambda x:x['maps'][0]['components'].__setitem__('marker_helpers',0))
    reject('flip guaranteed-hit bit',lambda x:x['maps'][0]['analyses']['carry']['predictions'][0].__setitem__('guaranteed_hit',True))
    reject('alter observed receiver total',lambda x:x['maps'][0]['observations'][0].__setitem__('complete_receiver_work',4164))
    (HERE/'CHECK_REPORT.json').write_text(json.dumps({'all_passed':True,'checker_does_not_import_model_or_emitter':True,'independence':'Separate source-loop reconstruction and absolute-deadline/reuse-distance transfer; execution observations rerun by unchanged model and compared to frozen record, not independently simulated.','maps_checked':2,'shared_prediction_decisions_checked':580,'explicit_source_events':782,'deterministic_observations_checked':20,'source_loop_sequence_matches_retained_compiled_stdout':True,'mutations':mutations,'details':details},indent=2)+'\n',encoding='utf-8')
    print('PASS: 782-event source reconstruction; 580 independent shared-read decisions; 20 frozen observations; 8/8 mutations rejected.')
