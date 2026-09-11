import { useState, useCallback } from 'react';
import type { PipelineStage } from '../types/gis';
import type { ElevationJobResponse } from '../types/elevationApi';

export interface UseElevationPipelineReturn {
  pipelineStage: PipelineStage;
  setPipelineStage: (stage: PipelineStage) => void;
  activeJobResponse: ElevationJobResponse | null;
  setActiveJobResponse: (resp: ElevationJobResponse | null) => void;
  isProcessing: boolean;
  errorMessage: string | null;
  clearError: () => void;
  submitElevationJob: (file: File) => Promise<ElevationJobResponse>;
  loadPresetJob: (presetKey: string) => ElevationJobResponse;
}

// In-Memory Benchmark Presets with Pure Client-Side Synthetic Metrics
const PRESET_MOCK_RESPONSES: Record<string, ElevationJobResponse> = {
  'alpine-ridge-dsm': {
    uuid: 'a3f12d80-5b12-4c23-8c7a-e490218fa21e',
    tilesetUrl: '', // Pure client-side procedural terrain (zero remote tileset requests)
    crs: 'EPSG:4326 (WGS84)',
    bounds: [7.692800, 45.964500, 7.724800, 45.988500],
    minElevation: 1840.5,
    maxElevation: 3845.0,
    isGeoreferenced: true,
    metrics: {
      rmse: 1.18,
      mae: 0.89,
      correlation: 0.96,
      f1Score: 0.924
    }
  },
  'quarry-mine-rdsm': {
    uuid: 'b7c43e91-6a23-4f81-9b8b-d381920fc32a',
    tilesetUrl: '',
    crs: 'EPSG:4326 (WGS84)',
    bounds: [11.235100, 43.768200, 11.258900, 43.785400],
    minElevation: 120.0,
    maxElevation: 465.2,
    isGeoreferenced: true,
    metrics: {
      rmse: 1.05,
      mae: 0.78,
      correlation: 0.978,
      f1Score: 0.941
    }
  },
  'coastal-fjord-dsm': {
    uuid: 'c9d82a10-7e45-4c92-8f12-e194830ba54c',
    tilesetUrl: '',
    crs: 'EPSG:4326 (WGS84)',
    bounds: [5.289100, 60.384200, 5.324500, 60.409800],
    minElevation: 0.0,
    maxElevation: 1120.4,
    isGeoreferenced: true,
    metrics: {
      rmse: 1.25,
      mae: 0.94,
      correlation: 0.955,
      f1Score: 0.915
    }
  }
};

/**
 * Pure Client-Side Single-View Elevation Pipeline Hook.
 * Executes 100% in-browser without any backend server dependencies or external HTTP requests.
 */
export function useElevationPipeline(): UseElevationPipelineReturn {
  const [pipelineStage, setPipelineStage] = useState<PipelineStage>('streaming');
  const [activeJobResponse, setActiveJobResponse] = useState<ElevationJobResponse | null>(
    PRESET_MOCK_RESPONSES['alpine-ridge-dsm']
  );
  const [isProcessing, setIsProcessing] = useState<boolean>(false);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);

  const clearError = useCallback(() => {
    setErrorMessage(null);
  }, []);

  // Preset job loader
  const loadPresetJob = useCallback((presetKey: string): ElevationJobResponse => {
    const mock = PRESET_MOCK_RESPONSES[presetKey] || PRESET_MOCK_RESPONSES['alpine-ridge-dsm'];
    setActiveJobResponse(mock);
    return mock;
  }, []);

  // Main client-side pipeline simulation: progresses realistically through ML inference stages
  const submitElevationJob = useCallback(async (_file: File): Promise<ElevationJobResponse> => {
    setIsProcessing(true);
    setErrorMessage(null);

    // 1. Upload & EXIF Parsing Simulation
    setPipelineStage('upload');
    await new Promise(res => setTimeout(res, 350));

    // 2. Monocular ViT Height Regression
    setPipelineStage('depth_estimation');
    await new Promise(res => setTimeout(res, 450));

    // 3. Metric Datum Anchor & Scale Calibration
    setPipelineStage('metric_calibration');
    await new Promise(res => setTimeout(res, 400));

    // 4. 3D Terrain Mesh & Spatial Tiling
    setPipelineStage('tiling');
    await new Promise(res => setTimeout(res, 400));

    // Synthesize realistic job response for uploaded raster
    const syntheticUuid = crypto.randomUUID ? crypto.randomUUID() : `job-${Date.now()}`;
    const mockResponse: ElevationJobResponse = {
      uuid: syntheticUuid,
      tilesetUrl: '',
      crs: 'EPSG:4326 (WGS84)',
      bounds: [7.695000, 45.968000, 7.722000, 45.986000],
      minElevation: 450.0,
      maxElevation: 1980.5,
      isGeoreferenced: true,
      metrics: {
        rmse: 1.18,
        mae: 0.89,
        correlation: 0.96,
        f1Score: 0.924
      }
    };

    setPipelineStage('streaming');
    setActiveJobResponse(mockResponse);
    setIsProcessing(false);
    return mockResponse;
  }, []);

  return {
    pipelineStage,
    setPipelineStage,
    activeJobResponse,
    setActiveJobResponse,
    isProcessing,
    errorMessage,
    clearError,
    submitElevationJob,
    loadPresetJob
  };
}
