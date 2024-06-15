#include "bigint.hpp"

BigInt BigInt::operator%(const BigInt &other) const {
  std::vector<long long> result =
      divideWithRemainder(this->digits, other.digits).second;
  return BigInt(result, isNegative == other.isNegative ? false : true);
}