// ============================================================
// DEPTHWIZARD
// FILE SELECTION UI
// ============================================================

import { dom } from '../core/dom.js';
import { state, setCurrentUuid } from '../core/state.js';
import { setFileStatus } from './status.js';
import { setScientificDataMode } from './workstationUI.js';
import { setPiPImage, showPiP, hidePiP } from './pipUI.js';

function formatFileSize(bytes) {
    if (!Number.isFinite(bytes)) return '';

    if (bytes < 1024) {
        return `${bytes} B`;
    }

    if (bytes < 1024 * 1024) {
        return `${(bytes / 1024).toFixed(1)} KB`;
    }

    return `${(bytes / (1024 * 1024)).toFixed(1)} MB`;
}

function isSupportedFile(file) {
    if (!file) return false;

    const type = file.type.toLowerCase();
    const name = file.name.toLowerCase();

    return (
        type.startsWith('image/') ||
        name.endsWith('.tif') ||
        name.endsWith('.tiff')
    );
}

function isBrowserPreviewableImage(file) {
    if (!file) return false;

    const type = file.type.toLowerCase();
    const name = file.name.toLowerCase();

    return (
        type === 'image/png' ||
        type === 'image/jpeg' ||
        type === 'image/jpg' ||
        type === 'image/webp' ||
        type === 'image/gif' ||
        name.endsWith('.jpg') ||
        name.endsWith('.jpeg') ||
        name.endsWith('.png') ||
        name.endsWith('.webp')
    );
}

function displaySelectedFile(file) {
    if (!file) return;

    state.selectedFile = file;
    setCurrentUuid(null);

    if (dom.selectedFileInfo) {
        dom.selectedFileInfo.classList.remove('hidden');
    }

    if (dom.selectedFileName) {
        dom.selectedFileName.textContent = file.name;
    }

    if (dom.selectedFileSize) {
        dom.selectedFileSize.textContent = formatFileSize(file.size);
    }

    if (dom.uploadBtn) {
        dom.uploadBtn.disabled = false;
    }

    if (dom.viewSourceBtn) {
        dom.viewSourceBtn.disabled = !isBrowserPreviewableImage(file);
    }

    // Revoke previous preview URL
    if (state.currentPreviewUrl) {
        URL.revokeObjectURL(state.currentPreviewUrl);
        state.currentPreviewUrl = null;
    }

    // Only create a browser preview for formats browsers reliably display.
    // TIFF is still accepted for processing, but is not forced into <img>.
    if (
        dom.thumbnailPreview &&
        isBrowserPreviewableImage(file)
    ) {
        state.currentPreviewUrl = URL.createObjectURL(file);

        dom.thumbnailPreview.src = state.currentPreviewUrl;
        dom.thumbnailPreview.classList.remove('hidden');
        dom.thumbnailPreview.style.display = 'block';
        setPiPImage(
            state.currentPreviewUrl,
            file.name,
            'Local optical source'
        );
        hidePiP();

    } else if (dom.thumbnailPreview) {
        dom.thumbnailPreview.removeAttribute('src');
        dom.thumbnailPreview.classList.add('hidden');
        dom.thumbnailPreview.style.display = 'none';
    }

    setFileStatus(`Selected: ${file.name}`);
}

export function setImageUploadType(type) {
    state.imageUploadType = type;
    setScientificDataMode(type === 'geotiff' ? 'metric' : 'dimensionless');

    if (type === 'geotiff') {
        dom.typeGeoTiffBtn?.classList.add('active');
        dom.typeNormalBtn?.classList.remove('active');

        if (dom.imageInput) {
            dom.imageInput.accept = '.tif,.tiff';
        }
        if (dom.dropzoneIcon) dom.dropzoneIcon.textContent = '🛰️';
        if (dom.dropzoneTitle) dom.dropzoneTitle.textContent = 'Select or drop GeoTIFF image';
        if (dom.dropzoneSubtitle) dom.dropzoneSubtitle.textContent = 'GeoTIFF (.tif, .tiff) • Uses /api/v1/processor';
    } else {
        dom.typeGeoTiffBtn?.classList.remove('active');
        dom.typeNormalBtn?.classList.add('active');

        if (dom.imageInput) {
            dom.imageInput.accept = '.jpg,.jpeg,.png,.webp';
        }
        if (dom.dropzoneIcon) dom.dropzoneIcon.textContent = '📷';
        if (dom.dropzoneTitle) dom.dropzoneTitle.textContent = 'Select or drop optical image';
        if (dom.dropzoneSubtitle) dom.dropzoneSubtitle.textContent = 'JPG / PNG / JPEG • Uses /api/v1/processor/normal-image';
    }
}

