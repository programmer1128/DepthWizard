// ============================================================
// DEPTHWIZARD
// HELP PANEL UI
// ============================================================

import { dom } from '../core/dom.js';


// ------------------------------------------------------------
// Open help panel
// ------------------------------------------------------------

export function openHelp() {

    if (!dom.helpPanel) return;

    dom.helpPanel.classList.add('show');
}


// ------------------------------------------------------------
// Close help panel
// ------------------------------------------------------------

export function closeHelp() {

    if (!dom.helpPanel) return;

    dom.helpPanel.classList.remove('show');
}


// ------------------------------------------------------------
// Toggle help panel
// ------------------------------------------------------------

export function toggleHelp() {

    if (!dom.helpPanel) return;

    dom.helpPanel.classList.toggle('show');
}


// ------------------------------------------------------------
// Initialize help panel events
// ------------------------------------------------------------

export function initPanel() {

    if (dom.helpBtn) {
        dom.helpBtn.addEventListener(
            'click',
            toggleHelp
        );
    }

    if (dom.closeHelpBtn) {
        dom.closeHelpBtn.addEventListener(
            'click',
            closeHelp
        );
    }
}