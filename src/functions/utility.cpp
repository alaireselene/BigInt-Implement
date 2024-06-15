#include "bigint.hpp"
#include <utility>
#include <vector>

std::vector<long long> add(const std::vector<long long> &a,
                           const std::vector<long long> &b) {
  std::vector<long long> result;
  int carry = 0;
  int i = 0;

  while (i < a.size() || i < b.size() || carry > 0) {
    int sum = carry;
    if (i < a.size()) {
      sum += a[i];
    }
    if (i < b.size()) {
      sum += b[i];
    }

    result.push_back(sum % 10);
    carry = sum / 10;
    ++i;
  }

  return result;
}

std::vector<long long> subtract(const std::vector<long long> &a,
                                const std::vector<long long> &b) {
  std::vector<long long> result;
  int borrow = 0;
  int i = 0;

  while (i < a.size() || i < b.size()) {
    int diff = borrow;
    if (i < a.size()) {
      diff += a[i];
    }
    if (i < b.size()) {
      diff -= b[i];
    }

    if (diff < 0) {
      diff += 10;
      borrow = -1;
    } else {
      borrow = 0;
    }

    result.push_back(diff);
    ++i;
  }
  return result;
}

std::vector<long long> multiply(const std::vector<long long> &a,
                                const std::vector<long long> &b) {
  std::vector<long long> result;
  for (int i = 0; i < b.size(); ++i) {
    std::vector<long long> partial;
    partial.insert(partial.begin(), i, 0);
    int carry = 0;
    for (int j = 0; j < a.size() || carry > 0; ++j) {
      long long int product = carry;
      if (j < a.size()) {
        product += a[j] * b[i];
      }
      partial.push_back(product % 10);
      carry = product / 10;
    }
    result = add(result, partial);
  }
  while (result.size() > 1 && result.back() == 0) {
    result.pop_back();
  }

  return result;
}

std::pair<std::vector<long long>, std::vector<long long>>
divideWithRemainder(const std::vector<long long> &a,
                    const std::vector<long long> &b) {
  std::vector<long long> quotient;
  std::vector<long long> remainder = a;
  int a_size = a.size();
  int b_size = b.size();

  // If b = 0 then throw logic exception
  if (b_size == 1 && b[0] == 0) {
    throw std::logic_error("Attempted division by zero");
  }
  // If a = 0 then remainder = 0 and quotient = 0
  else if (a_size == 1 && a[0] == 0) {
    quotient = std::vector<long long>{0};
    remainder = std::vector<long long>{0};
  }
  // If a = b then remainder = 0 and quotient = 1
  else if (equal(a, b)) {
    quotient = std::vector<long long>{1};
    remainder = std::vector<long long>{0};
  }
  // If a < b then remainder = a and quotient = 0
  else if (greater(a, b)) {
    quotient = std::vector<long long>{0};
  } else {
    // TODO: Implement division algorithm

    for (int i = a_size - b_size; i >= 0; --i) {
      std::vector<long long> subArray(remainder.begin() + i,
                                      remainder.begin() + i + b_size);
      if (greater(b, subArray)) {
        subArray = std::vector<long long>(remainder.begin() + i - 1,
                                          remainder.begin() + i + b_size);
        --i;
      }
      while (greater(subArray, b)) {
        // If subArray is greater than b but with same size, guess x in [1,
        // subArray.back() / b.back()]. Otherwise, guess x in [1, 9]
        int x = subArray.size() == b.size() ? subArray.back() / b.back() : 9;
        std::vector<long long> temp;
        while (greater(subArray, multiply(b, std::vector<long long>{x}))) {
          --x;
        }
        quotient.push_back(x);
        // To make implementation easier, I fill the temp vector with 0s then
        // subtract remainder with temp.
        temp = multiply(b, std::vector<long long>{x});
        temp.insert(temp.begin(), i, 0);
        remainder = subtract(remainder, temp);
      }
    }
  }
  quotient = std::vector<long long>(quotient.rbegin(), quotient.rend());
  return std::make_pair(quotient, remainder);
}

bool greater(const std::vector<long long> &a, const std::vector<long long> &b) {
  if (a.size() > b.size()) {
    return true;
  } else if (a.size() < b.size()) {
    return false;
  } else {
    bool isNotEqual = false;
    for (int i = a.size() - 1; i >= 0; --i) {
      if (a[i] < b[i]) {
        return false;
      } else if (a[i] > b[i]) {
        isNotEqual = true;
      }
    }
    return isNotEqual;
  }
}

bool equal(const std::vector<long long> &a, const std::vector<long long> &b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}