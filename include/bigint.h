#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <vector> // or other suitable container for storing digits

class BigInt {
public:
    // Constructors
    BigInt();                       // Default constructor (e.g., initializes to zero)
    BigInt(int value);              // Construct from an integer
    BigInt(const std::string& str); // Construct from a string representation

    // Arithmetic Operators
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;
    BigInt operator/(const BigInt& other) const;

    // Comparison Operators
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;

    // Assignment Operators
    BigInt& operator+=(const BigInt& other);
    BigInt& operator-=(const BigInt& other);
    // ... and so on

    // Utility Functions
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const BigInt& bigInt);
    friend std::istream& operator>>(std::istream& is, BigInt& bigInt);

private:
    // Data Members (e.g., to store the digits of the BigInt)
    std::vector<int> digits; // or std::vector<unsigned char> or other
    bool isNegative;

    // Helper Functions (if needed)
    std::vector<int> add(const std::vector<int>& a, const std::vector<int>& b) const;
    std::vector<int> subtract(const std::vector<int>& a, const std::vector<int>& b) const;
    std::vector<int> trim(const std::vector<int>& digits) const;
};

#endif // BIGINT_H