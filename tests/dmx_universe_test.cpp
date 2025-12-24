#include <gtest/gtest.h>
#include "dmx.h"

TEST(DmxUniverse, InitializesChannelsToZero)
{
    DmxUniverse u;
    EXPECT_EQ(u.get(1), 0);
    EXPECT_EQ(u.get(512), 0);
    EXPECT_EQ(u.get(100), 0);
}

TEST(DmxUniverse, SetThenGetReturnsStoredValue)
{
    DmxUniverse u;
    u.set(1, 123);
    u.set(512, 255);

    EXPECT_EQ(u.get(1), 123);
    EXPECT_EQ(u.get(512), 255);
}

TEST(DmxUniverse, OutOfRangeGetReturnsZero)
{
    DmxUniverse u;
    EXPECT_EQ(u.get(0), 0);
    EXPECT_EQ(u.get(513), 0);
    EXPECT_EQ(u.get(-10), 0);
}

TEST(DmxUniverse, OutOfRangeSetIsIgnoredSafely)
{
    DmxUniverse u;
    u.set(1, 10);

    u.set(0, 200);
    u.set(513, 200);
    u.set(-5, 200);

    // Must remain unchanged
    EXPECT_EQ(u.get(1), 10);
    EXPECT_EQ(u.get(0), 0);
    EXPECT_EQ(u.get(513), 0);
}
