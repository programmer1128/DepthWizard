// ============================================================
// DEPTHWIZARD
// GEOTIFF PROCESSING + PREVIEW
// ============================================================

import { dom } from '../core/dom.js';
import { state } from '../core/state.js';

import {
    setFileStatus,
    setReadyStatus,
    setErrorStatus
} from '../ui/status.js';

import {
    setPiPImage,
    setPiPMetadata,
    hidePiP
} from '../ui/pipUI.js';


// ============================================================
// CONFIG
// ============================================================

const MAX_SIZE = 2048;


// ============================================================
// CHECK GEOTIFF SUPPORT
// ============================================================

function getGeoTIFF() {

    if (!window.GeoTIFF) {
        throw new Error(
            'GeoTIFF library is not available.'
        );
    }

    return window.GeoTIFF;
}


// ============================================================
// CLAMP
// ============================================================

function clamp(value, min, max) {

    return Math.max(
        min,
        Math.min(max, value)
    );

}


// ============================================================
// CONVERT RASTER DATA TO RGB IMAGE
// ============================================================

function rasterToImageData(
    raster,
    width,
    height,
    samplesPerPixel
) {

    const canvas =
        document.createElement('canvas');

    canvas.width = width;
    canvas.height = height;

    const context =
        canvas.getContext('2d');

    const imageData =
        context.createImageData(
            width,
            height
        );

    const output =
        imageData.data;


    // --------------------------------------------------------
    // RGB / RGBA raster
    // --------------------------------------------------------

    if (
        samplesPerPixel === 3 ||
        samplesPerPixel === 4
    ) {

        const pixelCount =
            width * height;

        for (let i = 0; i < pixelCount; i++) {

            const sourceIndex =
                i * samplesPerPixel;

            const targetIndex =
                i * 4;

            output[targetIndex] =
                raster[sourceIndex] ?? 0;

            output[targetIndex + 1] =
                raster[sourceIndex + 1] ?? 0;

            output[targetIndex + 2] =
                raster[sourceIndex + 2] ?? 0;

            output[targetIndex + 3] =
                samplesPerPixel === 4
                    ? raster[sourceIndex + 3]
                    : 255;
        }

        context.putImageData(
            imageData,
            0,
            0
        );

        return canvas;
    }


    // --------------------------------------------------------
    // Grayscale / elevation raster
    // --------------------------------------------------------

    let min = Infinity;
    let max = -Infinity;

    for (let i = 0; i < raster.length; i++) {

        const value =
            Number(raster[i]);

        if (!Number.isFinite(value)) {
            continue;
        }

        if (value < min) {
            min = value;
        }

        if (value > max) {
            max = value;
        }

    }


    // Prevent division by zero
    if (
        !Number.isFinite(min) ||
        !Number.isFinite(max)
    ) {

        min = 0;
        max = 1;

    }


    const range =
        max - min || 1;


    for (let i = 0; i < width * height; i++) {

        const value =
            Number(raster[i]);

        const normalized =
            Number.isFinite(value)
                ? clamp(
                    (value - min) / range,
                    0,
                    1
                )
                : 0;

        const gray =
            Math.round(
                normalized * 255
            );

        const index =
            i * 4;

        output[index] = gray;
        output[index + 1] = gray;
        output[index + 2] = gray;
        output[index + 3] = 255;

    }


    context.putImageData(
        imageData,
        0,
        0
    );

    return canvas;

}


// ============================================================
// RESIZE IMAGE
// ============================================================

function resizeCanvas(
    sourceCanvas,
    maxSize = MAX_SIZE
) {

    const width =
        sourceCanvas.width;

    const height =
        sourceCanvas.height;


    if (
        width <= maxSize &&
        height <= maxSize
    ) {

        return sourceCanvas;

    }


    const scale =
        Math.min(
            maxSize / width,
            maxSize / height
        );


    const newWidth =
        Math.max(
            1,
            Math.round(width * scale)
        );

    const newHeight =
        Math.max(
            1,
            Math.round(height * scale)
        );


    const canvas =
        document.createElement('canvas');

    canvas.width = newWidth;
    canvas.height = newHeight;


    const context =
        canvas.getContext('2d');

    context.drawImage(
        sourceCanvas,
        0,
        0,
        newWidth,
        newHeight
    );


    return canvas;

}


// ============================================================
// CREATE PREVIEW
// ============================================================

function createPreview(
    canvas
) {

    return canvas.toDataURL(
        'image/jpeg',
        0.9
    );

}


