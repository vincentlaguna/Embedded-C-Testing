#ifndef REFLEX_H
#define REFLEX_H
#include <stdint.h>
#define ON 1
#define OFF 0

typedef struct
{
  uint8_t LED_1 :1;
  uint8_t LED_2 :1;
  uint8_t LED_3 :1;
  uint8_t LED_4 :1;
  uint8_t LED_5 :1;
  uint8_t LED_6 :1;
  uint8_t         :2;
}LEDS;

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

int Buttons_Init(void);

#endif //REFLEX_H