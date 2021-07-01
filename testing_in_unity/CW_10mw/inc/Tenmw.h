#ifndef     TENMW_H

#define     TENMW_H
#define     SQUARE_DIMENSION 11
#include    <stdlib.h>
#include    <stdbool.h>

extern char gridSquare[SQUARE_DIMENSION][SQUARE_DIMENSION];

void        displayBoard(void);

void        displayWinBoard(void);

void        displayGrid(char *grid, int n);

bool        isValidWalkLength(const char *walk);

bool        moveWalkerHome(const char *walk, char *grid, int n);

/**********  Random Char Generator  **********/

void /*char*/        randomCharGenerator(void)
{
  printf("\n\tTesting Random Char Function\n\n");
}

/*********************************************/

#endif //TENMW_H