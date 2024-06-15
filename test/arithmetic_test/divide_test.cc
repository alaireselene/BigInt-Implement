#include "bigint.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(Divide, Zero) {
  BigInt a(0);
  BigInt b(0);
  EXPECT_THROW(a / b, std::logic_error);
}

TEST(Divide, One) {
  BigInt a(1);
  BigInt b(1);
  EXPECT_EQ(a / b, BigInt(1));
}

TEST(Divide, NegativeOne) {
  BigInt a(-1);
  BigInt b(-1);
  EXPECT_EQ(a / b, BigInt(1));
}

TEST(Divide, Equal) {
  BigInt a(123456789);
  BigInt b(123456789);
  EXPECT_EQ(a / b, BigInt(1));
}

TEST(Divide, Greater) {
  BigInt a(123456789);
  BigInt b(987654321);
  EXPECT_EQ(a / b, BigInt(0));
}

TEST(Divide, Less) {
  BigInt a(987654321);
  BigInt b(123456789);
  EXPECT_EQ(a / b, BigInt(8));
}

TEST(Divide, Negative) {
  BigInt a(-987654321);
  BigInt b(123456789);
  EXPECT_EQ(a / b, BigInt(-8));
}

TEST(Divide, NegativeRemainder) {
  BigInt a(-987654321);
  BigInt b(-123456789);
  EXPECT_EQ(a / b, BigInt(8));
}

TEST(Divide, Extra) {
  BigInt a(14192);
  BigInt b(25);
  EXPECT_EQ(a / b, BigInt(int(14192 / 25)));
}