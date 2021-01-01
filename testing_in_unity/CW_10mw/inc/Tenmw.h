#ifndef TENMW_H
#define TENMW_H

#include <stdbool.h>

extern char gridSquare[11][11];

void displayBoard(void);

bool isValidWalkLength(const char *walk);

char *moveWalker(char *walk);

#endif //TENMW_H