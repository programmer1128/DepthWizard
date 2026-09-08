using System;
using Unity.Jobs;

namespace Unity.Collections.Tests.CoreCLR.TestJobs
{
    public class NestedProtectedTestJobContainterClass
    {
        // Expose the Type so we can check for it in the test
        public static Type TestJobType = typeof(NestedProtectedTestJob);

        protected struct NestedProtectedTestJob : IJob
        {
            public void Execute()
            {}
        }
    }
}
