#include "bigint.hpp"
#include <iostream>

int main() {
  BigInt a(1234567890);
  BigInt b(-9876543210);
  BigInt sum = a - b;
  std::cout << sum.toString() << std::endl;
}