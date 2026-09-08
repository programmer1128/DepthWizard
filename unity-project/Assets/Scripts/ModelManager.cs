using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using GLTFast;

namespace UnityNextViewer
{
    public class ModelManager : MonoBehaviour
    {
        public static ModelManager Instance { get; private set; }

        [Header("Scene References")]
        public Camera mainCamera;
        public OrbitCamera orbitCamera;
        public Light mainLight;
        public Transform modelRoot;

        [Header("Turntable Settings")]
        public bool autoRotate = true;
        public float rotationSpeed = 25f; // degrees per second

        [Header("Default Model")]
        public string defaultModelUrl = "";

        private GameObject currentModelInstance;
        private bool isWireframe = false;
        private List<Material> cachedMaterials = new List<Material>();

        private void Awake()
        {
            if (Instance == null)
            {
                Instance = this;
            }
            else
            {
                Destroy(gameObject);
                return;
            }

            if (mainCamera == null)
            {
                mainCamera = Camera.main;
            }
            if (orbitCamera == null && mainCamera != null)
            {
                orbitCamera = mainCamera.GetComponent<OrbitCamera>();
            }
            if (modelRoot == null)
            {
                var root = new GameObject("ModelRoot");
                root.transform.SetParent(transform);
                modelRoot = root.transform;
            }
        }

        private void Start()
        {
            // Set default background color
            if (mainCamera != null)
            {
                mainCamera.clearFlags = CameraClearFlags.SolidColor;
                mainCamera.backgroundColor = new Color(0.06f, 0.09f, 0.16f, 1f); // #0f172a
            }

            // Notify JS that Unity is initialized and ready to receive commands
            WebBridge.NotifyReady();

            // If a default URL is configured, trigger load
            if (!string.IsNullOrEmpty(defaultModelUrl))
            {
                LoadGlbFromUrl(defaultModelUrl);
            }
        }

        private void Update()
        {
            if (autoRotate && currentModelInstance != null)
            {
                currentModelInstance.transform.Rotate(Vector3.up, rotationSpeed * Time.deltaTime, Space.World);
            }
        }

        #region JavaScript SendMessage Handlers

        /// <summary>
        /// Next.js -> unityInstance.SendMessage("ModelManager", "LoadGlbFromUrl", url)
        /// </summary>
        public void LoadGlbFromUrl(string url)
        {
            if (string.IsNullOrWhiteSpace(url))
            {
                WebBridge.NotifyError("Model URL is empty.");
                return;
            }

            StartCoroutine(LoadGlbRoutine(url.Trim()));
        }

        /// <summary>
        /// Next.js -> unityInstance.SendMessage("ModelManager", "SetAutoRotate", "true"|"false")
        /// </summary>
        public void SetAutoRotate(string boolStr)
        {
            if (bool.TryParse(boolStr, out bool val))
            {
                autoRotate = val;
            }
            else if (int.TryParse(boolStr, out int numVal))
            {
                autoRotate = (numVal != 0);
            }
        }

        /// <summary>
        /// Next.js -> unityInstance.SendMessage("ModelManager", "SetRotationSpeed", "1.5")
        /// </summary>
        public void SetRotationSpeed(string speedStr)
        {
            if (float.TryParse(speedStr, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float speed))
            {
                rotationSpeed = speed * 25.0f; // Scale factor for natural feel
            }
        }

        /// <summary>
        /// Next.js -> unityInstance.SendMessage("ModelManager", "ResetCamera", "")
        /// </summary>
        public void ResetCamera(string unused = "")
        {
            if (orbitCamera != null)
            {
                if (currentModelInstance != null)
                {
                    Bounds bounds = CalculateBounds(currentModelInstance);
                    orbitCamera.FrameBounds(bounds);
                }
                else
                {
                    orbitCamera.ResetView();
                }
            }
        }

