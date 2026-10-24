"""Directed, read-only tracing of the unchanged model; not an exhaustive proof."""
from pathlib import Path
import sys,json,hashlib
import replacement_model as m
HERE=Path(__file__).resolve().parent
source=Path(m.__file__).resolve()
sha=hashlib.sha256(source.read_bytes()).hexdigest()
assert sha=='6270a7fa1c79a81dab99f9712e170c60c1ded14dd5052f3b987ba421a1b99e10'
base=dict(m.P);m.P.update(shared_blocks=2,writer_store_count=8,period=10)
cases=[('private_admission', [('phase',0),('read',0)],(255,255,255)),
       ('full_update_wait',[('phase',0),('read',0),('read',1)],(255,255,255)),
       ('config_collision',[('phase',0),('read',0),('compute',9),('phase',1),('read',1)],(255,254,254))]
rows=[]
for name,ops,ks in cases:
 events=[];reads=[]
 def tracer(frame,event,arg):
  if event!='line':return tracer
  if Path(frame.f_code.co_filename).resolve()!=source:return None
  loc=frame.f_locals;ln=frame.f_lineno;fn=frame.f_code.co_name
  if fn=='simulate' and ln in [103,142,164,172,182]:
   if ln==103:kind='configuration_delays_finishing_WU'
   elif ln==142:kind='private_store_admit'
   elif ln==164:kind='reader_capture_issue'
   elif ln==172:kind='reader_classified'
   else:kind='bus_grant'
   events.append({'event':kind,'cycle':loc.get('t'),'read_issue':loc.get('read_issue'),
      'read_block':loc.get('v'),'private_due':loc.get('private_due'),
      'configuration_due':loc.get('config_due'),'bus':dict(loc['bus']) if loc.get('bus') else None})
  if fn=='finish_read' and ln==96:
   reads.append({'issue':loc['read_issue'],'completion':loc['now'],'service':loc['now']-loc['read_issue']})
  return tracer
 sys.settrace(tracer)
 try:r=m.simulate(ops,ks,0,0,writer_count=8,keep_trace=True)
 finally:sys.settrace(None)
 rows.append({'case':name,'operations':ops,'K':ks,'result':r,'reads':reads,'events':events})
assert rows[0]['reads'][0]['service']==61
assert rows[1]['reads'][1]['service']==70
assert rows[2]['result']['config_wu_deferrals']==1
assert rows[2]['reads'][1]['service']==61
(HERE/'SERVICE71_DIRECTED_TRACES.json').write_text(json.dumps({'model_sha256':sha,
 'scope':'Three directed timing traces, not exhaustive proof and not a witness that 71 is attained.',
 'rows':rows},indent=2)+'\n')
for row in rows:print(row['case'],'reads',row['reads'],'WUdeferrals',row['result']['config_wu_deferrals'])
