#include "bigint.hpp"
#include <stdexcept>
#include <string>

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

// Deque of digits and sign to BigInt
BigInt::BigInt(const std::deque<digit> &digits, bool isNegative)
    : digits(digits), isNegative(isNegative) {
  if (digits.size() == 0) {
    this->digits.push_front(digit(0));
    this->isNegative = false;
  } else {
    while (this->digits.size() > 1 && this->digits.front() == 0) {
      this->digits.pop_front();
    }
  }
}

// String to BigInt
BigInt::BigInt(const std::string &str) {
  if (str.empty()) {
    throw std::invalid_argument("Your input is empty. Please enter a number.");
  } else {
    int start = 0;
    if (str[0] == '-') {
      isNegative = true;
      start = 1;
    } else {
      isNegative = false;
    }
    int str_len = str.length();
    for (int i = start; i < str_len; ++i) {
      if (str[i] < '0' || str[i] > '9') {
        std::string error = "Your input contains non-digit characters " +
                            str.substr(i, 1) + " with ASCII value " +
                            std::to_string(str[i]) +
                            ". Please enter a valid number.";
        throw std::invalid_argument(error);
      }
      if (i != start || str[i] != '0' || str_len == 1) {
        digits.push_back(digit(str[i] - '0'));
      }
    }
  }
}