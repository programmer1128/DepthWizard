#!/usr/bin/env bash

set -uo pipefail

# ---------------------------------------------------------------------------
# Directory configuration
# ---------------------------------------------------------------------------

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd -- "${SCRIPT_DIR}/.." && pwd)"

# An alternative build directory can be supplied as the first argument.
# Example:
#   ./test/run_tests_with_logs.sh build-debug
BUILD_DIR="${1:-${PROJECT_ROOT}/build-tests}"

if [[ "${BUILD_DIR}" != /* ]]; then
    BUILD_DIR="${PROJECT_ROOT}/${BUILD_DIR}"
fi

TEST_LOG_ROOT="${SCRIPT_DIR}/test_logs"
RUN_ID="$(date '+%Y-%m-%d_%H-%M-%S')"

PASSED_RUN_DIR="${TEST_LOG_ROOT}/passed/${RUN_ID}"
FAILED_RUN_DIR="${TEST_LOG_ROOT}/failed/${RUN_ID}"
SUMMARY_DIR="${TEST_LOG_ROOT}/summary"

SUMMARY_FILE="${SUMMARY_DIR}/summary_${RUN_ID}.log"
FAILURE_REPORT="${SUMMARY_DIR}/failed_details_${RUN_ID}.log"

mkdir -p \
    "${PASSED_RUN_DIR}" \
    "${FAILED_RUN_DIR}" \
    "${SUMMARY_DIR}"

# ---------------------------------------------------------------------------
# Initial validation
# ---------------------------------------------------------------------------

if ! command -v ctest >/dev/null 2>&1; then
    echo "ERROR: ctest was not found in PATH." >&2
    exit 2
fi

if [[ ! -d "${BUILD_DIR}" ]]; then
    echo "ERROR: Build directory does not exist:" >&2
    echo "       ${BUILD_DIR}" >&2
    exit 2
fi

if [[ ! -f "${BUILD_DIR}/CTestTestfile.cmake" ]]; then
    echo "ERROR: No CTestTestfile.cmake was found in:" >&2
    echo "       ${BUILD_DIR}" >&2
    echo "Configure the project with BUILD_TESTING enabled first." >&2
    exit 2
fi

# ---------------------------------------------------------------------------
# Discover all registered CTest tests
#
# Stored as:
#   test-number|full-test-name
# ---------------------------------------------------------------------------

mapfile -t REGISTERED_TESTS < <(
    ctest --test-dir "${BUILD_DIR}" -N |
        sed -nE \
            's/^[[:space:]]*Test +#([0-9]+):[[:space:]]+(.*)$/\1|\2/p'
)

if (( ${#REGISTERED_TESTS[@]} == 0 )); then
    echo "ERROR: No tests are registered with CTest." >&2
    echo "Check that enable_testing() and add_test() or gtest_discover_tests()" >&2
    echo "are present in your CMake configuration." >&2
    exit 2
fi

# ---------------------------------------------------------------------------
# Summary headers
# ---------------------------------------------------------------------------

{
    echo "DepthWizard C++ Test Run Summary"
    echo "================================"
    echo "Run ID       : ${RUN_ID}"
    echo "Project root : ${PROJECT_ROOT}"
    echo "Build folder : ${BUILD_DIR}"
    echo "Started at   : $(date --iso-8601=seconds)"
    echo "Tests found  : ${#REGISTERED_TESTS[@]}"
    echo
    printf '%-7s | %-10s | %-8s | %s\n' \
        "CTest #" "Result" "Time" "Test name"
    printf '%s\n' \
        "--------------------------------------------------------------------------"
} > "${SUMMARY_FILE}"

{
    echo "DepthWizard Failed-Test Details"
    echo "==============================="
    echo "Run ID       : ${RUN_ID}"
    echo "Build folder : ${BUILD_DIR}"
    echo
    echo "This report contains GTest assertion locations, expected/actual values,"
    echo "exceptions, sanitizer messages and relevant failure output."
    echo
} > "${FAILURE_REPORT}"

passed_count=0
failed_count=0
overall_status=0

run_start_ns="$(date +%s%N)"

# ---------------------------------------------------------------------------
# Run each registered test separately
# ---------------------------------------------------------------------------

for registered_test in "${REGISTERED_TESTS[@]}"; do
    test_number="${registered_test%%|*}"
    test_name="${registered_test#*|}"

    # Convert the test name into a safe filename.
    safe_test_name="$(
        printf '%s' "${test_name}" |
            sed 's/[^A-Za-z0-9_.-]/_/g'
    )"

    temporary_log="$(
        mktemp "${TEST_LOG_ROOT}/.ctest_${test_number}.XXXXXX"
    )"

    test_start_ns="$(date +%s%N)"

    echo "Running: ${test_name}"

    # -I runs exactly one test by its CTest number.
    # --verbose preserves GTest assertions and stdout/stderr.
    if GTEST_COLOR=no \
       GTEST_STACK_TRACE_DEPTH=100 \
       ctest \
           --test-dir "${BUILD_DIR}" \
           -I "${test_number},${test_number}" \
           --verbose \
           > "${temporary_log}" 2>&1
    then
        test_result="PASSED"
        destination_log="${PASSED_RUN_DIR}/${safe_test_name}.log"

        mv "${temporary_log}" "${destination_log}"
        ((passed_count += 1))
    else
        test_result="FAILED"
        destination_log="${FAILED_RUN_DIR}/${safe_test_name}.log"

        mv "${temporary_log}" "${destination_log}"
        ((failed_count += 1))
        overall_status=1

        # ---------------------------------------------------------------
        # Add an easy-to-read section to the consolidated failure report.
        # ---------------------------------------------------------------

        {
            echo "================================================================"
            echo "FAILED TEST"
            echo "================================================================"
            echo "CTest number : ${test_number}"
            echo "Test name    : ${test_name}"
            echo "Complete log : ${destination_log}"
            echo
            echo "Failure information"
            echo "-------------------"

            # A normal GTest assertion is reported in this form:
            # /path/to/TestFile.cc:123: Failure
            #
            # Print from the first assertion until GTest's FAILED marker.
            if grep -Eq ':[[:digit:]]+:[[:space:]]+Failure' \
                "${destination_log}"
            then
                awk '
                    /:[[:digit:]]+:[[:space:]]+Failure/ {
                        capture = 1
                    }

                    capture {
                        print
                    }

                    capture && /\[[[:space:]]+FAILED[[:space:]]+\]/ {
                        capture = 0
                    }
                ' "${destination_log}"
            else
                # Crashes, signals, timeouts and sanitizer failures might not
                # contain a normal GTest "Failure" line. Preserve the final
                # section where the relevant diagnostic usually appears.
                echo "No standard GTest assertion block was found."
                echo "The test may have crashed, timed out, or been terminated."
                echo
                echo "Last 100 lines of output:"
                echo
                tail -n 100 "${destination_log}"
            fi

            echo
        } >> "${FAILURE_REPORT}"
    fi

    test_end_ns="$(date +%s%N)"
    elapsed_ms=$(( (test_end_ns - test_start_ns) / 1000000 ))

    printf '%-7s | %-10s | %6s ms | %s\n' \
        "${test_number}" \
        "${test_result}" \
        "${elapsed_ms}" \
        "${test_name}" \
        >> "${SUMMARY_FILE}"

    printf '  %-6s %s ms -> %s\n' \
        "${test_result}" \
        "${elapsed_ms}" \
        "${destination_log}"
done

# ---------------------------------------------------------------------------
# Final summary
# ---------------------------------------------------------------------------

run_end_ns="$(date +%s%N)"
total_elapsed_ms=$(( (run_end_ns - run_start_ns) / 1000000 ))
total_count=$(( passed_count + failed_count ))

{
    echo
    echo "Final result"
    echo "------------"
    echo "Total tests : ${total_count}"
    echo "Passed      : ${passed_count}"
    echo "Failed      : ${failed_count}"
    echo "Duration    : ${total_elapsed_ms} ms"
    echo "Finished at : $(date --iso-8601=seconds)"
    echo
    echo "Passed logs : ${PASSED_RUN_DIR}"
    echo "Failed logs : ${FAILED_RUN_DIR}"
    echo "Failure report: ${FAILURE_REPORT}"
} >> "${SUMMARY_FILE}"

if (( failed_count == 0 )); then
    {
        echo "No tests failed during this run."
    } >> "${FAILURE_REPORT}"
fi

echo
echo "Test run completed."
echo "Passed: ${passed_count}"
echo "Failed: ${failed_count}"
echo
echo "Summary:"
echo "  ${SUMMARY_FILE}"

if (( failed_count > 0 )); then
    echo
    echo "Consolidated failure report:"
    echo "  ${FAILURE_REPORT}"
fi

exit "${overall_status}"