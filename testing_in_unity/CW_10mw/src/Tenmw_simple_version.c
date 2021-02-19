#include <stdio.h>
#include <stdbool.h>
#define  SQUARE_DIMENSION 11

bool isValidWalk(const char *walk);

int main(void)
{
  char *walk = {"nnwwwsseen"};
  
  isValidWalk(walk) ? puts("True") : puts("False");
  
  return(0);
}

bool isValidWalk(const char *walk) 
{
  
  // Creating 2D array grid on the stack
  char gridSquare[SQUARE_DIMENSION][SQUARE_DIMENSION] =
  {
    {'0','0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0','0'},
    {'0','0','0','0','0','0','0','0','0','0','0'},
  };
  
  // Creating pointer of type char to point to the 2D arrary grid
  char                       *pGrid;
  pGrid                     = gridSquare;
  
  // Local Variables
  int count                 = 0;
  int row                   = 5;
  int position              = 5;
  char marker               = 'X';
  
  // Booleans
  bool isValidWalkLength    = false;
  bool isWalkerBackHome     = false;
  
  // While Loop to iterate over the char array function argument
  while (*walk)
  {
    *walk++;
    count++;
  } 
  // Validate char array is of 10 characters
  if (count == 10)
    isValidWalkLength = true;
    
  // While Loop to iterate over char array with nested
  // Switch-Case statement to assign (and keep track of) marker
  // upon each character given as direction to move
  while (*walk)
  {
    switch (*walk)
    {
      case 'n': *(pGrid + (row-- * SQUARE_DIMENSION) + position) = marker;
        break;
      case 's': *(pGrid + (row++ * SQUARE_DIMENSION) + position) = marker;
        break;
      case 'e': *(pGrid + (row * SQUARE_DIMENSION) + position--) = marker;
        break;
      case 'w': *(pGrid + (row * SQUARE_DIMENSION) + position++) = marker;
        break;
    }
  }
  // Check if marker is back in the home position
  if (marker == *(pGrid + (row * SQUARE_DIMENSION) + position))
    isWalkerBackHome = true;

  // Final check for single boolean return: check both requirements == true
  if (isValidWalkLength && isWalkerBackHome)
    return true;
  return false;
}