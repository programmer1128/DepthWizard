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
    resetCamera,
    orbitControls
} from '../controls/navigation.js';

import {
    toggleMeasurement
} from '../features/measurement.js';

import {
    toggleLighting,
    setTimeOfDay,
    toggleGrid
} from '../viewer/lighting.js';

// ---> ADD THIS IMPORT <---
import {
    updateTerrainHeatmap,
    setVerticalExaggeration
} from '../viewer/terrain.js';

import {
    setComparisonEnabled,
    isSplitComparisonEnabled
} from '../features/splitComparison.js';

import {
    startRouteDrawing,
    stopRouteDrawing, // <-- Add this
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

function handleAutoRotateClick() {
    state.autoRotateEnabled = !state.autoRotateEnabled;
    
    updateAutoRotateButton();
    
    // Immediately apply to the camera
    orbitControls.autoRotate = state.autoRotateEnabled && !state.flyMode && !state.isFlyingRoute;
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
    if (state.metricMode !== 'metric') {
        if (dom.coordinates) {
            dom.coordinates.textContent = 'Metric measurement locked — upload a metric GeoTIFF.';
        }
        return;
    }
    toggleMeasurement();
}


// ============================================================
// LIGHTING
// ============================================================

function handleLightingClick() {
    toggleLighting();
}


function handleLightSlider(event) 
{
    const value = Number(event.target.value);
    setTimeOfDay(value);
}

function handleVerticalExaggeration(event) {
    const value = setVerticalExaggeration(Number(event.target.value));

    if (dom.verticalExaggerationValue) {
        dom.verticalExaggerationValue.textContent = `${value.toFixed(2)}×`;
    }
}

/*function handleHeatmapClick() {
    // Toggle the state
    state.heatmapEnabled = !state.heatmapEnabled;
    
    // Update the UI button styling and text
    if (dom.heatmapBtn) {
        if (state.heatmapEnabled) {
            dom.heatmapBtn.classList.add('active-green');
            dom.heatmapBtn.textContent = 'ON';
        } else {
            dom.heatmapBtn.classList.remove('active-green');
            dom.heatmapBtn.textContent = 'OFF';
        }
    }
    
    // Apply the material swap to the 3D model
    updateTerrainHeatmap();
}*/

function handleHeatmapClick() {
    if (isSplitComparisonEnabled()) {
        setComparisonEnabled(false);
    }

    state.heatmapEnabled = !state.heatmapEnabled;
    
    // Highlight the big button in cyan when active
    if (dom.heatmapBtn) {
        dom.heatmapBtn.classList.toggle('active', state.heatmapEnabled);
    }
    
    updateTerrainHeatmap();
}


// ============================================================
// ROUTE
// ============================================================

function handleDrawRouteClick() {
    if (state.isDrawingRoute) {
        stopRouteDrawing();
        if (dom.drawRouteBtn) {
            dom.drawRouteBtn.classList.remove('active');
        }
    } else {
        startRouteDrawing();
        if (dom.drawRouteBtn) {
            dom.drawRouteBtn.classList.add('active');
        }
    }
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


export function updateAutoRotateButton() {
    const enabled = Boolean(state.autoRotateEnabled);
    dom.autoRotateBtn?.classList.toggle('active', enabled);
    if (dom.autoRotateBtn) {
        dom.autoRotateBtn.textContent = enabled ? '⟳ Auto ON' : '⟳ Auto OFF';
        dom.autoRotateBtn.setAttribute('aria-pressed', String(enabled));
    }
    const badge = document.getElementById('autoRotateBadge');
    if (badge) badge.textContent = enabled ? 'AUTO ON' : 'AUTO OFF';
}

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

    if (dom.autoRotateBtn) 
    {
        dom.autoRotateBtn.addEventListener('click', handleAutoRotateClick);
    }

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

    // ---> ADD THIS EVENT LISTENER <---
    if (dom.heatmapBtn) {
        dom.heatmapBtn.addEventListener(
            'click',
            handleHeatmapClick
        );
    }

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

    if (dom.verticalExaggerationSlider) {
        dom.verticalExaggerationSlider.addEventListener(
            'input',
            handleVerticalExaggeration
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
    updateAutoRotateButton();

}