'use client';

import React, { useState, useEffect } from 'react';
import { Header } from '@/components/Header';
import { UnityViewer } from '@/components/UnityViewer';
import { ControlPanel } from '@/components/ControlPanel';
import { ModelStats } from '@/components/ModelStats';
import { MessageConsole } from '@/components/MessageConsole';
import { InstructionsModal } from '@/components/InstructionsModal';
import { useUnityBridge } from '@/hooks/useUnityBridge';

export default function Home() {
  const [showInstructions, setShowInstructions] = useState(false);

  const {
    unityInstance,
    setUnityInstance,
    isEngineReady,
    setIsEngineReady,
    engineProgress,
    setEngineProgress,

    currentModelUrl,
    isModelLoading,
    modelProgress,
    modelStage,
    modelStats,
    errorMessage,

    autoRotate,
    rotationSpeed,
    wireframe,
    backgroundColor,

    loadGlb,
    setAutoRotate,
    setRotationSpeed,
    resetCamera,
    setBackgroundColor,
    setWireframe,
    setFullscreen,

    logs,
    clearLogs
  } = useUnityBridge();

  // Automatically load the default duck.glb model when Unity engine becomes ready
  useEffect(() => {
    if (isEngineReady && !currentModelUrl) {
      const defaultUrl = '/models/duck.glb';
      loadGlb(defaultUrl);
    }
  }, [isEngineReady, currentModelUrl, loadGlb]);

  return (
    <div className="min-h-screen bg-slate-950 text-slate-100 flex flex-col font-sans selection:bg-indigo-500/30 selection:text-indigo-200">
      {/* Top Navigation */}
      <Header
        isEngineReady={isEngineReady}
        isModelLoading={isModelLoading}
        currentModelName={modelStats?.name}
        onOpenInstructions={() => setShowInstructions(true)}
      />

      {/* Main Studio Workspace */}
      <main className="flex-1 max-w-7xl w-full mx-auto p-4 sm:p-6 lg:p-8 space-y-6">
        {/* Quick Engine Status Banner */}
        <div className="flex flex-wrap items-center justify-between gap-3 p-3.5 rounded-2xl bg-gradient-to-r from-indigo-950/40 via-slate-900/60 to-cyan-950/40 border border-slate-800/80 text-xs">
          <div className="flex items-center gap-2">
            <span className="flex h-2 w-2 relative">
              <span className="animate-ping absolute inline-flex h-full w-full rounded-full bg-cyan-400 opacity-75"></span>
              <span className="relative inline-flex rounded-full h-2 w-2 bg-cyan-500"></span>
            </span>
            <span className="text-slate-300">
              WebGL 3D Context: <strong className="text-white">Unity 6 Engine</strong> with runtime <strong className="text-indigo-300">glTFast</strong> GLB streaming
            </span>
          </div>

          <div className="flex items-center gap-3 font-mono text-[11px] text-slate-400">
            <span>Inter-Process: <strong className="text-emerald-400">Emscripten .jslib</strong></span>
            <span>•</span>
            <span>Target: <strong className="text-cyan-400">HTML5 Canvas</strong></span>
          </div>
        </div>

        {/* 2-Column Responsive Layout */}
        <div className="grid grid-cols-1 lg:grid-cols-12 gap-6 items-start">
          {/* Left Column: 3D Viewport & Bridge Log */}
          <div className="lg:col-span-8 space-y-6">
            <UnityViewer
              unityInstance={unityInstance}
              setUnityInstance={setUnityInstance}
              isEngineReady={isEngineReady}
              setIsEngineReady={setIsEngineReady}
              engineProgress={engineProgress}
              setEngineProgress={setEngineProgress}
              isModelLoading={isModelLoading}
              modelProgress={modelProgress}
              modelStage={modelStage}
              errorMessage={errorMessage}
              autoRotate={autoRotate}
              onResetCamera={resetCamera}
              onSetFullscreen={setFullscreen}
              onSetAutoRotate={setAutoRotate}
            />

            {/* Live Message Console */}
            <MessageConsole logs={logs} onClear={clearLogs} />
          </div>

          {/* Right Column: Controls & Stats */}
          <div className="lg:col-span-4 space-y-6">
            {/* Model & Engine Controls */}
            <ControlPanel
              isEngineReady={isEngineReady}
              isModelLoading={isModelLoading}
              currentModelUrl={currentModelUrl}
              autoRotate={autoRotate}
              rotationSpeed={rotationSpeed}
              wireframe={wireframe}
              backgroundColor={backgroundColor}
              onLoadGlb={loadGlb}
              onSetAutoRotate={setAutoRotate}
              onSetRotationSpeed={setRotationSpeed}
              onResetCamera={resetCamera}
              onSetWireframe={setWireframe}
              onSetBackgroundColor={setBackgroundColor}
              onSetFullscreen={setFullscreen}
            />

            {/* Model Geometry Telemetry */}
            <ModelStats
              stats={modelStats}
              isLoading={isModelLoading}
              stage={modelStage}
              progress={modelProgress}
            />
          </div>
        </div>
      </main>

      {/* Instructions Modal */}
      <InstructionsModal
        isOpen={showInstructions}
        onClose={() => setShowInstructions(false)}
      />

      {/* Footer */}
      <footer className="border-t border-slate-800/80 bg-slate-950/80 py-4 px-6 text-center text-xs text-slate-500">
        Unity WebGL + Next.js Integration Architecture • Built for high-performance `.glb` 3D rendering
      </footer>
    </div>
  );
}
