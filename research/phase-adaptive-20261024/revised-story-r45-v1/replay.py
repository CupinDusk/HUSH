"""Verify and independently reduce saved R45 evidence; no new experiments."""
from pathlib import Path,PurePosixPath
import argparse,hashlib,json,stat,subprocess,sys,tempfile,zipfile
def json_pointer(value,pointer):
    assert isinstance(pointer,str) and pointer.startswith('/') and pointer.strip('/'),pointer
    for key in pointer[1:].split('/'):
        key=key.replace('~1','/').replace('~0','~')
        value=value[int(key)] if isinstance(value,list) else value[key]
    return value

def validate_execution_counts(counts,bindings,reader,component_names):
    assert isinstance(counts,dict) and counts
    assert all(type(v) is int and v>=0 for v in counts.values()),'Finalize actual execution counts before preparation'
    assert len(bindings)==len(counts) and {b['name'] for b in bindings}==set(counts)
    assert component_names and len(component_names)==len(set(component_names))
    checks=[]
    for b in bindings:
        values=[]
        for component in component_names:
            pointers=b.get('component_pointers',{}).get(component,b)
            summary=json.loads(reader(component,'SUMMARY.json'))
            ledger=json.loads(reader(component,'LEDGER.json'))
            a=json_pointer(summary,pointers['summary_pointer']);z=json_pointer(ledger,pointers['ledger_pointer'])
            assert type(a) is int and type(z) is int and a==z,(b['name'],component,a,z)
            values.append({'component':component,'actual':a,'summary_pointer':pointers['summary_pointer'],'ledger_pointer':pointers['ledger_pointer']})
        total=sum(value['actual'] for value in values)
        assert total==counts[b['name']],(b['name'],counts[b['name']],total)
        checks.append({'name':b['name'],'actual':total,'component_values':values})
    if {'cxxrtl_executions_total','cxxrtl_main_current','cxxrtl_gates_current','cxxrtl_historical_executions'}<=set(counts):
        assert counts['cxxrtl_executions_total']==sum(counts[k] for k in ['cxxrtl_main_current','cxxrtl_gates_current','cxxrtl_historical_executions'])
    for stem in ['cxxrtl_generation','cxxrtl_compile']:
        if {stem+'_attempts',stem+'_successes',stem+'_failures'}<=set(counts):
            assert counts[stem+'_attempts']==counts[stem+'_successes']+counts[stem+'_failures']
    for zero_field in ['native_cpu_executions','cycle_model_executions','formal_executions']:
        if zero_field in counts:assert counts[zero_field]==0,(zero_field,counts[zero_field])
    return checks


ap=argparse.ArgumentParser(description=__doc__)
ap.add_argument('--quick',action='store_true')
ap.add_argument('--output',type=Path)
args=ap.parse_args();base=Path(__file__).resolve().parent
m=json.loads((base/'MANIFEST.json').read_text(encoding='utf-8'))
assert m['schema']=='hush-r45-portable-v1'
assert m['new_native_executions_recorded']==m['new_source_cycle_model_executions_recorded']==m['new_formal_executions_recorded']==0
assert m['historical_native_total']==m['native_cumulative_total']==8325
assert set(m['components'])=={'service-contract','phase-sensitivity','compute-density'}
assert set(m['component_checks'])==set(m['components'])
def safe(n):
 p=PurePosixPath(n)
 assert p.parts and not p.is_absolute() and '..' not in p.parts
 assert '\\' not in n and all(':' not in t for t in p.parts)
 return p
def verify(b,r):
 assert len(b)==r['bytes'] and hashlib.sha256(b).hexdigest()==r['sha256'],r['path']
 if 'git_blob_sha1' in r:
  assert hashlib.sha1(b'blob '+str(len(b)).encode('ascii')+b'\0'+b).hexdigest()==r['git_blob_sha1']
assert {r['path'] for r in m['files']}=={'.gitattributes','README.md','replay.py'}|set(m['archive_parts'])
for r in m['files']:
 n=safe(r['path']);assert len(n.parts)==1;verify((base/n).read_bytes(),r)
checks=[]
with tempfile.TemporaryDirectory(prefix='hush-offline-evidence-') as tmp:
 root=Path(tmp)
 assembled=root/'reporting-inputs.zip'
 with assembled.open('wb') as output:
  for name in m['archive_parts']:
   assert len(safe(name).parts)==1
   output.write((base/name).read_bytes())
 assert assembled.stat().st_size==m['archive_bytes']
 assert hashlib.sha256(assembled.read_bytes()).hexdigest()==m['archive_sha256']
 with zipfile.ZipFile(assembled) as z:
  assert z.testzip() is None
  assert len(z.namelist())==len(set(z.namelist()))
  assert sorted(z.namelist())==sorted(r['path'] for r in m['archive_members'])
  records={r['path']:r for r in m['archive_members']}
  execution_count_checks=validate_execution_counts(m['execution_counts'],m['execution_count_bindings'],lambda c,p:z.read(c+'/'+p),m['components'])
  for info in z.infolist():
   n=safe(info.filename)
   assert not info.is_dir() and not stat.S_ISLNK(info.external_attr>>16)
   assert n.parts[0] in m['components']
   d=z.read(info.filename);verify(d,records[info.filename])
   p=root/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(d)
 for component in m['components']:
  assert len(safe(component).parts)==1
  p=root/component
  entry=m['component_checks'][component];script=safe(entry['script']);arguments=entry['arguments']
  assert len(script.parts)==1 and script.suffix=='.py'
  assert isinstance(arguments,list) and all(isinstance(a,str) for a in arguments)
  r=subprocess.run([sys.executable,'-B','-X','utf8',str(p/script),*arguments],cwd=p,
                   capture_output=True,text=True,encoding='utf-8',timeout=600)
  assert r.returncode==0,(component,r.stdout[-1500:],r.stderr[-4000:])
  checks.append({'component':component,'returncode':r.returncode,'stdout':r.stdout})
 for r in m['archive_members']:
  verify((root/safe(r['path'])).read_bytes(),r)
result={'status':'pass','mode':'quick','archive_members_verified':len(m['archive_members']),
 'checks':checks,'scope':'Hash verification and independent saved-result reduction; no CXXRTL executable, compiler, native simulator, cycle model, SAT, synthesis or STA execution',
 'new_native_executions_recorded':0,'historical_native_total':8325,'native_cumulative_total':8325,
 'new_formal_executions_recorded':0,'execution_counts':m['execution_counts'],'execution_count_checks':execution_count_checks,'cxxrtl_executions_during_replay':0,
 'new_source_cycle_model_executions_recorded':m['new_source_cycle_model_executions_recorded'],
 'packaged_member_bytes_unchanged_after_checks':True,'native_executions_during_replay':0,
 'earlier_index_commit':m['earlier_index_commit']}
if args.output:
 assert not args.output.exists();args.output.mkdir(parents=True)
 (args.output/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(json.dumps(result,indent=2))
