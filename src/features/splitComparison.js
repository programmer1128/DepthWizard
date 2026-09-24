// ============================================================
// DEPTHWIZARD
// OPTICAL <-> ELEVATION SPLIT COMPARISON
// Stable MeshStandardMaterial shader patch. No runtime shader
// string mutation after the material has been compiled.
// ============================================================

import * as THREE from 'three';

import { camera, renderer } from '../viewer/scene.js';
import { dom } from '../core/dom.js';
import { state } from '../core/state.js';
import { setViewerStatus } from '../ui/status.js';

const PATCH_KEY = 'depthwizard-split-comparison-v2';

let dividerDragging = false;
let initialized = false;

function clamp(value, min, max) {
    return Math.max(min, Math.min(max, value));
}

function getRendererResolution() {
    return new THREE.Vector2(
        renderer.domElement.width || 1,
        renderer.domElement.height || 1
    );
}

function updateUniformsForMaterial(material) {
    const uniforms = material?.userData?.depthWizardSplit?.uniforms;
    if (!uniforms) return;

    uniforms.uSplit.value = state.comparisonSplit;
    uniforms.uSplitEnabled.value = state.comparisonEnabled ? 1 : 0;
    uniforms.uElevationOpacity.value = state.comparisonElevationOpacity;
    uniforms.uResolution.value.copy(getRendererResolution());
}

function patchMaterial(material) {
    if (!material || !(
        material.isMeshStandardMaterial ||
        material.isMeshPhysicalMaterial
    )) {
        return;
    }

    if (material.userData.depthWizardSplit) {
        updateUniformsForMaterial(material);
        return;
    }

    const uniforms = {
        uSplit: { value: state.comparisonSplit },
        uSplitEnabled: { value: 0 },
        uElevationOpacity: { value: state.comparisonElevationOpacity },
        uResolution: { value: getRendererResolution() },
        uMinY: { value: 0 },
        uMaxY: { value: 1 }
    };

    const originalOnBeforeCompile = material.onBeforeCompile;

    material.userData.depthWizardSplit = {
        uniforms,
        originalOnBeforeCompile
    };

    const originalCacheKey = typeof material.customProgramCacheKey === 'function'
        ? material.customProgramCacheKey.bind(material)
        : null;
    material.customProgramCacheKey = () => `${originalCacheKey ? originalCacheKey() : 'standard'}|${PATCH_KEY}`;

    material.onBeforeCompile = (shader, rendererInstance) => {
        if (typeof originalOnBeforeCompile === 'function') {
            originalOnBeforeCompile(shader, rendererInstance);
        }

        Object.assign(shader.uniforms, uniforms);

        shader.vertexShader = shader.vertexShader.replace(
            '#include <common>',
            `#include <common>\nvarying float vDWWorldY;`
        );

        shader.vertexShader = shader.vertexShader.replace(
            '#include <project_vertex>',
            `\nvDWWorldY = (modelMatrix * vec4(transformed, 1.0)).y;\n#include <project_vertex>`
        );

        shader.fragmentShader = shader.fragmentShader.replace(
            '#include <common>',
            `#include <common>\nvarying float vDWWorldY;\nuniform float uSplit;\nuniform float uSplitEnabled;\nuniform float uElevationOpacity;\nuniform vec2 uResolution;\nuniform float uMinY;\nuniform float uMaxY;`
        );

        shader.fragmentShader = shader.fragmentShader.replace(
            '#include <output_fragment>',
            `
                // Preserve the renderer's fully lit, textured optical result first.
                #include <output_fragment>

                float dwNormalizedHeight = clamp(
                    (vDWWorldY - uMinY) / max(uMaxY - uMinY, 0.0001),
                    0.0,
                    1.0
                );

                // Scientific elevation ramp: low -> cyan -> yellow -> high.
                vec3 dwLow = vec3(0.025, 0.18, 0.52);
                vec3 dwMidLow = vec3(0.02, 0.78, 0.82);
                vec3 dwMidHigh = vec3(0.95, 0.84, 0.20);
                vec3 dwHigh = vec3(0.85, 0.15, 0.08);
                vec3 dwElevationColor;

                if (dwNormalizedHeight < 0.34) {
                    dwElevationColor = mix(dwLow, dwMidLow, smoothstep(0.0, 0.34, dwNormalizedHeight));
                } else if (dwNormalizedHeight < 0.70) {
                    dwElevationColor = mix(dwMidLow, dwMidHigh, smoothstep(0.34, 0.70, dwNormalizedHeight));
                } else {
                    dwElevationColor = mix(dwMidHigh, dwHigh, smoothstep(0.70, 1.0, dwNormalizedHeight));
                }

                // Horn-style analytical relief: directional light + subtle contour bands.
                vec3 dwN = normalize(normal);
                float dwLight = 0.42 + 0.58 * max(dot(dwN, normalize(vec3(0.42, 0.86, 0.28))), 0.0);
                float dwContour = smoothstep(0.42, 0.52, abs(fract(dwNormalizedHeight * 12.0) - 0.5));
                dwElevationColor *= dwLight;
                dwElevationColor = mix(dwElevationColor * 0.88, dwElevationColor, dwContour);

                float dwViewportX = gl_FragCoord.x / max(uResolution.x, 1.0);
                float dwMask = (uSplitEnabled > 0.5) ? step(uSplit, dwViewportX) : 0.0;
                float dwAmount = dwMask * clamp(uElevationOpacity, 0.0, 1.0);

                // Mix AFTER the standard output so the optical texture is never discarded.
                gl_FragColor.rgb = mix(gl_FragColor.rgb, dwElevationColor, dwAmount);
            `
        );
    };

    material.needsUpdate = true;
}