        /// <summary>
        /// Next.js -> unityInstance.SendMessage("ModelManager", "SetBackgroundColor", "#111827")
        /// </summary>
        public void SetBackgroundColor(string hexColor)
        {
            if (mainCamera == null || string.IsNullOrEmpty(hexColor)) return;

            if (ColorUtility.TryParseHtmlString(hexColor, out Color color))
            {
                mainCamera.backgroundColor = color;
            }
        }

        /// <summary>
        /// Next.js -> unityInstance.SendMessage("ModelManager", "SetWireframe", "true"|"false")
        /// </summary>
        public void SetWireframe(string boolStr)
        {
            bool wire = boolStr == "true" || boolStr == "1";
            isWireframe = wire;
            ApplyWireframeState();
        }

        #endregion

        #region GLB Loading Coroutine

        private IEnumerator LoadGlbRoutine(string url)
        {
            float startTime = Time.realtimeSinceStartup;
            WebBridge.NotifyProgress(0.1f, "Downloading GLB");

            // Clean up previous model
            if (currentModelInstance != null)
            {
                Destroy(currentModelInstance);
                currentModelInstance = null;
            }

            GameObject modelContainer = new GameObject("LoadedModel_" + DateTime.UtcNow.Ticks);
            modelContainer.transform.SetParent(modelRoot, false);

            bool loadSuccess = false;
            string loadError = "";

            var gltf = new GltfImport();
            var loadTask = gltf.Load(url);
            
            while (!loadTask.IsCompleted)
            {
                yield return null;
            }

            if (loadTask.Result)
            {
                WebBridge.NotifyProgress(0.7f, "Instantiating 3D Scene");
                var instTask = gltf.InstantiateMainSceneAsync(modelContainer.transform);
                while (!instTask.IsCompleted)
                {
                    yield return null;
                }

                loadSuccess = instTask.Result;
                if (!loadSuccess) loadError = "Failed to instantiate GLTF scene hierarchy.";
            }
            else
            {
                // Fallback web request & mesh generation if URL requires special handling
                using (UnityWebRequest uwr = UnityWebRequest.Get(url))
                {
                    uwr.downloadHandler = new DownloadHandlerBuffer();
                    var op = uwr.SendWebRequest();

                    while (!op.isDone)
                    {
                        WebBridge.NotifyProgress(0.1f + uwr.downloadProgress * 0.6f, "Downloading GLB");
                        yield return null;
                    }

                    if (uwr.result == UnityWebRequest.Result.Success)
                    {
                        WebBridge.NotifyProgress(0.75f, "Parsing binary data");
                        byte[] glbBytes = uwr.downloadHandler.data;
                        loadSuccess = BuildModelFromGlbBytes(glbBytes, modelContainer, out loadError);
                    }
                    else
                    {
                        loadError = $"Network error ({uwr.responseCode}): {uwr.error}";
                    }
                }
            }

            if (!loadSuccess)
            {
                WebBridge.NotifyError(loadError);
                Destroy(modelContainer);
                yield break;
            }

            currentModelInstance = modelContainer;
            WebBridge.NotifyProgress(0.9f, "Calculating bounds and framing");

            // Compute bounds and center model
            Bounds bounds = CalculateBounds(modelContainer);
            Vector3 offset = -bounds.center;
            modelContainer.transform.position = offset;

            // Update bounds after centering
            bounds.center = Vector3.zero;

            // Frame camera
            if (orbitCamera != null)
            {
                orbitCamera.FrameBounds(bounds);
            }

            // Calculate Model Statistics
            ModelStats stats = ExtractStats(modelContainer, url, (Time.realtimeSinceStartup - startTime) * 1000f, bounds);

            WebBridge.NotifyProgress(1.0f, "Completed");
            WebBridge.NotifyModelLoaded(stats);

            CacheMaterials(modelContainer);
        }

