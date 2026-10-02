import 'maplibre-gl/dist/maplibre-gl.css';
import mapLibreWorkerUrl from 'maplibre-gl/dist/maplibre-gl-worker.mjs?url';

import { dom } from '../core/dom.js';
import { generateGlobalMapGeoTIFF } from '../services/backend.js';
import {
    hideProcessingOverlay,
    setFileStatus,
    setViewerStatus,
    showProcessingOverlay
} from '../ui/status.js';

const VECTOR_STYLE = {
    version: 8,
    sources: {
        vectorPreview: {
            type: 'raster',
            tiles: ['https://tile.openstreetmap.org/{z}/{x}/{y}.png'],
            tileSize: 256,
            maxzoom: 19,
            attribution: '© OpenStreetMap contributors'
        }
    },
    layers: [{ id: 'vector-preview', type: 'raster', source: 'vectorPreview' }]
};

const RASTER_STYLES = {
    satellite: {
        version: 8,
        sources: {
            satellite: {
                type: 'raster',
                tiles: [
                    'https://server.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/{z}/{y}/{x}'
                ],
                tileSize: 256,
                attribution: 'Imagery © Esri and contributors'
            }
        },
        layers: [{ id: 'satellite', type: 'raster', source: 'satellite' }]
    },
    topo: {
        version: 8,
        sources: {
            topo: {
                type: 'raster',
                tiles: ['https://tile.opentopomap.org/{z}/{x}/{y}.png'],
                tileSize: 256,
                maxzoom: 17,
                attribution: '© OpenStreetMap contributors, SRTM | OpenTopoMap'
            }
        },
        layers: [{ id: 'topo', type: 'raster', source: 'topo' }]
    }
};

let initialized = false;
let map = null;
let modal = null;
let onGeoTIFFReady = null;
let mapLibreModule = null;

async function loadMapLibre() {
    if (!mapLibreModule) {
        mapLibreModule = await import('maplibre-gl');
        mapLibreModule.setWorkerUrl(mapLibreWorkerUrl);
    }
    return mapLibreModule;
}

function haversineKm(a, b) {
    const radius = 6371;
    const toRad = (value) => value * Math.PI / 180;
    const dLat = toRad(b.lat - a.lat);
    const dLng = toRad(b.lng - a.lng);
    const lat1 = toRad(a.lat);
    const lat2 = toRad(b.lat);
    const h = Math.sin(dLat / 2) ** 2 +
        Math.cos(lat1) * Math.cos(lat2) * Math.sin(dLng / 2) ** 2;
    return radius * 2 * Math.atan2(Math.sqrt(h), Math.sqrt(1 - h));
}

function getSelection() {
    if (!map || !modal) return null;

    const mapElement = modal.querySelector('#globalMapCanvas');
    const frame = modal.querySelector('#globalMapSelectionFrame');
    const mapRect = mapElement.getBoundingClientRect();
    const frameRect = frame.getBoundingClientRect();

    const northWest = map.unproject([
        frameRect.left - mapRect.left,
        frameRect.top - mapRect.top
    ]);
    const southEast = map.unproject([
        frameRect.right - mapRect.left,
        frameRect.bottom - mapRect.top
    ]);

    const bbox = [
        Number(northWest.lng.toFixed(7)),
        Number(southEast.lat.toFixed(7)),
        Number(southEast.lng.toFixed(7)),
        Number(northWest.lat.toFixed(7))
    ];

    const centerLat = (bbox[1] + bbox[3]) / 2;
    const centerLng = (bbox[0] + bbox[2]) / 2;
    const widthKm = haversineKm(
        { lat: centerLat, lng: bbox[0] },
        { lat: centerLat, lng: bbox[2] }
    );
    const heightKm = haversineKm(
        { lat: bbox[1], lng: centerLng },
        { lat: bbox[3], lng: centerLng }
    );

    return { bbox, widthKm, heightKm, centerLat, centerLng };
}

function updateSelectionReadout() {
    const selection = getSelection();
    if (!selection || !modal) return;

    const bounds = modal.querySelector('#globalMapBounds');
    const size = modal.querySelector('#globalMapAreaSize');
    if (bounds) {
        bounds.textContent =
            `${selection.bbox[1].toFixed(5)}, ${selection.bbox[0].toFixed(5)} → ` +
            `${selection.bbox[3].toFixed(5)}, ${selection.bbox[2].toFixed(5)}`;
    }
    if (size) {
        size.textContent =
            `${selection.widthKm.toFixed(1)} × ${selection.heightKm.toFixed(1)} km`;
    }
}

