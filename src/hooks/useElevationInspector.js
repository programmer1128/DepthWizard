'use client';

import { useState, useCallback, useRef } from 'react';
import { TerrainRaycaster } from '../utils/terrainRaycaster.js';

/**
 * useElevationInspector - React hook for managing terrain raycast inspection
 * and Surface Elevation card state in Next.js / React applications.
 */
export function useElevationInspector(initialData = null) {
  const [inspectionData, setInspectionData] = useState(
    initialData || {
      latitude: 45.980776,
      longitude: 7.696169,
      elevation: 1879.09,
      slopeAngle: 8.6,
      eyeAltitude: 354.2,
      targetRange: 482.7
    }
  );

  const [isCardOpen, setIsCardOpen] = useState(true);
  const raycasterRef = useRef(null);

  /**
   * Attach Raycaster to Three.js scene and canvas DOM element
   */
  const initRaycaster = useCallback((scene, camera, domElement, getTerrainMesh) => {
    if (raycasterRef.current) {
      raycasterRef.current.dispose();
    }

    raycasterRef.current = new TerrainRaycaster({
      scene,
      camera,
      domElement,
      getTerrainMesh,
      onInspect: (data) => {
        setInspectionData(data);
        setIsCardOpen(true);
      }
    });

    return raycasterRef.current;
  }, []);

  /**
   * Update animation loop tick for the pulsing cyan 3D pin
   */
  const updateTick = useCallback((delta) => {
    if (raycasterRef.current) {
      raycasterRef.current.update(delta);
    }
  }, []);

  const closeCard = useCallback(() => {
    setIsCardOpen(false);
    if (raycasterRef.current) {
      raycasterRef.current.hidePin();
    }
  }, []);

  const openCard = useCallback(() => {
    setIsCardOpen(true);
  }, []);

  return {
    inspectionData,
    isCardOpen,
    openCard,
    closeCard,
    initRaycaster,
    updateTick,
    raycaster: raycasterRef.current
  };
}
