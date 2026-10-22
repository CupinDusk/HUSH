"""Separate author-side auditor: no import of vector generator or DUT driver.

Inputs are the public frozen R03 files, serialized DUT evidence, and provenance.
Own event model uses per-client records, a deque and immutable tuple snapshots.
Policy arithmetic uses integer decrement counts and frozen cycle translations.
"""
from pathlib import Path
from collections import deque, Counter
import argparse, bisect, csv, gzip, hashlib, json, math, sys

HERE = Path(__file__).resolve().parent
SOURCE = HERE.parent
WORKSPACE = SOURCE.parents[3]

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def load(path):
    return json.loads(path.read_text(encoding='utf-8'))

def gz(path):
    with gzip.open(path, 'rt', encoding='utf-8') as f:
        return [json.loads(x) for x in f]

def need(test, message):
    if not test:
        raise AssertionError(message)

def eq(actual, expected, message):
    need(actual == expected, f'{message}: {actual!r} != {expected!r}')

def integer_csv(path):
    with path.open(newline='', encoding='utf-8') as f:
        for row in csv.DictReader(f):
            yield {k: int(v) for k, v in row.items()}

class Model:
    """Independent protocol-level receiver model, not read from RTL/C++ code."""
    def __init__(self, cfg):
        self.p, self.b, self.r = (cfg[k] for k in ('p','b','r'))
        self.clients = [dict(poll=0, pending=False, wait=False, serial=0),
                        dict(poll=self.b, pending=False, wait=False, serial=0)]
        self.queue = deque()
        self.regs = [None, None]
        self.latches = [(0,0,0), (0,0,0)]
        self.bytes = [0,0]
        self.valid = [True,True]
        self.count = [0,0]
        self.enabled = [False,False]
        self.lastgrant = self.lastemit = 0
        self.snapshots = {}

    def before(self, t):
        return [t % math.lcm(self.p,self.r),
                [None if x['poll'] is None else x['poll']-t for x in self.clients],
                [x['pending'] for x in self.clients],
                [x['wait'] for x in self.clients],
                [x[0] for x in self.queue],
                None if self.regs[0] is None else self.regs[0][0],
                None if self.regs[1] is None else self.regs[1][0]]

    def step(self, t, mode, cut):
        before = self.before(t)
        events = []
        extras = Counter()
        occupied_entry = self.regs[0] is not None
        word = 0 if mode is None else sum((t>cut[j]) << j for j in (0,1))
        extras['WUinput'] = word
        for j in (0,1):
            if word & (1<<j) and self.valid[j]:
                self.bytes[j] = 0 if mode==0 else 255 if mode==1 else (t*17+j*73)%256
                self.enabled[j], self.count[j] = True, 5
                extras['WUaccepted'] |= 1<<j
        if t % 24 == 0:
            for j in (0,1):
                if self.enabled[j]:
                    need(self.count[j] > 0, 'model counter misuse')
                    self.count[j] -= 1
                    if self.count[j] == 0:
                        self.valid[j] = self.enabled[j] = False
                        extras['expired'] |= 1<<j
        for j, client in enumerate(self.clients):
            if client['poll'] == t:
                if client['pending']:
                    client['poll'], client['wait'] = None, True
                    events.append(['wait',j])
                else:
                    client['serial'] += 1
                    client['pending'] = True
                    client['poll'] = t + (2+j)*self.p+1
                    self.queue.append((j,client['serial']))
                    events.append(['enqueue',j,client['serial']])
        extras['maxQueue'] = len(self.queue)
        extras['grantBlockedR0Queue'] = int(t%self.p==0 and occupied_entry and bool(self.queue))
        if t % self.p == 0:
            if not occupied_entry and self.queue:
                j, ident = self.queue.popleft()
                need(self.valid[j], f'unexpected model expiry at {t}')
                snap = (j,ident,self.bytes[j])
                self.regs[0] = self.latches[0] = snap
                need((j,ident) not in self.snapshots,'duplicate capture ID')
                self.snapshots[(j,ident)] = snap[2]
                self.lastgrant = snap[2]
                extras['cancelled'] = int(self.enabled[j]) << j
                self.enabled[j], self.count[j] = False, 0
                events.append(['grant',j,ident])
            emitted = None
            if self.regs[1] is not None:
                j, ident, value = self.regs[1]
                if t % self.r != 1:
                    emitted, self.regs[1] = self.regs[1], None
                    self.lastemit = value
                    eq(self.snapshots.pop((j,ident)),value,'immutable emission')
                    events.append(['emit',j,ident])
                else:
                    events.append(['backpressure',j,ident])
            if self.regs[0] is not None and self.regs[1] is None:
                self.regs[1] = self.latches[1] = self.regs[0]
                self.regs[0] = None
                j,ident,_ = self.regs[1]
                events.append(['transfer',j,ident])
            if emitted is not None:
                j,ident,_ = emitted
                client = self.clients[j]
                need(client['pending'],'model callback lacks pending ownership')
                client['pending'] = False
                if client['wait']:
                    client['wait'] = False
                    client['poll'] = t+(2+j)*self.p+1
                events.append(['callback',j,ident])
        tokens = Counter(j for j,_ in self.queue)
        for snap in self.regs:
            if snap is not None:
                tokens[snap[0]] += 1
                eq(self.snapshots[snap[:2]],snap[2], 'snapshot register ownership')
        for j,client in enumerate(self.clients):
            eq(tokens[j], int(client['pending']),'one pending token per client')
            need(not client['wait'] or (client['pending'] and client['poll'] is None),'wait discipline')
            need(client['poll'] is None or client['poll']>t,'future poll')
        eq(len(self.snapshots),sum(x is not None for x in self.regs),'snapshot count')
        need(sum(tokens.values())<=2 and len(self.queue)<=2,'two token/FIFO bound')
        out = dict(t=t, phase=before[0], pollDelayA=-1 if before[1][0] is None else before[1][0],
                   pollDelayB=-1 if before[1][1] is None else before[1][1],
                   pendingA=int(before[2][0]),pendingB=int(before[2][1]),
                   waitA=int(before[3][0]),waitB=int(before[3][1]),queueLength=len(before[4]),
                   queueOwner0=before[4][0] if before[4] else -1,
                   queueOwner1=before[4][1] if len(before[4])>1 else -1,
                   R0ownerBefore=-1 if before[5] is None else before[5],
                   R1ownerBefore=-1 if before[6] is None else before[6])
        out.update(waitEvents=0,enqEvents=0,enqIdA=0,enqIdB=0)
        for label in ('grant','emit','blocked','transfer','callback'):
            out[label+'Owner'],out[label+'Id'] = -1,0
        for typ,j,*rest in events:
            if typ=='wait': out['waitEvents'] |= 1<<j
            elif typ=='enqueue':
                out['enqEvents'] |= 1<<j
                out['enqId'+('B' if j else 'A')] = rest[0]
            else:
                name = 'blocked' if typ=='backpressure' else typ
                out[name+'Owner'],out[name+'Id'] = j,rest[0]
        for name in ('WUinput','WUaccepted','expired','cancelled'):
            out[name] = extras[name]
        out.update(validAfter=sum(int(x)<<j for j,x in enumerate(self.valid)),
                   enabledAfter=sum(int(x)<<j for j,x in enumerate(self.enabled)),
                   countA=self.count[0],countB=self.count[1],dataA=self.bytes[0],dataB=self.bytes[1],
                   grantByte=self.lastgrant,emitByte=self.lastemit,fault=0)
        for i,name in enumerate(('R0','R1')):
            owner,ident,value = self.latches[i]
            out.update({name+'valid':int(self.regs[i] is not None),name+'owner':owner,
                        name+'id':ident,name+'byte':value})
        return before,events,out,extras

