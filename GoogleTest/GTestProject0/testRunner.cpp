#include <iostream>
#include <stdexcept>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "LibraryCode.hpp"
// #include <vector>
// #include <cctype>
// #include <string.h>

// Account Class Tests

// Create Account Test Fixture Class

class AccountTestFixture : public testing::Test
{
  public:
    
    AccountTestFixture();
    virtual ~AccountTestFixture();
    
    void SetUp() override;
    void TearDown() override;
  
  protected:
  
    Account *account; 
};

// Test Fixture Constructor

AccountTestFixture::AccountTestFixture()
{
  std::cout << "\nConstructor called\n";
}

// Test Fixture Destructor

AccountTestFixture::~AccountTestFixture()
{
  std::cout << "\nConstructor called\n";
}

// Setup

void AccountTestFixture::SetUp()
{
  std::cout << "\nAccount Test Fixture SetUp() called\n";
  
  account = new Account();
  
  account->deposit(100.05);
}

// TearDown

void AccountTestFixture::TearDown()
{
  std::cout << "\nAccount Test Fixture TearDown() called\n";
  
  delete account;
}



TEST_F(AccountTestFixture, TestDeposit)
{
  // Arrange
  // Account account;
  // double balance = account.getBalance();
  // Act
  // account.deposit(100.0);
  // Assert
  ASSERT_EQ(100.05, account->getBalance());
}

TEST_F(AccountTestFixture, TestWithdrawOK)
{
  // Arrange
  // Account account;
  // account.deposit(100.0);
  // Act
  account->withdraw(50.05);
  // Assert
  ASSERT_EQ(50, account->getBalance());
}

TEST_F(AccountTestFixture, TestWithdrawInsufficientFunds)
{
  // Arrange
  // Account account;
  // account.deposit(100.0);
  // Act
  // Assert
  ASSERT_THROW(account->withdraw(100.06), std::runtime_error);
}

TEST_F(AccountTestFixture, TestTransferOK)
{
  // Arrange
  // Account account;
  // account.deposit(100.05);
  Account newAccount;
  // Act
  account->transfer(newAccount, 50);
  // Assert
  ASSERT_EQ(50.05, account->getBalance());
  ASSERT_EQ(50, newAccount.getBalance());
}

TEST_F(AccountTestFixture, TestTransferInsufficientFunds)
{
  // Arrange
  // Account account;
  // account.deposit(100.05);
  Account newAccount;
  // Act
  // Assert
  ASSERT_THROW(account->transfer(newAccount, 100000.00), std::runtime_error);
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