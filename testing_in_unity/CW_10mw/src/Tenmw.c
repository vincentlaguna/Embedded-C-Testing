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
#include <stdio.h>
#include "../inc/Tenmw.h"
//#define _TEST

char gridSquare[11][11] =
{
  {'0','0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','H','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0','0'},
};

#ifdef _TEST
int Tenmw(void)
{
#endif

#ifndef _TEST
int main(void)
{
#endif

  displayBoard();
  char *walk = {"nsnsnsnsns"};
  
  if (isValidWalk(walk))
    printf("It was 10 chars!\n");
  else
    printf("Nope, not ten or your code SUCKS!\n");
//   char direction;
//   int size = 0;
//   char *s;
  
//   for (s = walk; s != '\0'; s++)
//     size++;
//   printf("%d", size);//worthless... 
  
  //switch (direction)
  //gridSquare[4][5];
  // while (walk != '\0')
  // {
  //   printf("%s", walk);
  // }
  // displayBoard(); / This is FUTILE!!!
  return(0);
}

void displayBoard(void)
{
  //system("clear");
  printf("\n\n\tTen Minute walk grid\n\n");
  printf("\n\n\tWalker [x] - Home ['0']\n\n\n"); 
  
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
  
  printf("\n\n");
  
}

bool isValidWalk(const char *walk) 
{
  int ct = 0;
  
  while (*(walk) != '\0')
  {
    *walk++;
    ++ct;
  }
  if (ct == 10)
    return true;
  false;
}