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


// -----------------------------
// 2. Create the scene
// -----------------------------

const scene = new THREE.Scene();

scene.background = new THREE.Color(0x1a1a24);

// Create the TilesRenderer instance
const TILESET_URL = '/glb_tileset.json';
const tilesRenderer = new TilesRenderer(TILESET_URL);

console.log('TilesRenderer created');
console.log('Tileset URL:', TILESET_URL);

tilesRenderer.addEventListener('load-tile-set', () => {
    console.log('🔥 TILESET LOADED');
});

tilesRenderer.addEventListener('load-content', (event) => {
    console.log('🔥 TILE CONTENT LOADED', event);
});

tilesRenderer.addEventListener('load-error', (event) => {
    console.error('🔥 TILESET ERROR', event);
});

// testcases without  minIO
tilesRenderer.addEventListener('load-tile-set', () => {
    console.log('3D Tiles tileset loaded successfully');
});

tilesRenderer.addEventListener('load-content', (event) => {
    console.log('3D Tiles content loaded:', event);
});

tilesRenderer.addEventListener('load-error', (event) => {
    console.error('3D Tiles loading error:', event);
});

// Variable to hold the terrain model
let terrainModel = null;

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


// -----------------------------
// 4. Create the renderer
// -----------------------------

const renderer = new THREE.WebGLRenderer({
    antialias: true,
    powerPreference: 'high-performance'
});

renderer.setSize(
    container.clientWidth,
    container.clientHeight
);

renderer.setPixelRatio(
    Math.min(window.devicePixelRatio, 2)
);

container.appendChild(renderer.domElement);

// Add the TilesRenderer group to the scene
scene.add(tilesRenderer.group);


// -----------------------------
// 5. Add lighting
// -----------------------------

const ambientLight = new THREE.AmbientLight(
    0xffffff,
    1.5
);

scene.add(ambientLight);


const directionalLight = new THREE.DirectionalLight(
    0xffffff,
    2
);

directionalLight.position.set(200, 400, 200);

scene.add(directionalLight);


// -----------------------------
// 6. Add OrbitControls
// -----------------------------

const orbitControls = new OrbitControls(
    camera,
    renderer.domElement
);

orbitControls.enableDamping = true;


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

    if (!terrainModel) return;

    const rect = renderer.domElement.getBoundingClientRect();

    mouse.x =
        ((event.clientX - rect.left) / rect.width) * 2 - 1;

    mouse.y =
        -((event.clientY - rect.top) / rect.height) * 2 + 1;

    raycaster.setFromCamera(mouse, camera);

    const intersects =
        raycaster.intersectObject(terrainModel, true);

    if (intersects.length > 0) {

        const point = intersects[0].point;

        console.log('Clicked terrain point:');
        console.log('X:', point.x);
        console.log('Y:', point.y);
        console.log('Z:', point.z);
        // Update the coordinates display
        coordinates.innerHTML = `
          <div><strong>X:</strong> ${point.x.toFixed(2)}</div>
          <div><strong>Y:</strong> ${point.y.toFixed(2)}</div>
          <div><strong>Z:</strong> ${point.z.toFixed(2)}</div>
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

    tilesRenderer.setCamera(camera);
    tilesRenderer.setResolutionFromRenderer(camera, renderer);
    tilesRenderer.update();

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