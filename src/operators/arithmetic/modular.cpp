#include "bigint.hpp"

BigInt BigInt::operator%(const BigInt &other) const {
  std::deque<digit> result =
      divideWithRemainder(this->digits, other.digits).second;
  return BigInt(result, isNegative == other.isNegative ? false : true);
}