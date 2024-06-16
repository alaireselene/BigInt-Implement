#include "bigint.hpp"

BigInt BigInt::operator+() const { return *this; }

BigInt BigInt::operator-() const {
  BigInt result = *this;
  result.isNegative = !result.isNegative;
  return result;
}

BigInt BigInt::operator++(int) {
  *this += BigInt(1);
  return *this;
}

BigInt BigInt::operator--(int) {
  *this -= BigInt(1);
  return *this;
}