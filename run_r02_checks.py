"""Recompute new exact analyses and audit every published native measurement."""
from pathlib import Path
from bisect import bisect_right
from collections import Counter, defaultdict
import gzip, hashlib, json, statistics, struct, subprocess, sys

HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text(encoding='utf-8'))
def run(rel):
 p=HERE/rel
 result=subprocess.run([sys.executable,'-B','-X','utf8',str(p)],cwd=p.parent,capture_output=True,text=True,encoding='utf-8')
 (p.parent/(p.stem+'.replay.log')).write_text(result.stdout+result.stderr,encoding='utf-8')
 assert result.returncode==0,(rel,result.returncode,result.stdout[-3000:],result.stderr[-3000:])
 print(rel,'PASS',flush=True)

def audit_native():
 loc=HERE/'r02/lookup';expect=HERE/'r02/expected'
 manifest=read(loc/'NATIVE_INPUT_MANIFEST.json')
 baseline=read(expect/'NATIVE_INPUT_MANIFEST.json')
 # Protocol and generated input/query bytes are unchanged, despite portable imports.
 assert manifest==baseline
 result=read(expect/'NATIVE_RECORDED_RESULTS.json')
 events=[json.loads(line) for line in gzip.decompress((expect/'NATIVE_RECORDED_EVENTS.jsonl.gz').read_bytes()).decode('utf-8').splitlines()]
 assert events[0]['event']=='start' and events[-1]['event']=='complete' and events[-1]['status']=='PASS'
 counts=Counter(e['event'] for e in events)
 assert counts['timing']==387 and counts['block_order']==126 and counts['validation']==14
 assert counts['profile_storage']==10572 and counts['construction']==14 and not counts['failure']
 assert result['source_sha256']==sha(loc/'benchmark.cpp')
 bytype=defaultdict(list)
 for e in events:bytype[e['event']].append(e)
 orders={(e['corpus'],e['block']):e['order'] for e in bytype['block_order']}
 assert len(orders)==126
 for s in manifest['schedule']:assert orders[s['corpus'],s['block']]==s['order']
 timings={(e['corpus'],e['block'],e['route']):e for e in bytype['timing']};assert len(timings)==387
 native_checks={e['corpus']:e for e in bytype['validation']}
 # Independent arbitrary-integer predecessor checksums for all generated queries.
 words=iter((loc/'NATIVE_PROFILES.txt').read_text().split());n=int(next(words));oracles=[]
 sys.path.insert(0,str(HERE/'analysis'))
 from sparse_canonical_check import canonical
 from r26_remod import profile
 for i in range(n):
  name,corpus=next(words),next(words)
  m,nraw,ng,nc=[int(next(words)) for _ in range(4)]
  pairs=[(int(next(words)),int(next(words))) for _ in range(nraw+ng+nc)]
  raw,grouped,core=pairs[:nraw],pairs[nraw:nraw+ng],pairs[nraw+ng:]
  assert tuple(grouped)==profile(raw,m) and list(core)==canonical(m,grouped)
  reset=sorted(((r+1)%m,-v) for r,v in core)
  oracles.append((m,[a for a,h in reset],[h for a,h in reset]))
 assert next(words,None) is None and n==10572
 checks=0
 for stream in manifest['streams']:
  p=loc/stream['file'];assert sha(p)==stream['sha256']
  checksum=0;cnt=0
  for ident,z in struct.iter_unpack('<IQ',p.read_bytes()):
   m,aa,hh=oracles[ident];j=bisect_right(aa,z)-1
   checksum+=hh[j]+((z-aa[j])%m);cnt+=1
  assert cnt==stream['query_count'] and str(checksum)==native_checks[stream['corpus']]['expected_checksum']
  checks+=cnt
 corpus={c['corpus']:c for c in result['corpora']}
 for stream in manifest['streams']:
  name=stream['corpus'];c=corpus[name]
  assert c['query_count']==stream['query_count']
  for route in c['routes']:
   r=route['route']
   if r not in stream['eligible_routes']:
    assert route['status']=='UNAVAILABLE_MODULUS_EXCEEDS_2_POWER_20';continue
   rows=[timings[name,b,r] for b in range(9)]
   assert rows==route['blocks']
   ns=[row['elapsed_ns'] for row in rows];q=[v/stream['query_count'] for v in ns]
   assert route['elapsed_ns']==dict(median=statistics.median(ns),minimum=min(ns),maximum=max(ns))
   assert route['nanoseconds_per_query']==dict(median=statistics.median(q),minimum=min(q),maximum=max(q))
 assert checks==1474560
 return dict(status='PASS_RECORDED_EVENTS_ALL_NUMERICAL_TIMINGS_AND_INDEPENDENT_CHECKSUMS',profiles=n,query_records=checks,timing_observations=387,paired_blocks=126,native_full_benchmark_rerun=False)

def main():
 output=HERE/'R02_REPLAY_RESULTS.json';assert not output.exists(),'Use a fresh extraction; do not overwrite evidence.'
 manifest=read(HERE/'MANIFEST.json')
 for name,h in manifest['files'].items():assert sha(HERE/name)==h,name
 for rel in ['r02/prefix/check_prefix_admission.py','r02/prefix/independent_countdown_validation.py','r02/lookup/validate_and_generate.py','r02/lookup/prepare_native_inputs.py']:run(rel)
 expect=HERE/'r02/expected'
 full=read(HERE/'r02/prefix/RESULTS.json')
 actual={k:v for k,v in full.items() if k not in ['protocol_sha256','script_sha256','input_r30_sha256','input_r35_sha256','all_phase_bases_sha256','all_phase_bases_bytes','records']}
 actual['expected_per_entry_records']=len(full['records'])
 assert actual==read(expect/'PREFIX_SUMMARY.json')
 indep=read(HERE/'r02/prefix/INDEPENDENT_VALIDATION.json')
 assert {k:v for k,v in indep.items() if not k.endswith('_sha256')}==read(expect/'PREFIX_INDEPENDENT.json')
 val=read(HERE/'r02/lookup/VALIDATION_RESULTS.json')
 assert {k:v for k,v in val.items() if k not in ['protocol_sha256','script_sha256']}==read(expect/'LOOKUP_VALIDATION.json')
 native=audit_native()
 report=dict(status='PASS_FRESH_EXTRACTION_NEW_CORE_ANALYSES_AND_RECORDED_TIMING_AUDIT',prefix=actual['checks'],prefix_full_expanded=actual['grids']['expanded']['all'],independent_prefix=indep['checks'],lookup=dict(small_profiles=val['small_profiles'],small_phase_checks=val['small_phase_checks'],family_checks=val['source_family_physical_phase_checks'],wide_checks=val['wide_checks']),native=native,scope='New portable exact analyses recomputed. All old source/model files remain byte-identical to prior public v3; their older separate suite is not rerun by this command. Recorded native event arithmetic, schedule and every numerical timing record audited; elapsed times are not a new native benchmark run.')
 output.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');print(json.dumps(report,indent=2),flush=True)
if __name__=='__main__':main()
