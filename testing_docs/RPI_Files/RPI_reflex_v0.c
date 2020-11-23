// Project for Reflex game on a RPi3-4 in C
#include <stdio.h>
#include <wiringPi.h>
#define LED_NUM 6
// Define the arrays of elements that will correspond to our LED's and switches
// Maybe a struct implementation may be a better option???
static int leds[6] = {5,12,17,22,0};
static int switches[LED_NUM] = {6,13,19,23,24,0};
// Main function - need while loop somewhere?
int main(void)
{

  return(0);
}