"""Text-only packaging wrapper; recorded scientific replay is unchanged."""
from pathlib import Path
import argparse,json,hashlib,subprocess,sys
from safe_decode import checked_path,decode
R=Path(__file__).resolve().parent
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--output',type=Path,default=R/'REPLAY_RESULT.json');a=ap.parse_args()
 for rel,m in json.loads((R/'TEXT_INPUT_MANIFEST.json').read_text()).items():
  b=checked_path(rel).read_bytes()
  if len(b)!=m['bytes'] or hashlib.sha256(b).hexdigest()!=m['sha256']:raise ValueError('text input mismatch: '+rel)
 decode()
 p=subprocess.run([sys.executable,'-B','-X','utf8',str(R/'recorded/replay.py'),'--output',str(a.output.resolve())],cwd=R/'recorded')
 if p.returncode:raise SystemExit(p.returncode)
if __name__=='__main__':main()
