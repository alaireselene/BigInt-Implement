#include "bigint.hpp"

std::ostream &operator<<(std::ostream &os, const BigInt &bigInt) {
  if (bigInt.isNegative) {
    os << '-';
  }
  for (int i = bigInt.digits.size() - 1; i >= 0; i--) {
    os << bigInt.digits[i];
  }
  return os;
}