function isTiff(file) {
    if (!file) return false;
    const name = (file.name || '').toLowerCase();
    const type = (file.type || '').toLowerCase();
    return name.endsWith('.tif') || name.endsWith('.tiff') || type === 'image/tiff';
}

function handleFile(file) {
    if (!file) return;

    if (!isSupportedFile(file)) {
        setFileStatus('Unsupported file type.');
        return;
    }

    // Auto-adjust toggle if dropped file is detected
    if (isTiff(file)) {
        setImageUploadType('geotiff');
    } else {
        setImageUploadType('normal');
    }

    displaySelectedFile(file);
}

export function selectFileForUpload(file) {
    handleFile(file);
}

function handleInputChange(event) {
    const file = event.target.files?.[0];
    handleFile(file);
}

function handleDragOver(event) {
    event.preventDefault();

    if (dom.fileDropzone) {
        dom.fileDropzone.classList.add('drag-over');
    }
}

function handleDragLeave(event) {
    event.preventDefault();

    if (dom.fileDropzone) {
        dom.fileDropzone.classList.remove('drag-over');
    }
}

function handleDrop(event) {
    event.preventDefault();

    if (dom.fileDropzone) {
        dom.fileDropzone.classList.remove('drag-over');
    }

    const file = event.dataTransfer?.files?.[0];

    handleFile(file);
}

export function openFilePicker() {
    if (dom.imageInput) {
        dom.imageInput.click();
    }
}

export function initFileUI() {
    if (dom.typeGeoTiffBtn) {
        dom.typeGeoTiffBtn.addEventListener('click', () => setImageUploadType('geotiff'));
    }

    if (dom.typeNormalBtn) {
        dom.typeNormalBtn.addEventListener('click', () => setImageUploadType('normal'));
    }

    if (dom.imageInput) {
        dom.imageInput.addEventListener(
            'change',
            handleInputChange
        );
    }

    if (dom.fileDropzone) {
        dom.fileDropzone.addEventListener(
            'dragover',
            handleDragOver
        );

        dom.fileDropzone.addEventListener(
            'dragleave',
            handleDragLeave
        );

        dom.fileDropzone.addEventListener(
            'drop',
            handleDrop
        );

        // Prevent the <input type="file"> click from bubbling
        // back into the dropzone and opening a second picker.
        dom.fileDropzone.addEventListener('click', (event) => {
            if (event.target === dom.imageInput) {
                return;
            }

            openFilePicker();
        });
    }

    if (dom.emptyUploadTrigger) {
        dom.emptyUploadTrigger.addEventListener(
            'click',
            openFilePicker
        );
    }


    const viewSourceBtn = dom.viewSourceBtn;
    if (viewSourceBtn) {
        viewSourceBtn.addEventListener('click', () => {
            if (state.currentPreviewUrl) {
                setPiPImage(state.currentPreviewUrl, state.selectedFile?.name || 'Optical source', 'Local source preview');
                showPiP();
            } else {
                setFileStatus('Preview is available after selecting a JPG, PNG, or GeoTIFF.');
            }
        });
    }

    // Set initial toggle styling, but keep scientific tools locked until a file is selected.
    setImageUploadType(state.imageUploadType || 'geotiff');
    if (!state.selectedFile) {
        setScientificDataMode('unknown');
    }
}
