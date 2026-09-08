using System;
using NUnit.Framework;
using Unity.Burst;
using Unity.Collections;
using Unity.Collections.LowLevel.Unsafe;
using Unity.Collections.Tests;
using Unity.Jobs;
using Assert = FastAssert;

[BurstCompile]
internal class NativeQueueTests : CollectionsTestCommonBase
{
    static void ExpectedCount<T>(ref NativeQueue<T> container, int expected) where T : unmanaged
    {
        Assert.AreEqual(expected == 0, container.IsEmpty());
        Assert.AreEqual(expected, container.Count);
    }

    [Test]
    public void Enqueue_Dequeue()
    {
        var queue = new NativeQueue<int>(Allocator.Temp);
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        for (int i = 0; i < 16; ++i)
            queue.Enqueue(i);
        ExpectedCount(ref queue, 16);
        for (int i = 0; i < 16; ++i)
            Assert.AreEqual(i, queue.Dequeue(), "Got the wrong value from the queue");
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        queue.Dispose();
    }

    [Test]
    public void ConcurrentEnqueue_Dequeue()
    {
        var queue = new NativeQueue<int>(Allocator.Temp);
        var cQueue = queue.AsParallelWriter();
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        for (int i = 0; i < 16; ++i)
            cQueue.Enqueue(i);
        ExpectedCount(ref queue, 16);
        for (int i = 0; i < 16; ++i)
            Assert.AreEqual(i, queue.Dequeue(), "Got the wrong value from the queue");
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        queue.Dispose();
    }

    [Test]
    public void Enqueue_Dequeue_Peek()
    {
        var queue = new NativeQueue<int>(Allocator.Temp);
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        for (int i = 0; i < 16; ++i)
            queue.Enqueue(i);
        ExpectedCount(ref queue, 16);
        for (int i = 0; i < 16; ++i)
        {
            Assert.AreEqual(i, queue.Peek(), "Got the wrong value from the queue");
            queue.Dequeue();
        }
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        queue.Dispose();
    }

    [Test]
    public void Enqueue_Dequeue_Clear()
    {
        var queue = new NativeQueue<int>(Allocator.Temp);
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        for (int i = 0; i < 16; ++i)
            queue.Enqueue(i);
        ExpectedCount(ref queue, 16);
        for (int i = 0; i < 8; ++i)
            Assert.AreEqual(i, queue.Dequeue(), "Got the wrong value from the queue");
        ExpectedCount(ref queue, 8);
        queue.Clear();
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        queue.Dispose();
    }

    [Test]
    [TestRequiresCollectionChecks]
    public void Double_Deallocate_Throws()
    {
        var queue = new NativeQueue<int>(CommonRwdAllocator.Handle);
        queue.Dispose();
        Assert.Throws<ObjectDisposedException>(
            () => { queue.Dispose(); });
    }

    [Test]
    public void EnqueueScalability()
    {
        var queue = new NativeQueue<int>(Allocator.Persistent);
        for (int i = 0; i != 1000 * 100; i++)
        {
            queue.Enqueue(i);
        }

        ExpectedCount(ref queue, 1000 * 100);

        for (int i = 0; i != 1000 * 100; i++)
            Assert.AreEqual(i, queue.Dequeue());
        ExpectedCount(ref queue, 0);

        queue.Dispose();
    }

    [Test]
    public void Enqueue_Wrap()
    {
        var queue = new NativeQueue<int>(Allocator.Temp);
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        for (int i = 0; i < 256; ++i)
            queue.Enqueue(i);
        ExpectedCount(ref queue, 256);

        for (int i = 0; i < 128; ++i)
            Assert.AreEqual(i, queue.Dequeue(), "Got the wrong value from the queue");
        ExpectedCount(ref queue, 128);

        for (int i = 0; i < 128; ++i)
            queue.Enqueue(i);
        ExpectedCount(ref queue, 256);

        for (int i = 128; i < 256; ++i)
            Assert.AreEqual(i, queue.Dequeue(), "Got the wrong value from the queue");
        ExpectedCount(ref queue, 128);

        for (int i = 0; i < 128; ++i)
            Assert.AreEqual(i, queue.Dequeue(), "Got the wrong value from the queue");
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        queue.Dispose();
    }

