using System;
using Unity.Jobs;

namespace Unity.Collections.Tests.CoreCLR.TestJobs
{
    public class NestedPrivateTestJobContainterClass
    {
        // Expose the Type so we can check for it in the test
        public static Type TestJobType = typeof(NestedPrivateTestJob);

        struct NestedPrivateTestJob : IJob
        {
            public void Execute()
            {}
        }
    }
}
