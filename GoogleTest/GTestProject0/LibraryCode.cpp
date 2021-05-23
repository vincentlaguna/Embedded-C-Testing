#include "LibraryCode.hpp"
#include <algorithm>
#include <cctype>
#include <string.h>

// Simple Function Definition
int add(int a, int b)
{
  return a + b;
}
// Used in the countPositives() function
bool isPositive(int x)
{
  return x >= 0;
}
// Count the number of positive occurrences in the inputVector
int countPositives(std::vector<int> const &inputVector)
{
  return std::count_if(inputVector.begin(), inputVector.end(), isPositive);
}
// Convert chars to uppercase in c-style *string
void toUpper(char *inputString)
{
  for (unsigned int i = 0; i < strlen(inputString); i++)
  {
    inputString[i] = toupper(inputString[i]);
  }
}