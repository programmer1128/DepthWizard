using System.Collections.Generic;
using Unity.PerformanceTesting.Runtime;
using Unity.Profiling;
using UnityEngine;

namespace Unity.PerformanceTesting.Measurements
{
    class ProfilerMeasurementBehaviour : MonoBehaviour
    {
        private bool m_MeasurementStarted = false;
        private ProfilerMarkerMeasurement m_ProfilerMarkerMeasurement = new ProfilerMarkerMeasurement(averageSampleMeasurement: false);

        public void AddProfilerSampleGroup(IEnumerable<SampleGroup> sampleGroups)
        {
            m_ProfilerMarkerMeasurement.AddProfilerSampleGroup(sampleGroups);
            // Frame measurements sample once per frame, so recording starts right away
            m_ProfilerMarkerMeasurement.StartRecording();
        }

        public void StopAndSampleRecorders()
        {
            m_ProfilerMarkerMeasurement.StopAndSampleRecorders();
        }

        public void Update()
        {
            // Skip one frame where we just start recording and don't have full data yet
            if (!m_MeasurementStarted)
            {
                m_MeasurementStarted = true;
            }
            else
            {
                m_ProfilerMarkerMeasurement.SampleProfilerSamples();
            }
        }

        public void OnDestroy()
        {
            m_ProfilerMarkerMeasurement.Dispose();
            m_ProfilerMarkerMeasurement = null;
        }
    }
}
