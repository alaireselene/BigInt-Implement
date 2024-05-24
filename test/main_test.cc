#include <gtest/gtest.h>
#include "bigint.h"

TEST (NumberIntegrity, PositiveString) {
    BigInt b("987654321098765432109876543210");
    EXPECT_EQ(b.toString(), "987654321098765432109876543210");
}

TEST (NumberIntegrity, NegativeString) {
    BigInt b("-987654321098765432109876543210");
    EXPECT_EQ(b.toString(), "-987654321098765432109876543210");
}

TEST (NumberIntegrity, PositiveInt) {
    BigInt b(987654321);
    EXPECT_EQ(b.toString(), "987654321");
}

TEST (NumberIntegrity, NegativeInt) {
    BigInt b(-987654321);
    EXPECT_EQ(b.toString(), "-987654321");
}