function setBasemap(name) {
    if (!map) return;
    map.setStyle(name === 'vector' ? VECTOR_STYLE : RASTER_STYLES[name]);
    modal?.querySelectorAll('[data-global-basemap]').forEach((button) => {
        button.classList.toggle('active', button.dataset.globalBasemap === name);
    });
}

function closeGlobalMap() {
    if (!modal) {
        return;
    }

    /*
     * Move keyboard focus outside the modal before hiding it.
     * This prevents the browser's blocked aria-hidden warning.
     */
    const focusedElement =
        document.activeElement;

    if (
        focusedElement instanceof HTMLElement &&
        modal.contains(focusedElement)
    ) {
        focusedElement.blur();

        if (dom.emptyGlobalMapTrigger) {
            dom.emptyGlobalMapTrigger.focus({
                preventScroll: true
            });
        }
    }

    /*
     * inert prevents the hidden modal's buttons and inputs
     * from receiving keyboard focus.
     */
    modal.inert = true;

    modal.classList.add(
        'hidden'
    );

    modal.setAttribute(
        'aria-hidden',
        'true'
    );
}

async function openGlobalMap() {
    if (!modal) {
        return;
    }

    /*
     * Remove inert before making the modal interactive.
     */
    modal.inert = false;

    modal.classList.remove(
        'hidden'
    );

    modal.setAttribute(
        'aria-hidden',
        'false'
    );

    window.requestAnimationFrame(() => {

        /*
         * Put keyboard focus into the opened modal.
         */
        modal
            .querySelector('#globalMapSearchInput')
            ?.focus({
                preventScroll: true
            });
        if (!map) {
            loadMapLibre().then(({ Map, NavigationControl }) => {
                if (map || modal.classList.contains('hidden')) return;
                map = new Map({
                container: 'globalMapCanvas',
                style: VECTOR_STYLE,
                center: [88.3639, 22.5726],
                zoom: 10.5,
                minZoom: 2,
                maxZoom: 16,
                attributionControl: true
            });
                map.addControl(new NavigationControl(), 'top-left');
                map.on('move', updateSelectionReadout);
                map.on('zoom', updateSelectionReadout);
                map.on('load', updateSelectionReadout);
                window.setTimeout(() => {
                    map?.resize();
                    updateSelectionReadout();
                }, 50);
            }).catch((error) => {
                setViewerStatus('MAP VIEW FAILED TO LOAD', 'error');
                setFileStatus(error.message || 'Unable to load the global map.');
                closeGlobalMap();
            });
        } else {
            map.resize();
            updateSelectionReadout();
        }
    });
}

async function searchLocation(query) {
    const results = modal?.querySelector('#globalMapSearchResults');
    if (!results || !query.trim()) return;

    results.innerHTML = '<div class="global-map-search-message">Searching…</div>';

    try {
        const response = await fetch(
            `https://nominatim.openstreetmap.org/search?format=jsonv2&limit=6&q=${encodeURIComponent(query.trim())}`,
            { headers: { Accept: 'application/json' } }
        );
        if (!response.ok) throw new Error('Search service unavailable.');
        const places = await response.json();

        if (!places.length) {
            results.innerHTML = '<div class="global-map-search-message">No places found.</div>';
            return;
        }

        results.innerHTML = places.map((place, index) => `
            <button type="button" class="global-map-search-result" data-result-index="${index}">
                ${place.display_name}
            </button>
        `).join('');

        results.querySelectorAll('[data-result-index]').forEach((button) => {
            button.addEventListener('click', () => {
                const place = places[Number(button.dataset.resultIndex)];
                const bbox = place.boundingbox?.map(Number);
                if (bbox?.length === 4) {
                    map.fitBounds(
                        [[bbox[2], bbox[0]], [bbox[3], bbox[1]]],
                        { padding: 120, maxZoom: 13, duration: 900 }
                    );
                } else {
                    map.flyTo({
                        center: [Number(place.lon), Number(place.lat)],
                        zoom: 11
                    });
                }
                results.innerHTML = '';
            });
        });
    } catch (error) {
        results.innerHTML =
            `<div class="global-map-search-message error">${error.message}</div>`;
    }
}

