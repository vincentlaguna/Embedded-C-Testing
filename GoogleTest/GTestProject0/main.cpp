#include <iostream>
// #include <gtest/gtest.h>
// #include <gmock/gmock.h>
#include "IDatabaseConnection.hpp"
#include "Employee.hpp"
#include "EmployeeManager.hpp"
// #include "LibraryCode.hpp"

/**********GMOCK CLASS TEST CASES**********

class SomeClass
{
  public:
    
    SomeClass() = default;
    
    virtual void someMethod()
    {
      std::cout << "\nTesting someMethod() function in SomeClass class\n";
    };
};

class MockedClass : public SomeClass
{
  public:
    
    MockedClass() = default;
    MOCK_METHOD0(someMethod, void());
};

TEST(TestSample, TestMock)
{
  // Arrange
  MockedClass mc;
  // Act
  // Assert
  EXPECT_CALL(mc, someMethod()).Times(1);
  mc.someMethod();
}

/******************************************/


/**********SIMPLE TEST CASES**********

// Simple Test Case for simple function (currently in TestRunner.cpp)

int add(int a, int b)
{
  return a + b;
}

TEST(TestSample, TestAddition)
{
  ASSERT_EQ(2, add(1, 1));
}

/*************************************/

int main(int argc, char **argv)
{
  // testing::InitGoogleTest(&argc, argv);
  std::cout << "Doing something with the library code\n";
  // std::cout << "Actual Application Code: \n";
  // std::cout << "2 + 3 = " << add(2, 3) << "\n";
  
  // return RUN_ALL_TESTS();
}

/*************************************/