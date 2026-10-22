"""Posthoc analysis of frozen R03 data, with zero new controller execution."""
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
import csv
import gzip
import hashlib
import io
import json
import math
import sys

from encoder import encode, structural_size
from decoder import decode, complete_slack

HERE = Path(__file__).resolve().parent
INPUT = HERE.parents[1] / "r03-analysis" / "hush-shared-controller"
INPUT_NAMES = ["RELATIONS.json", "ALL_PHASE_BASES.jsonl.gz", "POLICY_RESULTS.json",
               "PROTOCOL.json", "extract_shared.py"]
EPOCH_TEXT = ("R04 constructed two-client two-line component model; fixed initial entry "
              "immediately after each line's guaranteed first capture; no revocation, "
              "refill, payload mutation or other invalidation; frozen R03 relation epoch 1.")


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write_json(path, value):
    path.write_text(json.dumps(value, indent=2, ensure_ascii=False)+"\n", encoding="utf-8")


def input_fingerprints():
    return {name: {"sha256": sha(INPUT/name), "bytes": (INPUT/name).stat().st_size}
            for name in INPUT_NAMES}


def prebind():
    """Write hashes before parsing/deriving any controller, query, or result."""
    path = HERE / "PRECOMPUTATION_INPUT_BINDING.json"
    current = dict(protocol_sha256=sha(HERE/"PROTOCOL.json"),
                   inputs=input_fingerprints(),
                   implementation={name: sha(HERE/name) for name in
                                   ("analyze.py", "encoder.py", "decoder.py")},
                   epoch_text=EPOCH_TEXT,
                   epoch_sha256=hashlib.sha256(EPOCH_TEXT.encode()).hexdigest())
    if path.exists():
        old = json.loads(path.read_text(encoding="utf-8"))
        if old["binding"] != current:
            raise RuntimeError("precomputation binding differs; do not overwrite frozen provenance")
        return old
    result = dict(status="BOUND_BEFORE_FIRST_DERIVED_COMPUTATION",
                  bound_utc=datetime.now(timezone.utc).isoformat(), binding=current)
    write_json(path, result)
    return result


def group(pairs, modulus):
    spans = {}
    for residue, span in pairs:
        residue %= modulus
        spans[residue] = max(span, spans.get(residue, -1))
    return [[r, v] for r, v in sorted(spans.items())]


def core(pairs, modulus):
    return [[r, v] for r, v in pairs if not any(
        q != r and w-v >= (r-q) % modulus for q, w in pairs)]


def envelope(pairs, modulus):
    return [min((phi-r-1) % modulus-v for r, v in pairs) for phi in range(modulus)]


def optimum(policies):
    if not policies:
        return dict(status="EMPTY_FEASIBLE_SET", minimum_retention_proxy_ticks=None,
                    optimum_tie_count=0, all_optimum_ties=[], selected=None,
                    feasible_policy_count=0)
    best = min(row["retention_proxy_ticks"] for row in policies)
    ties = sorted((row for row in policies if row["retention_proxy_ticks"] == best),
                  key=lambda row: (row["K"], row["P"], row["phi"]))
    return dict(status="FEASIBLE", minimum_retention_proxy_ticks=best,
                optimum_tie_count=len(ties), all_optimum_ties=ties,
                selected=ties[0], feasible_policy_count=len(policies))


