#include <iostream>
#include <gtest/gtest.h>
#include "LibraryCode.hpp"
#include <vector>
#include <cctype>
#include <string.h>


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
  // Assert 
  ASSERT_EQ(0, count);
}

TEST(TestCountPositives, AllNegativesVectorTest)
{
  // Arrange
  std::vector<int> inputVector{-2, -4, -6};
  // Act
  int count = countPositives(inputVector);
  // Assert 
  EXPECT_EQ(0, count);
  // After the Assertion (EXPECT = non-fatal)
  std::cout << "\nAfter the Assertion (non-fatal)\n\n";
}

TEST(ToUpperTest, BasicTest)
{
  // Arrange
  char inputString[] = "Hello World";
  char expectedVal[] = "HELLO WORLD";
  // Act
  toUpper(inputString);
  // Assert
  EXPECT_EQ(0, strcmp(expectedVal, inputString));
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}