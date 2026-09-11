import './style.css';

import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';
import { FlyControls } from 'three/examples/jsm/controls/FlyControls.js';
import { GLTFLoader } from 'three/examples/jsm/loaders/GLTFLoader.js';
import { DRACOLoader } from 'three/examples/jsm/loaders/DRACOLoader.js';

import { TilesRenderer } from '3d-tiles-renderer';

// -----------------------------
// 1. Get the container
// -----------------------------

const container = document.getElementById('canvas-container');

const coordinates = document.getElementById('coordinates');

const inspectorContent = document.getElementById('inspector-content');


// add status indicators for viewer, system, and file
const viewerStatus =
    document.getElementById('viewerStatus');

const systemStatus =
    document.getElementById('systemStatus');

const fileStatus =
    document.getElementById('fileStatus');

function setViewerStatus(status, type = 'ready') {

    viewerStatus.textContent = status;

    if (type === 'loading') {

        systemStatus.textContent =
            '● Loading terrain';

        systemStatus.style.color =
            '#f0b45b';

    } else if (type === 'error') {

        systemStatus.textContent =
            '● Load error';

        systemStatus.style.color =
            '#ff6b6b';

    } else {

        systemStatus.textContent =
            '● Viewer ready';

        systemStatus.style.color =
            '#48d597';
    }
}


// -----------------------------
// 2. Create the scene
// -----------------------------

const scene = new THREE.Scene();

//scene.background = new THREE.Color(0x1a1a24);
scene.background = null; // Transparent background

// Variable to hold the terrain model
let terrainModel = null;

let initialCameraPosition = new THREE.Vector3();
let initialCameraTarget = new THREE.Vector3();
let initialCameraZoom = 1;

// -----------------------------
// 3. Create the camera
// -----------------------------

const camera = new THREE.PerspectiveCamera(
    60,
    container.clientWidth / container.clientHeight,
    0.1,
    5000
);

camera.position.set(0, 100, 200);

const compassControl =
    document.getElementById('compass-control');

const compassFace =
    document.querySelector('.compass-face');
// const cameraDirection = new THREE.Vector3();

// camera.getWorldDirection(cameraDirection);

// const angle = Math.atan2(
//     cameraDirection.x,
//     cameraDirection.z
// );

// compass.style.transform =
//     `rotate(${angle}rad)`;

compassControl.addEventListener('click', () => {

    if (flyMode) {
        return;
    }

    orbitControls.autoRotate = false;

    const distance =
        camera.position.distanceTo(
            orbitControls.target
        );

    camera.position.set(
        0,
        distance,
        0
    );

    camera.lookAt(
        orbitControls.target
    );

    orbitControls.update();

    setTimeout(() => {

        if (!flyMode) {
            orbitControls.autoRotate = true;
        }

    }, 2000);

});

function updateCompass(force = false) {

    if (
        orbitControls.autoRotate &&
        !userInteracting &&
        !force
    ) {
        return;
    }

    const direction = new THREE.Vector3();

    camera.getWorldDirection(direction);

    const angle = Math.atan2(
        direction.x,
        direction.z
    );

    compassFace.style.transform =
        `rotate(${angle}rad)`;
}

// -----------------------------
// 4. Create the renderer
// -----------------------------

const renderer = new THREE.WebGLRenderer({
    antialias: true,
    alpha: true,
    powerPreference: 'high-performance'
});

renderer.shadowMap.enabled = true;
renderer.shadowMap.type = THREE.PCFSoftShadowMap;


renderer.setSize(
    container.clientWidth,
    container.clientHeight
);

renderer.setPixelRatio(
    Math.min(window.devicePixelRatio, 2)
);

container.appendChild(renderer.domElement);


// Variable to hold the TilesRenderer instance
let tilesRenderer = null;

function loadTileset(url) {
    console.log('Loading tileset:', url);

    tilesRenderer = new TilesRenderer(url);

    tilesRenderer.addEventListener('load-tile-set', () => {
        console.log('3D Tiles tileset loaded successfully');
    });

    tilesRenderer.addEventListener('load-content', (event) => {
        console.log('3D Tiles content loaded:', event);
    });

    tilesRenderer.addEventListener('load-error', (event) => {
        console.error('3D Tiles loading error:', event);
    });

    scene.add(tilesRenderer.group);

    tilesRenderer.setCamera(camera);
    tilesRenderer.setResolutionFromRenderer(camera, renderer);

    return tilesRenderer;
}

