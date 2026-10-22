"""Reproduce the corrected current public/model checks in a fresh folder."""
from pathlib import Path
import argparse,hashlib,json,subprocess,sys
HERE=Path(__file__).resolve().parent
def main():
    p=argparse.ArgumentParser();p.add_argument('--zig',required=True);a=p.parse_args()
    m=json.loads((HERE/'MANIFEST.json').read_text(encoding='utf-8'))
    for n,h in m['files'].items():assert hashlib.sha256((HERE/n).read_bytes()).hexdigest()==h,n
    reports={}
    jobs=[('serial_source_only.py','SERIAL_CLIENT_RESULTS.json','SERIAL_SOURCE_CHECK.json'),
          ('read_boundary.py','READ_BOUNDARY_RESULTS.json','READ_BOUNDARY_RESULTS.json'),
          ('periodic_poll.py','PERIODIC_POLL_RESULTS.json','PERIODIC_POLL_RESULTS.json'),
          ('check_new_comparisons.py','NEW_COMPARISONS.json','NEW_COMPARISONS.json'),
          ('mixed_poll.py','MIXED_POLL_RESULTS.json','MIXED_POLL_RESULTS.json'),
          ('joint_witness.py','JOINT_WITNESS_RESULTS.json','JOINT_WITNESS_RESULTS.json'),
          ('r20_interface.py','R20_INTERFACE_RESULTS.json','R20_INTERFACE_RESULTS.json'),
          ('r21_periods.py','R21_PERIOD_RESULTS.json','R21_PERIOD_RESULTS.json'),
          ('r21_lift.py','R21_LIFT_RESULTS.json','R21_LIFT_RESULTS.json'),
          ('r22_handoff.py','R22_HANDOFF_RESULTS.json','R22_HANDOFF_RESULTS.json'),
          ('r23_canonical.py','R23_CANONICAL_RESULTS.json','R23_CANONICAL_RESULTS.json'),
          ('variable_latency.py','VARIABLE_LATENCY_RESULTS.json','VARIABLE_LATENCY_RESULTS.json'),
          ('r26_remod.py','R26_REMOD_RESULTS.json','R26_REMOD_RESULTS.json'),
          ('endpoint_check.py','R28_ENDPOINT_RESULTS.json','R28_ENDPOINT_RESULTS.json'),
          ('endpoint_family_check.py','R30_PRODUCER_FAMILY_RESULTS.json','R30_PRODUCER_FAMILY_RESULTS.json'),
          ('branch_endpoint_check.py','R31_BRANCH_RESULTS.json','R31_BRANCH_RESULTS.json'),
          ('sparse_canonical_check.py','R32_SPARSE_RESULTS.json','R32_SPARSE_RESULTS.json'),
          ('multiphase_endpoint_check.py','R34_MULTIPHASE_RESULTS.json','R34_MULTIPHASE_RESULTS.json'),
          ('family_aggregate_check.py','R35_FAMILY_AGGREGATE_RESULTS.json','R35_FAMILY_AGGREGATE_RESULTS.json')]
    for script,report,expected in jobs:
        flags=['--zig',a.zig] if script in ['serial_source_only.py','periodic_poll.py','mixed_poll.py','variable_latency.py','endpoint_check.py','endpoint_family_check.py','branch_endpoint_check.py','multiphase_endpoint_check.py'] else []
        r=subprocess.run([sys.executable,'-B','-X','utf8',str(HERE/'analysis'/script),*flags],capture_output=True,text=True,timeout=600)
        (HERE/(script+'.log')).write_text(r.stdout+'\n'+r.stderr,encoding='utf-8');assert r.returncode==0,r.stderr
        actual=json.loads((HERE/'analysis'/report).read_text(encoding='utf-8'))
        frozen=json.loads((HERE/'expected'/expected).read_text(encoding='utf-8'))
        if script=='serial_source_only.py':assert {n:actual[n] for n in frozen}==frozen
        else:
            actual.pop('binary_sha256',None);frozen.pop('binary_sha256',None)
            if script=='joint_witness.py':
                fresh=hashlib.sha256((HERE/'analysis/MIXED_POLL_RESULTS.json').read_bytes()).hexdigest()
                assert actual.pop('mixed_source_result_sha256')==fresh
                assert frozen.pop('mixed_source_result_sha256')==hashlib.sha256((HERE/'expected/MIXED_POLL_RESULTS.json').read_bytes()).hexdigest()
            if script in ['r21_periods.py','r21_lift.py']:
                fresh=hashlib.sha256((HERE/'analysis/MIXED_POLL_RESULTS.json').read_bytes()).hexdigest()
                assert actual.pop('existing_mixed_results_sha256')==fresh
                assert frozen.pop('existing_mixed_results_sha256')==hashlib.sha256((HERE/'expected/MIXED_POLL_RESULTS.json').read_bytes()).hexdigest()
            if script=='r22_handoff.py':
                assert actual.pop('input_lift_results_sha256')==hashlib.sha256((HERE/'analysis/R21_LIFT_RESULTS.json').read_bytes()).hexdigest()
                assert frozen.pop('input_lift_results_sha256')==hashlib.sha256((HERE/'expected/R21_LIFT_RESULTS.json').read_bytes()).hexdigest()
            if script=='r23_canonical.py':
                for field,report in [('input_lift_sha256','R21_LIFT_RESULTS.json'),('input_old_handoff_sha256','R22_HANDOFF_RESULTS.json')]:
                    assert actual.pop(field)==hashlib.sha256((HERE/'analysis'/report).read_bytes()).hexdigest()
                    assert frozen.pop(field)==hashlib.sha256((HERE/'expected'/report).read_bytes()).hexdigest()
            if script=='r26_remod.py':
                assert actual.pop('input_mixed_sha256')==hashlib.sha256((HERE/'analysis/MIXED_POLL_RESULTS.json').read_bytes()).hexdigest()
                assert frozen.pop('input_mixed_sha256')==hashlib.sha256((HERE/'expected/MIXED_POLL_RESULTS.json').read_bytes()).hexdigest()
            if script=='family_aggregate_check.py':
                for field,report in [('input_r30_result_sha256','R30_PRODUCER_FAMILY_RESULTS.json'),('input_r34_result_sha256','R34_MULTIPHASE_RESULTS.json')]:
                    assert actual.pop(field)==hashlib.sha256((HERE/'analysis'/report).read_bytes()).hexdigest()
                    assert frozen.pop(field)==hashlib.sha256((HERE/'expected'/report).read_bytes()).hexdigest()
            assert actual==frozen,script
        reports[script]='PASS'
    result={'result':'PASS_V14_ALL_FAMILY_AGGREGATES_AND_ALL_PRIOR_MODELS','input_files_verified':len(m['files']),
            'checks':reports,'new_source_function_execution':True,'native_cache_or_hardware':False,
            'public_release':'NOT_PERFORMED_BY_THIS_LOCAL_RUN'}
    (HERE/'CURRENT_RESULTS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps(result))
if __name__=='__main__':main()
