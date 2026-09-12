// ============================================================
// DEPTHWIZARD
// MAIN APPLICATION ENTRY POINT
// ============================================================

import * as THREE from 'three';


// ============================================================
// CORE
// ============================================================

import { dom } from './core/dom.js';
import { state } from './core/state.js';


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
    setLightIntensity,
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
    setViewerStatus,
    setSystemStatus,
    setFileStatus,
    setModeStatus,
    setGridStatus
} from './ui/status.js';


// ============================================================
// CLOCK
// ============================================================

const clock =
    new THREE.Clock();


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


    // --------------------------------------------------------
    // Initial state
    // --------------------------------------------------------

    state.lightingEnabled = true;
    state.gridVisible = true;

    setLightingEnabled(true);
    setLightIntensity(2.0);
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

        setViewerStatus(
            'Processing image...',
            'loading'
        );


        setFileStatus(
            `Processing ${file.name}...`
        );


        // ----------------------------------------------------
        // GeoTIFF
        // ----------------------------------------------------

        if (isGeoTIFFFile(file)) {

            await processGeoTIFF(file);

            return;

        }


        // ----------------------------------------------------
        // Clear previous route before new terrain
        // ----------------------------------------------------

        clearRoute();

        disposeTiles();


        // ----------------------------------------------------
        // Send image to backend
        // ----------------------------------------------------

        const result =
            await processImage(file);


        const normalized =
            normalizeResult(result);


        if (
            !normalized.success ||
            !normalized.terrainUrl
        ) {

            throw new Error(
                normalized.message ||
                'Height estimation pipeline did not return a GLB mesh.'
            );

        }


        // ----------------------------------------------------
        // Load generated GLB
        // ----------------------------------------------------

        await loadTerrainGLB(
            normalized.terrainUrl
        );


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
            'Terrain loaded',
            'ready'
        );


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

    }

}


// ============================================================
// DEMO TERRAIN
// ============================================================

async function handleDemo() {

    try {

        clearRoute();
        disposeTiles();


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
            '/test_8_output.glb'
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
                '/icons.svg';

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
                'ISRO Satellite Sample';

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

        if (state.isFlyingRoute) {
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
    // Route flythrough
    // --------------------------------------------------------

    if (
        state.isFlyingRoute
    ) {

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