async function generateFromSelection() {

    /*
     * Important: selection must be declared inside this function.
     */
    const selection =
        getSelection();

    if (!selection) {
        console.error(
            '[DepthWizard Global Map] No valid map selection was available.'
        );

        setFileStatus(
            'Move or zoom the map before generating.'
        );

        return;
    }


    /*
     * Prevent accidentally requesting an extremely large area.
     */
    if (
        selection.widthKm > 500 ||
        selection.heightKm > 500
    ) {
        setFileStatus(
            'Zoom in: the selected area must be smaller than 500 km per side.'
        );

        return;
    }


    /*
     * Read the map-generation options before closing the modal.
     */
    const resolution =
        Number(
            modal
                ?.querySelector('#globalMapResolution')
                ?.value || 1024
        );

    const maxCloudCoverage =
        Number(
            modal
                ?.querySelector('#globalMapCloudCoverage')
                ?.value || 20
        );


    /*
     * Print the exact request information in the console.
     */
    console.groupCollapsed(
        '[DepthWizard Global Map] Selected map area'
    );

    console.info(
        'Bounding box:',
        selection.bbox
    );

    console.info(
        'Area:',
        `${selection.widthKm.toFixed(1)} × ` +
        `${selection.heightKm.toFixed(1)} km`
    );

    console.info(
        'Output resolution:',
        `${resolution} × ${resolution}`
    );

    console.info(
        'Maximum cloud coverage:',
        `${maxCloudCoverage}%`
    );

    console.groupEnd();


    /*
     * Closing the modal now moves focus away from the
     * Generate button before aria-hidden is applied.
     */
    closeGlobalMap();


    /*
     * Display the processing overlay.
     */
    showProcessingOverlay(
        'Preparing satellite GeoTIFF',
        'Requesting the least-cloudy Sentinel-2 true-colour image for the selected area…'
    );

    setViewerStatus(
        'GENERATING GLOBAL MAP GEOTIFF',
        'loading'
    );

    setFileStatus(
        'Downloading selected satellite imagery…'
    );


    /*
     * Allow the browser to visibly paint the processing overlay
     * before beginning the network request.
     */
    await new Promise((resolve) => {
        requestAnimationFrame(() => {
            requestAnimationFrame(resolve);
        });
    });


    const loadingStartedAt =
        performance.now();


    try {
        /*
         * Ask the backend to generate the selected GeoTIFF.
         */
        const file =
            await generateGlobalMapGeoTIFF({
                bbox:
                    selection.bbox,

                width:
                    resolution,

                height:
                    resolution,

                maxCloudCoverage
            });


        console.info(
            '[DepthWizard Global Map] GeoTIFF returned by backend:',
            {
                name:
                    file.name,

                type:
                    file.type,

                sizeBytes:
                    file.size,

                sizeMB:
                    (
                        file.size /
                        1024 /
                        1024
                    ).toFixed(2)
            }
        );


        if (
            typeof onGeoTIFFReady !==
            'function'
        ) {
            throw new Error(
                'The terrain processor is not connected.'
            );
        }


        /*
         * Pass the returned GeoTIFF into the existing
         * /api/v1/processor workflow.
         */
        await onGeoTIFFReady(
            file
        );

    } catch (error) {
        console.error(
            '[DepthWizard Global Map] Generation failed:',
            error
        );


        /*
         * Make sure the processing animation remains visible
         * long enough to be perceived.
         */
        const elapsed =
            performance.now() -
            loadingStartedAt;

        const remaining =
            Math.max(
                0,
                1200 - elapsed
            );


        if (remaining > 0) {
            await new Promise((resolve) => {
                setTimeout(
                    resolve,
                    remaining
                );
            });
        }


        hideProcessingOverlay();


        setViewerStatus(
            error?.message ||
            'GLOBAL MAP GENERATION FAILED',
            'error'
        );


        setFileStatus(
            error?.message ||
            'Unable to generate the selected GeoTIFF.'
        );
    }
}

