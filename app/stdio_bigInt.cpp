/*
  * File:   stdio_bigInt.cpp

  Name: Nguyen Truong Son
  Student ID: 20227148
  Class: 150327
  Project: Project 2 - BigInt Library
  Date: 17/06/2024

  Description: This program demonstrates the use of the BigInt library by taking
  two integers a and b as input and performing arithmetic operations on them,
  including addition, subtraction, multiplication, division, and modulo. The
  program will output the results of these operations to console.
 */
#include "bigint.hpp"

#define MAX_LENGTH 1000

int main() {
  std::string aString, bString;
  try {
    std::cout << "Enter two integers a and b (each with at most " << MAX_LENGTH
              << " digits): ";
    std::cin >> aString >> bString;
    BigInt a(aString);
    BigInt b(bString);
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    try {
      std::cout << "a / b = " << a / b << std::endl;
    } catch (std::logic_error &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "a % b = " << a % b << std::endl;
    } catch (std::logic_error &e) {
      std::cout << e.what() << std::endl;
    }
  } catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}