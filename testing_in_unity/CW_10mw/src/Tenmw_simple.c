#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#define  SQUARE_DIMENSION   22
#define  MAX_RAND_NUM       4
//#define  RAND_WALK_TEST

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

bool isValidWalk(const char *walk);
bool moveWalker(const char *walk, char *grid, int n);
char *randomWalkGenerator(void);

int main(void)
{
  char         *pGrid;
  pGrid      = (char *)malloc(sizeof(gridSquare));
  
  // Need to create a random char generator to produce a large amount of input
  // for thorough testing
  
  //char *walk = {"ewewewewew"}; // Pass
  //char *walk = {"nnwwwsseee"}; // Pass
  //char *walk = {"nsnsnsnsns"}; // Pass
  //char *walk = {"nsnwensse"}; // Not Valid Length and Move
  //char *walk = {"nnwwwssees"}; // Not Valid Move
  //char *walk = {"eeeewnwwww"}; // Not Valid Move
  //char *walk = {"wwwwwwwwww"}; // Not Valid Move
  //char *walk = {"nnnnnnnnnn"}; // Not Valid Move
  //char *walk = {"ssssssssss"}; // Not Valid Move
  //char *walk = {"eeeeeeeeee"}; // Not Valid Move
  
  char *walk = randomWalkGenerator();
  moveWalker(walk, pGrid, SQUARE_DIMENSION);
  // for (int i = 0; i < 20; i++)
  // {
  //   moveWalker(randomWalkGenerator(), pGrid, SQUARE_DIMENSION);
  // }

  // if (isValidWalk(walk) && moveWalker(randomWalkGenerator(), pGrid, SQUARE_DIMENSION))
  // {
  //   printf("Length and Move Pass\n\n");
  // }
  // else
  // {
  //   printf("Fail\n\n");
  // }
  //randomWalkGenerator();
  free(pGrid);
  return(0);
}

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
      *(grid + ((x * SQUARE_DIMENSION) + y)) = ' ';
      printf("%c ", *(grid + ((x * SQUARE_DIMENSION) + y)));
    }
    printf("\n");
  }
  printf("\n");
  
  for (int i = 0; *walk != '\0'; i++, *walk++)
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
    printf("%d\n", i);
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
  //return false;
}

char* randomWalkGenerator(void)
{
  char  randomWalk[11] = {'\0'};
  char *pWalk = malloc(11);
  int   charNum     = 0;
  
  srand((unsigned) time(NULL));
  
  for (int i = 0; i < 10; i++)
  {
    charNum = rand() % MAX_RAND_NUM + 1;
    switch (charNum)
    {
      case 1: randomWalk[i] = 'n';
        break;
      case 2: randomWalk[i] = 's';
        break;
      case 3: randomWalk[i] = 'e';
        break;
      case 4: randomWalk[i] = 'w';
        break;
    }
    //printf("%d\n", charNum);
  }
  printf("\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%c", randomWalk[i]);
  }
  printf("\n");
  pWalk = randomWalk;
  printf("%s\n", pWalk);
  return pWalk;
}