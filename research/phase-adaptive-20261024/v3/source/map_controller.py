"""Portable matched mapping. Usage: python map_controller.py LIBRARY YOSYS.

Requires native Yosys with ABC, and Nangate45 typical library from the
pinned upstream revision in LIBRARY_SOURCE.json. Results are prelayout.
"""
from pathlib import Path
import subprocess,tempfile,shutil,json,sys,os,re,hashlib
here=Path(__file__).resolve().parent
lib=Path(sys.argv[1]).resolve();yosys=Path(sys.argv[2]).resolve()
env=dict(os.environ);env['PATH']=str(yosys.parent)+os.pathsep+str(yosys.parent.parent/'lib')+os.pathsep+env['PATH']
version=subprocess.run([str(yosys),'-V'],env=env,capture_output=True,text=True,check=True).stdout.strip()
rows=[]
with tempfile.TemporaryDirectory(prefix='hush-mapping-') as tmp:
 job=Path(tmp);shutil.copy2(here/'interlocked_timer.v',job/'interlocked_timer.v');shutil.copy2(lib,job/'nangate45.lib')
 (job/'constraints.txt').write_text('set_driving_cell BUF_X1\nset_load 5\n')
 for n in [4,64,512]:
  for top in ['fixed_interlocked_controller','interlocked_timer']:
   command=(f'read_verilog -sv interlocked_timer.v; chparam -set N {n} {top}; '
    f'synth -top {top} -flatten -noabc; dfflibmap -liberty nangate45.lib; '
    f'abc -liberty nangate45.lib -constr constraints.txt; clean; stat -liberty nangate45.lib')
   p=subprocess.run([str(yosys),'-Q','-T','-p',command],cwd=job,env=env,capture_output=True,text=True,timeout=180)
   assert p.returncode==0,p.stderr
   area=re.findall(r'Chip area for module.*?:\s*([\d.]+)',p.stdout)
   timing=re.findall(r'ABC:.*?Area\s*=\s*([\d.]+).*?Delay\s*=\s*([\d.]+)',p.stdout)
   assert area and timing,p.stdout[-2500:]
   rows.append({'lines':n,'top':top,'area_um2':float(area[-1]),'abc_comb_area_um2':float(timing[-1][0]),
    'abc_comb_delay_ps':float(timing[-1][1]),'command':command})
   print(n,top,rows[-1]['area_um2'],rows[-1]['abc_comb_delay_ps'],flush=True)
result={'yosys_version':version,'library_sha256':hashlib.sha256(lib.read_bytes()).hexdigest(),
 'rtl_sha256':hashlib.sha256((here/'interlocked_timer.v').read_bytes()).hexdigest(),
 'conditions':'Nangate45 typical, BUF_X1 input driver, output load5fF; ABC prelayout combinational timing, not STA/signoff; no extracted wires, placement, clock or queues',
 'rows':rows}
(here/'INTERLOCKED_MAPPED_COMPARISON.json').write_text(json.dumps(result,indent=2)+'\n')
expected=here/'expected/INTERLOCKED_MAPPED_COMPARISON.json'
if expected.exists():assert result==json.loads(expected.read_text()),'mapped result differs; check tool and library versions'
