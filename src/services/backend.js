// ============================================================
// DEPTHWIZARD
// BACKEND API SERVICE
// ============================================================

// IMPORTANT:
// Must match the drogon listener (main.cc: 0.0.0.0:8081). Override per
// deployment with VITE_API_BASE, e.g. VITE_API_BASE=http://host:8081 npm run dev

export const API_BASE =
    (import.meta.env?.VITE_API_BASE || 'http://localhost:8081').replace(/\/+$/, '');

export const GEOTIFF_PROCESSOR_ENDPOINT = `${API_BASE}/api/v1/processor`;
export const NORMAL_IMAGE_PROCESSOR_ENDPOINT = `${API_BASE}/api/v1/processor/normal-image`;

// Default backward-compatible alias
export const PROCESSOR_ENDPOINT = GEOTIFF_PROCESSOR_ENDPOINT;

// A full reconstruction can take several minutes: model inference, then
// SAT2LoD2 on Modal, whose container may first have to start (cold start).
// Kept above the backend's worst case (idle_connection_timeout: 1200 s).
export const PROCESSOR_TIMEOUT_MS = 20 * 60 * 1000;

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
    const controller = new AbortController();
    const timer = setTimeout(() => controller.abort(), PROCESSOR_TIMEOUT_MS);
    const started = Date.now();
    try {
        response = await fetch(
            endpoint,
            {
                method: 'POST',
                body: formData,
                signal: controller.signal
            }
        );
    } catch (networkError) {
        if (networkError?.name === 'AbortError') {
            throw new Error(
                `The backend did not finish within ${PROCESSOR_TIMEOUT_MS / 60000} minutes.`
            );
        }
        // Failing within seconds means no server; later means the connection
        // was dropped while the backend was still working.
        const seconds = Math.round((Date.now() - started) / 1000);
        throw new Error(
            seconds < 5
                ? `Unable to connect to backend at ${API_BASE}. Please ensure the server is running.`
                : `The connection to the backend was lost after ${seconds} s of processing. ` +
                  'Check the backend log; its idle_connection_timeout must exceed the processing time.'
        );
    } finally {
        clearTimeout(timer);
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

