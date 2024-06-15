#include "bigint.hpp"
#include <vector>

BigInt BigInt::operator*(const BigInt &other) const {
  std::vector<long long> result = multiply(digits, other.digits);
  return BigInt(result, isNegative == other.isNegative ? false : true);
}