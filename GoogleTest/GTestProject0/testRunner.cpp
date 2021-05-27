#include <iostream>
#include <stdexcept>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "LibraryCode.hpp"
// #include <vector>
// #include <cctype>
// #include <string.h>

// Account Class Tests

TEST(AccountTest, TestEmptyAccount)
{
  // Arrange
  Account account;
  // Act
  double  amount = account.getBalance();
  // Assert
  ASSERT_EQ(0, amount);
}

TEST(AccountTest, TestDeposit)
{
  // Arrange
  Account account;
  double balance = account.getBalance();
  //double amount = 100.0;
  // Act
  account.deposit(100.0);
  // Assert
  ASSERT_EQ(100.0, account.getBalance());
}

TEST(AccountTest, TestWithdrawOK)
{
  // Arrange
  Account account;
  account.deposit(100.0);
  // Act
  account.withdraw(50.5);
  // Assert
  ASSERT_EQ(49.5, account.getBalance());
}

// // Simple Test Case for simple function
// TEST(TestSample, TestAddition)
// {
//   ASSERT_EQ(2, add(1, 1));
// }

// TEST(SquareRootTest, PosArgTest)
// {
//   // Arrange
//   double inputVal = -9;
//   // Act
//   // Assert
//   ASSERT_THROW(mySqrt(inputVal), std::runtime_error);
// }

// TEST(SquareRootTest, NegArgTest)
// {
//   // Arrange
//   double inputVal = 9;
//   // Act
//   // Assert
//   ASSERT_NO_THROW(mySqrt(inputVal));
// }

// TEST(TestCountPositives, BasicTest)
// {
//   // Arrange
//   std::vector<int> inputVector{1, -2, 3, -4, 5, -6, -7};
//   // Act
//   int count = countPositives(inputVector);
//   // Assert *Unit testing convention: expected value goes first
//   ASSERT_EQ(3, count);
// }

// TEST(TestCountPositives, EmptyVectorTest)
// {
//   // Arrange
//   std::vector<int> inputVector{};
//   // Act
//   int count = countPositives(inputVector);
//   // Assert 
//   ASSERT_EQ(0, count);
// }

// TEST(TestCountPositives, AllNegativesVectorTest)
// {
//   // Arrange
//   std::vector<int> inputVector{-2, -4, -6};
//   // Act
//   int count = countPositives(inputVector);
//   // Assert 
//   EXPECT_EQ(0, count);
//   // After the Assertion (EXPECT = non-fatal)
//   std::cout << "\nAfter the Assertion (non-fatal)\n\n";
// }

// TEST(ToUpperTest, BasicTest)
// {
//   // Arrange
//   char inputString[] = "Hello World";
//   //char expectedVal[] = "HELLO WORLD";
//   // Act
//   toUpper(inputString);
//   // Assert
//   //EXPECT_EQ(0, strcmp(expectedVal, inputString));
//   EXPECT_STREQ("HELLO WORLD", inputString);
//   // If not C-style string:
//   std::string str(inputString);
//   // Assert
//   EXPECT_EQ("HELLO WORLD", str);
// }

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}