export function patchTerrainModel(model) {
    if (!model) return;

    model.traverse((child) => {
        if (!child.isMesh) return;

        const materials = Array.isArray(child.material)
            ? child.material
            : [child.material];

        materials.forEach(patchMaterial);
    });

    updateComparisonBounds(model);
}

export function updateComparisonBounds(model = state.terrainModel) {
    if (!model) return;

    const box = new THREE.Box3().setFromObject(model);
    const minY = Number.isFinite(box.min.y) ? box.min.y : 0;
    const maxY = Number.isFinite(box.max.y) ? box.max.y : minY + 1;

    state.terrainComparisonBounds = {
        minY,
        maxY
    };

    model.traverse((child) => {
        if (!child.isMesh) return;

        const materials = Array.isArray(child.material)
            ? child.material
            : [child.material];

        materials.forEach((material) => {
            const uniforms = material?.userData?.depthWizardSplit?.uniforms;
            if (!uniforms) return;
            uniforms.uMinY.value = minY;
            uniforms.uMaxY.value = maxY;
            updateUniformsForMaterial(material);
        });
    });
}

export function setComparisonEnabled(enabled) {
    state.comparisonEnabled = Boolean(enabled);

    if (state.comparisonEnabled && state.terrainModel) {
        // The split shader owns the elevation appearance while active.
        state.heatmapEnabled = false;
        dom.heatmapBtn?.classList.remove('active');

        // Keep the optical material as the underlying source on the left.
        state.terrainModel.traverse((child) => {
            if (!child.isMesh || !child.userData.originalMaterial) return;
            child.material = child.userData.originalMaterial;
        });
    }

    if (state.terrainModel) {
        patchTerrainModel(state.terrainModel);
    }

    if (dom.splitComparisonOverlay) {
        dom.splitComparisonOverlay.classList.toggle('hidden', !state.comparisonEnabled);
    }

    if (dom.splitCompareBtn) {
        dom.splitCompareBtn.classList.toggle('active', state.comparisonEnabled);
        dom.splitCompareBtn.innerHTML = state.comparisonEnabled
            ? '<span class="split-icon">⇆</span> Live Split · ON'
            : '<span class="split-icon">⇆</span> Compare Optical / Elevation';
    }

    setViewerStatus(
        state.comparisonEnabled
            ? 'OPTICAL / ELEVATION COMPARISON ACTIVE'
            : '3D VIEWER READY',
        'ready'
    );

    updateSplitUI();
}

export function setSplitPosition(value) {
    state.comparisonSplit = clamp(Number(value) || 0.5, 0.05, 0.95);
    updateSplitUI();
}

export function setElevationOpacity(value) {
    state.comparisonElevationOpacity = clamp(Number(value) || 1, 0, 1);
    updateSplitUI();
}

