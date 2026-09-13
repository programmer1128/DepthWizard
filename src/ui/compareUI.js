// ============================================================
// DEPTHWIZARD
// COMPARISON UI
// ============================================================

import {
    compareElevation
} from '../services/compare.js';

import {
    state
} from '../core/state.js';

import {
    setPiPImage
} from './pipUI.js';

let compareModal = null;
let inspectionCard = null;

// ============================================================
// MODAL CREATION
// ============================================================

function createCompareModal() {

    if (compareModal) {
        return compareModal;
    }

    compareModal = document.createElement('div');
    compareModal.id = 'compare-modal';

    compareModal.innerHTML = `
        <div class="compare-modal-backdrop"></div>

        <div class="compare-modal-card">

            <div class="compare-modal-header">
                <div>
                    <div class="compare-modal-kicker">
                        TERRAIN INSPECTION & VALIDATION
                    </div>
                    <h2>
                        Compare Elevation Data
                    </h2>
                </div>

                <button
                    id="compare-modal-close"
                    class="compare-close-btn"
                    type="button"
                    title="Close"
                >
                    ×
                </button>
            </div>

            <div class="compare-options">

                <!-- 01: DATASET -->
                <div class="compare-option">

                    <div class="compare-option-number">
                        01
                    </div>

                    <h3>
                        Reference Dataset
                    </h3>

                    <p>
                        Choose the benchmark reference elevation dataset for comparative accuracy inspection.
                    </p>

                    <div class="compare-field-group">
                        <label class="compare-input-label" for="compare-dataset-select">
                            Reference Benchmark
                        </label>
                        <select
                            id="compare-dataset-select"
                            class="compare-dataset-select"
                        >
                            <option value="opentopography" selected>
                                OpenTopography
                            </option>
                            <option value="bhuvan">
                                ISRO Bhuvan
                            </option>
                        </select>
                    </div>

                    <div class="compare-info-callout" style="margin-top: 14px; font-size: 11px; opacity: 0.65; line-height: 1.4;">
                        Compares single-view estimated 3D height against geospatial reference raster data at target coordinates.
                    </div>

                </div>

                <!-- 02: COORDINATES -->
                <div class="compare-option">

                    <div class="compare-option-number">
                        02
                    </div>

                    <h3>
                        Inspection Coordinates
                    </h3>

                    <p>
                        Enter target coordinates (X, Y) to compare elevation or click any point on the 3D terrain.
                    </p>

                    <div class="compare-coord-grid">
                        <div class="compare-field-group">
                            <label class="compare-input-label" for="compare-x-input">
                                Coordinate X
                            </label>
                            <input
                                id="compare-x-input"
                                class="compare-text-input"
                                type="number"
                                min="0"
                                step="any"
                                placeholder="10.0"
                            />
                        </div>

                        <div class="compare-field-group">
                            <label class="compare-input-label" for="compare-y-input">
                                Coordinate Y
                            </label>
                            <input
                                id="compare-y-input"
                                class="compare-text-input"
                                type="number"
                                min="0"
                                step="any"
                                placeholder="10.0"
                            />
                        </div>
                    </div>

                    <div class="compare-coord-actions">
                        <button
                            id="compare-use-clicked-btn"
                            class="compare-secondary-btn"
                            type="button"
                        >
                            Use Clicked Point
                        </button>
                        <button
                            id="compare-use-default-btn"
                            class="compare-secondary-btn"
                            type="button"
                        >
                            Sample (10.0, 10.0)
                        </button>
                    </div>

                    <span class="compare-input-hint" style="margin-top: 10px; display: block;">
                        Tip: Clicking any terrain surface point in 3D view sets coordinates automatically.
                    </span>

                </div>

            </div>

            <div class="compare-modal-footer">

                <div
                    id="compare-progress"
                    class="compare-progress"
                >
                    Ready for comparison.
                </div>

                <button
                    id="compare-get-btn"
                    class="compare-get-btn"
                    type="button"
                    disabled
                >
                    COMPARE ELEVATION
                </button>

            </div>

        </div>
    `;

    document.body.appendChild(compareModal);
    setupCompareEvents();

    return compareModal;
}

// ============================================================
// EVENT SETUP
// ============================================================

