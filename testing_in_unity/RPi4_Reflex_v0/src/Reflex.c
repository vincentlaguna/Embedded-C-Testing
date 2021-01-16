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
  button->button_1 |= ON;
  button->button_2 |= ON;
  button->button_3 |= ON;
  button->button_4 |= ON;
  button->button_5 |= ON;
  button->button_6 |= ON;
  
  if (button->button_1 && button->button_2 && button->button_3 &&
      button->button_4 && button->button_5 && button->button_6)
    return 1;
  return 0;
}

int LEDS_Init(void)
{
  LEDS *LED;
  LED = (LEDS *)malloc(sizeof(LEDS));
//   wiringPiSetup();
//   pinMode(LedPin, OUTPUT); 
//   pinMode(ButtonPin, INPUT);
//   pullUpDnControl(ButtonPin, PUD_UP); //pull up to 3.3V,make GPIO1 a stable level
  LED->LED_1 |= ON;
  LED->LED_2 |= ON;
  LED->LED_3 |= ON;
  LED->LED_4 |= ON;
  LED->LED_5 |= ON;
  LED->LED_6 |= ON;
  
  if (LED->LED_1 && LED->LED_2 && LED->LED_3 &&
      LED->LED_4 && LED->LED_5 && LED->LED_6)
    return 1;
  return 0;
}