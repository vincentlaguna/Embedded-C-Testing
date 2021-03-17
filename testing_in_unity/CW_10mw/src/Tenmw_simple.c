#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#define  SQUARE_DIMENSION 22

char gridSquare[SQUARE_DIMENSION][SQUARE_DIMENSION] =
  {
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  };

bool isValidWalk(const char *walk) 
{
  int  count               = 0;
  bool isValidWalkLength   = false;
  
  while (*walk)
  {
    *walk++;
    ++count;
  }
  if (count == 10)
    isValidWalkLength = true;
 
  if (isValidWalkLength)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool moveWalker(const char *walk, char *grid, int n)
{
  int   row       = 11;
  int   position  = 11;
  //char  home = *(grid + (row * SQUARE_DIMENSION) + position);
  //int   home = &grid + (row * SQUARE_DIMENSION) + position;
  char  marker = 'X';
  
  for (int x = 0; x < SQUARE_DIMENSION; x++)
  {
    for (int y = 0; y < SQUARE_DIMENSION; y++)
    {
      *(grid + ((x * SQUARE_DIMENSION) + y)) = '0';
      printf("%c ", *(grid + ((x * SQUARE_DIMENSION) + y)));
    }
    printf("\n");
  }
  printf("\n");
  
  for (; *walk != '\0'; *walk++)
  {
    switch (*walk)
    {
      case 'n':
        //marker = *(grid + (row-- * n) + position);
        *(grid + (row-- * n) + position) = marker;
        break;
      case 's': 
        //marker = *(grid + (row-- * n) + position);
        *(grid + (row++ * n) + position) = marker;
        break;
      case 'e':
        //marker = *(grid + (row-- * n) + position);
        *(grid + (row * n) + position--) = marker;
        break;
      case 'w':
        //marker = *(grid + (row-- * n) + position);
        *(grid + (row * n) + position++) = marker;
        break;
    }
    
    for (int x = 0; x < SQUARE_DIMENSION; x++)
    {
      for (int y = 0; y < SQUARE_DIMENSION; y++)
      {
        printf("%c ", *(grid + ((x * SQUARE_DIMENSION) + y)));
      }
    printf("\n");
    }
  printf("\n");
  sleep(1);
  }
  
  for (int x = 0; x < SQUARE_DIMENSION; x++)
  {
    for (int y = 0; y < SQUARE_DIMENSION; y++)
    {
      //*(pGrid + ((x * SQUARE_DIMENSION) + y)) = '0';
      printf("%c ", *(grid + ((x * SQUARE_DIMENSION) + y)));
    }
    printf("\n");
  }
  printf("\n");
  
  if (marker == *(grid + (row * SQUARE_DIMENSION) + position))
  //if (&marker == home)
    return true;
  return false;
}

int main(void)
{
  char        *pGrid;
  pGrid      = (char *)malloc(sizeof(gridSquare));
  // Need to create a random char generator to produce a large amount of input
  // for testing
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
  
  if (isValidWalk(walk) && moveWalker(walk, pGrid, SQUARE_DIMENSION))
  {
    printf("Length and Move Pass\n");
  }
  else
  {
    printf("Fail\n");
  }
  
  free(pGrid);
  return(0);
}