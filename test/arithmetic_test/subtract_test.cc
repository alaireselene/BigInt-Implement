#include "bigint.h"
#include <gtest/gtest.h>

TEST(Subtract, TwoPositiveString) {
    BigInt a("123456789");
    BigInt b("987654321");
    BigInt diff = a - b;
    EXPECT_EQ(diff.toString(), "-864197532");
}

TEST(Subtract, TwoNegativeString) {
    BigInt a("-123456789");
    BigInt b("-987654321");
    BigInt diff = a - b;
    EXPECT_EQ(diff.toString(), "864197532");
}

TEST(Subtract, PositiveAndNegativeString) {
    BigInt a("123456789");
    BigInt b("-987654321");
    BigInt diff = a - b;
    EXPECT_EQ(diff.toString(), "1111111110");
}

TEST(Subtract, TwoPositiveInt) {
    BigInt a(1234567890);
    BigInt b(9876543210);
    BigInt diff = a - b;
    EXPECT_EQ(diff.toString(), "-8641975320");
}

TEST(Subtract, TwoNegativeInt) {
    BigInt a(-1234567890);
    BigInt b(-9876543210);
    BigInt diff = a - b;
    EXPECT_EQ(diff.toString(), "8641975320");
}

TEST(Subtract, PositiveAndNegativeInt) {
    BigInt a(123456789);
    BigInt b(-987654321);
    BigInt diff = a - b;
    EXPECT_EQ(diff.toString(), "1111111110");
}
