/*
 * bigint.h
 * This file contains the declaration of the BigInt class.
 */

#ifndef BIGINT_H
#define BIGINT_H
#include <deque>
#include <iostream>
#include <string>
#include <utility>

// Define the digit [0-9] type
typedef char digit;

class BigInt {
public:
  // Constructors

  BigInt();
  BigInt(const BigInt &num);
  BigInt(long long value);
  BigInt(const std::string &str);
  BigInt(const std::deque<digit> &digits, bool isNegative);

  // Arithmetic Operators

  // Binary Operators
  BigInt operator+(const BigInt &other) const;
  BigInt operator+(const long long &other) const;
  BigInt operator+(const std::string &other) const;
  BigInt operator-(const BigInt &other) const;
  BigInt operator-(const long long &other) const;
  BigInt operator-(const std::string &other) const;
  BigInt operator*(const BigInt &other) const;
  BigInt operator*(const long long &other) const;
  BigInt operator*(const std::string &other) const;
  BigInt operator/(const BigInt &other) const;
  BigInt operator/(const long long &other) const;
  BigInt operator/(const std::string &other) const;
  BigInt operator%(const BigInt &other) const;
  BigInt operator%(const long long &other) const;
  BigInt operator%(const std::string &other) const;

  // Unary Operators
  BigInt operator+() const;
  BigInt operator-() const;
  BigInt operator++(int);
  BigInt operator--(int);

  // Comparison Operators
  bool operator==(const BigInt &other) const;
  bool operator!=(const BigInt &other) const;
  bool operator<(const BigInt &other) const;
  bool operator>(const BigInt &other) const;
  bool operator<=(const BigInt &other) const;
  bool operator>=(const BigInt &other) const;
  bool operator==(const long long &other) const;
  bool operator!=(const long long &other) const;
  bool operator<(const long long &other) const;
  bool operator>(const long long &other) const;
  bool operator<=(const long long &other) const;
  bool operator>=(const long long &other) const;
  bool operator==(const std::string &other) const;
  bool operator!=(const std::string &other) const;
  bool operator<(const std::string &other) const;
  bool operator>(const std::string &other) const;
  bool operator<=(const std::string &other) const;
  bool operator>=(const std::string &other) const;

  // Assignment Operators
  BigInt &operator+=(const BigInt &other);
  BigInt &operator-=(const BigInt &other);
  BigInt &operator*=(const BigInt &other);
  BigInt &operator/=(const BigInt &other);
  BigInt &operator%=(const BigInt &other);
  BigInt &operator+=(const long long &other);
  BigInt &operator-=(const long long &other);
  BigInt &operator*=(const long long &other);
  BigInt &operator/=(const long long &other);
  BigInt &operator%=(const long long &other);
  BigInt &operator+=(const std::string &other);
  BigInt &operator-=(const std::string &other);
  BigInt &operator*=(const std::string &other);
  BigInt &operator/=(const std::string &other);
  BigInt &operator%=(const std::string &other);

  // Conversion Functions
  std::string toString() const;
  int toInt() const;
  long toLong() const;
  long long toLongLong() const;

  // I/O Operators
  friend std::ostream &operator<<(std::ostream &os, const BigInt &bigInt);
  friend std::istream &operator>>(std::istream &is, BigInt &bigInt);

private:
  // The digits of the BigInt
  std::deque<digit> digits;
  // Sign of the BigInt. True if negative, false otherwise.
  bool isNegative;
};

// Utility Functions
std::deque<digit> add(const std::deque<digit> &a, const std::deque<digit> &b);
std::deque<digit> subtract(const std::deque<digit> &a,
                           const std::deque<digit> &b);
std::deque<digit> multiply(const std::deque<digit> &a,
                           const std::deque<digit> &b);
std::pair<std::deque<digit>, std::deque<digit>>
divideWithRemainder(const std::deque<digit> &a, const std::deque<digit> &b);
bool greater(const std::deque<digit> &a, const std::deque<digit> &b);
bool equal(const std::deque<digit> &a, const std::deque<digit> &b);
BigInt randomBigInt(const int &size);
#endif