def count_events(trace, rec, typ, horizon):
    """Event count through inclusive horizon using exact frozen cycle translation."""
    a,d = rec['cycle_entry_tick'],rec['translation']
    prefix = [t for t,_,es in trace if t<a for e in es if e[0]==typ]
    recurrent = [t-a for t,_,es in trace if a<=t<a+d for e in es if e[0]==typ]
    if horizon<a:
        return bisect.bisect_right(prefix,horizon)
    periods,rem = divmod(horizon-a,d)
    return len(prefix)+periods*len(recurrent)+bisect.bisect_right(recurrent,rem)

def edge_exists(rec, j, s,c,h):
    line = rec['lines'][j]
    if [s,c,h] in line['prefix']:
        return True
    d = rec['translation']
    return any(s>=s0 and (s-s0)%d==0 and c-c0==s-s0 and h-h0==s-s0
               for s0,c0,h0 in line['cycle'])

def audit_relations(records,traces):
    """Re-extract adjacent same-line grant/emission triples from the frozen events."""
    counts=Counter()
    for rec,tr in zip(records,traces):
        seen={}
        first_repeat=None
        grants=[[],[]]
        emits={}
        for t,key,es in tr['rows']:
            normalized=json.dumps(key,separators=(',',':'))
            if first_repeat is None:
                if normalized in seen:
                    first_repeat=(seen[normalized],t)
                else: seen[normalized]=t
            for e in es:
                if e[0]=='grant': grants[e[1]].append((t,e[2]))
                if e[0]=='emit':
                    need(tuple(e[1:]) not in emits,'unique emission identity')
                    emits[tuple(e[1:])]=t
        eq(first_repeat,(rec['cycle_entry_tick'],rec['repeat_tick']),'first repeated complete key')
        a,b,d=rec['cycle_entry_tick'],rec['repeat_tick'],rec['translation']
        for t in range(a,len(tr['rows'])-d):
            eq(tr['rows'][t][1],tr['rows'][t+d][1],'complete key translation')
        for j,line in enumerate(rec['lines']):
            triples=[]
            for (s,ident),(h,_) in zip(grants[j],grants[j][1:]):
                if s>=b: break
                c=emits[(j,ident)]
                need(s<c<h,'capture/emission/next grant order')
                triples.append([s,c,h])
            eq(line['initial_service_cutpoint'],grants[j][0][0],'actual initial capture cutpoint')
            eq(line['prefix'],[x for x in triples if x[0]<a],'re-extracted exact prefix triples')
            eq(line['cycle'],[x for x in triples if a<=x[0]<b],'re-extracted recurrent triples')
            counts['prefix_edges']+=len(line['prefix'])
            counts['cycle_edges']+=len(line['cycle'])
    return dict(counts)

