"""Compile deliberately altered DUT copies; originals are only read.

This probes four specified semantic errors. Rejection is sensitivity evidence,
not a claim that mutation testing proves implementation correctness.
"""
from pathlib import Path
import hashlib,json,shutil,subprocess,sys

HERE=Path(__file__).resolve().parent
SOURCE=HERE/'portable-source'
ROOT=HERE.parent.parents[3]
OUT=HERE/'mutation-tests-01'
PY=Path(sys.executable)
YOSYS=ROOT/'.tools/run_iscas_yosys.py'
ZIG=ROOT/'.tools/zig-0.14.1/zig-x86_64-windows-0.14.1/zig.exe'
INCLUDE=ROOT/'.tools/iscas-rtl-20261023/yowasp_yosys/share/include/backends/cxxrtl/runtime'

def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    OUT.mkdir(exist_ok=False)
    text=(SOURCE/'receiver.v').read_text(encoding='utf-8')
    begin=text.index('   if(wu[0]')
    end=text.index('   if(expiryphase==cfgphi)')
    loadblock=text[begin:end]
    decrementend=text.index('   // Source polls A then B.')
    reversed_priority=text[:begin]+text[end:decrementend]+loadblock+text[decrementend:]
    a=text.index('   if(pollen[0]')
    b=text.index('   if(pollen[1]')
    c=text.index('   if(cachephase==0)')
    reversed_source=text[:a]+text[b:c]+text[a:b]+text[c:]
    mutants={
        '01-decrement-before-WU':reversed_priority,
        '02-B-before-A':reversed_source,
        '03-missing-cancel-enable':text.replace('evcancel[qowner0]=enabled[qowner0];enabled[qowner0]=0;', 'evcancel[qowner0]=enabled[qowner0];'),
        '04-live-data-emission':text.replace('emitbyte=byteone;rone=0;', 'emitbyte=ownerone?datab:dataa;rone=0;')}
    report={'scope':'Sensitivity probes only, all changed RTL copies stay under independent/mutation-tests-01. No baseline result is replaced.',
            'source_sha256':sha(SOURCE/'receiver.v'),'mutants':[]}
    for name,rtl in mutants.items():
        assert rtl!=text
        dest=OUT/name
        dest.mkdir()
        (dest/'receiver.v').write_text(rtl,encoding='utf-8')
        shutil.copyfile(SOURCE/'driver.cpp',dest/'driver.cpp')
        item={'name':name,'mutated_source_sha256':sha(dest/'receiver.v'),'commands':[]}
        stages=[('synthesis',[str(PY),'-B','-X','utf8',str(YOSYS),'-p','read_verilog receiver.v; hierarchy -check -top receiver; prep -top receiver; check -assert; write_cxxrtl netlist.cpp']),
                ('compile',[str(ZIG),'c++','-std=c++17','-O3','-UNDEBUG','-I',str(INCLUDE),'driver.cpp','-o','simulate.exe']),
                ('simulation',[str(dest/'simulate.exe'),str(HERE/'fresh-replay-01'/'vectors'),str(dest)])]
        for stage,cmd in stages:
            proc=subprocess.run(cmd,cwd=dest,capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=600)
            (dest/(stage+'.stdout.log')).write_text(proc.stdout,encoding='utf-8')
            (dest/(stage+'.stderr.log')).write_text(proc.stderr,encoding='utf-8')
            item['commands'].append(dict(stage=stage,argv=cmd,returncode=proc.returncode))
            if stage!='simulation': assert proc.returncode==0,(name,stage,proc.stderr)
            else:
                assert proc.returncode!=0,(name,'unexpected mutant acceptance')
                item['actual_rejection']=(dest/'SIMULATION_FAILURE.txt').read_text().strip()
        item['netlist_sha256']=sha(dest/'netlist.cpp')
        item['executable_sha256']=sha(dest/'simulate.exe')
        item['status']='REJECTED_BY_UNCHANGED_FROZEN_DRIVER'
        report['mutants'].append(item)
        (OUT/'MUTATION_RESULTS.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
        print(name,item['actual_rejection'],flush=True)
    report['status']='ALL_FOUR_SEMANTIC_MUTANTS_REJECTED'
    (OUT/'MUTATION_RESULTS.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')

if __name__=='__main__': main()
