/*
  * File:   stdio_bigInt.cpp

  Name: Nguyen Truong Son
  Student ID: 20227148
  Class: 150327
  Project: Project 2 - BigInt Library
  Date: 17/06/2024

  Description: This program demonstrates the use of the BigInt library by
  reading a and b which seperated by newline character from test.inp and
  performing arithmetic operations on them, including addition, subtraction,
  multiplication, division, and modulo. The program will output the results of
  these operations to test.out, seperated by newline character.
 */

#include "bigint.hpp"
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

#define MAX_LENGTH 1000

int main() {
  std::ifstream inputFile("test.inp");
  std::ofstream outputFile("test.out");
  std::string aString, bString;
  if (!inputFile.is_open()) {
    std::cout << "test.inp is not exist or not found. We will create a new "
                 "file for you."
              << std::endl;
    std::ofstream _inputFile("test.inp");
    std::mt19937 gen(
        std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dis(15, MAX_LENGTH);
    _inputFile << randomize(dis(gen)) << std::endl << randomize(dis(gen));
    _inputFile.close();
    inputFile.open("test.inp");
  }
  inputFile >> aString >> bString;
  BigInt a(aString);
  BigInt b(bString);
  outputFile << a + b << std::endl;
  outputFile << a - b << std::endl;
  outputFile << a * b << std::endl;
  try {
    outputFile << a / b << std::endl;
  } catch (std::logic_error &e) {
    outputFile << e.what() << std::endl;
  }
  try {
    outputFile << a % b << std::endl;
  } catch (std::logic_error &e) {
    outputFile << e.what() << std::endl;
  }
  inputFile.close();
  outputFile.close();
  return 0;
}