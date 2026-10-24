"""Reproduce retrospective frontier, store normalization and posthoc transfer tables."""
from pathlib import Path
import argparse,subprocess,sys
ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path);a=ap.parse_args();F=Path(__file__).resolve().parent;O=(a.out or F).resolve();O.mkdir(parents=True,exist_ok=True)
for name in ['frontier.py','normalize.py','transfer.py']:subprocess.run([sys.executable,'-B','-X','utf8',str(F/name),'--out',str(O)],check=True)
