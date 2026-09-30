import {
    initHeightInspection
} from './features/height.js';

import {
    initSplitComparison
} from './features/splitComparison.js';

import {
    initFlood,
    clearFlood,
    updateFloodForTerrain
    //updateFloodAnimation
} from './features/flood.js';

import {
    initGuidedTour,
    updateGuidedTour,
    stopGuidedTour
} from './features/tour.js';

import {
    initExports
} from './features/export.js';

import {
    openCompareModal
} from './ui/compareUI.js';

// ============================================================
// DEPTHWIZARD
// MAIN APPLICATION ENTRY POINT
// ============================================================

import * as THREE from 'three';


// ============================================================
// CORE
// ============================================================

import { dom } from './core/dom.js';
import {
    state,
    setCurrentUuid,
    onUuidChange
} from './core/state.js';



// ============================================================
// VIEWER
// ============================================================

import {
    scene,
    camera,
    renderer,
    resizeRenderer
} from './viewer/scene.js';

import {
    initLighting,
    setLightingEnabled,
    setTimeOfDay,
    setGridVisible
} from './viewer/lighting.js';

import {
    loadTerrainGLB
} from './viewer/terrain.js';

import {
    loadTiles,
    updateTiles,
    disposeTiles
} from './viewer/tiles.js';


// ============================================================
// CONTROLS
// ============================================================

import {
    initNavigation,
    orbitControls,
    flyControls,
    updateNavigation,
    resetCamera
} from './controls/navigation.js';


// ============================================================
// FEATURES
// ============================================================

import {
    initInspector
} from './features/inspector.js';

import {
    initMeasurement
} from './features/measurement.js';

import {
    initRoute,
    clearRoute,
    removeLastWaypoint,
    updateRouteFlythrough
} from './features/route.js';

import {
    processGeoTIFF,
    isGeoTIFFFile
} from './features/geotiff.js';


// ============================================================
// SERVICES
// ============================================================

import {
    processImage
} from './services/backend.js';

import {
    normalizeResult
} from './services/result.js';


// ============================================================
// UI
// ============================================================

import {
    initPanel,
    closeHelp
} from './ui/panel.js';

import {
    initFileUI
} from './ui/fileUI.js';

import {
    initControlsUI
} from './ui/controlsUI.js';

import {
    initPiP
} from './ui/pipUI.js';

import {
    initWorkstationUI,
    setScientificDataMode,
    setTacticalCameraState,
    updateTacticalHUD,
    setMetricToolAvailability
} from './ui/workstationUI.js';

import {
    initSidebarUI
} from './ui/sidebarUI.js';
import {
    initLayoutUI
} from './ui/layoutUI.js';

import {
    setViewerStatus,
    setSystemStatus,
    setFileStatus,
    setModeStatus,
    setGridStatus,
    showProcessingOverlay,
    hideProcessingOverlay
} from './ui/status.js';




// ============================================================
// CLOCK
// ============================================================

const clock =
    new THREE.Clock();

const previousCameraPosition = new THREE.Vector3();
let hasPreviousCameraPosition = false;


// ============================================================
// APPLICATION INITIALIZATION
// ============================================================