    [Test]
    public void ConcurrentEnqueue_Wrap()
    {
        var queue = new NativeQueue<int>(Allocator.Temp);
        var cQueue = queue.AsParallelWriter();
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        for (int i = 0; i < 256; ++i)
            cQueue.Enqueue(i);
        ExpectedCount(ref queue, 256);

        for (int i = 0; i < 128; ++i)
            Assert.AreEqual(i, queue.Dequeue(), "Got the wrong value from the queue");
        ExpectedCount(ref queue, 128);

        for (int i = 0; i < 128; ++i)
            cQueue.Enqueue(i);
        ExpectedCount(ref queue, 256);

        for (int i = 128; i < 256; ++i)
            Assert.AreEqual(i, queue.Dequeue(), "Got the wrong value from the queue");
        ExpectedCount(ref queue, 128);

        for (int i = 0; i < 128; ++i)
            Assert.AreEqual(i, queue.Dequeue(), "Got the wrong value from the queue");
        ExpectedCount(ref queue, 0);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<System.InvalidOperationException>(() => { queue.Dequeue(); });
#endif

        queue.Dispose();
    }

    [Test]
    public void NativeQueue_DisposeJob()
    {
        var container = new NativeQueue<int>(Allocator.Persistent);
        Assert.True(container.IsCreated);
        Assert.DoesNotThrow(() => { container.Enqueue(0); });

        var disposeJob = container.Dispose(default);
        Assert.False(container.IsCreated);

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<ObjectDisposedException>(
            () => { container.Enqueue(0); });
#endif

        disposeJob.Complete();
    }

    [Test]
    public void TryDequeue_OnEmptyQueueWhichHadElements_RetainsValidState()
    {
        using (var queue = new NativeQueue<int>(Allocator.Temp))
        {
            for (int i = 0; i < 3; i++)
            {
                queue.Enqueue(i);
                Assert.AreEqual(1, queue.Count);

                int value;
                while (queue.TryDequeue(out value))
                {
                    Assert.AreEqual(i, value);
                }

                Assert.AreEqual(0, queue.Count);
            }
        }
    }

    [Test]
    public void TryDequeue_OnEmptyQueue_RetainsValidState()
    {
        using (var queue = new NativeQueue<int>(Allocator.Temp))
        {
            Assert.IsFalse(queue.TryDequeue(out _));
            queue.Enqueue(1);
            Assert.AreEqual(1, queue.Count);
        }
    }

    [Test]
    public void ToArray_ContainsCorrectElements()
    {
        using (var queue = new NativeQueue<int>(Allocator.Temp))
        {
            for (int i = 0; i < 100; i++)
                queue.Enqueue(i);
            using (var array = queue.ToArray(Allocator.Temp))
            {
                Assert.AreEqual(queue.Count, array.Length);
                for (int i = 0; i < array.Length; i++)
                    Assert.AreEqual(i, array[i]);
            }
        }
    }

    [Test]
    public void ToArray_RespectsDequeue()
    {
        using (var queue = new NativeQueue<int>(Allocator.Temp))
        {
            for (int i = 0; i < 100; i++)
                queue.Enqueue(i);
            for (int i = 0; i < 50; i++)
                queue.Dequeue();
            using (var array = queue.ToArray(Allocator.Temp))
            {
                Assert.AreEqual(queue.Count, array.Length);
                for (int i = 0; i < array.Length; i++)
                    Assert.AreEqual(50 + i, array[i]);
            }
        }
    }

    [Test]
    [TestRequiresCollectionChecks]
    public void NativeQueue_UseAfterFree_UsesCustomOwnerTypeName()
    {
        var container = new NativeQueue<int>(CommonRwdAllocator.Handle);
        container.Enqueue(123);
        container.Dispose();
        NUnit.Framework.Assert.That(() => container.Dequeue(),
            Throws.Exception.TypeOf<ObjectDisposedException>()
                .With.Message.Contains($"The {container.GetType()} has been deallocated"));
    }

    [Test]
    public void NativeQueue_CustomAllocatorTest()
    {
        AllocatorManager.Initialize();
        var allocatorHelper = new AllocatorHelper<CustomAllocatorTests.CountingAllocator>(AllocatorManager.Persistent);
        ref var allocator = ref allocatorHelper.Allocator;
        allocator.Initialize();

        using (var container = new NativeQueue<int>(allocator.Handle))
        {
        }

        Assert.IsTrue(allocator.WasUsed);
        allocator.Dispose();
        allocatorHelper.Dispose();
        AllocatorManager.Shutdown();
    }

