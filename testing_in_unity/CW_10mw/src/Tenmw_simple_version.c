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
  
  // Local Variables
  int count                 = 0;
  int row                   = 5;
  int position              = 5;
  
  // Booleans
  bool isValidWalkLength    = false;
  bool 
}