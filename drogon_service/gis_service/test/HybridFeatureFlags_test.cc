#include <gtest/gtest.h>
#include "utils/FeatureFlags.h"
#include "MeshMapping/MeshBuildConfig.h"

#include <cstdlib>
#include <string>

// HybridFeatureFlags::fromEnvironment reads the process environment; the
// parsing rules themselves are covered in BaselineHarness_test.cc.
namespace
{

class EnvScope
{
public:
    EnvScope(const char* name, const char* value) : name_(name)
    {
        if (const char* old = std::getenv(name))
        {
            hadOld_ = true;
            old_ = old;
        }
        if (value) setenv(name, value, 1);
        else unsetenv(name);
    }
    ~EnvScope()
    {
        if (hadOld_) setenv(name_.c_str(), old_.c_str(), 1);
        else unsetenv(name_.c_str());
    }

private:
    std::string name_;
    bool hadOld_{false};
    std::string old_;
};

} // namespace

TEST(HybridFeatureFlagsEnvironmentTest, UnsetEnvironmentIsTheScientificDefault)
{
    EnvScope style("DEPTHWIZARD_PRESENTATION_STYLE", nullptr);
    EnvScope neutral("DEPTHWIZARD_NEUTRAL_FACADES", nullptr);
    EnvScope sam2("DEPTHWIZARD_SAM2", nullptr);
    EnvScope kibs("DEPTHWIZARD_KIBS", nullptr);
    EnvScope fusion("DEPTHWIZARD_HYBRID_FUSION", nullptr);

    const HybridFeatureFlags flags = HybridFeatureFlags::fromEnvironment();
    EXPECT_TRUE(flags.allDefault());
    EXPECT_TRUE(flags.warnings.empty());
    EXPECT_EQ(MeshBuildConfig().presentationStyle, flags.presentationStyle);
    EXPECT_FALSE(MeshBuildConfig().neutralFacades);
}

TEST(HybridFeatureFlagsEnvironmentTest, ReadsEveryVariable)
{
    EnvScope style("DEPTHWIZARD_PRESENTATION_STYLE", "orthophoto");
    EnvScope neutral("DEPTHWIZARD_NEUTRAL_FACADES", "1");
    EnvScope sam2("DEPTHWIZARD_SAM2", "1");
    EnvScope kibs("DEPTHWIZARD_KIBS", "0");
    EnvScope fusion("DEPTHWIZARD_HYBRID_FUSION", "bogus");

    const HybridFeatureFlags flags = HybridFeatureFlags::fromEnvironment();
    EXPECT_EQ(flags.presentationStyle, depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC);
    EXPECT_TRUE(flags.neutralFacades);
    EXPECT_TRUE(flags.sam2);
    EXPECT_FALSE(flags.kibs);
    EXPECT_FALSE(flags.hybridFusion);
    ASSERT_EQ(flags.warnings.size(), 1U);
    EXPECT_NE(flags.warnings[0].find("DEPTHWIZARD_HYBRID_FUSION"), std::string::npos);
}
