// ============================================================
// DEPTHWIZARD
// COMPARISON API SERVICE
// ============================================================

import { API_BASE } from './backend.js';

export const COMPARE_ENDPOINT = `${API_BASE}/api/height/compare`;

export const SUPPORTED_DATASET_TAGS = [
    { value: 'opentopography', label: 'OpenTopography' },
    { value: 'bhuvan', label: 'ISRO Bhuvan' }
];

/**
 * Compare elevation data against a reference dataset at (x, y) coordinates.
 *
 * Backend contract:
 * POST http://localhost:8080/api/height/compare
 * Content-Type: application/json
 * Body: {"uuid": "<YOUR_UUID>", "tag": "opentopography", "x": 12.34, "y": 56.78}
 *
 * Response includes elevation metrics and `diff_map_base64`.
 */
export async function compareElevation({ uuid, tag = 'opentopography', x, y }) {

    if (!uuid) {
        throw new Error(
            'Model UUID is required for comparison. Please upload an image or provide an active UUID.'
        );
    }

    if (!tag) {
        throw new Error('Dataset tag is required (e.g. "opentopography").');
    }

    const numX = Math.max(0, Number(x));
    const numY = Math.max(0, Number(y));

    if (!Number.isFinite(numX) || !Number.isFinite(numY)) {
        throw new Error('Valid numerical (x, y) coordinates are required for comparison.');
    }

    let response;
    try {
        response = await fetch(
            COMPARE_ENDPOINT,
            {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({
                    uuid: String(uuid).trim(),
                    tag: String(tag).trim(),
                    x: numX,
                    y: numY
                })
            }
        );
    } catch (networkError) {
        throw new Error(
            `Unable to connect to compare API at ${COMPARE_ENDPOINT}. Ensure backend is running.`
        );
    }

    if (!response.ok) {
        let errorMessage = `Comparison request failed (${response.status})`;
        try {
            const errJson = await response.json();
            if (errJson.message || errJson.error || errJson.detail) {
                errorMessage = errJson.message || errJson.error || errJson.detail;
            }
        } catch (_) {}

        throw new Error(errorMessage);
    }

    const result = await response.json();

    if (
        result.status === 'error' ||
        result.success === false
    ) {
        throw new Error(
            result.message ||
            result.error ||
            'Elevation comparison processing failed.'
        );
    }

    return result;
}

/**
 * Backward-compatible or generic caller
 */
export async function runComparison(params, legacyDataset) {
    // Handle both runComparison({ uuid, tag, x, y }) and legacy runComparison(file, dataset)
    if (params && typeof params === 'object' && ('uuid' in params || 'x' in params)) {
        return compareElevation(params);
    }

    // If passed legacy params
    const tag = typeof legacyDataset === 'string' ? legacyDataset : 'opentopography';
    return compareElevation({
        uuid: params?.uuid || params,
        tag,
        x: params?.x ?? 0,
        y: params?.y ?? 0
    });
}
