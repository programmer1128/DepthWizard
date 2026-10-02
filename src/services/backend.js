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
export const GLOBAL_MAP_GEOTIFF_ENDPOINT = `${API_BASE}/api/v1/global-map/geotiff`;

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
// GLOBAL MAP -> OPTICAL GEOTIFF
// Credentials remain on the backend. The browser only sends
// the selected WGS84 bounding box and output dimensions.
// ============================================================

export async function generateGlobalMapGeoTIFF({
    bbox,
    width = 1024,
    height = 1024,
    maxCloudCoverage = 20
}) {
    if (
        !Array.isArray(bbox) ||
        bbox.length !== 4 ||
        bbox.some((value) => !Number.isFinite(Number(value)))
    ) {
        throw new Error(
            'Select a valid map area before generating.'
        );
    }

    const payload = {
        bbox: bbox.map(Number),
        width: Math.max(
            256,
            Math.min(2048, Math.round(width))
        ),
        height: Math.max(
            256,
            Math.min(2048, Math.round(height))
        ),
        maxCloudCoverage: Math.max(
            0,
            Math.min(
                100,
                Number(maxCloudCoverage) || 20
            )
        )
    };

    console.groupCollapsed(
        '[DepthWizard Global Map] 1/3 Requesting GeoTIFF'
    );

    console.info(
        'Endpoint:',
        GLOBAL_MAP_GEOTIFF_ENDPOINT
    );

    console.info(
        'Selected bounding box:',
        payload.bbox
    );

    console.info(
        'Output resolution:',
        `${payload.width} × ${payload.height}`
    );

    console.info(
        'Maximum cloud coverage:',
        `${payload.maxCloudCoverage}%`
    );

    console.info(
        'Request payload:',
        payload
    );

    console.groupEnd();

    const controller =
        new AbortController();

    const timeout =
        setTimeout(
            () => controller.abort(),
            3 * 60 * 1000
        );

    let response;

    try {
        response = await fetch(
            GLOBAL_MAP_GEOTIFF_ENDPOINT,
            {
                method: 'POST',

                headers: {
                    'Content-Type':
                        'application/json'
                },

                body:
                    JSON.stringify(payload),

                signal:
                    controller.signal
            }
        );
    } catch (error) {
        console.error(
            '[DepthWizard Global Map] Backend connection failed:',
            {
                endpoint:
                    GLOBAL_MAP_GEOTIFF_ENDPOINT,

                error,

                explanation:
                    'The frontend request is correct, but no backend is responding at this address.'
            }
        );

        if (error?.name === 'AbortError') {
            throw new Error(
                'Global imagery generation timed out after 3 minutes.'
            );
        }

        throw new Error(
            `Unable to connect to the global-map backend at ` +
            `${GLOBAL_MAP_GEOTIFF_ENDPOINT}. ` +
            `Make sure the backend is running on port 8081.`
        );
    } finally {
        clearTimeout(timeout);
    }

    console.info(
        '[DepthWizard Global Map] 2/3 Backend responded:',
        {
            status:
                response.status,

            statusText:
                response.statusText,

            contentType:
                response.headers.get(
                    'content-type'
                ),

            provider:
                response.headers.get(
                    'x-imagery-provider'
                )
        }
    );

    if (!response.ok) {
        let message =
            `Global imagery request failed (${response.status}).`;

        try {
            const errorBody =
                await response.json();

            message =
                errorBody.message ||
                errorBody.error ||
                errorBody.detail ||
                message;

            console.error(
                '[DepthWizard Global Map] Backend error body:',
                errorBody
            );
        } catch (_) {
            console.error(
                '[DepthWizard Global Map] Backend returned an HTTP error without JSON.'
            );
        }

        throw new Error(message);
    }

    const contentType =
        response.headers.get(
            'content-type'
        ) || '';

    if (
        !contentType.includes('tiff') &&
        !contentType.includes(
            'octet-stream'
        )
    ) {
        console.error(
            '[DepthWizard Global Map] Invalid response type:',
            contentType
        );

        throw new Error(
            'The global-map backend did not return a GeoTIFF.'
        );
    }

    const blob =
        await response.blob();

    if (!blob.size) {
        throw new Error(
            'The generated GeoTIFF was empty.'
        );
    }

    const timestamp =
        new Date()
            .toISOString()
            .replace(/[:.]/g, '-');

    const file =
        new File(
            [blob],
            `global-map-${timestamp}.tif`,
            {
                type:
                    'image/tiff',

                lastModified:
                    Date.now()
            }
        );

    console.groupCollapsed(
        '[DepthWizard Global Map] GeoTIFF received successfully'
    );

    console.info(
        'Filename:',
        file.name
    );

    console.info(
        'MIME type:',
        file.type
    );

    console.info(
        'File size:',
        `${(file.size / 1024 / 1024).toFixed(2)} MB`
    );

    console.info(
        'Next step:',
        'The file will now be submitted to /api/v1/processor.'
    );

    console.groupEnd();

    return file;
}

// ============================================================
// API INFORMATION
// ============================================================

export const API_CONFIG = {
    baseUrl: API_BASE,
    geotiffEndpoint: GEOTIFF_PROCESSOR_ENDPOINT,
    normalImageEndpoint: NORMAL_IMAGE_PROCESSOR_ENDPOINT,
    globalMapGeoTiffEndpoint: GLOBAL_MAP_GEOTIFF_ENDPOINT,
    processorEndpoint: GEOTIFF_PROCESSOR_ENDPOINT
};

