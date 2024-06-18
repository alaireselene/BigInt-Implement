#include "bigint.hpp"
#include "gtest/gtest.h"

TEST(BigIntTest, AssignmentOperator) {
  BigInt a = BigInt("123456789");
  BigInt b;
  b = a;

  ASSERT_TRUE(b == BigInt("123456789"));
}

TEST(BigIntTest, SelfAssignment) {
  BigInt a = BigInt("123456789");
  a = a;

  ASSERT_TRUE(a == BigInt("123456789"));
}

TEST(BigIntTest, ChainAssignment) {
  BigInt a = BigInt("123456789");
  BigInt b, c;
  c = b = a;

  ASSERT_TRUE(b == BigInt("123456789"));
  ASSERT_TRUE(c == BigInt("123456789"));
}