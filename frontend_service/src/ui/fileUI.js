// ============================================================
// DEPTHWIZARD
// FILE SELECTION UI
// ============================================================

import { dom } from '../core/dom.js';
import { state } from '../core/state.js';
import { setFileStatus } from './status.js';

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

    return (
        type === 'image/png' ||
        type === 'image/jpeg' ||
        type === 'image/jpg' ||
        type === 'image/webp' ||
        type === 'image/gif'
    );
}

function displaySelectedFile(file) {
    if (!file) return;

    state.selectedFile = file;

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
    } else if (dom.thumbnailPreview) {
        dom.thumbnailPreview.removeAttribute('src');
        dom.thumbnailPreview.classList.add('hidden');
        dom.thumbnailPreview.style.display = 'none';
    }

    setFileStatus(`Selected: ${file.name}`);
}

function handleFile(file) {
    if (!file) return;

    if (!isSupportedFile(file)) {
        setFileStatus('Unsupported file type.');
        return;
    }

    displaySelectedFile(file);
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
}