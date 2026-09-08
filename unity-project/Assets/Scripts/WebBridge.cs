using System;
using System.Runtime.InteropServices;
using UnityEngine;

namespace UnityNextViewer
{
    [Serializable]
    public class ModelStats
    {
        public string name;
        public int vertexCount;
        public int triangleCount;
        public int meshCount;
        public float loadTimeMs;
        public float boundsSizeX;
        public float boundsSizeY;
        public float boundsSizeZ;
    }

    [Serializable]
    public class ProgressPayload
    {
        public float progress;
        public string stage;
    }

    [Serializable]
    public class ReadyPayload
    {
        public bool ready;
        public string unityVersion;
    }

    [Serializable]
    public class ErrorPayload
    {
        public string error;
    }

    public static class WebBridge
    {
#if UNITY_WEBGL && !UNITY_EDITOR
        [DllImport("__Internal")]
        private static extern void DispatchBrowserEvent(string eventName, string payload);
#endif

        public static void EmitEvent(string eventName, string jsonPayload)
        {
#if UNITY_WEBGL && !UNITY_EDITOR
            try
            {
                DispatchBrowserEvent(eventName, jsonPayload);
            }
            catch (Exception ex)
            {
                Debug.LogError($"[WebBridge] Error dispatching WebGL event {eventName}: {ex.Message}");
            }
#else
            Debug.Log($"[WebBridge (Editor/Standalone)] Event: {eventName} | Payload: {jsonPayload}");
#endif
        }

        public static void NotifyReady()
        {
            var payload = new ReadyPayload
            {
                ready = true,
                unityVersion = Application.unityVersion
            };
            EmitEvent("UnityReady", JsonUtility.ToJson(payload));
        }

        public static void NotifyProgress(float progress, string stage)
        {
            var payload = new ProgressPayload
            {
                progress = Mathf.Clamp01(progress),
                stage = stage
            };
            EmitEvent("UnityModelProgress", JsonUtility.ToJson(payload));
        }

        public static void NotifyModelLoaded(ModelStats stats)
        {
            EmitEvent("UnityModelLoaded", JsonUtility.ToJson(stats));
        }

        public static void NotifyError(string errorMessage)
        {
            var payload = new ErrorPayload
            {
                error = errorMessage
            };
            EmitEvent("UnityModelError", JsonUtility.ToJson(payload));
        }
    }
}
