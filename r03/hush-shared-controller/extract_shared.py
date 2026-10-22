"""Prospectively declared bounded two-line producer; no counter is in control key."""
from pathlib import Path
from collections import Counter
import gzip, hashlib, json, math, sys

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[3]
OLD=ROOT/'outputs/iscas-review-loop-20261021/editor-analysis'
sys.path.insert(0,str(OLD))
from r23_canonical import canonical
from r26_remod import profile, project

def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def digest(v): return hashlib.sha256(json.dumps(v,separators=(',',':')).encode()).hexdigest()
def cases():
    return [dict(case_id=f'p{p}_b{b}_r{r}',p=p,q=[2*p+1,3*p+1],b=b,r=r)
            for p in (2,3,4,5,6) for b in range(p) for r in (3,5)]

class Producer:
    def __init__(self,cfg):
        self.cfg=cfg; self.t=0; self.poll=[0,cfg['b']]
        self.pending=[False,False]; self.wait=[False,False]
        self.seq=[0,0]; self.queue=[]; self.R0=None; self.R1=None
        self.services={}; self.receipts={}; self.grants=[]; self.emits=[]
        self.stats=Counter()
    def key(self):
        return (self.t%math.lcm(self.cfg['p'],self.cfg['r']),
                tuple(None if v is None else v-self.t for v in self.poll),
                tuple(self.pending),tuple(self.wait),tuple(x[0] for x in self.queue),
                None if self.R0 is None else self.R0[0],None if self.R1 is None else self.R1[0])
    def invariant(self):
        assert len(self.queue)<=2
        locations=self.queue+[x for x in (self.R0,self.R1) if x is not None]
        for j in (0,1):
            assert sum(x[0]==j for x in locations)==int(self.pending[j])
            assert not self.wait[j] or (self.pending[j] and self.poll[j] is None)
            assert self.poll[j] is None or self.poll[j]>=self.t
        assert len(locations)<=2 and len(set(locations))==len(locations)
    def step(self):
        self.invariant(); t=self.t; p=self.cfg['p']; r=self.cfg['r']
        before=self.key(); events=[]; entry_R0=self.R0
        for j in (0,1):
            if self.poll[j]==t:
                if self.pending[j]:
                    self.wait[j]=True; self.poll[j]=None
                    events.append(['wait',j]); self.stats['poll_while_pending']+=1
                else:
                    self.seq[j]+=1; token=(j,self.seq[j])
                    self.pending[j]=True; self.queue.append(token)
                    self.poll[j]=t+self.cfg['q'][j]
                    events.append(['enqueue',*token]); self.stats['enqueues']+=1
        self.stats['max_queue']=max(self.stats['max_queue'],len(self.queue))
        self.stats['queue_two_ticks']+=len(self.queue)==2
        emitted=None
        if t%p==0:
            self.stats['boundaries']+=1
            if entry_R0 is None and self.queue:
                assert self.R0 is None
                self.R0=self.queue.pop(0)
                self.services[self.R0]=t; self.grants.append((t,*self.R0))
                events.append(['grant',*self.R0]); self.stats['grants']+=1
            elif entry_R0 is not None and self.queue:
                self.stats['grant_blocked_R0_with_queue']+=1
            if self.R1 is not None:
                if t%r!=1:
                    emitted=self.R1; self.R1=None
                    self.receipts[emitted]=t; self.emits.append((t,*emitted))
                    events.append(['emit',*emitted]); self.stats['emits']+=1
                else:
                    self.stats['response_backpressure_stalls']+=1
                    events.append(['backpressure',*self.R1])
            if self.R0 is not None and self.R1 is None:
                self.R1=self.R0; self.R0=None
                events.append(['transfer',*self.R1]); self.stats['transfers']+=1
            if emitted is not None:
                j=emitted[0]; assert self.pending[j]
                self.pending[j]=False
                if self.wait[j]:
                    self.wait[j]=False; self.poll[j]=t+self.cfg['q'][j]
                events.append(['callback',*emitted])
        self.t+=1; self.invariant()
        return [t,before,events]

