#include "bigint.h"

BigInt BigInt::operator-(const BigInt& other) const {
    BigInt result;
    
    if (isNegative != other.isNegative) {
        result.digits = add(digits, other.digits);
        result.isNegative = isNegative;
    } else {
        result.digits = subtract(max(digits, other.digits), min(digits, other.digits));
        if (max(digits, other.digits) == digits) {
            result.isNegative = isNegative;
        } else {
            result.isNegative = !(other.isNegative);
        }
    }
    result.zeroTrim();
    return result;
}