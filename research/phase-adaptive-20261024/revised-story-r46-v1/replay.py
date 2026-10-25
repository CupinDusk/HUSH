"""Check saved R46 evidence. No new simulation or compilation is performed."""
from pathlib import Path,PurePosixPath
import argparse,hashlib,json,stat,subprocess,sys,tempfile,zipfile

def safe(name):
    p=PurePosixPath(name)
    assert p.parts and not p.is_absolute() and '..' not in p.parts
    assert '\\' not in name and all(':' not in x for x in p.parts)
    return p

def verify(data,record):
    assert len(data)==record['bytes'] and hashlib.sha256(data).hexdigest()==record['sha256'],record['path']

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--quick',action='store_true');args=ap.parse_args()
    B=Path(__file__).resolve().parent
    m=json.loads((B/'MANIFEST.json').read_text(encoding='utf-8'))
    assert m['schema']=='hush-r46-portable-v1'
    assert {r['path'] for r in m['files']}=={'.gitattributes','README.md','replay.py'}|set(m['archive_parts'])
    for r in m['files']:
        assert len(safe(r['path']).parts)==1
        verify((B/r['path']).read_bytes(),r)
    checks=[]
    with tempfile.TemporaryDirectory(prefix='hush-r46-evidence-') as tmp:
        root=Path(tmp)
        combined=root/'reporting-inputs.zip'
        with combined.open('wb') as output:
            for name in m['archive_parts']:
                assert len(safe(name).parts)==1
                output.write((B/name).read_bytes())
        assert combined.stat().st_size==m['archive_bytes'] and hashlib.sha256(combined.read_bytes()).hexdigest()==m['archive_sha256']
        with zipfile.ZipFile(combined) as z:
            assert z.testzip() is None and len(z.namelist())==len(set(z.namelist()))
            assert set(z.namelist())=={r['path'] for r in m['archive_members']}
            records={r['path']:r for r in m['archive_members']}
            for info in z.infolist():
                n=safe(info.filename);assert not info.is_dir() and not stat.S_ISLNK(info.external_attr>>16)
                assert n.parts[0] in m['components']
                data=z.read(info.filename);verify(data,records[info.filename])
                p=root/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(data)
        for name,entry in m['components'].items():
            assert len(safe(name).parts)==1
            p=root/name
            summary=json.loads((p/'SUMMARY.json').read_text(encoding='utf-8'))
            ledger=json.loads((p/'LEDGER.json').read_text(encoding='utf-8'))
            assert summary['execution_counts']==ledger['execution_counts']==entry['execution_counts']
            assert len(safe(entry['script']).parts)==1 and entry['script'].endswith('.py')
            assert entry['arguments']==['--quick']
            r=subprocess.run([sys.executable,'-B','-X','utf8',str(p/entry['script']),*entry['arguments']],cwd=p,capture_output=True,text=True,encoding='utf-8',timeout=600)
            assert r.returncode==0,(name,r.stdout[-2000:],r.stderr[-3000:])
            checks.append({'component':name,'returncode':0,'stdout':r.stdout})
        for record in m['archive_members']:verify((root/safe(record['path'])).read_bytes(),record)
    out={'status':'pass','archive_members_verified':len(m['archive_members']),'checks':checks,'recorded_scientific_execution_counts':m['execution_counts'],'new_scientific_executions_during_replay':0,'scope':'Saved source/guard/result checks only; no CPU or CXXRTL simulation, compilation, synthesis, STA or formal-tool execution'}
    print(json.dumps(out,ensure_ascii=False))

if __name__=='__main__':main()