function setupCompareEvents() {

    const closeButton =
        document.getElementById('compare-modal-close');

    closeButton?.addEventListener('click', closeCompareModal);

    const backdrop =
        compareModal.querySelector('.compare-modal-backdrop');

    backdrop?.addEventListener('click', closeCompareModal);

    const datasetSelect =
        document.getElementById('compare-dataset-select');

    datasetSelect?.addEventListener('change', updateGetButton);

    const xInput =
        document.getElementById('compare-x-input');

    const yInput =
        document.getElementById('compare-y-input');

    xInput?.addEventListener('input', updateGetButton);
    yInput?.addEventListener('input', updateGetButton);

    const useClickedBtn =
        document.getElementById('compare-use-clicked-btn');

    useClickedBtn?.addEventListener('click', () => {
        if (state.lastClickedPoint) {
            if (xInput) xInput.value = Number(state.lastClickedPoint.x).toFixed(2);
            if (yInput) yInput.value = Number(state.lastClickedPoint.y).toFixed(2);
            setProgress(`Coordinates set to last clicked terrain point.`);
        } else {
            setProgress(`No terrain point clicked yet. Click terrain in 3D viewer.`);
        }
        updateGetButton();
    });

    const useDefaultBtn =
        document.getElementById('compare-use-default-btn');

    useDefaultBtn?.addEventListener('click', () => {
        if (xInput) xInput.value = '10.0';
        if (yInput) yInput.value = '10.0';
        setProgress(`Sample coordinates loaded.`);
        updateGetButton();
    });

    const getButton =
        document.getElementById('compare-get-btn');

    getButton?.addEventListener('click', handleComparison);
}

// ============================================================
// GET BUTTON STATE
// ============================================================

function updateGetButton() {

    const datasetSelect =
        document.getElementById('compare-dataset-select');

    const xInput =
        document.getElementById('compare-x-input');

    const yInput =
        document.getElementById('compare-y-input');

    const getButton =
        document.getElementById('compare-get-btn');

    if (!getButton) {
        return;
    }

    const hasDataset = Boolean(datasetSelect?.value);
    const hasX = xInput?.value !== '' && Number.isFinite(Number(xInput?.value)) && Number(xInput?.value) >= 0;
    const hasY = yInput?.value !== '' && Number.isFinite(Number(yInput?.value)) && Number(yInput?.value) >= 0;

    getButton.disabled = !(hasDataset && hasX && hasY);
}

function setProgress(message) {
    const progress =
        document.getElementById('compare-progress');

    if (progress) {
        progress.textContent = message;
    }
}

// ============================================================
// COMPARISON DISPATCH
// ============================================================

async function handleComparison() {

    const datasetSelect =
        document.getElementById('compare-dataset-select');

    const xInput =
        document.getElementById('compare-x-input');

    const yInput =
        document.getElementById('compare-y-input');

    const getButton =
        document.getElementById('compare-get-btn');

    const uuid = state.currentUuid;

    const tag =
        datasetSelect?.value || 'opentopography';

    const x =
        Number(xInput?.value);

    const y =
        Number(yInput?.value);

    if (!uuid) {
        setProgress('Please upload an image first to generate terrain before comparison.');
        return;
    }

    if (!tag) {
        setProgress('Please select a reference dataset.');
        return;
    }

    if (!Number.isFinite(x) || !Number.isFinite(y)) {
        setProgress('Please provide numerical (X, Y) coordinates.');
        return;
    }

    if (x < 0 || y < 0) {
        setProgress('Coordinates must be non-negative raster coordinates (X >= 0, Y >= 0).');
        return;
    }

    try {

        if (getButton) {
            getButton.disabled = true;
        }

        setProgress(`Comparing elevation with ${tag} at (${x.toFixed(2)}, ${y.toFixed(2)})...`);

        const result = await compareElevation({
            uuid,
            tag,
            x,
            y
        });

        // Close compare selection modal
        closeCompareModal();

        // Show detailed inspection card with metrics and diff map (without UUID)
        showInspectionCard(result, tag, {
            x,
            y,
            meshElevation: state.lastClickedPoint?.meshElevation
        });

        setProgress('Comparison completed successfully.');

    } catch (error) {

        console.error('Comparison API error:', error);
        setProgress(error.message || 'Comparison request failed.');

    } finally {

        if (getButton) {
            updateGetButton();
        }

    }
}

// ============================================================
// VALUE EXTRACTION HELPERS
// ============================================================

function getValue(result, ...keys) {

    for (const key of keys) {
        const parts = key.split('.');
        let value = result;

        for (const part of parts) {
            if (value === null || value === undefined) {
                break;
            }
            value = value[part];
        }

        if (value !== undefined && value !== null) {
            return value;
        }
    }

    return null;
}

function formatMetric(value) {

    if (
        value === null ||
        value === undefined ||
        value === '--'
    ) {
        return '--';
    }

    const number = Number(value);

    return Number.isFinite(number)
        ? number.toFixed(2)
        : String(value);
}

