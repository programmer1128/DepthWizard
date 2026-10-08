// ============================================================
// DEPTHWIZARD
// APPLICATION CONSTANTS
// ============================================================

export const CONFIG = {

    // ========================================================
    // CAMERA
    // ========================================================

    CAMERA_FOV: 55,
    CAMERA_NEAR: 0.1,
    CAMERA_FAR: 10000,

    // Initial camera
    INITIAL_CAMERA_X: 160,
    INITIAL_CAMERA_Y: 110,
    INITIAL_CAMERA_Z: 200,

    // Orbit limits
    ORBIT_MIN_DISTANCE: 2,
    ORBIT_MAX_DISTANCE: 6000,

    // ========================================================
    // RENDERER
    // ========================================================

    MAX_PIXEL_RATIO: 2,

    // Original main.js used ACES Filmic tone mapping
    TONE_MAPPING_EXPOSURE: 1.1,

    // ========================================================
    // FREE-FLY NAVIGATION
    // ========================================================

    FLY_MOVEMENT_SPEED: 60,
    FLY_ROLL_SPEED: Math.PI / 10,

    // ========================================================
    // GROUND GRID
    // ========================================================

    GRID_SIZE: 1200,
    GRID_DIVISIONS: 48,

    // ========================================================
    // ROUTE PLANNING
    // ========================================================

    ROUTE_FLY_SPEED: 0.05,

    // Camera clearance above terrain
    ROUTE_CAMERA_HEIGHT: 30,

    // Number of points used to generate route
    ROUTE_MIN_SAMPLE_COUNT: 120,

    // Additional samples based on waypoint count
    ROUTE_SAMPLES_PER_WAYPOINT: 35,

    // Async raycasting chunk size
    ROUTE_CHUNK_SIZE: 12,

    // Height of waypoint marker above terrain
    ROUTE_WAYPOINT_HEIGHT: 1.5,

    // Height of route line above terrain
    ROUTE_SURFACE_OFFSET: 1.0,

    // Route visual settings
    ROUTE_MARKER_RADIUS: 2,

    // Camera look-ahead distance during flythrough
    ROUTE_LOOK_AHEAD_DISTANCE: 45,

    // ========================================================
    // IMAGE PREVIEW
    // ========================================================

    MAX_PREVIEW_SIZE: 2048,

    // ========================================================
    // ORBIT CONTROLS
    // ========================================================

    ORBIT_AUTO_ROTATE_SPEED: 0.8
};