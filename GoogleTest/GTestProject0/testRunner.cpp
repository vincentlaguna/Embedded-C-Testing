#include <iostream>
// #include <stdexcept>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
// #include "LibraryCode.hpp"
// #include <vector>
// #include <cctype>
// #include <string.h>

// Employee Manager Project

#include <map>
#include "IDatabaseConnection.hpp"
#include "EmployeeManager.hpp"
#include "Employee.hpp"

// MACROS

// INSTANTIATE_TEST_CASE -> Deprecated. Use -> INSTANTIATE_TEST_SUITE


/**********EMPLOYEE MANAGER PROJECT - TEST CASES**********/

// Create Mock Database Connection Class

class MockDatabaseConnection : public IDatabaseConnection
{
  public:
    
    MockDatabaseConnection(std::string serverAddress);
      // : IDatabaseConnection(serverAddress) {}
      
      MOCK_METHOD0(connect, void());
      MOCK_METHOD0(disconnect, void());
      
      MOCK_CONST_METHOD1(getSalary, float(int));
      MOCK_METHOD2(updateSalary, void(int, float));
      
      // MOCK_CONST_METHOD1(getSalariesRange, std::vector<Employee>(float));
      // MOCK_CONST_METHOD2(getSalariesRange, std::vector<Employee>(float, float));
      
      // MOCK_METHOD0(someMethod, (std::map<std::string, float>)());
      
      // Here for reference only when creating MOCK methods
      // virtual float getSalary(int id) const = 0; // SELECT * FROM employees WHERE id=...
      // virtual void  updateSalary(int id, float newSalary) = 0;
    
      // virtual std::vector<Employee> getSalariesRange(float low) const = 0; // Just > low
      // virtual std::vector<Employee> getSalariesRange(float low, float high) const = 0;
};

MockDatabaseConnection::MockDatabaseConnection(std::string serverAddress) : IDatabaseConnection(serverAddress)
{
  
}

// TESTS

TEST(TestEmployeeManager, TestConnection)
{
  // Arrange
  MockDatabaseConnection dbConnection("dummyConnection");
  // Assert
  EXPECT_CALL(dbConnection, connect());
  EXPECT_CALL(dbConnection, disconnect());
  // Act
  EmployeeManager employeeManager(&dbConnection);
}

TEST(TestEmployeeManager, TestUpdateSalary)
{
  // Arrange
  MockDatabaseConnection dbConnection("dummyConnection");
  // Assert
  EXPECT_CALL(dbConnection, connect());
  EXPECT_CALL(dbConnection, disconnect());
  EXPECT_CALL(dbConnection, updateSalary(testing::_, testing::_)).Times(1);
  // Act
  EmployeeManager employeeManager(&dbConnection);
  
  employeeManager.setSalary(50, 6000); 
}

// Instantiate Test Suite

/*********************************************************/


/**********PARAMETIZED TEST CASES**********

// TESTS

// Validator (5, 10)
// Below lower boundary, lower boundary, middle, upper boundary, above upper boundary (5 Test Cases)
// 4,5,7,10,11 

// Create Validator Test Fixture

class ValidatorFixture : public testing::TestWithParam<std::tuple<int, bool>>
{
  public:
  
  protected:
    
    Validator mValidator {5, 10};  
};

// TESTS

TEST_P(ValidatorFixture, TestInRange)
{
  // ARRANGE
  // Get input parameters from testing::Values()
  std::tuple<int, bool> tuple = GetParam();
  
  int param = std::get<0>(tuple);
  
  bool expectedValue = std::get<1>(tuple);
  
  std::cout << "Param = " << param << " expected value = " << expectedValue << "\n";
  // ACT
  bool isInside = mValidator.inRange(param);
  // ASSERT
  ASSERT_EQ(expectedValue, isInside);
}
// Instantiate Test Suite
INSTANTIATE_TEST_SUITE_P(InRangeTrue, ValidatorFixture, testing::Values(
                          std::make_tuple(-50, false),
                          std::make_tuple(4, false),
                          std::make_tuple(5, true),
                          std::make_tuple(6, true),
                          std::make_tuple(7, true),
                          std::make_tuple(9, true),
                          std::make_tuple(10, true),
                          std::make_tuple(11, false),
                          std::make_tuple(100, false)));

// TEST_P(ValidatorNegativeFixture, TestNotInRange)
// {
//   // ARRANGE
//   // Get input parameters
//   int param = GetParam();
//   std::cout << "\nParam not in range = " << param << "\n\n";
//   // ACT
//   bool isInside = mValidator.inRange(param);
//   // ASSERT
//   ASSERT_FALSE(isInside);
// }
// // Instantiate Test Suite
// INSTANTIATE_TEST_SUITE_P(InRangeFalse, ValidatorNegativeFixture, testing::Values(-50, 4, 11, 100));

/******************************************/


/**********ACCOUNT CLASS TEST CASES**********

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

// TESTS

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

/******************************************/


/**********SIMPLE TEST CASES**********

// Simple Test Case for simple function
TEST(TestSample, TestAddition)
{
  ASSERT_EQ(2, add(1, 1));
}

TEST(SquareRootTest, PosArgTest)
{
  // Arrange
  double inputVal = -9;
  // Act
  // Assert
  ASSERT_THROW(mySqrt(inputVal), std::runtime_error);
}

/*************************************/


/**********INITIAL TEST CASES**********

TEST(SquareRootTest, NegArgTest)
{
  // Arrange
  double inputVal = 9;
  // Act
  // Assert
  ASSERT_NO_THROW(mySqrt(inputVal));
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
  //char expectedVal[] = "HELLO WORLD";
  // Act
  toUpper(inputString);
  // Assert
  //EXPECT_EQ(0, strcmp(expectedVal, inputString));
  EXPECT_STREQ("HELLO WORLD", inputString);
  // If not C-style string:
  std::string str(inputString);
  // Assert
  EXPECT_EQ("HELLO WORLD", str);
}

/*************************************/


/**********TEST RUNNER MAIN**********/

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}

/************************************/