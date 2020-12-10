// Download:
// git clone git://git.drogon.net/wiringPi
// Installation:
// cd wiringPi
// git pull origin
// ./build
// Testing:
// gpio -v
// gpio readall
// Project for Reflex game on a RPi3-4 in C
#include <stdio.h>
#include <wiringPi.h>

#define LED_NUM  6
#define TRUE     1
#define FALSE    0
// Typedef for bool (didn't want to include yet another library...)
typedef int bool
// Define the arrays of elements that will correspond to our LED's and switches
// Maybe a struct implementation may be a better option???
static int leds[6]           =  {5,12,17,22,0};
static int switches[LED_NUM] =  {6,13,19,23,24,0};
// Main function - need while loop somewhere?
int main(void)
{
  wiringPiSetup(); // Initial wiringPi
  // Let's define our variables
  int rand_int         =  0;
  bool button_valid    =  FALSE;
  bool button_invalid  =  FALSE;
  int points_max       =  10;
  
  return(0);
}