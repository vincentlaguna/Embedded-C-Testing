#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define  SQUARE_DIMENSION 11

char gridSquare[SQUARE_DIMENSION][SQUARE_DIMENSION] =
  {
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
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
  
  for (int x = 0; x < SQUARE_DIMENSION; x++)
  {
    for (int y = 0; y < SQUARE_DIMENSION; y++)
    {
      *(pGrid + ((x * SQUARE_DIMENSION) + y)) = '0';
      printf("%c ", *(pGrid + ((x * SQUARE_DIMENSION) + y)));
    }
    printf("\n");
  }
  printf("\n");
  
  // for (int x = 0; x < SQUARE_DIMENSION; x++)
  // {
  //   for (int y = 0; y < SQUARE_DIMENSION; y++)
  //   {
  //     //*(pGrid + ((x * SQUARE_DIMENSION) + y)) = '0';
  //     printf("%c ", *(pGrid + ((x * SQUARE_DIMENSION) + y)));
  //   }
  //   printf("\n");
  // }
  // printf("\n");
  
  // if (marker == *(pGrid + (row * SQUARE_DIMENSION) + position))
  //   isBackHome = true;
  
  if (isValidWalkLength/* && isBackHome */)
    return true;
  return false;
  
  //free(pGrid);
}

bool moveWalker(const char *walk, char *grid, int n)
{
  int row = 5;
  int position = 5;
  //bool isBackHome = false;
  char marker = 'X';
  
  for (; *walk != '\0'; *walk++)
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
    }
  }
  if (marker == *(grid + (row * n) + position))
    return true;
  return false;
}

int main(void)
{
  char        *pGrid;
  pGrid      = gridSquare;
  char *walk = {"nnwwwsseee"}; // Pass
  //char *walk = {"nsnwensses"}; // Not Valid Move
  //char *walk = {"nsnwensse"}; // Not Valid Length and Move
  
  if (isValidWalk(walk) && moveWalker(walk, pGrid, SQUARE_DIMENSION))
  {
    printf("Length and Move Pass\n");
  }
  else
  {
    printf("Fail\n");
  }

  return(0);
}