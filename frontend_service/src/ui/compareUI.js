// ============================================================
// DEPTHWIZARD
// COMPARISON UI
// ============================================================

import {
    runComparison
} from '../services/compare.js';

let compareModal = null;
let inspectionCard = null;

let selectedTiff = null;

function createCompareModal() {

    if (compareModal) {
        return compareModal;
    }

    compareModal =
        document.createElement('div');

    compareModal.id =
        'compare-modal';

    compareModal.innerHTML = `

        <div class="compare-modal-backdrop"></div>

        <div class="compare-modal-card">

            <div class="compare-modal-header">

                <div>
                    <div class="compare-modal-kicker">
                        TERRAIN INSPECTION
                    </div>

                    <h2>
                        Compare Elevation Data
                    </h2>
                </div>

                <button
                    id="compare-modal-close"
                    class="compare-close-btn"
                    type="button"
                >
                    ×
                </button>

            </div>

            <div class="compare-options">

                <!-- USER TIF -->

                <div class="compare-option">

                    <div class="compare-option-number">
                        01
                    </div>

                    <h3>
                        Upload .TIF by User
                    </h3>

                    <p>
                        Upload the reference GeoTIFF
                        for comparison.
                    </p>

                    <label
                        class="compare-upload-box"
                        for="compare-tiff-input"
                    >

                        <span
                            id="compare-upload-name"
                        >
                            Choose .TIF file
                        </span>

                        <span>
                            Browse
                        </span>

                    </label>

                    <input
                        id="compare-tiff-input"
                        type="file"
                        accept=".tif,.tiff,image/tiff"
                        hidden
                    />

                </div>


                <!-- DATASET -->

                <div class="compare-option">

                    <div class="compare-option-number">
                        02
                    </div>

                    <h3>
                        Dataset Choice
                    </h3>

                    <p>
                        Select the reference
                        elevation dataset.
                    </p>

                    <select
                        id="compare-dataset-select"
                        class="compare-dataset-select"
                    >

                        <option value="">
                            Select dataset
                        </option>

                        <option value="bhuvan">
                            ISRO Bhuvan
                        </option>

                        <option value="opentopography">
                            OpenTopography
                        </option>

                    </select>

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
                    GET
                </button>

            </div>

        </div>
    `;

    document.body.appendChild(
        compareModal
    );

    setupCompareEvents();

    return compareModal;
}

function setupCompareEvents() {

    const closeButton =
        document.getElementById(
            'compare-modal-close'
        );

    closeButton?.addEventListener(
        'click',
        closeCompareModal
    );

    const backdrop =
        compareModal.querySelector(
            '.compare-modal-backdrop'
        );

    backdrop?.addEventListener(
        'click',
        closeCompareModal
    );

    const input =
        document.getElementById(
            'compare-tiff-input'
        );

    input?.addEventListener(
        'change',
        handleTiffSelection
    );

    const dataset =
        document.getElementById(
            'compare-dataset-select'
        );

    dataset?.addEventListener(
        'change',
        updateGetButton
    );

    const getButton =
        document.getElementById(
            'compare-get-btn'
        );

    getButton?.addEventListener(
        'click',
        handleComparison
    );
}

function handleTiffSelection(event) {

    selectedTiff =
        event.target.files?.[0] ||
        null;

    const name =
        document.getElementById(
            'compare-upload-name'
        );

    if (!name) {
        return;
    }

    name.textContent =
        selectedTiff
            ? selectedTiff.name
            : 'Choose .TIF file';

    updateGetButton();
}

function updateGetButton() {

    const dataset =
        document.getElementById(
            'compare-dataset-select'
        );

    const getButton =
        document.getElementById(
            'compare-get-btn'
        );

    if (!getButton) {
        return;
    }

    getButton.disabled =
        !selectedTiff ||
        !dataset?.value;
}

function setProgress(message) {

    const progress =
        document.getElementById(
            'compare-progress'
        );

    if (progress) {
        progress.textContent =
            message;
    }
}