// ============================================================
// FORMAT FILE SIZE
// ============================================================

function formatFileSize(bytes) {

    if (!bytes) {
        return '0 B';
    }

    const units = [
        'B',
        'KB',
        'MB',
        'GB'
    ];

    let size = bytes;
    let unitIndex = 0;


    while (
        size >= 1024 &&
        unitIndex < units.length - 1
    ) {

        size /= 1024;
        unitIndex++;

    }


    return `${size.toFixed(1)} ${units[unitIndex]}`;

}


// ============================================================
// UPDATE PREVIEW UI
// ============================================================

function updatePreviewUI(
    previewUrl,
    file,
    width,
    height
) {

    if (dom.thumbnailPreview) {

        dom.thumbnailPreview.src =
            previewUrl;

        dom.thumbnailPreview.classList.remove(
            'hidden'
        );

    }


    if (dom.selectedFileName) {

        dom.selectedFileName.textContent =
            file.name;

    }


    if (dom.selectedFileSize) {

        dom.selectedFileSize.textContent =
            formatFileSize(file.size);

    }


    setPiPImage(
        previewUrl,
        file.name,
        `${width} × ${height}px`
    );

    setPiPMetadata(
        file.name,
        `${width} × ${height}px`
    );
    hidePiP();

}


// ============================================================
// READ GEOTIFF
// ============================================================

export async function readGeoTIFF(file) {

    if (!file) {
        throw new Error(
            'No GeoTIFF file provided.'
        );
    }


    const GeoTIFF =
        getGeoTIFF();


    const arrayBuffer =
        await file.arrayBuffer();


    const tiff =
        await GeoTIFF.fromArrayBuffer(
            arrayBuffer
        );


    const image =
        await tiff.getImage();


    const width =
        image.getWidth();

    const height =
        image.getHeight();


    const samples =
        image.getSamplesPerPixel();


    // --------------------------------------------------------
    // Read raster
    // --------------------------------------------------------

    let raster;


    try {

        const result =
            await image.readRasters({
                interleave: true
            });

        raster = result;

    } catch (error) {

        const result =
            await image.readRasters();

        raster =
            result.length === 1
                ? result[0]
                : result;

    }


    return {
        raster,
        width,
        height,
        samplesPerPixel: samples
    };

}


// ============================================================
// PROCESS GEOTIFF
// ============================================================

export async function processGeoTIFF(file) {

    if (!file) {
        throw new Error(
            'No GeoTIFF file selected.'
        );
    }


    try {

        setFileStatus(
            'Reading GeoTIFF...'
        );


        const {
            raster,
            width,
            height,
            samplesPerPixel
        } = await readGeoTIFF(file);


        setFileStatus(
            'Generating elevation preview...'
        );


        const sourceCanvas =
            rasterToImageData(
                raster,
                width,
                height,
                samplesPerPixel
            );


        const previewCanvas =
            resizeCanvas(
                sourceCanvas,
                MAX_SIZE
            );


        const previewUrl =
            createPreview(
                previewCanvas
            );


        // ----------------------------------------------------
        // Replace previous preview
        // ----------------------------------------------------

        state.currentPreviewUrl =
            previewUrl;


        // ----------------------------------------------------
        // Store selected file
        // ----------------------------------------------------

        state.selectedFile =
            file;


        // ----------------------------------------------------
        // Update normal file UI
        // ----------------------------------------------------

        updatePreviewUI(
            previewUrl,
            file,
            width,
            height
        );


        // ----------------------------------------------------
        // Final status
        // ----------------------------------------------------

        setFileStatus(
            `GeoTIFF ready • ${width} × ${height}px`
        );


        setReadyStatus(
            'GeoTIFF preview ready'
        );


        return {
            file,
            width,
            height,
            samplesPerPixel,
            previewUrl
        };

    } catch (error) {

        console.error(
            'GeoTIFF processing failed:',
            error
        );


        setErrorStatus(
            error.message ||
            'Failed to process GeoTIFF.'
        );


        setFileStatus(
            'GeoTIFF processing failed'
        );


        throw error;

    }

}


// ============================================================
// CHECK WHETHER FILE IS GEOTIFF
// ============================================================

export function isGeoTIFFFile(file) {

    if (!file) {
        return false;
    }


    const name =
        file.name.toLowerCase();


    return (
        name.endsWith('.tif') ||
        name.endsWith('.tiff')
    );

}