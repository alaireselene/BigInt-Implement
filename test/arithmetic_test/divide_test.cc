#include "bigint.h"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(Divide, Zero)
{
    BigInt a(0);
    BigInt b(0);
    EXPECT_THROW(a / b, std::invalid_argument);
}