    [BurstCompile(CompileSynchronously = true)]
    struct BurstedCustomAllocatorJob : IJob
    {
        [NativeDisableUnsafePtrRestriction]
        public unsafe CustomAllocatorTests.CountingAllocator* Allocator;

        public void Execute()
        {
            unsafe
            {
                using (var container = new NativeQueue<int>(Allocator->Handle))
                {
                }
            }
        }
    }

    [Test]
    public unsafe void NativeQueue_BurstedCustomAllocatorTest()
    {
        AllocatorManager.Initialize();
        var allocatorHelper = new AllocatorHelper<CustomAllocatorTests.CountingAllocator>(AllocatorManager.Persistent);
        ref var allocator = ref allocatorHelper.Allocator;

        allocator.Initialize();

        var allocatorPtr = (CustomAllocatorTests.CountingAllocator*)UnsafeUtility.AddressOf<CustomAllocatorTests.CountingAllocator>(ref allocator);
        unsafe
        {
            var handle = new BurstedCustomAllocatorJob { Allocator = allocatorPtr }.Schedule();
            handle.Complete();
        }

        Assert.IsTrue(allocator.WasUsed);
        allocator.Dispose();
        allocatorHelper.Dispose();
        AllocatorManager.Shutdown();
    }

    public struct NestedContainer
    {
        public NativeQueue<int> data;
    }

    [Test]
    public void NativeQueue_Nested()
    {
        var inner = new NativeQueue<int>(CommonRwdAllocator.Handle);
        NestedContainer nestedStruct = new NestedContainer { data = inner };

        var containerNestedStruct = new NativeQueue<NestedContainer>(CommonRwdAllocator.Handle);
        var containerNested = new NativeQueue<NativeQueue<int>>(CommonRwdAllocator.Handle);

        containerNested.Enqueue(inner);
        containerNestedStruct.Enqueue(nestedStruct);

        containerNested.Dispose();
        containerNestedStruct.Dispose();
        inner.Dispose();
    }


    [Test]
    public void NativeQueue_ReadOnly()
    {
        var container = new NativeQueue<int>(CommonRwdAllocator.Handle);
        container.Enqueue(123);
        container.Enqueue(456);
        container.Enqueue(789);

        var ro = container.AsReadOnly();
        Assert.AreEqual(3, ro.Count);
        Assert.AreEqual(123, ro[0]);
        Assert.AreEqual(456, ro[1]);
        Assert.AreEqual(789, ro[2]);
#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<IndexOutOfRangeException>(() => { _ = ro[3]; });
        Assert.Throws<IndexOutOfRangeException>(() => { _ = ro[-1]; });
        Assert.Throws<IndexOutOfRangeException>(() => { _ = ro[int.MaxValue]; });
        Assert.Throws<IndexOutOfRangeException>(() => { _ = ro[int.MinValue]; });
#endif

        container.Dispose();
    }

    // Burst error BC1071: Unsupported assert type
    // [BurstCompile(CompileSynchronously = true)]
    struct NativeQueueTestAsReadOnly : IJob
    {
        [ReadOnly]
        NativeQueue<int>.ReadOnly container;

        public NativeQueueTestAsReadOnly(NativeQueue<int>.ReadOnly container) { this.container = container; }

        public void Execute()
        {
            var ro = container;
            Assert.AreEqual(3, ro.Count);
            Assert.AreEqual(123, ro[0]);
            Assert.AreEqual(456, ro[1]);
            Assert.AreEqual(789, ro[2]);
#if ENABLE_UNITY_COLLECTIONS_CHECKS
            Assert.Throws<IndexOutOfRangeException>(() => { _ = ro[3]; });
            Assert.Throws<IndexOutOfRangeException>(() => { _ = ro[-1]; });
            Assert.Throws<IndexOutOfRangeException>(() => { _ = ro[int.MaxValue]; });
            Assert.Throws<IndexOutOfRangeException>(() => { _ = ro[int.MinValue]; });
#endif
        }
    }

    [Test]
    [TestRequiresCollectionChecks]
    public void NativeQueue_ReadOnlyJob()
    {
        var container = new NativeQueue<int>(CommonRwdAllocator.Handle);
        container.Enqueue(123);
        container.Enqueue(456);
        container.Enqueue(789);

        var job = new NativeQueueTestAsReadOnly(container.AsReadOnly()).Schedule();

        Assert.Throws<InvalidOperationException>(() => { container.Enqueue(987); });
        Assert.Throws<InvalidOperationException>(() => { container.Dequeue(); });
        Assert.Throws<InvalidOperationException>(() => { container.Dispose(); });

        job.Complete();

        Assert.DoesNotThrow(() => { container.Enqueue(987); });
        Assert.DoesNotThrow(() => { container.Dequeue(); });
        Assert.DoesNotThrow(() => { container.Dispose(); });
    }

