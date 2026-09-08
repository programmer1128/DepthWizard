using System;
using System.Globalization;
using Unity.PerformanceTesting.Data;
using Unity.PerformanceTesting.Runtime;
using UnityEngine;
#if USE_CUSTOM_METADATA
using com.unity.test.metadatamanager;
#endif

namespace Unity.PerformanceTesting
{
    /// <summary>
    /// Helper class to retrieve metadata information about player settings and hardware.
    /// </summary>
    public static class Metadata
    {
        /// <summary>
        /// Gets hardware information.
        /// </summary>
        /// <returns>Hardware information.</returns>
        public static Hardware GetHardware()
        {
            return new Hardware
            {
                OperatingSystem = SystemInfo.operatingSystem,
                DeviceModel = SystemInfo.deviceModel,
                DeviceName = SystemInfo.deviceName,
                ProcessorType = SystemInfo.processorType,
                ProcessorCount = SystemInfo.processorCount,
                GraphicsDeviceName = SystemInfo.graphicsDeviceName,
                SystemMemorySizeMB = SystemInfo.systemMemorySize
            };
        }

        /// <summary>
        /// Sets player settings.
        /// </summary>
        /// <param name="run">Run used to set settings.</param>
        public static void SetPlayerSettings(Run run)
        {
            run.Player.Vsync = QualitySettings.vSyncCount;
            run.Player.AntiAliasing = QualitySettings.antiAliasing;
            run.Player.ColorSpace = QualitySettings.activeColorSpace.ToString();
            run.Player.AnisotropicFiltering = QualitySettings.anisotropicFiltering.ToString();
            run.Player.BlendWeights = QualitySettings.skinWeights.ToString();
            #if UNITY_2022_2_OR_NEWER
            run.Player.ScreenRefreshRate = (int)Math.Round(Screen.currentResolution.refreshRateRatio.value); // casting to int and rounding to ensure backwards compatibility with older package versions
            #else
            run.Player.ScreenRefreshRate = Screen.currentResolution.refreshRate;
            #endif
            run.Player.ScreenWidth = Screen.currentResolution.width;
            run.Player.ScreenHeight = Screen.currentResolution.height;
            run.Player.Fullscreen = Screen.fullScreen;
            run.Player.Batchmode = Application.isBatchMode;
            run.Player.Development = Application.isEditor || Debug.isDebugBuild;
            run.Player.Platform = Application.platform.ToString();
            run.Player.GraphicsApi = SystemInfo.graphicsDeviceType.ToString();
            run.Player.RenderThreadingMode = SystemInfo.renderingThreadingMode.ToString();
            run.Player.MtRendering = SystemInfo.graphicsMultiThreaded;
            run.Player.GraphicsJobs = SystemInfo.renderingThreadingMode.ToString().IndexOf("Job", StringComparison.InvariantCultureIgnoreCase) >= 0;
            
            // This is a bit of a hack, but there isn't currently a way to get this information at runtime. Eventually this will be a proper player setting we can query.
            try
            {
                run.Player.UnityGraphicsKernel = Array.Exists(Environment.GetCommandLineArgs(), arg => arg.Equals("-force-ugk", StringComparison.OrdinalIgnoreCase));
            }
            catch (NotSupportedException)
            {
                // In some environments (WebGL) we can't query command line arguments, so we just catch the exception and move on, leaving this field with its default value of false.
                // When UGK supports these platforms we can update this code to properly query the player setting instead of relying on command line arguments.
            }
        }

        /// <summary>
        /// Loads run from resources.
        /// </summary>
        /// <returns>Performance run data loaded from resources.</returns>
        public static Run GetFromResources()
        {
            var run = ResourcesLoader.Load<Run>(Utils.TestRunInfo, Utils.PlayerPrefKeyRunJSON);
            SetRuntimeSettings(run);

            return run;
        }

        /// <summary>
        /// Sets runtime player settings on a run.
        /// </summary>
        /// <param name="run">Run used to set settings.</param>
        public static void SetRuntimeSettings(Run run)
        {
            run.Hardware = GetHardware();
            SetPlayerSettings(run);
            run.TestSuite = Application.isPlaying ? "Playmode" : "Editmode";
#if USE_CUSTOM_METADATA
            SetCustomMetadata(run);
#endif
        }

#if USE_CUSTOM_METADATA
        private static void SetCustomMetadata(Run run)
        {
            var customMetadataManager = new CustomMetadataManager(run.Dependencies);
            // This field is historically not used so we can safely store additional string delimited
            // metadata here, then parse the metadata values out on the SQL side to give us access
            // to additional metadata that would normally require a schema change, or a property back field
            run.Player.AndroidTargetSdkVersion = customMetadataManager.GetCustomMetadata();
        }
#endif
    }
}