setViewerStatus(
    'LOADING TERRAIN',
    'loading'
);

loadTileset('/glb_tileset.json');


// -----------------------------
// 5. Add lighting
// -----------------------------

const ambientLight = new THREE.AmbientLight(
    0xffffff,
    1.5
);

const hemisphereLight = new THREE.HemisphereLight(
    0xbfd7ea,
    0x3b4650,
    0.65
);

const directionalLight = new THREE.DirectionalLight(
    0xffffff,
    2
);

directionalLight.position.set(300, 600, 250);
directionalLight.castShadow = true;

directionalLight.shadow.mapSize.width = 2048;
directionalLight.shadow.mapSize.height = 2048;

directionalLight.shadow.camera.left = -1000;
directionalLight.shadow.camera.right = 1000;
directionalLight.shadow.camera.top = 1000;
directionalLight.shadow.camera.bottom = -1000;

directionalLight.shadow.camera.near = 1;
directionalLight.shadow.camera.far = 3000;

scene.add(ambientLight);
scene.add(hemisphereLight);
scene.add(directionalLight);

// -----------------------------
// Ground Grid
// -----------------------------

const gridHelper = new THREE.GridHelper(
    2000,
    40,
    0x4d5a68,
    0x29313b
);

gridHelper.visible = false;

scene.add(gridHelper);


// -----------------------------
// 6. Add OrbitControls
// -----------------------------

const orbitControls = new OrbitControls(
    camera,
    renderer.domElement
);

orbitControls.enableDamping = true;

// Automatic terrain rotation
orbitControls.autoRotate = true;
orbitControls.autoRotateSpeed = 0.8;


//adding fly controls for free movement
const flyControls = new FlyControls(
    camera,

    renderer.domElement
);

flyControls.movementSpeed = 50;
flyControls.rollSpeed = Math.PI / 12;
flyControls.dragToLook = true;
flyControls.enabled = false;

let flyMode = false;
let userInteracting = false;
let interactionTimeout = null;


window.addEventListener('keydown', (event) => {

    if (event.key.toLowerCase() === 'f') {

        flyMode = !flyMode;

        orbitControls.enabled = !flyMode;
        flyControls.enabled = flyMode;

        console.log(
            flyMode
                ? 'Fly mode ON'
                : 'Orbit mode ON'
        );
    }

});

//add raycasting to detect clicks on the terrain model
const raycaster = new THREE.Raycaster();
const mouse = new THREE.Vector2();
renderer.domElement.addEventListener('click', (event) => {

    if (!terrainModel && !tilesRenderer) return;

    const rect = renderer.domElement.getBoundingClientRect();

    mouse.x =
        ((event.clientX - rect.left) / rect.width) * 2 - 1;

    mouse.y =
        -((event.clientY - rect.top) / rect.height) * 2 + 1;

    raycaster.setFromCamera(mouse, camera);

    let intersects = [];

if (terrainModel) {
    intersects = raycaster.intersectObject(
        terrainModel,
        true
    );
}

if (
    intersects.length === 0 &&
    tilesRenderer
) {
    intersects = raycaster.intersectObject(
        tilesRenderer.group,
        true
    );
}

    if (intersects.length > 0) {

        const point = intersects[0].point;

        console.log('Clicked terrain point:');
        console.log('X:', point.x);
        console.log('Y:', point.y);
        console.log('Z:', point.z);
        // Update the coordinates display
        coordinates.innerHTML = `
            <div class="coordinate-row">
                <span class="coordinate-label">X</span>
                <span class="coordinate-value">${point.x.toFixed(2)}</span>
            </div>

            <div class="coordinate-row">
                <span class="coordinate-label">Y</span>
                <span class="coordinate-value">${point.y.toFixed(2)}</span>
            </div>

            <div class="coordinate-row">
                <span class="coordinate-label">Z</span>
                <span class="coordinate-value">${point.z.toFixed(2)}</span>
            </div>
        `;
        inspectorContent.innerHTML = `
            <div style="line-height:1.8">
                <div>
                    <span style="color:#788596">X</span>
                    <strong>${point.x.toFixed(2)}</strong>
                </div>

                <div>
                    <span style="color:#788596">Y</span>
                    <strong>${point.y.toFixed(2)}</strong>
                </div>

                <div>
                    <span style="color:#788596">Z</span>
                    <strong>${point.z.toFixed(2)}</strong>
                </div>
            </div>
        `;

    }

});


