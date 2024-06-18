#include "bigint.hpp"
#include "gtest/gtest.h"

TEST(UtilityTest, DivideWithRemainderByOne) {
  std::deque<digit> a = {1, 2, 3, 4, 5};
  std::deque<digit> b = {1};
  auto result = divideWithRemainder(a, b);
  EXPECT_EQ(result.first, a);
  EXPECT_EQ(result.second, std::deque<digit>{0});
}

TEST(UtilityTest, DivideWithRemainderBySelf) {
  std::deque<digit> a = {1, 2, 3, 4, 5};
  auto result = divideWithRemainder(a, a);
  EXPECT_EQ(result.first, std::deque<digit>{1});
  EXPECT_EQ(result.second, std::deque<digit>{0});
}

TEST(UtilityTest, DivideWithRemainderByLarger) {
  std::deque<digit> a = {1, 2, 3, 4, 5};
  std::deque<digit> b = {1, 2, 3, 4, 5, 6};
  auto result = divideWithRemainder(a, b);
  EXPECT_EQ(result.first, std::deque<digit>{0});
  EXPECT_EQ(result.second, a);
}

TEST(UtilityTest, DivideWithRemainderByZero) {
  std::deque<digit> a = {1, 2, 3, 4, 5};
  std::deque<digit> b = {0};
  EXPECT_THROW(divideWithRemainder(a, b), std::logic_error);
}

TEST(UtilityTest, DivideZeroWithRemainder) {
  std::deque<digit> a = {0};
  std::deque<digit> b = {1, 2, 3, 4, 5};
  auto result = divideWithRemainder(a, b);
  EXPECT_EQ(result.first, std::deque<digit>{0});
  EXPECT_EQ(result.second, std::deque<digit>{0});
}