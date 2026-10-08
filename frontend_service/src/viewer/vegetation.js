import * as THREE from 'three';

// Vegetation overlays (VEGETATION_CANOPY, VEGETATION_TREE_INSTANCES) are
// visualization proxies: they render like any other mesh, but scientific
// tools (height inspection, measurement, flood, route, heatmap, elevation
// comparison, model recentering) must see only terrain and buildings.
//
// GLTFLoader copies glTF node extras into userData and node names into
// object.name. Extras are authoritative; the name prefix is a guarded
// fallback that an explicit scientificSurface=true always overrides.

const VEGETATION_NAME_PREFIX = 'VEGETATION_';

function declaresVegetation(object) {
    const data = object.userData || {};
    if (data.scientificSurface === true) {
        return false;
    }
    if (data.visualizationProxy === true) {
        return true;
    }
    if (typeof data.geometrySemantic === 'string' && data.geometrySemantic.startsWith(VEGETATION_NAME_PREFIX)) {
        return true;
    }
    return typeof object.name === 'string' && object.name.startsWith(VEGETATION_NAME_PREFIX);
}

// True for a vegetation node or anything inside one.
export function isVegetationVisualizationNode(object) {
    for (let current = object; current; current = current.parent) {
        if (declaresVegetation(current)) {
            return true;
        }
    }
    return false;
}

// Raycast hits on scientific surfaces only, nearest first.
export function scientificHits(intersections) {
    return intersections.filter((hit) => !isVegetationVisualizationNode(hit.object));
}

// Vegetation subtrees are pruned before the raycast, so instanced trees
// (thousands of instances) are never tested.
function scientificObjects(object, result = []) {
    if (declaresVegetation(object)) {
        return result;
    }
    result.push(object);
    for (const child of object.children) {
        scientificObjects(child, result);
    }
    return result;
}

export function intersectScientific(raycaster, root) {
    if (isVegetationVisualizationNode(root)) {
        return [];
    }
    return scientificHits(raycaster.intersectObjects(scientificObjects(root), false));
}

// Bounds of the scientific geometry (terrain and buildings), excluding
// vegetation, in world space. Rendering may still use full visual bounds.
export function scientificBounds(root, target = new THREE.Box3()) {
    target.makeEmpty();
    root.updateWorldMatrix(true, true);
    root.traverse((object) => {
        if (object.isMesh && !isVegetationVisualizationNode(object)) {
            target.expandByObject(object, false);
        }
    });
    return target;
}
