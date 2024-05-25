#include "bigint.h"
#include <vector>
#include <iostream>

BigInt BigInt::operator*(const BigInt &other) const
{
    BigInt result;
    for (int i = 0; i < other.digits.size(); ++i)
    {
        BigInt partial;
        if (i == 0)
        {
            // Remove default '0' digit
            partial.rightShift(1);
        }
        else
        {
            partial.leftShift(i - 1);
        }
        int carry = 0;
        for (int j = 0; j < digits.size() || carry > 0; ++j)
        {
            long long int product = carry;
            if (j < digits.size())
            {
                product += digits[j] * other.digits[i];
            }
            partial.digits.push_back(product % 10);
            carry = product / 10;
        }
        result += partial;
    }
    result.isNegative = isNegative != other.isNegative;
    result.zeroTrim();
    return result;
}