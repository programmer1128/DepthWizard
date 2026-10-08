// ============================================================
// DEPTHWIZARD
// SAMPLE TERRAIN CATALOG
//
// All four categories intentionally point to the same temporary
// GLB/preview. Replace only modelUrl and previewUrl later when
// category-specific assets are available.
// ============================================================

export const SAMPLE_TERRAINS = Object.freeze({
    urban: {
        id: 'urban',
        label: 'Urban Area',
        description: 'Dense buildings and complex structural boundaries.',
        modelUrl: '/new_test.glb',
        previewUrl: '/demo_optical.png'
    },
    sparse: {
        id: 'sparse',
        label: 'Sparse / Rural Area',
        description: 'Low-density structures and open terrain.',
        modelUrl: '/new_test.glb',
        previewUrl: '/demo_optical.png'
    },
    hilly: {
        id: 'hilly',
        label: 'Hilly Terrain',
        description: 'Sloped terrain and larger elevation variation.',
        modelUrl: '/new_test.glb',
        previewUrl: '/demo_optical.png'
    },
    forested: {
        id: 'forested',
        label: 'Forested Landscape',
        description: 'Vegetation-heavy terrain and irregular canopy structure.',
        modelUrl: '/new_test.glb',
        previewUrl: '/demo_optical.png'
    }
});

export function getSampleTerrain(sampleId = 'urban') {
    return SAMPLE_TERRAINS[sampleId] || SAMPLE_TERRAINS.urban;
}
