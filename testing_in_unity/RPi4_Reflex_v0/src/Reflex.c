#include <stdio.h>
#include <stdlib.h>
#include "../inc/Reflex.h"

int Buttons_Init(void)
{
  Buttons *button;
  button = (Buttons *)malloc(sizeof(Buttons));
//   wiringPiSetup();
//   pinMode(LedPin, OUTPUT); 
//   pinMode(ButtonPin, INPUT);
//   pullUpDnControl(ButtonPin, PUD_UP); //pull up to 3.3V,make GPIO1 a stable level
  button->button1 = 1;
  if (button->button1)
    return 1;
  return 0;
}