def audit_phases(ref, records):
    phase_rows = gz(ref/'ALL_PHASE_BASES.jsonl.gz')[1:]
    negatives = gz(ref/'ALL_NEGATIVE_FIRST_FAILURES.jsonl.gz')[1:]
    negative_map = {tuple(x[:5]):x for x in negatives}
    eq(len(negative_map),len(negatives),'negative records unique')
    byid = {x['case_id']:x for x in records}
    expected = []
    results = Counter()
    maximum = Counter()
    pair_keys = set()
    per_case = {}
    for data in phase_rows:
        rec,P = byid[data['case_id']],data['P']
        ci = records.index(rec)
        eq(data['m'],math.gcd(P,rec['translation']),'physical phase modulus')
        need(1<=P<=4*rec['configuration']['p'],'P domain')
        pair_keys.add((ci,P))
        eq([r[0] for r in data['rows']],list(range(P)),'all physical phases')
        per_case.setdefault(rec['case_id'],Counter())
        for row in data['rows']:
            phi,base,completion,prefix,recur,j,s,c,h,supported,mask,cmask=row
            m=math.gcd(P,rec['translation'])
            prefix_values=[1+((phi-(s0+1))%P)-(h0-s0)
                           for line in rec['lines'] for s0,_,h0 in line['prefix']]
            pv=min(prefix_values) if prefix_values else None
            rv=min(1+((phi-(s0+1))%m)-(h0-s0)
                   for line in rec['lines'] for s0,_,h0 in line['cycle'])
            cv=min(1-line['J']-line['A']+((phi-(c0-line['J']+1))%m)
                   for line in rec['lines'] for c0 in line['C0'])
            eq(prefix,pv,'independent exact prefix base')
            eq(recur,rv,'independent gcd recurrence base')
            eq(base,min([rv]+prefix_values),'independent exact full base')
            eq(completion,min([cv]+prefix_values),'independent per-line completion base')
            eq(supported,all(line['posthoc_g']%m==0 for line in rec['lines']),'unsupported retained')
            eq(mask,sum((base+(K-1)*P>0)<<(K-1) for K in range(1,6)),'exact policy mask')
            eq(cmask,sum((completion+(K-1)*P>0)<<(K-1) for K in range(1,6)),'completion policy mask')
            need(edge_exists(rec,j,s,c,h),'actual lifted minimizer edge')
            eq(s+1+((phi-(s+1))%P)-h,base,'literal minimizer base')
            need(s+1>rec['lines'][j]['initial_service_cutpoint'],'WU after contract entry')
            for K in range(1,6):
                safe=base+(K-1)*P>0
                expired=s+1+((phi-(s+1))%P)+(K-1)*P
                need((expired>h)==safe,'literal one-WU expectation')
                if not safe:
                    n=negative_map.pop((rec['case_id'],P,phi,K,j))
                    eq(n[5:],[s,c,h,s+1,expired,h],'public negative first-failure witness')
                cfg=rec['configuration']
                expected.append(dict(query=len(expected),case=ci,p=cfg['p'],b=cfg['b'],r=cfg['r'],K=K,P=P,
                                     phi=phi,line=j,s=s,c=c,h=h,WUtick=s+1,expectedPass=int(safe),
                                     expectedExpiry=-1 if safe else expired))
                results['positive' if safe else 'negative']+=1
                results['completion_admitted']+=int(completion+(K-1)*P>0)
                results['service_extra_over_completion']+=int(safe and completion+(K-1)*P<=0)
                results['completion_extra_over_service']+=int(not safe and completion+(K-1)*P>0)
                results['unsupported_queries']+=int(not supported)
                results['posthoc_supported_queries']+=int(supported)
                results['posthoc_supported_full_positive']+=int(supported and safe)
                results['posthoc_supported_full_unknown']+=int(supported and not safe)
                results['posthoc_supported_service_only']+=int(supported and safe and completion+(K-1)*P<=0)
                per_case[rec['case_id']]['positive' if safe else 'negative']+=1
                per_case[rec['case_id']]['service_extra_over_completion']+=int(safe and completion+(K-1)*P<=0)
                maximum['h']=max(maximum['h'],h)
                maximum['s']=max(maximum['s'],s)
    eq(negative_map,{},'no negative witness discarded')
    eq(pair_keys,{(ci,P) for ci,r in enumerate(records) for P in range(1,4*r['configuration']['p']+1)},'all case/Ps')
    eq(len(expected),37000,'full physical policy domain')
    return expected,dict(results),dict(maximum),{k:dict(v) for k,v in per_case.items()}

