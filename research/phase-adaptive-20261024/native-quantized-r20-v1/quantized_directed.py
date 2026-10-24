"""Directed native Cache receiver harness; bus/CPU consistency is a separate smoke.

Synthetic fills and injected WUs exercise the compiled Cache methods. This is
not an independent proof of the private simulator or its four-client service.
"""
import argparse,json
from pathlib import Path
import m5
from m5.objects import *
ap=argparse.ArgumentParser();ap.add_argument('--case',type=int,required=True);ap.add_argument('--period',type=int,default=10);ap.add_argument('--summary',required=True);a=ap.parse_args()
s=System(mem_ranges=[AddrRange('64KiB')],mem_mode='timing',cache_line_size=64)
s.voltage_domain=VoltageDomain();s.clk_domain=SrcClockDomain(clock='1GHz',voltage_domain=s.voltage_domain)
s.bus=CoherentXBar(width=16,frontend_latency=1,forward_latency=1,response_latency=1,snoop_response_latency=1,point_of_coherency=True,hush_l1_update_terminator=True,hush_protocol_mode='hush',hush_num_cores=1,hush_request_service_cycles=4,hush_update_service_cycles=10,hush_response_service_cycles=50)
s.cache=Cache(size='1KiB',assoc=2,tag_latency=1,data_latency=1,response_latency=1,mshrs=8,tgts_per_mshr=8,write_buffers=8,hush_c1_enabled=True,hush_protocol_mode='hush',hush_theta_cycles=4*a.period,hush_quantized_period=a.period,hush_quantized_phi=0,hush_quantized_trace=True)
s.bus.hush_peer_caches=[s.cache];s.cache.mem_side=s.bus.cpu_side_ports;s.system_port=s.cache.cpu_side
s.mem=SimpleMemory(range=s.mem_ranges[0],latency='50ns');s.mem.port=s.bus.mem_side_ports
Root(full_system=False,system=s);m5.instantiate()
c=s.cache;checks=[];A=0x1000;B=0x1040;C=0x1080
def q(op,x=0,y=0,z=0):return int(c.hushDebugQuantized(op,x,y,z))
def run(t):
 delta=t*1000-int(m5.curTick());assert delta>=0
 if delta:m5.simulate(delta)
def ck(label,got,expected):
 checks.append({'label':label,'got':got,'expected':expected});assert got==expected,(label,got,expected)
def fill(addr,val=17):ck('fill',q('fill',addr,val),1)
if a.case==1:
 for r,e in [(10,10),(11,20),(19,20)]:ck('K1 zero-distance '+str(r),q('deadline',r,1),e)
 fill(A);q('load',1);q('schedwu',A,10,77);q('schedcapture',A,10);run(10)
 ck('native zero-distance expiry',q('valid',A),0);ck('zero-distance capture misses',q('lastcapture'),256)
elif a.case==2:
 if a.period==10:
  for r,e in [(10,40),(11,50)]:ck('K4 '+str(r),q('deadline',r,4),e)
 else:
  for r,e in [(256,16512),(257,16640)]:ck('K128 '+str(r),q('deadline',r,128),e)
 fill(A);load,received,deadline=(4,10,40) if a.period==10 else (128,256,16512)
 q('load',load);q('schedwu',A,received,77);run(received);ck('compiled native actual arm',q('deadlineof',A),deadline)
 run(deadline-1);ck('line remains before expiry',q('valid',A),1);run(deadline);ck('actual exact expiry',q('valid',A),0)
elif a.case in [3,4]:
 fill(A);old,new=(1,4) if a.case==3 else (4,1);q('load',old);q('schedwu',A,1,34)
 run(4);c.hushSetPhaseTimeout(new*a.period)
 run(5);ck('phase write preserves old arm',q('deadlineof',A),10 if old==1 else 40)
 q('schedwu',A,6,51);run(6);ck('new WU prospective reload',q('deadlineof',A),40 if new==4 else 10)
elif a.case==5:
 fill(A);q('load',4);q('schedwu',A,1,34);q('schedwu',A,10,77);q('schedcapture',A,10)
 run(9);c.hushSetPhaseTimeout(a.period)
 run(10);ck('config-cycle capture precedes held WU',q('lastcapture'),34)
 run(11);ck('held WU accepts next cycle',q('deadlineof',A),20);ck('held changing payload',q('capture',A),77)
elif a.case==6:
 for x in [A,B,C]:fill(x)
 q('load',1)
 for x in [A,B,C]:q('schedwu',x,1,34)
 q('schedconfig',4,5);q('schedcapture',A,9);q('schedcapture',B,10);q('schedwu',C,10,77)
 run(9);ck('snapshot captured before expiry',q('lastcapture'),34)
 run(10);ck('capture on expiry misses',q('lastcapture'),256);ck('same-tick WU outruns stale expiry',q('deadlineof',C),40)
 ck('buffered line timer disabled',q('timer',A),0);ck('same-tick new payload',q('capture',C),77)
elif a.case==7:
 fill(A);fill(B);q('load',1);q('schedwu',A,1,34);run(2);q('load',255);q('schedwu',B,3,51);q('schedconfig',1,5)
 run(5);ck('old finite unaffected',q('deadlineof',A),10);ck('old infinity unaffected',q('timer',B),1)
 assert q('deadlineof',B)>10**12
 q('schedconfig',255,6);run(6);ck('finite-to-infinity keeps old arm',q('deadlineof',A),10);q('schedwu',A,7,77);run(20)
 ck('subsequent WU uses infinity',q('valid',A),1);ck('infinity survives tick',q('valid',B),1);ck('configuration does not allocate',q('valid',0x1100),0)
 c.hushSetPhaseTimeout(a.period);q('schedwu',B,22,88);run(21)
 assert q('deadlineof',B)>10**12
 run(22);ck('subsequent WU leaves infinity using new finite load',q('deadlineof',B),30)
 run(30);ck('new finite arm expires',q('valid',B),0);ck('other infinity remains',q('valid',A),1)
elif a.case==8:
 B=A+512;C=A+1024;D=A+1536;fill(A);fill(B);q('load',1);q('schedwu',B,1,34);run(10);ck('competitor expired',q('valid',B),0)
 fill(C,51);ck('invalid hole before live eviction',q('valid',A),1);q('load',128);q('arm',C);ck('fill snapshot cancels armed timer',q('fillcapture',C,51),51);ck('fill capture timer disabled',q('timer',C),0)
 q('load',128);q('schedwu',A,11,77);q('schedwu',A+2048,11,88);run(11);fill(D,99)
 ck('WU does not allocate',q('valid',A+2048),0);ck('WU does not change LRU',q('valid',A),0);ck('newer fill retained',q('valid',C),1)
else:raise ValueError(a.case)
out={'case':a.case,'period':a.period,'all_passed':True,'checks':checks,'scope':'compiled native Cache receiver directed debug harness; no full-bus claim'}
Path(a.summary).write_text(json.dumps(out,indent=2)+'\n');print('HUSH_Q_DIRECTED_PASS '+json.dumps(out))
