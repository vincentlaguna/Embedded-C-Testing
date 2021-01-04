#ifndef TENMW_H
#define TENMW_H

#include <stdbool.h>

//extern char gridSquare[11][11];

void displayBoard(void);

void displayGrid(char *grid, int n);

bool isValidWalkLength(const char *walk);

#endif //TENMW_H