def distribution(values):
    values = sorted(values)
    if not values:
        return dict(count=0, min=None, max=None, median=None, mean=None, histogram=[])
    n = len(values)
    median = values[n//2] if n % 2 else (values[n//2-1]+values[n//2])/2
    return dict(count=n, min=values[0], max=values[-1], median=median,
                mean=sum(values)/n,
                histogram=[dict(value=k, controllers=v) for k, v in sorted(Counter(values).items())])


def binary_record(rec, variant, bindings, line_forms):
    cfg = rec["configuration"]
    return dict(variant=variant, p=cfg["p"], b=cfg["b"], r=cfg["r"],
                d=rec["translation"], maxP=4*cfg["p"], bindings=bindings,
                lines=[dict(owner=line["line"], tag=line["tag"],
                            initial_capture=line["initial_service_cutpoint"],
                            cycle_entry=rec["cycle_entry_tick"],
                            g=rec["translation"] if variant == "full" else forms["prospective_g"],
                            prefix=line["prefix"],
                            pairs=forms["full_canonical"] if variant == "full" else forms["projected_canonical"])
                       for line, forms in zip(rec["lines"], line_forms)])


def guarded_rejection_tests(record, payload, bindings):
    checks = Counter()
    malformed = [(payload[:-1], "truncation"), (payload+b"x", "trailing_bytes"),
                 (b"BADMAGIC"+payload[8:], "unknown_magic"),
                 (payload[:8]+b"\x02\x00\x00\x00"+payload[12:], "unknown_version")]
    for data, name in malformed:
        try:
            decode(data)
        except ValueError:
            checks[name] += 1
        else:
            raise AssertionError("malformed record accepted")
    wrong = dict(bindings)
    wrong["epoch"] = "00"*32
    try:
        complete_slack(record, 1, 1, 0, wrong)
    except ValueError:
        checks["binding_mismatch"] += 1
    else:
        raise AssertionError("wrong model binding accepted")
    if record["variant"] == "prospective":
        try:
            complete_slack(record, record["maxP"]+1, 1, 0, bindings)
        except ValueError:
            checks["outside_portfolio"] += 1
        else:
            raise AssertionError("out-of-portfolio query accepted")
    return checks


def main():
    provenance = prebind()  # Intentionally before parsing any input data.
    fixed_inputs = provenance["binding"]["inputs"]
    relations = json.loads((INPUT/"RELATIONS.json").read_text(encoding="utf-8"))
    oldresults = json.loads((INPUT/"POLICY_RESULTS.json").read_text(encoding="utf-8"))
    with gzip.open(INPUT/"ALL_PHASE_BASES.jsonl.gz", "rt", encoding="utf-8") as handle:
        phase_schema = json.loads(next(handle))
        phases = [json.loads(line) for line in handle]
    records = relations["records"]
    assert len(records) == 40 and all(x["status"] == "EXACT_CYCLE" for x in records)
    assert {x["case_id"] for x in records} == {
        f"p{p}_b{b}_r{r}" for p in (2, 3, 4, 5, 6) for b in range(p) for r in (3, 5)}
    phase_by_case = {rec["case_id"]: [] for rec in records}
    for phase in phases:
        phase_by_case[phase["case_id"]].append(phase)
    bindings = dict(source=fixed_inputs["extract_shared.py"]["sha256"],
                    receiver=fixed_inputs["PROTOCOL.json"]["sha256"],
                    relation=fixed_inputs["RELATIONS.json"]["sha256"],
                    epoch=provenance["binding"]["epoch_sha256"])
    (HERE/"records").mkdir(exist_ok=True)
    forms_records, tuning_records, byte_records, query_records = [], [], [], []
    checks = Counter()
    total = Counter()
    for rec in records:
        cid = rec["case_id"]
        cfg = rec["configuration"]
        p, d = cfg["p"], rec["translation"]
        prospect = math.lcm(*(math.gcd(P, d) for P in range(1, 4*p+1)))
        line_forms = []
        for line in rec["lines"]:
            spans = [[s, h-s] for s, c, h in line["cycle"]]
            full_group = group(spans, d)
            full_core = core(full_group, d)
            projected_group = group(spans, prospect)
            projected_core = core(projected_group, prospect)
            assert full_group == line["raw_master"] and full_core == line["master"]
            assert prospect == line["prospective_g"]
            assert projected_core == line["prospective_pairs"]
            assert envelope(full_group, d) == envelope(full_core, d)
            assert envelope(projected_group, prospect) == envelope(projected_core, prospect)
            assert core(group(full_core, prospect), prospect) == projected_core
            checks["direct_envelope_phase_checks"] += d+prospect
            form = dict(line=line["line"], tag=line["tag"], full_d=d, prospective_g=prospect,
                        full_group=full_group, full_canonical=full_core,
                        projected_group=projected_group, projected_canonical=projected_core,
                        full_canonical_deletions=len(full_group)-len(full_core),
                        support_projection_group_reduction=len(full_group)-len(projected_group),
                        prospective_canonical_deletions=len(projected_group)-len(projected_core),
                        prefix_edges=len(line["prefix"]))
            line_forms.append(form)
            for field in ("full_group", "full_canonical", "projected_group", "projected_canonical"):
                total[field+"_pairs"] += len(form[field])
        forms_records.append(dict(case_id=cid, p=p, d=d, maxP=4*p,
                                  prospective_g=prospect, lines=line_forms))
        decoded = {}
        sizes = {}
        for variant in ("full", "prospective"):
            expected = binary_record(rec, variant, bindings, line_forms)
            payload = encode(expected)
            path = HERE/"records"/(cid+"."+variant+".bin")
            path.write_bytes(payload)
            parsed = decode(path.read_bytes())
            assert parsed == expected
            assert len(payload) == structural_size(parsed)
            checks.update(guarded_rejection_tests(parsed, payload, bindings))
            checks["records_decoded_exact_fields"] += 1
            decoded[variant] = parsed
            prefix_n = sum(len(line["prefix"]) for line in parsed["lines"])
            pair_n = sum(len(line["pairs"]) for line in parsed["lines"])
            size = dict(path=path.relative_to(HERE).as_posix(), bytes=len(payload), sha256=sha(path),
                        controller_header_bytes=184, line_metadata_bytes=48*len(parsed["lines"]),
                        exact_prefix_edges=prefix_n, exact_prefix_bytes=24*prefix_n,
                        pairs=pair_n, profile_pair_bytes=16*pair_n,
                        non_pair_overhead_bytes=184+48*len(parsed["lines"])+24*prefix_n)
            sizes[variant] = size
            total[variant+"_serialized_bytes"] += size["bytes"]
            total[variant+"_pair_bytes"] += size["profile_pair_bytes"]
            total[variant+"_overhead_bytes"] += size["non_pair_overhead_bytes"]
        assert sizes["full"]["non_pair_overhead_bytes"] == sizes["prospective"]["non_pair_overhead_bytes"]
        byte_records.append(dict(case_id=cid, full=sizes["full"], prospective=sizes["prospective"],
                                 bytes_saved=sizes["full"]["bytes"]-sizes["prospective"]["bytes"],
                                 saved_fraction=(sizes["full"]["bytes"]-sizes["prospective"]["bytes"])/sizes["full"]["bytes"]))
        service, completion = [], []
        local = Counter()
        case_phases = sorted(phase_by_case[cid], key=lambda item: item["P"])
        assert [x["P"] for x in case_phases] == list(range(1, 4*p+1))
        for phase in case_phases:
            P = phase["P"]
            assert phase["m"] == math.gcd(P, d)
            assert [row[0] for row in phase["rows"]] == list(range(P))
            for row in phase["rows"]:
                phi, base, compbase, prebase, recbase, owner, s, c, h, supported, me, mc = row
                # Retain the frozen literal witness and every phase field verbatim.
                policies = []
                for K in range(1, 6):
                    service_slack = base+(K-1)*P
                    completion_slack = compbase+(K-1)*P
                    accepted = service_slack > 0
                    baseline_accepted = completion_slack > 0
                    assert accepted == bool(me & (1 << (K-1)))
                    assert baseline_accepted == bool(mc & (1 << (K-1)))
                    assert not baseline_accepted or accepted
                    for variant, parsed in decoded.items():
                        assert complete_slack(parsed, P, K, phi, bindings) == service_slack
                        checks[variant+"_complete_query_slack_matches"] += 1
                    policy = dict(K=K, P=P, phi=phi, retention_proxy_ticks=K*P-1,
                                  service_slack=service_slack, completion_slack=completion_slack,
                                  frozen_minimizer=dict(line=owner, s=s, c=c, h=h))
                    if accepted:
                        service.append(policy)
                    if baseline_accepted:
                        completion.append(policy)
                    local["queries"] += 1
                    local["service_positive"] += accepted
                    local["service_unknown"] += not accepted
                    local["completion_positive"] += baseline_accepted
                    local["completion_unknown"] += not baseline_accepted
                    local["service_only_admissions"] += accepted and not baseline_accepted
                    local["posthoc_unsupported_queries"] += not supported
                    policies.append(dict(K=K, retention_proxy_ticks=K*P-1,
                                         service_slack=service_slack, completion_slack=completion_slack,
                                         service_positive=accepted, completion_positive=baseline_accepted))
                query_records.append(dict(case_id=cid, P=P, m=phase["m"], frozen_phase_row=row,
                                          policies=policies))
                checks["phase_rows_retained"] += 1
        so, co = optimum(service), optimum(completion)
        gain = (co["minimum_retention_proxy_ticks"]-so["minimum_retention_proxy_ticks"]
                if so["selected"] is not None and co["selected"] is not None else None)
        if gain is not None:
            assert gain >= 0
        tuning_records.append(dict(case_id=cid, configuration=cfg, counts=dict(local),
                                   service=so, line_aware_tight_CJA_same_exact_prefix=co,
                                   retention_proxy_gain_ticks=gain,
                                   optimum_comparison=("SERVICE_LOWER_PROXY" if gain and gain > 0
                                                       else "NO_PROXY_GAIN" if gain == 0
                                                       else "ONE_OR_BOTH_EMPTY_FEASIBLE_SET"),
                                   no_additional_admissions=local["service_only_admissions"] == 0))
        total.update(local)
    assert total["queries"] == 37000 and checks["phase_rows_retained"] == 7400
    for ours, old in (("service_positive", "full_service_positive"),
                      ("service_unknown", "full_service_unknown"),
                      ("completion_positive", "full_completion_positive"),
                      ("service_only_admissions", "full_service_only"),
                      ("posthoc_unsupported_queries", "posthoc_unsupported_queries")):
        assert total[ours] == oldresults["counts"][old]
    write_json(HERE/"PAIR_DECOMPOSITION.json", dict(records=forms_records))
    write_json(HERE/"TUNING_PER_CONTROLLER.json", dict(records=tuning_records))
    write_json(HERE/"SERIALIZED_RECORDS.json", dict(bindings=bindings, epoch_text=EPOCH_TEXT,
                                                 records=byte_records))
    with (HERE/"ALL_QUERY_DERIVATIONS.jsonl.gz").open("wb") as raw:
        with gzip.GzipFile(fileobj=raw, mode="wb", mtime=0, filename="") as zipped:
            with io.TextIOWrapper(zipped, encoding="utf-8", newline="\n") as out:
                out.write(json.dumps(dict(frozen_phase_schema=phase_schema,
                                          note="One row per frozen physical phase; all five K queries retained; same frozen witness, no new source execution."))+"\n")
                for record in query_records:
                    out.write(json.dumps(record, separators=(",", ":"))+"\n")
    distributions = dict(
        service_optimum_ticks=distribution([r["service"]["minimum_retention_proxy_ticks"] for r in tuning_records if r["service"]["selected"]]),
        completion_optimum_ticks=distribution([r["line_aware_tight_CJA_same_exact_prefix"]["minimum_retention_proxy_ticks"] for r in tuning_records if r["line_aware_tight_CJA_same_exact_prefix"]["selected"]]),
        retention_proxy_gain_ticks=distribution([r["retention_proxy_gain_ticks"] for r in tuning_records if r["retention_proxy_gain_ticks"] is not None]),
        service_optimum_tie_count=distribution([r["service"]["optimum_tie_count"] for r in tuning_records]),
        completion_optimum_tie_count=distribution([r["line_aware_tight_CJA_same_exact_prefix"]["optimum_tie_count"] for r in tuning_records]),
        full_total_bytes=distribution([r["full"]["bytes"] for r in byte_records]),
        prospective_total_bytes=distribution([r["prospective"]["bytes"] for r in byte_records]),
        serialized_bytes_saved=distribution([r["bytes_saved"] for r in byte_records]),
        per_controller_byte_saving_fraction=distribution([r["saved_fraction"] for r in byte_records]),
        service_only_admissions=distribution([r["counts"]["service_only_admissions"] for r in tuning_records]))
    with (HERE/"PER_CONTROLLER_STATS.csv").open("w", encoding="utf-8", newline="") as handle:
        writer = csv.writer(handle, lineterminator="\n")
        writer.writerow(["case_id", "p", "b", "r", "service_optimum_ticks", "completion_optimum_ticks",
                         "proxy_gain_ticks", "service_optimum_ties", "completion_optimum_ties",
                         "service_only_admissions", "full_group_pairs", "full_canonical_pairs",
                         "projected_group_pairs", "projected_canonical_pairs", "full_bytes",
                         "prospective_bytes", "bytes_saved", "non_pair_overhead_bytes"])
        for tuning, forms, size in zip(tuning_records, forms_records, byte_records):
            cfg = tuning["configuration"]
            writer.writerow([tuning["case_id"], cfg["p"], cfg["b"], cfg["r"],
                             tuning["service"]["minimum_retention_proxy_ticks"],
                             tuning["line_aware_tight_CJA_same_exact_prefix"]["minimum_retention_proxy_ticks"],
                             tuning["retention_proxy_gain_ticks"], tuning["service"]["optimum_tie_count"],
                             tuning["line_aware_tight_CJA_same_exact_prefix"]["optimum_tie_count"],
                             tuning["counts"]["service_only_admissions"],
                             *(sum(len(line[k]) for line in forms["lines"]) for k in
                               ("full_group", "full_canonical", "projected_group", "projected_canonical")),
                             size["full"]["bytes"], size["prospective"]["bytes"], size["bytes_saved"],
                             size["full"]["non_pair_overhead_bytes"]])
    result = dict(status="PRODUCER_CHECKS_PASS_PENDING_SEPARATE_CHECKER", study_type="POSTHOC_DERIVED_EXISTING_GRID",
                  controllers=40, lines=80, counts=dict(total), checks=dict(checks),
                  cases_with_lower_service_optimum=sum(r["retention_proxy_gain_ticks"] is not None and r["retention_proxy_gain_ticks"] > 0 for r in tuning_records),
                  cases_with_no_proxy_gain=sum(r["retention_proxy_gain_ticks"] == 0 for r in tuning_records),
                  cases_with_no_additional_admissions=sum(r["no_additional_admissions"] for r in tuning_records),
                  service_empty_feasible_sets=sum(r["service"]["selected"] is None for r in tuning_records),
                  completion_empty_feasible_sets=sum(r["line_aware_tight_CJA_same_exact_prefix"]["selected"] is None for r in tuning_records),
                  cases_with_no_byte_saving=sum(r["bytes_saved"] == 0 for r in byte_records),
                  full_canonical_deletions=total["full_group_pairs"]-total["full_canonical_pairs"],
                  support_projection_group_reduction=total["full_group_pairs"]-total["projected_group_pairs"],
                  prospective_canonical_deletions=total["projected_group_pairs"]-total["projected_canonical_pairs"],
                  pair_saving_fraction=1-total["projected_canonical_pairs"]/total["full_canonical_pairs"],
                  serialized_total_saving_fraction=1-total["prospective_serialized_bytes"]/total["full_serialized_bytes"],
                  distributions=distributions,
                  input_binding_sha256=sha(HERE/"PRECOMPUTATION_INPUT_BINDING.json"),
                  frozen_protocol_sha256=sha(HERE/"PROTOCOL.json"),
                  scope="Specified constructed component model and explicit demonstration byte format only. No new workloads, controller execution, timings, hardware, traffic, energy, WCET, minimum-byte or native-HUSH/coherence claim.")
    # Catch accidental modification of any frozen input after all computations.
    assert input_fingerprints() == fixed_inputs
    write_json(HERE/"RESULTS.json", result)
    print(json.dumps({k: v for k, v in result.items() if k != "distributions"}, indent=2))


if __name__ == "__main__":
    main()
