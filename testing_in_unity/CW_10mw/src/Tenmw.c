/***********************************************************************************
* You live in the city of Cartesia where all roads are laid out in a perfect grid. *
* You arrived ten minutes too early to an appointment, so you decided to take      *
* the opportunity to go for a short walk. The city provides its citizens with a    *
* Walk Generating App on their phones -- everytime you press the button it sends   *
* you an array of one-letter strings representing directions to walk               *
* (eg. ['n', 's', 'w', 'e']). You always walk only a single block                  * 
* for each letter (direction) and you know it takes you one minute to              *
* traverse one city block, so create a function that will return true if           *
* the walk the app gives you will take you exactly ten minutes                     *
* (you don't want to be early or late!) and will, of course,                       *
* return you to your starting point. Return false otherwise.                       *
*                                                                                  *
* **********************************************************************************/
#define _CW
#ifndef _CW
/******************** NCW ***********************
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../inc/Tenmw.h"
#define _TEST

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

#ifdef _TEST
int Tenmw(void)
{
#endif

#ifndef _TEST
int main(void)
{
#endif

  // char *pGrid = NULL;
  void *pGrid = NULL;
  pGrid = gridSquare;
  
  // char *walk = {"nnwwwsseee"}; // Valid
  char *walk = {"eeeeeennnn"}; // Not Valid - Out of bounds
  //char *walk = {"nsnwensses"}; // Not Valid
  
#ifndef _TEST
    
  displayBoard();
  // displayGrid(pGrid, SQUARE_DIMENSION);
  moveWalkerHome(walk, pGrid, SQUARE_DIMENSION);
#endif
  
  return(0);
}

void displayBoard(void)
{
  //system("clear");
  // printf("\n\n\tTen Minute walk grid\n\n");
  // printf("\n\n\tWalker [x] - Home ['0']\n\n\n"); 
  
  printf("\t _________________________________________________________________ \n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[0][0], gridSquare[0][1], gridSquare[0][2], gridSquare[0][3], gridSquare[0][4], gridSquare[0][5], gridSquare[0][6], gridSquare[0][7], gridSquare[0][8], gridSquare[0][9], gridSquare[0][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[1][0], gridSquare[1][1], gridSquare[1][2], gridSquare[1][3], gridSquare[1][4], gridSquare[1][5], gridSquare[1][6], gridSquare[1][7], gridSquare[1][8], gridSquare[1][9], gridSquare[1][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[2][0], gridSquare[2][1], gridSquare[2][2], gridSquare[2][3], gridSquare[2][4], gridSquare[2][5], gridSquare[2][6], gridSquare[2][7], gridSquare[2][8], gridSquare[2][9], gridSquare[2][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[3][0], gridSquare[3][1], gridSquare[3][2], gridSquare[3][3], gridSquare[3][4], gridSquare[3][5], gridSquare[3][6], gridSquare[3][7], gridSquare[3][8], gridSquare[3][9], gridSquare[3][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[4][0], gridSquare[4][1], gridSquare[4][2], gridSquare[4][3], gridSquare[4][4], gridSquare[4][5], gridSquare[4][6], gridSquare[4][7], gridSquare[4][8], gridSquare[4][9], gridSquare[4][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[5][0], gridSquare[5][1], gridSquare[5][2], gridSquare[5][3], gridSquare[5][4], gridSquare[5][5], gridSquare[5][6], gridSquare[5][7], gridSquare[5][8], gridSquare[5][9], gridSquare[5][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[6][0], gridSquare[6][1], gridSquare[6][2], gridSquare[6][3], gridSquare[6][4], gridSquare[6][5], gridSquare[6][6], gridSquare[6][7], gridSquare[6][8], gridSquare[6][9], gridSquare[6][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[7][0], gridSquare[7][1], gridSquare[7][2], gridSquare[7][3], gridSquare[7][4], gridSquare[7][5], gridSquare[7][6], gridSquare[7][7], gridSquare[7][8], gridSquare[7][9], gridSquare[7][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[8][0], gridSquare[8][1], gridSquare[8][2], gridSquare[8][3], gridSquare[8][4], gridSquare[8][5], gridSquare[8][6], gridSquare[8][7], gridSquare[8][8], gridSquare[8][9], gridSquare[8][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[9][0], gridSquare[9][1], gridSquare[9][2], gridSquare[9][3], gridSquare[9][4], gridSquare[9][5], gridSquare[9][6], gridSquare[9][7], gridSquare[9][8], gridSquare[9][9], gridSquare[9][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
  printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[10][0], gridSquare[10][1], gridSquare[10][2], gridSquare[10][3], gridSquare[10][4], gridSquare[10][5], gridSquare[10][6], gridSquare[10][7], gridSquare[10][8], gridSquare[10][9], gridSquare[10][10]);
  printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");

}

bool isValidWalkLength(const char *walk) 
{
  int ct = 0;
  
  while (*walk)
  {
    *walk++;
    ++ct;
  }
  if (ct == 10)
    return true;
  false;
}

void displayGrid(char *grid, int n)
{
  for (int x = 0; x < n; x++)
  {
    for (int y = 0; y < n; y++)
    {
      printf("%c ", *(grid + ((x * n) + y)));
    }
    printf("\n");
  }
  printf("\n");
}

bool moveWalkerHome(const char *walk, char *grid, int n)
{
  // Implement a for loop that can iterate over each char of walk, then create a switch case during
  // the loop which assigns the correct position according to each char being iterated?
  // I think that might be the right idea, we will see...
  int row = 5;
  int position = 5;
  bool backHome = false;
  // bool outOfbounds = false;
  int boundary = 5;
  int nCount, sCount, eCount, wCount = 0;
  char marker = 'X';
  
  for (; *walk != '\0'; *walk++)
  //for (int direction = 0; *walk != '\0'; *walk++, direction++)
  {
    // #ifndef _TEST
    //   printf("%d = %c\n", direction, *walk);
    // #endif
    
    switch (*walk)
    {
      case 'n':
        *(grid + (row-- * n) + position) = marker;
        nCount++;
        break;
      case 's':
        *(grid + (row++ * n) + position) = marker;
        sCount++;
        break;
      case 'e':
        *(grid + (row * n) + position--) = marker;
        eCount++;
        break;
      case 'w':
        *(grid + (row * n) + position++) = marker;
        wCount++;
        break;
    }
    
  #ifndef _TEST
    
    displayGrid(grid, SQUARE_DIMENSION);
    displayBoard();
    sleep(1);
    
  #endif
  
  }
  
  // printf("\ncount = %d\n", eCount); // Debug... 
  if (marker == *(grid + (row * n) + position))
  {
    backHome = true;
    
  #ifndef _TEST
    
    displayWinBoard();
  
  #endif
    
    printf("\nWalker is Back Home!\n");
    return true;
  }
  if ((nCount) || (sCount) || (eCount) || (wCount) > boundary) // Freaking parenthesis... really?
  {
    printf("\nSorry, walker went out of bounds!\n");
    return false;
  }
  else
  {
    printf("\nSorry, walker did not make it back home...\n");
    return false;
  }
}  

void displayWinBoard(void)
{
  char *pMsg0 = "Im...";
  char *pMsg1 = "Home!";
  
  for (int x = 0; x < SQUARE_DIMENSION; x++)
  {
    for (int y = 0; y < SQUARE_DIMENSION; y++)
    {
      gridSquare[x][y] = ' ';
    }
  }
  
  for (int i = 0; i < 5; i++)
  {
    gridSquare[4][3 + i] = *pMsg0++;
    gridSquare[5][3 + i] = *pMsg1++;
  
    printf("\t _________________________________________________________________ \n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[0][0], gridSquare[0][1], gridSquare[0][2], gridSquare[0][3], gridSquare[0][4], gridSquare[0][5], gridSquare[0][6], gridSquare[0][7], gridSquare[0][8], gridSquare[0][9], gridSquare[0][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[1][0], gridSquare[1][1], gridSquare[1][2], gridSquare[1][3], gridSquare[1][4], gridSquare[1][5], gridSquare[1][6], gridSquare[1][7], gridSquare[1][8], gridSquare[1][9], gridSquare[1][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[2][0], gridSquare[2][1], gridSquare[2][2], gridSquare[2][3], gridSquare[2][4], gridSquare[2][5], gridSquare[2][6], gridSquare[2][7], gridSquare[2][8], gridSquare[2][9], gridSquare[2][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[3][0], gridSquare[3][1], gridSquare[3][2], gridSquare[3][3], gridSquare[3][4], gridSquare[3][5], gridSquare[3][6], gridSquare[3][7], gridSquare[3][8], gridSquare[3][9], gridSquare[3][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[4][0], gridSquare[4][1], gridSquare[4][2], gridSquare[4][3], gridSquare[4][4], gridSquare[4][5], gridSquare[4][6], gridSquare[4][7], gridSquare[4][8], gridSquare[4][9], gridSquare[4][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[5][0], gridSquare[5][1], gridSquare[5][2], gridSquare[5][3], gridSquare[5][4], gridSquare[5][5], gridSquare[5][6], gridSquare[5][7], gridSquare[5][8], gridSquare[5][9], gridSquare[5][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[6][0], gridSquare[6][1], gridSquare[6][2], gridSquare[6][3], gridSquare[6][4], gridSquare[6][5], gridSquare[6][6], gridSquare[6][7], gridSquare[6][8], gridSquare[6][9], gridSquare[6][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[7][0], gridSquare[7][1], gridSquare[7][2], gridSquare[7][3], gridSquare[7][4], gridSquare[7][5], gridSquare[7][6], gridSquare[7][7], gridSquare[7][8], gridSquare[7][9], gridSquare[7][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[8][0], gridSquare[8][1], gridSquare[8][2], gridSquare[8][3], gridSquare[8][4], gridSquare[8][5], gridSquare[8][6], gridSquare[8][7], gridSquare[8][8], gridSquare[8][9], gridSquare[8][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[9][0], gridSquare[9][1], gridSquare[9][2], gridSquare[9][3], gridSquare[9][4], gridSquare[9][5], gridSquare[9][6], gridSquare[9][7], gridSquare[9][8], gridSquare[9][9], gridSquare[9][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", gridSquare[10][0], gridSquare[10][1], gridSquare[10][2], gridSquare[10][3], gridSquare[10][4], gridSquare[10][5], gridSquare[10][6], gridSquare[10][7], gridSquare[10][8], gridSquare[10][9], gridSquare[10][10]);
    printf("\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  
    sleep(1.0);
  }
}

/******************** NCW ***********************/

