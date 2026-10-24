"""Verify regenerated scientific outputs against the compact expected record."""
from pathlib import Path
import hashlib
import json

HERE = Path(__file__).resolve().parent


def canonical(value):
    return json.dumps(value, ensure_ascii=False, sort_keys=True,
                      separators=(',', ':'), allow_nan=False)


def digest(value):
    return hashlib.sha256(canonical(value).encode('utf-8')).hexdigest()


def normalized_rows(rows):
    # The canonical payload is a sorted JSON array of canonical row strings.
    return sorted(canonical(row) for row in rows)


def without_elapsed(value):
    if isinstance(value, dict):
        return {key: without_elapsed(item) for key, item in value.items()
                if key != 'elapsed_seconds'}
    if isinstance(value, list):
        return [without_elapsed(item) for item in value]
    return value


def main():
    expected = json.loads((HERE / 'EXPECTED_RESULTS.json').read_text(encoding='utf-8'))
    result = json.loads((HERE / 'REPLACEMENT_RESULTS.json').read_text(encoding='utf-8'))
    rows = result['rows']
    assert len(rows) == expected['row_count']
    assert all(sorted(row) == expected['row_fields'] for row in rows)
    assert digest(normalized_rows(rows)) == expected['normalized_rows_sha256']
    assert result['summary'] == expected['summary']
    assert len(set(normalized_rows(rows))) == len(rows)
    for name, sha in expected['source_sha256'].items():
        actual = hashlib.sha256((HERE / name).read_bytes()).hexdigest()
        assert actual == sha, (name, actual, sha)
    assert result['model_sha256'] == expected['source_sha256']['replacement_model.py']
    assert result['driver_sha256'] == expected['source_sha256']['run_study.py']
    assert result['trace_sha256'] == expected['source_sha256']['fir2dim-read-trace.json']
    for filename, wanted in expected['checker_scientific_outputs'].items():
        actual = json.loads((HERE / filename).read_text(encoding='utf-8'))
        assert without_elapsed(actual) == wanted, filename
    output = {
        'passed': True,
        'scientific_rows_compared': len(rows),
        'scientific_fields_per_row': len(expected['row_fields']),
        'normalized_rows_sha256': expected['normalized_rows_sha256'],
        'summary_matches': True,
        'checker_outputs_match_except_elapsed': True,
        'source_hashes_match': True,
    }
    print(json.dumps(output, indent=2))


if __name__ == '__main__':
    main()