function initializeApplication() {

    // --------------------------------------------------------
    // Navigation
    // --------------------------------------------------------

    initNavigation();


    // --------------------------------------------------------
    // Visualization
    // --------------------------------------------------------

    initLighting();


    // --------------------------------------------------------
    // Features
    // --------------------------------------------------------

    initWorkstationUI();
    initSidebarUI();
    initLayoutUI();
    initSplitComparison();
    initFlood();
    initGuidedTour();
    initExports();
    initInspector();
    initMeasurement();
    initRoute();


    // --------------------------------------------------------
    // UI
    // --------------------------------------------------------

    initPanel();
    initFileUI();
    initControlsUI();
    initPiP();

    initHeightInspection();

    onUuidChange((uuid) => {
        setMetricToolAvailability(state.metricMode === 'metric' && Boolean(uuid));
    });

    if (dom.compareBtn) {
        dom.compareBtn.addEventListener(
            'click',
            () => openCompareModal()
        );
    }




    // --------------------------------------------------------
    // Initial state
    // --------------------------------------------------------

    state.lightingEnabled = true;
    state.gridVisible = true;
    state.verticalExaggeration = 1;
    setScientificDataMode(state.metricMode || 'dimensionless');
    setTacticalCameraState(camera);

    setLightingEnabled(true);
    setTimeOfDay(12);
    setGridVisible(true);

    setModeStatus('orbit');
    setGridStatus(true);

    setViewerStatus(
        'Viewer ready',
        'ready'
    );

    setSystemStatus(
        'Viewer Ready',
        'ready'
    );

    setFileStatus(
        'No terrain loaded'
    );

    


    // --------------------------------------------------------
    // Events
    // --------------------------------------------------------

    initializeApplicationEvents();


    // --------------------------------------------------------
    // Start render loop
    // --------------------------------------------------------

    animate();

}


// ============================================================
// APPLICATION EVENTS
// ============================================================

function initializeApplicationEvents() {

    // --------------------------------------------------------
    // Demo
    // --------------------------------------------------------

    if (dom.demoBtn) {

        dom.demoBtn.addEventListener(
            'click',
            handleDemo
        );

    }

    if (dom.emptyDemoTrigger) {

        dom.emptyDemoTrigger.addEventListener(
            'click',
            handleDemo
        );

    }


    // --------------------------------------------------------
    // Empty upload trigger
    // --------------------------------------------------------

    if (dom.emptyUploadTrigger) {

        dom.emptyUploadTrigger.addEventListener(
            'click',
            () => {

                if (dom.imageInput) {
                    dom.imageInput.click();
                }

            }
        );

    }


    // --------------------------------------------------------
    // Upload button
    // --------------------------------------------------------

    if (dom.uploadBtn) {

        dom.uploadBtn.addEventListener(
            'click',
            handleUpload
        );

    }


    // --------------------------------------------------------
    // Fullscreen
    // --------------------------------------------------------

    if (dom.fullscreenBtn) {

        dom.fullscreenBtn.addEventListener(
            'click',
            toggleFullscreen
        );

    }


    // --------------------------------------------------------
    // Keyboard
    // --------------------------------------------------------

    window.addEventListener(
        'keydown',
        handleKeyboard
    );


    // --------------------------------------------------------
    // Resize
    // --------------------------------------------------------

    window.addEventListener(
        'resize',
        resizeRenderer
    );

}


// ============================================================
// UPLOAD HANDLER
// ============================================================

