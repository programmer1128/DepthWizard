// ============================================================
// DEPTHWIZARD
// BACKEND RESULT NORMALIZER
// ============================================================

// ------------------------------------------------------------
// Get the generated terrain / GLB URL
// ------------------------------------------------------------

export function getTerrainUrl(result) {

    if (!result) {
        return null;
    }

    return (
        result.saved_file ||
        result.terrain_url ||
        result.glb_url ||
        result.model_url ||
        result.mesh_url ||
        null
    );
}


// ------------------------------------------------------------
// Get 3D Tiles URL
// ------------------------------------------------------------

export function getTilesUrl(result) {

    if (!result) {
        return null;
    }

    return (
        result.tileset_url ||
        result.tiles_url ||
        result.tileset ||
        null
    );
}


// ------------------------------------------------------------
// Get elevation / DSM URL
// ------------------------------------------------------------

export function getElevationUrl(result) {

    if (!result) {
        return null;
    }

    return (
        result.dsm_url ||
        result.dsm ||
        result.elevation_url ||
        result.elevation_map ||
        null
    );
}


// ------------------------------------------------------------
// Check whether backend processing succeeded
// ------------------------------------------------------------

export function isSuccessfulResult(result) {

    return Boolean(
        result &&
        result.status === 'success'
    );
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