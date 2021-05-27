#include "LibraryCode.hpp"
#include <iostream>
#include <stdexcept>
// #include <string.h>
// #include <algorithm>
// #include <math.h>
// #include <cctype>
// Simple Function Definition

Account::Account()
: mBalance {0} {}

void Account::deposit(double amount)
{
  mBalance += amount;
}

void Account::withdraw(double amount)
{
  if (mBalance < amount)
  {
    std::cout << "Exception Thrown\n";
    throw std::runtime_error("Insufficient Funds");
  }
  mBalance -= amount;
}

double Account::getBalance() const
{
  return mBalance;
}

void Account::transfer(Account &to, double amount)
{
    
}

// int add(int a, int b)
// {
//   return a + b;
// }

// double mySqrt(double input)
// {
//   if (input < 0)
//   {
//     std::cout << "Exception Thrown\n";
//     throw std::runtime_error("Negative Argument!");
//   }
//   std::cout << "No Exception Thrown.\n";
//   return sqrt(input);
// }

// // Used in the countPositives() function
// bool isPositive(int x)
// {
//   return x >= 0;
// }
// // Count the number of positive occurrences in the inputVector
// int countPositives(std::vector<int> const &inputVector)
// {
//   return std::count_if(inputVector.begin(), inputVector.end(), isPositive);
// }
// // Convert chars to uppercase in c-style *string
// void toUpper(char *inputString)
// {
//   for (unsigned int i = 0; i < strlen(inputString); i++)
//   {
//     inputString[i] = toupper(inputString[i]);
//   }
// }