async function handleUpload() {

    const file =
        state.selectedFile;

    if (!file) {

        setFileStatus(
            'Select an image first'
        );

        return;

    }


    try {

        setCurrentUuid(null);

        setViewerStatus(
            'Processing image...',
            'loading'
        );


        setFileStatus(
            `Processing ${file.name}...`
        );

        showProcessingOverlay(
            'Processing terrain',
            `Analyzing ${file.name} and generating the 3D elevation model...`
        );


        // ----------------------------------------------------
        // GeoTIFF 2D optical preview
        // ----------------------------------------------------

        if (isGeoTIFFFile(file)) {
            try {
                await processGeoTIFF(file);
            } catch (tifErr) {
                console.warn('GeoTIFF preview generation note:', tifErr);
            }
        }


        // ----------------------------------------------------
        // Clear previous route before new terrain
        // ----------------------------------------------------

        clearRoute();
        clearFlood();
        state.comparisonEnabled = false;
        state.comparisonSplit = 0.5;
        state.comparisonElevationOpacity = 1;

        updateFloodForTerrain();

        disposeTiles();


        // ----------------------------------------------------
        // Send image to backend (GeoTIFF vs Normal Image)
        // ----------------------------------------------------

        // Show how long the backend has been working: a cold reconstruction
        // service can add a few minutes, which should not look like a hang.
        const processingStarted = Date.now();
        const elapsedTicker = setInterval(() => {
            const seconds = Math.round((Date.now() - processingStarted) / 1000);
            const clock = `${Math.floor(seconds / 60)}:${String(seconds % 60).padStart(2, '0')}`;
            if (dom.processingPercent) {
                dom.processingPercent.textContent = clock;
            }
            if (dom.processingMessage && seconds >= 60) {
                dom.processingMessage.textContent =
                    `Reconstructing buildings for ${file.name}... ` +
                    'The first run after a pause can take a few minutes while the reconstruction service starts.';
            }
        }, 1000);

        let result;
        try {
            result = await processImage(file, state.imageUploadType || 'auto');
        } finally {
            clearInterval(elapsedTicker);
        }


        const normalized =
            normalizeResult(result);


        // Capture active model UUID internally for single height and compare APIs
        if (normalized.uuid) {
            setCurrentUuid(normalized.uuid);
        }


        if (!normalized.success) {

            throw new Error(
                normalized.message ||
                'Height estimation pipeline failed.'
            );

        }


        // ----------------------------------------------------
        // Load generated GLB if available
        // ----------------------------------------------------

        if (normalized.terrainUrl) {

            await loadTerrainGLB(
                normalized.terrainUrl
            );

        }


        // ----------------------------------------------------
        // Optional 3D Tiles
        // ----------------------------------------------------

        if (normalized.tilesUrl) {

            try {

                await loadTiles(
                    normalized.tilesUrl
                );

            } catch (tilesError) {

                console.warn(
                    '3D Tiles could not be loaded:',
                    tilesError
                );

            }

        }


        // ----------------------------------------------------
        // Success
        // ----------------------------------------------------

        setViewerStatus(
            normalized.terrainUrl ? 'Terrain loaded' : 'Processing complete',
            'ready'
        );

        setFileStatus(
            `${file.name} ready • 3D mesh generated`
        );
        hideProcessingOverlay();




    } catch (error) {

        console.error(
            'Upload processing failed:',
            error
        );


        setViewerStatus(
            error.message ||
            'Processing failed',
            'error'
        );


        setFileStatus(
            'Processing failed'
        );
        hideProcessingOverlay();

    }

}


// ============================================================
// DEMO TERRAIN
// ============================================================

async function handleDemo() {

    try {

        clearRoute();
        clearFlood();
        state.comparisonEnabled = false;
        state.comparisonSplit = 0.5;
        state.comparisonElevationOpacity = 1;

        updateFloodForTerrain();
        disposeTiles();
        setCurrentUuid(null);


        setViewerStatus(
            'Loading demo terrain...',
            'loading'
        );


        setFileStatus(
            'Loading ISRO satellite sample...'
        );


        // ----------------------------------------------------
        // Original demo asset
        // ----------------------------------------------------

        await loadTerrainGLB(
            '/new_test.glb'
        );


        // ----------------------------------------------------
        // Original demo file information
        // ----------------------------------------------------

        setFileStatus(
            'test_8_output.glb (Demo)'
        );


        // ----------------------------------------------------
        // Demo PiP image
        // ----------------------------------------------------

        if (dom.pipImage) {

            dom.pipImage.src =
                '/demo_optical.png';

            dom.pipImage.classList.remove(
                'hidden'
            );

        }

        if (dom.pipPlaceholder) {

            dom.pipPlaceholder.classList.add(
                'hidden'
            );

        }

        if (dom.pipFilename) {

            dom.pipFilename.textContent =
                'Demo Terrain Mesh';

        }

        if (dom.pipDimensions) {

            dom.pipDimensions.textContent =
                'Embedded optical texture from demo GLB';

        }


        if (dom.pipToggle) {
            dom.pipToggle.checked = true;
        }

        if (dom.comparisonPiP) {

            dom.comparisonPiP.classList.remove(
                'hidden'
            );

        }


        setViewerStatus(
            'Demo terrain ready',
            'ready'
        );


    } catch (error) {

        console.error(
            'Demo loading failed:',
            error
        );


        setViewerStatus(
            error.message ||
            'Demo terrain failed to load',
            'error'
        );


        setFileStatus(
            'Demo loading failed'
        );

    }

}


