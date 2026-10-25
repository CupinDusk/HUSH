"""Portable R33 entry: verify exact inputs, then check source/control evidence."""
from pathlib import Path, PurePosixPath
import argparse, hashlib, json, shutil, subprocess, sys, tempfile, zipfile

def digest(p): return hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    mode=ap.add_mutually_exclusive_group()
    mode.add_argument('--quick',action='store_true',help='hash, functional and scientific reduction checks (default)')
    mode.add_argument('--full',action='store_true',help='also repeat registered source simulations; no native gem5 or SAT runs')
    ap.add_argument('--output',type=Path)
    args=ap.parse_args();base=Path(__file__).resolve().parent
    manifest=json.loads((base/'MANIFEST.json').read_text(encoding='utf-8'))
    for row in manifest['files']:
        p=base/row['path'];assert p.stat().st_size==row['bytes'] and digest(p)==row['sha256'],row['path']
    z=base/'reporting-inputs.zip'
    with tempfile.TemporaryDirectory(prefix='hush-r33-') as tmp:
        root=Path(tmp)
        with zipfile.ZipFile(z) as archive:
            assert sorted(archive.namelist())==sorted(r['path'] for r in manifest['archive_members'])
            for row in manifest['archive_members']:
                name=PurePosixPath(row['path'])
                assert not name.is_absolute() and '..' not in name.parts and '\\' not in row['path']
                data=archive.read(row['path'])
                assert len(data)==row['bytes'] and hashlib.sha256(data).hexdigest()==row['sha256'],row['path']
                p=root/name;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(data)
        logs={}
        for name,command in [('source',[sys.executable,'-B','-X','utf8',str(root/'source/check_sources.py'),'--full' if args.full else '--quick']),
                             ('control',[sys.executable,'-B','-X','utf8',str(root/'control/check_v2.py')])]:
            r=subprocess.run(command,cwd=root/name,capture_output=True,text=True,encoding='utf-8')
            logs[name]=r.stdout+r.stderr
            assert r.returncode==0,logs[name][-6000:]
        result={'status':'pass','mode':'full-source-simulation' if args.full else 'quick-hash-functional-reduction',
                'archive_members_verified':len(manifest['archive_members']),
                'source_and_control_checks_pass':True,'new_native_executions':0,'new_SAT_or_mapping_runs':0,
                'quick_is_not_simulation_reexecution':not args.full,
                'earlier_4308_native_records_are_indexed_separately':True}
        if args.output:
            assert not args.output.exists(),'Choose a fresh output directory'
            args.output.mkdir(parents=True)
            for name,log in logs.items():(args.output/(name+'-check.log')).write_text(log,encoding='utf-8')
            (args.output/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
        print(json.dumps(result,indent=2))

if __name__=='__main__':main()
