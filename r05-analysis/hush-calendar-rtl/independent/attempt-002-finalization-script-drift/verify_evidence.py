"""Bindings, independent peak counters, complete streams and paper facts."""
from pathlib import Path
from collections import Counter,defaultdict
import csv,json,hashlib
HERE=Path(__file__).resolve().parent;SOURCE=HERE.parent;BUILD=HERE/'frozen-input/fresh-build'
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
def read(p):
 with p.open(newline='',encoding='utf-8') as f:return list(csv.DictReader(f))
def numeric(p):return [{k:int(v) for k,v in r.items()} for r in read(p)]
def dump(n,x):(HERE/n).write_text(json.dumps(x,indent=2)+'\n',encoding='utf-8')
def main():
 stable={p.name:sha(p)==sha(SOURCE/p.name) for p in (HERE/'frozen-input').iterdir() if p.is_file() and (SOURCE/p.name).exists()}
 assert all(stable.values()),stable
 streams={}
 for a,b in [('INDEPENDENT_POLICY_TICKS.delta','build-05-policy/POLICY_TICKS.delta'),('INDEPENDENT_POLICY_RESULTS.csv','build-05-policy/POLICY_RESULTS.csv'),('INDEPENDENT_policies.txt','analysis-01/policies.txt')]:
  streams[a]=dict(independent_sha256=sha(HERE/a),producer_sha256=sha(SOURCE/b),bytes=(HERE/a).stat().st_size);assert streams[a]['independent_sha256']==streams[a]['producer_sha256']
 control5=numeric(HERE/'INDEPENDENT_CONTROL_5F.csv');control4=numeric(BUILD/'CONTROL_TICKS.csv')
 assert [r for r in control5 if r['t']<4*r['F']]==control4
 policies=numeric(HERE/'INDEPENDENT_policies_COUNTERS.csv');controls=numeric(HERE/'INDEPENDENT_control_COUNTERS.csv')
 assert len(policies)==130112 and len(controls)==48
 peaks=numeric(SOURCE/'PEAK_POLICY_COUNTERS.csv');controlpeaks=read(SOURCE/'PEAK_CONTROL_DATA_COUNTERS.csv')
 peakfields=['peakFIFO','peakGlobal','peakLine0','peakLine1','peakLine2','peakLine3']
 maxfields=['maxFIFO','maxGlobal','maxLine0','maxLine1','maxLine2','maxLine3']
 globalpeak=defaultdict(lambda:[0]*6);globalsample=defaultdict(lambda:[0]*6)
 for i,(a,b) in enumerate(zip(policies,peaks)):
  assert a['query']==b['query']==i and a['case']==b['case']
  assert [a[k] for k in peakfields]==[b[k] for k in peakfields]
  for j,k in enumerate(peakfields):globalpeak[a['case']][j]=max(globalpeak[a['case']][j],a[k])
  for j,k in enumerate(maxfields):globalsample[a['case']][j]=max(globalsample[a['case']][j],a[k])
 index={(r['case'],r['mode']):r for r in controls}
 for row in controlpeaks:
  ci,mode=int(row['case']),int(row['mode']);a=index[(ci,mode)]
  assert [a[k] for k in peakfields]==[int(row[k]) for k in peakfields]
 assert dict(globalpeak)=={int(k):v for k,v in json.loads((SOURCE/'PEAK_COUNTERS.json').read_text())['policy_maxima_by_case'].items()}
 counts={}
 for label,rr in [('policies',policies),('data',[r for r in controls if r['mode']>=0]),('independent_control_5F',[r for r in controls if r['mode']==-1])]:
  counts[label]={k:sum(r[k] for r in rr) for k in ['ticks','enqueues','captures','emissions','transfers','backpressure','cancels','expiries','WUs','heldExpired','heldExpiredBlock']}
 assert counts['policies']['ticks']==84379472 and counts['data']['ticks']==34416
 assert counts['data']['captures']==counts['data']['emissions']==858
 assert counts['data']['cancels']==714 and counts['data']['backpressure']==1116 and counts['data']['WUs']==135792
 assert counts['policies']['heldExpired']==9428 and counts['policies']['heldExpiredBlock']==9356
 primary=Counter();coverage=Counter()
 for name in ['CONTROL_TICKS.csv','DATA_TICKS.csv']:
  for r in numeric(BUILD/name):
   primary[name]+=1
   coverage['multi_enqueues']+=r['evenq']==2
   coverage['enqueue_and_grant']+=bool(r['evenq'] and r['evgrant'])
   coverage['grant_and_callback']+=bool(r['evgrant'] and r['evcallback'])
   coverage['emit_and_transfer']+=bool(r['evemit'] and r['evtransfer'])
 # Policy timing ties are obtained from independent physical expiry/capture results.
 timing=numeric(HERE/'INDEPENDENT_POLICY_RESULTS.csv')
 coverage['expiry_equals_next_grant_first_miss']=sum(r['actualExpiry']==r['h'] and r['firstFail']==r['h'] for r in timing)
 coverage['first_miss']=sum(r['firstFail']>=0 for r in timing)
 omitted=sum(r['start'] for r in timing);assert omitted==440303104
 facts=dict(status='PASS_INDEPENDENT_FIXED_REFERENCE_RTL_SCOPE',case_count=12,primary_control_data_serialized_ticks=dict(primary),primary_control_data_total_ticks=sum(primary.values()),separate_independent_control_5F_ticks=counts['independent_control_5F']['ticks'],extra_control_ticks_beyond_4F=counts['independent_control_5F']['ticks']-primary['CONTROL_TICKS.csv'],actual_counts=counts,policy_positive=sum(r['firstFail']<0 for r in timing),policy_negative=sum(r['firstFail']>=0 for r in timing),omitted_prehistory_NOT_executed=omitted,coverage=dict(coverage),after_tick_maxima_by_case=dict(globalsample),exact_event_order_peaks_by_case=dict(globalpeak),all_peak_sidecars_match=True,source_files_unchanged_since_copy=stable,semantic_streams=streams,original_empty_frame_gate=dict(pass_cases=11,unknown_cases=[7],p7_r7_end_3F_queued=2),extension=dict(entries=[[r['case'],r['entry'],r['repeat']] for r in json.loads((HERE/'INDEPENDENT_RELATIONS.json').read_text())['records']],all_12_validated=True,extra_5F_endpoint_gate=True),limits=['Own reference component only; no native HUSH/coherence/PPA/silicon/application/performance inference.','Finite one-WU executions do not exhaust arbitrary WU words. Conditional proof requires WU t>initial capture cutpoint, fixed epoch/source/ready schedule and no other invalidation.','Physical prefix is preserved; omitted prehistory is not executed.','Container bytes are independently hashed; executable timestamp/debug GUID/gzip mtime need not reproduce.'])
 dump('PAPER_READY_FACTS.json',facts)
 dump('EVIDENCE_BINDING_CHECK.json',dict(status='PASS',source_stability=stable,semantic_streams=streams,peak_sidecars=True,counts=counts,coverage=dict(coverage)))
 print(json.dumps(dict(status='PASS',counts=counts,coverage=dict(coverage)),indent=2))
if __name__=='__main__':main()
