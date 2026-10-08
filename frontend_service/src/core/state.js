// ============================================================
// DEPTHWIZARD
// APPLICATION STATE
// ============================================================

export const state = {

    // ----------------------------------------------------------
    // Terrain / 3D data
    // ----------------------------------------------------------

    terrainModel: null,
    vegetationTrees: null,   // Instanced vegetation proxies (vegetationTreeRenderer.js)
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
    presentationStyle: 'orthophoto',
    renderQuality: 'balanced',
    frameTimes: [],

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
    lastClickedPoint: null,

    // ----------------------------------------------------------
    // Scientific / workstation state
    // ----------------------------------------------------------

    metricMode: 'unknown',
    verticalExaggeration: 1.0,

    // Split comparison
    comparisonEnabled: false,
    comparisonSplit: 0.5,
    comparisonElevationOpacity: 1.0,
    terrainComparisonBounds: null,

    // Flood simulator
    floodWaterMesh: null,
    floodSeedCell: null,
    floodSeedPoint: null,
    floodWaterLevel: null,

    // Guided tour / tactical HUD
    tourActive: false,
    tourElapsed: 0,
    tacticalSpeed: 0
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

export function showProcessingOverlay(
    title = 'Processing terrain',
    message = 'Generating 3D elevation model…'
) {

    if (!dom.processingOverlay) {
        return;
    }

    if (dom.processingTitle) {
        dom.processingTitle.textContent =
            title;
    }

    if (dom.processingMessage) {
        dom.processingMessage.textContent =
            message;
    }

    if (dom.processingPercent) {
        dom.processingPercent.textContent =
            'WORKING';
    }

    if (dom.processingProgressBar) {
        dom.processingProgressBar.style.width =
            '35%';
    }

    dom.processingOverlay.classList.remove(
        'hidden'
    );
}


export function hideProcessingOverlay() {

    if (!dom.processingOverlay) {
        return;
    }

    dom.processingOverlay.classList.add(
        'hidden'
    );
}