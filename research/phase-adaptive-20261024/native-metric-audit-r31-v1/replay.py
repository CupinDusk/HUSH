"""Verify and replay the exact native metrics using only the Python standard library."""
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


def digest(data):
    return hashlib.sha256(data).hexdigest()


def git_blob(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


def safe_name(name):
    p = PurePosixPath(name)
    require(not p.is_absolute() and bool(p.parts) and ".." not in p.parts, "Unsafe member name")
    require("\\" not in name and all(":" not in part for part in p.parts), "Unsafe member name")
    return p


def verify_bytes(data, record):
    require(len(data) == record["bytes"], "Size mismatch: " + record["path"])
    require(digest(data) == record["sha256"], "SHA256 mismatch: " + record["path"])
    require(git_blob(data) == record["git_blob_sha1"], "Blob hash mismatch: " + record["path"])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, help="Copy verified CSV tables and receipt to this directory")
    args = parser.parse_args()
    base = Path(__file__).resolve().parent
    manifest = json.loads((base / "MANIFEST.json").read_text(encoding="utf-8"))
    for row in manifest["files"]:
        p = safe_name(row["path"])
        require(len(p.parts) == 1, "Top-level file name required")
        verify_bytes((base / p).read_bytes(), row)
    members = {r["path"]: r for r in manifest["archive_members"]}
    require(len(members) == len(manifest["archive_members"]), "Duplicate manifest member")

    with tempfile.TemporaryDirectory(prefix="hush-metric-replay-") as temp:
        root = Path(temp)
        extracted = root / "payload"
        with zipfile.ZipFile(base / manifest["archive"]) as z:
            names = z.namelist()
            require(len(names) == len(set(names)), "Duplicate ZIP member")
            require(set(names) == set(members), "ZIP membership differs from manifest")
            require(z.testzip() is None, "ZIP CRC failure")
            for info in z.infolist():
                safe_name(info.filename)
                require(not info.is_dir() and not stat.S_ISLNK(info.external_attr >> 16), "Non-regular ZIP member")
                verify_bytes(z.read(info.filename), members[info.filename])
            z.extractall(extracted)

        analysis = extracted / "analysis"
        generated = root / "generated"
        command = [sys.executable, "-B", "-X", "utf8", str(analysis / "audit_native_metrics.py"),
                   "--inputs-dir", str(analysis / "inputs"), "--output-dir", str(generated)]
        completed = subprocess.run(command, check=True, capture_output=True, text=True, cwd=root)
        result = json.loads(completed.stdout)
        require(result == manifest["expected_result_counts"], "Result counts differ")
        expected = {PurePosixPath(name).name: analysis / "expected" / PurePosixPath(name).name
                    for name in manifest["expected_outputs"]}
        require(len(expected) == len(manifest["expected_outputs"]), "Duplicate expected output name")
        require({p.name for p in generated.iterdir()} == set(expected), "Generated output membership differs")
        for name, reference in expected.items():
            require((generated / name).read_bytes() == reference.read_bytes(), "Output differs: " + name)

        # Exercise the checker's pinned-input rejection using an isolated copy.
        changed_inputs = root / "changed-inputs"
        shutil.copytree(analysis / "inputs", changed_inputs)
        changed = changed_inputs / "TRAINING_SEVEN.csv"
        changed.write_bytes(changed.read_bytes() + b"\n")
        reject_command = [sys.executable, "-B", "-X", "utf8", str(analysis / "audit_native_metrics.py"),
                          "--inputs-dir", str(changed_inputs), "--output-dir", str(root / "rejected-output")]
        rejected = subprocess.run(reject_command, capture_output=True, text=True, cwd=root)
        require(rejected.returncode != 0 and "TRAINING_SEVEN.csv" in rejected.stderr,
                "Changed input was not rejected by its pin")

        if args.output is not None:
            args.output.mkdir(parents=True, exist_ok=True)
            for name in sorted(expected):
                target = args.output / name
                data = (generated / name).read_bytes()
                require(not target.exists() or target.read_bytes() == data,
                        "Output already exists with different bytes: " + name)
                target.write_bytes(data)
        print(json.dumps({**result, "all_expected_outputs_byte_equal": True,
                          "expected_outputs_checked": len(expected), "changed_input_rejected": True}, indent=2))


if __name__ == "__main__":
    main()
