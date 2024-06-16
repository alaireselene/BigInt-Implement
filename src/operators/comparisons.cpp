#include "bigint.hpp"

bool BigInt::operator==(const BigInt &other) const {
  if (digits.size() != other.digits.size() || isNegative != other.isNegative) {
    return false;
  }

  for (size_t i = 0; i < digits.size(); i++) {
    if (digits[i] != other.digits[i]) {
      return false;
    }
  }

  return true;
}

bool BigInt::operator!=(const BigInt &other) const { return !(*this == other); }

bool BigInt::operator<(const BigInt &other) const {
  if (isNegative != other.isNegative) {
    return isNegative;
  }

  if (digits.size() != other.digits.size()) {
    return digits.size() < other.digits.size();
  }

  for (int i = digits.size() - 1; i >= 0; i--) {
    if (digits[i] != other.digits[i]) {
      return digits[i] < other.digits[i];
    }
  }

  return false;
}

bool BigInt::operator>(const BigInt &other) const { return other < *this; }

bool BigInt::operator<=(const BigInt &other) const { return !(*this > other); }

bool BigInt::operator>=(const BigInt &other) const { return !(*this < other); }

bool BigInt::operator==(const long long &other) const {
  return *this == BigInt(other);
}

bool BigInt::operator!=(const long long &other) const {
  return !(*this == BigInt(other));
}

bool BigInt::operator<(const long long &other) const {
  return *this < BigInt(other);
}

bool BigInt::operator>(const long long &other) const {
  return *this > BigInt(other);
}

bool BigInt::operator<=(const long long &other) const {
  return *this <= BigInt(other);
}

bool BigInt::operator>=(const long long &other) const {
  return *this >= BigInt(other);
}

bool BigInt::operator==(const std::string &other) const {
  return *this == BigInt(other);
}

bool BigInt::operator!=(const std::string &other) const {
  return !(*this == BigInt(other));
}

bool BigInt::operator<(const std::string &other) const {
  return *this < BigInt(other);
}

bool BigInt::operator>(const std::string &other) const {
  return *this > BigInt(other);
}

bool BigInt::operator<=(const std::string &other) const {
  return *this <= BigInt(other);
}

bool BigInt::operator>=(const std::string &other) const {
  return *this >= BigInt(other);
}
