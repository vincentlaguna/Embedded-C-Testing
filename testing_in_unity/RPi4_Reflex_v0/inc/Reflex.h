#ifndef REFLEX_H
#define REFLEX_H
#include <stdint.h>
#define ON 1
#define OFF 0

typedef struct
{
  uint8_t button1 :1;
  uint8_t button2 :1;
  uint8_t button3 :1;
  uint8_t button4 :1;
  uint8_t button5 :1;
  uint8_t button6 :1;
  uint8_t         :2;
}Buttons;

int init_Buttons(void);

#endif //REFLEX_H