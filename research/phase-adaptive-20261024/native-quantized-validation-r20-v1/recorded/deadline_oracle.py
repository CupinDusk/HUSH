"""Independent tick-sequence oracle for sanitized native receiver traces.

Input JSON has cases with P, phi, clock_period_ticks and native event strings.
The oracle enumerates successive global ticks and decrements the captured K;
it does not use the implementation's modulo deadline expression. It checks
ARM timestamps and the observed EXPIRE generation/deadline relation. This is
trace validation, not a proof of the full native cache or an RTL equivalence.
"""
import argparse,json,re,hashlib
from pathlib import Path
MAX=(1<<64)-1
def counter_deadline(received,k,p,phi):
 if k==255:return MAX
 assert 1<=k<=254 and p>0 and 0<=phi<p
 tick=phi
 if tick<received:
  # Skip full periods without calculating the final expiry deadline.
  tick+=((received-tick)//p)*p
 while tick<received:tick+=p
 count=k
 while True:
  count-=1
  if count==0:return tick
  tick+=p
def check_case(c):
 p=c['P']*c['clock_period_ticks'];phi=c['phi']*c['clock_period_ticks'];latest={};arms=expires=captures=holds=0;errors=[];nonedges=0
 for line in c['events']:
  kind=line.split()[0];fields=dict(re.findall(r'(\w+)=([^\s]+)',line));cache=fields.get('cache','')
  if kind=='HUSH_Q_ARM':
   arms+=1;r=int(fields['tick']);k=int(fields['K']);deadline=int(fields['deadline']);gen=int(fields['gen']);addr=int(fields['addr'],0)
   nonedges+=bool(r%c['clock_period_ticks'])
   expected=counter_deadline(r,k,p,phi)
   # A sub-cycle arrival is stamped at its next receiver edge. Since P and
   # phi are whole receiver cycles, both tick sequences must agree exactly.
   edge=(r+c['clock_period_ticks']-1)//c['clock_period_ticks']
   edge_expected=MAX if k==255 else counter_deadline(edge,k,c['P'],c['phi'])*c['clock_period_ticks']
   if deadline!=expected or deadline!=edge_expected:errors.append({'line':line,'expected':expected,'integer_receiver_edge_expected':edge_expected})
   latest[(cache,addr)]=(gen,deadline)
  elif kind=='HUSH_Q_EXPIRE':
   expires+=1;key=(cache,int(fields['addr'],0));got=(int(fields['gen']),int(fields['tick']))
   if key not in latest or latest[key]!=got:errors.append({'expiry':line,'latest':latest.get(key)})
  elif kind=='HUSH_Q_CAPTURE':captures+=1
  elif kind=='HUSH_Q_HOLD':
   holds+=1
   if int(fields['accepted'])<=int(fields['tick']):errors.append({'hold':line})
 return {'id':c['id'],'P':c['P'],'phi':c['phi'],'arms':arms,'expiries':expires,'captures_of_armed_lines':captures,'input_holds':holds,'non_clock_edge_arms':nonedges,'receiver_cycle_stamp':'ceil(arrival_tick/clock_period_ticks); checked independently against native deadline','errors':errors,'pass':not errors}
def main():
 ap=argparse.ArgumentParser();ap.add_argument('input',type=Path);ap.add_argument('--output',type=Path,required=True);a=ap.parse_args();data=json.loads(a.input.read_text());rows=[check_case(c) for c in data['cases']]
 out={'scope':__doc__.strip(),'input_sha256':hashlib.sha256(a.input.read_bytes()).hexdigest(),'cases':rows,'all_passed':all(r['pass'] for r in rows),'arm_count':sum(r['arms'] for r in rows)}
 a.output.write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8',newline='\n');assert out['all_passed']
if __name__=='__main__':main()
