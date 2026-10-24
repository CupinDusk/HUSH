from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
import subprocess,json,hashlib,time,re,sys,os
R=Path(__file__).resolve().parent
SIM_SOURCE=Path(os.environ['HUSH_GEM5_SOURCE']).resolve()
BENCH=Path(os.environ['HUSH_PIPELINE_BINARY']).resolve()
BIN=Path(os.environ['HUSH_GEM5_BINARY']).resolve()
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
M=json.loads(Path(sys.argv[1]).read_text());OUT=R/M['round'];OUT.mkdir(exist_ok=False)
def one(c):
 d=OUT/c['id'];d.mkdir()
 cost_arg=str(c['cost']) if c.get('legacy_layout') else f"{c['cost']:05d}"
 cmd=[str(BIN),'-d',str(d),str(R/'config_v3.py'),'--cmd',str(BENCH),'--options',f"{c['N']} {c['perline']} {c['lags']} 4 {cost_arg} {c['pattern']}",'--mode',c['mode'],'--schedule',','.join(map(str,c['K'])),'--config-cycles',str(c['cost']),'--cache-size',c['cache'],'--max-ticks','20000000000','--summary',str(d/'summary.json')]
 cmd+=['--write-policy',c.get('write_policy','apply')]
 if c.get('legacy_layout'):cmd+=['--legacy-layout']
 start=time.time()
 with (d/'stdout.log').open('w') as so,(d/'stderr.log').open('w') as se:p=subprocess.run(cmd,stdout=so,stderr=se,cwd=SIM_SOURCE)
 blocks=[];st={}
 if (d/'stats.txt').exists():
  for line in (d/'stats.txt').read_text().splitlines():
   if 'Begin Simulation Statistics' in line:st={};continue
   if 'End Simulation Statistics' in line:blocks.append(st);continue
   z=line.split()
   if len(z)>1:
    try:st[z[0]]=float(z[1])
    except ValueError:pass
 s=json.loads((d/'summary.json').read_text()) if (d/'summary.json').exists() else None
 text=(d/'stdout.log').read_text(errors='replace');idx=s.get('roi_stats_block') if s else None
 stats=blocks[idx] if isinstance(idx,int) and idx<len(blocks) else {}
 failed={f'{i}:{k}':v for i,b in enumerate(blocks) for k,v in b.items() if k.endswith('InvariantFailures') and v}
 good=bool(p.returncode==0 and s and s.get('roi_ticks') and 'TEST PASSED' in text and not s.get('marker_errors') and [z['id'] for z in s['phase_events'] if z['id']<10 or z['id']==99]==[0,1,2,99] and sorted(z['id'] for z in s['phase_events'] if 10<=z['id']<14)==[10,11,12,13] and not failed and stats and s['terminal']['code']==0)
 keep=lambda k:k=='simInsts' or 'hush' in k or k.endswith('overallMisses::total') or k.endswith('overallHits::total') or k.endswith('replacements') or k.endswith('numInsts') or k.endswith('numCycles')
 keys={k:v for k,v in stats.items() if keep(k)}
 epochs=[{**e,'statistics':{k:v for k,v in blocks[e['stats_block']].items() if keep(k)}} for e in s.get('epoch_snapshots',[])] if s else []
 good=good and len(epochs)==4 and [e['label'] for e in epochs]==['validation','fir','features','join']
 result={'case':c,'valid':good,'returncode':p.returncode,'elapsed_seconds':time.time()-start,'summary':s,'test_pass':'TEST PASSED' in text,'stdout_tail':text[-1200:],'stderr_tail':(d/'stderr.log').read_text(errors='replace')[-1800:] if not good else '', 'invariant_failures':failed,'statistics':keys,'epoch_statistics':epochs,'config_sha256':sha(R/'config_v3.py'),'benchmark_sha256':sha(BENCH)}
 (d/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
 return result
rows=[]
with ThreadPoolExecutor(max_workers=2) as pool:
 for row in pool.map(one,M['cases']):
  rows.append(row);(R/'STATUS.json').write_text(json.dumps({'round':M['round'],'completed':len(rows),'cases':len(M['cases'])})+'\n',encoding='utf-8',newline='\n')
(OUT/'RESULTS.json').write_text(json.dumps({'rows':rows,'valid':sum(r['valid'] for r in rows),'cases':len(rows),'manifest_sha256':sha(Path(sys.argv[1]))},indent=2)+'\n',encoding='utf-8',newline='\n')
(R/'STATUS.json').write_text(json.dumps({'round':M['round'],'stage':'complete','completed':len(rows),'cases':len(rows)})+'\n',encoding='utf-8',newline='\n')
