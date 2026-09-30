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

    scientificBadge:
        document.getElementById('scientificBadge'),

    scientificBadgeDetail:
        document.getElementById('scientificBadgeDetail'),

    dataModeText:
        document.getElementById('dataModeText'),

    topScientificBadge:
        document.getElementById('topScientificBadge'),

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

    imageTypeToggle:
        document.getElementById('imageTypeToggle'),

    typeGeoTiffBtn:
        document.getElementById('typeGeoTiffBtn'),

    typeNormalBtn:
        document.getElementById('typeNormalBtn'),

    imageInput:
        document.getElementById('imageInput'),

    fileDropzone:
        document.getElementById('fileDropzone'),

    dropzoneIcon:
        document.getElementById('dropzoneIcon'),

    dropzoneTitle:
        document.getElementById('dropzoneTitle'),

    dropzoneSubtitle:
        document.getElementById('dropzoneSubtitle'),

    selectedFileInfo:
        document.getElementById('selectedFileInfoBox'),

    selectedFileName:
        document.getElementById('selectedFileName'),

    selectedFileSize:
        document.getElementById('selectedFileSize'),

    thumbnailPreview:
        document.getElementById('thumbnailPreview'),

    viewSourceBtn:
        document.getElementById('viewSourceBtn'),

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

    autoRotateBtn:
        document.getElementById('autoRotateBtn'),

    gridBtn:
        document.getElementById('gridBtn'),

    measureBtn:
        document.getElementById('measureBtn'),

    // --------------------------------------------------------
    // Visualization / lighting
    // --------------------------------------------------------

    heatmapBtn:
        document.getElementById('heatmapBtn'), // <--- ADD THIS LINE
        
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

    undoRouteBtn: 
        document.getElementById('undoRouteBtn'),

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

    compassArrowContainer:
        document.querySelector('.compass-arrow-container'),

    compassFace:
        document.querySelector('.compass-face'),

    compareBtn: document.getElementById('compareBtn'),

    metricLockNote:
        document.getElementById('metricLockNote'),

    // Split comparison
    splitCompareBtn:
        document.getElementById('splitCompareBtn'),
    splitComparisonOverlay:
        document.getElementById('splitComparisonOverlay'),
    splitDivider:
        document.getElementById('splitComparisonDivider'),
    splitDividerValue:
        document.getElementById('splitDividerValue'),
    splitOpacitySlider:
        document.getElementById('splitOpacitySlider'),
    splitOpacityValue:
        document.getElementById('splitOpacityValue'),
    splitResetBtn:
        document.getElementById('splitResetBtn'),

    // Vertical exaggeration / measurement
    verticalExaggerationSlider:
        document.getElementById('verticalExaggerationSlider'),
    verticalExaggerationValue:
        document.getElementById('verticalExaggerationValue'),
    measurementReadout:
        document.getElementById('measurement-readout'),

    // Hydrology
    floodSeedBtn:
        document.getElementById('floodSeedBtn'),
    floodLevelSlider:
        document.getElementById('floodLevelSlider'),
    floodLevelValue:
        document.getElementById('floodLevelValue'),
    floodStatus:
        document.getElementById('floodStatus'),
    floodResetBtn:
        document.getElementById('floodResetBtn'),

    // Guided tour / tactical HUD
    guidedTourBtn:
        document.getElementById('guidedTourBtn'),
    tourStatus:
        document.getElementById('tourStatus'),
    tacticalHud:
        document.getElementById('tacticalHud'),
    hudAltitude:
        document.getElementById('hudAltitude'),
    hudHeading:
        document.getElementById('hudHeading'),
    hudSpeed:
        document.getElementById('hudSpeed'),
    hudElevation:
        document.getElementById('hudElevation'),
    hudDataMode:
        document.getElementById('hudDataMode'),

    inspectorPanel:
        document.getElementById('inspectorPanel'),
    inspectorMode:
        document.getElementById('inspectorMode'),
    inspectorValue:
        document.getElementById('inspectorValue'),
    inspectorCoords:
        document.getElementById('inspectorCoords'),
    inspectorNote:
        document.getElementById('inspectorNote'),

    exportSnapshotBtn:
        document.getElementById('exportSnapshotBtn'),
    exportPngBtn:
        document.getElementById('exportPngBtn'),
    exportTerrainBtn:
        document.getElementById('exportTerrainBtn'),
    exportStatus:
        document.getElementById('exportStatus'),
    processingOverlay:
    document.getElementById('processingOverlay'),

processingTitle:
    document.getElementById('processingTitle'),

processingMessage:
    document.getElementById('processingMessage'),

processingProgressBar:
    document.getElementById('processingProgressBar'),

processingPercent:
    document.getElementById('processingPercent')
};