// ============================================================
// INSPECTION RESULTS CARD
// ============================================================

function createInspectionCard() {

    if (inspectionCard) {
        return inspectionCard;
    }

    inspectionCard = document.createElement('div');
    inspectionCard.id = 'inspection-card';

    document.body.appendChild(inspectionCard);
    return inspectionCard;
}

export function showInspectionCard(result, datasetTag = 'opentopography', queryParams = {}) {

    const card = createInspectionCard();

    const metrics =
        result.metrics ||
        result.data?.metrics ||
        result.result?.metrics ||
        result;

    // Direct extraction from backend contract with resilient resolution
    let modelHeight = null;
    const modelCandidates = [
        result.original_height_meters,
        result.elevation_meters,
        getValue(result, 'original_height_meters', 'elevation_meters', 'model_height', 'estimated_height', 'height')
    ];
    for (const val of modelCandidates) {
        if (val !== null && val !== undefined && Number.isFinite(Number(val)) && Number(val) > 0) {
            modelHeight = Number(val);
            break;
        }
    }
    if (modelHeight === null) {
        for (const val of modelCandidates) {
            if (val !== null && val !== undefined && Number.isFinite(Number(val))) {
                modelHeight = Number(val);
                break;
            }
        }
    }
    // Fallback to mesh surface elevation if backend returned 0 or null
    if (
        (modelHeight === null || modelHeight === 0) &&
        queryParams.meshElevation &&
        Number.isFinite(Number(queryParams.meshElevation)) &&
        Number(queryParams.meshElevation) !== 0
    ) {
        modelHeight = Number(queryParams.meshElevation);
    }

    const referenceHeight =
        result.reference_height_meters ??
        getValue(result, 'reference_height_meters', 'reference_height', 'dataset_height');

    let diffHeight = null;
    if (
        modelHeight !== null &&
        referenceHeight !== null &&
        Number.isFinite(Number(modelHeight)) &&
        Number.isFinite(Number(referenceHeight))
    ) {
        diffHeight = Math.abs(Number(modelHeight) - Number(referenceHeight));
    } else {
        diffHeight = getValue(result, 'difference', 'diff', 'error');
    }

    const accuracy =
        result.accuracy_percentage ??
        getValue(metrics, 'accuracy_percentage', 'accuracy');

    const rmse =
        result.rmse ??
        getValue(metrics, 'rmse');

    const mae =
        result.mae ??
        getValue(metrics, 'mae');

    const pearson =
        result.pearson_correlation ??
        getValue(metrics, 'pearson_correlation', 'pearson', 'correlation');

    const validPixels =
        result.valid_pixels_count ??
        getValue(result, 'valid_pixels_count', 'data.valid_pixels_count');

    // Difference map base64 image
    const rawDiffMap =
        result.diff_map_base64 ||
        result.data?.diff_map_base64 ||
        result.diff_map ||
        null;

    let diffMapSrc = null;
    if (rawDiffMap && typeof rawDiffMap === 'string') {
        diffMapSrc = rawDiffMap.startsWith('data:')
            ? rawDiffMap
            : `data:image/png;base64,${rawDiffMap}`;
    }

    const formattedDatasetName =
        datasetTag === 'bhuvan'
            ? 'ISRO Bhuvan'
            : datasetTag === 'opentopography'
                ? 'OpenTopography'
                : datasetTag;

    const coordStr = (queryParams.x !== undefined && queryParams.y !== undefined)
        ? `X: ${Number(queryParams.x).toFixed(2)}, Y: ${Number(queryParams.y).toFixed(2)}`
        : '--';

    card.innerHTML = `
        <div class="inspection-card-header">
            <div>
                <div class="inspection-kicker">
                    COMPARISON COMPLETE
                </div>
                <h2>
                    Inspection Results
                </h2>
            </div>

            <button
                id="inspection-card-close"
                class="inspection-close-btn"
                type="button"
                title="Close inspection"
            >
                ×
            </button>
        </div>

        <div class="inspection-dataset">
            <span>Reference Dataset: <strong>${formattedDatasetName}</strong></span>
            <div class="inspection-query-details">
                <span>Inspection Point: <strong>${coordStr}</strong></span>
            </div>
        </div>

        ${(modelHeight !== null || referenceHeight !== null || diffHeight !== null) ? `
        <div class="inspection-elevation-summary">
            ${modelHeight !== null ? `
                <div class="inspection-summary-col">
                    <span class="summary-label">Estimated Height</span>
                    <strong class="summary-value">${formatMetric(modelHeight)} m</strong>
                </div>
            ` : ''}
            ${referenceHeight !== null ? `
                <div class="inspection-summary-col">
                    <span class="summary-label">Reference Height</span>
                    <strong class="summary-value">${formatMetric(referenceHeight)} m</strong>
                </div>
            ` : ''}
            ${diffHeight !== null ? `
                <div class="inspection-summary-col">
                    <span class="summary-label">Difference (Δ)</span>
                    <strong class="summary-value highlight">${formatMetric(diffHeight)} m</strong>
                </div>
            ` : ''}
        </div>
        ` : ''}

        <div class="inspection-metrics">
            ${metricBox('Accuracy', accuracy !== null ? `${formatMetric(accuracy)}%` : '--', true)}
            ${metricBox('RMSE', rmse !== null ? `${formatMetric(rmse)} m` : '--', true)}
            ${metricBox('MAE', mae !== null ? `${formatMetric(mae)} m` : '--', true)}
            ${metricBox('Pearson Correlation', pearson !== null ? Number(pearson).toFixed(4) : '--', true)}
            ${validPixels !== null ? metricBox('Valid Pixels', Number(validPixels).toLocaleString(), true) : ''}
        </div>

        ${diffMapSrc ? `
        <div class="inspection-diff-map-card">
            <div class="diff-map-bar">
                <span class="diff-map-label">ELEVATION DIFFERENCE MAP</span>
                <button
                    id="inspection-pip-btn"
                    class="diff-pip-action-btn"
                    type="button"
                    title="Display difference map in Picture-in-Picture window"
                >
                    ⛶ View in PiP
                </button>
            </div>
            <div class="diff-map-preview-wrap">
                <img
                    id="inspection-diff-img"
                    src="${diffMapSrc}"
                    alt="Elevation Difference Map"
                    class="diff-map-image"
                />
            </div>
        </div>
        ` : ''}

        <button
            id="inspection-card-close-bottom"
            class="inspection-done-btn"
            type="button"
        >
            CLOSE
        </button>
    `;

    card.classList.add('visible');

    document.getElementById('inspection-card-close')
        ?.addEventListener('click', hideInspectionCard);

    document.getElementById('inspection-card-close-bottom')
        ?.addEventListener('click', hideInspectionCard);

    if (diffMapSrc) {
        document.getElementById('inspection-pip-btn')
            ?.addEventListener('click', () => {
                setPiPImage(
                    diffMapSrc,
                    `Diff Map: ${formattedDatasetName}`,
                    coordStr
                );
            });
    }
}

