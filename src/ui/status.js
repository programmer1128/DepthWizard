// ============================================================
// DEPTHWIZARD
// STATUS / HUD UI
// ============================================================

import { dom } from '../core/dom.js';


// ------------------------------------------------------------
// Update viewer status
// ------------------------------------------------------------

export function setViewerStatus(message, type = 'ready') {

    if (dom.viewerStatus) {
        dom.viewerStatus.textContent = message;
    }

    updateStatusDot(type);

    // Keep the top system status synchronized with viewer status
    if (dom.systemStatus) {

        if (type === 'loading') {
            dom.systemStatus.textContent = 'Processing';
        }
        else if (type === 'error') {
            dom.systemStatus.textContent = 'System Alert';
        }
        else {
            dom.systemStatus.textContent = 'Viewer Ready';
        }
    }
}


// ------------------------------------------------------------
// Update system status only
// ------------------------------------------------------------

export function setSystemStatus(message, type = 'ready') {

    if (dom.systemStatus) {
        dom.systemStatus.textContent = message;
    }

    updateStatusDot(type);
}


// ------------------------------------------------------------
// Update file status
// ------------------------------------------------------------

export function setFileStatus(message) {

    if (dom.fileStatus) {
        dom.fileStatus.textContent = message;
    }
}


// ------------------------------------------------------------
// Update status indicators
// ------------------------------------------------------------

export function updateStatusDot(type = 'ready') {

    const dots = [
        dom.statusDot,
        dom.hudStatusDot
    ];

    dots.forEach(dot => {

        if (!dot) return;

        dot.classList.remove(
            'ready',
            'loading',
            'error'
        );

        dot.classList.add(type);
    });
}


// ------------------------------------------------------------
// Update current navigation mode
// ------------------------------------------------------------

export function setModeStatus(mode) {

    const isFly = mode === 'fly';

    if (dom.currentModeBadge) {
        dom.currentModeBadge.textContent =
            isFly ? 'FLY' : 'ORBIT';
    }

    if (dom.topModeText) {
        dom.topModeText.textContent =
            isFly ? 'Fly Mode' : 'Orbit Mode';
    }
}


// ------------------------------------------------------------
// Update grid status
// ------------------------------------------------------------

export function setGridStatus(visible) {

    if (dom.topGridText) {
        dom.topGridText.textContent =
            visible ? 'Grid On' : 'Grid Off';
    }
}


// ------------------------------------------------------------
// Convenience helpers
// ------------------------------------------------------------

export function setLoadingStatus(message = 'Loading...') {

    setViewerStatus(message, 'loading');
}


export function setReadyStatus(message = 'Ready') {

    setViewerStatus(message, 'ready');
}


export function setErrorStatus(message = 'Error') {

    setViewerStatus(message, 'error');
}

