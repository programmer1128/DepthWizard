// ============================================================
// DEPTHWIZARD
// SINGLE HEIGHT API SERVICE
// ============================================================

import { API_BASE } from './backend.js';

export const SINGLE_HEIGHT_ENDPOINT = `${API_BASE}/api/height/single`;

/**
 * Query single terrain height at (x, y) coordinates for a given model UUID.
 *
 * Backend contract:
 * POST <API_BASE>/api/height/single
 * Content-Type: application/json
 * Body: {"uuid": "<YOUR_UUID>", "x": 12.34, "y": 56.78, "feature_id": 42}
 *
 * x, y are metres east and south of the terrain's north-west corner.
 * feature_id is the clicked building's _FEATURE_ID_0 from the GLB (optional).
 * The response has kind "building" (building_height_meters, roof/base
 * elevations) or "terrain" (elevation_meters, absolute).
 */
export async function fetchSingleHeight({ uuid, x, y, featureId = null }) {

    if (!uuid) {
        throw new Error(
            'Model UUID is required. Please upload an image first or enter an active UUID.'
        );
    }

    const numX = Math.max(0, Number(x));
    const numY = Math.max(0, Number(y));

    if (!Number.isFinite(numX) || !Number.isFinite(numY)) {
        throw new Error('Valid numerical (x, y) coordinates are required.');
    }

    let response;
    try {
        response = await fetch(
            SINGLE_HEIGHT_ENDPOINT,
            {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({
                    uuid: String(uuid).trim(),
                    x: numX,
                    y: numY,
                    ...(Number.isFinite(featureId) && featureId >= 1
                        ? { feature_id: featureId }
                        : {})
                })
            }
        );
    } catch (networkError) {
        throw new Error(
            `Unable to connect to height API at ${SINGLE_HEIGHT_ENDPOINT}. Ensure backend is running.`
        );
    }

    if (!response.ok) {
        let errorMessage = `Single height request failed (${response.status})`;
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
            'Unable to fetch terrain height.'
        );
    }

    return result;
}

/**
 * Backward-compatible wrapper
 */
export async function fetchActualHeight(x, y, uuid = null) {
    return fetchSingleHeight({ uuid, x, y });
}
