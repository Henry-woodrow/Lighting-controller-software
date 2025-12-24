#include <gtest/gtest.h>
#include "light_engine.h"
#include <cstdint>

// Helper: makes it explicit we are reading DMX channel 1.
static uint8_t Ch1(const LightEngine& e)
{
    return e.getChannel(1);
}

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



TEST(LightEngineDmxMapping, IntensityZeroMapsToDmxZeroOnChannel1)
{
    LightEngine engine;

    engine.setIntensity(0.0f);
    engine.tick();

    EXPECT_EQ(Ch1(engine), static_cast<uint8_t>(0));
}

TEST(LightEngineDmxMapping, IntensityOneMapsToDmx255OnChannel1)
{
    LightEngine engine;

    engine.setIntensity(1.0f);
    engine.tick();

    EXPECT_EQ(Ch1(engine), static_cast<uint8_t>(255));
}

TEST(LightEngineDmxMapping, IntensityHalfMapsToApproximately127or128OnChannel1)
{
    LightEngine engine;

    engine.setIntensity(0.5f);
    engine.tick();

    const uint8_t v = Ch1(engine);
    EXPECT_TRUE(v == 127 || v == 128);
}

TEST(LightEngineDmxMapping, Channel1UpdatesWhenIntensityChangesOverTime)
{
    LightEngine engine;

    engine.setIntensity(0.0f);
    engine.tick();
    EXPECT_EQ(Ch1(engine), 0);

    engine.setIntensity(0.25f);
    engine.tick();
    // 0.25 * 255 = 63.75 -> static_cast<uint8_t> truncates -> 63
    EXPECT_EQ(Ch1(engine), static_cast<uint8_t>(63));

    engine.setIntensity(0.75f);
    engine.tick();
    // 0.75 * 255 = 191.25 -> truncates -> 191
    EXPECT_EQ(Ch1(engine), static_cast<uint8_t>(191));

    engine.setIntensity(1.0f);
    engine.tick();
    EXPECT_EQ(Ch1(engine), 255);
}

TEST(LightEngineDmxMapping, NoDmxWriteOccursOutsideTick)
{
    LightEngine engine;

    // Given: channel starts at 0 (universe init to zero)
    EXPECT_EQ(Ch1(engine), 0);

    // When: intensity changes but tick is NOT called
    engine.setIntensity(1.0f);

    // Then: channel output must remain unchanged until tick
    EXPECT_EQ(Ch1(engine), 0);

    // When: tick is called
    engine.tick();

    // Then: channel reflects intensity
    EXPECT_EQ(Ch1(engine), 255);
}
