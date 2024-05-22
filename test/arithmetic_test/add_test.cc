#include <gtest/gtest.h>
#include "bigint.h"

TEST(Add, TwoPositiveString) {
    BigInt a("123456789012345678901234567890");
    BigInt b("987654321098765432109876543210");
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "1111111110111111111011111111100");
}

TEST(Add, TwoNegativeString) {
    BigInt a("-123456789012345678901234567890");
    BigInt b("-987654321098765432109876543210");
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "-1111111110111111111011111111100");
}

TEST(Add, PositiveAndNegativeString) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-987654321098765432109876543210");
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "-864197532086419753208641975320");
}

TEST(Add, TwoPositiveInt) {
    BigInt a(1234567890);
    BigInt b(9876543210);
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "11111111100");
}

TEST(Add, TwoNegativeInt) {
    BigInt a(-1234567890);
    BigInt b(-9876543210);
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "-11111111100");
}

TEST(Add, PositiveAndNegativeInt) {
    BigInt a(1234567890);
    BigInt b(-9876543210);
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "-8641975320");
}