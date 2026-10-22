"""Exact within-tick ownership peaks, retaining original after-tick counters."""
from pathlib import Path
from collections import defaultdict
import argparse,csv,json,struct
from decode_trace import PAYLOAD,readvar
HERE=Path(__file__).resolve().parent
def peak(outstanding,callback,owner):return [((outstanding>>(4*j))&15)+int(callback and owner==j) for j in range(4)]
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--control',default='build-04');ap.add_argument('--policy',default='build-05-policy');a=ap.parse_args()
 aggregates={};data=[]
 for name in ['CONTROL_TICKS.csv','DATA_TICKS.csv']:
  grouped={}
  with (HERE/a.control/name).open(newline='') as f:
   for raw in csv.DictReader(f):
    r={k:int(v) for k,v in raw.items()};key=(r['case'],r['mode']);s=grouped.setdefault(key,[0,0,0,0,0,0]);line=peak(r['after_outstanding'],r['evcallback'],r['callbackowner']);s[0]=max(s[0],r['after_qlen']+r['evgrant']);s[1]=max(s[1],sum(line))
    for j in range(4):s[2+j]=max(s[2+j],line[j])
  for (ci,mode),s in sorted(grouped.items()):data.append([name,ci,mode,*s])
 with (HERE/'PEAK_CONTROL_DATA_COUNTERS.csv').open('w',newline='') as f:
  w=csv.writer(f);w.writerow(['file','case','mode','peakFIFO','peakGlobal','peakLine0','peakLine1','peakLine2','peakLine3']);w.writerows(data)
 with (HERE/a.policy/'POLICY_RESULTS.csv').open(newline='') as f:pol=[{k:int(v) for k,v in r.items()} for r in csv.DictReader(f)]
 with (HERE/a.policy/'POLICY_TICKS.delta').open('rb') as f,(HERE/'PEAK_POLICY_COUNTERS.csv').open('w',newline='') as out:
  assert f.read(8)==b'HCR5DT01';w=csv.writer(out);w.writerow(['query','case','peakFIFO','peakGlobal','peakLine0','peakLine1','peakLine2','peakLine3'])
  for qi,p in enumerate(pol):
   q,n=struct.unpack('<II',f.read(8));assert qi==q and n==p['ticks'];prev=[0]*len(PAYLOAD);s=[0]*6
   for z in range(n):
    nb=f.read(1);assert nb;nc=nb[0];last=-1
    for _ in range(nc):
     b=f.read(1);assert b;k=b[0];assert last<k<len(prev);last=k;v=readvar(f);assert prev[k]!=v;prev[k]=v
    if nc:
     # Enqueues precede both grant and callback. Grant removes FIFO only;
     # callback alone retires outstanding ownership, and callback is last.
     line=peak(prev[19],prev[52],prev[53]);s[0]=max(s[0],prev[1]+prev[40]);s[1]=max(s[1],sum(line))
     for j in range(4):s[2+j]=max(s[2+j],line[j])
   assert s[0]<=8 and s[1]<=10 and s[0]>=p['maxFIFO'] and s[1]>=p['maxGlobal']
   assert all(s[2+j]>=p['maxLine'+str(j)] for j in range(4))
   w.writerow([qi,p['case'],*s]);ag=aggregates.setdefault(p['case'],[0]*6)
   for j in range(6):ag[j]=max(ag[j],s[j])
  assert f.read(1)==b''
 (HERE/'PEAK_COUNTERS.json').write_text(json.dumps({'status':'EXACT_WITHIN_TICK_PEAKS_DERIVED_FROM_ACTUAL_RAW_TRANSCRIPTS','original_maxima_are':'after-tick samples; retained unchanged','formula':'FIFO peak=after qlen+successful grant; line outstanding peak=after line count+callback token for that owner. Enqueue precedes both; callback is last.','policy_maxima_by_case':aggregates,'fields':['peakFIFO','peakGlobal','peakLine0','peakLine1','peakLine2','peakLine3'],'scope':'Producer derived, not independent checker.'},indent=2)+'\n',encoding='utf-8');print(json.dumps(aggregates,indent=2))
if __name__=='__main__':main()
