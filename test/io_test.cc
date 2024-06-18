#include "bigint.hpp"
#include <gtest/gtest.h>

TEST(BigIntTest, OutputStreamOperator) {
  BigInt a = BigInt("123456789");
  std::ostringstream oss;
  oss << a;

  ASSERT_EQ(oss.str(), "123456789");
}

TEST(BigIntTest, InputStreamOperator) {
  BigInt a;
  std::istringstream iss("123456789");
  iss >> a;

  ASSERT_TRUE(a == BigInt("123456789"));
}

TEST(BigIntTest, InputStreamOperatorWithInvalidInput) {
  BigInt a;
  std::istringstream iss("123abc456");
  EXPECT_THROW(iss >> a, std::invalid_argument);
}