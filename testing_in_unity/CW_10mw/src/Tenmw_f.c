#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#define SQUARE_DIMENSION 22

int main(void)
{
  // Char array used for input test
  char *walk = {"ewewewewew"}; // Pass
  //char *walk = {"nnwwwsseee"}; // Pass
  //char *walk = {"nsnsnsnsns"}; // Pass
  //char *walk = {"nsnwensse"}; // Not Valid Length and Move
  //char *walk = {"nnwwwssees"}; // Not Valid Move
  //char *walk = {"eeeewnwwww"}; // Not Valid Move
  //char *walk = {"wwwwwwwwww"}; // Not Valid Move
  //char *walk = {"nnnnnnnnnn"}; // Not Valid Move
  //char *walk = {"ssssssssss"}; // Not Valid Move
  //char *walk = {"eeeeeeeeee"}; // Not Valid Move
  // Declare 2-dimensional grid
  char gridSquare[SQUARE_DIMENSION][SQUARE_DIMENSION];
  char *pGrid = NULL;
  // Local Variables
  int row = 11;
  int position = 11;
  char marker = 'X';
  int count = 0;
  bool isValidWalkLength = false;
  bool isBackHome = false;
  // Check for valid string length on *walk
  while (*walk)
  {
    *walk++;
    ++count;
  }
  if (count == 10)
  {
    isValidWalkLength = true;
    printf("Walk is of valid length (10)\n");
  }
  else
  {
    printf("Walk is not of valid length -> %d\n", count);
  }
  // Move marker across 2D grid
  pGrid = gridSquare;
  
  for (; *walk != '\0'; *walk++)
  {
    switch (*walk)
    {
      case 'n':
        //marker = *(grid + (row-- * n) + position);
        *(pGrid + (row-- * SQUARE_DIMENSION) + position) = marker;
        break;
      case 's': 
        //marker = *(grid + (row-- * n) + position);
        *(pGrid + (row++ * SQUARE_DIMENSION) + position) = marker;
        break;
      case 'e':
        //marker = *(grid + (row-- * n) + position);
        *(pGrid + (row * SQUARE_DIMENSION) + position--) = marker;
        break;
      case 'w':
        //marker = *(grid + (row-- * n) + position);
        *(pGrid + (row * SQUARE_DIMENSION) + position++) = marker;
        break;
    }
    for (int x = 0; x < SQUARE_DIMENSION; x++)
    {
      for (int y = 0; y < SQUARE_DIMENSION; y++)
      {
        printf("%c ", *(pGrid + ((x * SQUARE_DIMENSION) + y)));
      }
    printf("\n");
    }
  printf("\n");
  sleep(1);
  }
  if (marker == *(pGrid + (row * SQUARE_DIMENSION) + position))
  {
    isBackHome = true;
    printf("Walker is back home!\n");
  }
  else
  {
    printf("Walker did not make it :(\n");
  }
    
  return(0);
}