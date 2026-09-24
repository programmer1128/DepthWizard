// ============================================================
// DEPTHWIZARD
// PICTURE-IN-PICTURE COMPARISON UI
// ============================================================

import { dom } from '../core/dom.js';
import { state } from '../core/state.js';


// ============================================================
// SHOW PiP
// ============================================================

export function showPiP() {

    if (!dom.comparisonPiP) {
        return;
    }

    dom.comparisonPiP.classList.remove('hidden');

    if (dom.pipToggle) {
        dom.pipToggle.checked = true;
    }

}


// ============================================================
// HIDE PiP
// ============================================================

export function hidePiP() {

    if (!dom.comparisonPiP) {
        return;
    }

    dom.comparisonPiP.classList.add('hidden');

    if (dom.pipToggle) {
        dom.pipToggle.checked = false;
    }

}


// ============================================================
// TOGGLE PiP
// ============================================================

export function togglePiP() {

    if (!dom.comparisonPiP) {
        return;
    }

    const isHidden =
        dom.comparisonPiP.classList.contains('hidden');

    if (isHidden) {
        showPiP();
    } else {
        hidePiP();
    }

}


// ============================================================
// MINIMIZE / RESTORE
// ============================================================

export function togglePiPMinimize() {

    if (!dom.comparisonPiP) {
        return;
    }

    const minimized =
        dom.comparisonPiP.classList.toggle('minimized');

    if (dom.pipMinimizeBtn) {
        dom.pipMinimizeBtn.textContent =
            minimized ? '+' : '−';
    }

}


// ============================================================
// CLOSE BUTTON
// ============================================================

export function closePiP() {

    hidePiP();

    if (dom.comparisonPiP) {
        dom.comparisonPiP.classList.remove('minimized');
    }

    if (dom.pipMinimizeBtn) {
        dom.pipMinimizeBtn.textContent = '−';
    }

}


// ============================================================
// SET IMAGE
// ============================================================

export function setPiPImage(imageSource, filename = 'Comparison Image', dimensions = '') {
    if (!imageSource) return;

    if (dom.pipImage) {
        dom.pipImage.onload = () => {
            dom.pipImage.classList.remove('hidden');
            dom.pipImage.style.display = 'block';
            dom.pipPlaceholder?.classList.add('hidden');
            if (dom.pipPlaceholder) dom.pipPlaceholder.style.display = 'none';
        };
        dom.pipImage.onerror = () => {
            dom.pipImage.style.display = 'none';
            dom.pipPlaceholder?.classList.remove('hidden');
            if (dom.pipPlaceholder) dom.pipPlaceholder.style.display = 'flex';
        };
        dom.pipImage.src = imageSource;
        dom.pipImage.classList.remove('hidden');
        dom.pipImage.style.display = 'block';
    }

    if (dom.pipPlaceholder) {
        dom.pipPlaceholder.classList.add('hidden');
        dom.pipPlaceholder.style.display = 'none';   // FIX
    }

    setPiPMetadata(filename, dimensions);
    showPiP();
}
// ============================================================
// SET METADATA
// ============================================================

export function setPiPMetadata(
    filename = '',
    dimensions = ''
) {

    if (dom.pipFilename) {
        dom.pipFilename.textContent =
            filename || 'Comparison Image';
    }

    if (dom.pipDimensions) {
        dom.pipDimensions.textContent =
            dimensions || '';
    }

}


// ============================================================
// CLEAR IMAGE
// ============================================================
export function clearPiPImage() {
    if (dom.pipImage) {
        dom.pipImage.removeAttribute('src');
        dom.pipImage.classList.add('hidden');
        dom.pipImage.style.display = 'none';
    }

    if (dom.pipPlaceholder) {
        dom.pipPlaceholder.classList.remove('hidden');
        dom.pipPlaceholder.style.display = 'flex';
    }

    setPiPMetadata('No comparison image', '');
}

// ============================================================
// INITIALIZE PiP
// ============================================================

export function initPiP() {

    if (dom.pipToggle) {
        dom.pipToggle.addEventListener(
            'change',
            togglePiP
        );
    }

    if (dom.pipMinimizeBtn) {
        dom.pipMinimizeBtn.addEventListener(
            'click',
            togglePiPMinimize
        );
    }

    if (dom.pipCloseBtn) {
        dom.pipCloseBtn.addEventListener(
            'click',
            closePiP
        );
    }

    // Start closed, matching the original UI behavior.
    hidePiP();

}