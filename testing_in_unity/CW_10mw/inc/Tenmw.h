#ifndef TENMW_H
#define TENMW_H
#include <stdbool.h>

const char *walk = {"nsnsnsnsns"};

bool isValidWalk(const char *walk) 
{
  if ((sizeof(walk) / sizeof(walk[0])) != 10)
      return false;
}

#endif //TENMW_H