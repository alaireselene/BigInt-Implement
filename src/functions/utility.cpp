#include "bigint.hpp"
#include <chrono>
#include <cmath>
#include <random>

// Add two deques of digits
std::deque<digit> add(const std::deque<digit> &a, const std::deque<digit> &b) {
  std::deque<digit> result;
  int a_size = a.size();
  int b_size = b.size();
  int carry = 0;
  int i = 0;

  while (i < a_size || i < b_size || carry > 0) {
    int sum = carry;
    if (i < a_size) {
      sum += a.at(a_size - 1 - i);
    }
    if (i < b_size) {
      sum += b.at(b_size - 1 - i);
    }
    result.push_front(sum % 10);
    carry = sum / 10;
    ++i;
  }

  return result;
}

std::deque<digit> subtract(const std::deque<digit> &a,
                           const std::deque<digit> &b) {
  std::deque<digit> result;
  int a_size = a.size();
  int b_size = b.size();
  int borrow = 0;
  int i = 0;
  while (i < a_size || i < b_size) {
    int diff = borrow;
    if (i < a_size) {
      diff += a.at(a_size - i - 1);
    }
    if (i < b_size) {
      diff -= b.at(b_size - i - 1);
    }
    if (diff < 0) {
      diff += 10;
      borrow = -1;
    } else {
      borrow = 0;
    }
    result.push_front(diff);
    ++i;
  }
  while (result.size() > 1 && result.front() == 0) {
    result.pop_front();
  }
  return result;
}

// Multiply two deques of digits
std::deque<digit> multiply(const std::deque<digit> &a,
                           const std::deque<digit> &b) {
  std::deque<digit> result;
  int a_size = a.size();
  int b_size = b.size();
  for (int i = a_size - 1; i >= 0; --i) {
    std::deque<digit> partial;
    partial.insert(partial.begin(), a_size - 1 - i, 0);
    int carry = 0;
    for (int j = b_size - 1; j >= 0 || carry > 0; --j) {
      int product = carry;
      if (j >= 0)
        product += a.at(i) * b.at(j);
      partial.push_front(product % 10);
      carry = product / 10;
    }
    result = add(result, partial);
  }
  while (result.size() > 1 && result.front() == 0) {
    result.pop_front();
  }

  return result;
}

// Divide two deques of digits
std::pair<std::deque<digit>, std::deque<digit>>
divideWithRemainder(const std::deque<digit> &a, const std::deque<digit> &b) {
  std::deque<digit> quotient;
  std::deque<digit> remainder = a;
  int a_size = a.size();
  int b_size = b.size();

  // If b = 0 then throw logic error
  if (b_size == 1 && b.back() == 0) {
    throw std::logic_error("Undefined, attempt to divide by zero.");
  }
  // If a = 0 then remainder = 0 and quotient = 0
  else if (a_size == 1 && a.back() == 0) {
    quotient = std::deque<digit>{0};
    remainder = std::deque<digit>{0};
  }
  // If b = 1 then remainder = 0 and quotient = a
  else if (b_size == 1 && b.back() == 1) {
    quotient = a;
    remainder = std::deque<digit>{0};
  }

  // If a = b then remainder = 0 and quotient = 1
  else if (equal(a, b)) {
    quotient = std::deque<digit>{1};
    remainder = std::deque<digit>{0};
  }
  // If a < b then remainder = a and quotient = 0
  else if (greater(b, a)) {
    quotient = std::deque<digit>{0};
  } else {

    // Set flag to keep track of the current index of a
    int flag = b_size - 1;
    remainder.erase(remainder.begin() + b_size, remainder.end());

    for (auto i = flag; i < a_size; ++i) {
      if (greater(remainder, b) || equal(remainder, b)) {
        // If temp is greater than b but with same size, guess x in [1,
        // temp.back() / b.back()] . Otherwise, guess x in [1, 9]
        digit x =
            remainder.size() == b.size() ? remainder.front() / b.front() : 9;
        while (greater(multiply(b, std::deque<digit>{x}), remainder)) {
          --x;
        }
        quotient.push_back(x);
        remainder = subtract(remainder, multiply(b, std::deque<digit>{x}));
      }
      if (i < a_size - 1) {
        remainder.push_back(a.at(i + 1));
      }
    }
  }
  return std::make_pair(quotient, remainder);
}

// Check if a is greater than b
bool greater(const std::deque<digit> &a, const std::deque<digit> &b) {
  int a_size = a.size();
  int b_size = b.size();
  if (a_size > b_size) {
    return true;
  } else if (a_size < b_size) {
    return false;
  } else {
    bool isGreater = true;
    for (int i = 0; i < a_size; ++i) {
      if (a.at(i) != b.at(i)) {
        isGreater = a.at(i) > b.at(i);
        break;
      }
    }
    return isGreater;
  }
}

// Check if a is equal to b
bool equal(const std::deque<digit> &a, const std::deque<digit> &b) {
  if (a.size() != b.size()) {
    return false;
  }
  int a_size = a.size();
  for (int i = 0; i < a_size; ++i) {
    if (a.at(i) != b.at(i)) {
      return false;
    }
  }
  return true;
}

// Generate a random BigInt with a given size
BigInt randomBigInt(const int &size) {
  std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> dis(0, 9);
  std::uniform_int_distribution<int> sign(0, 1);
  std::deque<char> digits;
  bool isNegative = bool(sign(gen));
  for (int i = 0; i < size; ++i) {
    digits.push_back(dis(gen));
  }

  return BigInt(digits, isNegative);
}