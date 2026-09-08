'use client';

import React, { useState, useRef } from 'react';

interface ControlPanelProps {
  isEngineReady: boolean;
  isModelLoading: boolean;
  currentModelUrl: string;
  autoRotate: boolean;
  rotationSpeed: number;
  wireframe: boolean;
  backgroundColor: string;
  onLoadGlb: (url: string) => void;
  onSetAutoRotate: (enabled: boolean) => void;
  onSetRotationSpeed: (speed: number) => void;
  onResetCamera: () => void;
  onSetWireframe: (enabled: boolean) => void;
  onSetBackgroundColor: (colorHex: string) => void;
  onSetFullscreen: () => void;
}

const PRESET_MODELS = [
  {
    id: 'duck',
    name: 'Khronos Duck',
    url: '/models/duck.glb',
    description: 'Official Khronos glTF 2.0 PBR sample duck'
  },
  {
    id: 'cube',
    name: 'Unit PBR Cube',
    url: '/models/sample-cube.glb',
    description: 'Minimal valid binary glTF box'
  },
  {
    id: 'helmet',
    name: 'Damaged Helmet',
    url: 'https://raw.githubusercontent.com/KhronosGroup/glTF-Sample-Models/master/2.0/DamagedHelmet/glTF-Binary/DamagedHelmet.glb',
    description: 'High-detail PBR metallic rough helmet from Khronos'
  },
  {
    id: 'avocado',
    name: 'Avocado',
    url: 'https://raw.githubusercontent.com/KhronosGroup/glTF-Sample-Models/master/2.0/Avocado/glTF-Binary/Avocado.glb',
    description: 'Organic textures & normal maps sample'
  }
];

const COLOR_PRESETS = [
  { name: 'Dark Slate', hex: '#0f172a' },
  { name: 'Cyber Void', hex: '#030712' },
  { name: 'Deep Space', hex: '#0f0f23' },
  { name: 'Charcoal', hex: '#18181b' },
  { name: 'Studio Grey', hex: '#27272a' }
];

