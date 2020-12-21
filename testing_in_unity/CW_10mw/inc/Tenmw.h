#ifndef TENMW_H
#define TENMW_H
#include <stdbool.h>

int isValidWalk(const char *walk) 
{
  if ((sizeof(walk) / sizeof(walk[0])) != 10)
      printf("%d\n", sizeof(walk) / sizeof(walk[0]));
      return 0;
  return 1;
}

#endif //TENMW_H