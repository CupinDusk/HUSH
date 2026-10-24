import argparse

import m5
from m5.objects import *


SCENARIO_MODES = {
    **{f"C1-S{i}": "hush" for i in range(1, 8)},
    "C1-S8": "stock",
    **{f"FM-F{i}": "wu-of" for i in range(1, 5)},
    "FEX-1": "wu-of",
    "PA-UP": "hush",
    "PA-DOWN": "hush",
    "HT-T1": "hush",
    "HT-T2": "hush",
    "PT-P1": "pendulum-star",
    "PT-P2": "pendulum-star",
    "AR-R1": "predictable-wi",
    "AR-R2": "predictable-wi",
    "BD-B1": "wu-of",
    "BD-B2": "predictable-wi",
    "BD-B3": "hush",
}
SCENARIOS = tuple(SCENARIO_MODES)
MODES = (
    "stock",
    "predictable-wi",
    "pendulum-star",
    "wu-o",
    "wu-of",
    "hush",
)

parser = argparse.ArgumentParser(description="Directed classic HUSH C1 tests")
parser.add_argument("--scenario", choices=SCENARIOS, required=True)
parser.add_argument("--mode", choices=MODES)
parser.add_argument("--hush-c1", choices=("on", "off"), default="on")
parser.add_argument("--timer-period", type=int, default=128)
parser.add_argument("--tick-phase", type=int, default=0)
parser.add_argument("--theta-cycles", type=int, default=20)
parser.add_argument("--max-ticks", type=int, default=2_000_000)
args = parser.parse_args()
expected_mode = SCENARIO_MODES[args.scenario]
mode = args.mode or expected_mode
if mode != expected_mode:
    parser.error(
        f"{args.scenario} requires mode {expected_mode}, got {mode}"
    )
if args.theta_cycles <= 0:
    parser.error("--theta-cycles must be positive")


def run_stock_default_off():
    """Reproduce tests/gem5/memory/memtest-run.py with explicit guards."""

    m5.util.addToPath("../")
    from common.Caches import L1Cache, L2Cache

    cpus = [MemTest(max_loads=1e5, progress_interval=1e4) for _ in range(8)]
    system = System(
        cpu=cpus,
        physmem=SimpleMemory(),
        membus=SystemXBar(
            hush_l1_update_terminator=False,
            hush_protocol_mode="stock",
        ),
    )
    system.voltage_domain = VoltageDomain()
    system.clk_domain = SrcClockDomain(
        clock="1GHz", voltage_domain=system.voltage_domain
    )
    system.cpu_clk_domain = SrcClockDomain(
        clock="2GHz", voltage_domain=system.voltage_domain
    )
    system.toL2Bus = L2XBar(
        clk_domain=system.cpu_clk_domain,
        hush_l1_update_terminator=False,
        hush_protocol_mode="stock",
    )
    system.l2c = L2Cache(
        clk_domain=system.cpu_clk_domain,
        size="64KiB",
        assoc=8,
        hush_c1_enabled=False,
        hush_protocol_mode="stock",
    )
    system.l2c.cpu_side = system.toL2Bus.mem_side_ports
    system.l2c.mem_side = system.membus.cpu_side_ports

    for cpu in cpus:
        cpu.clk_domain = system.cpu_clk_domain
        cpu.l1c = L1Cache(
            size="32KiB",
            assoc=4,
            hush_c1_enabled=False,
            hush_protocol_mode="stock",
        )
        cpu.l1c.cpu_side = cpu.port
        cpu.l1c.mem_side = system.toL2Bus.cpu_side_ports

    system.system_port = system.membus.cpu_side_ports
    system.physmem.port = system.membus.mem_side_ports
    root = Root(full_system=False, system=system)
    root.system.mem_mode = "timing"
    m5.instantiate()
    event = m5.simulate()
    if event.getCause() != "maximum number of loads reached":
        raise RuntimeError(f"C1-S8 unexpected exit: {event.getCause()}")
    print("HUSH_C1_PASS scenario=C1-S8 stock_default_off=1")


if args.scenario == "C1-S8":
    # The default-off witness is the frozen stock topology, not the no-L2
    # directed topology used by enabled C1 scenarios.
    run_stock_default_off()
else:
    enabled = mode in ("wu-o", "wu-of", "hush")
    service_enabled = True
    if (args.hush_c1 == "on") != enabled:
        parser.error(
            f"--hush-c1 must be {'on' if enabled else 'off'} for {mode}"
        )

    class HushL1D(Cache):
        size = "1KiB"
        assoc = 1
        tag_latency = 1
        data_latency = 1
        response_latency = 1
        mshrs = 8
        tgts_per_mshr = 8
        write_buffers = 8

    system = System(mem_ranges=[AddrRange("64KiB")], cache_line_size=64)
    system.voltage_domain = VoltageDomain()
    system.clk_domain = SrcClockDomain(
        clock="1GHz", voltage_domain=system.voltage_domain
    )
    system.membus = CoherentXBar(
        width=16,
        frontend_latency=1,
        forward_latency=1,
        response_latency=1,
        snoop_response_latency=1,
        point_of_coherency=True,
        hush_l1_update_terminator=enabled,
        hush_protocol_mode=mode,
        hush_num_cores=4,
        hush_request_service_cycles=4 if service_enabled else 0,
        hush_update_service_cycles=10 if service_enabled else 0,
        hush_response_service_cycles=50 if service_enabled else 0,
    )
    system.physmem = SimpleMemory(
        range=system.mem_ranges[0], latency="50ns"
    )
    system.l1s = [
        HushL1D(
            hush_quantized_period=args.timer_period,
            hush_quantized_phi=args.tick_phase,
            hush_quantized_trace=True,
            hush_c1_enabled=enabled,
            hush_protocol_mode=mode,
            hush_theta_cycles=(
                args.theta_cycles if mode in ("hush", "pendulum-star") else 0
            ),
        )
        for _ in range(4)
    ]
    system.membus.hush_peer_caches = system.l1s
    system.tester = HushClassicTester(
        scenario=args.scenario,
        caches=system.l1s,
        xbar=system.membus,
        theta_cycles=args.theta_cycles,
        max_ticks=args.max_ticks,
    )

    system.tester.clk_domain = SrcClockDomain(clock="20GHz", voltage_domain=system.voltage_domain)

    for l1 in system.l1s:
        system.tester.ports = l1.cpu_side
        l1.mem_side = system.membus.cpu_side_ports

    system.system_port = system.membus.cpu_side_ports
    system.physmem.port = system.membus.mem_side_ports
    root = Root(full_system=False, system=system)
    root.system.mem_mode = "timing"
    m5.instantiate()
    event = m5.simulate(args.max_ticks)
    expected_cause = (
        "HUSH classic C1 scenario passed"
        if args.scenario.startswith("C1-")
        else "HUSH classic five-mode scenario passed"
    )
    if event.getCause() != expected_cause:
        raise RuntimeError(
            f"{args.scenario} unexpected exit: {event.getCause()}"
        )
