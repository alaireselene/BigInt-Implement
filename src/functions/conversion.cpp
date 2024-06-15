#include "bigint.hpp"
#include <fstream>

// Convert a BigInt to string
std::string BigInt::toString() const {
  std::string result;
  if (isNegative) {
    result.push_back('-');
  }
  for (int i = digits.size() - 1; i >= 0; --i) {
    result.push_back(digits[i] + '0');
  }
  return result;
}

// Convert a BigInt to an integer
int BigInt::toInt() const {
  int result = 0;
  for (int i = digits.size() - 1; i >= 0; --i) {
    result = result * 10 + digits[i];
  }
  return isNegative ? -result : result;
}

// Convert a BigInt to a long
long BigInt::toLong() const {
  long result = 0;
  for (int i = digits.size() - 1; i >= 0; --i) {
    result = result * 10 + digits[i];
  }
  return isNegative ? -result : result;
}

// Convert a BigInt to a long long
long long BigInt::toLongLong() const {
  long long result = 0;
  for (int i = digits.size() - 1; i >= 0; --i) {
    result = result * 10 + digits[i];
  }
  return isNegative ? -result : result;
}

void BigInt::toFile(const std::string &filename) const {
  std::ofstream file(filename);
  if (file.is_open()) {
    file << toString();
    file.close();
  } else {
    std::cerr << "Error: Unable to open file " << filename << std::endl;
  }
}