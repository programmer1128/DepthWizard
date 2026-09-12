'use client';

import { useState, useCallback, useRef } from 'react';
import { TerrainRaycaster } from '../utils/terrainRaycaster.js';

export function useElevationInspector(initialData = null) {
  const [inspectionData, setInspectionData] = useState(initialData);
  const [isCardOpen, setIsCardOpen] = useState(false);
  const raycasterRef = useRef(null);

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
      },
      onDeselect: () => {
        setIsCardOpen(false);
        setInspectionData(null);
      }
    });
  }, []);

  const closeCard = useCallback(() => {
    setIsCardOpen(false);
    setInspectionData(null);
  }, []);

  return {
    inspectionData,
    setInspectionData,
    isCardOpen,
    setIsCardOpen,
    closeCard,
    initRaycaster,
  };
}
