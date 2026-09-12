// ============================================================
// DEPTHWIZARD
// BACKEND API SERVICE
// ============================================================

// IMPORTANT:
// Do not change this endpoint unless the backend team
// changes the API contract.

const API_BASE =
    'http://localhost:8080';

const PROCESSOR_ENDPOINT =
    `${API_BASE}/api/v1/processor`;

// ============================================================
// PROCESS IMAGE
// ============================================================

export async function processImage(file) {

    if (!file) {

        throw new Error(
            'No image file selected.'
        );
    }

    // --------------------------------------------------------
    // Create multipart form data
    // --------------------------------------------------------

    const formData =
        new FormData();

    // IMPORTANT:
    // The backend expects the field name "image".
    formData.append(
        'image',
        file
    );

    // --------------------------------------------------------
    // Send request
    // --------------------------------------------------------

    const response =
        await fetch(
            PROCESSOR_ENDPOINT,
            {
                method: 'POST',
                body: formData
            }
        );

    // --------------------------------------------------------
    // HTTP error
    // --------------------------------------------------------

    if (!response.ok) {

        throw new Error(
            `Backend request failed (${response.status})`
        );
    }

    // --------------------------------------------------------
    // Parse JSON
    // --------------------------------------------------------

    const result =
        await response.json();

    // --------------------------------------------------------
    // Return raw backend response
    // --------------------------------------------------------

    return result;
}

// ============================================================
// API INFORMATION
// ============================================================

export const API_CONFIG = {

    baseUrl:
        API_BASE,

    processorEndpoint:
        PROCESSOR_ENDPOINT
};