def audit_ticks(build, records, traces):
    aggregates=Counter()
    case_rows=[]
    coverage=Counter()
    maxvals=Counter()
    control_tokens=iter(map(int,(build/'vectors'/'controls.txt').read_text().split()))
    eq(next(control_tokens),len(records),'serialized control vector case count')
    vector_fields='t phase pollDelayA pollDelayB pendingA pendingB waitA waitB queueLength queueOwner0 queueOwner1 R0ownerBefore R1ownerBefore waitEvents enqEvents enqIdA enqIdB grantOwner grantId emitOwner emitId blockedOwner blockedId transferOwner transferId callbackOwner callbackId'.split()
    for category,filename in ((0,'CONTROL_TICKS.csv'),(1,'DATA_TICKS.csv')):
        it=iter(integer_csv(build/filename))
        for pattern in range(3 if category else 1):
            for ci,rec in enumerate(records):
                model=Model(rec['configuration'])
                cut=[line['initial_service_cutpoint'] for line in rec['lines']]
                stats=Counter()
                if category==0:
                    eq([next(control_tokens) for _ in range(7)],
                       [ci,model.p,model.b,model.r,rec['validation_trace_ticks'],*cut],
                       'serialized control vector header')
                for t,key,events in traces[ci]['rows']:
                    row=next(it)
                    before,es,out,extra=model.step(t,pattern if category else None,cut)
                    eq(before,key,f'independent control key c{ci} t{t}')
                    eq(es,events,f'independent ordered events c{ci} t{t}')
                    out.update(category=category,pattern=pattern,case=ci)
                    if category==0:
                        eq([next(control_tokens) for _ in range(27)],
                           [out[k] for k in vector_fields],'every serialized control vector field')
                    eq(set(row),set(out),'all serialized CSV columns recognized')
                    for field,val in row.items():
                        eq(val,out[field],f'{filename} c{ci} p{pattern} t{t} {field}')
                    stats['ticks']+=1
                    for kind,name in [('grant','grants'),('emit','emits'),('backpressure','backpressure')]:
                        stats[name]+=sum(e[0]==kind for e in es)
                    for event,name in [('cancelled','cancels'),('expired','expiries'),('WUaccepted','WUs')]:
                        stats[name]+=out[event].bit_count()
                    stats['maxQueue']=max(stats['maxQueue'],extra['maxQueue'])
                    if category==0:
                        coverage['grant_blocked_R0_occupied_queue_nonempty']+=extra['grantBlockedR0Queue']
                        coverage['poll_callback_ties']+=sum(any(e[:2]==['wait',j] for e in es) and any(e[:2]==['callback',j] for e in es) for j in (0,1))
                        coverage['simultaneous_enqueue_ticks']+=int(out['enqEvents']==3)
                        coverage['ready_off_boundaries']+=int(t%model.p==0 and t%model.r==1)
                        coverage['WU_decrement_same_tick']+=int(out['WUaccepted']>0 and t%24==0)
                    if category==1:
                        coverage['data_WU_decrement_same_tick']+=int(out['WUaccepted']>0 and t%24==0)
                        coverage['data_WU_capture_same_tick']+=int(out['WUaccepted']>0 and out['grantOwner']>=0)
                        coverage['data_block_with_WU']+=int(out['WUaccepted']>0 and out['blockedOwner']>=0)
                    maxvals['tick']=max(maxvals['tick'],t)
                    for snap in model.latches:
                        maxvals['request_id']=max(maxvals['request_id'],snap[1])
                    maxvals['scheduled_poll']=max([maxvals['scheduled_poll']]+[x['poll'] or 0 for x in model.clients])
                    maxvals['counter']=max([maxvals['counter']]+model.count)
                case_rows.append(dict(category=category,pattern=pattern,case=ci,
                                      **{k:stats[k] for k in ['ticks','grants','emits','backpressure','cancels','expiries','WUs','maxQueue']},fault=0))
                if category:
                    for k in ['ticks','grants','emits','backpressure','cancels','expiries','WUs']:
                        aggregates['snapshot_'+k]+=stats[k]
                    aggregates['snapshot_runs']+=1
                else:
                    aggregates['control_ticks']+=stats['ticks']
                    aggregates['control_cases']+=1
                    aggregates['backpressure_cases']+=int(stats['backpressure']>0)
                    aggregates['queue_two_cases']+=int(stats['maxQueue']==2)
        eq(list(it),[],'no extra serialized ticks')
    eq(list(integer_csv(build/'CASE_CHECKS.csv')),case_rows,'every serialized case aggregate')
    eq(list(control_tokens),[],'no trailing control vector fields')
    return dict(aggregates),dict(coverage),dict(maxvals)

