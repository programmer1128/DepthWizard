using NUnit.Framework;
using Unity.Collections;
using Unity.Collections.Tests;
using UnityEngine;

internal class HashUtilitiesTests : CollectionsTestCommonBase
{
    [Test]
    [TestCase("", "1909f56bfc062723c751e8b465ee728b", Ignore = "HashUtilities.cs does not handle empty arrays")]
    [TestCase("The quick brown fox jumps over the lazy dog", "c79306aa46e8122b1b340724747e361d", Ignore = "SpookyHash.cs has a bug with ushort & wrong goto case, see comments there")]
    [TestCase("some test string", "4427b2b382b00395c6b8acfbe7b76c9e")]
    //[TestCase("The quick brown fox jumps over the lazy dog The quick brown fox jumps over the lazy dog The quick brown fox jumps over the lazy dog The quick brown fox jumps over the lazy dog The quick brown fox jumps over the lazy dog", "e739afc56a1cb7f1499cd20da66393b6")]
    public unsafe void ComputeHash128_ReturnsCorrectSpookyHashV2Results(string data, string expected)
    {
        var hash = new Hash128();

        SpookyHashV2.ComputeHash128(new FixedString512Bytes(data), &hash);

        Assert.That(hash.ToString(), Is.EqualTo(expected));
    }
}
