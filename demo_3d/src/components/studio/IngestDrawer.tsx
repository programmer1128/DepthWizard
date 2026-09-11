import React, { useState, useRef } from 'react';
import { 
  UploadCloud, 
  CheckCircle2, 
  AlertTriangle, 
  FileCheck, 
  X, 
  Eye, 
  Activity, 
  Globe,
  Cpu
} from 'lucide-react';
import type { 
  DatasetMode,
  ShadingMode, 
  PipelineStage, 
  FileIngestValidation,
  TerrainMetadata 
} from '../../types/gis';
import type { ElevationJobResponse } from '../../types/elevationApi';
import { PRESET_DATASETS } from '../../data/presets';
import { formatFileSize } from '../../utils/formatters';

interface IngestDrawerProps {
  isOpen: boolean;
  onClose: () => void;
  currentMetadata: TerrainMetadata;
  shadingMode: ShadingMode;
  onShadingModeChange: (shading: ShadingMode) => void;
  pipelineStage: PipelineStage;
  onRunPipeline: (file: File, mode: DatasetMode) => void;
  onSelectPreset: (presetId: string) => void;
  activeJobResponse: ElevationJobResponse | null;
}

export const IngestDrawer: React.FC<IngestDrawerProps> = ({
  isOpen,
  onClose,
  currentMetadata,
  shadingMode,
  onShadingModeChange,
  pipelineStage,
  onRunPipeline,
  onSelectPreset,
  activeJobResponse,
}) => {
  const [isDragActive, setIsDragActive] = useState(false);
  const [validationState, setValidationState] = useState<FileIngestValidation | null>(null);
  const [validationError, setValidationError] = useState<string | null>(null);
  const fileInputRef = useRef<HTMLInputElement>(null);

  if (!isOpen) return null;

  // Strict File Extension Validation (.tif, .tiff, .png, .jpg, .jpeg)
  const validateAndProcessFile = (file: File) => {
    setValidationError(null);
    const fileName = file.name;
    const ext = '.' + fileName.split('.').pop()?.toLowerCase();

    const isGeoTiff = ext === '.tif' || ext === '.tiff';
    const isImage = ext === '.png' || ext === '.jpg' || ext === '.jpeg';

    if (isGeoTiff || isImage) {
      const mode: DatasetMode = 'georeferenced'; // defaults to georeferenced metric DSM
      const validState: FileIngestValidation = {
        file,
        name: fileName,
        size: file.size,
        extension: ext,
        detectedMode: mode,
        isValid: true
      };
      setValidationState(validState);
      onRunPipeline(file, mode);
      return;
    }

    // Reject all other extensions
    const errorMsg = `Unsupported format "${ext}". Allowed extensions: .tif, .tiff, .png, .jpg, .jpeg`;
    setValidationError(errorMsg);
    setValidationState({
      file: null,
      name: fileName,
      size: file.size,
      extension: ext,
      detectedMode: 'georeferenced',
      isValid: false,
      errorMessage: errorMsg
    });
  };

  const handleDragOver = (e: React.DragEvent) => {
    e.preventDefault();
    setIsDragActive(true);
  };

  const handleDragLeave = () => {
    setIsDragActive(false);
  };

  const handleDrop = (e: React.DragEvent) => {
    e.preventDefault();
    setIsDragActive(false);
    if (e.dataTransfer.files && e.dataTransfer.files.length > 0) {
      validateAndProcessFile(e.dataTransfer.files[0]);
    }
  };

  const handleFileInputChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    if (e.target.files && e.target.files.length > 0) {
      validateAndProcessFile(e.target.files[0]);
    }
  };

  // Upload & Inference Progress Phases: (Upload -> Monocular Depth -> Metric Calibration -> 3D Tiling -> Stream)
  const PIPELINE_STEPS = [
    { key: 'upload', label: '1. Upload & Parse', desc: 'Metadata & EXIF Extraction' },
    { key: 'depth_estimation', label: '2. Monocular Depth', desc: 'Dense ViT Height Regression' },
    { key: 'metric_calibration', label: '3. Metric Calibration', desc: 'Ground Anchor & Datum Fitting' },
    { key: 'tiling', label: '4. 3D Spatial Tiling', desc: 'Hierarchical LoD Quadtree' },
    { key: 'streaming', label: '5. Stream Ready', desc: 'Interactive 3D Terrain Stream' },
  ];

  const getStepStatus = (stepKey: string) => {
    const order = ['idle', 'upload', 'depth_estimation', 'metric_calibration', 'tiling', 'streaming'];
    const currentIndex = order.indexOf(pipelineStage);
    const stepIndex = order.indexOf(stepKey);

    if (pipelineStage === 'idle') return 'idle';
    if (stepIndex < currentIndex || pipelineStage === 'streaming') return 'complete';
    if (stepIndex === currentIndex) return 'active';
    return 'pending';
  };

  return (
    <div 
      className="w-84 sm:w-96 h-[calc(100vh-3.5rem)] bg-slate-900/95 backdrop-blur-xl border-r border-slate-800 flex flex-col z-20 shadow-2xl overflow-y-auto select-none"
      aria-label="Data Ingestion and Pipeline Panel"
    >
      <div className="p-4 border-b border-slate-800 flex items-center justify-between sticky top-0 bg-slate-900/95 z-10 backdrop-blur-md">
        <div className="flex items-center gap-2">
          <div className="p-1.5 rounded-md bg-cyan-500/10 text-cyan-400 border border-cyan-500/20">
            <Cpu className="w-4 h-4" />
          </div>
          <div>
            <h2 className="text-sm font-semibold text-slate-100">Data Ingestion Engine</h2>
            <p className="text-[11px] text-slate-400">Pure Client-Side Height Estimation</p>
          </div>
        </div>
        <button
          type="button"
          onClick={onClose}
          className="p-1.5 rounded-md text-slate-400 hover:text-slate-200 hover:bg-slate-800 transition-colors"
        >
          <X className="w-4 h-4" />
        </button>
      </div>

      <div className="p-4 space-y-5 flex-1">
        {/* Pure Client-Side Status Badge */}
        <div className="p-3 rounded-xl bg-slate-950/80 border border-slate-800 shadow-sm">
          <div className="flex items-center justify-between">
            <div className="flex items-center gap-2">
              <span className="w-2 h-2 rounded-full bg-emerald-400 animate-pulse" />
              <div>
                <span className="text-xs font-semibold text-slate-200 block">
                  Client-Side In-Memory Engine
                </span>
                <span className="text-[10px] text-slate-400 font-mono">
                  100% In-Browser Simulation &bull; Zero Network Latency
                </span>
              </div>
            </div>
            <span className="px-2 py-0.5 rounded text-[10px] font-mono font-bold bg-emerald-500/20 text-emerald-300 border border-emerald-500/40">
              Pure Client
            </span>
          </div>
        </div>

        {/* Strict Validation Dropzone */}
        <div>
          <label className="text-xs font-medium text-slate-300 mb-1.5 flex items-center justify-between">
            <span>Input Raster Source</span>
            <span className="text-[10px] text-slate-500 font-mono">GeoTIFF / Aerial Image</span>
          </label>
          
          <div
            onDragOver={handleDragOver}
            onDragLeave={handleDragLeave}
            onDrop={handleDrop}
            onClick={() => fileInputRef.current?.click()}
            className={`border-2 border-dashed rounded-xl p-6 text-center cursor-pointer transition-all duration-200 ${
              isDragActive
                ? 'border-cyan-400 bg-cyan-500/10 scale-[0.99]'
                : validationError
                ? 'border-rose-500/60 bg-rose-500/5 hover:border-rose-500'
                : 'border-slate-800 bg-slate-950/50 hover:border-slate-700 hover:bg-slate-950'
            }`}
          >
            <input
              ref={fileInputRef}
              type="file"
              accept=".tif,.tiff,.png,.jpg,.jpeg"
              onChange={handleFileInputChange}
              className="hidden"
            />
            <div className="w-10 h-10 mx-auto mb-3 rounded-full bg-slate-900 flex items-center justify-center text-slate-400 border border-slate-800">
              <UploadCloud className="w-5 h-5 text-cyan-400" />
            </div>
            <p className="text-xs font-medium text-slate-200">
              Drag and drop your raster image here
            </p>
            <p className="text-[11px] text-slate-400 mt-1">
              or <span className="text-cyan-400 underline underline-offset-2">browse local files</span>
            </p>
            <div className="mt-3 flex items-center justify-center gap-1.5 text-[10px] text-slate-400 font-mono">
              <span className="px-1.5 py-0.5 rounded bg-slate-900 border border-slate-800">.TIF</span>
              <span className="px-1.5 py-0.5 rounded bg-slate-900 border border-slate-800">.TIFF</span>
              <span className="px-1.5 py-0.5 rounded bg-slate-900 border border-slate-800">.PNG</span>
              <span className="px-1.5 py-0.5 rounded bg-slate-900 border border-slate-800">.JPG</span>
            </div>
          </div>

          {/* Validation Status Feedback */}
          {validationError && (
            <div className="mt-2.5 p-2.5 rounded-lg bg-rose-500/10 border border-rose-500/30 flex items-start gap-2 text-rose-400 text-xs">
              <AlertTriangle className="w-4 h-4 shrink-0 mt-0.5" />
              <div className="flex-1">
                <span className="font-semibold block">Validation Failed</span>
                <span className="text-[11px] text-rose-300/90">{validationError}</span>
              </div>
            </div>
          )}

          {validationState && validationState.isValid && (
            <div className="mt-2.5 p-2.5 rounded-lg bg-emerald-500/10 border border-emerald-500/30 flex items-start gap-2 text-emerald-400 text-xs">
              <FileCheck className="w-4 h-4 shrink-0 mt-0.5" />
              <div className="flex-1 min-w-0">
                <div className="flex items-center justify-between">
                  <span className="font-semibold truncate">{validationState.name}</span>
                  <span className="text-[10px] font-mono text-emerald-300/80">
                    {formatFileSize(validationState.size)}
                  </span>
                </div>
                <div className="text-[10px] text-emerald-300/80 flex items-center gap-1.5 mt-0.5">
                  <span className="font-mono uppercase">{validationState.extension}</span>
                  <span>&bull;</span>
                  <span>Georeferenced Metric DSM Target</span>
                </div>
              </div>
            </div>
          )}
        </div>

        {/* Pipeline Execution Progression */}
        <div className="p-3 rounded-xl bg-slate-950/60 border border-slate-800/80">
          <div className="flex items-center justify-between mb-2">
            <label className="text-xs font-medium text-slate-300 flex items-center gap-1.5">
              <Activity className="w-3.5 h-3.5 text-cyan-400" />
              Inference &amp; Tiling Pipeline
            </label>
            <span className="text-[10px] font-mono text-cyan-400 capitalize">
              {pipelineStage.replace('_', ' ')}
            </span>
          </div>

          <div className="space-y-2">
            {PIPELINE_STEPS.map((step) => {
              const status = getStepStatus(step.key);
              return (
                <div 
                  key={step.key}
                  className={`flex items-center justify-between p-2 rounded-lg text-xs transition-colors ${
                    status === 'active'
                      ? 'bg-cyan-950/40 border border-cyan-500/30 text-cyan-300'
                      : status === 'complete'
                      ? 'bg-slate-900/60 text-slate-300'
                      : 'text-slate-400 opacity-60'
                  }`}
                >
                  <div className="flex items-center gap-2">
                    {status === 'complete' ? (
                      <CheckCircle2 className="w-3.5 h-3.5 text-emerald-400 shrink-0" />
                    ) : status === 'active' ? (
                      <span className="w-3.5 h-3.5 rounded-full border-2 border-cyan-400 border-t-transparent animate-spin shrink-0"></span>
                    ) : (
                      <span className="w-3.5 h-3.5 rounded-full border border-slate-700 shrink-0"></span>
                    )}
                    <div>
                      <span className="font-medium block leading-tight">{step.label}</span>
                      <span className="text-[10px] text-slate-400 leading-none">{step.desc}</span>
                    </div>
                  </div>
                  <span className="text-[10px] font-mono capitalize">
                    {status}
                  </span>
                </div>
              );
            })}
          </div>

          {/* Active Job Metrics Tag */}
          {activeJobResponse?.metrics && (
            <div className="mt-3 pt-2.5 border-t border-slate-800 flex items-center justify-between text-[10px] font-mono text-slate-400">
              <span>RMSE: <strong className="text-emerald-400">{activeJobResponse.metrics.rmse}m</strong></span>
              <span>MAE: <strong className="text-emerald-400">{activeJobResponse.metrics.mae}m</strong></span>
              <span>r: <strong className="text-cyan-400">{activeJobResponse.metrics.correlation}</strong></span>
              <span>F1: <strong className="text-indigo-400">{activeJobResponse.metrics.f1Score}</strong></span>
            </div>
          )}
        </div>

        {/* Preset Benchmark Datasets */}
        <div>
          <label className="text-xs font-medium text-slate-300 mb-2 flex items-center justify-between">
            <span>Pre-Computed Benchmark Datasets</span>
            <span className="text-[10px] text-slate-500 font-mono">1-Click Test</span>
          </label>
          <div className="space-y-2">
            {PRESET_DATASETS.map((preset) => {
              const isSelected = currentMetadata.id === preset.metadata.id;
              return (
                <button
                  key={preset.metadata.id}
                  type="button"
                  onClick={() => onSelectPreset(preset.metadata.id)}
                  className={`w-full text-left p-2.5 rounded-xl border transition-all duration-150 ${
                    isSelected
                      ? 'bg-cyan-950/30 border-cyan-500/50 shadow-sm shadow-cyan-500/10'
                      : 'bg-slate-950/40 border-slate-800 hover:border-slate-700 hover:bg-slate-950/80'
                  }`}
                >
                  <div className="flex items-center justify-between">
                    <span className="text-xs font-semibold text-slate-200">
                      {preset.metadata.title}
                    </span>
                    <span className="text-[10px] px-1.5 py-0.5 rounded font-mono uppercase bg-slate-900 border border-slate-700 text-slate-400">
                      {preset.sourceType}
                    </span>
                  </div>
                  <div className="mt-1 flex items-center gap-3 text-[10px] text-slate-400 font-mono">
                    <span className="flex items-center gap-1">
                      <Globe className="w-3 h-3 text-cyan-400" />
                      {preset.metadata.crs}
                    </span>
                    <span>&bull;</span>
                    <span>{preset.metadata.areaCoverage}</span>
                  </div>
                </button>
              );
            })}
          </div>
        </div>

        {/* Dynamic Shading Selector */}
        <div>
          <label className="text-xs font-medium text-slate-300 mb-2 flex items-center justify-between">
            <span>Terrain Shading Mode</span>
            <span className="text-[10px] text-slate-500 font-mono capitalize">{shadingMode}</span>
          </label>
          <div className="grid grid-cols-2 gap-2">
            {/* 1. Photorealistic Optical */}
            <button
              type="button"
              onClick={() => onShadingModeChange('rgb')}
              className={`p-2 rounded-lg border text-left text-xs transition-all ${
                shadingMode === 'rgb'
                  ? 'bg-cyan-500/20 border-cyan-500 text-cyan-300 font-semibold'
                  : 'bg-slate-950 border-slate-800 text-slate-400 hover:border-slate-700 hover:text-slate-200'
              }`}
            >
              <div className="flex items-center justify-between mb-1">
                <span className="font-semibold">True Optical</span>
                <span className="w-2.5 h-2.5 rounded-full bg-gradient-to-tr from-emerald-500 to-amber-500"></span>
              </div>
              <p className="text-[10px] text-slate-400">Satellite / Aerial Ortho</p>
            </button>

            {/* 2. Hypsometric Elevation Heatmap */}
            <button
              type="button"
              onClick={() => onShadingModeChange('hypsometric')}
              className={`p-2 rounded-lg border text-left text-xs transition-all ${
                shadingMode === 'hypsometric'
                  ? 'bg-cyan-500/20 border-cyan-500 text-cyan-300 font-semibold'
                  : 'bg-slate-950 border-slate-800 text-slate-400 hover:border-slate-700 hover:text-slate-200'
              }`}
            >
              <div className="flex items-center justify-between mb-1">
                <span className="font-semibold">Elevation Heatmap</span>
                <span className="w-2.5 h-2.5 rounded-full bg-gradient-to-r from-blue-500 via-emerald-500 to-red-500"></span>
              </div>
              <p className="text-[10px] text-slate-400">Turbo / Jet Color Ramp</p>
            </button>

            {/* 3. Slope Gradient */}
            <button
              type="button"
              onClick={() => onShadingModeChange('slope')}
              className={`p-2 rounded-lg border text-left text-xs transition-all ${
                shadingMode === 'slope'
                  ? 'bg-cyan-500/20 border-cyan-500 text-cyan-300 font-semibold'
                  : 'bg-slate-950 border-slate-800 text-slate-400 hover:border-slate-700 hover:text-slate-200'
              }`}
            >
              <div className="flex items-center justify-between mb-1">
                <span className="font-semibold">Slope Gradient</span>
                <span className="w-2.5 h-2.5 rounded-full bg-gradient-to-r from-emerald-500 via-yellow-500 to-rose-600"></span>
              </div>
              <p className="text-[10px] text-slate-400">Hazard / Steepness (0-60°)</p>
            </button>

            {/* 4. GIS Wireframe */}
            <button
              type="button"
              onClick={() => onShadingModeChange('wireframe')}
              className={`p-2 rounded-lg border text-left text-xs transition-all ${
                shadingMode === 'wireframe'
                  ? 'bg-cyan-500/20 border-cyan-500 text-cyan-300 font-semibold'
                  : 'bg-slate-950 border-slate-800 text-slate-400 hover:border-slate-700 hover:text-slate-200'
              }`}
            >
              <div className="flex items-center justify-between mb-1">
                <span className="font-semibold">GIS Wireframe</span>
                <span className="w-2.5 h-2.5 rounded-full border border-emerald-400"></span>
              </div>
              <p className="text-[10px] text-slate-400">LoD Vector Mesh</p>
            </button>
          </div>
        </div>

        {/* Active Elevation Bounds */}
        <div className="p-3 rounded-xl bg-slate-950/40 border border-slate-800/80 text-[11px] space-y-1.5">
          <div className="font-semibold text-slate-300 flex items-center gap-1 mb-1">
            <Eye className="w-3 h-3 text-cyan-400" />
            Active Elevation Bounds
          </div>
          <div className="grid grid-cols-2 gap-2 text-slate-400 font-mono text-[10px]">
            <div>Datum: <span className="text-slate-200">{currentMetadata.verticalDatum}</span></div>
            <div>GSD: <span className="text-slate-200">{currentMetadata.gsd}</span></div>
            <div>Min Elev: <span className="text-slate-200">{currentMetadata.minElevation.toFixed(1)} m</span></div>
            <div>Max Elev: <span className="text-slate-200">{currentMetadata.maxElevation.toFixed(1)} m</span></div>
          </div>
        </div>
      </div>
    </div>
  );
};
