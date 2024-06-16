#include "bigint.hpp"

BigInt BigInt::operator-(const BigInt &other) const {
  BigInt result;

  if (isNegative != other.isNegative) {
    result.digits = add(digits, other.digits);
    result.isNegative = isNegative;
  } else {
    if (greater(digits, other.digits)) {
      result.digits = subtract(digits, other.digits);
      result.isNegative = isNegative;
    } else {
      result.digits = subtract(other.digits, digits);
      result.isNegative = !(other.isNegative);
    }
  }
  return result;
}