    struct NativeQueueTestWriteMappedToReadOnly : IJob
    {
        [WriteOnly]
        public NativeQueue<int>.ParallelWriter Container;
        public void Execute() { }
    }

    [Test]
    [TestRequiresCollectionChecks]
    public void NativeQueue_ReadOnlyCannotScheduledForWrite()
    {
        var container = new NativeQueue<int>(CommonRwdAllocator.Handle);
        container.Enqueue(123);
        container.Enqueue(456);
        container.Enqueue(789);

        var ro = container.AsReadOnly();
        var job = new NativeQueueTestWriteMappedToReadOnly { Container = container.AsParallelWriter() }.Schedule();

        Assert.Throws<InvalidOperationException>(() => { _ = ro.Count; });
        Assert.Throws<InvalidOperationException>(() => { _ = ro[0]; });
        Assert.Throws<InvalidOperationException>(() => { _ = ro[1]; });
        Assert.Throws<InvalidOperationException>(() => { _ = ro[2]; });
        Assert.Throws<InvalidOperationException>(() => { foreach (var item in ro) { } });

        job.Complete();

        Assert.AreEqual(3, ro.Count);
        Assert.AreEqual(123, ro[0]);
        Assert.AreEqual(456, ro[1]);
        Assert.AreEqual(789, ro[2]);
        Assert.DoesNotThrow(() => { foreach (var item in ro) { } });

        container.Dispose();
    }

    [Test]
    public void NativeQueue_ReadOnlyForEach()
    {
        var container = new NativeQueue<int>(CommonRwdAllocator.Handle);
        container.Enqueue(123);
        container.Enqueue(456);
        container.Enqueue(789);

        var ro = container.AsReadOnly();

        var idx = 0;
        foreach (var item in ro)
        {
            Assert.AreEqual(item, ro[idx++]);
        }

        container.Dispose();
    }

    struct NativeQueue_ForEachIterator : IJob
    {
        [ReadOnly]
        public NativeQueue<int>.Enumerator Iter;

        public void Execute()
        {
            while (Iter.MoveNext())
            {
            }
        }
    }

    [Test]
    [TestRequiresCollectionChecks]
    public void NativeQueue_ForEach_Throws_Job_Iterator()
    {
        using (var container = new NativeQueue<int>(CommonRwdAllocator.Handle))
        {
            var jobHandle = new NativeQueue_ForEachIterator
            {
                Iter = container.AsReadOnly().GetEnumerator()

            }.Schedule();

            Assert.Throws<InvalidOperationException>(() => { container.Enqueue(987); });

            jobHandle.Complete();
        }
    }

    struct NativeQueueParallelWriteJob : IJobParallelFor
    {
        [WriteOnly]
        public NativeQueue<int>.ParallelWriter Writer;

        public void Execute(int index)
        {
            Writer.Enqueue(index);
        }
    }

    [Test]
    [TestRequiresCollectionChecks]
    public void NativeQueue_ForEach_Throws()
    {
        using (var container = new NativeQueue<int>(CommonRwdAllocator.Handle))
        {
            var iter = container.AsReadOnly().GetEnumerator();

            var jobHandle = new NativeQueueParallelWriteJob
            {
                Writer = container.AsParallelWriter()

            }.Schedule(1, 2);

            Assert.Throws<InvalidOperationException>(() =>
            {
                while (iter.MoveNext())
                {
                }
            });

            jobHandle.Complete();
        }
    }

    struct NativeQueue_ForEach_Job : IJob
    {
        public NativeQueue<int>.ReadOnly Input;

        public void Execute()
        {
            var index = 0;
            foreach (var value in Input)
            {
                Assert.AreEqual(value, Input[index++]);
            }
        }
    }

    [Test]
    public void NativeQueue_ForEach_From_Job([Values(10, 1000)] int n)
    {
        var seen = new NativeArray<int>(n, Allocator.Temp);
        using (var container = new NativeQueue<int>(CommonRwdAllocator.Handle))
        {
            for (int i = 0; i < n; i++)
            {
                container.Enqueue(i * 37);
            }

            new NativeQueue_ForEach_Job
            {
                Input = container.AsReadOnly(),

            }.Run();
        }
    }

