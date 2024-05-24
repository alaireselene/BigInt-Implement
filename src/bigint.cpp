#include "bigint.h"
#include <vector>
#include <limits>

BigInt::BigInt() : digits({0}), isNegative(false) {}

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

BigInt::BigInt(const std::string& str) {
    if (str.empty()) {
        digits.push_back(0);
        isNegative = false;
        return;
    }

    size_t start = 0;
    if (str[0] == '-') {
        isNegative = true;
        start = 1;
    } else {
        isNegative = false;
    }

    for (size_t i = str.size() - 1; i >= start; --i) {
        if (str[i] < '0' || str[i] > '9') {
            digits.clear();
            digits.push_back(0);
            isNegative = false;
            return;
        }
        digits.push_back(str[i] - '0');
    }
}

std::vector<int> add(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    int carry = 0;
    size_t i = 0;

    while (i < a.size() || i < b.size() || carry > 0) {
        int sum = carry;
        if (i < a.size()) {
            sum += a[i];
        }
        if (i < b.size()) {
            sum += b[i];
        }

        result.push_back(sum % 10);
        carry = sum / 10;
        ++i;
    }

    return result;
}

std::vector<int> subtract(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    int borrow = 0;
    size_t i = 0;

    while (i < a.size() || i < b.size()) {
        int diff = borrow;
        if (i < a.size()) {
            diff += a[i];
        }
        if (i < b.size()) {
            diff -= b[i];
        }

        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        result.push_back(diff);
        ++i;
    }
    result = trim(result);

    return result;
}

std::vector<int> trim(const std::vector<int>& digits) {
    std::vector<int> result = digits;
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}

std::vector<int> max(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() > b.size()) {
        return a;
    } else if (a.size() < b.size()) {
        return b;
    } else {
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] > b[i]) {
                return a;
            } else if (a[i] < b[i]) {
                return b;
            }
        }
        return a; // a == b
    }
}

std::vector<int> min(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() < b.size()) {
        return a;
    } else if (a.size() > b.size()) {
        return b;
    } else {
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] < b[i]) {
                return a;
            } else if (a[i] > b[i]) {
                return b;
            }
        }
        return a; // a == b
    }
}

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