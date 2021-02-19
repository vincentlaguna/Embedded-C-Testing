#include <stdbool.h>
#define SQUARE_DIMENSION 11


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
  //char *walk              = {"nnwwwsseee"}; // For Testing
  
  // Local Variables
  int count                 = 0;
  int row                   = 5;
  int position              = 5;
  
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
}