"""Verify frozen bit-composition and tick-enabled receiver evidence."""
from pathlib import Path, PurePosixPath
import argparse, hashlib, json, subprocess, sys, tempfile, zipfile

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--quick',action='store_true')
    ap.add_argument('--output',type=Path)
    args=ap.parse_args();base=Path(__file__).resolve().parent
    manifest=json.loads((base/'MANIFEST.json').read_text(encoding='utf-8'))
    for row in manifest['files']:
        data=(base/row['path']).read_bytes()
        assert len(data)==row['bytes'] and hashlib.sha256(data).hexdigest()==row['sha256']
    with tempfile.TemporaryDirectory(prefix='hush-composition-check-') as tmp:
        root=Path(tmp)
        with zipfile.ZipFile(base/'reporting-inputs.zip') as z:
            assert len(z.namelist())==len(set(z.namelist()))
            assert sorted(z.namelist())==sorted(r['path'] for r in manifest['archive_members'])
            for row in manifest['archive_members']:
                n=PurePosixPath(row['path'])
                assert not n.is_absolute() and '..' not in n.parts and '\\' not in row['path']
                assert all(':' not in part for part in n.parts)
                data=z.read(row['path'])
                assert len(data)==row['bytes'] and hashlib.sha256(data).hexdigest()==row['sha256']
                path=root/n;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(data)
        run=subprocess.run([sys.executable,'-B','-X','utf8',str(root/'composition/check.py')],
                           cwd=root/'composition',capture_output=True,text=True,encoding='utf-8')
        assert run.returncode==0,(run.stdout+run.stderr)[-6000:]
        result={'status':'pass','mode':'quick','archive_members_verified':len(manifest['archive_members']),
                'checks':[{'script':'composition/check.py','returncode':run.returncode,'stdout':run.stdout}],
                'scope':'Evidence integrity and independent frozen waveform replay; no new SAT execution',
                'new_native_executions':0,'new_SAT_or_mapping_runs':0,
                'prior_index_commit':manifest['earlier_index_commit']}
        if args.output:
            assert not args.output.exists(),'Choose a fresh output directory'
            args.output.mkdir(parents=True)
            (args.output/'component.log').write_text(run.stdout+run.stderr,encoding='utf-8')
            (args.output/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
        print(json.dumps(result,indent=2))
if __name__=='__main__':main()