def audit_policy_csv(build, expected, records, traces):
    it=iter(integer_csv(build/'POLICY_CHECKS.csv'))
    stats=Counter()
    vector_tokens=iter(map(int,(build/'vectors'/'policies.txt').read_text().split()))
    eq(next(vector_tokens),len(expected),'serialized policy vector count')
    for want in expected:
        eq([next(vector_tokens) for _ in range(15)],list(want.values()),'every serialized policy vector field')
        row=next(it)
        eq(set(row),set(want)|{'actualFirstFail','actualFailOwner','actualExpiry','actualTicks','fault','captures','emissions','cancels'},'every policy CSV field recognized')
        for field,value in want.items():
            eq(row[field],value,f'policy {want["query"]} {field}')
        ci,h,j=want['case'],want['h'],want['line']
        rec,trace=records[ci],traces[ci]['rows']
        safe=bool(want['expectedPass'])
        eq(row['actualFirstFail'],-1 if safe else h,'observed first failure')
        eq(row['actualFailOwner'],-1 if safe else j,'first-failure ownership')
        eq(row['actualExpiry'],want['expectedExpiry'],'observed literal expiry')
        eq(row['actualTicks'],h+1,'complete target horizon')
        eq(row['fault'],0,'no RTL width/invariant fault')
        eq(row['captures'],count_events(trace,rec,'grant',h if safe else h-1),'policy captures')
        eq(row['emissions'],count_events(trace,rec,'emit',h if safe else h-1),'policy emissions')
        eq(row['cancels'],int(safe),'policy cancellation')
        stats['policy_queries']+=1
        stats['policy_positive_survivals' if safe else 'policy_negative_first_failures']+=1
        stats['policy_simulated_ticks']+=h+1
    eq(list(it),[],'no extra serialized policies')
    eq(list(vector_tokens),[],'no trailing policy vector fields')
    return dict(stats)

