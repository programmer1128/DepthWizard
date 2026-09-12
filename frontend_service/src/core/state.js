// ============================================================
// DEPTHWIZARD
// APPLICATION STATE
// ============================================================

export const state = {

    // ----------------------------------------------------------
    // Terrain / 3D data
    // ----------------------------------------------------------

    terrainModel: null,
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
    // File / preview
    // ----------------------------------------------------------

    selectedFile: null,
    currentPreviewUrl: null
};