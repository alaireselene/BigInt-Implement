#include "bigint.h"

bool BigInt::operator==(const BigInt &other) const
{
    if (digits.size() != other.digits.size() || isNegative != other.isNegative)
    {
        return false;
    }

    for (size_t i = 0; i < digits.size(); i++)
    {
        if (digits[i] != other.digits[i])
        {
            return false;
        }
    }

    return true;
}