"""Execution-driven x86 HUSH application pilot. See APPLICATION_PILOT_PROTOCOL.md."""
import argparse,json,shlex,hashlib,os
from pathlib import Path
import m5
from m5.objects import System,AddrRange,VoltageDomain,SrcClockDomain,CoherentXBar,L2XBar,Cache,SimpleMemory,Root,Process,SEWorkload,X86TimingSimpleCPU
ap=argparse.ArgumentParser()
ap.add_argument('--cache-size',default='16KiB');ap.add_argument('--cmd',required=True);ap.add_argument('--options',default='');ap.add_argument('--mode',choices=['stock','predictable-wi','hush','wu-of'],default='hush')
ap.add_argument('--schedule',default='512,512,512');ap.add_argument('--config-cycles',type=int,default=0)
ap.add_argument('--max-ticks',type=int,default=50000000000);ap.add_argument('--summary',required=True)
a=ap.parse_args();ts=[int(x) for x in a.schedule.split(',')];assert len(ts)==3 and all(x>0 for x in ts)
assert a.mode=='hush' or len(set(ts))==1
class L1(Cache):
    size=a.cache_size;assoc=2;tag_latency=1;data_latency=1;response_latency=1;mshrs=8;tgts_per_mshr=8;write_buffers=8
enabled=a.mode in ['hush','wu-of']
system=System(cpu=[X86TimingSimpleCPU(cpu_id=i) for i in range(4)],mem_mode='timing',mem_ranges=[AddrRange('1GiB')],cache_line_size=64,exit_on_work_items=True)
system.voltage_domain=VoltageDomain();system.clk_domain=SrcClockDomain(clock='1GHz',voltage_domain=system.voltage_domain)
system.membus=CoherentXBar(width=16,frontend_latency=1,forward_latency=1,response_latency=1,snoop_response_latency=1,
    point_of_coherency=True,hush_trace_metrics=True,hush_l1_update_terminator=enabled,hush_protocol_mode=a.mode,hush_num_cores=4,
    hush_request_service_cycles=4,hush_update_service_cycles=10,hush_response_service_cycles=50)
system.l1s=[L1(hush_c1_enabled=enabled,hush_protocol_mode=a.mode,hush_theta_cycles=ts[0] if a.mode=='hush' else 0,
    hush_trace_metrics=True,hush_core_id=i,hush_num_cores=4,hush_request_service_cycles=4,hush_update_service_cycles=10,hush_response_service_cycles=50) for i in range(4)]
# The core-side coherent merge also sees upward express HUSH snoops. It has
# no HUSH service gate or peer caches; it only routes them to CPU ports.
system.gateways=[L2XBar(hush_l1_update_terminator=enabled,
    hush_protocol_mode='wu-of' if enabled else 'stock',hush_num_cores=4,
    hush_request_service_cycles=0,hush_update_service_cycles=0,
    hush_response_service_cycles=0,hush_trace_metrics=False) for _ in range(4)]
system.membus.hush_peer_caches=system.l1s
system.memory=SimpleMemory(range=system.mem_ranges[0],latency='50ns',bandwidth='12.8GiB/s');system.memory.port=system.membus.mem_side_ports
process=Process(pid=100,executable=str(Path(a.cmd).resolve()),cmd=[str(Path(a.cmd).resolve())]+shlex.split(a.options),cwd=str(Path(a.cmd).resolve().parent))
process.env=['HUSH_CONFIG_CYCLES='+str(a.config_cycles),'HUSH_STAGE_LOADS='+','.join(f'{x:05d}' for x in ts)]
for cpu,b,c in zip(system.cpu,system.gateways,system.l1s):
    cpu.workload=process;cpu.createThreads()
    cpu.icache_port=b.cpu_side_ports;cpu.dcache_port=b.cpu_side_ports;b.mem_side_ports=c.cpu_side;c.mem_side=system.membus.cpu_side_ports
    cpu.mmu.connectWalkerPorts(b.cpu_side_ports,b.cpu_side_ports)
system.system_port=system.membus.cpu_side_ports
for cpu in system.cpu:
    cpu.createInterruptController();cpu.interrupts[0].pio=system.membus.mem_side_ports
    cpu.interrupts[0].int_requestor=system.membus.cpu_side_ports;cpu.interrupts[0].int_responder=system.membus.mem_side_ports
system.workload=SEWorkload.init_compatible(process.executable)
Root(full_system=False,system=system);m5.instantiate()
events=[];roi_start=roi_end=None;cur=ts[0];writes=0;terminal=None;marker_errors=[];stats_dump_count=0;roi_stats_block=None
while int(m5.curTick())<a.max_ticks:
    e=m5.simulate(a.max_ticks-int(m5.curTick()));cause=e.getCause();code=int(e.getCode());tick=int(m5.curTick())
    if cause=='workbegin':
        entry={'id':code,'tick':tick}
        if code==0:
            if roi_start is not None:marker_errors.append('duplicate ROI begin')
            if roi_end is not None:marker_errors.append('ROI begin after end')
            if roi_start is None:
                roi_start=tick;m5.stats.dump();stats_dump_count+=1;m5.stats.reset()
            selected=ts[0]
        elif code in [1,2]:
            if roi_start is None or roi_end is not None:marker_errors.append('phase marker outside ROI')
            selected=ts[code]
        elif code==99:
            if roi_start is None or roi_end is not None:marker_errors.append('missing begin or duplicate end')
            roi_end=tick;selected=None
            m5.stats.dump();roi_stats_block=stats_dump_count;stats_dump_count+=1;m5.stats.reset()
        elif code in [10,11,12,13]:
            selected=None;entry['completed_task']=code-10
        else:raise RuntimeError('Unexpected marker id '+str(code))
        if selected is not None and a.mode=='hush' and selected!=cur:
            for c in system.l1s:c.hushSetPhaseTimeout(selected)
            cur=selected;writes+=4;entry['applied_T_cycles']=selected
        events.append(entry)
        continue
    terminal={'cause':cause,'code':code,'tick':tick};break
m5.stats.dump()
ids=[e['id'] for e in events]
if ids.count(0)!=1 or ids.count(99)!=1 or ids[0:1]!=[0] or ids[-1:]!=[99] or not all(x in [0,1,2,10,11,12,13,99] for x in ids):marker_errors.append('invalid marker sequence')
if not all(p in ids for p in [1,2]):marker_errors.append('missing phase type')
out={'kind':'native_cpu_application_pilot','mode':a.mode,'schedule_cycles':ts,'configuration_stall_cycles':a.config_cycles,
     'command':[Path(a.cmd).name]+shlex.split(a.options),'binary_sha256':hashlib.sha256(Path(a.cmd).read_bytes()).hexdigest(),
     'architecture':'four TimingSimple x86 cores, private unified'+a.cache_size+' 2way caches, continuous expiry, common4-client HUSH service',
     'roi_start_tick':roi_start,'roi_end_tick':roi_end,'roi_ticks':roi_end-roi_start if roi_start is not None and roi_end is not None else None,
     'phase_events':events,'timeout_register_writes':writes,'terminal':terminal,'final_tick':int(m5.curTick()),'marker_errors':marker_errors,'roi_stats_block':roi_stats_block,
     'scope':'source-marker-guided prospective API, not quantized RTL/WCET proof or production CSR; exact configuration-cost model recorded'}
Path(a.summary).write_text(json.dumps(out,indent=2)+'\n')
print('HUSH_APPLICATION='+json.dumps(out))
