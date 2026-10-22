"""Independent dict/state-machine and decrement-event validation.

Does not import extraction, canonicalization, projection or expiry code.
"""
from pathlib import Path
from collections import Counter
import gzip,hashlib,json,math
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def digest(x):return hashlib.sha256(json.dumps(x,separators=(',',':')).encode()).hexdigest()

class Oracle:
  def __init__(self,c):
    self.c=c;self.time=0
    self.source={j:dict(next=[0,c['b']][j],busy=False,waiting=False,serial=0) for j in (0,1)}
    self.fifo=[];self.stage={'capture':None,'response':None};self.serv={};self.recv={}
    self.attempts=[]
  def normalized(self):
    s=self.source;t=self.time
    return [t%math.lcm(self.c['p'],self.c['r']),
            [None if s[j]['next'] is None else s[j]['next']-t for j in (0,1)],
            [s[j]['busy'] for j in (0,1)],[s[j]['waiting'] for j in (0,1)],
            [x[0] for x in self.fifo],
            None if self.stage['capture'] is None else self.stage['capture'][0],
            None if self.stage['response'] is None else self.stage['response'][0]]
  def tick(self):
    t=self.time;before=self.normalized();actions=[]
    entrance_free=self.stage['capture'] is None
    for j in range(2):
      s=self.source[j]
      if s['next']!=t:continue
      if s['busy']:
        s['waiting']=True;s['next']=None;actions.append(['wait',j])
      else:
        s['serial']+=1;s['busy']=True;s['next']=t+self.c['q'][j]
        request=(j,s['serial']);self.fifo.append(request);actions.append(['enqueue',*request])
    outgoing=None
    if t%self.c['p']==0:
      if entrance_free and len(self.fifo):
        tok=self.fifo[0];self.fifo=self.fifo[1:]
        self.stage['capture']=tok;self.serv[tok]=t
        self.attempts.append((t,tok[0],tok[1]));actions.append(['grant',*tok])
      old=self.stage['response']
      if old is not None:
        if t%self.c['r']==1: actions.append(['backpressure',*old])
        else:
          outgoing=old;self.stage['response']=None;self.recv[old]=t
          actions.append(['emit',*old])
      if self.stage['response'] is None and self.stage['capture'] is not None:
        self.stage['response']=self.stage['capture'];self.stage['capture']=None
        actions.append(['transfer',*self.stage['response']])
      if outgoing is not None:
        s=self.source[outgoing[0]];assert s['busy'];s['busy']=False
        if s['waiting']:
          s['waiting']=False;s['next']=t+self.c['q'][outgoing[0]]
        actions.append(['callback',*outgoing])
    locations=self.fifo+[v for v in self.stage.values() if v is not None]
    assert len(self.fifo)<=2 and len(locations)<=2
    for j in (0,1):assert sum(x[0]==j for x in locations)==self.source[j]['busy']
    self.time+=1
    return [t,before,actions]

def decrements(s,h,P,phi):
  # Count actual periodic decrement ticks in the half-open/closed interval.
  return (h-phi)//P-(s-phi)//P

