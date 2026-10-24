from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
import subprocess,json,hashlib,time,re,sys,os
R=Path(__file__).resolve().parent
BIN=Path(os.environ['HUSH_GEM5_BINARY']).resolve()
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
M=json.loads(Path(sys.argv[1]).read_text());OUT=R/M['round'];OUT.mkdir(exist_ok=False)
def one(c):
 d=OUT/c['id'];d.mkdir()
 cmd=[str(BIN),'-d',str(d),str(R/'config_v2.py'),'--cmd',str(Path(os.environ['HUSH_PIPELINE_BINARY']).resolve()),'--options',f"{c['N']} {c['perline']} 16 4 {c['cost']} {c['pattern']}",'--mode',c['mode'],'--schedule',','.join(map(str,c['K'])),'--config-cycles',str(c['cost']),'--cache-size',c['cache'],'--max-ticks','20000000000','--summary',str(d/'summary.json')]
 start=time.time()
 with (d/'stdout.log').open('w') as so,(d/'stderr.log').open('w') as se:p=subprocess.run(cmd,stdout=so,stderr=se,cwd=R)
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
 keys={k:v for k,v in stats.items() if k=='simInsts' or 'hush' in k or k.endswith('overallMisses::total') or k.endswith('replacements')}
 result={'case':c,'valid':good,'returncode':p.returncode,'elapsed_seconds':time.time()-start,'summary':s,'test_pass':'TEST PASSED' in text,'stdout_tail':text[-1200:],'stderr_tail':(d/'stderr.log').read_text(errors='replace')[-1800:] if not good else '', 'invariant_failures':failed,'statistics':keys,'config_sha256':sha(R/'config_v2.py'),'benchmark_sha256':sha(Path(os.environ['HUSH_PIPELINE_BINARY']).resolve())}
 (d/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n')
 return result
rows=[]
with ThreadPoolExecutor(max_workers=2) as pool:
 for row in pool.map(one,M['cases']):
  rows.append(row);(R/'STATUS.json').write_text(json.dumps({'round':M['round'],'completed':len(rows),'cases':len(M['cases'])})+'\n')
(OUT/'RESULTS.json').write_text(json.dumps({'rows':rows,'valid':sum(r['valid'] for r in rows),'cases':len(rows),'manifest_sha256':sha(Path(sys.argv[1]))},indent=2)+'\n')
(R/'STATUS.json').write_text(json.dumps({'round':M['round'],'stage':'complete','completed':len(rows),'cases':len(rows)})+'\n')
