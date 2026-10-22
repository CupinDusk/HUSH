"""Fill only cycle-witness coverage after full-prefix witnesses; no retuning."""
from pathlib import Path
import hashlib,json,math
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 out=HERE/'cycle-supplement-01';out.mkdir(exist_ok=False);bound=[HERE/'analysis-01/RELATIONS.json',HERE/'SUPPLEMENT_03_CYCLE_WITNESS_COVERAGE.md',Path(__file__)]
 (out/'PREGENERATION_BINDING.json').write_text(json.dumps({str(p.relative_to(HERE)):sha(p) for p in bound},indent=2)+'\n')
 rel=json.loads(bound[0].read_text());(out/'RELATIONS.json').write_text(json.dumps(rel,indent=2)+'\n');rec=rel['records'][7];assert rec['case']==7 and rec['entry']==37 and rec['cycle_entry_empty'];cfg=rec['configuration'];d=rec['period'];entry=rec['entry'];pol=[]
 for P in range(1,4*cfg['p']+1):
  m=math.gcd(P,d)
  for phi in range(P):
   w=min((s+n*d+1+(phi-s-n*d-1)%P-h-n*d,s+n*d,l['line'],c+n*d,h+n*d,n) for l in rec['lines'] for s,c,h in l['cycle'] for n in range(P//m))
   base,s,j,c,h,n=w
   for K in range(1,17):
    E=s+1+(phi-s-1)%P+(K-1)*P;pol.append([len(pol),7,K,P,phi,j,s,c,h,s+1,entry+n*d,n,E-h,E])
 assert len(pol)==6496
 with (out/'policies.txt').open('w',newline='\n') as f:
  f.write(str(len(pol))+'\n')
  for row in pol:f.write(' '.join(map(str,row))+'\n')
 (out/'SCOPE.json').write_text(json.dumps({'scope':'Cycle-only finite witnesses for all6496 case7 policies; not full admission counts. Original123616 other-controller witnesses are cycle minima already.','full_admission_results_unchanged':True,'queries':len(pol),'input_sha256':sha(out/'policies.txt')},indent=2)+'\n')
 print('Generated6496 cycle-only supplemental witnesses, original full admissions unchanged.')
if __name__=='__main__':main()
