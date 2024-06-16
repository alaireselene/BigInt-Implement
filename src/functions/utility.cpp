#include "bigint.hpp"
#include <cmath>

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

std::pair<std::deque<digit>, std::deque<digit>>
divideWithRemainder(const std::deque<digit> &a, const std::deque<digit> &b) {
  std::deque<digit> quotient;
  std::deque<digit> remainder = a;
  int a_size = a.size();
  int b_size = b.size();

  // If b = 0 then throw logic exception
  if (b_size == 1 && b.back() == 0) {
    throw std::logic_error("Attempted division by zero");
  }
  // If a = 0 then remainder = 0 and quotient = 0
  else if (a_size == 1 && a.back() == 0) {
    quotient = std::deque<digit>{0};
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
    // TODO: Implement division algorithm

    // Set flag to keep track of the current index of a
    int flag = b_size - 1;
    remainder.erase(remainder.begin() + b_size, remainder.end());

    for (int i = flag; i < a_size; ++i) {
      if (greater(remainder, b) || equal(remainder, b)) {
        // If temp is greater than b but with same size, guess x in [1,
        // temp.back() / b.back()] . Otherwise, guess x in [1, 9]
        digit x =
            remainder.size() == b.size() ? remainder.front() / b.front() : 9;
        while (greater(multiply(b, std::deque<digit>{x}), remainder)) {
          --x;
        }
        quotient.push_back(x);
        // To make implementation easier, I fill the temp deque with 0s then
        // subtract remainder with temp.
        remainder = subtract(remainder, multiply(b, std::deque<digit>{x}));
      }
      if (i < a_size - 1) {
        remainder.push_back(a.at(i + 1));
      }
    }
  }
  return std::make_pair(quotient, remainder);
}

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

bool equal(const std::deque<digit> &a, const std::deque<digit> &b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (int i = 0; i < a.size(); ++i) {
    if (a.at(i) != b.at(i)) {
      return false;
    }
  }
  return true;
}