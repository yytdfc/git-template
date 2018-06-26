#include <iostream>
#include <gtest/gtest.h>
TEST(example, example) {
  EXPECT_GE(2, 2);
  EXPECT_GT(3, 2);
  EXPECT_LE(1, 2);
  EXPECT_LT(1, 2);
  EXPECT_EQ(2, 2);
  EXPECT_NE(0, 2);
}
