#include <gtest/gtest.h>
#include "dmx.h"   // or "universe.h" if that's what you actually have

TEST(DmxUniverse, SetGetRoundTrip)
{
    DmxUniverse u;          // or whatever your class is actually called
    u.set(1, 123);
    ASSERT_EQ(u.get(1), 123);
}
