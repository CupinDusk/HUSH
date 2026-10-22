"""Assemble author-side audit receipts from the independent raw reports."""
from pathlib import Path
import hashlib,json
HERE=Path(__file__).resolve().parent
ROOT=HERE.parent
def r(n):return json.loads((HERE/n).read_text(encoding='utf-8'))
def save(n,x):(HERE/n).write_text(json.dumps(x,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

check=r('CHECK_RESULTS.json');small=r('SMALL_CHECKS.json');old=r('OLD_RELATION_RESULTS.json');size=r('SIZE_RESULTS.json');probes=r('PARSER_PROBES.json');mut=r('MUTATION_CONTROLS.json')
sources=[dict(title='Knuth, Morris, Pratt (1977), Fast Pattern Matching in Strings',url='https://epubs.siam.org/doi/10.1137/0206024',use='Standard string period/prefix-function computation; no new generic algorithm claimed.'),dict(title='Zippo and Stea (2023), Computationally Efficient Worst-Case Analysis of Flow-Controlled Networks With Network Calculus',url='https://arxiv.org/pdf/2203.02497',doi='10.1109/TIT.2023.3244276',locations='Section IV-A1 Definition 5 and Lemma 1, printed p2673; Appendix B Theorem 9',use='Prior periodic-function representation minimization by repeated breakpoint parts and period-multiple structure; scope differs from integer cyclic observer.')]
limits=[
    'New posthoc conditional extension. Original fixed-modulus and nondivisor results remain intact.',
    '19,524 counts nonempty raw assignments, not distinct canonical functions.',
    'Mathematical identity applies to any positive integer P and K under checked exact lift; finite checks do not prove universal quantifiers.',
    'Minimum pair count is confined to the exact period-lift family for the same exact H, not arbitrary encodings or sign-only queries.',
    'Expanded-profile digest is not self-authenticating; trusted registry and actual source-period proof remain necessary.',
    'Source triples/profile lift are checked for declared exact relations; native source closure/refinement and hardware behavior are not established.',
    'Initialization/capture/cycle-entry, physical prefixes and epoch obligations are retained, not derived from the compressed record.',
    'Actual decoder probes are targeted normal-Python checks; assert-based guards are not optimized-Python hardening.',
    'Large size-family phases use independent reset-event envelope sweep with a mathematical equal-span proof, not p-term brute minimum at every phase.',
    'Four actual mutant branches are witnessed; no generic mutation coverage claimed.',
    'No generic novelty claim for period minimization/KMP, and no hardware, memory, runtime, application or performance claim.',
]
audit=dict(status='PASS',role='AUTHOR_SIDE_INDEPENDENT_MATHEMATICAL_AND_ENCODING_AUDIT',blind_review=False,score_requested=False,scope='Conditional exact integer unit-slope cyclic observer with trusted expected registry',mathematical_conclusion='Canonical reset/span translation iff exact H period; primitive decorated gap word gives fundamental e; checked exact lift yields recurrent h=gcd(P,e) and physical (K-1)P, unchanged prefixes.',independent_implementation=dict(science_imports_from_producer=False,canonicalization='Direct envelope strict-reset inverse',periods='Exhaustive function/translation/dividing word-block tests, not producer KMP',size_envelope='Independent event sweep with equal-span proof',codec='Independent parse and byte regeneration; producer actual decoder loaded separately solely for adversarial codec testing'),small_census=small,old_controller_results=old,size_results=size,mutation_controls=mut,actual_decoder_probes=probes,source_receipts=check['source_receipt'],established_primary_sources=sources,scope_limits=limits,history=dict(producer_first_syntax_failure_preserved=True,producer_first_correct_source_reconstructed_byte_exact=True,old_protocol_hash_distinct_from_amended_protocol=True,independent_first_invocation_compile_failure_preserved='failure-001-syntax/',original_reports_and_binaries_unchanged=True),artifacts=dict(full_proof='INDEPENDENT_AUDIT.md',paper_ready_facts='PAPER_READY_FACTS.md',checker='check_independent.py',producer_codec_probes='parser_probe.py',input_hash_manifest='READ_INPUT_MANIFEST.json',audit_manifest='AUDIT_FILE_MANIFEST.json'))
save('INDEPENDENT_AUDIT.json',audit)
facts=dict(status='PASS_WITH_STATED_SCOPE',role=audit['role'],theorem=dict(statement=audit['mathematical_conclusion'],mandatory_conditions=['Nonempty canonical unit-slope integer profile','Exact residue AND span translation/lift checked from source profile','Trusted expected expanded-profile and four-binding registry','Valid initialization and unchanged physical prefix/epoch semantics'],optimality='Minimum pair count only among exact period lifts of same H'),census=dict(raw_assignments=small['counts']['profiles'],divisor_profile_checks=small['counts']['target_divisor_profiles'],physical_slacks=small['counts']['physical_policy_slacks'],semantic_sha256=small['canonical_case_digest']),original_census=dict(controllers=40,lines=80,reduced_lines=11,unchanged_lines=69,pairs_before=961,pairs_after=950,full_bytes_before=36560,period_bytes_after=39584,all_controllers_larger=True,old_portfolio_bytes=33424,adaptive_full_fallback_bytes=36560,per_line_slacks=74000,complete_slacks=37000,added_metadata_bytes=3200,saved_pair_bytes=176,net_byte_increase=3024),size_family=dict(cases=size['cases'],all_phases=2798064,sampled_physical_slacks=378,one_line_baseline_magic='HUFULL05',period_record_magic='HUPERD05',previous_simple_header_bytes=32,previous_simple_period_bytes=48,favorable_size_result_does_not_replace_original_regressions=True),codec=dict(valid_artifacts=54,rejected_targeted_mutants=2762,matching_forged_registry_acceptance_controls=47,trust_requirement='Digest plus untrusted registry is not source authentication',normal_python_only=True),actual_named_mutant_branches=4,source_receipts=check['source_receipt'],primary_sources=sources,prohibited_inferences=limits)
save('PAPER_READY_FACTS.json',facts)

source_names=['PROTOCOL.md','ARGUMENT.md','research.py','research-version-001.py','FIRST_SOURCE_RECOVERY.json','reconstruct_first_source.py','INPUT_BINDING_BEFORE_PARSE.json','SIZE_INPUT_BINDING_BEFORE_PARSE.json','prepare_inputs.py','prepare_size_inputs.py','failure-001-syntax/research.py','failure-001-syntax/FAILURE.txt']
for attempt in ('attempt-001','attempt-002'):
    source_names.extend(f'{attempt}/{n}' for n in ('START_BINDING.json','SMALL_CHECKS.json','OLD_RELATION_RESULTS.json','MUTATION_CONTROLS.json','RESULTS.json'))
source_names.append('attempt-002/SIZE_RESULTS.json')
manifest=dict(status='HASH_BOUND_FINAL_AUDIT_ARTIFACTS',manifest_self_excluded=True,source_files={n:dict(bytes=(ROOT/n).stat().st_size,sha256=sha(ROOT/n)) for n in source_names},independent_files={str(p.relative_to(HERE)).replace('\\','/'):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in sorted(HERE.rglob('*')) if p.is_file() and p.name!='AUDIT_FILE_MANIFEST.json'})
save('AUDIT_FILE_MANIFEST.json',manifest)
print(json.dumps(dict(status=audit['status'],source_files=len(manifest['source_files']),independent_files=len(manifest['independent_files']),input_files=len(r('READ_INPUT_MANIFEST.json'))),indent=2))
