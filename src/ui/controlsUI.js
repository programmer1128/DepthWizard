// ============================================================
// DEPTHWIZARD
// UI CONTROL BINDINGS
// ============================================================

import { dom } from '../core/dom.js';
import { state } from '../core/state.js';

import {
    toggleNavigationMode,
    setOrbitMode,
    setFlyMode,
    resetCamera
} from '../controls/navigation.js';

import {
    toggleMeasurement
} from '../features/measurement.js';

import {
    toggleLighting,
    setLightIntensity,
    toggleGrid
} from '../viewer/lighting.js';

import {
    startRouteDrawing,
    clearRoute,
    startRouteFlythrough
} from '../features/route.js';


// ============================================================
// NAVIGATION
// ============================================================

function handleOrbitClick() {
    setOrbitMode();
}


function handleFlyClick() {
    setFlyMode();
}


function handleNavigationToggle() {
    toggleNavigationMode();
}


function handleResetClick() {
    resetCamera();
}


// ============================================================
// GRID
// ============================================================

function handleGridClick() {
    toggleGrid();
}


// ============================================================
// MEASUREMENT
// ============================================================

function handleMeasureClick() {
    toggleMeasurement();
}


// ============================================================
// LIGHTING
// ============================================================

function handleLightingClick() {
    toggleLighting();
}


function handleLightSlider(event) {

    const value = Number(event.target.value);

    setLightIntensity(value);

}


// ============================================================
// ROUTE
// ============================================================

function handleDrawRouteClick() {
    startRouteDrawing();
}


function handleClearRouteClick() {
    clearRoute();
}


function handleFlyRouteClick() {
    startRouteFlythrough();
}


// ============================================================
// BUTTON STATE HELPERS
// ============================================================

export function updateNavigationButtons() {

    if (dom.orbitBtn) {
        dom.orbitBtn.classList.toggle(
            'active',
            !state.flyMode
        );
    }

    if (dom.flyBtn) {
        dom.flyBtn.classList.toggle(
            'active',
            state.flyMode
        );
    }

}


export function updateGridButton() {

    if (!dom.gridBtn) {
        return;
    }

    dom.gridBtn.classList.toggle(
        'active',
        state.gridVisible
    );

}


export function updateMeasurementButton(active) {

    if (!dom.measureBtn) {
        return;
    }

    dom.measureBtn.classList.toggle(
        'active',
        Boolean(active)
    );

}


// ============================================================
// INITIALIZE ALL UI CONTROLS
// ============================================================

export function initControlsUI() {

    // --------------------------------------------------------
    // Navigation
    // --------------------------------------------------------

    if (dom.orbitBtn) {
        dom.orbitBtn.addEventListener(
            'click',
            handleOrbitClick
        );
    }

    if (dom.flyBtn) {
        dom.flyBtn.addEventListener(
            'click',
            handleFlyClick
        );
    }

    if (dom.resetBtn) {
        dom.resetBtn.addEventListener(
            'click',
            handleResetClick
        );
    }


    // --------------------------------------------------------
    // Navigation toggle
    // --------------------------------------------------------

    const navigationToggleBtn =
        document.getElementById('navigationToggleBtn');

    if (navigationToggleBtn) {
        navigationToggleBtn.addEventListener(
            'click',
            handleNavigationToggle
        );
    }


    // --------------------------------------------------------
    // Grid
    // --------------------------------------------------------

    if (dom.gridBtn) {
        dom.gridBtn.addEventListener(
            'click',
            handleGridClick
        );
    }


    // --------------------------------------------------------
    // Measurement
    // --------------------------------------------------------

    if (dom.measureBtn) {
        dom.measureBtn.addEventListener(
            'click',
            handleMeasureClick
        );
    }


    // --------------------------------------------------------
    // Lighting
    // --------------------------------------------------------

    if (dom.lightingBtn) {
        dom.lightingBtn.addEventListener(
            'click',
            handleLightingClick
        );
    }

    if (dom.lightSlider) {
        dom.lightSlider.addEventListener(
            'input',
            handleLightSlider
        );
    }


    // --------------------------------------------------------
    // Route
    // --------------------------------------------------------

    if (dom.drawRouteBtn) {
        dom.drawRouteBtn.addEventListener(
            'click',
            handleDrawRouteClick
        );
    }

    if (dom.clearRouteBtn) {
        dom.clearRouteBtn.addEventListener(
            'click',
            handleClearRouteClick
        );
    }

    if (dom.flyRouteBtn) {
        dom.flyRouteBtn.addEventListener(
            'click',
            handleFlyRouteClick
        );
    }


    // --------------------------------------------------------
    // Initial UI state
    // --------------------------------------------------------

    updateNavigationButtons();
    updateGridButton();

}