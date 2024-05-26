#include "bigint.h"
#include <exception>
#include <stdexcept>

BigInt BigInt::operator/(const BigInt &other) const
{
    BigInt quotient;
    BigInt remainder;

    // Check for division by zero
    if (other == BigInt(0))
    {
        throw std::invalid_argument("Division by zero");
    }
    return quotient;
}