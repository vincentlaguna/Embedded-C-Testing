#include <stdio.h>
#include <stdbool.h>
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
  return(0);
}