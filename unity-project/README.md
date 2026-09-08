# Unity WebGL 3D Engine Project

This Unity project provides the 3D WebGL rendering engine for the Next.js application.

## Key Features
- **Runtime `.glb` Loading**: Utilizes Unity's official `com.unity.cloud.gltfast` package to download, parse, and instantiate glTF/GLB models dynamically at runtime.
- **Auto-Framing**: Dynamically computes model bounding boxes and auto-frames the camera with smooth orbit controls (`OrbitCamera.cs`).
- **Bidirectional JS ↔ Unity Bridge**:
  - `unityInstance.SendMessage("ModelManager", ...)` for commands from Next.js.
  - `Assets/Plugins/WebGL/WebBridge.jslib` + `Assets/Scripts/WebBridge.cs` dispatching custom DOM events (`UnityReady`, `UnityModelLoaded`, `UnityModelProgress`, `UnityModelError`) to the browser.
- **Automated WebGL Builds**: `Assets/Editor/WebGLBuilder.cs` configures headless builds with disabled compression so files can be statically served by Next.js.

## Directory Structure
- `Assets/Scripts/ModelManager.cs`: Main manager receiving JS commands, loading GLB models, and managing rotation and rendering.
- `Assets/Scripts/OrbitCamera.cs`: Mouse & touch orbit, zoom, pan, and bounding-box framing.
- `Assets/Scripts/WebBridge.cs`: C# wrapper for WebGL browser communication.
- `Assets/Plugins/WebGL/WebBridge.jslib`: Emscripten plugin that fires browser `CustomEvent` instances.
- `Assets/Editor/WebGLBuilder.cs`: Headless builder script for CI / automated builds.
- `build-webgl.bat`: 1-click batch script to build directly to `../nextjs-app/public/unity-build/`.

## How to Build
Run:
```cmd
build-webgl.bat
```
Or open the project in Unity Editor (6000.6.0f1) and select:
**Menu bar -> Build -> Build WebGL to Next.js**.
