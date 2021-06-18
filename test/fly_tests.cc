#include <gtest/gtest.h>

#include "duck.h"

struct FlyTest : ::testing::Test
{
    Fly* fly;
    FlyTest()
    {
        fly = new Fly;
    }

    ~FlyTest()
    {
        delete fly;
    }
};

TEST_F(FlyTest, FlySpeedTest)
{
    /* initial */
    EXPECT_EQ(2, fly->getSpeed().first);
    EXPECT_EQ(3, fly->getSpeed().second);

    fly->setSpeed(4, 5);
    EXPECT_EQ(4, fly->getSpeed().first);
    EXPECT_EQ(5, fly->getSpeed().second);

    /* should not change speed */
    fly->setSpeed(-12, 12);
    EXPECT_EQ(4, fly->getSpeed().first);
    EXPECT_EQ(5, fly->getSpeed().second);
}

TEST_F(FlyTest, FlyHeightTest)
{
    /* initial */
    EXPECT_DOUBLE_EQ(0.0, fly->getHeight());

    fly->setHeight(4.6);
    EXPECT_DOUBLE_EQ(4.6, fly->getHeight());

    fly->setHeight(0);
    EXPECT_DOUBLE_EQ(0, fly->getHeight());

    fly->setHeight(3);
    EXPECT_DOUBLE_EQ(3, fly->getHeight());

    fly->setHeight(18.2);
    EXPECT_DOUBLE_EQ(18.2, fly->getHeight());

    /* should not change height */
    fly->setHeight(-14.6);
    EXPECT_DOUBLE_EQ(18.2, fly->getHeight());
}
