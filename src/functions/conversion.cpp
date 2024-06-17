#include "bigint.hpp"

// Convert a BigInt to string
std::string BigInt::toString() const {
  std::string result;
  if (isNegative) {
    result.push_back('-');
  }
  for (digit d : digits) {
    result.push_back(d + '0');
  }
  return result;
}

// Convert a BigInt to an integer. If the BigInt is too large, throw an
// overflow exception
int BigInt::toInt() const {
  int result = 0;
  int digits_size = digits.size();
  for (int i = 0; i < digits_size; ++i) {
    if (result > (INT_MAX - digits.at(i)) / 10) {
      throw std::overflow_error("BigInt is too large to convert to int");
    } else
      result = result * 10 + digits.at(i);
  }
  return isNegative ? -result : result;
}

// Convert a BigInt to a long. If the BigInt is too large, throw an overflow
// exception
long BigInt::toLong() const {
  long result = 0;
  int digits_size = digits.size();
  for (auto i = 0; i < digits_size; ++i) {
    if (result > (LONG_MAX - digits.at(i)) / 10) {
      throw std::overflow_error("BigInt is too large to convert to long");
    } else
      result = result * 10 + digits.at(i);
  }
  return isNegative ? -result : result;
}

// Convert a BigInt to a long long. If the BigInt is too large, throw an
// overflow exception
long long BigInt::toLongLong() const {
  long long result = 0;
  int digits_size = digits.size();
  for (auto i = 0; i < digits_size; ++i) {
    if (result > (LLONG_MAX - digits.at(i)) / 10) {
      throw std::overflow_error("BigInt is too large to convert to long long");
    } else
      result = result * 10 + digits.at(i);
  }
  return isNegative ? -result : result;
}