// ============================================================
// DEPTHWIZARD
// SCIENTIFIC WORKSTATION UI + TACTICAL HUD
// ============================================================

import * as THREE from 'three';

import { camera } from '../viewer/scene.js';
import { dom } from '../core/dom.js';
import { state } from '../core/state.js';

function setToolLocked(button, locked, title) {
    if (!button) return;
    button.disabled = locked;
    button.classList.toggle('locked', locked);
    if (title) button.title = title;
}

export function setScientificDataMode(mode) {
    const normalized = mode === 'metric'
        ? 'metric'
        : mode === 'dimensionless'
            ? 'dimensionless'
            : mode === 'demo'
                ? 'demo'
                : 'unknown';

    state.metricMode = normalized;

    const isMetric = normalized === 'metric';

    const config = {
        metric: {
            label: 'DATUM-RESOLVED METRIC DSM',
            short: 'METRIC DSM',
            className: 'metric',
            copy: 'Metric-sensitive tools are available for this input mode.'
        },
        dimensionless: {
            label: 'DIMENSIONLESS rDSM',
            short: 'RELATIVE / rDSM',
            className: 'dimensionless',
            copy: 'Absolute metre claims are locked for uncalibrated optical input.'
        },
        demo: {
            label: 'DEMO TERRAIN / RELATIVE',
            short: 'DEMO DATA',
            className: 'demo',
            copy: 'Sample terrain loaded • treat measurements as demonstration values.'
        },
        unknown: {
            label: 'AWAITING DATA / TOOLS LOCKED',
            short: 'NO DATA',
            className: 'unknown',
            copy: 'Select an input type before using metric-sensitive analysis tools.'
        }
    }[normalized];

    if (dom.scientificBadge) {
        dom.scientificBadge.textContent = config.label;
        dom.scientificBadge.className = `scientific-badge ${config.className}`;
    }

    if (dom.topScientificBadge) {
        dom.topScientificBadge.textContent = config.short;
        dom.topScientificBadge.className = `scientific-badge ${config.className}`;
    }

    if (dom.scientificBadgeDetail) {
        dom.scientificBadgeDetail.textContent = config.copy;
    }

    if (dom.dataModeText) {
        dom.dataModeText.textContent = config.short;
    }

    const lockMessage = isMetric
        ? (state.currentUuid
            ? 'Metric tools unlocked for the active metric terrain.'
            : 'Upload/process the metric input before benchmark comparison.')
        : 'Locked: upload a metric GeoTIFF to enable absolute elevation comparison.';

    setToolLocked(dom.measureBtn, !isMetric, lockMessage);
    setToolLocked(dom.compareBtn, !isMetric || !state.currentUuid, lockMessage);

    if (dom.metricLockNote) {
        dom.metricLockNote.textContent = isMetric
            ? 'Metric measurement enabled • vertical exaggeration is corrected before reporting.'
            : 'Metric measurement and benchmark comparison are locked until a metric GeoTIFF is supplied.';
        dom.metricLockNote.classList.toggle('is-locked', !isMetric);
    }
}

export function setMetricToolAvailability(enabled) {
    const locked = !enabled;
    const message = enabled
        ? 'Metric tool available.'
        : 'Locked in dimensionless mode.';
    setToolLocked(dom.measureBtn, locked, message);
    setToolLocked(dom.compareBtn, locked, message);
}

export function updateVerticalExaggerationUI(value) {
    const numeric = Number(value) || 1;
    if (dom.verticalExaggerationValue) {
        dom.verticalExaggerationValue.textContent = `${numeric.toFixed(2)}×`;
    }
}

export function updateTacticalHUD() {
    if (!dom.tacticalHud) return;

    const p = camera.position;
    const speed = state.tacticalSpeed || 0;
    const heading = getHeadingDegrees();
    const elevation = state.lastClickedPoint?.meshElevation;

    if (dom.hudAltitude) dom.hudAltitude.textContent = `${Math.abs(p.y).toFixed(1)}`;
    if (dom.hudHeading) dom.hudHeading.textContent = `${heading.toFixed(0)}°`;
    if (dom.hudSpeed) dom.hudSpeed.textContent = `${speed.toFixed(1)} u/s`;
    if (dom.hudElevation) {
        dom.hudElevation.textContent = Number.isFinite(elevation)
            ? `${elevation.toFixed(1)}${state.metricMode === 'metric' ? ' m' : ' rel.'}`
            : '—';
    }
    if (dom.hudDataMode) {
        dom.hudDataMode.textContent = state.metricMode === 'metric' ? 'METRIC' : 'RELATIVE';
    }
}

function getHeadingDegrees() {
    const forward = new THREE.Vector3(0, 0, -1)
        .applyQuaternion(camera.quaternion);
    const heading = Math.atan2(forward.x, forward.z) * 180 / Math.PI;
    return (heading + 360) % 360;
}

export function setTacticalCameraState() {
    // Camera is imported from the viewer scene; this initializer is kept as a
    // named hook so main.js can explicitly initialize the telemetry system.
}

export function initWorkstationUI() {
    setScientificDataMode(state.metricMode || 'dimensionless');
    updateVerticalExaggerationUI(state.verticalExaggeration || 1);
}
