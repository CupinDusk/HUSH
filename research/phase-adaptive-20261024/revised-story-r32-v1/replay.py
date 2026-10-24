"""Verify and replay the HUSH reporting/source-plan supplement offline."""
from __future__ import annotations

import argparse
import hashlib
import json
import shutil
import stat
import subprocess
import sys
import tempfile
import zipfile
from pathlib import Path, PurePosixPath


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def blob(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


def safe_name(name):
    path = PurePosixPath(name)
    require(not path.is_absolute() and bool(path.parts) and ".." not in path.parts, "Unsafe file name")
    require("\\" not in name and all(":" not in part for part in path.parts), "Unsafe file name")
    return path


def verify_bytes(data, record):
    require(len(data) == record["bytes"], "Size mismatch: " + record["path"])
    require(sha(data) == record["sha256"], "SHA256 mismatch: " + record["path"])
    require(blob(data) == record["git_blob_sha1"], "Blob mismatch: " + record["path"])


def execute(script, arguments, cwd, check=True):
    return subprocess.run([sys.executable, "-B", "-X", "utf8", str(script), *map(str, arguments)],
                          cwd=cwd, capture_output=True, text=True, check=check)


def compare_exact(generated, expected, names):
    for name in names:
        require((generated / name).read_bytes() == (expected / name).read_bytes(), "Replay differs: " + name)


def export_files(source, target, names):
    target.mkdir(parents=True, exist_ok=True)
    for name in names:
        data = (source / name).read_bytes()
        path = target / name
        require(not path.exists() or path.read_bytes() == data, "Output differs from existing file: " + name)
        path.write_bytes(data)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, help="Copy verified native and FIR results to this directory")
    args = parser.parse_args()
    base = Path(__file__).resolve().parent
    manifest = json.loads((base / "MANIFEST.json").read_text(encoding="utf-8"))
    for record in manifest["files"]:
        name = safe_name(record["path"])
        require(len(name.parts) == 1, "Top-level file name required")
        verify_bytes((base / name).read_bytes(), record)
    members = {r["path"]: r for r in manifest["archive_members"]}
    require(len(members) == len(manifest["archive_members"]), "Duplicate manifest member")

    with tempfile.TemporaryDirectory(prefix="hush-reporting-replay-") as temp:
        root = Path(temp)
        payload = root / "payload"
        with zipfile.ZipFile(base / manifest["archive"]) as archive:
            names = archive.namelist()
            require(len(names) == len(set(names)) and set(names) == set(members), "ZIP membership mismatch")
            require(archive.testzip() is None, "ZIP CRC failure")
            for item in archive.infolist():
                safe_name(item.filename)
                require(not item.is_dir() and not stat.S_ISLNK(item.external_attr >> 16), "Non-regular ZIP member")
                verify_bytes(archive.read(item.filename), members[item.filename])
            archive.extractall(payload)

        native = payload / "analysis/native-reporting"
        native_out = root / "native-results"
        native_run = execute(native / "replay.py", ["--output-dir", native_out], root)
        native_names = manifest["native_reporting"]["exact_outputs"]
        compare_exact(native_out, native / "expected", native_names)
        native_receipt = json.loads((native_out / "AUDIT_RECEIPT.json").read_text(encoding="utf-8"))
        require(native_receipt["TableII_absolute_rows"] == 9, "Native table count mismatch")
        require(native_receipt["correctness"]["TableII_1278_distinct_records_numerically_checked"], "Table checksum check failed")
        require(native_receipt["eta"]["observations"] == 420 and native_receipt["eta"]["candidate_points"] == 140,
                "Native interval population mismatch")

        fir = payload / "analysis/fir-study"
        execute(fir / "run_fir_study_r32.py", [], root)
        fir_names = manifest["fir_study"]["exact_outputs"]
        compare_exact(fir, fir / "expected", fir_names)
        fir_result = json.loads((fir / "RESULT.json").read_text(encoding="utf-8"))
        require("elapsed_s" in fir_result, "FIR runtime field absent")
        fir_result.pop("elapsed_s")
        stable = json.loads((fir / "expected/RESULT_STABLE.json").read_text(encoding="utf-8"))
        require(fir_result == stable, "FIR stable result differs")
        require(fir_result["conditional_cycle_model_executions"] == 3128, "FIR execution count mismatch")

        # Rejection tests modify isolated copies, never the bundled evidence.
        native_bad = root / "changed-native"
        shutil.copytree(native, native_bad)
        changed = native_bad / "inputs/R25-PER_OFFSET.csv"
        changed.write_bytes(changed.read_bytes() + b"\n")
        rejected = execute(native_bad / "replay.py", ["--output-dir", root / "rejected-native"], root, check=False)
        require(rejected.returncode != 0 and "R25-PER_OFFSET.csv" in rejected.stderr, "Native input change not rejected")

        fir_bad = root / "changed-fir"
        shutil.copytree(fir, fir_bad)
        changed = fir_bad / "inputs/replacement_model.py"
        changed.write_bytes(changed.read_bytes() + b"\n")
        rejected = execute(fir_bad / "run_fir_study_r32.py", [], root, check=False)
        require(rejected.returncode != 0 and "AssertionError" in rejected.stderr, "FIR input change not rejected")

        probe_result = None
        probe_out = root / "probe-results"
        if manifest.get("probe") is not None:
            probe = manifest["probe"]
            require(probe["offline_only"] is True, "Only offline probe replay may be invoked")
            script = payload / safe_name(probe["script"])
            arguments = [probe["output_flag"], probe_out] if probe.get("output_flag") else []
            completed = execute(script, arguments, root)
            probe_result = json.loads(completed.stdout)
            require(probe_result["new_native_execution_by_checker"] is False,
                    "The probe entry point must remain an offline checker")
            probe_out.mkdir()
            (probe_out / "CHECK_RESULT.json").write_text(json.dumps(probe_result, indent=2) + "\n", encoding="utf-8")
            expected_dir = payload / safe_name(probe["expected_directory"])
            compare_exact(probe_out, expected_dir, probe["exact_outputs"])

        if args.output is not None:
            export_files(native_out, args.output / "native-reporting", native_names)
            export_files(fir, args.output / "fir-study", fir_names)
            # The stable receipt excludes elapsed_s openly, and pins the patched runner hash.
            (args.output / "fir-study/RESULT_STABLE.json").write_text(json.dumps(fir_result, indent=2) + "\n", encoding="utf-8")
            if probe_result is not None:
                export_files(probe_out, args.output / "probe", manifest["probe"]["exact_outputs"])
        print(json.dumps({"native_exact_output_files": len(native_names), "native_TableII_rows": 9,
                          "native_TableII_distinct_checksums": 1278, "native_interval_groups": 20,
                          "FIR_candidates": fir_result["candidate_count"], "FIR_frozen_validations": fir_result["validation_count"],
                          "FIR_model_executions": 3128, "all_expected_scientific_outputs_equal": True,
                          "native_and_FIR_input_changes_rejected": True,
                          "probe_included": probe_result is not None, "probe_offline_result": probe_result,
                          "native_simulator_executions_in_replay": 0}, indent=2))


if __name__ == "__main__":
    main()
