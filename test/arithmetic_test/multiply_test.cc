#include "bigint.h"
#include <gtest/gtest.h>

TEST(Multiply, TwoPositiveString) {
    BigInt a("123456789");
    BigInt b("987654321");
    BigInt product = a * b;
    EXPECT_EQ(product.toString(), "121932631112635269");
}

TEST(Multiply, Simple) {
    BigInt a(100);
    BigInt b(11);
    BigInt product = a * b;
    EXPECT_EQ(product.toString(), "1100");
}

TEST(Multiply, TwoNegativeString) {
    BigInt a("-123456789");
    BigInt b("-987654321");
    BigInt product = a * b;
    EXPECT_EQ(product.toString(), "121932631112635269");
}

TEST(Multiply, PositiveAndNegativeString) {
    BigInt a("123456789");
    BigInt b("-987654321");
    BigInt product = a * b;
    EXPECT_EQ(product.toString(), "-121932631112635269");
}

TEST(Multiply, TwoPositiveInt) {
    BigInt a(1234567890);
    BigInt b(9876543210);
    BigInt product = a * b;
    EXPECT_EQ(product.toString(), "12193263111263526900");
}

TEST(Multiply, TwoNegativeInt) {
    BigInt a(-1234567890);
    BigInt b(-9876543210);
    BigInt product = a * b;
    EXPECT_EQ(product.toString(), "12193263111263526900");
}

TEST(Multiply, PositiveAndNegativeInt) {
    BigInt a(123456789);
    BigInt b(-987654321);
    BigInt product = a * b;
    EXPECT_EQ(product.toString(), "-121932631112635269");
}

TEST(Multiply, Zero) {
    BigInt a(0);
    BigInt b(123456789);
    BigInt product = a * b;
    EXPECT_EQ(product.toString(), "0");
}

TEST(Multiply, LargeNumber) {
    BigInt a("123456789123456789123456789123456789");
    BigInt b("987654321987654321987654321987654321");
    BigInt product = a * b;
    EXPECT_EQ(product.toString(), "121932631112635269121932631112635269121932631112635269121932631112635269");
}
