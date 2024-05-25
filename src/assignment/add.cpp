#include "bigint.h"

BigInt& BigInt::operator+=(const BigInt& other) {
    *this = *this + other;
    return *this;
}