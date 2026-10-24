"""Pure-stdlib recorded-measurement replay. No simulator, shell, or network."""
from pathlib import Path
from collections import defaultdict
import json,hashlib,math,base64,gzip
F=Path(__file__).resolve().parent
def read(n):
 if n=='MEASUREMENTS.json':
  b=gzip.decompress(base64.b64decode((F/'MEASUREMENTS.json.gz.b64').read_bytes()))
  assert hashlib.sha256(b).hexdigest()=='1a53419bb91be0c8882d1660f749a5b616ab38c1c3a0c6c20edf01cb167346c2'
  return json.loads(b)
 return json.loads((F/n).read_text(encoding='utf-8'))
for item in read('FILE_MANIFEST.json')['files']:
 p=F/item['path'];assert p.is_file() and p.stat().st_size==item['bytes'] and hashlib.sha256(p.read_bytes()).hexdigest()==item['sha256'],p.name
m=read('MEASUREMENTS.json');baseline=read('BASELINE_MEASUREMENTS.json');manifest=read('MANIFEST.json');expected=read('EXPECTED.json')
assert len(m)==72 and len(baseline)==18
assert {r['case']['id'] for r in m}=={c['id'] for c in manifest['cases']}
groups=defaultdict(list);pairs=defaultdict(dict)
for r in m:
 c=r['case'];assert r['valid'] and r['terminal_code']==0 and r['invariant_failures']==0 and r['checksum']==r['expected_checksum']=='5812969091072'
 assert c['N']==32 and c['P'] in (64,128,256) and c['phi'] in (0,c['P']//2,c['P']-1)
 assert [e['epoch'] for e in r['epochs']]==['validation','fir','features','join']
 assert sum(e['cycles'] for e in r['epochs'])==r['J']
 for k in ['instructions','WU','misses','hits','replacements']:assert sum(e[k] for e in r['epochs'])==r[k] and all(e[k]>=0 for e in r['epochs'])
 groups[(c['P'],c['cost'],c['cache'])].append(r);pairs[(c['P'],c['cost'],c['cache'],c['phi'])][c['kind']]=r
for r in baseline:groups[(128,8,r['case']['cache'])].append(r)
aggregates=[]
for ref in expected['aggregates']:
 key=(ref['P'],ref['cost'],ref['cache']);rows=groups[key];assert len(rows)==9
 z={'P':key[0],'cost':key[1],'cache':key[2],'origin':'existing R20' if key[:2]==(128,8) else 'new R22'}
 for kind in ['fixed','phase','suppress']:
  rr=[r for r in rows if r['case']['kind']==kind];assert len(rr)==3
  z[kind+'_max_J']=max(r['J'] for r in rr);z[kind+'_max_WU']=max(r['WU'] for r in rr)
 z['phase_minus_fixed_J_pct']=100*(z['phase_max_J']-z['fixed_max_J'])/z['fixed_max_J']
 z['phase_WU_reduction_vs_fixed_pct']=100*(z['fixed_max_WU']-z['phase_max_WU'])/z['fixed_max_WU']
 z['phase_minus_suppression_J']=z['phase_max_J']-z['suppress_max_J']
 assert z.keys()==ref.keys() and all((math.isclose(z[k],ref[k],rel_tol=1e-13,abs_tol=1e-12) if isinstance(z[k],(int,float)) else z[k]==ref[k]) for k in z)
 aggregates.append(z)
for key,r in pairs.items():
 assert r['phase']['case']['K']==r['suppress']['case']['K'] and r['phase']['epochs'][0]==r['suppress']['epochs'][0]
 assert r['suppress']['timeout_writes']==0 and r['fixed']['timeout_writes']==0
 assert r['phase']['timeout_writes']==(8 if key[2]=='32KiB' else 4)
print(json.dumps({'new_cases':72,'existing_baseline_cases':18,'all_checksums_and_epoch_sums_pass':True,'paired_conditions':len(pairs),'aggregate_rows':len(aggregates),'negative_result_retained':next(x for x in aggregates if (x['P'],x['cost'],x['cache'])==(64,8,'32KiB'))},indent=2))
