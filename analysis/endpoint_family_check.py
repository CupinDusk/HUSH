"""Prespecified parameter family: actual source/functions and receiver registers."""
from pathlib import Path
from collections import Counter
import argparse,hashlib,json,math,subprocess
from source_producer import NAMES,extract
from r23_canonical import canonical
from r26_remod import profile,project
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def edge(s,p,q):
 c=p*((s+p-1)//p)+p
 return (s,c,s+q if c<s+q else c+q),c==s+q
def relation(p,q,s0):
 seen={};triples=[];s=s0
 while s%p not in seen:
  seen[s%p]=len(triples);e,tie=edge(s,p,q)
  if tie:return {'admitted':False,'tie':e,'visited_phases':list(seen)}
  triples.append(e);s=e[2]
 start=seen[s%p];prefix=triples[:start];cycle=triples[start:];d=s-cycle[0][0]
 assert start<p and 1<=len(cycle)<=p and d>0 and d%p==0
 if q<p:assert len(cycle)==1 and d==2*p
 if q>=2*p:assert len(cycle)==p//math.gcd(p,q) and d==math.lcm(p,q)
 return {'admitted':True,'prefix':prefix,'cycle':cycle,'translation':d}
def expected(p,q,s0):
 services=[s0];receipts=[];polls=[]
 for _ in range(32):
  (s,c,h),tie=edge(services[-1],p,q);assert not tie
  receipts.append(c);services.append(h)
  if c>s+q:polls.append(s+q)
 return services,receipts,polls
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--zig',type=Path,required=True);a=ap.parse_args()
 out=HERE/'R30_PRODUCER_FAMILY_RESULTS.json';build=HERE/'endpoint-family-build';assert not out.exists() and not build.exists();build.mkdir()
 records=[];admitted=[];counts=Counter();queries=unknown=positive=master_reduced=target_reduced=0
 for p in range(1,13):
  for q in range(1,3*p+1):
   for s0 in range(p):
    rec={'p':p,'q':q,'s0':s0,**relation(p,q,s0)};records.append(rec)
    regime='waiting' if q<p else 'polling' if q>=2*p else 'mixed_band'
    counts[regime+('_admitted' if rec['admitted'] else '_tie_rejected')]+=1
    if not rec['admitted']:continue
    rec['case_id']=len(admitted);admitted.append(rec)
    cyc=rec['cycle'];d=rec['translation'];raw=profile([(s,h-s) for s,c,h in cyc],d);Q=canonical(raw,d)
    master_reduced+=len(Q)<len(raw);rec['master_pairs']=Q
    all_edges=rec['prefix']+cyc;safeP=q+2*p
    rec['safe_policy']=[2,safeP,0]
    rec['safe_prefix_and_cycle_slack']=min(s+1+(-s-1)%safeP+safeP-h for s,c,h in all_edges)
    assert rec['safe_prefix_and_cycle_slack']>0
    for P in range(1,2*p+1):
     m=math.gcd(P,d);target=project(Q,m);target_reduced+=len(target)<len(raw)
     for phi in range(P):
      base=min(s+1+n*d+(phi-s-1-n*d)%P-h-n*d for s,c,h in cyc for n in range(P//m))
      derived=1+min((phi-r-1)%m-v for r,v in target)
      assert base==derived,(p,q,s0,P,phi)
      for K in [1,2]:
       value=(K-1)*P+derived;queries+=1;positive+=value>0;unknown+=value<=0
    if (p,q,s0) in [(5,3,0),(5,12,0),(5,8,3),(9,16,5)]:rec['worked_example']=True
 assert len(records)==1950 and len(admitted)+sum(v for k,v in counts.items() if k.endswith('tie_rejected'))==1950
 public=HERE/'upstream-memtest.cc';text=public.read_text(encoding='utf-8');defs=[(n,*extract(text,n)) for n in NAMES]
 code=text[:text.index('*/')+2]+'\n'+(HERE/'serial_client.prefix.cpp').read_text(encoding='utf-8')+'\n'+'\n\n'.join(d[1] for d in defs)+'\n'+(HERE/'endpoint_port.cpp').read_text(encoding='utf-8')+'\n'+(HERE/'endpoint_family_main.cpp').read_text(encoding='utf-8')
 assert 'const Tick target=' not in code
 for n,body,_,_ in defs:assert extract(code,n)[0]==body
 cpp=build/'endpoint_family.cpp';cpp.write_text(code,encoding='utf-8');binary=build/'endpoint_family.exe'
 run=subprocess.run([str(a.zig),'c++','-std=c++17','-O2','-UNDEBUG','-I',str(HERE),str(cpp),'-o',str(binary)],capture_output=True,text=True,timeout=120)
 (build/'compiler.log').write_text(run.stdout+run.stderr,encoding='utf-8');assert run.returncode==0,run.stderr
 stdin=''.join(f"{r['case_id']} {r['p']} {r['q']} {r['s0']}\n" for r in admitted)
 run=subprocess.run([str(binary)],input=stdin,capture_output=True,text=True,timeout=180)
 (build/'executions.jsonl').write_text(run.stdout,encoding='utf-8');(build/'stderr.txt').write_text(run.stderr,encoding='utf-8');assert run.returncode==0,run.stderr
 rows=[json.loads(x) for x in run.stdout.splitlines()];assert len(rows)==3*len(admitted)
 seen=set()
 for row in rows:
  rec=admitted[row['case']];key=(row['case'],row['WU_mode']);assert key not in seen;seen.add(key)
  assert (row['services'],row['receipts'],row['waiting_polls'])==expected(rec['p'],rec['q'],rec['s0'])
 result={'result':'PASS_PARAMETERIZED_SOURCE_COUPLED_PRODUCER_FAMILY',
 'protocol_sha256':sha(HERE/'R30_PRODUCER_FAMILY_PROTOCOL.json'),'argument_sha256':sha(HERE/'R30_PRODUCER_FAMILY_ARGUMENT.md'),
 'script_sha256':sha(Path(__file__)),'unchanged_receiver_sha256':sha(HERE/'endpoint_implementation.hpp'),
 'generated_source_sha256':sha(cpp),'source_execution_record_sha256':sha(build/'executions.jsonl'),
 'parameter_entries':len(records),'admitted_entries':len(admitted),'regime_counts':dict(counts),
 'source_coupled_executions':len(rows),'accepted_source_reads':33*len(rows),'completed_source_callbacks':32*len(rows),
 'master_projection_scalar_queries':queries,'positive_queries':positive,'nonpositive_queries_retained':unknown,
 'entries_with_master_reduction':master_reduced,'period_targets_with_reduction':target_reduced,
 'worked_examples':[r for r in records if r.get('worked_example')],
 'records':records,'scope':'One parameterized logical endpoint/client family with proved finite phase characterization. Three selected WU words per admitted entry, not complete WU exploration for each. Manual parameter proof plus finite source/exact scalar corroboration; no native cache, independent program or hardware claim.'}
 out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
 print(json.dumps({k:v for k,v in result.items() if k!='records'},indent=2))
if __name__=='__main__':main()
