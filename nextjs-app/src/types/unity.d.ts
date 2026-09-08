export interface UnityInstance {
  SendMessage(gameObjectName: string, methodName: string, parameter?: string | number): void;
  SetFullscreen(fullscreen: 0 | 1): void;
  Quit(): Promise<void>;
}

export interface UnityConfig {
  dataUrl: string;
  frameworkUrl: string;
  codeUrl: string;
  streamingAssetsUrl?: string;
  companyName?: string;
  productName?: string;
  productVersion?: string;
}

export interface ModelStats {
  name: string;
  vertexCount: number;
  triangleCount: number;
  meshCount: number;
  loadTimeMs: number;
  boundsSizeX?: number;
  boundsSizeY?: number;
  boundsSizeZ?: number;
}

export interface ProgressPayload {
  progress: number;
  stage: string;
}

export interface BridgeLogEntry {
  id: string;
  timestamp: string;
  direction: 'to-unity' | 'from-unity';
  channel: string;
  payload: unknown;
}

declare global {
  interface Window {
    createUnityInstance?: (
      canvas: HTMLCanvasElement,
      config: UnityConfig,
      onProgress?: (progress: number) => void
    ) => Promise<UnityInstance>;
    onUnityBridgeEvent?: (eventName: string, payload: unknown) => void;
  }
}
