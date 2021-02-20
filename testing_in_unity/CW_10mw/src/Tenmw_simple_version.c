#include <stdio.h>
#include <stdbool.h>
#define  SQUARE_DIMENSION 11

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

bool isValidWalk(const char *walk);
bool moveWalkerHome(const char *walk, char *grid, int n);

int main(void)
{
  char *walk = {"nnwwwsseen"};
  
  isValidWalk(walk) ? puts("True") : puts("False");
  
  return(0);
}

bool isValidWalk(const char *walk) 
{
  
  // Creating pointer of type char to point to the 2D arrary grid
  char                       *pGrid;
  pGrid                     = gridSquare;
  char *walk                = {"nnwwwsseen"};
  
  // Local Variables
  int count                 = 0;
  int row                   = 5;
//   int position              = 5;
//   char marker               = 'X';
  
  // Booleans
  bool isValidWalkLength    = false;
  bool isWalkerBackHome     = false;
  
  // While Loop to iterate over the char array function argument
  while (*walk)
  {
    *walk++;
    ++count;
  } 
  // Validate char array is of 10 characters
  if (count == 10)
    isValidWalkLength = true;
  if (isValidWalkLength)
    printf("It is 10\n");
    
  // While Loop to iterate over char array with nested
  // Switch-Case statement to assign (and keep track of) marker
  // upon each character given as direction to move
//   for (int i = 0; *walk != '\0'; *walk++, i++)
//   {
//     switch (*walk)
//     {
//       case 'n': *(pGrid + (row-- * SQUARE_DIMENSION) + position) = marker;
//         break;
//       case 's': *(pGrid + (row++ * SQUARE_DIMENSION) + position) = marker;
//         break;
//       case 'e': *(pGrid + (row * SQUARE_DIMENSION) + position--) = marker;
//         break;
//       case 'w': *(pGrid + (row * SQUARE_DIMENSION) + position++) = marker;
//         break;
//     }
//   }
  // Check if marker is back in the home position
  if (moveWalkerHome(walk, pGrid, SQUARE_DIMENSION)
    isWalkerBackHome = true;

  if (isWalkerBackHome)
    printf("Walker is back Home!\n");

  // Final check for single boolean return: check both requirements == true
  if (isValidWalkLength && isWalkerBackHome)
    return true;
  return false;
}

bool moveWalkerHome(const char *walk, char *grid, int n)
{
  // Implement a for loop that can iterate over each char of walk, then create a switch case during
  // the loop which assigns the correct position according to each char being iterated?
  // I think that might be the right idea, we will see...
  int row = 5;
  int position = 5;
  bool backHome = false;
  char marker = 'X';
  
  for (int direction = 0; *walk != '\0'; *walk++, direction++)
  {
    switch (*walk)
    {
      case 'n':
        *(grid + (row-- * n) + position) = marker;
        break;
      case 's':
        *(grid + (row++ * n) + position) = marker;
        break;
      case 'e':
        *(grid + (row * n) + position--) = marker;
        break;
      case 'w':
        *(grid + (row * n) + position++) = marker;
        break;
      //default:
        //printf("Somthing is wrong with the *char input! Exiting the H*** out!...\n");
    }
    
    if (marker == *(grid + (row * n) + position))
    {
      backHome = true;
      printf("\nWalker is Back Home!\n");
      return true;
    }
    else
    {
      printf("\nSorry, walker did not make it back home...\n");
      return false;
    }
  }