#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SQUARE_DIMENSION 11

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
  char                      *pGrid;
  char marker              = 'X';
  char                      *pMarker;
  pMarker                  = &marker;
  pGrid                    = (char *)malloc(sizeof(gridSquare));
  int  count               = 0;
  int  row                 = 5;
  int  position            = 5;
  bool isBackHome          = false;
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
  
  for (; *walk != '\0'; *walk++)
  {
    switch (*walk)
    {
      case 'n': 
        *(pGrid + (row-- * SQUARE_DIMENSION) + position) = *pMarker;
        break;
      case 's': 
        *(pGrid + (row++ * SQUARE_DIMENSION) + position) = *pMarker;
        break;
      case 'e':
        *(pGrid + (row * SQUARE_DIMENSION) + position--) = *pMarker;
        break;
      case 'w':
        *(pGrid + (row * SQUARE_DIMENSION) + position++) = *pMarker;
        break;
    }
  }
  
  for (int x = 0; x < SQUARE_DIMENSION; x++)
  {
    for (int y = 0; y < SQUARE_DIMENSION; y++)
    {
      //*(pGrid + ((x * SQUARE_DIMENSION) + y)) = '0';
      printf("%c ", *(pGrid + ((x * SQUARE_DIMENSION) + y)));
    }
    printf("\n");
  }
  printf("\n");
  
  if (*pMarker == *(pGrid + (row * SQUARE_DIMENSION) + position))
    isBackHome = true;
  
  if (isValidWalkLength && isBackHome)
    return true;
  return false;
  
  free(pGrid);
}

int main(void)
{
  char *walk = {"nnwwwsseee"};
  
  if (isValidWalk(walk))
  {
    printf("Pass\n");
  }
  else
  {
    printf("Fail\n");
  }
  return(0);
}