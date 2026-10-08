// node --test: vegetation overlays render normally but never reach scientific tools.
import test from 'node:test';
import assert from 'node:assert/strict';
import * as THREE from 'three';

import {
    intersectScientific,
    isVegetationVisualizationNode,
    scientificBounds,
    scientificHits
} from './vegetation.js';

// A model shaped like a DepthWizard GLB: one unnamed base node holding
// terrain and building meshes, plus an appended VEGETATION_CANOPY node with
// the extras the backend writes.
function makeModel({ withCanopy = true, canopyExtras = true } = {}) {
    const model = new THREE.Group();
    const base = new THREE.Group();
    model.add(base);

    const terrain = new THREE.Mesh(new THREE.PlaneGeometry(100, 100), new THREE.MeshStandardMaterial());
    terrain.rotation.x = -Math.PI / 2; // Horizontal at y = 0
    terrain.name = 'terrain';
    base.add(terrain);

    const building = new THREE.Mesh(new THREE.BoxGeometry(10, 30, 10), new THREE.MeshStandardMaterial());
    building.position.set(30, 15, 30);
    building.name = 'building';
    base.add(building);

    let canopy = null;
    if (withCanopy) {
        // A canopy sheet 50 m up over the western half: taller than everything else.
        canopy = new THREE.Mesh(new THREE.PlaneGeometry(40, 40), new THREE.MeshStandardMaterial());
        canopy.rotation.x = -Math.PI / 2;
        canopy.position.set(-25, 50, 0);
        canopy.name = 'VEGETATION_CANOPY';
        if (canopyExtras) {
            canopy.userData = {
                geometrySemantic: 'VEGETATION_CANOPY',
                visualizationProxy: true,
                scientificSurface: false
            };
        }
        model.add(canopy);
    }
    model.updateMatrixWorld(true);
    return { model, terrain, building, canopy };
}

function downRay(x, z) {
    const raycaster = new THREE.Raycaster();
    raycaster.set(new THREE.Vector3(x, 200, z), new THREE.Vector3(0, -1, 0));
    return raycaster;
}

test('the predicate recognises canopy extras, children and the guarded name fallback', () => {
    const { terrain, building, canopy } = makeModel();
    assert.equal(isVegetationVisualizationNode(canopy), true);
    assert.equal(isVegetationVisualizationNode(terrain), false);
    assert.equal(isVegetationVisualizationNode(building), false);

    const child = new THREE.Object3D();
    canopy.add(child);
    assert.equal(isVegetationVisualizationNode(child), true);

    const named = makeModel({ canopyExtras: false }).canopy; // Name only
    assert.equal(isVegetationVisualizationNode(named), true);
    named.userData.scientificSurface = true; // Explicit extras win over the name
    assert.equal(isVegetationVisualizationNode(named), false);

    const trees = new THREE.Object3D();
    trees.userData.geometrySemantic = 'VEGETATION_TREE_INSTANCES';
    assert.equal(isVegetationVisualizationNode(trees), true);
});

test('scientific raycasts skip the canopy and still hit terrain and buildings', () => {
    const { model, terrain, building, canopy } = makeModel();

    const underCanopy = downRay(-25, 0);
    const raw = underCanopy.intersectObject(model, true);
    assert.equal(raw[0].object, canopy); // The renderer's view: canopy on top
    const hits = intersectScientific(underCanopy, model);
    assert.equal(hits[0].object, terrain);
    assert.ok(Math.abs(hits[0].point.y) < 1e-6);
    assert.ok(hits.every((hit) => hit.object !== canopy));

    // Building selection is unchanged.
    const onBuilding = intersectScientific(downRay(30, 30), model);
    assert.equal(onBuilding[0].object, building);
    assert.ok(Math.abs(onBuilding[0].point.y - 30) < 1e-6);

    assert.deepEqual(scientificHits(raw).map((hit) => hit.object), [terrain]);
});

test('the canopy does not change the recentering reference bounds', () => {
    const bare = makeModel({ withCanopy: false }).model;
    const { model } = makeModel();
    const reference = scientificBounds(bare);
    const withCanopy = scientificBounds(model);
    assert.deepEqual(withCanopy.min.toArray(), reference.min.toArray());
    assert.deepEqual(withCanopy.max.toArray(), reference.max.toArray());
    const centre = (box) => box.getCenter(new THREE.Vector3()).toArray();
    assert.deepEqual(centre(withCanopy), centre(reference));
});

test('normal visual rendering still includes the canopy', () => {
    const { model, canopy } = makeModel();
    assert.equal(canopy.visible, true);
    assert.equal(canopy.parent, model);
    const visual = new THREE.Box3().setFromObject(model);
    assert.ok(visual.max.y >= 50 - 1e-6); // Visual bounds reach the canopy
    assert.ok(scientificBounds(model).max.y <= 30 + 1e-6);
    let rendered = 0;
    model.traverse((object) => { if (object.isMesh && object.visible) rendered += 1; });
    assert.equal(rendered, 3);
});
