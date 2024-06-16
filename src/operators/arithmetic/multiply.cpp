#include "bigint.hpp"
#include <deque>

BigInt BigInt::operator*(const BigInt &other) const {
  std::deque<digit> result = multiply(digits, other.digits);
  return BigInt(result, isNegative == other.isNegative ? false : true);
}