function createModal() {
    const element =
        document.createElement('div');

    element.id =
        'globalMapModal';

    element.className =
        'global-map-modal hidden';

    element.setAttribute(
        'aria-hidden',
        'true'
    );

    /*
     * The modal starts hidden, so none of its controls
     * should initially be focusable.
     */
    element.inert = true;
    element.innerHTML = `
        <div class="global-map-shell">
            <header class="global-map-header">
                <div>
                    <div class="global-map-kicker">GLOBAL SATELLITE SOURCE</div>
                    <h2>Select an area for 3D reconstruction</h2>
                </div>
                <button id="globalMapClose" class="global-map-close" type="button" aria-label="Close global map">×</button>
            </header>

            <div class="global-map-stage">
                <div id="globalMapCanvas" class="global-map-canvas"></div>

                <form id="globalMapSearchForm" class="global-map-search">
                    <input id="globalMapSearchInput" type="search" placeholder="Search city, landmark or coordinates" autocomplete="off" />
                    <button type="submit">Search</button>
                    <div id="globalMapSearchResults" class="global-map-search-results"></div>
                </form>

                <div id="globalMapSelectionFrame" class="global-map-selection-frame" aria-hidden="true">
                    <span class="corner top-left"></span>
                    <span class="corner top-right"></span>
                    <span class="corner bottom-left"></span>
                    <span class="corner bottom-right"></span>
                    <div class="global-map-frame-label">SELECTED CAPTURE AREA</div>
                </div>

                <div class="global-map-basemaps" aria-label="Map style">
                    <button type="button" class="active" data-global-basemap="vector">Vector</button>
                    <button type="button" data-global-basemap="satellite">Satellite</button>
                    <button type="button" data-global-basemap="topo">Topo</button>
                </div>
            </div>

            <footer class="global-map-footer">
                <div class="global-map-selection-info">
                    <span>Selected bounds</span>
                    <strong id="globalMapBounds">Move or zoom the map</strong>
                    <small id="globalMapAreaSize">—</small>
                </div>

                <label>
                    Frame size
                    <input id="globalMapFrameSize" type="range" min="28" max="72" value="48" />
                </label>

                <label>
                    Output
                    <select id="globalMapResolution">
                        <option value="768">768 × 768</option>
                        <option value="1024" selected>1024 × 1024</option>
                        <option value="1536">1536 × 1536</option>
                        <option value="2048">2048 × 2048</option>
                    </select>
                </label>

                <label>
                    Max cloud
                    <select id="globalMapCloudCoverage">
                        <option value="10">10%</option>
                        <option value="20" selected>20%</option>
                        <option value="40">40%</option>
                        <option value="70">70%</option>
                    </select>
                </label>

                <button id="globalMapGenerate" class="global-map-generate" type="button">
                    Generate 3D Map
                </button>
            </footer>
        </div>
    `;
    document.getElementById('viewer')?.appendChild(element);
    return element;
}

export function initGlobalMap({ onGeoTIFF } = {}) {
    if (initialized) {
        onGeoTIFFReady = onGeoTIFF || onGeoTIFFReady;
        return;
    }
    initialized = true;
    onGeoTIFFReady = onGeoTIFF;
    modal = createModal();

    dom.emptyGlobalMapTrigger?.addEventListener('click', openGlobalMap);
    dom.globalMapTrigger?.addEventListener('click', openGlobalMap);
    modal.querySelector('#globalMapClose')?.addEventListener('click', closeGlobalMap);
    modal.querySelector('#globalMapGenerate')?.addEventListener('click', generateFromSelection);

    modal.querySelector('#globalMapSearchForm')?.addEventListener('submit', (event) => {
        event.preventDefault();
        searchLocation(modal.querySelector('#globalMapSearchInput')?.value || '');
    });

    modal.querySelectorAll('[data-global-basemap]').forEach((button) => {
        button.addEventListener('click', () => setBasemap(button.dataset.globalBasemap));
    });

    modal.querySelector('#globalMapFrameSize')?.addEventListener('input', (event) => {
        modal.style.setProperty('--global-frame-size', `${Number(event.target.value)}%`);
        updateSelectionReadout();
    });

    document.addEventListener('keydown', (event) => {
        if (event.key === 'Escape' && !modal.classList.contains('hidden')) {
            closeGlobalMap();
        }
    });
}