export const ControlPanel: React.FC<ControlPanelProps> = ({
  isEngineReady,
  isModelLoading,
  currentModelUrl,
  autoRotate,
  rotationSpeed,
  wireframe,
  backgroundColor,
  onLoadGlb,
  onSetAutoRotate,
  onSetRotationSpeed,
  onResetCamera,
  onSetWireframe,
  onSetBackgroundColor,
  onSetFullscreen
}) => {
  const [activeTab, setActiveTab] = useState<'presets' | 'url' | 'upload'>('presets');
  const [customUrlInput, setCustomUrlInput] = useState('');
  const [dragActive, setDragActive] = useState(false);
  const fileInputRef = useRef<HTMLInputElement>(null);

  const handleCustomUrlSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (customUrlInput.trim()) {
      onLoadGlb(customUrlInput.trim());
    }
  };

  const handleFile = (file: File) => {
    if (!file.name.toLowerCase().endsWith('.glb') && !file.name.toLowerCase().endsWith('.gltf')) {
      alert('Please upload a .glb or .gltf file.');
      return;
    }
    const blobUrl = URL.createObjectURL(file);
    onLoadGlb(blobUrl);
  };

  const handleDrop = (e: React.DragEvent) => {
    e.preventDefault();
    e.stopPropagation();
    setDragActive(false);
    if (e.dataTransfer.files && e.dataTransfer.files[0]) {
      handleFile(e.dataTransfer.files[0]);
    }
  };

  return (
    <div className="rounded-2xl bg-slate-900/80 border border-slate-800/80 p-5 shadow-xl backdrop-blur-sm space-y-5">
      {/* Tab Navigation */}
      <div>
        <div className="flex rounded-xl bg-slate-950 p-1 border border-slate-800/80">
          <button
            onClick={() => setActiveTab('presets')}
            className={`flex-1 py-1.5 px-3 rounded-lg text-xs font-medium transition-all ${
              activeTab === 'presets'
                ? 'bg-indigo-600 text-white shadow-md'
                : 'text-slate-400 hover:text-white'
            }`}
          >
            Presets
          </button>
          <button
            onClick={() => setActiveTab('url')}
            className={`flex-1 py-1.5 px-3 rounded-lg text-xs font-medium transition-all ${
              activeTab === 'url'
                ? 'bg-indigo-600 text-white shadow-md'
                : 'text-slate-400 hover:text-white'
            }`}
          >
            Custom URL
          </button>
          <button
            onClick={() => setActiveTab('upload')}
            className={`flex-1 py-1.5 px-3 rounded-lg text-xs font-medium transition-all ${
              activeTab === 'upload'
                ? 'bg-indigo-600 text-white shadow-md'
                : 'text-slate-400 hover:text-white'
            }`}
          >
            Local File
          </button>
        </div>
      </div>

      {/* Tab Content: Presets */}
      {activeTab === 'presets' && (
        <div className="space-y-2">
          <label className="text-[11px] font-semibold uppercase tracking-wider text-slate-400">
            Select 3D Model
          </label>
          <div className="grid grid-cols-1 gap-2">
            {PRESET_MODELS.map((model) => {
              const isActive = currentModelUrl.includes(model.url) || currentModelUrl.endsWith(model.url);
              return (
                <button
                  key={model.id}
                  onClick={() => onLoadGlb(model.url)}
                  disabled={isModelLoading}
                  className={`flex items-center justify-between p-2.5 rounded-xl border text-left transition-all ${
                    isActive
                      ? 'bg-indigo-950/60 border-indigo-500/60 ring-1 ring-indigo-500/40'
                      : 'bg-slate-950/50 border-slate-800/80 hover:bg-slate-800/50 hover:border-slate-700'
                  }`}
                >
                  <div>
                    <div className="flex items-center gap-1.5">
                      <span className="text-xs font-semibold text-white">{model.name}</span>
                      {isActive && (
                        <span className="w-2 h-2 rounded-full bg-indigo-400 animate-pulse" />
                      )}
                    </div>
                    <span className="text-[10px] text-slate-400 block mt-0.5">{model.description}</span>
                  </div>
                  <span className="text-xs text-indigo-400 font-mono">Load ➔</span>
                </button>
              );
            })}
          </div>
        </div>
      )}

      {/* Tab Content: Custom URL */}
      {activeTab === 'url' && (
        <form onSubmit={handleCustomUrlSubmit} className="space-y-3">
          <label className="text-[11px] font-semibold uppercase tracking-wider text-slate-400">
            Remote .GLB File URL
          </label>
          <div className="space-y-2">
            <input
              type="url"
              value={customUrlInput}
              onChange={(e) => setCustomUrlInput(e.target.value)}
              placeholder="https://example.com/assets/model.glb"
              className="w-full px-3 py-2 bg-slate-950 border border-slate-800 rounded-xl text-xs text-white placeholder-slate-500 focus:outline-none focus:border-indigo-500 focus:ring-1 focus:ring-indigo-500"
            />
            <button
              type="submit"
              disabled={isModelLoading || !customUrlInput.trim()}
              className="w-full py-2 bg-indigo-600 hover:bg-indigo-500 disabled:opacity-50 text-white rounded-xl text-xs font-medium transition-colors shadow-lg shadow-indigo-600/20"
            >
              {isModelLoading ? 'Streaming to Unity...' : 'Load GLB into Unity'}
            </button>
          </div>
        </form>
      )}

      {/* Tab Content: Local File Upload */}
      {activeTab === 'upload' && (
        <div className="space-y-2">
          <label className="text-[11px] font-semibold uppercase tracking-wider text-slate-400">
            Drag & Drop .GLB File
          </label>
          <div
            onDragEnter={(e) => { e.preventDefault(); setDragActive(true); }}
            onDragLeave={(e) => { e.preventDefault(); setDragActive(false); }}
            onDragOver={(e) => { e.preventDefault(); }}
            onDrop={handleDrop}
            onClick={() => fileInputRef.current?.click()}
            className={`p-6 border-2 border-dashed rounded-xl text-center cursor-pointer transition-all ${
              dragActive
                ? 'border-cyan-400 bg-cyan-950/20'
                : 'border-slate-800 hover:border-slate-700 bg-slate-950/40 hover:bg-slate-950/60'
            }`}
          >
            <input
              ref={fileInputRef}
              type="file"
              accept=".glb,.gltf"
              className="hidden"
              onChange={(e) => {
                if (e.target.files && e.target.files[0]) {
                  handleFile(e.target.files[0]);
                }
              }}
            />
            <svg className="w-8 h-8 text-indigo-400 mx-auto mb-2 opacity-80" viewBox="0 0 24 24" fill="none" stroke="currentColor">
              <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M7 16a4 4 0 01-.88-7.903A5 5 0 1115.9 6L16 6a5 5 0 011 9.9M15 13l-3-3m0 0l-3 3m3-3v12" />
            </svg>
            <p className="text-xs font-medium text-slate-200">
              Click to select or drag .glb file here
            </p>
            <p className="text-[10px] text-slate-500 mt-1">
              File is sent to Unity engine via in-memory Blob URL
            </p>
          </div>
        </div>
      )}

      <hr className="border-slate-800/80" />

      {/* Engine Controls */}
      <div className="space-y-4">
        <h3 className="text-xs font-semibold uppercase tracking-wider text-slate-400">
          Unity Engine Controls
        </h3>

        {/* Auto-Rotate Switch */}
        <div className="flex items-center justify-between">
          <span className="text-xs text-slate-300 font-medium">Turntable Rotation</span>
          <button
            onClick={() => onSetAutoRotate(!autoRotate)}
            className={`relative inline-flex h-5 w-10 items-center rounded-full transition-colors ${
              autoRotate ? 'bg-indigo-600' : 'bg-slate-700'
            }`}
          >
            <span
              className={`inline-block h-3.5 w-3.5 transform rounded-full bg-white transition-transform ${
                autoRotate ? 'translate-x-5' : 'translate-x-1'
              }`}
            />
          </button>
        </div>

        {/* Speed Slider */}
        {autoRotate && (
          <div className="space-y-1.5">
            <div className="flex justify-between text-xs">
              <span className="text-slate-400">Rotation Speed</span>
              <span className="font-mono text-indigo-400">{rotationSpeed.toFixed(1)}x</span>
            </div>
            <input
              type="range"
              min="0.2"
              max="4.0"
              step="0.1"
              value={rotationSpeed}
              onChange={(e) => onSetRotationSpeed(parseFloat(e.target.value))}
              className="w-full accent-indigo-500 bg-slate-800 h-1.5 rounded-lg appearance-none cursor-pointer"
            />
          </div>
        )}

        {/* Wireframe Switch */}
        <div className="flex items-center justify-between">
          <span className="text-xs text-slate-300 font-medium">Wireframe Overlay</span>
          <button
            onClick={() => onSetWireframe(!wireframe)}
            className={`relative inline-flex h-5 w-10 items-center rounded-full transition-colors ${
              wireframe ? 'bg-indigo-600' : 'bg-slate-700'
            }`}
          >
            <span
              className={`inline-block h-3.5 w-3.5 transform rounded-full bg-white transition-transform ${
                wireframe ? 'translate-x-5' : 'translate-x-1'
              }`}
            />
          </button>
        </div>

        {/* Background Color Palette */}
        <div className="space-y-2">
          <span className="text-xs text-slate-400">Clear Color</span>
          <div className="flex items-center gap-2">
            {COLOR_PRESETS.map((p) => (
              <button
                key={p.hex}
                onClick={() => onSetBackgroundColor(p.hex)}
                style={{ backgroundColor: p.hex }}
                className={`w-6 h-6 rounded-full border transition-transform ${
                  backgroundColor.toLowerCase() === p.hex.toLowerCase()
                    ? 'scale-125 border-white ring-2 ring-indigo-500'
                    : 'border-slate-700 hover:scale-110'
                }`}
                title={p.name}
              />
            ))}
            <input
              type="color"
              value={backgroundColor}
              onChange={(e) => onSetBackgroundColor(e.target.value)}
              className="w-6 h-6 rounded-full bg-transparent cursor-pointer border-0 p-0"
              title="Custom Hex Color"
            />
          </div>
        </div>

        {/* Action Buttons */}
        <div className="grid grid-cols-2 gap-2 pt-2">
          <button
            onClick={onResetCamera}
            className="flex items-center justify-center gap-1.5 py-2 px-3 bg-slate-800 hover:bg-slate-700 text-white rounded-xl text-xs font-medium transition-colors border border-slate-700/80"
          >
            <svg className="w-3.5 h-3.5 text-cyan-400" viewBox="0 0 24 24" fill="none" stroke="currentColor">
              <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M15 10l4.553-2.276A1 1 0 0121 8.618v6.764a1 1 0 01-1.447.894L15 14M5 18h8a2 2 0 002-2V8a2 2 0 00-2-2H5a2 2 0 00-2 2v8a2 2 0 002 2z" />
            </svg>
            <span>Frame Model</span>
          </button>

          <button
            onClick={onSetFullscreen}
            className="flex items-center justify-center gap-1.5 py-2 px-3 bg-slate-800 hover:bg-slate-700 text-white rounded-xl text-xs font-medium transition-colors border border-slate-700/80"
          >
            <svg className="w-3.5 h-3.5 text-indigo-400" viewBox="0 0 24 24" fill="none" stroke="currentColor">
              <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M4 8V4m0 0h4M4 4l5 5m11-1V4m0 0h-4m4 0l-5 5M4 16v4m0 0h4m-4 0l5-5m11 5l-5-5m5 5v-4m0 4h-4" />
            </svg>
            <span>Fullscreen</span>
          </button>
        </div>
      </div>
    </div>
  );
};
