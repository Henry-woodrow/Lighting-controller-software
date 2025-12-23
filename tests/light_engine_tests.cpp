#include <gtest/gtest.h>
#include "light_engine.h"

TEST(LightEngine, TickIncrements)
{
    LightEngine e;
    ASSERT_EQ(e.getTickCount(), 0u);
    e.tick();
    ASSERT_EQ(e.getTickCount(), 1u);
}
