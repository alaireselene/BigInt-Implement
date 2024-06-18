#include "bigint.hpp"
#include "gtest/gtest.h"

TEST(BigIntTest, Equality) {
  BigInt a = BigInt("123456789");
  BigInt b = BigInt("123456789");
  BigInt c = BigInt("987654321");

  ASSERT_TRUE(a == b);
  ASSERT_FALSE(a == c);
}

TEST(BigIntTest, Inequality) {
  BigInt a = BigInt("123456789");
  BigInt b = BigInt("987654321");

  ASSERT_TRUE(a != b);
}

TEST(BigIntTest, LessThan) {
  BigInt a = BigInt("123456789");
  BigInt b = BigInt("987654321");

  ASSERT_TRUE(a < b);
  ASSERT_FALSE(b < a);
}

TEST(BigIntTest, GreaterThan) {
  BigInt a = BigInt("123456789");
  BigInt b = BigInt("987654321");

  ASSERT_TRUE(b > a);
  ASSERT_FALSE(a > b);
}

TEST(BigIntTest, LessThanOrEqual) {
  BigInt a = BigInt("123456789");
  BigInt b = BigInt("987654321");
  BigInt c = BigInt("123456789");

  ASSERT_TRUE(a <= b);
  ASSERT_TRUE(a <= c);
  ASSERT_FALSE(b <= a);
}

TEST(BigIntTest, GreaterThanOrEqual) {
  BigInt a = BigInt("123456789");
  BigInt b = BigInt("987654321");
  BigInt c = BigInt("123456789");

  ASSERT_TRUE(b >= a);
  ASSERT_TRUE(c >= a);
  ASSERT_FALSE(a >= b);
}

TEST(BigIntTest, EqualityWithLongLong) {
  BigInt a = BigInt("123456789");
  long long b = 123456789;

  ASSERT_TRUE(a == b);
}

TEST(BigIntTest, InequalityWithLongLong) {
  BigInt a = BigInt("123456789");
  long long b = 987654321;

  ASSERT_TRUE(a != b);
}

TEST(BigIntTest, LessThanWithLongLong) {
  BigInt a = BigInt("123456789");
  long long b = 987654321;

  ASSERT_TRUE(a < b);
}

TEST(BigIntTest, EqualityWithString) {
  BigInt a = BigInt("123456789");
  std::string b = "123456789";

  ASSERT_TRUE(a == b);
}

TEST(BigIntTest, InequalityWithString) {
  BigInt a = BigInt("123456789");
  std::string b = "987654321";

  ASSERT_TRUE(a != b);
}

TEST(BigIntTest, LessThanWithString) {
  BigInt a = BigInt("123456789");
  std::string b = "987654321";

  ASSERT_TRUE(a < b);
}