async function handleComparison() {

    const dataset =
        document.getElementById(
            'compare-dataset-select'
        );

    // Make sure a TIF is selected
    if (!selectedTiff) {
        setProgress(
            'Please select a .TIF file.'
        );
        return;
    }

    // Make sure a dataset is selected
    if (!dataset?.value) {
        setProgress(
            'Please select a dataset.'
        );
        return;
    }

    // ========================================================
    // TEMPORARY TEST MODE
    // ========================================================

    const testMode = true;

    if (testMode) {

        const result = {

            metrics: {
                rmse: 'N/A',
                mae: 'N/A',
                pearson_correlation: 'N/A',
                accuracy: 'N/A'
            },

            original_backend_tif_height: 'N/A'
        };

        // IMPORTANT:
        // Close the comparison selection panel FIRST
        closeCompareModal();

        // Then show the results beside the terrain
        showInspectionCard(
            result,
            dataset.value
        );

        return;
    }

    // ========================================================
    // REAL BACKEND CODE
    // ========================================================

    try {

        setProgress(
            'Processing comparison...'
        );

        const result =
            await runComparison(
                selectedTiff,
                dataset.value
            );

        // Close upload/dataset panel
        closeCompareModal();

        // Show results beside terrain
        showInspectionCard(
            result,
            dataset.value
        );

        setProgress(
            'Comparison completed successfully.'
        );

    } catch (error) {

        console.error(
            'Comparison failed:',
            error
        );

        setProgress(
            error.message ||
            'Comparison failed.'
        );
    }
}

function getValue(
    result,
    ...keys
) {

    for (const key of keys) {

        const parts =
            key.split('.');

        let value =
            result;

        for (const part of parts) {

            if (
                value === null ||
                value === undefined
            ) {
                break;
            }

            value =
                value[part];
        }

        if (
            value !== undefined &&
            value !== null
        ) {
            return value;
        }
    }

    return '--';
}

function formatMetric(value) {

    if (
        value === null ||
        value === undefined ||
        value === '--'
    ) {
        return '--';
    }

    const number =
        Number(value);

    return Number.isFinite(number)
        ? number.toFixed(4)
        : String(value);
}

function createInspectionCard() {

    if (inspectionCard) {
        return inspectionCard;
    }

    inspectionCard =
        document.createElement('div');

    inspectionCard.id =
        'inspection-card';

    document.body.appendChild(
        inspectionCard
    );

    return inspectionCard;
}

function showInspectionCard(
    result,
    dataset
) {

    const card =
        createInspectionCard();

    const metrics =
        result.metrics ||
        result.data?.metrics ||
        result.result?.metrics ||
        result;

    const backendHeight =
        getValue(
            result,
            'original_backend_tif_height',
            'backend_tif_height',
            'original_tif_height',
            'data.original_backend_tif_height',
            'data.backend_tif_height'
        );


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
            >
                ×
            </button>

        </div>

        <div class="inspection-dataset">
            Reference:
            <strong>
                ${
                    dataset === 'bhuvan'
                        ? 'ISRO Bhuvan'
                        : 'OpenTopography'
                }
            </strong>
        </div>

        <div class="inspection-metrics">

            ${metricBox(
                'RMSE',
                getValue(
                    metrics,
                    'rmse'
                )
            )}

            ${metricBox(
                'MAE',
                getValue(
                    metrics,
                    'mae'
                )
            )}

            ${metricBox(
                'Pearson Correlation',
                getValue(
                    metrics,
                    'pearson_correlation',
                    'pearson',
                    'correlation'
                )
            )}

            ${metricBox(
                'Accuracy',
                getValue(
                    metrics,
                    'accuracy'
                )
            )}

            ${metricBox(
                'Original Backend .TIF Height',
                backendHeight,
                true
            )}

        </div>

        <button
            id="inspection-card-close-bottom"
            class="inspection-done-btn"
            type="button"
        >
            CLOSE
        </button>
    `;

    card.classList.add(
        'visible'
    );

    document
        .getElementById(
            'inspection-card-close'
        )
        ?.addEventListener(
            'click',
            hideInspectionCard
        );

    document
        .getElementById(
            'inspection-card-close-bottom'
        )
        ?.addEventListener(
            'click',
            hideInspectionCard
        );
}

function metricBox(
    label,
    value,
    raw = false
) {

    return `
        <div class="inspection-metric">

            <span class="inspection-metric-label">
                ${label}
            </span>

            <strong class="inspection-metric-value">
                ${
                    raw
                        ? value
                        : formatMetric(value)
                }
            </strong>

        </div>
    `;
}

export function hideInspectionCard() {

    if (!inspectionCard) {
        return;
    }

    inspectionCard.classList.remove(
        'visible'
    );
}

export function openCompareModal() {

    const modal =
        createCompareModal();

    modal.classList.add(
        'visible'
    );

    updateGetButton();
}

export function closeCompareModal() {

    if (!compareModal) {
        return;
    }

    compareModal.classList.remove(
        'visible'
    );
}

export function initCompareUI() {

    // Created lazily when Compare is clicked.
}