    [Test]
    public void NativeQueue_ReadOnly_Count()
    {
        var queue1 = new NativeQueue<int>(Allocator.Temp);
        var queue2 = new NativeQueue<int>(Allocator.Temp);
        var queue3 = new NativeQueue<int>(Allocator.Temp);

        // Leave queue1 as empty

        // Make queue2 have two items, no dequeue.
        queue2.Enqueue(0);
        queue2.Enqueue(1);

        // Make queue3 have two items, enqueue 3 items and dequeue 1
        queue3.Enqueue(0);
        queue3.Enqueue(1);
        queue3.Enqueue(2);
        queue3.Dequeue();

        var ro1 = queue1.AsReadOnly();
        var ro2 = queue2.AsReadOnly();
        var ro3 = queue3.AsReadOnly();

        Assert.AreEqual(0, ro1.Count);
        Assert.AreEqual(2, ro2.Count);
        Assert.AreEqual(2, ro3.Count);

        // Dequeue everything in queue3 and make sure the new ReadOnly count is correct.
        queue3.Dequeue();
        queue3.Dequeue();
        ro3 = queue3.AsReadOnly();
        Assert.AreEqual(0, ro3.Count);
        queue3.Dispose();
        queue2.Dispose();
        queue1.Dispose();
    }

    [Test]
    public void NativeQueue_ReadOnly_Indexer()
    {
        var queue1 = new NativeQueue<int>(Allocator.Temp);
        var queue2 = new NativeQueue<int>(Allocator.Temp);
        var queue3 = new NativeQueue<int>(Allocator.Temp);

        // Leave queue1 as empty

        // Make queue2 have two items, no dequeue.
        queue2.Enqueue(0);
        queue2.Enqueue(1);

        // Make queue3 have two items, enqueue 3 items and dequeue 1
        queue3.Enqueue(0);
        queue3.Enqueue(1);
        queue3.Enqueue(2);
        queue3.Dequeue();

        var ro1 = queue1.AsReadOnly();
        var ro2 = queue2.AsReadOnly();
        var ro3 = queue3.AsReadOnly();

#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<IndexOutOfRangeException>(() => Assert.AreEqual(0, ro1[-1]));
        Assert.Throws<IndexOutOfRangeException>(() => Assert.AreEqual(0, ro1[0]));
        Assert.Throws<IndexOutOfRangeException>(() => Assert.AreEqual(0, ro2[-1]));
        Assert.Throws<IndexOutOfRangeException>(() => Assert.AreEqual(0, ro2[2]));
        Assert.Throws<IndexOutOfRangeException>(() => Assert.AreEqual(0, ro3[-1]));
        Assert.Throws<IndexOutOfRangeException>(() => Assert.AreEqual(0, ro3[2]));
#endif
        Assert.AreEqual(0, ro2[0]);
        Assert.AreEqual(1, ro2[1]);
        Assert.AreEqual(1, ro3[0]);
        Assert.AreEqual(2, ro3[1]);

        // Dequeue everything in queue3 and make sure that we generate an exception when using the indexer.
        queue3.Dequeue();
        queue3.Dequeue();
        ro3 = queue3.AsReadOnly();
#if ENABLE_UNITY_COLLECTIONS_CHECKS
        Assert.Throws<IndexOutOfRangeException>(() => Assert.AreEqual(0, ro3[-1]));
        Assert.Throws<IndexOutOfRangeException>(() => Assert.AreEqual(0, ro3[0]));
#endif
        Assert.AreEqual(0, ro3.Count);
        queue3.Dispose();
        queue2.Dispose();
        queue1.Dispose();
    }