#endif // 

#ifdef _CW

/*****CodeWars Implementation*****/

#include                    <stdio.h>
#include                    <stdlib.h>
#include                    <stdbool.h>
#define                     SQUARE_DIMENSION 11

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
  void *pGrid               = (char *)malloc(sizeof(gridSquare));
  pGrid                     = gridSquare;
  // Define local variables
  int   charCount           = 0;
  int   row                 = 5;
  int   position            = 5;
  int   boundary            = 5;
  int   nCount              = 0;
  int   sCount              = 0;
  int   eCount              = 0;
  int   wCount              = 0;
  char  marker              = 'X';
  // Define Booleans
  bool isValidWalkLength    = false;
  bool isWalkerHome         = false;
  bool isWalkerWithinBounds = false;
  
  // Confirm Walk Length
  while (*walk)
  {
    *walk++;
    ++charCount;
  }
  
  if (charCount == 10)
  { 
    isValidWalkLength       = true;
    printf("charCount = [%d]\n", charCount); // Debug...
  }
  else
  {
    isValidWalkLength       = false;
    printf("charCount = [%d]\n", charCount); // Debug...
  }
//   // Confirm Walker Made it Home
//   for (; *walk != '\0'; *walk++)
//   {
//     switch (*walk)
//     {
//       case 'n':
//         *(pGrid + (row-- * SQUARE_DIMENSION) + position) = marker;
//         nCount++;
//         break;
//       case 's':
//         *(pGrid + (row++ * SQUARE_DIMENSION) + position) = marker;
//         sCount++;
//         break;
//       case 'e':
//         *(pGrid + (row * SQUARE_DIMENSION) + position--) = marker;
//         eCount++;
//         break;
//       case 'w':
//         *(pGrid + (row * SQUARE_DIMENSION) + position++) = marker;
//         wCount++;
//         break;
//       }
//   }
  
//   if (marker == *(pGrid + (row * SQUARE_DIMENSION) + position))
//   isWalkerHome            = true;

//   if ((nCount) || (sCount) || (eCount) || (wCount) < boundary)
//   isWalkerWithinBounds    = true;

//   if ((isValidWalkLength) && (isWalkerHome) && (isWalkerWithinBounds) != false)
  
  if (isValidWalkLength)
        return true;
  return false;
}

int main(void)
{
  // char *pGrid = NULL;
  // void *pGrid = NULL;
  // pGrid = gridSquare;
  
  char *walk = {"nnwwwsseee"}; // Valid
  // char *walk = {"eeeeeennnn"}; // Not Valid - Out of bounds Length
  //char *walk = {"nsnwensse"}; // Not Valid
  //char *walk = {"nsnwensses"}; // Not Valid
  
  // if (isValidWalk(walk))
  //   printf("PASSED...\n");
  // printf("No Egg...\n");

  (isValidWalk(walk)) ? printf("PASSED...\n") : printf("No Egg...\n"); 
    
  return(0);
}

/*********************************/
#endif // _CW