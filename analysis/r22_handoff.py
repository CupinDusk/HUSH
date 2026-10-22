"""Complete/incremental payload routing, finite decisions, separate JSON consumer."""
from pathlib import Path
from collections import Counter
import copy,hashlib,json,subprocess,sys
from handoff_consumer import consume
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def key(r):return (r['P'],r['g'],r['J'],r['A'],tuple(r['completion_residues_g']),tuple(map(tuple,r['profile_g'])))

def issue(r,mode):
    assert mode in ['complete_new','existing_completion']
    binding={'identity':'block0','epoch':'fixed-model-epoch','horizon':'recurrent-valid-entry','P':r['P'],'d':r['d']}
    C,W,nu=r['completion_residues_g'],r['joint_witness_residues_g'],r['profile_g'];m,w,t=len(C),len(W),len(nu)
    context={'bindings':binding};base={'C_g':C,'J':r['J'],'A':r['A']}
    if mode=='existing_completion':context['existing_completion']=base
    completion_cost=m+w+5 if mode=='complete_new' else w+2
    if r['exact'] and completion_cost<2*t+1:
        payload={'bindings':binding,'kind':'completion','joint_witness_residues_g':W,'exact_status':True}
        if mode=='complete_new':payload['completion']=base
    else:payload={'bindings':binding,'kind':'profile','profile_g':nu}
    # This response-phase consumer is an explicit prototype use of pre-existing fields.
    response={'completion_residue_envelope_g':C,'request_to_next_decision_bound':r['J']+r['A']} if mode=='existing_completion' else None
    return context,payload,response

def tally(rows):
    decision=Counter();routes={mode:Counter() for mode in ['complete_new','existing_completion']};queries=0;signloss=0
    for r in rows:
        counts=Counter()
        for K in range(1,5):
            B=(K-1)*r['P']
            for phi in range(r['P']):
                abstract=B-r['J']+1+min((phi+r['J']-1-c)%r['g'] for c in r['completion_residues_g'])-r['A']
                exact=B+1+min((phi-s-1)%r['g']-v for s,v in r['profile_g'])
                assert exact>=abstract
                counts['both_certify' if abstract>0 else 'profile_only_certifies' if exact>0 else 'neither_certifies']+=1
                queries+=1
        assert counts['profile_only_certifies']==r['finite_K1_to4_sign_differences'];decision.update(counts);signloss+=counts['profile_only_certifies']
        for mode in routes:
            context,payload,response=issue(r,mode)
            routes[mode][payload['kind']]+=1
            for K,phi in [(1,0),(4,r['P']-1)]:
                got=consume(context,payload,{'P':r['P'],'K':K,'phi':phi})
                wanted=(K-1)*r['P']+1+min((phi-s-1)%r['g']-v for s,v in r['profile_g'])
                assert got['slack']==wanted
    return {'interfaces':len(rows),'physical_phase_K1_to4_queries':queries,'decision_counts':dict(decision),'profile_only_total':signloss,'routing':{k:dict(v) for k,v in routes.items()}}

def demonstrate(r,mode,K,phi,out,name):
    context,payload,response=issue(r,mode);query={'P':r['P'],'K':K,'phi':phi};folder=out/name;folder.mkdir()
    for filename,record in [('context',context),('payload',payload),('query',query)]:
        (folder/(filename+'.json')).write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8')
    run=subprocess.run([sys.executable,'-B','-X','utf8',str(HERE/'handoff_consumer.py'),'--context',str(folder/'context.json'),'--payload',str(folder/'payload.json'),'--query',str(folder/'query.json')],capture_output=True,text=True,timeout=30)
    assert run.returncode==0,run.stderr
    got=json.loads(run.stdout);assert got==consume(context,payload,query)
    (folder/'consumer-output.json').write_text(json.dumps(got,indent=2)+'\n',encoding='utf-8')
    return {'client':r.get('client'),'P':r['P'],'g':r['g'],'m':len(r['completion_residues_g']),'w':len(r['joint_witness_residues_g']),'t':len(r['profile_g']),
            'mode':mode,'response_phase_consumer':response,'context':context,'payload':payload,'query':query,'result':got}

def main():
    protocol=HERE/'R22_HANDOFF_PROTOCOL.json';spec=json.loads(protocol.read_text(encoding='utf-8'))
    source=HERE/'R21_LIFT_RESULTS.json';lift=json.loads(source.read_text(encoding='utf-8'));rows=lift['cases'];assert len(rows)==11904
    unique={}
    for r in rows:
        k=key(r)
        if k in unique:assert unique[k]['exact']==r['exact']
        unique[k]=r
    assert len(unique)==2510
    reports={'raw_cycle_period':tally(rows),'deduplicated_interface':tally(list(unique.values()))}
    main=next(r for r in rows if r['client']==[5,1,3,8] and r['P']==5)
    full_candidates=sorted((r for r in rows if r['exact'] and len(r['completion_residues_g'])+len(r['joint_witness_residues_g'])+5<2*len(r['profile_g'])+1),key=lambda r:(r['client'],r['P']))
    assert full_candidates
    out=HERE/'r22-handoff-build';assert not out.exists();out.mkdir()
    demos=[demonstrate(main,'complete_new',4,0,out,'main_full'),demonstrate(main,'existing_completion',4,0,out,'main_incremental'),
           demonstrate(full_candidates[0],'complete_new',4,0,out,'first_full_completion_advantage')]
    slow={'client':[4,1,100,9],'P':9,'d':36,'g':9,'J':7,'A':5,'completion_residues_g':[5,6,7,8],'joint_witness_residues_g':[],
          'profile_g':[[1,9]],'exact':False}
    demos.append(demonstrate(slow,'existing_completion',2,8,out,'slow_profile_fallback'))
    context,payload,response=issue(main,'existing_completion');query={'P':5,'K':4,'phi':0};rejects={}
    for field in ['identity','epoch','horizon','P','d']:
        bad=copy.deepcopy(payload);bad['bindings'][field]=bad['bindings'][field]+1 if isinstance(bad['bindings'][field],int) else 'stale-other'
        try:consume(context,bad,query)
        except AssertionError:rejects['stale_'+field]='REJECTED'
        else:raise AssertionError('stale binding accepted')
    for name,value in [('false_exact_status',False),('missing_exact_status',None)]:
        bad=copy.deepcopy(payload);bad['exact_status']=value
        try:consume(context,bad,query)
        except AssertionError:rejects[name]='REJECTED'
        else:raise AssertionError('bad status accepted')
    bad=copy.deepcopy(payload);bad['joint_witness_residues_g']=[]
    try:consume(context,bad,query)
    except AssertionError:rejects['missing_witness']='REJECTED'
    else:raise AssertionError('bad witnesses accepted')
    result={'result':'PASS_R22_SERIALIZED_HANDOFF_AND_DECISION_ACCOUNTING','protocol_sha256':sha(protocol),'script_sha256':sha(Path(__file__)),
            'consumer_sha256':sha(HERE/'handoff_consumer.py'),'input_lift_results_sha256':sha(source),'new_source_execution':False,'new_native_measurements':0,
            'reports':reports,'demonstrations':demos,'negative_binding_controls':rejects,'scientific_boundary':spec['new_evidence_boundary']}
    (HERE/'R22_HANDOFF_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'result':result['result'],'reports':reports,'demonstrations':[{'mode':d['mode'],'client':d['client'],'P':d['P'],'mwt':[d[k] for k in ['m','w','t']],'result':d['result']} for d in demos],'negative_controls':rejects}))
if __name__=='__main__':main()
