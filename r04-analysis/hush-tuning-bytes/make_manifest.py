"""Bind this producer's deliverables without modifying protocol or R03 inputs."""
from pathlib import Path
import hashlib
import json

HERE = Path(__file__).resolve().parent


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    prebinding = json.loads((HERE/"PRECOMPUTATION_INPUT_BINDING.json").read_text(encoding="utf-8"))
    result = json.loads((HERE/"RESULTS.json").read_text(encoding="utf-8"))
    files = {path.relative_to(HERE).as_posix(): dict(bytes=path.stat().st_size, sha256=sha(path))
             for path in sorted(HERE.rglob("*"))
             if path.is_file() and path.name != "MANIFEST.json" and "__pycache__" not in path.parts}
    manifest = dict(status="PRODUCER_DELIVERABLE_HASH_MANIFEST_PENDING_SEPARATE_CHECKER",
                    date="2026-10-23", study_type="POSTHOC_DERIVED_EXISTING_GRID",
                    frozen_r04_protocol_sha256=sha(HERE/"PROTOCOL.json"),
                    precomputation_input_binding_sha256=sha(HERE/"PRECOMPUTATION_INPUT_BINDING.json"),
                    readonly_frozen_r03_inputs=prebinding["binding"]["inputs"],
                    input_location="../../r03-analysis/hush-shared-controller/",
                    files=files, producer_status=result["status"],
                    independence="Same-author source/decoder/replay checks only; separate checker required before paper use.",
                    scope=result["scope"])
    (HERE/"MANIFEST.json").write_text(json.dumps(manifest, indent=2)+"\n", encoding="utf-8")
    print(json.dumps(dict(files_bound=len(files), record_files=sum(name.endswith(".bin") for name in files),
                          manifest_sha256=sha(HERE/"MANIFEST.json"), status=manifest["status"]), indent=2))


if __name__ == "__main__":
    main()