// ============================================================
// FULLSCREEN
// ============================================================

async function toggleFullscreen() {

    try {

        if (!document.fullscreenElement) {

            await document.documentElement.requestFullscreen();

        } else {

            await document.exitFullscreen();

        }

    } catch (error) {

        console.error(
            'Fullscreen error:',
            error
        );

    }

}


// ============================================================
// UPDATE FULLSCREEN BUTTON
// ============================================================

function updateFullscreenButton() {

    if (!dom.fullscreenBtn) {
        return;
    }

    dom.fullscreenBtn.textContent =
        document.fullscreenElement
            ? '🗗'
            : '⛶';

}


// ============================================================
// FULLSCREEN EVENT
// ============================================================

document.addEventListener(
    'fullscreenchange',
    updateFullscreenButton
);


// ============================================================
// KEYBOARD CONTROLS
// ============================================================

function handleKeyboard(event) {

    // Never capture shortcuts while typing
    const target =
        event.target;

    const isTyping =
        target instanceof HTMLInputElement ||
        target instanceof HTMLTextAreaElement ||
        target instanceof HTMLSelectElement ||
        target?.isContentEditable;


    if (isTyping) {
        return;
    }


    // --------------------------------------------------------
    // F = Toggle Fly / Orbit
    // --------------------------------------------------------

    if (
        event.key === 'f' ||
        event.key === 'F'
    ) {

        event.preventDefault();

        if (state.isFlyingRoute || state.tourActive) {
            return;
        }

        if (state.flyMode) {

            orbitControls.enabled = true;
            flyControls.enabled = false;
            state.flyMode = false;

            setModeStatus('orbit');

        } else {

            orbitControls.enabled = false;
            flyControls.enabled = true;
            state.flyMode = true;

            setModeStatus('fly');

        }

        return;

    }


    // --------------------------------------------------------
    // Escape
    // --------------------------------------------------------

    if (
        event.key === 'Escape'
    ) {

        if (state.tourActive) {
            stopGuidedTour(true);
            return;
        }

        if (state.isFlyingRoute) {

            state.isFlyingRoute = false;

        }

        state.isDrawingRoute = false;

        closeHelp();

    }

}


// ============================================================
// ANIMATION LOOP
// ============================================================

function animate() {

    requestAnimationFrame(
        animate
    );


    const delta =
        Math.min(
            clock.getDelta(),
            0.1
        );


    // --------------------------------------------------------
    // Guided tour / route / normal navigation
    // --------------------------------------------------------

    if (state.tourActive) {

        updateGuidedTour(delta);

    } else if (state.isFlyingRoute) {

        updateRouteFlythrough(
            delta
        );

    } else {

        // ----------------------------------------------------
        // Normal navigation
        // ----------------------------------------------------

        updateNavigation(
            delta
        );

    }


    // --------------------------------------------------------
    // 3D Tiles
    // --------------------------------------------------------

    updateTiles();

    // // --------------------------------------------------------
    // // Flood water animation
    // // --------------------------------------------------------

    // updateFloodAnimation(delta);


    // --------------------------------------------------------
    // Tactical HUD / camera telemetry
    // --------------------------------------------------------

    if (hasPreviousCameraPosition) {
        state.tacticalSpeed = camera.position.distanceTo(previousCameraPosition) / Math.max(delta, 0.001);
    } else {
        state.tacticalSpeed = 0;
        hasPreviousCameraPosition = true;
    }
    previousCameraPosition.copy(camera.position);
    updateTacticalHUD();

    // --------------------------------------------------------
    // Render
    // --------------------------------------------------------

    renderer.render(
        scene,
        camera
    );

}


// ============================================================
// START APPLICATION
// ============================================================

initializeApplication();