using System;
using Unity.Jobs;

namespace Unity.Collections.Tests.CoreCLR.TestJobs
{
    public class NestedPublicGenericTestJobContainterClass
    {
        // Expose the Type so we can check for it in the test
        public static Type TestJobType = typeof(NestedPublicGenericTestJob<PrivateExecutor>);

        public interface IExecutor
        {
            public abstract void Execute();
        }
        public struct NestedPublicGenericTestJob<TExecutor> : IJob where TExecutor : IExecutor
        {
            public TExecutor executor;
            public void Execute()
            {
                executor.Execute();
            }
        }

        struct PrivateExecutor : IExecutor
        {
            public void Execute(){ }
        }

        public void DeclareTestInstance()
        {
            var testJob = new NestedPublicGenericTestJob<PrivateExecutor>();
            testJob.Execute();
        }
    }
}
