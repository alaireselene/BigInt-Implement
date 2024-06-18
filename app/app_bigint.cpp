/*
  * File:   app_bigint.cpp

  Name: Nguyen Truong Son
  Student ID: 20227148
  Class: 150327
  Project: Project 2 - BigInt Library
  Date: 17/06/2024

  Description: This program demonstrates the use of the BigInt library by taking
  input from keyboard or file and performing arithmetic operations on them,
  including addition, subtraction, multiplication, division, and modulo. The
  program will output the results of these operations to console or file based
  on user's choice.
 */

#include "bigint.hpp"
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define MAX_LENGTH 1000

BigInt a, b, sum, diff, prod, idiv, mod;

// Print the menu
void printMenu() {
  std::cout << "1. Input from keyboard" << std::endl;
  std::cout << "2. Input from file" << std::endl;
  std::cout << "3. Chaotic mode: Randomly generate input and output to file"
            << std::endl;
  std::cout << "4. Exit" << std::endl;
}

// Take input from keyboard then perform arithmetic operations and write output
// to test.out
void inputFromKeyboard() {
  std::string aString, bString;
  try {
    std::cout << "Enter two integers a and b (each with at most " << MAX_LENGTH
              << " digits): ";
    std::cin >> aString >> bString;

    // Throw exception if the length of a and b exceeds the maximum limit.
    // Otherwise, proceed with caution.
    if (aString.length() <= MAX_LENGTH && bString.length() <= MAX_LENGTH) {
      a = BigInt(aString);
      b = BigInt(bString);
    } else if (aString.length() * bString.length() >= aString.max_size()) {
      throw std::invalid_argument("The product of the lengths of a and b "
                                  "exceeds the maximum limit of system.");
    } else {
      std::cout << "WARNING: The length of a or b exceeds the maximum limit of "
                << MAX_LENGTH
                << " digits, which may cause the program to run slowly. Please "
                   "proceed with caution."
                << std::endl;
    }
  } catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
    return;
  }
}

// Take input from file
void inputFromFile() {
  std::ifstream inputFile("test.inp");
  std::ofstream outputFile("test.out");
  std::string aString, bString;
  if (!inputFile.is_open()) {
    throw std::invalid_argument("test.inp is not exist or not found.");
  }
  inputFile >> aString >> bString;
  inputFile.close();
  if (aString.length() <= MAX_LENGTH && bString.length() <= MAX_LENGTH) {
    a = BigInt(aString);
    b = BigInt(bString);
  } else if (aString.length() * bString.length() >= aString.max_size()) {
    throw std::invalid_argument("The product of the lengths of a and b "
                                "exceeds the maximum limit of system.");
  } else {
    std::cout << "WARNING: The length of a or b exceeds the maximum limit of "
              << MAX_LENGTH
              << " digits, which may cause the program to run slowly. Please "
                 "proceed with caution."
              << std::endl;
  }
}

// Do arithmetic operations, write output to console and file. If division by 0
// then write "NULL" to file and show error message in console.
void operate() {
  std::ofstream outputFile("test.out");
  sum = BigInt(a + b);
  diff = BigInt(a - b);
  prod = BigInt(a * b);
  std::cout << "a + b = " << sum << std::endl;
  std::cout << "a - b = " << diff << std::endl;
  std::cout << "a * b = " << prod << std::endl;
  outputFile << sum << std::endl;
  outputFile << diff << std::endl;
  outputFile << prod << std::endl;
  try {
    idiv = BigInt(a / b);
    std::cout << "a / b = " << idiv << std::endl;
    outputFile << a / b << std::endl;
  } catch (std::logic_error &e) {
    std::cout << "a / b = " << e.what() << std::endl;
    outputFile << "NULL" << std::endl;
  }
  try {
    mod = BigInt(a % b);
    std::cout << "a % b = " << mod << std::endl;
    outputFile << a % b << std::endl;
  } catch (std::logic_error &e) {
    std::cout << "a % b = " << e.what() << std::endl;
    outputFile << "NULL" << std::endl;
  }
  outputFile.close();
  std::cout << "Output has been written to test.out" << std::endl;
}

// Chaotic mode: Randomly generate input and output to file. For testcase
// generation only. It will generate 50 testcases, each with two random integers
// a and b, then write the input to test.inp and the output to test.out.
void chaoticMode() {
  for (int i = 0; i < 50; ++i) {
    std::cout << "Generating test case #" << i + 1 << "..." << std::endl;
    int raa = rand() % 1001;
    int rab = rand() % 1001;
    BigInt ra(randomize(raa));
    BigInt rb(randomize(rab));
    std::stringstream ss;
    ss << "testcase_" << i + 1;
    std::filesystem::create_directories(ss.str());
    std::ofstream inputFile(ss.str() + "/test.inp");
    std::ofstream outputFile(ss.str() + "/test.out");
    inputFile << ra << " " << rb << std::endl;
    outputFile << ra + rb << std::endl;
    outputFile << ra - rb << std::endl;
    outputFile << ra * rb << std::endl;
    try {
      outputFile << ra / rb << std::endl;
    } catch (std::logic_error &e) {
      outputFile << "NULL" << std::endl;
    }
    try {
      outputFile << ra % rb << std::endl;
    } catch (std::logic_error &e) {
      outputFile << "NULL" << std::endl;
    }
    inputFile.close();
    outputFile.close();
  }
  std::cout << "All files generated" << std::endl;
  return;
}

// Main function
int main() {
  std::string choice = "";
  do {
    printMenu();
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    if (choice == "1") {
      try {
        inputFromKeyboard();
        operate();
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
      break;
    } else if (choice == "2") {
      try {
        inputFromFile();
        operate();
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
      break;
    } else if (choice == "3") {
      chaoticMode();
      break;
    } else if (choice == "4") {
      std::cout << "Goodbye!" << std::endl;
      break;
    } else {
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
  } while (choice != "3");
  return 0;
}