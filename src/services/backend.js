// ============================================================
// DEPTHWIZARD
// BACKEND API SERVICE
// ============================================================

// IMPORTANT:
// Do not change this endpoint unless the backend team
// changes the API contract.

export const API_BASE = 'http://localhost:8080';

export const GEOTIFF_PROCESSOR_ENDPOINT = `${API_BASE}/api/v1/processor`;
export const NORMAL_IMAGE_PROCESSOR_ENDPOINT = `${API_BASE}/api/v1/processor/normal-image`;

// Default backward-compatible alias
export const PROCESSOR_ENDPOINT = GEOTIFF_PROCESSOR_ENDPOINT;

export function isTiffFile(file) {
    if (!file) return false;
    const name = (file.name || '').toLowerCase();
    const type = (file.type || '').toLowerCase();
    return name.endsWith('.tif') || name.endsWith('.tiff') || type === 'image/tiff';
}

// ============================================================
// PROCESS IMAGE (GeoTIFF or Standard JPG/PNG)
// ============================================================

export async function processImage(file, imageType = 'auto') {

    if (!file) {
        throw new Error('No image file selected.');
    }

    // Determine target endpoint
    let endpoint = GEOTIFF_PROCESSOR_ENDPOINT;

    if (imageType === 'normal') {
        endpoint = NORMAL_IMAGE_PROCESSOR_ENDPOINT;
    } else if (imageType === 'geotiff') {
        endpoint = GEOTIFF_PROCESSOR_ENDPOINT;
    } else {
        // Auto-detect based on file extension / MIME
        endpoint = isTiffFile(file)
            ? GEOTIFF_PROCESSOR_ENDPOINT
            : NORMAL_IMAGE_PROCESSOR_ENDPOINT;
    }

    // --------------------------------------------------------
    // Create multipart form data
    // --------------------------------------------------------

    const formData = new FormData();

    // IMPORTANT:
    // The backend expects the field name "image".
    formData.append('image', file);

    // --------------------------------------------------------
    // Send request
    // --------------------------------------------------------

    let response;
    try {
        response = await fetch(
            endpoint,
            {
                method: 'POST',
                body: formData
            }
        );
    } catch (networkError) {
        throw new Error(
            `Unable to connect to backend at ${API_BASE}. Please ensure the server is running.`
        );
    }

    // --------------------------------------------------------
    // HTTP error
    // --------------------------------------------------------

    if (!response.ok) {
        let errorMessage = `Processor API request failed (${response.status})`;
        try {
            const errorJson = await response.json();
            if (errorJson.message || errorJson.error || errorJson.detail) {
                errorMessage = errorJson.message || errorJson.error || errorJson.detail;
            }
        } catch (_) {}

        throw new Error(errorMessage);
    }

    // --------------------------------------------------------
    // Parse JSON
    // --------------------------------------------------------

    const result = await response.json();

    // --------------------------------------------------------
    // Return raw backend response
    // --------------------------------------------------------

    return result;
}

export async function processGeoTIFFImage(file) {
    return processImage(file, 'geotiff');
}

export async function processNormalImage(file) {
    return processImage(file, 'normal');
}

// ============================================================
// API INFORMATION
// ============================================================

export const API_CONFIG = {
    baseUrl: API_BASE,
    geotiffEndpoint: GEOTIFF_PROCESSOR_ENDPOINT,
    normalImageEndpoint: NORMAL_IMAGE_PROCESSOR_ENDPOINT,
    processorEndpoint: GEOTIFF_PROCESSOR_ENDPOINT
};

