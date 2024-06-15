/*
 * bigint.h
 * This file contains the declaration of the BigInt class.
 */

#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

class BigInt {
public:
  // Constructors

  // Default constructor (e.g., initializes to zero)
  BigInt();
  // Copy constructor
  BigInt(const BigInt &num);
  // Construct from an integer
  BigInt(long long value);
  // Construct from a string representation
  BigInt(const std::string &str);
  // Construct from a vector of digits and a sign
  BigInt(const std::vector<long long> &digits, bool isNegative);

  // Arithmetic Operators
  BigInt operator+(const BigInt &other) const;
  BigInt operator-(const BigInt &other) const;
  BigInt operator*(const BigInt &other) const;
  BigInt operator/(const BigInt &other) const;
  BigInt operator%(const BigInt &other) const;
  BigInt operator+(const long long &other) const;
  BigInt operator-(const long long &other) const;
  BigInt operator*(const long long &other) const;
  BigInt operator/(const long long &other) const;
  BigInt operator%(const long long &other) const;
  BigInt operator+(const std::string &other) const;
  BigInt operator-(const std::string &other) const;
  BigInt operator*(const std::string &other) const;
  BigInt operator/(const std::string &other) const;
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
  void toFile(const std::string &filename) const;

  // Utility Functions
  friend std::ostream &operator<<(std::ostream &os, const BigInt &bigInt);
  friend std::istream &operator>>(std::istream &is, BigInt &bigInt);

private:
  // The digits of the BigInt, but with reversed order
  std::vector<long long> digits;
  // Sign of the BigInt. True if negative, false otherwise
  bool isNegative;
};

// Utility Functions
std::vector<long long> max(const std::vector<long long> &a,
                           const std::vector<long long> &b);
std::vector<long long> min(const std::vector<long long> &a,
                           const std::vector<long long> &b);
std::vector<long long> add(const std::vector<long long> &a,
                           const std::vector<long long> &b);
std::vector<long long> subtract(const std::vector<long long> &a,
                                const std::vector<long long> &b);
std::vector<long long> multiply(const std::vector<long long> &a,
                                const std::vector<long long> &b);
std::pair<std::vector<long long>, std::vector<long long>>
divideWithRemainder(const std::vector<long long> &a,
                    const std::vector<long long> &b);
bool greater(const std::vector<long long> &a, const std::vector<long long> &b);
bool equal(const std::vector<long long> &a, const std::vector<long long> &b);
#endif