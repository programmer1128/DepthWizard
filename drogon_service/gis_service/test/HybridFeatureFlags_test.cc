#include <gtest/gtest.h>
#include "structures/HybridFeatureFlags.h"
#include "MeshMapping/MeshBuildConfig.h"
#include "MeshMapping/PresentationStyle.h"
#include "MeshMapping/SceneMeshService.h"
#include "BuildingReconstructionTestSupport.h"

#include <cstdlib>
#include <string>

namespace
{

class EnvScope
{
public:
    EnvScope(const char* name, const char* value) : name_(name)
    {
        const char* oldVal = std::getenv(name);
        if (oldVal)
        {
            hasOldVal_ = true;
            oldVal_ = oldVal;
        }
        if (value)
        {
            setenv(name, value, 1);
        }
        else
        {
            unsetenv(name);
        }
    }

    ~EnvScope()
    {
        if (hasOldVal_)
        {
            setenv(name_.c_str(), oldVal_.c_str(), 1);
        }
        else
        {
            unsetenv(name_.c_str());
        }
    }

private:
    std::string name_;
    bool hasOldVal_{false};
    std::string oldVal_;
};

} // namespace

TEST(HybridFeatureFlagsTest, DefaultsAreAllDisabledAndScientific)
{
    EnvScope s1("DEPTHWIZARD_PRESENTATION_STYLE", nullptr);
    EnvScope s2("DEPTHWIZARD_SAM2", nullptr);
    EnvScope s3("DEPTHWIZARD_KIBS", nullptr);
    EnvScope s4("DEPTHWIZARD_HYBRID_FUSION", nullptr);

    const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
    EXPECT_EQ(flags.presentationStyle, depthwizard::PresentationStyle::SCIENTIFIC);
    EXPECT_STREQ(depthwizard::toString(flags.presentationStyle), "scientific");
    EXPECT_FALSE(flags.enableSam2);
    EXPECT_FALSE(flags.enableKibs);
    EXPECT_FALSE(flags.enableHybridFusion);

    MeshBuildConfig config;
    EXPECT_EQ(config.presentationStyle, depthwizard::PresentationStyle::SCIENTIFIC);
}

TEST(HybridFeatureFlagsTest, ParsesPresentationStyles)
{
    {
        EnvScope s("DEPTHWIZARD_PRESENTATION_STYLE", "terra");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_EQ(flags.presentationStyle, depthwizard::PresentationStyle::TERRA_MASSING);
        EXPECT_STREQ(depthwizard::toString(flags.presentationStyle), "terra");
    }
    {
        EnvScope s("DEPTHWIZARD_PRESENTATION_STYLE", "orthophoto");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_EQ(flags.presentationStyle, depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC);
        EXPECT_STREQ(depthwizard::toString(flags.presentationStyle), "orthophoto");
    }
    {
        EnvScope s("DEPTHWIZARD_PRESENTATION_STYLE", "scientific");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_EQ(flags.presentationStyle, depthwizard::PresentationStyle::SCIENTIFIC);
        EXPECT_STREQ(depthwizard::toString(flags.presentationStyle), "scientific");
    }
    {
        EnvScope s("DEPTHWIZARD_PRESENTATION_STYLE", "unknown_mode");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_EQ(flags.presentationStyle, depthwizard::PresentationStyle::SCIENTIFIC);
    }
}

TEST(HybridFeatureFlagsTest, ParsesSam2Flags)
{
    {
        EnvScope s("DEPTHWIZARD_SAM2", "1");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_TRUE(flags.enableSam2);
    }
    {
        EnvScope s("DEPTHWIZARD_SAM2", "0");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_FALSE(flags.enableSam2);
    }
    {
        EnvScope s("DEPTHWIZARD_SAM2", "true");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_TRUE(flags.enableSam2);
    }
    {
        EnvScope s("DEPTHWIZARD_SAM2", "false");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_FALSE(flags.enableSam2);
    }
}

TEST(HybridFeatureFlagsTest, ParsesKibsFlags)
{
    {
        EnvScope s("DEPTHWIZARD_KIBS", "1");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_TRUE(flags.enableKibs);
    }
    {
        EnvScope s("DEPTHWIZARD_KIBS", "0");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_FALSE(flags.enableKibs);
    }
    {
        EnvScope s("DEPTHWIZARD_KIBS", "true");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_TRUE(flags.enableKibs);
    }
}

TEST(HybridFeatureFlagsTest, ParsesHybridFusionFlags)
{
    {
        EnvScope s("DEPTHWIZARD_HYBRID_FUSION", "1");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_TRUE(flags.enableHybridFusion);
    }
    {
        EnvScope s("DEPTHWIZARD_HYBRID_FUSION", "0");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_FALSE(flags.enableHybridFusion);
    }
    {
        EnvScope s("DEPTHWIZARD_HYBRID_FUSION", "true");
        const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
        EXPECT_TRUE(flags.enableHybridFusion);
    }
}

TEST(HybridFeatureFlagsTest, FlagsOffPreservesByteIdenticalOutput)
{
    EnvScope s1("DEPTHWIZARD_PRESENTATION_STYLE", "0");
    EnvScope s2("DEPTHWIZARD_SAM2", "0");
    EnvScope s3("DEPTHWIZARD_KIBS", "0");
    EnvScope s4("DEPTHWIZARD_HYBRID_FUSION", "0");

    const auto flags = depthwizard::HybridFeatureFlags::loadFromEnvironment();
    EXPECT_EQ(flags.presentationStyle, depthwizard::PresentationStyle::SCIENTIFIC);
    EXPECT_FALSE(flags.enableSam2);
    EXPECT_FALSE(flags.enableKibs);
    EXPECT_FALSE(flags.enableHybridFusion);
}

