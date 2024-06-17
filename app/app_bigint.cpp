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
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define MAX_LENGTH 1000

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
  std::ofstream outputFile("test.out");
  try {
    std::cout << "Enter two integers a and b (each with at most " << MAX_LENGTH
              << " digits): ";
    std::cin >> aString >> bString;

    if (aString.length() <= MAX_LENGTH && bString.length() <= MAX_LENGTH) {
      BigInt a(aString);
      BigInt b(bString);
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
    BigInt a(aString);
    BigInt b(bString);

    BigInt sum(a + b);
    BigInt diff(a - b);
    BigInt prod(a * b);
    std::cout << "a + b = " << sum << std::endl;
    outputFile << sum << std::endl;
    std::cout << "a - b = " << diff << std::endl;
    outputFile << diff << std::endl;
    std::cout << "a * b = " << prod << std::endl;
    outputFile << prod << std::endl;
    try {
      BigInt div(a / b);
      std::cout << "a / b = " << a / b << std::endl;
      outputFile << div << std::endl;
    } catch (std::logic_error &e) {
      std::cout << "a / b = " << e.what() << std::endl;
      outputFile << "NULL" << std::endl;
    }
    try {
      BigInt mod(a % b);
      std::cout << "a % b = " << a % b << std::endl;
      outputFile << mod << std::endl;
    } catch (std::logic_error &e) {
      std::cout << "a % b = " << e.what() << std::endl;
      outputFile << "NULL" << std::endl;
    }
  } catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
    outputFile << "NULL" << std::endl;
  }
  std::cout << "Output has been written to test.out" << std::endl;
  outputFile.close();
}

// Take input from file
void inputFromFile() {
  std::ifstream inputFile("test.inp");
  std::ofstream outputFile("test.out");
  std::string aString, bString;
  if (!inputFile.is_open()) {
    std::cout << "test.inp is not exist or not found. We will create a new "
                 "file for you."
              << std::endl;
    std::ofstream _inputFile("test.inp");
    _inputFile << "1234567890123456789012345678901234567890\n"
               << "9876543210987654321098765432109876543210";
    _inputFile.close();
    inputFile.open("test.inp");
  }
  try {
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
  } catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
    outputFile << "NULL" << std::endl;
  }
  std::cout << "Output has been written to test.out" << std::endl;
  inputFile.close();
  outputFile.close();
}

// Chaotic mode: Randomly generate input and output to file
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
}

// Main function
int main() {
  std::string choice = "";
  do {
    printMenu();
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    if (choice == "1") {
      inputFromKeyboard();
      break;
    } else if (choice == "2") {
      inputFromFile();
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