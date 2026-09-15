// ============================================================
// DEPTHWIZARD
// APPLICATION STATE
// ============================================================

export const state = {

    // ----------------------------------------------------------
    // Terrain / 3D data
    // ----------------------------------------------------------

    terrainModel: null,
    terrainBounds: null,
    currentLoadedUrl: null,

    tilesRenderer: null,


    // ----------------------------------------------------------
    // Camera / navigation
    // ----------------------------------------------------------

    flyMode: false,
    userInteracting: false,
    interactionTimeout: null,

    initialCameraPosition: null,
    initialCameraTarget: null,
    initialCameraZoom: 1,


    // ----------------------------------------------------------
    // Viewer settings
    // ----------------------------------------------------------

    lightingEnabled: true,
    gridVisible: true,
    heatmapEnabled: false,
    autoRotateEnabled: false,

    // ----------------------------------------------------------
    // Route system
    // ----------------------------------------------------------

    isDrawingRoute: false,
    isFlyingRoute: false,

    routeWaypoints: [],
    routeMarkerMeshes: [],
    routeLineMesh: null,
    routeSurfaceCurve: null,

    routeDistance: 0,
    flyProgress: 0,

    currentRouteCalculationId: 0,

    routePreviousFlyMode: false,


    // ----------------------------------------------------------
    // File / preview / backend session
    // ----------------------------------------------------------

    selectedFile: null,
    currentPreviewUrl: null,

    // Backend session UUID returned by /api/v1/processor (managed internally)
    currentUuid: null,

    // Image upload type: 'geotiff' or 'normal'
    imageUploadType: 'geotiff',

    // Last inspected or clicked coordinate on terrain
    lastClickedPoint: null
};

const uuidChangeListeners = new Set();

export function onUuidChange(callback) {
    if (typeof callback === 'function') {
        uuidChangeListeners.add(callback);
    }
    return () => uuidChangeListeners.delete(callback);
}

export function setCurrentUuid(uuid) {
    state.currentUuid = uuid ? String(uuid).trim() : null;
    for (const listener of uuidChangeListeners) {
        try {
            listener(state.currentUuid);
        } catch (err) {
            console.error('UUID listener error:', err);
        }
    }
}