function metricBox(label, value, isFormatted = false) {

    const displayVal = isFormatted ? value : (value !== null ? formatMetric(value) : '--');

    return `
        <div class="inspection-metric">
            <span class="inspection-metric-label">
                ${label}
            </span>
            <strong class="inspection-metric-value">
                ${displayVal}
            </strong>
        </div>
    `;
}

export function hideInspectionCard() {

    if (!inspectionCard) {
        return;
    }

    inspectionCard.classList.remove('visible');
}

// ============================================================
// OPEN / CLOSE MODAL
// ============================================================

export function openCompareModal(initialParams = {}) {

    const modal = createCompareModal();

    const datasetSelect =
        document.getElementById('compare-dataset-select');

    const xInput =
        document.getElementById('compare-x-input');

    const yInput =
        document.getElementById('compare-y-input');

    // Populate dataset
    if (datasetSelect && initialParams.tag) {
        datasetSelect.value = initialParams.tag;
    }

    // Populate Coordinates
    if (xInput && initialParams.x !== undefined) {
        xInput.value = Number(initialParams.x).toFixed(2);
    } else if (xInput && state.lastClickedPoint?.x !== undefined) {
        xInput.value = Number(state.lastClickedPoint.x).toFixed(2);
    } else if (xInput && !xInput.value) {
        xInput.value = '10.0';
    }

    if (yInput && initialParams.y !== undefined) {
        yInput.value = Number(initialParams.y).toFixed(2);
    } else if (yInput && state.lastClickedPoint?.y !== undefined) {
        yInput.value = Number(state.lastClickedPoint.y).toFixed(2);
    } else if (yInput && !yInput.value) {
        yInput.value = '10.0';
    }

    setProgress('Ready for comparison.');
    updateGetButton();

    modal.classList.add('visible');
}

export function closeCompareModal() {

    if (!compareModal) {
        return;
    }

    compareModal.classList.remove('visible');
}

export function initCompareUI() {
    // Modal will be created on demand when Compare is clicked
}