// -----------------------------
// 7. Load GLB
// -----------------------------

const loader = new GLTFLoader();

// Set up DRACO loader
const dracoLoader = new DRACOLoader();
dracoLoader.setDecoderPath('/draco/');
loader.setDRACOLoader(dracoLoader);

loader.load(
    '/test_8_output.glb',

    (gltf) => {

        console.log('GLB loaded successfully');

        setViewerStatus(
            '3D VIEWER READY',
            'ready'
        );

        const model = gltf.scene;

        terrainModel = model;

        scene.add(model);

        // Calculate the model's bounding box
        const box = new THREE.Box3().setFromObject(model);

        const center = box.getCenter(new THREE.Vector3());
        const size = box.getSize(new THREE.Vector3());

        console.log('Model center:', center);
        console.log('Model size:', size);

        // Move model so its center is near the origin
        model.position.sub(center);

        model.traverse((object) => {
            if (object.isMesh) {
                object.castShadow = true;
                object.receiveShadow = true;
            }
        });

        // Recalculate terrain bounds after centering
        const centeredBox = new THREE.Box3().setFromObject(model);

        // Put grid slightly below the terrain
        gridHelper.position.y = centeredBox.min.y - 1;

        console.log('Grid Y position:', gridHelper.position.y);

        // Position camera according to model size
        const maxDimension = Math.max(
            size.x,
            size.y,
            size.z
        );

        const distance = maxDimension * 1.5;

        camera.position.set(
          distance,
          distance * 0.7,
          distance
        );

        camera.lookAt(0, 0, 0);

        orbitControls.target.set(0, 0, 0);
        orbitControls.update();

        initialCameraPosition.copy(camera.position);
        initialCameraTarget.copy(orbitControls.target);
        initialCameraZoom = camera.zoom;
    },

    (progress) => {

        if (progress.total) {
            const percent =
                (progress.loaded / progress.total) * 100;

            console.log(
                `Loading: ${percent.toFixed(1)}%`
            );
        }

    },

    (error) => {

        setViewerStatus(
            'ERROR LOADING TERRAIN',
            'error'
        );

        console.error(
            'Error loading GLB:',
            error
        );

    }
);


// -----------------------------
// 8. Animation loop
// -----------------------------
const timer= new THREE.Timer();

function animate() {

    requestAnimationFrame(animate);

    timer.update();

    const delta = timer.getDelta();

    if (flyMode) {
        flyControls.update(delta);
    } else {
        orbitControls.update();
    }

    camera.updateMatrixWorld();

    if (flyMode || userInteracting) {
        updateCompass();
    }

    if (tilesRenderer) {
        tilesRenderer.setCamera(camera);
        tilesRenderer.setResolutionFromRenderer(camera, renderer);
        tilesRenderer.update();
    }
    renderer.render(
        scene,
        camera
    );
}

animate();


// -----------------------------
// 9. Handle window resize
// -----------------------------

window.addEventListener(
    'resize',
    () => {

        camera.aspect =
            container.clientWidth /
            container.clientHeight;

        camera.updateProjectionMatrix();

        renderer.setSize(
            container.clientWidth,
            container.clientHeight
        );
    }
);

// -----------------------------
// 10. Backend image upload
// -----------------------------

const imageInput = document.getElementById('imageInput');
const selectedFileInfo = document.getElementById('selectedFileInfo');

imageInput.addEventListener('change', () => {

    const file = imageInput.files[0];

    if (!file) {

        selectedFileInfo.textContent =
            'No file selected';

        fileStatus.textContent =
            'No imagery selected';

        return;
    }

    const sizeMB =
        file.size / (1024 * 1024);

    selectedFileInfo.innerHTML = `
        <strong style="color:#dfe8f3">
            ${file.name}
        </strong>
        <br>
        ${file.type || 'Unknown format'}
        <br>
        ${sizeMB.toFixed(2)} MB
    `;

    fileStatus.textContent =
        `Selected: ${file.name}`;

});


