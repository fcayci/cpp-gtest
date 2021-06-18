#include <gtest/gtest.h>

#include "duck.h"

struct DuckTest : ::testing::Test
{
    Duck* duck;
    DuckTest()
    {
        duck = new Duck;
    }

    ~DuckTest()
    {
        delete duck;
    }
};

TEST_F(DuckTest, DuckLegTest)
{
    EXPECT_EQ(2, duck->legs);
}

TEST_F(DuckTest, DuckWingTest)
{
    EXPECT_EQ(2, duck->wings);
}