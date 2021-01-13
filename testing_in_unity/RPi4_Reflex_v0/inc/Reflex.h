#ifndef REFLEX_H
#define REFLEX_H
#include <stdint.h>

typedef struct
{
  int button1;
  int button2;
}Buttons;

int init_Buttons(void);

#endif //REFLEX_H