// ============================================================
// DEPTHWIZARD
// LIGHTING + GRID SYSTEM
// ============================================================

import * as THREE from 'three';

import { scene } from './scene.js';
import { dom } from '../core/dom.js';
import { state } from '../core/state.js';
import { CONFIG } from '../core/constants.js';
import { setGridStatus } from '../ui/status.js';


// ============================================================
// LIGHTS
// ============================================================

// Main ambient illumination
export const ambientLight = new THREE.AmbientLight(
    0xffffff,
    1.6
);


// Main directional sunlight
export const directionalLight = new THREE.DirectionalLight(
    0xffffff,
    2.0
);

directionalLight.position.set(
    250,
    500,
    250
);

directionalLight.castShadow = true;

directionalLight.shadow.mapSize.width = 2048;
directionalLight.shadow.mapSize.height = 2048;

directionalLight.shadow.camera.near = 0.5;
directionalLight.shadow.camera.far = 2000;

directionalLight.shadow.camera.left = -1000;
directionalLight.shadow.camera.right = 1000;
directionalLight.shadow.camera.top = 1000;
directionalLight.shadow.camera.bottom = -1000;


// Secondary cool fill light
export const secondaryLight = new THREE.DirectionalLight(
    0x38bdf8,
    0.8
);

secondaryLight.position.set(
    -200,
    -200,
    -200
);


// Add lights to scene
scene.add(
    ambientLight,
    directionalLight,
    secondaryLight
);


// ============================================================
// GRID
// ============================================================

export const gridHelper = new THREE.GridHelper(
    CONFIG.GRID_SIZE,
    CONFIG.GRID_DIVISIONS,
    0xffffff, // Center line color (Pure White)
    0x8a9bb2  // Grid line color (Soft Light Blue-Gray)
);

gridHelper.position.y = 0;
gridHelper.visible = true;

scene.add(gridHelper);


// ============================================================
// LIGHTING STATE
// ============================================================

let lightIntensity = 2.0;


// ============================================================
// UPDATE LIGHTING BUTTON UI
// ============================================================

function updateLightingButton() {

    if (!dom.lightingBtn) {
        return;
    }

    dom.lightingBtn.classList.toggle(
        'active',
        state.lightingEnabled
    );

    dom.lightingBtn.textContent =
        state.lightingEnabled ? 'ON' : 'OFF';

}


// ============================================================
// UPDATE LIGHT VALUE DISPLAY
// ============================================================

function updateLightValue() {

    if (!dom.lightValue) {
        return;
    }

    dom.lightValue.textContent =
        lightIntensity.toFixed(1);

}


// ============================================================
// APPLY TIME OF DAY (SUN DYNAMICS)
// ============================================================

export function setTimeOfDay(hours) {

    // Clamp between 6.0 (6 AM) and 18.0 (6 PM)
    const time = Math.max(6, Math.min(18, Number(hours)));
    
    // Map 6..18 to an angle from 0 to PI (180 degrees)
    const angle = ((time - 6) / 12) * Math.PI;
    
    // 1. Calculate Sun Position over the terrain
    const radius = 1000;
    const sunX = Math.cos(angle) * -radius;
    const sunY = Math.sin(angle) * radius;
    const sunZ = Math.cos(angle) * 300; // Slight tilt on Z axis
    
    directionalLight.position.set(sunX, sunY, sunZ);
    
    // 2. Calculate Brightness (peaks at noon / PI/2)
    const intensityMultiplier = Math.max(0.1, Math.sin(angle));
    directionalLight.intensity = intensityMultiplier * 2.8;
    ambientLight.intensity = 0.6 + (intensityMultiplier * 1.0);
    
    // 3. Calculate Color Temperature
    // Warm orange/yellow at dawn/dusk, crisp white at midday
    const color = new THREE.Color();
    const isNoon = Math.sin(angle);
    color.setHSL(0.1 + (isNoon * 0.05), 1.0 - (isNoon * 0.5), 0.5 + (isNoon * 0.5));
    directionalLight.color = color;
    
    // 4. Update UI Text (HH:MM format)
    if (dom.lightValue) {
        const h = Math.floor(time);
        const m = Math.floor((time - h) * 60).toString().padStart(2, '0');
        dom.lightValue.textContent = `${h}:${m}`;
    }
}


// ============================================================
// LIGHTING ON / OFF
// ============================================================

export function setLightingEnabled(enabled) {

    state.lightingEnabled = Boolean(enabled);

    ambientLight.visible =
        state.lightingEnabled;

    directionalLight.visible =
        state.lightingEnabled;

    secondaryLight.visible =
        state.lightingEnabled;

    updateLightingButton();

}


// ============================================================
// TOGGLE LIGHTING
// ============================================================

export function toggleLighting() {

    setLightingEnabled(
        !state.lightingEnabled
    );

}


// ============================================================
// GRID ON / OFF
// ============================================================

export function setGridVisible(visible) {

    state.gridVisible = Boolean(visible);

    gridHelper.visible =
        state.gridVisible;

    updateGridButton();

    setGridStatus(
        state.gridVisible
    );

}


// ============================================================
// UPDATE GRID BUTTON UI
// ============================================================

function updateGridButton() {

    if (!dom.gridBtn) {
        return;
    }

    dom.gridBtn.classList.toggle(
        'active',
        state.gridVisible
    );

    dom.gridBtn.textContent =
        state.gridVisible
            ? '▦ Grid On'
            : '▦ Grid Off';

}


// ============================================================
// TOGGLE GRID
// ============================================================

export function toggleGrid() {

    setGridVisible(
        !state.gridVisible
    );

}


// ============================================================
// INITIALIZE VISUALIZATION
// ============================================================

export function initLighting() {

    // Default state
    state.lightingEnabled = true;
    state.gridVisible = true;

    setTimeOfDay(12); // Start at Noon
    setLightingEnabled(state.lightingEnabled);
    setGridVisible(state.gridVisible);
}