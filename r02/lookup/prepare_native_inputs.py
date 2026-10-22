"""Freeze all raw/grouped/canonical inputs and paired timing schedules."""
from pathlib import Path
from collections import defaultdict
import hashlib,json,random,struct,sys
HERE=Path(__file__).resolve().parent;PACKAGE=HERE.parents[1]
OLD=PACKAGE/'expected'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 out=HERE/'NATIVE_INPUT_MANIFEST.json';assert not out.exists()
 src=HERE/'PROFILES.txt';words=iter(src.read_text().split());n=int(next(words));rows=[]
 original={str(r['case_id']):r for r in json.loads((OLD/'R30_PRODUCER_FAMILY_RESULTS.json').read_text())['records'] if r['admitted']}
 for i in range(n):
  name,corpus,m,ng,nc=[next(words) for _ in range(5)];m,ng,nc=map(int,[m,ng,nc]);pairs=[(int(next(words)),int(next(words))) for _ in range(ng+nc)]
  grouped,canon=pairs[:ng],pairs[ng:]
  if corpus=='family':
   ident=name.split('_')[1];raw=[(s,h-s) for s,c,h in original[ident]['cycle']]
  else:raw=grouped[:] # A disclosed sorted ordering of the same distinct sparse terms.
  rows.append(dict(name=name,corpus=corpus,m=m,raw=raw,grouped=grouped,canonical=canon))
 rawfile=HERE/'NATIVE_PROFILES.txt';assert not rawfile.exists()
 with rawfile.open('w',encoding='ascii',newline='\n') as f:
  f.write(f'{n}\n')
  for r in rows:
   f.write(f"{r['name']} {r['corpus']} {r['m']} {len(r['raw'])} {len(r['grouped'])} {len(r['canonical'])}\n")
   for a,v in r['raw']+r['grouped']+r['canonical']:f.write(f'{a} {v}\n')
 corpora=defaultdict(list)
 for i,r in enumerate(rows):corpora[r['corpus']].append(i)
 rng=random.Random(20261023);streams=[];schedule=[]
 for ci,(name,ids) in enumerate(corpora.items()):
  count=2**20 if name=='family' else 2**15
  qp=HERE/f'queries_{ci:02d}.bin';assert not qp.exists()
  with qp.open('wb') as f:
   for j in range(count):
    i=ids[j%len(ids)];z=rng.randrange(rows[i]['m']);f.write(struct.pack('<IQ',i,z))
  eligible=[0,1,2,3] if all(rows[i]['m']<=2**20 for i in ids) else [0,1,2]
  for block in range(9):
   order=eligible[:];rng.shuffle(order);schedule.append(dict(corpus=name,block=block,order=order))
  streams.append(dict(index=ci,corpus=name,profile_ids=ids,query_count=count,file=qp.name,sha256=sha(qp),eligible_routes=eligible))
 control=HERE/'NATIVE_CONTROL.txt'
 with control.open('w',encoding='ascii',newline='\n') as f:
  f.write(f'{len(streams)}\n')
  for s in streams:
   f.write(f"{s['corpus']} {s['file']} {s['query_count']} {len(s['profile_ids'])} {len(s['eligible_routes'])}\n")
   f.write(' '.join(map(str,s['profile_ids']))+'\n')
   f.write(' '.join(map(str,s['eligible_routes']))+'\n')
   for order in [r['order'] for r in schedule if r['corpus']==s['corpus']]:f.write(' '.join(map(str,order))+'\n')
 result=dict(status='INPUTS_AND_RUN_SCHEDULE_FROZEN_BEFORE_NATIVE_EXECUTION',seed=20261023,
  protocol_sha256=sha(HERE/'PROTOCOL.json'),validated_profiles_sha256=sha(src),raw_profile_file=rawfile.name,raw_profile_sha256=sha(rawfile),
  control_file=control.name,control_sha256=sha(control),streams=streams,schedule=schedule,
  native_format='N then name corpus modulus nraw ngrouped ncanonical; raw/grouped/canonical pairs each as decimal residue span. Query records little-endian uint32 global profile id plus uint64 reduced phase;12bytes per record.',
  routes=['grouped_scan','canonical_scan','reset_predecessor','dense_phase_table'],
  construction='Native grouping takes raw source service/span rows for family. Wide inputs retain their original distinct values but are sorted by residue before native grouping; ordering is a disclosed transformation. Expected grouped/canonical arrays are exact validation oracles, not inputs to construction timers.',
  scope='No native timing has yet executed. Complete generated query streams and realized9-block route orders are frozen before measurements.')
 out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps({k:v for k,v in result.items() if k not in ['streams','schedule']},indent=2))
if __name__=='__main__':main()