def extract(cfg):
    sim=Producer(cfg); seen={}; trace=[]; cap=1000000
    while sim.t<cap:
        key=sim.key()
        if key in seen:
            a,b=seen[key],sim.t; break
        seen[key]=sim.t; trace.append(sim.step())
    else:
        return {'case_id':cfg['case_id'],'configuration':cfg,'status':'CAP_FAILURE','ticks':sim.t},trace
    d=b-a; assert d>0 and d%math.lcm(cfg['p'],cfg['r'])==0
    for _ in range(2*d): trace.append(sim.step())
    # Grant and response schedules themselves, not just states, must repeat.
    for events in (sim.grants,sim.emits):
        one=[(t-a,j) for t,j,n in events if a<=t<b]
        two=[(t-b,j) for t,j,n in events if b<=t<b+d]
        three=[(t-b-d,j) for t,j,n in events if b+d<=t<b+2*d]
        assert one==two==three
    lines=[]
    for j in (0,1):
        grants=[(t,(k,n)) for t,k,n in sim.grants if k==j]
        assert grants
        triples=[]
        for (s,token),(h,_) in zip(grants,grants[1:]):
            if s>=b: break
            c=sim.receipts[token]; assert s<c<h
            triples.append([s,c,h])
        pre=[row for row in triples if row[0]<a]
        cycle=[row for row in triples if a<=row[0]<b]
        assert cycle and len(triples)==len(pre)+len(cycle)
        master=canonical(profile([(s,h-s) for s,c,h in cycle],d),d)
        raw=profile([(s,h-s) for s,c,h in cycle],d)
        g=d//math.gcd(d,3); stored=project(master,g)
        prospect=1
        for P in range(1,4*cfg['p']+1): prospect=math.lcm(prospect,math.gcd(P,d))
        lines.append({'line':j,'tag':[64,128][j],'initial_service_cutpoint':grants[0][0],
                      'prefix':pre,'cycle':cycle,'raw_master':raw,'master':master,
                      'posthoc_g':g,'posthoc_pairs':stored,'prospective_g':prospect,
                      'prospective_pairs':project(master,prospect),
                      'J':max(c-s for s,c,h in cycle),'A':max(h-c for s,c,h in cycle),
                      'C0':sorted({c for s,c,h in cycle})})
    out={'case_id':cfg['case_id'],'configuration':cfg,'status':'EXACT_CYCLE',
         'cycle_entry_tick':a,'repeat_tick':b,'translation':d,'unique_control_keys':len(seen),
         'extraction_ticks_to_detect':b,'validation_trace_ticks':len(trace),'trace_sha256':digest(trace),
         'stats_over_detection_plus_two_cycles':dict(sim.stats),'lines':lines}
    return out,trace

def positive(base,P,K): return base is None or base+(K-1)*P>0
def main():
    assert not (HERE/'RELATIONS.json').exists()
    assert json.loads((HERE/'PROTOCOL.json').read_text())['status'].startswith('prospective')
    records=[]; tracepath=HERE/'TRACES.jsonl.gz'
    with gzip.open(tracepath,'wt',encoding='utf-8',newline='\n',compresslevel=9) as out:
        for cfg in cases():
            rec,trace=extract(cfg); records.append(rec)
            out.write(json.dumps({'case_id':cfg['case_id'],'rows':trace},separators=(',',':'))+'\n')
            print(cfg['case_id'],rec['status'],rec.get('cycle_entry_tick'),rec.get('translation'),flush=True)
    result={'status':'EXTRACTED_ALL_PREDECLARED_CASES','protocol_sha256':sha(HERE/'PROTOCOL.json'),
            'script_sha256':sha(Path(__file__)),'trace_file_sha256':sha(tracepath),'records':records}
    (HERE/'RELATIONS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'cases':len(records),'cycle_cases':sum(r['status']=='EXACT_CYCLE' for r in records),
                      'cap_failures':sum(r['status']!='EXACT_CYCLE' for r in records),
                      'max_detection_ticks':max(r.get('repeat_tick',0) for r in records)}),flush=True)
if __name__=='__main__': main()
