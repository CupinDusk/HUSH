"""Check service-case envelopes and concrete fresh trace reproduction."""
from pathlib import Path
import hashlib,json
HERE=Path(__file__).resolve().parent
actual=json.loads((HERE/'SERVICE71_DIRECTED_TRACES.json').read_text())
expected=json.loads((HERE/'EXPECTED_SERVICE_TRACES.json').read_text())
assert actual==expected

# Envelope states encode the one-outstanding-writer gate. Configuration may
# defer only a WU completing now, and no phase write issues during a read.
ordinary=[]
for old_private_remaining in [0,1]:
    for other_wu_wait in range(11):
        service=old_private_remaining+other_wu_wait+60
        ordinary.append({'old_private_remaining':old_private_remaining,
            'other_WU_wait':other_wu_wait,'configuration_residual':0,
            'miss_service':60,'completion_from_issue':service})
        assert service<=71
configuration=[{'old_private_remaining':0,'other_WU_wait':0,
    'configuration_residual':1,'miss_service':60,'completion_from_issue':61}]

rows=actual['rows'];collision=rows[2]
event=next(e for e in collision['events'] if e['event']=='configuration_delays_finishing_WU')
issue=next(e for e in collision['events'] if e['event']=='reader_capture_issue' and e['cycle']==event['cycle'])
assert event['private_due'] is None and issue['private_due'] is None
assert event['bus']['kind']=='wu' and event['bus']['end']==event['cycle']==71
assert issue['bus']['end']==72
assert collision['reads'][1]=={'issue':71,'completion':132,'service':61}
full=rows[1];assert full['reads'][1]=={'issue':61,'completion':131,'service':70}
private=rows[0];assert private['reads'][0]=={'issue':0,'completion':61,'service':61}

result={'model_sha256':actual['model_sha256'],'fresh_trace_equals_frozen':True,
    'ordinary_envelope_case_count':len(ordinary),'ordinary_maximum':max(r['completion_from_issue'] for r in ordinary),
    'configuration_envelope_case_count':len(configuration),'configuration_maximum':61,
    'combined_envelope_bound':71,'ordinary_envelope_rows':ordinary,'configuration_envelope_rows':configuration,
    'concrete_cases':[{k:r[k] for k in ['case','operations','K','reads']} for r in rows],
    'no_double_count_reason':'The single writer cannot have an admitted private store and a WU in flight simultaneously. A configuration collision extends only a WU finishing at miss issue, by one remaining cycle, not by another full ten-cycle WU. No configuration is issued during the outstanding read.',
    'scope':'Finite arithmetic envelopes are a case check under the stated model gates, not an exhaustive reachable-state proof. Concrete traces attain 61/70/61; no claim that the conservative bound71 is attained.'}
(HERE/'SERVICE_CASE_CHECK.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(json.dumps({k:result[k] for k in ['fresh_trace_equals_frozen','ordinary_maximum','configuration_maximum','combined_envelope_bound']},indent=2))
