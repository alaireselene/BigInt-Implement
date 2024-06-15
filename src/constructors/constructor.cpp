#include "bigint.hpp"

// Default constructor
BigInt::BigInt() : digits({0}), isNegative(false) {}

// Copy constructor
BigInt::BigInt(const BigInt &num) {
  digits = num.digits;
  isNegative = num.isNegative;
}
// Integer to BigInt
BigInt::BigInt(long long int value) {
  isNegative = false;
  if (value == 0) {
    digits.push_back(0);
  } else {
    if (value < 0) {
      value = -value;
      isNegative = true;
    }
    while (value > 0) {
      digits.push_back(value % 10);
      value /= 10;
    }
  }
}

// Vector of digits and sign to BigInt
BigInt::BigInt(const std::vector<long long> &digits, bool isNegative)
    : digits(digits), isNegative(isNegative) {
  if (digits.size() == 0) {
    this->digits.push_back(0);
    this->isNegative = false;
  }
}

// String to BigInt
BigInt::BigInt(const std::string &str) {
  if (str.empty()) {
    digits.push_back(0);
    isNegative = false;
    return;
  } else {
    int start = 0;
    if (str[0] == '-') {
      isNegative = true;
      start = 1;
    } else {
      isNegative = false;
    }

    for (int i = str.length() - 1; i >= start; --i) {
      if (str[i] < '0' || str[i] > '9') {
        digits.clear();
        digits.push_back(0);
        isNegative = false;
        return;
      }
      digits.push_back(str[i] - '0');
    }
  }
}