"""Compile PR2 and fail if its printed academic-test summary is incomplete."""
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile


ROOT = Path(__file__).resolve().parents[1] / "UOCCoworkingPr2"


def main():
    gcc = shutil.which("gcc")
    if not gcc:
        print("GCC with C99 support is required.", file=sys.stderr)
        return 1
    with tempfile.TemporaryDirectory() as build:
        executable = Path(build) / "uocoworking"
        compile_result = subprocess.run(
            [gcc, "-std=c99", "-Wall", "-Wextra", "-Iinclude",
             *[str(p.relative_to(ROOT)) for p in sorted((ROOT / "src").glob("*.c"))],
             "-lm", "-o", str(executable)], cwd=ROOT, timeout=60)
        if compile_result.returncode:
            return 1
        result = subprocess.run([str(executable), "-t"], cwd=ROOT,
                                text=True, capture_output=True, timeout=30)
        print(result.stdout, end="")
        print(result.stderr, end="", file=sys.stderr)
        totals = re.findall(r"Total:\s+Passed\s+(\d+)\s+of\s+(\d+)", result.stdout)
        if result.returncode or totals != [("45", "45")]:
            print("Validation failed: expected exactly one summary with 45 of 45 tests passed.",
                  file=sys.stderr)
            return 1
        print("Verified: all 45 academic tests passed.")
        return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, subprocess.TimeoutExpired) as error:
        print(f"Validation failed: {error}", file=sys.stderr)
        raise SystemExit(1)