const uploadBtn = document.getElementById('uploadBtn');

uploadBtn.addEventListener('click', async () => {

    const file = imageInput.files[0];

    if (!file) {
        console.log('Please select an image first.');
        return;
    }

    console.log('Selected image:', file.name);
    console.log('Image type:', file.type);
    console.log('Image size:', file.size, 'bytes');

    const formData = new FormData();
    formData.append('file', file);

    try {

        console.log('Sending image to backend...');

        const response = await fetch('/api/v1/processor', {
            method: 'POST',
            body: formData
        });

        console.log('Backend status:', response.status);

        const result = await response.json();

        console.log('Backend response:', result);

    } catch (error) {

        console.error('Backend request failed:', error);

    }

});


// -----------------------------
// UI controls
// -----------------------------

const orbitBtn = document.getElementById('orbitBtn');
const flyBtn = document.getElementById('flyBtn');
const resetBtn = document.getElementById('resetBtn');
const lightingBtn = document.getElementById('lightingBtn');
const lightSlider = document.getElementById('lightSlider');
const lightValue = document.getElementById('lightValue');

const gridBtn = document.getElementById('gridBtn');
// Grid toggle
gridBtn.addEventListener('click', () => {

    gridHelper.visible = !gridHelper.visible;

    gridBtn.classList.toggle(
        'active',
        gridHelper.visible
    );

    console.log(
        gridHelper.visible
            ? 'Grid ON'
            : 'Grid OFF'
    );

});

lightingBtn.addEventListener('click', () => {
    const isOn = lightingBtn.classList.toggle('active');

    ambientLight.visible = isOn;
    directionalLight.visible = isOn;

    lightingBtn.textContent = isOn ? 'ON' : 'OFF';
});

lightSlider.addEventListener('input', () => {
    const intensity = Number(lightSlider.value);

    directionalLight.intensity = intensity;
    lightValue.textContent = intensity.toFixed(1);
});

const helpBtn = document.getElementById('helpBtn');
const helpPanel = document.getElementById('help-panel');

const fullscreenBtn =
    document.getElementById('fullscreenBtn');


// Orbit mode
orbitBtn.addEventListener('click', () => {

    flyMode = false;

    orbitControls.enabled = true;
    flyControls.enabled = false;
    orbitControls.autoRotate = true;

    orbitBtn.classList.add('active');
    flyBtn.classList.remove('active');

    console.log('Orbit mode ON');

});

orbitControls.addEventListener('start', () => {

    userInteracting = true;

    orbitControls.autoRotate = false;

    clearTimeout(interactionTimeout);
});

orbitControls.addEventListener('end', () => {

    userInteracting = false;

    clearTimeout(interactionTimeout);

    interactionTimeout = setTimeout(() => {

        if (!flyMode) {
            orbitControls.autoRotate = true;
        }

    }, 2500);

});


// Fly mode
flyBtn.addEventListener('click', () => {

    flyMode = true;

    orbitControls.enabled = false;
    orbitControls.autoRotate = false;
    flyControls.enabled = true;
    
    flyBtn.classList.add('active');
    orbitBtn.classList.remove('active');

    console.log('Fly mode ON');

});


// Reset camera
resetBtn.addEventListener('click', () => {

    // Force Orbit mode
    flyMode = false;

    flyControls.enabled = false;
    orbitControls.enabled = true;

    orbitControls.autoRotate = true;

    // Restore camera position
    camera.position.copy(initialCameraPosition);
    camera.zoom = initialCameraZoom;
    camera.updateProjectionMatrix();

    // Restore orbit target
    orbitControls.target.copy(initialCameraTarget);

    // Make camera look toward target
    camera.lookAt(initialCameraTarget);

    // Update controls
    orbitControls.update();

    // Update UI
    orbitBtn.classList.add('active');
    flyBtn.classList.remove('active');

    console.log('Camera reset successfully');
});


// Help
helpBtn.addEventListener('click', () => {

    helpPanel.classList.toggle('show');

});


// Fullscreen
fullscreenBtn.addEventListener('click', async () => {

    if (!document.fullscreenElement) {

        await document.documentElement.requestFullscreen();

    } else {

        await document.exitFullscreen();

    }

});