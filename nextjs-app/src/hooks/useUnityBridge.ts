'use client';

import { useState, useEffect, useCallback, useRef } from 'react';
import type { UnityInstance, ModelStats, ProgressPayload, BridgeLogEntry } from '@/types/unity';

export function useUnityBridge() {
  const [unityInstance, setUnityInstance] = useState<UnityInstance | null>(null);
  const [isEngineReady, setIsEngineReady] = useState(false);
  const [engineProgress, setEngineProgress] = useState(0);

  // Model state
  const [currentModelUrl, setCurrentModelUrl] = useState<string>('');
  const [isModelLoading, setIsModelLoading] = useState(false);
  const [modelProgress, setModelProgress] = useState(0);
  const [modelStage, setModelStage] = useState('');
  const [modelStats, setModelStats] = useState<ModelStats | null>(null);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);

  // Turntable & visual settings state
  const [autoRotate, setAutoRotateState] = useState(true);
  const [rotationSpeed, setRotationSpeedState] = useState(1.0);
  const [wireframe, setWireframeState] = useState(false);
  const [backgroundColor, setBackgroundColorState] = useState('#0f172a');

  // Bidirectional message log
  const [logs, setLogs] = useState<BridgeLogEntry[]>([]);

  const unityInstanceRef = useRef<UnityInstance | null>(null);
  unityInstanceRef.current = unityInstance;

  const addLog = useCallback((direction: 'to-unity' | 'from-unity', channel: string, payload: unknown) => {
    const entry: BridgeLogEntry = {
      id: Math.random().toString(36).substring(2, 9),
      timestamp: new Date().toLocaleTimeString('en-US', { hour12: false, hour: '2-digit', minute: '2-digit', second: '2-digit', fractionalSecondDigits: 3 }),
      direction,
      channel,
      payload
    };
    setLogs((prev) => [entry, ...prev].slice(0, 50)); // keep last 50 entries
  }, []);

  // Low-level send command
  const sendUnityMessage = useCallback((gameObjectName: string, methodName: string, parameter: string | number = '') => {
    addLog('to-unity', `${gameObjectName}.${methodName}`, parameter);

    if (unityInstanceRef.current) {
      try {
        unityInstanceRef.current.SendMessage(gameObjectName, methodName, parameter);
      } catch (err) {
        console.error(`[UnityBridge] Error calling ${gameObjectName}.${methodName}:`, err);
      }
    } else {
      console.warn(`[UnityBridge] Unity instance not ready yet for ${gameObjectName}.${methodName}(${parameter})`);
    }
  }, [addLog]);

  // High-level Actions
  const loadGlb = useCallback((url: string) => {
    if (!url) return;
    setCurrentModelUrl(url);
    setIsModelLoading(true);
    setModelProgress(0.05);
    setModelStage('Initiating Download');
    setErrorMessage(null);

    // Convert relative URL to full absolute URL if needed so Unity WebGL can fetch without ambiguity
    let fullUrl = url;
    if (typeof window !== 'undefined' && !url.startsWith('http://') && !url.startsWith('https://') && !url.startsWith('blob:')) {
      fullUrl = new URL(url, window.location.origin).href;
    }

    sendUnityMessage('ModelManager', 'LoadGlbFromUrl', fullUrl);
  }, [sendUnityMessage]);

  const setAutoRotate = useCallback((enabled: boolean) => {
    setAutoRotateState(enabled);
    sendUnityMessage('ModelManager', 'SetAutoRotate', enabled ? 'true' : 'false');
  }, [sendUnityMessage]);

  const setRotationSpeed = useCallback((speed: number) => {
    setRotationSpeedState(speed);
    sendUnityMessage('ModelManager', 'SetRotationSpeed', speed.toString());
  }, [sendUnityMessage]);

  const resetCamera = useCallback(() => {
    sendUnityMessage('ModelManager', 'ResetCamera', '');
  }, [sendUnityMessage]);

  const setBackgroundColor = useCallback((hexColor: string) => {
    setBackgroundColorState(hexColor);
    sendUnityMessage('ModelManager', 'SetBackgroundColor', hexColor);
  }, [sendUnityMessage]);

  const setWireframe = useCallback((enabled: boolean) => {
    setWireframeState(enabled);
    sendUnityMessage('ModelManager', 'SetWireframe', enabled ? 'true' : 'false');
  }, [sendUnityMessage]);

  const setFullscreen = useCallback(() => {
    addLog('to-unity', 'SetFullscreen', 1);
    if (unityInstanceRef.current) {
      unityInstanceRef.current.SetFullscreen(1);
    }
  }, [addLog]);

  // Register Event Listeners for messages coming FROM Unity
  useEffect(() => {
    if (typeof window === 'undefined') return;

    const handleUnityReady = (e: CustomEvent<{ ready: boolean; unityVersion?: string }>) => {
      addLog('from-unity', 'UnityReady', e.detail);
      setIsEngineReady(true);
      setEngineProgress(1.0);
    };

    const handleModelProgress = (e: CustomEvent<ProgressPayload>) => {
      addLog('from-unity', 'UnityModelProgress', e.detail);
      setIsModelLoading(true);
      setModelProgress(e.detail?.progress ?? 0);
      setModelStage(e.detail?.stage ?? 'Processing');
    };

    const handleModelLoaded = (e: CustomEvent<ModelStats>) => {
      addLog('from-unity', 'UnityModelLoaded', e.detail);
      setIsModelLoading(false);
      setModelProgress(1.0);
      setModelStage('Rendered');
      setModelStats(e.detail);
    };

    const handleModelError = (e: CustomEvent<{ error: string }>) => {
      addLog('from-unity', 'UnityModelError', e.detail);
      setIsModelLoading(false);
      setErrorMessage(e.detail?.error || 'Unknown error occurred while loading GLB in Unity.');
    };

    window.addEventListener('UnityReady', handleUnityReady as EventListener);
    window.addEventListener('UnityModelProgress', handleModelProgress as EventListener);
    window.addEventListener('UnityModelLoaded', handleModelLoaded as EventListener);
    window.addEventListener('UnityModelError', handleModelError as EventListener);

    return () => {
      window.removeEventListener('UnityReady', handleUnityReady as EventListener);
      window.removeEventListener('UnityModelProgress', handleModelProgress as EventListener);
      window.removeEventListener('UnityModelLoaded', handleModelLoaded as EventListener);
      window.removeEventListener('UnityModelError', handleModelError as EventListener);
    };
  }, [addLog]);

  return {
    // Engine State
    unityInstance,
    setUnityInstance,
    isEngineReady,
    setIsEngineReady,
    engineProgress,
    setEngineProgress,

    // Model State
    currentModelUrl,
    isModelLoading,
    modelProgress,
    modelStage,
    modelStats,
    errorMessage,

    // Visual controls state
    autoRotate,
    rotationSpeed,
    wireframe,
    backgroundColor,

    // Action dispatches
    loadGlb,
    setAutoRotate,
    setRotationSpeed,
    resetCamera,
    setBackgroundColor,
    setWireframe,
    setFullscreen,

    // Logs
    logs,
    clearLogs: () => setLogs([])
  };
}
