#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "LibraryCode.hpp"

/*************************************/

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
  // std::cout << "Actual Application Code: \n";
  // std::cout << "2 + 3 = " << add(2, 3) << "\n";
  
  // return RUN_ALL_TESTS();
}

/*************************************/