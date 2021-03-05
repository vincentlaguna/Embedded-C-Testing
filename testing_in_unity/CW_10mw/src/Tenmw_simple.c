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
    return true;
  return false;
}

bool moveWalker(const char *walk, char *grid, int n)
{
  int row = 11;
  int position = 11;
  char marker = 'X';
  
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
    return true;
  return false;
}

int main(void)
{
  char        *pGrid;
  pGrid      = (char *)malloc(sizeof(gridSquare));
  //char *walk = {"nnwwwsseee"}; // Pass
  //char *walk = {"nsnsnsnsns"}; // Pass
  char *walk = {"nnnnnsssss"}; // Not Valid Move
  //char *walk = {"nsnwensse"}; // Not Valid Length and Move
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