    [Test]
    public void NativeQueue_ReadOnly_Indexer_Big()
    {
        // This test exercises the NativeQueue.ReadOnly indexer for a queue that has a lot of enqueues followed by dequeues.
        const int kEnqueueCount = 4096;
        var queue = new NativeQueue<int>(Allocator.Temp);

        for (int testIteration = 0; testIteration < 4; ++testIteration)
        {
            // Fill the queue.
            for (int i = 0; i < kEnqueueCount; ++i)
            {
                queue.Enqueue(i);
            }

            var ro = queue.AsReadOnly();
            int count = queue.Count;

            // Verify the queue via the ReadOnly indexer.
            for (int i = 0; i < count; ++i)
            {
                Assert.AreEqual(i, ro[i]);
            }

            // Remove some items then verify the queue again.
            const int kDequeueCount1 = 123;
            Assert.LessOrEqual(kDequeueCount1, kEnqueueCount);

            for (int i = 0; i < kDequeueCount1; ++i)
            {
                queue.Dequeue();
            }

            count = queue.Count;
            ro = queue.AsReadOnly();

            for (int i = 0; i < count; ++i)
            {
                Assert.AreEqual(i + kDequeueCount1, ro[i]);
            }

            // Then do it again.
            const int kDequeueCount2 = 400;
            Assert.LessOrEqual(kDequeueCount1 + kDequeueCount2, kEnqueueCount);

            for (int i = 0; i < kDequeueCount2; ++i)
            {
                queue.Dequeue();
            }

            count = queue.Count;
            ro = queue.AsReadOnly();

            for (int i = 0; i < count; ++i)
            {
                Assert.AreEqual(i + kDequeueCount1 + kDequeueCount2, ro[i]);
            }

            // And again.
            const int kDequeueCount3 = 3000;
            Assert.LessOrEqual(kDequeueCount1 + kDequeueCount2 + kDequeueCount3, kEnqueueCount);

            for (int i = 0; i < kDequeueCount3; ++i)
            {
                queue.Dequeue();
            }

            count = queue.Count;
            ro = queue.AsReadOnly();

            for (int i = 0; i < count; ++i)
            {
                Assert.AreEqual(i + kDequeueCount1 + kDequeueCount2 + kDequeueCount3, ro[i]);
            }

            // Drain the queue for the next iteration.
            while (!queue.IsEmpty())
            {
                queue.Dequeue();
            }
        }

        queue.Dispose();
    }

    [Test]
    public void NativeQueue_ReadOnly_Enumerator_MoveNext_EmptyQueue()
    {
        var queue = new NativeQueue<int>(Allocator.Temp);
        var enumerator = queue.AsReadOnly().GetEnumerator();
        Assert.IsFalse(enumerator.MoveNext());
        Assert.IsFalse(enumerator.MoveNext());
        Assert.IsFalse(enumerator.MoveNext());
        enumerator.Dispose();
        queue.Dispose();
    }

    [Test]
    public void NativeQueue_ReadOnly_Enumerator_MoveNext()
    {
        var queue = new NativeQueue<int>(Allocator.Temp);
        const int kCount = 10;

        for (int i = 0; i < kCount; ++i)
        {
            queue.Enqueue(i);
        }

        var enumerator = queue.AsReadOnly().GetEnumerator();
        int count = 0;

        while (enumerator.MoveNext())
        {
            Assert.AreEqual(count, enumerator.Current);
            ++count;
        }

        Assert.AreEqual(kCount, count);
        enumerator.Dispose();
        queue.Dispose();
    }

    [Test]
    public void NativeQueue_ReadOnly_Enumerator_MoveNext_WithDequeue()
    {
        var queue = new NativeQueue<int>(Allocator.Temp);
        const int kCount = 10;

        for (int i = 0; i < kCount; ++i)
        {
            queue.Enqueue(i);
        }

        queue.Dequeue();
        var enumerator = queue.AsReadOnly().GetEnumerator();
        int count = 0;

        while (enumerator.MoveNext())
        {
            Assert.AreEqual(count + 1, enumerator.Current);
            ++count;
        }

        Assert.AreEqual(kCount - 1, count);
        enumerator.Dispose();
        queue.Dispose();
    }

    [Test]
    public void NativeQueue_ReadOnly_Enumerator_Reset()
    {
        var queue = new NativeQueue<int>(Allocator.Temp);

        // Build some arbitrary queue that has been used.
        queue.Enqueue(0);
        queue.Enqueue(1);
        queue.Enqueue(2);
        queue.Dequeue();
        var enumerator = queue.AsReadOnly().GetEnumerator();
        int count = 0;

        // Discover the count via enumerator.
        while (enumerator.MoveNext())
        {
            ++count;
            Assert.AreEqual(count, enumerator.Current);
        }

        // Check count and reset for the next try.
        Assert.AreEqual(2, count);
        enumerator.Reset();
        count = 0;

        // Discover the count a second time, it should be the same.
        while (enumerator.MoveNext())
        {
            ++count;
            Assert.AreEqual(count, enumerator.Current);
        }

        Assert.AreEqual(2, count);
        enumerator.Dispose();
        queue.Dispose();
    }
}
