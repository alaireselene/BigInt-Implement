#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <vector> // or other suitable container for storing digits

class BigInt
{
public:
    // Constructors
    BigInt();                       // Default constructor (e.g., initializes to zero)
    BigInt(long long int value);    // Construct from an integer
    BigInt(const std::string &str); // Construct from a string representation

    // Arithmetic Operators
    BigInt operator+(const BigInt &other) const;
    BigInt operator-(const BigInt &other) const;
    BigInt operator*(const BigInt &other) const;
    BigInt operator/(const BigInt &other) const;

    // Comparison Operators
    bool operator==(const BigInt &other) const;
    bool operator!=(const BigInt &other) const;
    bool operator<(const BigInt &other) const;
    bool operator>(const BigInt &other) const;
    bool operator<=(const BigInt &other) const;
    bool operator>=(const BigInt &other) const;

    // Assignment Operators
    BigInt &operator+=(const BigInt &other);
    BigInt &operator-=(const BigInt &other);
    // ... and so on

    // Utility Functions
    std::string toString() const;
    void leftShift(int n);
    void rightShift(int n);
    void zeroTrim();
    friend std::ostream &operator<<(std::ostream &os, const BigInt &bigInt);
    friend std::istream &operator>>(std::istream &is, BigInt &bigInt);

private:
    // Data Members (e.g., to store the digits of the BigInt)
    std::vector<long long int> digits;
    bool isNegative;
};

// Helper Functions
std::vector<long long int> max(const std::vector<long long int> &a, const std::vector<long long int> &b);
std::vector<long long int> min(const std::vector<long long int> &a, const std::vector<long long int> &b);
std::vector<long long int> add(const std::vector<long long int> &a, const std::vector<long long int> &b);
std::vector<long long int> subtract(const std::vector<long long int> &a, const std::vector<long long int> &b);
bool greater(const std::vector<long long int> &a, const std::vector<long long int> &b);
bool equal(const std::vector<long long int> &a, const std::vector<long long int> &b);
#endif // BIGINT_H