#include "bigint.hpp"
#include <iostream>

int main() {
  BigInt a(14192);
  BigInt b(25);
  BigInt sum = a / b;
  std::cout << sum.toString() << std::endl;
}