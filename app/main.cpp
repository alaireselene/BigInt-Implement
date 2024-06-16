#include "bigint.hpp"

#define MAX_LENGTH 999

int main() {
  BigInt a = randomBigInt(1000);
  BigInt b = randomBigInt(900);
  a.toFile("a.inp");
  b.toFile("b.inp");
  (a + b).toFile("add.out");
  (a - b).toFile("sub.out");
  (a * b).toFile("mul.out");
  (a / b).toFile("div.out");
  return 0;
}