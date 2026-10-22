"""Strict lossless reader for actual per-tick netlist delta output."""
from pathlib import Path
import argparse,csv,gzip,json,struct
STATE=['tick','cp','rp','fp','pp','nextid','qlen','qowners',*[f'qid{i}' for i in range(8)],'R0v','R0owner','R0id','R0byte','R1v','R1owner','R1id','R1byte','outstanding','valid','enabled','bytes',*[f'count{i}' for i in range(4)],'failed','fault']
EVENT=['evwu','evexpire','evcancel','evenq','enqowner','enqid','enqowner2','enqid2','evattempt','attemptowner','attemptid','evgrant','grantowner','grantid','grantbyte','evemit','emitowner','emitid','emitbyte','evtransfer','transferowner','transferid','transferbyte','evcallback','callbackowner','callbackid','evblock','blockowner','blockid','failtick','failowner','failid']
PAYLOAD=STATE[5:]+EVENT
def readvar(f):
 value=0
 for shift in [0,7,14,21,28]:
  b=f.read(1)
  if not b:raise ValueError('truncated varint')
  b=b[0];value|=(b&127)<<shift
  if not b&128:
   if value>0xffffffff or shift and b==0:raise ValueError('noncanonical/out-of-range varint')
   return value
 raise ValueError('overlong varint')
def openbin(p):return gzip.open(p,'rb') if str(p).endswith('.gz') else open(p,'rb')
def query_ticks(path,configs,policies):
 with openbin(path) as f:
  assert f.read(8)==b'HCR5DT01'
  for q,p in enumerate(policies):
   h=f.read(8);assert len(h)==8
   qi,n=struct.unpack('<II',h);assert qi==q==p['query'] and n==p['ticks']==p['h']-p['start']+1
   c=configs[p['case']];prev=[0]*len(PAYLOAD)
   for i in range(n):
    b=f.read(1);assert b
    nc=b[0];assert nc<=len(PAYLOAD);last=-1
    for _ in range(nc):
     b=f.read(1);assert b;k=b[0];assert last<k<len(prev);last=k;new=readvar(f);assert prev[k]!=new;prev[k]=new
    t=p['start']+i;after={'tick':t+1,'cp':(t+1)%c['p'],'rp':(t+1)%c['r'],'fp':(t+1)%c['F'],'pp':(t+1)%p['P']};after.update(zip(PAYLOAD,prev))
    yield q,t,after
  assert f.read(1)==b''
def main():
 ap=argparse.ArgumentParser();ap.add_argument('directory',type=Path);ap.add_argument('--relations',type=Path,required=True);ap.add_argument('--csv',type=Path);a=ap.parse_args();configs={r['case']:r['configuration'] for r in json.loads(a.relations.read_text())['records']}
 with (a.directory/'POLICY_RESULTS.csv').open(newline='') as f:policies=[{k:int(v) for k,v in r.items()} for r in csv.DictReader(f)]
 f=a.csv.open('w',newline='') if a.csv else None;wr=csv.writer(f) if f else None
 if wr:wr.writerow(['query','t']+STATE+EVENT)
 n=0
 path=a.directory/'POLICY_TICKS.delta';path=path if path.exists() else path.with_suffix('.delta.gz')
 for q,t,row in query_ticks(path,configs,policies):
  n+=1
  if wr:wr.writerow([q,t]+[row[k] for k in STATE+EVENT])
 if f:f.close()
 print(json.dumps({'strictly_decoded_ticks':n,'queries':len(policies),'format':'HCR5DT01'}))
if __name__=='__main__':main()
