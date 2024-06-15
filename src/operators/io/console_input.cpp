#include "bigint.hpp"

std::istream &operator>>(std::istream &is, BigInt &bigInt) {
  std::string input;
  is >> input;
  bigInt = BigInt(input);
  return is;
}