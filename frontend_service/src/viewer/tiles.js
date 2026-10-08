// ============================================================
// DEPTHWIZARD
// 3D TILES SUPPORT
// ============================================================

import * as THREE from 'three';

import {
    scene,
    camera,
    renderer
} from './scene.js';

import {
    state
} from '../core/state.js';

// ============================================================
// 3D TILES RENDERER
// ============================================================

// Loaded dynamically so the application can still work
// when the backend returns a normal GLB file.

let TilesRendererClass = null;

// ============================================================
// LOAD 3D TILES
// ============================================================

export async function loadTiles(url) {

    if (!url) {
        throw new Error(
            'No 3D Tiles URL provided.'
        );
    }

    // --------------------------------------------------------
    // Load library only when needed
    // --------------------------------------------------------

    if (!TilesRendererClass) {

        const module =
            await import(
                '3d-tiles-renderer'
            );

        TilesRendererClass =
            module.TilesRenderer;
    }

    // --------------------------------------------------------
    // Remove previous tileset
    // --------------------------------------------------------

    disposeTiles();

    // --------------------------------------------------------
    // Create renderer
    // --------------------------------------------------------

    const tilesRenderer =
        new TilesRendererClass(url);

    // --------------------------------------------------------
    // Connect Three.js renderer
    // --------------------------------------------------------

    tilesRenderer.setCamera(
        camera
    );

    tilesRenderer.setResolutionFromRenderer(
        camera,
        renderer
    );

    // --------------------------------------------------------
    // Store in application state
    // --------------------------------------------------------

    state.tilesRenderer =
        tilesRenderer;

    // --------------------------------------------------------
    // Add to scene
    // --------------------------------------------------------

    scene.add(
        tilesRenderer.group
    );

    console.log(
        'DepthWizard 3D Tiles loaded:',
        url
    );

    return tilesRenderer;
}

// ============================================================
// UPDATE TILES
// ============================================================

export function updateTiles() {

    if (
        !state.tilesRenderer
    ) {
        return;
    }

    state.tilesRenderer.setCamera(
        camera
    );

    state.tilesRenderer.setResolutionFromRenderer(
        camera,
        renderer
    );

    state.tilesRenderer.update();
}

// ============================================================
// DISPOSE TILES
// ============================================================

export function disposeTiles() {

    if (
        !state.tilesRenderer
    ) {
        return;
    }

    const tilesRenderer =
        state.tilesRenderer;

    // Remove from scene
    if (
        tilesRenderer.group
    ) {

        scene.remove(
            tilesRenderer.group
        );
    }

    // Dispose renderer
    if (
        typeof tilesRenderer.dispose ===
        'function'
    ) {

        tilesRenderer.dispose();
    }

    state.tilesRenderer =
        null;
}

// ============================================================
// CHECK WHETHER TILES ARE ACTIVE
// ============================================================

export function hasTiles() {

    return Boolean(
        state.tilesRenderer
    );
}