def audit_provenance(source, portable, replay):
    """Public-file bindings; external tools/binaries are deliberately not inputs.

    Semantic routines below are the unchanged separately authored checker.
    Saved mode audits historical execution records, never infers a fresh run.
    The optional runner passes an actual newly compiled/executed replay here.
    """
    root=source.parents[1]
    adaptations=load(root/'R04_PUBLIC_ADAPTATIONS.json')
    changed={x['path']:x for x in adaptations['changes']}
    excluded={x['path']:x for x in adaptations['omitted']}
    def original_binding(path, digest, size=None):
        rel=path.relative_to(root).as_posix()
        if not path.exists():
            need(rel in excluded,'only explicitly excluded executable may be absent')
            eq(excluded[rel]['sha256'],digest,'historical excluded binary hash')
            return
        if rel in changed:
            eq(changed[rel]['original_sha256'],digest,'original author metadata hash')
            eq(sha(path),changed[rel]['public_sha256'],'public adapted metadata hash')
        else:
            eq(sha(path),digest,'unchanged author file hash')
            if size is not None:eq(path.stat().st_size,size,'unchanged author file size')
    bindings=load(source/'REFERENCE_INPUTS.json')['inputs']
    for name,x in bindings.items():
        for path in (source/'reference-inputs'/name,portable/'reference-inputs'/name,root/'r03/hush-shared-controller'/name):
            eq(sha(path),x['sha256'],'public frozen reference binding')
            eq(path.stat().st_size,x['bytes'],'public reference length')
    original=load(source/'MANIFEST.json')
    for name,x in original['files'].items():original_binding(source/name,x['sha256'],x['bytes'])
    for name in ['receiver.v','driver.cpp','PROTOCOL.json','generate_vectors.py','replay_portable.py']:
        eq(sha(source/name),sha(portable/name),'portable source exact')
    build=load(source/'build-01/BUILD.json')
    for name,h in build['inputs'].items():
        eq(sha(source/name),h,'author source input')
        eq(sha(source/'build-01'/name),h,'author copied build input')
    for name,h in build['generated_sha256'].items():original_binding(source/'build-01'/name,h)
    replaydoc=load(replay/'PORTABLE_REPLAY.json')
    eq(replaydoc['status'],'EXECUTED_GENERATED_REFERENCE_RTL','recorded replay completion')
    eq([x['returncode'] for x in replaydoc['commands']],[0]*5,'recorded replay command completion')
    for name,h in replaydoc['inputs'].items():eq(sha(portable/name),h,'replay source binding')
    for name,h in replaydoc['outputs'].items():
        path=replay/name
        if path.is_relative_to(root):original_binding(path,h)
        else:eq(sha(path),h,'actual fresh output binding')
    synth=(replay/'synthesis.stdout.log').read_text(encoding='utf-8')
    for marker in ['Executing Verilog-2005 frontend','Executing PREP pass','Found and reported 0 problems.','Executing CXXRTL backend.','Yosys 0.70']:
        need(marker in synth,'recorded synthesis stage '+marker)
    need('#include "netlist.cpp"' in (portable/'driver.cpp').read_text(),'driver includes generated DUT')
    netlist=(replay/'netlist.cpp').read_text()
    need('p_receiver' in netlist and 'p_tick' in netlist,'generated DUT signals')
    same={}
    for name in ['netlist.cpp','CONTROL_TICKS.csv','DATA_TICKS.csv','CASE_CHECKS.csv','POLICY_CHECKS.csv','RTL_RESULTS.json']:
        eq(sha(replay/name),sha(source/'build-01'/name),'all saved/fresh semantic outputs exact')
        same[name]=sha(replay/name)
    for name in ['controls.txt','policies.txt']:eq(sha(replay/'vectors'/name),sha(source/'vectors-v2'/name),'regenerated vector identity')
    old_generator=(source/'failure-01-generator-path/generate_vectors.py').read_text(encoding='utf-8')
    current_generator=(source/'generate_vectors.py').read_text(encoding='utf-8')
    eq(old_generator.replace("default=HERE.parent/'hush-shared-controller'", "default=HERE.parents[1]/'r03-analysis/hush-shared-controller'"),current_generator,'initial path-only generator fix')
    need(not (source/'vectors-v1').exists() or not list((source/'vectors-v1').iterdir()),'first failed attempt has no replacement vectors')
    return dict(public_input_files=len(bindings),producer_manifest_files=len(original['files']),actual_external_tools_checked=0,
                external_tools_are_optional_and_not_bundled=True,identical_semantic_artifacts=same,
                initial_generator_failure_preserved=True,executable_identity_required=False,
                saved_mode_is_not_a_new_native_execution=(replay==source/'independent/fresh-replay-01'))


