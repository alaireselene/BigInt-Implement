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
    digits.push_front(digit(0));
  } else {
    if (value < 0) {
      value = -value;
      isNegative = true;
    }
    while (value > 0) {
      digits.push_front(digit(value % 10));
      value /= 10;
    }
  }
}

// deque of digits and sign to BigInt
BigInt::BigInt(const std::deque<digit> &digits, bool isNegative)
    : digits(digits), isNegative(isNegative) {
  if (digits.size() == 0) {
    this->digits.push_front(digit(0));
    this->isNegative = false;
  }
}

// String to BigInt
BigInt::BigInt(const std::string &str) {
  if (str.empty()) {
    digits.push_front(digit(0));
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

    for (int i = start; i < str.length(); ++i) {
      if (str[i] < '0' || str[i] > '9') {
        digits.clear();
        digits.push_back(digit(0));
        isNegative = false;
        return;
      }
      digits.push_back(digit(str[i] - '0'));
    }
  }
}