def main():
  assert not (HERE/'INDEPENDENT_VALIDATION.json').exists()
  rel=json.loads((HERE/'RELATIONS.json').read_text())
  rows=json.loads((HERE/'POLICY_RESULTS.json').read_text())
  byid={r['case_id']:r for r in rel['records']};fulltraces={};checks=Counter()
  with gzip.open(HERE/'TRACES.jsonl.gz','rt',encoding='utf-8') as f:
    for line in f:
      x=json.loads(line);rec=byid[x['case_id']];sim=Oracle(rec['configuration']);new=[]
      keys={};first=None
      for expected in x['rows']:
        key=json.dumps(sim.normalized(),separators=(',',':'))
        if key in keys and first is None:first=(keys[key],sim.time)
        keys.setdefault(key,sim.time)
        observed=sim.tick();assert observed==expected,(x['case_id'],sim.time)
        new.append(observed);checks['independent_control_tick_checks']+=1
      assert first==(rec['cycle_entry_tick'],rec['repeat_tick'])
      assert digest(new)==rec['trace_sha256'];checks['independent_trace_sha_checks']+=1
      # Derive all retained relations from independent request-token observations.
      for source in (0,1):
        found=[];grants=sorted((s,tok) for tok,s in sim.serv.items() if tok[0]==source)
        for (s,tok),(h,_) in zip(grants,grants[1:]):
          if s>=rec['repeat_tick']:break
          found.append([s,sim.recv[tok],h])
        line=rec['lines'][source]
        assert [v for v in found if v[0]<rec['cycle_entry_tick']]==line['prefix']
        assert [v for v in found if v[0]>=rec['cycle_entry_tick']]==line['cycle']
        checks['independent_line_relation_checks']+=1
      fulltraces[x['case_id']]=(sim,new)
  totals=Counter();casecounts={};negative=[]
  with gzip.open(HERE/'ALL_PHASE_BASES.jsonl.gz','rt',encoding='utf-8') as f:
    header=json.loads(next(f))
    for entry in f:
      x=json.loads(entry);rec=byid[x['case_id']];P=x['P'];d=rec['translation'];m=math.gcd(P,d)
      for row in x['rows']:
        phi,full,comp,pref,recbase,j,s,c,h,supported,me,mc=row
        allreal=[];virtual=[]
        for line in rec['lines']:
          allreal += line['prefix']
          for service,emission,successor in line['cycle']:
            for n in range(P//m): allreal.append([service+n*d,emission+n*d,successor+n*d])
          # Independent virtual interval interpretation of the (C,J,A) bound.
          for completion in line['C0']:
            for n in range(P//m):
              centre=completion+n*d
              virtual.append([centre-line['J'],centre,centre+line['A']])
          virtual+=line['prefix']
        nmax=max(decrements(a,z,P,phi) for a,b,z in allreal)
        ncomp=max(decrements(a,z,P,phi) for a,b,z in virtual)
        cmask=sum(1<<(K-1) for K in range(1,6) if K>ncomp)
        emask=sum(1<<(K-1) for K in range(1,6) if K>nmax)
        assert emask==me and cmask==mc
        assert decrements(s,h,P,phi)==nmax
        assert [s,c,h] in rec['lines'][j]['prefix'] or any(
            [s-n*d,c-n*d,h-n*d] in rec['lines'][j]['cycle'] for n in range(P//m))
        local=Counter(policy_queries=5,full_service_positive=me.bit_count(),
          full_service_unknown=5-me.bit_count(),full_completion_positive=mc.bit_count(),
          full_service_only=(me&~mc).bit_count(),posthoc_supported_queries=5 if supported else 0,
          posthoc_unsupported_queries=0 if supported else 5,
          posthoc_supported_full_positive=me.bit_count() if supported else 0,
          posthoc_supported_full_unknown=5-me.bit_count() if supported else 0,
          posthoc_supported_service_only=(me&~mc).bit_count() if supported else 0)
        totals.update(local);casecounts.setdefault(x['case_id'],Counter()).update(local)
        checks['independent_phase_admission_checks']+=1
        # Replay the independent controller through the actual counterexample.
        # First-failure induction licenses using its no-failure schedule until
        # the first failing grant. Every negative K is independently checked.
        sim,trace=fulltraces[x['case_id']]
        while sim.time<=h:trace.append(sim.tick())
        target_events=[v for v in sim.attempts if v[1]==j and s<=v[0]<=h]
        assert [v[0] for v in target_events]==[s,h]
        for K in range(1,6):
          valid=True;enabled=False;count=0;firstfail=None;expire=None
          for tick in range(s,h+1):
            if tick==s+1:
              assert valid;count=K;enabled=True
            if tick%P==phi and enabled:
              count-=1
              if count==0:valid=False;enabled=False;expire=tick
            # Grant is after decrement; successful service cancels the counter.
            if tick==s or tick==h:
              if not valid:firstfail=tick;break
              enabled=False
          assert (firstfail is None)==bool(me&(1<<(K-1)))
          if firstfail is not None:
            assert firstfail==h and expire is not None and expire<=h
            negative.append([x['case_id'],P,phi,K,j,s,c,h,s+1,expire,h])
            checks['actual_first_failed_grant_counterexamples']+=1
          else:checks['actual_minimum_edge_one_WU_survivals']+=1
  for k,v in totals.items():assert rows['counts'][k]==v,(k,rows['counts'][k],v)
  for rec in rows['records']:
    for k,v in casecounts[rec['case_id']].items():assert rec['counts'][k]==v
  negpath=HERE/'ALL_NEGATIVE_FIRST_FAILURES.jsonl.gz'
  with gzip.open(negpath,'wt',encoding='utf-8',newline='\n',compresslevel=9) as f:
    f.write(json.dumps({'schema':'[case_id,P,phi,K,line,previous_successful_service_s,matching_emission_c,first_failed_grant_h,WU_tick,expiry_tick,first_failed_grant_tick]; all earlier WUs absent, other line has no WUs.'})+'\n')
    for item in negative:f.write(json.dumps(item,separators=(',',':'))+'\n')
  result={'status':'PASS_INDEPENDENT_CONTROLLER_RELATIONS_ALL_POLICY_ADMISSIONS_AND_EVERY_NEGATIVE_FIRST_FAILURE',
    'script_sha256':sha(Path(__file__)),'protocol_sha256':sha(HERE/'PROTOCOL.json'),
    'relations_sha256':sha(HERE/'RELATIONS.json'),'policy_results_sha256':sha(HERE/'POLICY_RESULTS.json'),
    'checks':dict(checks),'independent_counts':dict(totals),
    'negative_counterexamples_sha256':sha(negpath),
    'scope':'Independent dict controller exactly matches every recorded tick and relation; all 37000 policy statuses and 19613 sharp one-WU negative executions. Positive arbitrary-WU completeness is the monotone-rearm/first-failure argument in ARGUMENT.md, not inferred from these one-WU tests.'}
  (HERE/'INDEPENDENT_VALIDATION.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
  print(json.dumps(result,indent=2),flush=True)
if __name__=='__main__':main()
