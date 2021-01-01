#ifndef TENMW_H
#define TENMW_H

#include <stdbool.h>

extern char gridSquare[11][11];

void displayBoard(void);

bool isValidWalkLength(const char *walk);

bool isValidWalk(char *pGridPosition);

void moveWalker(char gridSquare[][11]);

#endif //TENMW_H