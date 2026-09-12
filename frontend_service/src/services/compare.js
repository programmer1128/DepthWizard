// ============================================================
// DEPTHWIZARD
// COMPARISON API SERVICE
// ============================================================

const API_BASE = 'http://localhost:8080';

const UPLOAD_ENDPOINT =
    `${API_BASE}/api/v1/compare/upload`;

/*
 * These dataset endpoints are provisional until
 * backend teammates give the final API paths.
 */
const DATASET_ENDPOINTS = {
    bhuvan:
        `${API_BASE}/api/v1/compare/bhuvan`,

    opentopography:
        `${API_BASE}/api/v1/compare/open-topography`
};

export async function uploadComparisonTiff(file) {

    if (!file) {
        throw new Error(
            'Please select a .TIF file.'
        );
    }

    const formData =
        new FormData();

    formData.append(
        'file',
        file
    );

    const response =
        await fetch(
            UPLOAD_ENDPOINT,
            {
                method: 'POST',
                body: formData
            }
        );

    if (!response.ok) {
        throw new Error(
            `TIF upload failed (${response.status})`
        );
    }

    const result =
        await response.json();

    if (
        result.status === 'error' ||
        result.success === false
    ) {
        throw new Error(
            result.message ||
            'TIF upload failed.'
        );
    }

    return result;
}

export async function compareWithDataset(
    dataset,
    uploadResult
) {

    const endpoint =
        DATASET_ENDPOINTS[dataset];

    if (!endpoint) {
        throw new Error(
            'Invalid comparison dataset.'
        );
    }

    const response =
        await fetch(
            endpoint,
            {
                method: 'POST',
                headers: {
                    'Content-Type':
                        'application/json'
                },
                body: JSON.stringify({
                    dataset,
                    upload: uploadResult
                })
            }
        );

    if (!response.ok) {
        throw new Error(
            `Comparison failed (${response.status})`
        );
    }

    const result =
        await response.json();

    if (
        result.status === 'error' ||
        result.success === false
    ) {
        throw new Error(
            result.message ||
            'Comparison processing failed.'
        );
    }

    return result;
}

export async function runComparison(
    file,
    dataset
) {

    const uploadResult =
        await uploadComparisonTiff(
            file
        );

    return compareWithDataset(
        dataset,
        uploadResult
    );
}