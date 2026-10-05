// ============================================================
// DEPTHWIZARD
// BASELINE CAPTURE MODE (tools/baseline in the backend repository)
// ============================================================
//
// Opt-in only: main.js imports this module when the page URL carries
// ?baselineGlb=<url>. It loads that GLB through the normal viewer path, pins
// visual settings that vary between sessions, and places the camera at a
// fixed preset relative to the model's bounds, so screenshots of the same
// geometry are reproducible. window.__DW_BASELINE reports readiness to the
// screenshot script.

import { camera } from '../viewer/scene.js';
import { orbitControls } from '../controls/navigation.js';
import { state } from '../core/state.js';
import { loadTerrainGLB } from '../viewer/terrain.js';

// Azimuth from +X towards +Z (south), elevation above the horizon, and
// distance as a multiple of the model's horizontal extent.
export const BASELINE_CAMERAS = {
    overview: { azimuthDeg: 135, elevationDeg: 35, distance: 1.1 },
    oblique: { azimuthDeg: 110, elevationDeg: 18, distance: 0.8 },
    top: { azimuthDeg: 90, elevationDeg: 89, distance: 1.2 }
};

function nextFrames(count) {
    return new Promise((resolve) => {
        const step = (remaining) => remaining <= 0
            ? resolve()
            : requestAnimationFrame(() => step(remaining - 1));
        step(count);
    });
}

export async function runBaselineCapture(params) {

    window.__DW_BASELINE = { ready: false };
    const glbUrl = params.get('baselineGlb');
    const presetName = params.get('baselineCamera') || 'overview';
    const preset = BASELINE_CAMERAS[presetName];

    try {
        if (!preset) {
            throw new Error(`Unknown baselineCamera '${presetName}'`);
        }

        state.autoRotateEnabled = false;
        orbitControls.autoRotate = false;
        state.verticalExaggeration = 1;

        await loadTerrainGLB(glbUrl);

        const size = state.terrainBounds.size;
        const extent = Math.max(size.x, size.z, 1);
        const azimuth = preset.azimuthDeg * Math.PI / 180;
        const elevation = preset.elevationDeg * Math.PI / 180;
        const radius = extent * preset.distance;

        // The viewer centres the model on the origin.
        orbitControls.target.set(0, 0, 0);
        camera.position.set(
            radius * Math.cos(elevation) * Math.cos(azimuth),
            radius * Math.sin(elevation),
            radius * Math.cos(elevation) * Math.sin(azimuth)
        );
        camera.up.set(0, 1, 0);
        camera.lookAt(0, 0, 0);
        orbitControls.update();

        // Let the render loop draw the final pose.
        await nextFrames(5);

        window.__DW_BASELINE = {
            ready: true,
            camera: presetName,
            glb: glbUrl,
            extentMetres: extent,
            heightMetres: size.y
        };

    } catch (error) {
        window.__DW_BASELINE = { ready: true, error: String(error?.message || error) };
    }
}
