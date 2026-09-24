// ============================================================
// DEPTHWIZARD
// SESSION / VIEW EXPORTS
// ============================================================

import { renderer } from '../viewer/scene.js';
import { dom } from '../core/dom.js';
import { state } from '../core/state.js';

function downloadBlob(blob, filename) {
    const url = URL.createObjectURL(blob);
    const anchor = document.createElement('a');
    anchor.href = url;
    anchor.download = filename;
    document.body.appendChild(anchor);
    anchor.click();
    anchor.remove();
    setTimeout(() => URL.revokeObjectURL(url), 1000);
}

function downloadText(text, filename, type = 'application/json') {
    downloadBlob(new Blob([text], { type }), filename);
}

function exportAnalysisSnapshot() {
    const payload = {
        project: 'DepthWizard 3D Workstation',
        generatedAt: new Date().toISOString(),
        scientificMode: state.metricMode,
        verticalExaggeration: state.verticalExaggeration,
        splitComparison: {
            enabled: state.comparisonEnabled,
            split: state.comparisonSplit,
            elevationOpacity: state.comparisonElevationOpacity
        },
        measurement: state.lastMeasurement || null,
        clickedPoint: state.lastClickedPoint || null,
        route: {
            waypointCount: state.routeWaypoints.length,
            distance: state.routeDistance
        },
        flood: {
            seeded: Boolean(state.floodSeedPoint),
            waterLevel: state.floodWaterLevel
        },
        terrainUrl: state.currentLoadedUrl || null,
        uuid: state.currentUuid || null
    };

    downloadText(
        JSON.stringify(payload, null, 2),
        'depthwizard-analysis-snapshot.json'
    );

    if (dom.exportStatus) {
        dom.exportStatus.textContent = 'Analysis snapshot downloaded.';
    }
}

function captureViewport() {
    try {
        const link = document.createElement('a');
        link.href = renderer.domElement.toDataURL('image/png');
        link.download = 'depthwizard-viewport.png';
        document.body.appendChild(link);
        link.click();
        link.remove();
        if (dom.exportStatus) dom.exportStatus.textContent = 'Viewport image saved.';
    } catch (error) {
        if (dom.exportStatus) dom.exportStatus.textContent = 'Viewport capture unavailable in this browser.';
    }
}

async function exportLoadedTerrain() {
    if (!state.currentLoadedUrl) {
        if (dom.exportStatus) dom.exportStatus.textContent = 'Load a GLB terrain before exporting.';
        return;
    }

    try {
        const response = await fetch(state.currentLoadedUrl);
        if (!response.ok) throw new Error(`HTTP ${response.status}`);
        const blob = await response.blob();
        downloadBlob(blob, 'depthwizard-terrain.glb');
        if (dom.exportStatus) dom.exportStatus.textContent = 'Terrain GLB downloaded.';
    } catch (error) {
        if (dom.exportStatus) {
            dom.exportStatus.textContent = 'Terrain export blocked by the source server (CORS or network).';
        }
    }
}

export function initExports() {
    dom.exportSnapshotBtn?.addEventListener('click', exportAnalysisSnapshot);
    dom.exportPngBtn?.addEventListener('click', captureViewport);
    dom.exportTerrainBtn?.addEventListener('click', exportLoadedTerrain);
}