def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('--source',type=Path,default=SOURCE)
    ap.add_argument('--portable',type=Path,default=SOURCE)
    ap.add_argument('--replay',type=Path,default=SOURCE/'independent/fresh-replay-01')
    ap.add_argument('--out',type=Path,default=HERE/'INDEPENDENT_AUDIT.json')
    args=ap.parse_args()
    source,portable,replay=args.source.resolve(),args.portable.resolve(),args.replay.resolve()
    provenance=audit_provenance(source,portable,replay)
    ref=portable/'reference-inputs'
    records=load(ref/'RELATIONS.json')['records']
    traces=gz(ref/'TRACES.jsonl.gz')
    eq([r['case_id'] for r in records],[x['case_id'] for x in traces],'frozen case order')
    eq({(r['configuration']['p'],r['configuration']['b'],r['configuration']['r']) for r in records},
       {(p,b,r) for p in range(2,7) for b in range(p) for r in (3,5)},'all 40 declared configurations')
    for rec,tr in zip(records,traces):
        eq(len(tr['rows']),rec['validation_trace_ticks'],'complete frozen trace length')
        eq([x[0] for x in tr['rows']],list(range(rec['validation_trace_ticks'])),'contiguous frozen ticks')
        eq(rec['validation_trace_ticks'],rec['repeat_tick']+2*rec['translation'],'detect plus two cycles')
        for line in rec['lines']:
            eq(line['J'],max(c-s for s,c,h in line['cycle']),'tight recurrent J')
            eq(line['A'],max(h-c for s,c,h in line['cycle']),'tight recurrent A')
            eq(line['C0'],[c for s,c,h in line['cycle']],'actual per-line completion residues')
    relation_counts=audit_relations(records,traces)
    expected,phase_counts,maxpolicy,per_case=audit_phases(ref,records)
    tick_counts,coverage,widths=audit_ticks(replay,records,traces)
    policy_counts=audit_policy_csv(replay,expected,records,traces)
    old_validation=load(ref/'INDEPENDENT_VALIDATION.json')['independent_counts']
    for key in ['posthoc_supported_queries','posthoc_supported_full_positive','posthoc_supported_full_unknown','posthoc_supported_service_only']:
        eq(phase_counts[key],old_validation[key],'independently reconstructed prior adverse/outcome count')
    vm=load(replay/'vectors'/'VECTORS.json')
    eq(vm['case_order'],[r['case_id'] for r in records],'serialized vector case order')
    eq(vm['control_ticks'],tick_counts['control_ticks'],'serialized vector ticks')
    eq(vm['maximum_policy_target_tick'],maxpolicy['h'],'serialized vector target bound')
    eq(vm['policies'],len(expected),'serialized vector policies')
    eq(vm['generator_sha256'],sha(portable/'generate_vectors.py'),'serialized generator hash')
    for name,value in vm['files'].items(): eq(sha(replay/'vectors'/name),value,'serialized vector file binding')
    for name,value in vm['reference_sha256'].items(): eq(sha(ref/name),value,'serialized frozen reference binding')
    summary=load(replay/'RTL_RESULTS.json')
    mapped=dict(control_cases=tick_counts['control_cases'],control_ticks=tick_counts['control_ticks'],
                backpressure_cases=tick_counts['backpressure_cases'],queue_two_cases=tick_counts['queue_two_cases'],
                snapshot_runs=tick_counts['snapshot_runs'],snapshot_ticks=tick_counts['snapshot_ticks'],
                snapshot_captures=tick_counts['snapshot_grants'],snapshot_emissions=tick_counts['snapshot_emits'],
                snapshot_timer_cancels=tick_counts['snapshot_cancels'],snapshot_backpressure_ticks=tick_counts['snapshot_backpressure'])
    mapped.update(policy_counts)
    for field,value in mapped.items(): eq(summary[field],value,'serialized RTL_RESULTS aggregate '+field)
    eq(summary['mismatches'],0,'serialized mismatch aggregate')
    eq(summary['status'],'PASS_EXECUTED_YOSYS_GENERATED_REFERENCE_RTL','serialized result status')
    eq(coverage['grant_blocked_R0_occupied_queue_nonempty'],0,'unexercised grant-block state remains zero')
    need(maxpolicy['h']<65000 and widths['scheduled_poll']<65515 and widths['request_id']<65535,'admitted finite widths')
    result=dict(status='PASS_INDEPENDENT_AUTHOR_SIDE_NEW_REFERENCE_RTL_GATE',
                scope='New constructed RTL, actual generated CXXRTL; not native HUSH/gem5, universal WU exhaustion, coherent memory, hardware throughput or PPA.',
                checker_sha256=sha(Path(__file__)),provenance=provenance,
                counts=mapped,phase_reconstruction=phase_counts,per_case_phase_counts=per_case,
                reextracted_relation_counts=relation_counts,
                no_service_gain_cases=[k for k,v in per_case.items() if not v['service_extra_over_completion']],
                exercised_coverage=coverage,width_observations=dict(control_and_data=widths,policy=maxpolicy),
                all_serialized_case_policy_and_tick_fields_checked=True,
                fresh_replay_root='fresh output or bundled saved evidence',source_root='r04-analysis/hush-rtl',
                limits=['No arbitrary WU-word exhaustion; positives exercise the declared minimizing one-WU word only.',
                        'Only three fixed byte patterns with K=5/P=24/phi=0, valid-only WUs after initial captures.',
                        'R0-occupied with a queued head at grant is unexercised and receives no coverage credit.',
                        'FIFO occupancy two and actual sink-ready backpressure are separately counted.',
                        'Fourteen cases have no response backpressure; all forty cases remain included.',
                        'Invalid configurations, overflow, epoch changes and revocation recovery are untested.',
                        'Synthesis structure and logical tick counts supply no area, timing, energy or hardware-rate claim.'])
    args.out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(status=result['status'],counts=mapped,phase_counts=phase_counts,coverage=coverage),indent=2))

if __name__=='__main__':
    main()
