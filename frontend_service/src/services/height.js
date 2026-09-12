// ============================================================
// DEPTHWIZARD
// ACTUAL HEIGHT API
// ============================================================

const API_BASE = 'http://localhost:8080';

export async function fetchActualHeight(x, y) {

    const url =
        `${API_BASE}/api/v1/get-actual-height/` +
        `x=${encodeURIComponent(x)},y=${encodeURIComponent(y)}`;

    const response = await fetch(url);

    if (!response.ok) {
        throw new Error(
            `Actual height API failed (${response.status})`
        );
    }

    const result = await response.json();

    if (
        result.status === 'error' ||
        result.success === false
    ) {
        throw new Error(
            result.message ||
            'Unable to fetch actual height.'
        );
    }

    return result;
}