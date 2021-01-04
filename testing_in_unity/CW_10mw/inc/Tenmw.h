#ifndef TENMW_H
#define TENMW_H

#include <stdbool.h>

//extern char gridSquare[11][11];

void displayBoard(void);

void displayGrid(const char *grid, int row, int col);

bool isValidWalkLength(const char *walk);

#endif //TENMW_H