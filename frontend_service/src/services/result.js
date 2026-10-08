// ============================================================
// DEPTHWIZARD
// BACKEND RESULT NORMALIZER
// ============================================================

// ------------------------------------------------------------
// Get the generated terrain / GLB URL
// ------------------------------------------------------------

import { API_BASE } from './backend.js';

// ------------------------------------------------------------
// Resolve relative URL to full backend URL if needed
// ------------------------------------------------------------

function resolveUrl(url) {
    if (!url || typeof url !== 'string') {
        return null;
    }

    if (
        url.startsWith('http://') ||
        url.startsWith('https://') ||
        url.startsWith('blob:') ||
        url.startsWith('data:')
    ) {
        return url;
    }

    const cleanBase = API_BASE.replace(/\/+$/, '');
    const cleanPath = url.startsWith('/') ? url : `/${url}`;

    return `${cleanBase}${cleanPath}`;
}

// ------------------------------------------------------------
// Extract session / model UUID
// ------------------------------------------------------------

export function getResultUuid(result) {
    if (!result || typeof result !== 'object') {
        return null;
    }

    return (
        result.uuid ||
        result.id ||
        result.session_id ||
        result.task_id ||
        result.data?.uuid ||
        result.data?.id ||
        result.result?.uuid ||
        null
    );
}

// ------------------------------------------------------------
// Get the generated terrain / GLB URL
// ------------------------------------------------------------

export function getTerrainUrl(result) {

    if (!result) {
        return null;
    }

    const raw = (
        result.saved_file ||
        result.terrain_url ||
        result.glb_url ||
        result.model_url ||
        result.mesh_url ||
        result.mesh ||
        result.output_glb ||
        result.data?.saved_file ||
        result.data?.terrain_url ||
        result.data?.glb_url ||
        null
    );

    return resolveUrl(raw);
}


// ------------------------------------------------------------
// Get 3D Tiles URL
// ------------------------------------------------------------

export function getTilesUrl(result) {

    if (!result) {
        return null;
    }

    const raw = (
        result.tileset_url ||
        result.tiles_url ||
        result.tileset ||
        result.data?.tileset_url ||
        null
    );

    return resolveUrl(raw);
}


// ------------------------------------------------------------
// Get elevation / DSM URL
// ------------------------------------------------------------

export function getElevationUrl(result) {

    if (!result) {
        return null;
    }

    const raw = (
        result.dsm_url ||
        result.dsm ||
        result.elevation_url ||
        result.elevation_map ||
        result.data?.dsm_url ||
        null
    );

    return resolveUrl(raw);
}


// ------------------------------------------------------------
// Check whether backend processing succeeded
// ------------------------------------------------------------

export function isSuccessfulResult(result) {

    if (!result || typeof result !== 'object') {
        return false;
    }

    if (result.status === 'error' || result.success === false) {
        return false;
    }

    if (result.status === 'success' || result.status === 'ok' || result.success === true) {
        return true;
    }

    // If UUID or a terrain URL was returned, assume success
    if (getResultUuid(result) || getTerrainUrl(result)) {
        return true;
    }

    return true;
}


// ------------------------------------------------------------
// Get backend error message
// ------------------------------------------------------------

export function getResultMessage(result) {

    if (!result) {
        return 'Backend returned no response.';
    }

    return (
        result.message ||
        result.error ||
        result.detail ||
        'Height estimation pipeline failed.'
    );
}


// ------------------------------------------------------------
// Normalize the complete backend response
// ------------------------------------------------------------

export function normalizeResult(result) {

    return {

        success:
            isSuccessfulResult(result),

        uuid:
            getResultUuid(result),

        terrainUrl:
            getTerrainUrl(result),

        tilesUrl:
            getTilesUrl(result),

        elevationUrl:
            getElevationUrl(result),

        message:
            getResultMessage(result),

        raw:
            result
    };
}
