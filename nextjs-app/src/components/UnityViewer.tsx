'use client';

import React, { useEffect, useRef, useState, useCallback } from 'react';
import type { UnityInstance } from '@/types/unity';

interface UnityViewerProps {
  unityInstance: UnityInstance | null;
  setUnityInstance: (instance: UnityInstance | null) => void;
  isEngineReady: boolean;
  setIsEngineReady: (ready: boolean) => void;
  engineProgress: number;
  setEngineProgress: (progress: number) => void;
  isModelLoading: boolean;
  modelProgress: number;
  modelStage: string;
  errorMessage: string | null;
  autoRotate: boolean;
  onResetCamera: () => void;
  onSetFullscreen: () => void;
  onSetAutoRotate: (enabled: boolean) => void;
}

export const UnityViewer: React.FC<UnityViewerProps> = ({
  unityInstance,
  setUnityInstance,
  isEngineReady,
  setIsEngineReady,
  engineProgress,
  setEngineProgress,
  isModelLoading,
  modelProgress,
  modelStage,
  errorMessage,
  autoRotate,
  onResetCamera,
  onSetFullscreen,
  onSetAutoRotate
}) => {
  const containerRef = useRef<HTMLDivElement>(null);
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const [loadError, setLoadError] = useState<string | null>(null);
  const [isBuildingMock, setIsBuildingMock] = useState(false);

  // Initialize Unity WebGL Loader
  useEffect(() => {
    if (typeof window === 'undefined' || unityInstance) return;

    let isMounted = true;
    const loaderUrl = '/unity-build/Build/unity-build.loader.js';

    // Verify if build assets exist by attempting to load loader script
    const script = document.createElement('script');
    script.src = loaderUrl;
    script.async = true;

    script.onload = () => {
      if (!isMounted || !canvasRef.current || !window.createUnityInstance) return;

      const config = {
        dataUrl: '/unity-build/Build/unity-build.data',
        frameworkUrl: '/unity-build/Build/unity-build.framework.js',
        codeUrl: '/unity-build/Build/unity-build.wasm',
        streamingAssetsUrl: '/unity-build/StreamingAssets',
        companyName: 'UnityNext',
        productName: 'UnityNextViewer',
        productVersion: '1.0'
      };

      window.createUnityInstance(canvasRef.current, config, (progress: number) => {
        if (isMounted) {
          setEngineProgress(progress);
        }
      })
      .then((instance) => {
        if (isMounted) {
          setUnityInstance(instance);
          setIsEngineReady(true);
        }
      })
      .catch((err) => {
        console.error('[UnityViewer] createUnityInstance failed:', err);
        if (isMounted) {
          setLoadError(err?.message || 'Failed to initialize Unity WebGL player instance.');
        }
      });
    };

    script.onerror = () => {
      console.warn(`[UnityViewer] Unity build files not yet loaded at ${loaderUrl}.`);
      if (isMounted) {
        setIsBuildingMock(true);
      }
    };

    document.body.appendChild(script);

    return () => {
      isMounted = false;
      if (script.parentNode) {
        script.parentNode.removeChild(script);
      }
    };
  }, [unityInstance, setUnityInstance, setIsEngineReady, setEngineProgress]);

  // Fallback simulator for development/verification if Unity build is in progress
  const startSimulation = useCallback(() => {
    setIsBuildingMock(false);
    setIsEngineReady(true);
    setEngineProgress(1.0);

    const mockInstance: UnityInstance = {
      SendMessage: (obj: string, method: string, param?: string | number) => {
        console.log(`[Simulated Unity] Received SendMessage: ${obj}.${method}(${param})`);

        if (method === 'LoadGlbFromUrl' && typeof window !== 'undefined') {
          const url = String(param);
          const fileName = url.split('/').pop() || 'Model.glb';
          
          window.dispatchEvent(new CustomEvent('UnityModelProgress', {
            detail: { progress: 0.2, stage: 'Downloading GLB' }
          }));

          setTimeout(() => {
            window.dispatchEvent(new CustomEvent('UnityModelProgress', {
              detail: { progress: 0.7, stage: 'Parsing Mesh' }
            }));
          }, 300);

          setTimeout(() => {
            window.dispatchEvent(new CustomEvent('UnityModelLoaded', {
              detail: {
                name: fileName,
                vertexCount: fileName.includes('cube') ? 24 : 12480,
                triangleCount: fileName.includes('cube') ? 12 : 8200,
                meshCount: 1,
                loadTimeMs: 420,
                boundsSizeX: 1.5,
                boundsSizeY: 1.8,
                boundsSizeZ: 1.5
              }
            }));
          }, 600);
        }
      },
      SetFullscreen: () => {
        if (containerRef.current?.requestFullscreen) {
          containerRef.current.requestFullscreen();
        }
      },
      Quit: async () => {}
    };

    setUnityInstance(mockInstance);

    // Render visual feedback on canvas
    if (canvasRef.current) {
      const canvas = canvasRef.current;
      const ctx = canvas.getContext('2d');
      if (ctx) {
        let angle = 0;
        let animId: number;
        const render = () => {
          if (!canvas) return;
          ctx.fillStyle = '#0f172a';
          ctx.fillRect(0, 0, canvas.width, canvas.height);

          // Draw grid
          ctx.strokeStyle = '#1e293b';
          ctx.lineWidth = 1;
          for (let i = 0; i < canvas.width; i += 40) {
            ctx.beginPath();
            ctx.moveTo(i, 0);
            ctx.lineTo(i, canvas.height);
            ctx.stroke();
          }
          for (let j = 0; j < canvas.height; j += 40) {
            ctx.beginPath();
            ctx.moveTo(0, j);
            ctx.lineTo(canvas.width, j);
            ctx.stroke();
          }

          // Draw rotating wireframe cube
          ctx.save();
          ctx.translate(canvas.width / 2, canvas.height / 2);
          if (autoRotate) angle += 0.02;
          ctx.rotate(angle);

          ctx.strokeStyle = '#6366f1';
          ctx.lineWidth = 2.5;
          ctx.strokeRect(-60, -60, 120, 120);

          ctx.strokeStyle = '#38bdf8';
          ctx.strokeRect(-40, -40, 80, 80);

          ctx.fillStyle = '#f8fafc';
          ctx.font = '12px monospace';
          ctx.textAlign = 'center';
          ctx.fillText('Unity WebGL Bridge Active', 0, 95);

          ctx.restore();
          animId = requestAnimationFrame(render);
        };
        render();
        return () => cancelAnimationFrame(animId);
      }
    }
  }, [autoRotate, setIsEngineReady, setEngineProgress, setUnityInstance]);

  return (
    <div
      ref={containerRef}
      className="relative w-full h-[540px] lg:h-[620px] rounded-2xl overflow-hidden bg-slate-950 border border-slate-800 shadow-2xl flex items-center justify-center select-none"
    >
      {/* Unity Canvas */}
      <canvas
        id="unity-canvas"
        ref={canvasRef}
        width={960}
        height={600}
        className="w-full h-full object-contain cursor-grab active:cursor-grabbing outline-none block"
        tabIndex={0}
      />

      {/* Floating Canvas Overlay Controls */}
      <div className="absolute top-4 right-4 flex items-center gap-2 z-20">
        <button
          onClick={() => onSetAutoRotate(!autoRotate)}
          className={`px-3 py-1.5 rounded-lg text-xs font-medium border backdrop-blur-md transition-all flex items-center gap-1.5 ${
            autoRotate
              ? 'bg-indigo-600/80 text-white border-indigo-400/60 shadow-lg shadow-indigo-600/30'
              : 'bg-slate-900/80 text-slate-300 border-slate-700/80 hover:bg-slate-800/80'
          }`}
          title="Toggle Turntable Rotation"
        >
          <svg className="w-3.5 h-3.5" viewBox="0 0 24 24" fill="none" stroke="currentColor">
            <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M4 4v5h.582m15.356 2A8.001 8.001 0 004.582 9m0 0H9m11 11v-5h-.581m0 0a8.003 8.003 0 01-15.357-2m15.357 2H15" />
          </svg>
          <span>{autoRotate ? 'Rotating' : 'Paused'}</span>
        </button>

        <button
          onClick={onResetCamera}
          className="p-2 rounded-lg bg-slate-900/80 hover:bg-slate-800/80 border border-slate-700/80 text-slate-300 hover:text-white backdrop-blur-md transition-colors"
          title="Re-frame Camera"
        >
          <svg className="w-4 h-4 text-cyan-400" viewBox="0 0 24 24" fill="none" stroke="currentColor">
            <circle cx="12" cy="12" r="3" />
            <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M3 9a2 2 0 012-2h.93a2 2 0 001.664-.89l.812-1.22A2 2 0 0110.07 4h3.86a2 2 0 011.664.89l.812 1.22A2 2 0 0018.07 7H19a2 2 0 012 2v9a2 2 0 01-2 2H5a2 2 0 01-2-2V9z" />
          </svg>
        </button>

        <button
          onClick={onSetFullscreen}
          className="p-2 rounded-lg bg-slate-900/80 hover:bg-slate-800/80 border border-slate-700/80 text-slate-300 hover:text-white backdrop-blur-md transition-colors"
          title="Fullscreen"
        >
          <svg className="w-4 h-4 text-indigo-400" viewBox="0 0 24 24" fill="none" stroke="currentColor">
            <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M4 8V4m0 0h4M4 4l5 5m11-1V4m0 0h-4m4 0l-5 5M4 16v4m0 0h4m-4 0l5-5m11 5l-5-5m5 5v-4m0 4h-4" />
          </svg>
        </button>
      </div>

      {/* Floating Instructions at bottom-left */}
      <div className="absolute bottom-4 left-4 pointer-events-none z-10 flex items-center gap-2 text-[11px] font-medium text-slate-400 bg-slate-950/70 border border-slate-800/80 px-3 py-1.5 rounded-lg backdrop-blur-sm">
        <span>Left Click Drag: Orbit</span>
        <span>•</span>
        <span>Scroll: Zoom</span>
        <span>•</span>
        <span>Right Click: Pan</span>
      </div>

      {/* Minimalist Slim Engine Loading Progress Bar (No splash animation) */}
      {!isEngineReady && !isBuildingMock && !loadError && (
        <div className="absolute top-0 left-0 right-0 z-30 pointer-events-none">
          <div className="h-1 w-full bg-slate-900 overflow-hidden">
            <div
              className="h-full bg-gradient-to-r from-cyan-500 via-indigo-500 to-cyan-400 transition-all duration-300"
              style={{ width: `${Math.max(5, engineProgress * 100)}%` }}
            />
          </div>
          <div className="p-3 flex items-center justify-between text-[11px] font-mono text-slate-400 bg-slate-950/60 backdrop-blur-sm border-b border-slate-800/40">
            <span>Loading 3D Engine...</span>
            <span className="text-cyan-400">{Math.round(engineProgress * 100)}%</span>
          </div>
        </div>
      )}

      {/* Model Download / Loading Progress Pill */}
      {isModelLoading && (
        <div className="absolute top-4 left-4 z-20 flex items-center gap-2.5 bg-slate-900/90 border border-indigo-500/40 px-3.5 py-2 rounded-xl backdrop-blur-md shadow-lg shadow-indigo-950/50">
          <div className="w-4 h-4 border-2 border-indigo-500/30 border-t-indigo-400 rounded-full animate-spin" />
          <div>
            <div className="text-xs font-medium text-white flex items-center gap-2">
              <span>{modelStage || 'Loading Model...'}</span>
              <span className="font-mono text-[11px] text-cyan-400">
                {Math.round(modelProgress * 100)}%
              </span>
            </div>
            <div className="w-36 h-1 bg-slate-800 rounded-full mt-1 overflow-hidden">
              <div
                className="h-full bg-indigo-500 transition-all duration-200"
                style={{ width: `${Math.max(5, modelProgress * 100)}%` }}
              />
            </div>
          </div>
        </div>
      )}

      {/* Error Overlay */}
      {errorMessage && (
        <div className="absolute bottom-16 left-4 right-4 z-20 p-3 rounded-xl bg-rose-950/90 border border-rose-700/60 text-rose-200 text-xs flex items-center gap-2.5 backdrop-blur-md">
          <svg className="w-4 h-4 text-rose-400 shrink-0" viewBox="0 0 24 24" fill="none" stroke="currentColor">
            <circle cx="12" cy="12" r="10" />
            <line x1="12" y1="8" x2="12" y2="12" />
            <line x1="12" y1="16" x2="12.01" y2="16" />
          </svg>
          <span className="truncate">{errorMessage}</span>
        </div>
      )}

      {/* Notice & Simulation Trigger if WebGL build files are waiting */}
      {isBuildingMock && (
        <div className="absolute inset-0 bg-slate-950/95 backdrop-blur-md z-30 flex flex-col items-center justify-center p-6 text-center">
          <div className="w-12 h-12 rounded-2xl bg-indigo-500/20 border border-indigo-500/40 flex items-center justify-center mb-3">
            <svg className="w-6 h-6 text-indigo-400" viewBox="0 0 24 24" fill="none" stroke="currentColor">
              <polygon points="12 2 2 7 12 12 22 7 12 2" />
              <polyline points="2 17 12 22 22 17" />
              <polyline points="2 12 12 17 22 12" />
            </svg>
          </div>
          <h3 className="text-sm font-bold text-white mb-1">
            Unity WebGL Build Not Detected Yet
          </h3>
          <p className="text-xs text-slate-400 max-w-md mb-4 leading-relaxed">
            Run <code className="text-cyan-300 font-mono bg-slate-900 px-1.5 py-0.5 rounded border border-slate-800">build-webgl.bat</code> in the <code className="text-slate-300 font-mono">unity-project</code> folder to compile the production WebGL build directly into <code className="text-slate-300 font-mono">public/unity-build</code>.
          </p>
          <div className="flex gap-3">
            <button
              onClick={startSimulation}
              className="px-4 py-2 bg-indigo-600 hover:bg-indigo-500 text-white rounded-xl text-xs font-semibold shadow-lg shadow-indigo-600/30 transition-all"
            >
              Launch Live Bridge Preview
            </button>
          </div>
        </div>
      )}
    </div>
  );
};
