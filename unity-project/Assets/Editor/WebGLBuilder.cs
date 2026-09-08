using System;
using System.IO;
using UnityEditor;
using UnityEditor.Build.Reporting;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace UnityNextViewer.Editor
{
    public static class WebGLBuilder
    {
        [MenuItem("Build/Build WebGL to Next.js")]
        public static void BuildWebGL()
        {
            Debug.Log("[WebGLBuilder] Starting automated WebGL build...");

            // Determine output directory: nextjs-app/public/unity-build
            string projectRoot = Directory.GetParent(Application.dataPath).FullName;
            string outputPath = Path.Combine(projectRoot, "..", "nextjs-app", "public", "unity-build");
            outputPath = Path.GetFullPath(outputPath);

            // Read custom output path from command line arguments if passed
            string[] args = Environment.GetCommandLineArgs();
            for (int i = 0; i < args.Length; i++)
            {
                if (args[i] == "-customOutputPath" && i + 1 < args.Length)
                {
                    outputPath = args[i + 1];
                    break;
                }
            }

            Debug.Log($"[WebGLBuilder] Output directory target: {outputPath}");

            // Ensure destination directory exists
            if (!Directory.Exists(outputPath))
            {
                Directory.CreateDirectory(outputPath);
            }

            // Ensure scene exists and is saved
            string scenePath = "Assets/Scenes/MainScene.unity";
            EnsureSceneSetup(scenePath);

            // Configure WebGL player settings
            EditorUserBuildSettings.SwitchActiveBuildTarget(BuildTargetGroup.WebGL, BuildTarget.WebGL);

            // IMPORTANT: Disable compression (Disabled / None) so files can be served directly by Next.js static server without requiring custom Brotli/Gzip server headers!
            PlayerSettings.WebGL.compressionFormat = WebGLCompressionFormat.Disabled;
            PlayerSettings.WebGL.dataCaching = false;
            // Disable "Made with Unity" splash screen and animations
            PlayerSettings.SplashScreen.show = false;
            PlayerSettings.SplashScreen.showUnityLogo = false;
            PlayerSettings.companyName = "UnityNext";
            PlayerSettings.productName = "UnityNextViewer";

            // Prepare build options
            BuildPlayerOptions buildPlayerOptions = new BuildPlayerOptions
            {
                scenes = new[] { scenePath },
                locationPathName = outputPath,
                target = BuildTarget.WebGL,
                options = BuildOptions.None
            };

            Debug.Log("[WebGLBuilder] Executing BuildPipeline.BuildPlayer...");
            BuildReport report = BuildPipeline.BuildPlayer(buildPlayerOptions);
            BuildSummary summary = report.summary;

            if (summary.result == BuildResult.Succeeded)
            {
                Debug.Log($"[WebGLBuilder] SUCCESS! WebGL build generated at {outputPath} ({summary.totalSize / (1024 * 1024)} MB)");
            }
            else if (summary.result == BuildResult.Failed)
            {
                Debug.LogError($"[WebGLBuilder] FAILED with {summary.totalErrors} error(s).");
                EditorApplication.Exit(1);
            }
        }

        public static void EnsureSceneSetup(string scenePath)
        {
            string dir = Path.GetDirectoryName(scenePath);
            if (!Directory.Exists(dir))
            {
                Directory.CreateDirectory(dir);
            }

            Scene scene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Single);

            // 1. Camera with OrbitCamera
            GameObject camObj = new GameObject("Main Camera");
            Camera cam = camObj.AddComponent<Camera>();
            cam.tag = "MainCamera";
            cam.clearFlags = CameraClearFlags.SolidColor;
            cam.backgroundColor = new Color(0.06f, 0.09f, 0.16f, 1f); // Dark slate
            cam.fieldOfView = 50f;
            cam.nearClipPlane = 0.01f;
            cam.farClipPlane = 1000f;
            camObj.AddComponent<AudioListener>();
            OrbitCamera orbitCam = camObj.AddComponent<OrbitCamera>();
            camObj.transform.position = new Vector3(0, 2, -5);

            // 2. Directional Key Light
            GameObject lightObj = new GameObject("Directional Light");
            Light light = lightObj.AddComponent<Light>();
            light.type = LightType.Directional;
            light.color = Color.white;
            light.intensity = 1.2f;
            lightObj.transform.rotation = Quaternion.Euler(50f, -30f, 0f);

            // 3. Fill Light
            GameObject fillLightObj = new GameObject("Fill Light");
            Light fillLight = fillLightObj.AddComponent<Light>();
            fillLight.type = LightType.Directional;
            fillLight.color = new Color(0.7f, 0.8f, 1.0f);
            fillLight.intensity = 0.5f;
            fillLightObj.transform.rotation = Quaternion.Euler(-30f, 150f, 0f);

            // 4. ModelManager GameObject
            GameObject managerObj = new GameObject("ModelManager");
            ModelManager manager = managerObj.AddComponent<ModelManager>();
            manager.mainCamera = cam;
            manager.orbitCamera = orbitCam;
            manager.mainLight = light;
            manager.autoRotate = true;
            manager.rotationSpeed = 25f;

            orbitCam.target = managerObj.transform;

            EditorSceneManager.SaveScene(scene, scenePath);
            Debug.Log($"[WebGLBuilder] Scene created and saved to {scenePath}");
        }
    }
}
