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
 allowed={'derive_peaks.py','replay_portable.py','verify_policy.py'}
 assert all(ok or n in allowed for n,ok in stable.items()),stable
 reviewed={n:dict(original_frozen_sha256=sha(HERE/'frozen-input'/n),reviewed_finalization_sha256=sha(HERE/'finalization-snapshot'/n)) for n in allowed}
 assert all(sha(SOURCE/n)==v['reviewed_finalization_sha256'] for n,v in reviewed.items())
 streams={}
 for a,b in [('INDEPENDENT_POLICY_TICKS.delta','build-05-policy/POLICY_TICKS.delta'),('INDEPENDENT_POLICY_RESULTS.csv','build-05-policy/POLICY_RESULTS.csv'),('INDEPENDENT_policies.txt','analysis-01/policies.txt')]:
  streams[a]=dict(independent_sha256=sha(HERE/a),producer_sha256=sha(SOURCE/b),bytes=(HERE/a).stat().st_size);assert streams[a]['independent_sha256']==streams[a]['producer_sha256']
 control5=numeric(HERE/'INDEPENDENT_CONTROL_5F.csv');control4=numeric(BUILD/'CONTROL_TICKS.csv')
 assert [r for r in control5 if r['t']<4*r['F']]==control4
 end=next(r for r in control4 if r['case']==7 and r['t']==167)
 assert end['after_qlen']==2 and end['after_R0v']==end['after_R1v']==0
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
 relations={r['case']:r for r in json.loads((HERE/'INDEPENDENT_RELATIONS.json').read_text())['records']}
 with (HERE/'INDEPENDENT_INITIALIZATION.csv').open('w',newline='') as f:
  w=csv.writer(f);w.writerow(['query','case','start','entry','translationFrames','cachePhase','readyPhase','calendarPhase','physicalPPhase','physicalNextIdAtEntry','resetNextId','IDTranslation','omittedPrehistoryTicksNOTExecuted','actualExecutedTicks'])
  for row in timing:
   rel=relations[row['case']];s=rel['entry_state'];start=row['start'];n=row['translationFrames'];cfg=rel['configuration']
   assert rel['cycle_entry_empty'] and all(s['before_'+k]==0 for k in ['qlen','R0v','R1v','outstanding','enabled','bytes','count0','count1','count2','count3','failed','fault']) and s['before_valid']==15
   if start:assert start==rel['entry']+n*cfg['F']
   origin=1 if start==0 else s['before_nextid']+8*n
   w.writerow([row['query'],row['case'],start,rel['entry'],n,start%cfg['p'],start%cfg['r'],start%cfg['F'],start%row['P'],origin,1,1-origin,start,row['ticks']])
 assert sha(HERE/'INDEPENDENT_INITIALIZATION.csv')==sha(SOURCE/'analysis-01/POLICY_INITIALIZATION.csv')
 coverage['expiry_equals_next_grant_first_miss']=sum(r['actualExpiry']==r['h'] and r['firstFail']==r['h'] for r in timing)
 coverage['first_miss']=sum(r['firstFail']>=0 for r in timing)
 omitted=sum(r['start'] for r in timing);assert omitted==440303104
 facts=dict(status='PASS_INDEPENDENT_FIXED_REFERENCE_RTL_SCOPE',case_count=12,primary_control_data_serialized_ticks=dict(primary),primary_control_data_total_ticks=sum(primary.values()),separate_independent_control_5F_ticks=counts['independent_control_5F']['ticks'],extra_control_ticks_beyond_4F=counts['independent_control_5F']['ticks']-primary['CONTROL_TICKS.csv'],actual_counts=counts,policy_positive=sum(r['firstFail']<0 for r in timing),policy_negative=sum(r['firstFail']>=0 for r in timing),omitted_prehistory_NOT_executed=omitted,coverage=dict(coverage),after_tick_maxima_by_case=dict(globalsample),exact_event_order_peaks_by_case=dict(globalpeak),all_peak_sidecars_match=True,source_files_unchanged_since_copy=stable,semantic_streams=streams,original_empty_frame_gate=dict(pass_cases=11,unknown_cases=[7],p7_r7_end_3F_queued=2),extension=dict(entries=[[r['case'],r['entry'],r['repeat']] for r in json.loads((HERE/'INDEPENDENT_RELATIONS.json').read_text())['records']],all_12_validated=True,extra_5F_endpoint_gate=True),limits=['Own reference component only; no native HUSH/coherence/PPA/silicon/application/performance inference.','Finite one-WU executions do not exhaust arbitrary WU words. Conditional proof requires WU t>initial capture cutpoint, fixed epoch/source/ready schedule and no other invalidation.','Physical prefix is preserved; omitted prehistory is not executed.','Container bytes are independently hashed; executable timestamp/debug GUID/gzip mtime need not reproduce.'])
 dump('PAPER_READY_FACTS.json',facts)
 facts['reviewed_nonRTL_finalization_changes']=reviewed
 supplement=json.loads((HERE/'cycle-supplement/INDEPENDENT_SUPPLEMENT_AUDIT.json').read_text())
 facts['separate_cycle_witness_supplement']={k:supplement[k] for k in ['status','queries','actual_executed_ticks','cycle_local_positive','cycle_local_negative','full_admitted_unchanged','cycle_local_positive_but_prefix_rejects','omitted_prehistory_NOT_executed','scope']}
 counterexample=dict(selection='Minimum KP-1, then K,P,phi among all271 cycle-local positives rejected by exact prefix',case=7,p=7,r=7,F=56,K=15,P=2,phi=0,KP_minus1=29,line=1,strict_first_capture_cutpoint=7,prefix=dict(query=16894,start=0,s=7,c=8,h=49,WU=8,expiry=36,slack=-13,actual_first_miss=49,actual_fail_owner=1,actual_fail_ID=6,actual_ticks=50),cycle=dict(query=30,start=37,cache_phase=2,ready_phase=2,calendar_phase=37,physical_P_phase=1,s=49,c=50,h=77,WU=50,expiry_if_not_cancelled=78,slack=1,actual_first_miss=None,actual_cancel_at=77,actual_ticks=41),interpretation='Two separate one-WU executions of the same policy. Cycle-local survival is not fresh-policy admission. All four prefix crossing edges remain required.')
 local=read_supp=numeric(HERE/'cycle-supplement/INDEPENDENT_POLICY_RESULTS.csv')
 fr={(r['K'],r['P'],r['phi']):r for r in timing if r['case']==7}
 pairs=[(r,fr[(r['K'],r['P'],r['phi'])]) for r in local if r['firstFail']<0 and fr[(r['K'],r['P'],r['phi'])]['firstFail']>=0]
 assert len(pairs)==271
 cr,pr=min(pairs,key=lambda z:(z[0]['K']*z[0]['P']-1,z[0]['K'],z[0]['P'],z[0]['phi']))
 assert (cr['query'],pr['query'])==(30,16894) and cr['expectedExpiry']==78 and pr['actualExpiry']==36 and pr['firstFail']==49
 facts['prominent_prefix_counterexample']=counterexample
 facts['strict_initial_WU_contract']='For each line j, every accepted/attempted WU word in the safety claim has t>its guaranteed first capture cutpoint. Data and one-WU tests obey this strict boundary.'
 dump('PAPER_READY_FACTS.json',facts)
 dump('EVIDENCE_BINDING_CHECK.json',dict(status='PASS_STABLE_RTL_AND_REVIEWED_FINALIZATION_SCRIPTS',source_stability=stable,reviewed_nonRTL_finalization_changes=reviewed,semantic_streams=streams,peak_sidecars=True,counts=counts,coverage=dict(coverage)))
 print(json.dumps(dict(status='PASS',counts=counts,coverage=dict(coverage)),indent=2))
if __name__=='__main__':main()
