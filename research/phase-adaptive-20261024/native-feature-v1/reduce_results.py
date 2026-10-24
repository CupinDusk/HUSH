"""Audit complete frozen native matrices and derive task-completion bottlenecks.

Run only once VALIDATION_ROWS.json exists. Positive percent means shorter time
than the held-out best of all15 tested fixed values. The deployed-mode view
uses BOTH the mode and fixed/phase parameters frozen from training.
"""
from pathlib import Path
from itertools import product
import json,csv,hashlib,math,statistics
HERE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
CELL_KEYS=['lags','perline','pattern']
TRAIN_LOADS=[8,64,512,4096,65536]
FIXED_LOADS=[8,64,128,256,512,768,1024,1536,2048,3072,4096,8192,16384,32768,65536]
CELLS=set(product([1,16,64],[64,256],[0,1]))
def cell(row):return tuple(row['case'][k] for k in CELL_KEYS)
def percent(base,other):return 100.0*(base-other)/base
def dump(name,obj):(HERE/name).write_text(json.dumps(obj,indent=2)+'\n')
def write_csv(name,rows):
 with (HERE/name).open('w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
def best(rows):return min(rows,key=lambda r:(r['roi_cycles'],r['case']['K']))
def summarize(values):
 return {'n':len(values),'improve':sum(x>0 for x in values),'tie':sum(x==0 for x in values),
         'regress':sum(x<0 for x in values),'min_percent':min(values),'max_percent':max(values),
         'median_percent':statistics.median(values),'mean_percent':statistics.mean(values)}
def timing(row):
 assert row['valid'] is True,(row['case']['id'],'invalid source row')
 assert row['returncode']==0 and row['terminal']['code']==0
 assert not row.get('marker_errors') and not row.get('invariant_failures')
 assert row['roi_ticks']>0 and row['roi_cycles']>0
 events=row['phase_events'];ids=[e['id'] for e in events]
 assert len(ids)==8 and set(ids)=={0,1,2,10,11,12,13,99}
 assert ids[0]==0 and ids[-1]==99
 ticks={e['id']:int(e['tick']) for e in events}
 assert ticks[0]<ticks[1]<ticks[2]<ticks[99]
 assert all(ticks[2]<=ticks[i]<=ticks[99] for i in [10,11,12])
 assert ticks[0]<=ticks[13]<=ticks[99]
 assert ticks[99]-ticks[0]==row['roi_ticks']
 units=row['roi_ticks']/row['roi_cycles']
 assert math.isfinite(units) and units>0
 reader=max(ticks[i] for i in [10,11,12])-ticks[0]
 writer=ticks[13]-ticks[0];join=ticks[99]-ticks[0]
 assert max(reader,writer)<=join
 return {'ticks_per_cycle':units,'receiver_completion_cycles':reader/units,
         'writer_completion_cycles':writer/units,'joint_completion_cycles':join/units,
         'post_completion_tail_cycles':(join-max(reader,writer))/units,
         'last_worker':'receiver' if reader>writer else 'writer' if writer>reader else 'tie',
         'receiver0_completion_cycles':(ticks[10]-ticks[0])/units,
         'receiver1_completion_cycles':(ticks[11]-ticks[0])/units,
         'receiver2_completion_cycles':(ticks[12]-ticks[0])/units}

def main():
 required=['TRAINING_ROWS.json','FROZEN_SELECTION.json','VALIDATION_ROWS.json']
 assert all((HERE/n).is_file() for n in required),'Wait for complete VALIDATION_ROWS.json before running.'
 train=json.loads((HERE/required[0]).read_text());frozen=json.loads((HERE/required[1]).read_text())
 validation=json.loads((HERE/required[2]).read_text())
 assert isinstance(train,list) and isinstance(validation,list)
 assert len(train)==324 and len(validation)==216
 assert frozen['native_N28_N32_timing_seen'] is False
 training_bytes=(HERE/'TRAINING_ROWS.json').read_bytes()
 # The original freeze binds Windows CRLF bytes. Git/web exports can retain
 # the same UTF-8 text with LF endings; accept only those two representations.
 training_crlf=training_bytes.replace(b'\r\n',b'\n').replace(b'\n',b'\r\n')
 assert frozen['training_rows_sha256'] in {sha(HERE/'TRAINING_ROWS.json'),hashlib.sha256(training_crlf).hexdigest()}
 assert len({r['case']['id'] for r in train})==324 and len({r['case']['id'] for r in validation})==216
 assert {cell(r) for r in train}==CELLS=={cell(r) for r in validation}
 assert {r['case']['N'] for r in train}=={16} and {r['case']['N'] for r in validation}=={28}
 assert {r['case']['cache'] for r in train+validation}=={'16KiB'}
 assert len({r['benchmark_sha256'] for r in train+validation})==1
 assert len({r['config_sha256'] for r in train+validation})==1
 bound_rows=[]
 for split,source in [('training',train),('validation',validation)]:
  for row in source:
   t=timing(row);bound_rows.append({'split':split,**row,'derived_task_timing':t})
 assert len(bound_rows)==540
 scales={r['derived_task_timing']['ticks_per_cycle'] for r in bound_rows}
 assert len(scales)==1,scales
 selection={tuple(r[k] for k in CELL_KEYS):r for r in frozen['rows']}
 assert set(selection)==CELLS and len(frozen['rows'])==12
 groups=[];audited_pairs=[]
 for key in sorted(CELLS):
  z=[r for r in train if cell(r)==key];v=[r for r in validation if cell(r)==key];s=selection[key]
  assert len(z)==27 and len(v)==18
  zfixed=[r for r in z if r['case']['kind']=='fixed'];zphase=[r for r in z if r['case']['kind']=='phase']
  zcontrol=[r for r in z if r['case']['kind']=='control']
  assert len(zfixed)==5 and len(zphase)==20 and len(zcontrol)==2
  assert {tuple(r['case']['K']) for r in zfixed+zphase}=={(a,a,b) for a,b in product(TRAIN_LOADS,repeat=2)}
  assert {r['case']['mode'] for r in zcontrol}=={'predictable-wi','wu-of'}
  ft=best(zfixed);pt=best(zphase)
  assert ft['case']['K']==s['fixed_K'] and pt['case']['K']==s['phase_K']
  assert ft['roi_cycles']==s['training_fixed_J'] and pt['roi_cycles']==s['training_phase_J']
  mode='phase' if pt['roi_cycles']<ft['roi_cycles'] else 'fixed'
  assert mode==s['training_selected_mode']
  vf=[r for r in v if r['case']['kind']=='fixed'];vp=[r for r in v if r['case']['kind']=='selected-phase']
  vc=[r for r in v if r['case']['kind']=='control']
  assert len(vf)==15 and len(vp)==1 and len(vc)==2
  assert {tuple(r['case']['K']) for r in vf}=={(k,k,k) for k in FIXED_LOADS}
  assert all(r['case']['mode']=='hush' and r['case']['cost']==8 for r in vf+vp)
  assert vp[0]['case']['K']==s['phase_K'] and len(set(s['phase_K']))>1
  assert {r['case']['mode'] for r in vc}=={'predictable-wi','wu-of'}
  oracle=best(vf);phase=vp[0]
  frozen_fixed=next(r for r in vf if r['case']['K']==s['fixed_K'])
  deployed=phase if mode=='phase' else frozen_fixed
  fixed_time=timing(oracle);phase_time=timing(phase);deployed_time=timing(deployed)
  wi=next(r for r in vc if r['case']['mode']=='predictable-wi')
  wu=next(r for r in vc if r['case']['mode']=='wu-of')
  row={**dict(zip(CELL_KEYS,key)),'N':28,'training_mode':mode,
       'training_fixed_K':s['fixed_K'],'training_phase_K':s['phase_K'],
       'training_fixed_J':ft['roi_cycles'],'training_phase_J':pt['roi_cycles'],
       'training_phase_signed_percent':percent(ft['roi_cycles'],pt['roi_cycles']),
       'best15_fixed_K':oracle['case']['K'],'best15_fixed_J':oracle['roi_cycles'],
       'frozen_phase_K':phase['case']['K'],'phase_J':phase['roi_cycles'],
       'phase_vs_best15_ratio':phase['roi_cycles']/oracle['roi_cycles'],
       'phase_vs_best15_signed_percent':percent(oracle['roi_cycles'],phase['roi_cycles']),
       'deployed_mode':mode,'deployed_K':deployed['case']['K'],'deployed_J':deployed['roi_cycles'],
       'deployed_vs_best15_signed_percent':percent(oracle['roi_cycles'],deployed['roi_cycles']),
       'frozen_fixed_J':frozen_fixed['roi_cycles'],'WI_J':wi['roi_cycles'],'WU_J':wu['roi_cycles'],
       'fixed_receiver_cycles':fixed_time['receiver_completion_cycles'],
       'fixed_writer_cycles':fixed_time['writer_completion_cycles'],
       'fixed_join_cycles':fixed_time['joint_completion_cycles'],
       'fixed_tail_cycles':fixed_time['post_completion_tail_cycles'],'fixed_last_worker':fixed_time['last_worker'],
       'phase_receiver_cycles':phase_time['receiver_completion_cycles'],
       'phase_writer_cycles':phase_time['writer_completion_cycles'],
       'phase_join_cycles':phase_time['joint_completion_cycles'],
       'phase_tail_cycles':phase_time['post_completion_tail_cycles'],'phase_last_worker':phase_time['last_worker'],
       'phase_receiver_signed_percent':percent(fixed_time['receiver_completion_cycles'],phase_time['receiver_completion_cycles']),
       'phase_writer_signed_percent':percent(fixed_time['writer_completion_cycles'],phase_time['writer_completion_cycles']),
       'fixed_updates':oracle.get('updates'),'phase_updates':phase.get('updates'),
       'fixed_misses':oracle.get('misses'),'phase_misses':phase.get('misses'),
       'fixed_replacements':oracle.get('replacements'),'phase_replacements':phase.get('replacements')}
  groups.append(row)
  audited_pairs.append({'cell':dict(zip(CELL_KEYS,key)),'training_frozen':s,
       'best15_fixed_case_id':oracle['case']['id'],'phase_case_id':phase['case']['id'],
       'deployed_case_id':deployed['case']['id'],'best15_fixed_timing':fixed_time,
       'phase_timing':phase_time,'deployed_timing':deployed_time})
 summary={'rows_preserved':540,'training_rows':324,'validation_rows':216,'cells':12,
   'fixed_loads_per_validation_cell':FIXED_LOADS,'ticks_per_cycle':next(iter(scales)),
   'phase_vs_best15':summarize([r['phase_vs_best15_signed_percent'] for r in groups]),
   'training_deployed_mode_vs_best15':summarize([r['deployed_vs_best15_signed_percent'] for r in groups]),
   'by_lags':{str(L):{'phase_vs_best15':summarize([r['phase_vs_best15_signed_percent'] for r in groups if r['lags']==L]),
                     'deployed_mode_vs_best15':summarize([r['deployed_vs_best15_signed_percent'] for r in groups if r['lags']==L])} for L in [1,16,64]},
   'best_fixed_last_worker_counts':{v:sum(r['fixed_last_worker']==v for r in groups) for v in ['writer','receiver','tie']},
   'phase_last_worker_counts':{v:sum(r['phase_last_worker']==v for r in groups) for v in ['writer','receiver','tie']},
   'input_sha256':{n:sha(HERE/n) for n in required},
   'reducer_sha256':sha(Path(__file__)),'all_input_rows_and_freeze_checks_passed':True,
   'scope':'Deterministic paired native timing reduction, not WCET; training fixed parameters and mode are frozen. Best15 is a held-out comparison oracle, not deployed retuning.'}
 dump('ALL_ROWS_WITH_TIMING.json',bound_rows);dump('CELL_BOTTLENECK_AUDIT.json',audited_pairs)
 dump('REDUCTION_SUMMARY.json',summary);write_csv('CELL_RESULTS.csv',groups)
 compact=[]
 for row in bound_rows:
  c=row['case'];compact.append({'split':row['split'],'id':c['id'],'N':c['N'],
    'lags':c['lags'],'perline':c['perline'],'pattern':c['pattern'],'kind':c['kind'],
    'mode':c['mode'],'K':c['K'],'roi_cycles':row['roi_cycles'],
    **row['derived_task_timing'],'updates':row.get('updates'),'misses':row.get('misses'),
    'replacements':row.get('replacements'),'valid':row['valid']})
 write_csv('ALL540_TIMING_ROWS.csv',compact)
 print(json.dumps(summary,indent=2))

if __name__=='__main__':main()
