using System;
using System.Collections.Generic;
using Unity.PerformanceTesting.Runtime;
using Unity.Profiling;
using UnityEngine;

namespace Unity.PerformanceTesting.Measurements
{
    class ProfilerMarkerMeasurement : IDisposable
    {
        private readonly bool m_AverageSampleMeasurement;
        bool m_DisposedValue;
        bool m_RecordingStarted;

        protected struct RecordedSampleGroup
        {
            public SampleGroup SampleGroup;
            public ProfilerRecorder ProfilerRecorder;
        }

        protected readonly List<RecordedSampleGroup> m_SampleGroups = new List<RecordedSampleGroup>();

        public ProfilerMarkerMeasurement(bool averageSampleMeasurement)
        {
            m_AverageSampleMeasurement = averageSampleMeasurement;
        }

        public void AddProfilerSampleGroup(IEnumerable<SampleGroup> sampleGroups)
        {
            foreach (var sampleGroup in sampleGroups)
            {
                AddProfilerSample(sampleGroup);
            }
        }

        public void AddProfilerSample(SampleGroup sampleGroup)
        {
            m_SampleGroups.Add(new RecordedSampleGroup { SampleGroup = sampleGroup });
        }

        /// <summary>
        /// Creates and starts the recorders for all registered sample groups. Samples produced by the
        /// measured markers before this call are not part of the measurement, which allows warmup
        /// iterations to be excluded from the reported values.
        /// </summary>
        public void StartRecording()
        {
            if (m_RecordingStarted)
                return;
            m_RecordingStarted = true;

            for (var i = 0; i < m_SampleGroups.Count; i++)
            {
                var sampleGroup = m_SampleGroups[i];
                sampleGroup.ProfilerRecorder = new ProfilerRecorder(sampleGroup.SampleGroup.Name, 1,
                    ProfilerRecorderOptions.WrapAroundWhenCapacityReached | ProfilerRecorderOptions.SumAllSamplesInFrame | ProfilerRecorderOptions.StartImmediately);
                m_SampleGroups[i] = sampleGroup;
            }
        }

        public void SampleProfilerSamples(bool stopRecorders = false)
        {
            foreach (var sampleGroup in m_SampleGroups)
            {
                // Validate that the recorder is attached to a valid marker. This check must stay ahead of
                // any Stop/GetSample call: it also skips recorders that were never started (default handle),
                // on which Stop would throw InvalidOperationException
                if (!sampleGroup.ProfilerRecorder.Valid)
                {
                    Debug.LogError($"ProfilerMarker measurement is attached to invalid marker \"{sampleGroup.SampleGroup.Name}\"! Ensure the marker is created at the time of the measurement");
                    continue;
                }

                if (stopRecorders)
                    sampleGroup.ProfilerRecorder.Stop();

                var delta = 0.0;

                // Record the last recorded value if present, otherwise use 0.
                if (sampleGroup.ProfilerRecorder.Count > 0 && sampleGroup.ProfilerRecorder.GetSample(0).Count > 0)
                {
                    var sampleCount = m_AverageSampleMeasurement ? sampleGroup.ProfilerRecorder.GetSample(0).Count : 1;
                    if (sampleCount > 0)
                    {
                        var totalTimeNs = sampleGroup.ProfilerRecorder.GetSample(0).Value / sampleCount;
                        delta = Utils.ConvertSample(SampleUnit.Nanosecond, sampleGroup.SampleGroup.Unit, totalTimeNs);
                    }
                }

                Measure.Custom(sampleGroup.SampleGroup, delta);
            }
        }

        public void StopAndSampleRecorders() => SampleProfilerSamples(true);

        protected virtual void Dispose(bool disposing)
        {
            if (m_DisposedValue)
                return;

            foreach (var sampleGroup in m_SampleGroups)
            {
                sampleGroup.ProfilerRecorder.Dispose();
            }

            m_DisposedValue = true;
        }

        ~ProfilerMarkerMeasurement()
        {
            // Do not change this code. Put cleanup code in 'Dispose(bool disposing)' method
            Dispose(disposing: false);
        }

        public void Dispose()
        {
            // Do not change this code. Put cleanup code in 'Dispose(bool disposing)' method
            Dispose(disposing: true);
            GC.SuppressFinalize(this);
        }
    }
}
