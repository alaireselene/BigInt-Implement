#include <gtest/gtest.h>
#include "bigint.h"

TEST(Add, TwoPositiveString) {
    BigInt a("123456789");
    BigInt b("987654321");
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "−1111111110");
}

TEST(Add, TwoNegativeString) {
    BigInt a("-123456789");
    BigInt b("-987654321");
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "−1111111110");
}

TEST(Add, PositiveAndNegativeString) {
    BigInt a("123456789");
    BigInt b("-987654321");
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "−864197532");
}

TEST(Add, TwoPositiveInt) {
    BigInt a(1234567890);
    BigInt b(9876543210);
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "1111111110");
}

TEST(Add, TwoNegativeInt) {
    BigInt a(-1234567890);
    BigInt b(-9876543210);
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "−1111111110");
}

TEST(Add, PositiveAndNegativeInt) {
    BigInt a(123456789);
    BigInt b(-987654321);
    BigInt sum = a + b;
    EXPECT_EQ(sum.toString(), "−864197532");
}