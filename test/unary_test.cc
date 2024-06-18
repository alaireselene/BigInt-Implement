#include "bigint.hpp"
#include "gtest/gtest.h"

TEST(BigIntTest, UnaryMinus) {
  BigInt a = BigInt("123456789");
  BigInt b = -a;

  ASSERT_TRUE(b == BigInt("-123456789"));
}

TEST(BigIntTest, UnaryPlus) {
  BigInt a = BigInt("123456789");
  BigInt b = +a;

  ASSERT_TRUE(b == BigInt("123456789"));
}