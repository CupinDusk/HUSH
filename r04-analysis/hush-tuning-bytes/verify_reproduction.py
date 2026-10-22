"""Producer reproducibility check. This is NOT an independent scientific check."""
from contextlib import redirect_stdout
from pathlib import Path
import hashlib
import io
import json

import analyze

HERE = Path(__file__).resolve().parent
DERIVED = ["RESULTS.json", "PAIR_DECOMPOSITION.json", "TUNING_PER_CONTROLLER.json",
           "SERIALIZED_RECORDS.json", "ALL_QUERY_DERIVATIONS.jsonl.gz", "PER_CONTROLLER_STATS.csv"]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    paths = [HERE/name for name in DERIVED] + sorted((HERE/"records").glob("*.bin"))
    assert len(paths) == 86
    original = {path.relative_to(HERE).as_posix(): digest(path) for path in paths}
    protocol_before = digest(HERE/"PROTOCOL.json")
    binding_before = digest(HERE/"PRECOMPUTATION_INPUT_BINDING.json")
    with redirect_stdout(io.StringIO()):
        analyze.main()
    reproduced = {path.relative_to(HERE).as_posix(): digest(path) for path in paths}
    assert original == reproduced
    assert digest(HERE/"PROTOCOL.json") == protocol_before
    assert digest(HERE/"PRECOMPUTATION_INPUT_BINDING.json") == binding_before
    evidence = dict(status="PRODUCER_BYTE_EXACT_REPRODUCTION_PASS_NOT_INDEPENDENT_VALIDATION",
                    reproduced_data_files=len(paths),
                    frozen_protocol_sha256=protocol_before,
                    precomputation_input_binding_sha256=binding_before,
                    all_reproduced_sha256=reproduced,
                    script_sha256=digest(Path(__file__)),
                    scope="Same producer rerun only. Does not satisfy the separate-checker gate.")
    (HERE/"REPRODUCIBILITY_CHECK.json").write_text(json.dumps(evidence, indent=2)+"\n", encoding="utf-8")
    print(json.dumps({k: v for k, v in evidence.items() if k != "all_reproduced_sha256"}, indent=2))


if __name__ == "__main__":
    main()
