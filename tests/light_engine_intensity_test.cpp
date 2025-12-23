#include <gtest/gtest.h>
#include "light_engine.h"

TEST(LightEngineIntensity, ClampsBelowZeroToZero)
{
    LightEngine engine;
    engine.setIntensity(-1.0f);
    EXPECT_FLOAT_EQ(engine.getIntensity(), 0.0f);
}

TEST(LightEngineIntensity, ClampsAboveOneToOne)
{
    LightEngine engine;
    engine.setIntensity(1.2f);
    EXPECT_FLOAT_EQ(engine.getIntensity(), 1.0f);
}

TEST(LightEngineIntensity, StoresMidRangeValueWithinTolerance)
{
    LightEngine engine;
    engine.setIntensity(0.5f);

    // Either of these are acceptable; pick one style and keep it consistent.
    EXPECT_NEAR(engine.getIntensity(), 0.5f, 1e-6f);
    // or: EXPECT_FLOAT_EQ(engine.getIntensity(), 0.5f);
}
