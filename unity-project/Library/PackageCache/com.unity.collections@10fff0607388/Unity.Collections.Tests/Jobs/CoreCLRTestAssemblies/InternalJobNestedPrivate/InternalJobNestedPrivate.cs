using System;
using Unity.Jobs;

namespace Unity.Collections.Tests.CoreCLR.TestJobs
{
    public class InternalJobNestedPrivateContainerClass
    {
        // Expose the Type so we can check for it in the test
        public static Type TestJobType = typeof(PrivateInternalContainerClass.PrivateNestedInternalTestJob);

        private class PrivateInternalContainerClass
        {
            internal struct PrivateNestedInternalTestJob : IJob
            {
                public void Execute()
                { }
            }
        }
    }
}
