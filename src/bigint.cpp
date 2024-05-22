#include "bigint.h"
#include <vector>

BigInt::BigInt() : digits({0}), isNegative(false) {}

BigInt::BigInt(int value) {
    if (value < 0) {
        isNegative = true;
        value = -value;
    } else {
        isNegative = false;
    }

    if (value == 0) {
        digits.push_back(0);
    } else {
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

std::vector<int> BigInt::add(const std::vector<int>& a, const std::vector<int>& b) const {
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

std::vector<int> BigInt::subtract(const std::vector<int>& a, const std::vector<int>& b) const {
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

    return result;
}

std::vector<int> BigInt::trim(const std::vector<int>& digits) const {
    std::vector<int> result = digits;
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}