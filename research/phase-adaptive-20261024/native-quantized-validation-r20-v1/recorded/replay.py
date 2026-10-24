"""Replay the public native receiver validation data with only Python stdlib."""
from pathlib import Path
import json,gzip,hashlib,argparse
from deadline_oracle import check_case
R=Path(__file__).resolve().parent
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--output',type=Path,default=R/'REPLAY_RESULT.json');a=ap.parse_args()
 manifest=json.loads((R/'FILE_MANIFEST.json').read_text())
 for n,m in manifest.items():
  p=(R/n).resolve();assert p.is_relative_to(R) and p.is_file();raw=p.read_bytes()
  assert len(raw)==m['bytes'] and hashlib.sha256(raw).hexdigest()==m['sha256'],n
 raw=gzip.decompress((R/'NATIVE_RECEIVER_TRACES.json.gz').read_bytes());expected=json.loads((R/'NATIVE_ORACLE_AUDIT.json').read_text());assert hashlib.sha256(raw).hexdigest()==expected['native_trace_sha256']
 rows=[check_case(c) for c in json.loads(raw)['cases']];assert rows==expected['cases'] and all(r['pass'] for r in rows)
 d=json.loads((R/'directed-v2/RESULTS.json').read_text())['rows'];assert len(d)==9 and all(r['returncode']==0 and r['summary']['all_passed'] for r in d)
 f=json.loads((R/'freshness-v2/RESULTS.json').read_text());assert f['cases']==f['valid']==24 and f['checks']==168480 and f['stale']==0
 p=json.loads((R/'pipeline-smoke-v2/RESULT.json').read_text());assert p['returncode']==0 and p['test_pass'] and not p['summary']['marker_errors']
 b=json.loads((R/'bus-directed-v4/RESULTS.json').read_text())['rows'];assert len(b)==4 and all(r['pass'] for r in b)
 old=json.loads((R/'INVALID_FIRST_OLD_WITNESS.json').read_text());new=json.loads((R/'INVALID_FIRST_NEW_WITNESS.json').read_text());assert old['A_valid_after_two_fills']==0 and new['A_valid_after_two_fills']==1 and old['B_valid_after_two_fills']==new['B_valid_after_two_fills']==1
 out={'all_passed':True,'files_verified':len(manifest),'trace_cases':len(rows),'timer_arms_checked':sum(r['arms'] for r in rows),'expiry_generations_checked':sum(r['expiries'] for r in rows),'native_receiver_processes':len(d),'freshness_cases':24,'version_checks':f['checks'],'stale_versions':f['stale'],'pipeline_smoke':True,'controlled_bus_cases':len(b),'invalid_first_before_after_confirmed':True,'scope':'recorded native data and independent tick oracle replay; private native simulator source/binary are not included'}
 a.output.write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps(out,indent=2))
if __name__=='__main__':main()
