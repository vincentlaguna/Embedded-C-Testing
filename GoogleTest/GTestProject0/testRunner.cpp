#include <iostream>
#include <gtest/gtest.h>
#include "LibraryCode.hpp"
#include <vector>

// Simple Test Case for simple function
TEST(TestSample, TestAddition)
{
  ASSERT_EQ(2, add(1, 1));
}

TEST(TestCountPositives, BasicTest)
{
  // Arrange
  std::vector<int> inputVector{1, -2, 3, -4, 5, -6, -7};
  // Act
  int count = countPositives(inputVector);
  // Assert *Unit testing convention: expected value goes first
  ASSERT_EQ(3, count);
}

TEST(TestCountPositives, EmptyVectorTest)
{
  // Arrange
  std::vector<int> inputVector{};
  // Act
  int count = countPositives(inputVector);
  // Assert *Unit testing convention: expected value goes first
  ASSERT_EQ(0, count);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}