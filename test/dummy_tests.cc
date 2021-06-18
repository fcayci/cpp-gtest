#include <gtest/gtest.h>

TEST(Dummy, SumPass)
{
    EXPECT_EQ(2, 1 + 1);
}

TEST(Dummy, SumFail)
{
    ASSERT_EQ(3, 1 + 1);
}
