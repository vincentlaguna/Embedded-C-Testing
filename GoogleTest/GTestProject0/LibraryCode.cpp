#include "LibraryCode.hpp"
#include <algorithm>

// Simple Function Definition
int add(int a, int b)
{
  return a + b;
}

bool isPositive(int x)
{
  return x >= 0;
}

int countPositives(std::vector<int> const &inputVector)
{
  return std::count_if(inputVector.begin(), inputVector.end(), isPositive);
}