function updateSplitUI() {
    const split = state.comparisonSplit * 100;

    if (dom.splitComparisonOverlay) {
        dom.splitComparisonOverlay.style.setProperty('--split-position', `${split}%`);
    }

    if (dom.splitDividerValue) {
        dom.splitDividerValue.textContent = `${split.toFixed(0)} / ${(100 - split).toFixed(0)}`;
    }

    if (dom.splitOpacityValue) {
        dom.splitOpacityValue.textContent = `${Math.round(state.comparisonElevationOpacity * 100)}%`;
    }

    if (dom.splitOpacitySlider &&
        Number(dom.splitOpacitySlider.value) !== Math.round(state.comparisonElevationOpacity * 100)) {
        dom.splitOpacitySlider.value = String(Math.round(state.comparisonElevationOpacity * 100));
    }

    if (state.terrainModel) {
        state.terrainModel.traverse((child) => {
            if (!child.isMesh) return;
            const materials = Array.isArray(child.material)
                ? child.material
                : [child.material];
            materials.forEach(updateUniformsForMaterial);
        });
    }
}

function updateSplitFromPointer(clientX) {
    if (!dom.splitComparisonOverlay) return;

    const rect = dom.splitComparisonOverlay.getBoundingClientRect();
    if (!rect.width) return;

    setSplitPosition((clientX - rect.left) / rect.width);
}

function beginDividerDrag(event) {
    if (!state.comparisonEnabled) return;
    dividerDragging = true;
    dom.splitDivider?.classList.add('dragging');
    updateSplitFromPointer(event.clientX);
    event.preventDefault();
    event.stopPropagation();
}

function moveDivider(event) {
    if (!dividerDragging) return;
    updateSplitFromPointer(event.clientX);
    event.preventDefault();
}

function endDividerDrag() {
    dividerDragging = false;
    dom.splitDivider?.classList.remove('dragging');
}

function resetSplit() {
    setSplitPosition(0.5);
    setElevationOpacity(1);
}

export function initSplitComparison() {
    if (initialized) return;
    initialized = true;

    dom.splitCompareBtn?.addEventListener('click', () => {
        if (!state.terrainModel) {
            setViewerStatus('LOAD TERRAIN BEFORE STARTING COMPARISON', 'error');
            return;
        }
        setComparisonEnabled(!state.comparisonEnabled);
    });

    dom.splitDivider?.addEventListener('pointerdown', (event) => {
        beginDividerDrag(event);
        dom.splitDivider?.setPointerCapture?.(event.pointerId);
    });
    dom.splitDivider?.addEventListener('keydown', (event) => {
        if (!state.comparisonEnabled) return;
        const step = event.shiftKey ? 0.10 : 0.02;
        if (event.key === 'ArrowLeft') { setSplitPosition(state.comparisonSplit - step); event.preventDefault(); }
        if (event.key === 'ArrowRight') { setSplitPosition(state.comparisonSplit + step); event.preventDefault(); }
        if (event.key === 'Home') { setSplitPosition(0.05); event.preventDefault(); }
        if (event.key === 'End') { setSplitPosition(0.95); event.preventDefault(); }
    });
    window.addEventListener('pointermove', moveDivider, { passive: false });
    window.addEventListener('pointerup', (event) => {
        try { dom.splitDivider?.releasePointerCapture?.(event.pointerId); } catch (_) {}
        endDividerDrag();
    });
    dom.splitResetBtn?.addEventListener('click', resetSplit);

    dom.splitOpacitySlider?.addEventListener('input', (event) => {
        setElevationOpacity(Number(event.target.value) / 100);
    });

    window.addEventListener('resize', () => {
        if (!state.terrainModel) return;
        updateComparisonBounds(state.terrainModel);
        updateSplitUI();
    });

    updateSplitUI();
}

export function updateSplitComparison() {
    if (!initialized || !state.terrainModel) return;
    updateSplitUI();
}

export function isSplitComparisonEnabled() {
    return Boolean(state.comparisonEnabled);
}

export function getSplitComparisonState() {
    return {
        enabled: state.comparisonEnabled,
        split: state.comparisonSplit,
        elevationOpacity: state.comparisonElevationOpacity,
        cameraPosition: camera.position.clone()
    };
}
