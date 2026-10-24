"""Run a frozen native manifest; simulator/benchmark paths are user inputs."""
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime,timezone
import subprocess,json,hashlib,time,sys,argparse
ap=argparse.ArgumentParser()
ap.add_argument('manifest',type=Path);ap.add_argument('--binary',type=Path,required=True)
ap.add_argument('--benchmark',type=Path,required=True);ap.add_argument('--config',type=Path,required=True)
ap.add_argument('--sim-cwd',type=Path,required=True);ap.add_argument('--workers',type=int,default=4)
a=ap.parse_args();assert 1<=a.workers<=4
R=Path(__file__).resolve().parent;M=json.loads(a.manifest.read_text());OUT=R/M['round'];OUT.mkdir(exist_ok=False)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
binding={'simulator_sha256':sha(a.binary),'benchmark_sha256':sha(a.benchmark),'config_sha256':sha(a.config),'driver_sha256':sha(Path(__file__)),'manifest_sha256':sha(a.manifest),'started_utc':datetime.now(timezone.utc).isoformat(),'workers':a.workers}
assert binding['benchmark_sha256']=='2240805a3edaceb2741e7b0285f9dd1cdd07188395705322a8ca088206300096'
(OUT/'SOURCE_BINDING.json').write_text(json.dumps(binding,indent=2)+'\n')
def one(c):
 d=OUT/c['id'];d.mkdir()
 assert c['P']==128 and 0<=c['phi']<c['P'] and all(1<=k<=255 for k in c['K'])
 nominal=[k*c['P'] for k in c['K']]
 cmd=[str(a.binary),'-d',str(d),str(a.config),'--cmd',str(a.benchmark),'--options',f"{c['N']} {c['perline']} {c['lags']} 4 {c['cost']:05d} {c['pattern']}",'--mode',c['mode'],'--schedule',','.join(map(str,nominal)),'--config-cycles',str(c['cost']),'--cache-size',c['cache'],'--max-ticks','20000000000','--summary',str(d/'summary.json'),'--write-policy',c['write_policy'],'--timer-period',str(c['P']),'--tick-phase',str(c['phi'])]
 start=time.monotonic()
 with (d/'stdout.log').open('w') as so,(d/'stderr.log').open('w') as se:
  p=subprocess.run(cmd,stdout=so,stderr=se,cwd=a.sim_cwd)
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
 good=bool(good and len(epochs)==4 and [e['label'] for e in epochs]==['validation','fir','features','join'])
 result={'case':c,'valid':good,'returncode':p.returncode,'elapsed_seconds':time.monotonic()-start,'summary':s,'test_pass':'TEST PASSED' in text,'stdout_tail':text[-1200:],'stderr_tail':(d/'stderr.log').read_text(errors='replace')[-1800:] if not good else '','invariant_failures':failed,'statistics':keys,'epoch_statistics':epochs,**{k:binding[k] for k in ['simulator_sha256','benchmark_sha256','config_sha256','driver_sha256']}}
 (d/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n')
 return result
rows=[]
with ThreadPoolExecutor(max_workers=a.workers) as pool:
 for row in pool.map(one,M['cases']):
  rows.append(row);(R/'STATUS.json').write_text(json.dumps({'round':M['round'],'completed':len(rows),'valid':sum(r['valid'] for r in rows),'cases':len(M['cases'])})+'\n')
assert sha(a.binary)==binding['simulator_sha256'] and sha(a.config)==binding['config_sha256']
(OUT/'RESULTS.json').write_text(json.dumps({'rows':rows,'valid':sum(r['valid'] for r in rows),'cases':len(rows),'binding':binding},indent=2)+'\n')
(R/'STATUS.json').write_text(json.dumps({'round':M['round'],'stage':'complete','completed':len(rows),'valid':sum(r['valid'] for r in rows),'cases':len(rows)})+'\n')
