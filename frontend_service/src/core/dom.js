// ============================================================
// DEPTHWIZARD
// DOM ELEMENT REFERENCES
// ============================================================

export const dom = {

    // --------------------------------------------------------
    // Main viewer
    // --------------------------------------------------------

    container:
        document.getElementById('canvas-container'),

    // --------------------------------------------------------
    // Viewer status / HUD
    // --------------------------------------------------------

    coordinates:
        document.getElementById('coordinates'),

    inspectorContent:
        document.getElementById('inspector-content'),

    viewerStatus:
        document.getElementById('viewerStatus'),

    systemStatus:
        document.getElementById('systemStatus'),

    fileStatus:
        document.getElementById('fileStatus'),

    statusDot:
        document.getElementById('statusDot'),

    hudStatusDot:
        document.getElementById('hudStatusDot'),

    currentModeBadge:
        document.getElementById('currentModeBadge'),

    topModeText:
        document.getElementById('topModeText'),

    topGridText:
        document.getElementById('topGridText'),

    // --------------------------------------------------------
    // Empty viewer state
    // --------------------------------------------------------

    emptyStateOverlay:
        document.getElementById('emptyStateOverlay'),

    emptyUploadTrigger:
        document.getElementById('emptyUploadTrigger'),

    emptyDemoTrigger:
        document.getElementById('emptyDemoTrigger'),

    // --------------------------------------------------------
    // Optical imagery input
    // --------------------------------------------------------

    imageInput:
        document.getElementById('imageInput'),

    fileDropzone:
        document.getElementById('fileDropzone'),

    selectedFileInfo:
        document.getElementById('selectedFileInfoBox'),

    selectedFileName:
        document.getElementById('selectedFileName'),

    selectedFileSize:
        document.getElementById('selectedFileSize'),

    thumbnailPreview:
        document.getElementById('thumbnailPreview'),

    uploadBtn:
        document.getElementById('uploadBtn'),

    demoBtn:
        document.getElementById('demoBtn'),

    // --------------------------------------------------------
    // 2D / 3D comparison PiP
    // --------------------------------------------------------

    pipToggle:
        document.getElementById('pipToggle'),

    comparisonPiP:
        document.getElementById('comparisonPiP'),

    pipImage:
        document.getElementById('pipImage'),

    pipPlaceholder:
        document.getElementById('pipPlaceholder'),

    pipFilename:
        document.getElementById('pipFilename'),

    pipDimensions:
        document.getElementById('pipDimensions'),

    pipMinimizeBtn:
        document.getElementById('pipMinimizeBtn'),

    pipCloseBtn:
        document.getElementById('pipCloseBtn'),

    // --------------------------------------------------------
    // Camera / navigation
    // --------------------------------------------------------

    orbitBtn:
        document.getElementById('orbitBtn'),

    flyBtn:
        document.getElementById('flyBtn'),

    resetBtn:
        document.getElementById('resetBtn'),

    gridBtn:
        document.getElementById('gridBtn'),

    measureBtn:
        document.getElementById('measureBtn'),

    // --------------------------------------------------------
    // Visualization / lighting
    // --------------------------------------------------------

    lightingBtn:
        document.getElementById('lightingBtn'),

    lightSlider:
        document.getElementById('lightSlider'),

    lightValue:
        document.getElementById('lightValue'),

    // --------------------------------------------------------
    // Route planning
    // --------------------------------------------------------

    drawRouteBtn:
        document.getElementById('drawRouteBtn'),

    clearRouteBtn:
        document.getElementById('clearRouteBtn'),

    flyRouteBtn:
        document.getElementById('flyRouteBtn'),

    flyRouteBtnText:
        document.getElementById('flyRouteBtnText'),

    routeWaypointsBadge:
        document.getElementById('routeWaypointsBadge'),

    routePointsCount:
        document.getElementById('routePointsCount'),

    routeDistance:
        document.getElementById('routeDistance'),

    routeStatus:
        document.getElementById('routeStatus'),

    routeBanner:
        document.getElementById('routeBanner'),

    // --------------------------------------------------------
    // Help / fullscreen
    // --------------------------------------------------------

    helpBtn:
        document.getElementById('helpBtn'),

    closeHelpBtn:
        document.getElementById('closeHelpBtn'),

    helpPanel:
        document.getElementById('help-panel'),

    fullscreenBtn:
        document.getElementById('fullscreenBtn'),

    // --------------------------------------------------------
    // Compass
    // --------------------------------------------------------

    compassControl:
        document.getElementById('compass-control'),

    compassFace:
        document.querySelector('.compass-face')
};