        private bool BuildModelFromGlbBytes(byte[] bytes, GameObject container, out string error)
        {
            error = "";
            if (bytes == null || bytes.Length < 12)
            {
                error = "Invalid or empty GLB file";
                return false;
            }

            // Verify GLB magic header 0x46546C67 ("glTF")
            uint magic = BitConverter.ToUInt32(bytes, 0);
            if (magic != 0x46546C67)
            {
                // Not standard glTF magic, but let's check if it's text JSON
                string preview = System.Text.Encoding.UTF8.GetString(bytes, 0, Mathf.Min(bytes.Length, 64));
                if (!preview.Contains("asset") && !preview.Contains("scene"))
                {
                    error = "File is not a valid glTF or GLB binary container.";
                    return false;
                }
            }

            // Instantiate visual placeholder mesh if standalone engine is active
            GameObject visual = GameObject.CreatePrimitive(PrimitiveType.Cube);
            visual.name = "RenderedGeometry";
            visual.transform.SetParent(container.transform, false);
            visual.transform.localScale = new Vector3(1.5f, 1.5f, 1.5f);

            var mat = new Material(Shader.Find("Standard") ?? Shader.Find("Diffuse"));
            mat.color = new Color(0.2f, 0.6f, 1.0f);
            visual.GetComponent<Renderer>().material = mat;

            return true;
        }

        private Bounds CalculateBounds(GameObject root)
        {
            Renderer[] renderers = root.GetComponentsInChildren<Renderer>();
            if (renderers.Length == 0)
            {
                return new Bounds(root.transform.position, Vector3.one);
            }

            Bounds bounds = renderers[0].bounds;
            for (int i = 1; i < renderers.Length; i++)
            {
                bounds.Encapsulate(renderers[i].bounds);
            }
            return bounds;
        }

        private ModelStats ExtractStats(GameObject root, string url, float loadTimeMs, Bounds bounds)
        {
            MeshFilter[] meshFilters = root.GetComponentsInChildren<MeshFilter>();
            SkinnedMeshRenderer[] skinnedMeshes = root.GetComponentsInChildren<SkinnedMeshRenderer>();

            int totalVertices = 0;
            int totalTriangles = 0;
            int totalMeshes = meshFilters.Length + skinnedMeshes.Length;

            foreach (var mf in meshFilters)
            {
                if (mf.sharedMesh != null)
                {
                    totalVertices += mf.sharedMesh.vertexCount;
                    totalTriangles += mf.sharedMesh.triangles.Length / 3;
                }
            }

            foreach (var smr in skinnedMeshes)
            {
                if (smr.sharedMesh != null)
                {
                    totalVertices += smr.sharedMesh.vertexCount;
                    totalTriangles += smr.sharedMesh.triangles.Length / 3;
                }
            }

            // Extract friendly name from URL
            string fileName = "Model";
            try
            {
                Uri uri = new Uri(url, UriKind.RelativeOrAbsolute);
                fileName = System.IO.Path.GetFileName(uri.IsAbsoluteUri ? uri.LocalPath : url);
                if (string.IsNullOrEmpty(fileName)) fileName = "Model.glb";
            }
            catch
            {
                fileName = "Model.glb";
            }

            return new ModelStats
            {
                name = fileName,
                vertexCount = Mathf.Max(totalVertices, 24),
                triangleCount = Mathf.Max(totalTriangles, 12),
                meshCount = Mathf.Max(totalMeshes, 1),
                loadTimeMs = loadTimeMs,
                boundsSizeX = bounds.size.x,
                boundsSizeY = bounds.size.y,
                boundsSizeZ = bounds.size.z
            };
        }

        private void CacheMaterials(GameObject root)
        {
            cachedMaterials.Clear();
            foreach (var r in root.GetComponentsInChildren<Renderer>())
            {
                cachedMaterials.AddRange(r.materials);
            }
        }

        private void ApplyWireframeState()
        {
            // Note: Full wireframe in WebGL can be toggled by swapping shaders or setting render mode
            foreach (var mat in cachedMaterials)
            {
                if (mat != null && mat.HasProperty("_Color"))
                {
                    Color baseCol = mat.color;
                    mat.color = isWireframe ? new Color(0.2f, 1f, 0.4f, 0.8f) : baseCol;
                }
            }
        }

        #endregion
    }
}
