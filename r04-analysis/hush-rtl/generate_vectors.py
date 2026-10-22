"""Serialize frozen R03 expectations; imports no producer/native implementation."""
from pathlib import Path
import argparse,gzip,hashlib,json,math
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def readgz(p):
 with gzip.open(p,'rt',encoding='utf-8') as f:return [json.loads(s) for s in f]
def fields(row):
 t,key,events=row
 phase,polls,pending,wait,queue,r0,r1=key
 v=[t,phase,*[-1 if x is None else x for x in polls],*map(int,pending),*map(int,wait),len(queue),*(queue+[-1,-1])[:2],-1 if r0 is None else r0,-1 if r1 is None else r1]
 wm=em=0;ids=[0,0];g=e=b=x=c=[-1,0]
 for ev in events:
  typ,j,*serial=ev
  if typ=='wait':wm|=1<<j
  elif typ=='enqueue':em|=1<<j;ids[j]=serial[0]
  elif typ=='grant':g=[j,serial[0]]
  elif typ=='emit':e=[j,serial[0]]
  elif typ=='backpressure':b=[j,serial[0]]
  elif typ=='transfer':x=[j,serial[0]]
  elif typ=='callback':c=[j,serial[0]]
 return v+[wm,em,*ids,*g,*e,*b,*x,*c]
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--reference',type=Path,default=HERE.parents[1]/'r03-analysis/hush-shared-controller');ap.add_argument('--out',type=Path,required=True);a=ap.parse_args();a.out.mkdir(parents=True,exist_ok=False)
 paths={n:a.reference/n for n in ['PROTOCOL.json','RELATIONS.json','TRACES.jsonl.gz','ALL_PHASE_BASES.jsonl.gz','ALL_NEGATIVE_FIRST_FAILURES.jsonl.gz','INDEPENDENT_VALIDATION.json']}
 rec=json.loads(paths['RELATIONS.json'].read_text())['records'];byid={r['case_id']:r for r in rec};traces=readgz(paths['TRACES.jsonl.gz']);assert len(rec)==len(traces)==40
 for r in rec:assert r['status']=='EXACT_CYCLE'
 controls=a.out/'controls.txt'
 with controls.open('w',encoding='utf-8',newline='\n') as f:
  f.write('40\n')
  for index,(r,tr) in enumerate(zip(rec,traces)):
   assert r['case_id']==tr['case_id'];cfg=r['configuration'];assert len(tr['rows'])==r['validation_trace_ticks']
   f.write(' '.join(map(str,[index,cfg['p'],cfg['b'],cfg['r'],len(tr['rows']),*[l['initial_service_cutpoint'] for l in r['lines']]]))+'\n')
   for row in tr['rows']:f.write(' '.join(map(str,fields(row)))+'\n')
 negatives=readgz(paths['ALL_NEGATIVE_FIRST_FAILURES.jsonl.gz'])[1:];negs={tuple(row[:5]):row for row in negatives};assert len(negs)==19613
 policy=[]
 for x in readgz(paths['ALL_PHASE_BASES.jsonl.gz'])[1:]:
  r=byid[x['case_id']];idx=rec.index(r);cfg=r['configuration'];P=x['P']
  for row in x['rows']:
   phi,base,_,_,_,j,s,c,h,_,mask,_=row
   for K in range(1,6):
    accepted=int(bool(mask&(1<<(K-1))));expiry=-1
    if not accepted:
     nr=negs[(x['case_id'],P,phi,K,j)];assert nr[5:9]==[s,c,h,s+1] and nr[10]==h;expiry=nr[9]
    assert h<65000 and s+1>r['lines'][j]['initial_service_cutpoint']
    policy.append([len(policy),idx,cfg['p'],cfg['b'],cfg['r'],K,P,phi,j,s,c,h,s+1,accepted,expiry])
 assert len(policy)==37000 and sum(v[-2] for v in policy)==17387
 with (a.out/'policies.txt').open('w',encoding='utf-8',newline='\n') as f:
  f.write(str(len(policy))+'\n')
  for v in policy:f.write(' '.join(map(str,v))+'\n')
 meta={'kind':'frozen_serialized_reference_vectors','reference_sha256':{n:sha(p) for n,p in paths.items()},'case_order':[r['case_id'] for r in rec],'control_ticks':sum(len(t['rows']) for t in traces),'policies':len(policy),'positive':17387,'negative':19613,'maximum_policy_target_tick':max(v[11] for v in policy),'snapshot_runs':120,'snapshot_patterns':['0','255','(t*17+owner*73) mod 256'],'snapshot_K_P_phi':[5,24,0],'width_contract':{'tick_bits':16,'id_bits':16,'counter_bits':3,'data_bits':8,'maximum_simulation_tick_exclusive':65001,'configuration_stable_per_run':True},'files':{n:sha(a.out/n) for n in ['controls.txt','policies.txt']},'generator_sha256':sha(Path(__file__))}
 (a.out/'VECTORS.json').write_text(json.dumps(meta,indent=2)+'\n',encoding='utf-8');print(json.dumps(meta,indent=2))
if __name__=='__main__':main()
