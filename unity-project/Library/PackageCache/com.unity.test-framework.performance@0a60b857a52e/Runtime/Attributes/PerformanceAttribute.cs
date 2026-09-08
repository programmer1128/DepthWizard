using System;
using System.Collections;
using NUnit.Framework;
using NUnit.Framework.Interfaces;
using NUnit.Framework.Internal;
using Unity.PerformanceTesting.Data;
using Unity.PerformanceTesting.Runtime;
using UnityEngine.TestTools;

namespace Unity.PerformanceTesting
{
    /// <summary>
    /// Test attribute to specify a performance test. It will add category "Performance" to test properties.
    /// Optionally, a performance regression threshold can be specified, to be used at the test result endpoint.
    /// </summary>
    [AttributeUsage(AttributeTargets.Method, AllowMultiple = false)]
    public class PerformanceAttribute : CategoryAttribute, IOuterUnityTestAction, IApplyToTest
    {
        /// <summary>
        /// Adds performance attribute to a test method.
        /// </summary>
        public PerformanceAttribute()
            : base("Performance") { }

        /// <summary>
        /// Performance regression threshold.
        /// </summary>
        public double Threshold { get; } = PerformanceTest.DefaultThresholdValue;

        /// <summary>
        /// Adds performance attribute to a test method with a performance regression threshold.
        /// </summary>
        /// <param name="threshold">A performance regression threshold to associate for the given test, taken into account at the result endpoint.  The value represents a multiple of the result.  Only positive values are considered valid. If the value is invalid, the property will not be serialized/sent to the result endpoint.</param>
        public PerformanceAttribute(double threshold) : base("Performance")
        {
            Threshold = threshold;
        }

        /// <summary>
        /// Executed before a test execution.
        /// </summary>
        /// <param name="test">Test to execute.</param>
        /// <returns>Enumerable collection of actions to perform before test setup.</returns>
        public IEnumerator BeforeTest(ITest test)
        {
            if (RunSettings.Instance == null)
            {
                RunSettings.Instance = ResourcesLoader.Load<RunSettings>(Utils.RunSettings, Utils.PlayerPrefKeySettingsJSON);
            }

            // domain reload will cause this method to be hit multiple times
            // active performance test is serialized and survives reloads
            if (PerformanceTest.Active == null)
            {
                PerformanceTest.StartTest(test);
                yield return null;
            }
        }

        /// <summary>
        /// Executed after a test execution.
        /// </summary>
        /// <param name="test">Executed test.</param>
        /// <returns>Enumerable collection of actions to perform after test teardown.</returns>
        public IEnumerator AfterTest(ITest test)
        {
            PerformanceTest.EndTest(test);
            yield return null;
        }

        /// <summary>
        /// Used to apply the Threshold property to the Test's Properties
        /// </summary>
        /// <param name="test">An NUnit test</param>
        public new void ApplyToTest(Test test)
        {
            if (Threshold > PerformanceTest.ThresholdSerializationCutOff)
            {
                test.Properties.Add("Threshold", Threshold);
            }

            base.ApplyToTest(test);
        }
    }
}
