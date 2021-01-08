#include <stdio.h>
#include <wiringPi.h>

#define LED_NUM  6
#define TRUE     1
#define FALSE    0
// Typedef for bool (didn't want to include yet another library...)
typedef int bool
// Define the arrays of elements that will correspond to our LED's and switches
// Maybe a struct implementation may be a better option???
static int leds[6]           =  {5,12,17,22,25};
static int switches[LED_NUM] =  {6,13,19,23,24,0};
// Let's Declare our function prototypes
int buttonPressed(int *pSwitches, int *pLeds);
// Main function - need while loop somewhere?
int main(void)
{
  wiringPiSetup(); // Initial wiringPi
  // Let's define our variables
  int   rand_int        =  0;
  bool  button_valid    =  FALSE;
  bool  button_invalid  =  FALSE;
  int   points_max      =  10;
  int   deduction       =  5;
  
  //setenv("WIRINGPI_GPIOMEM", "1", 1); // Might not need this?

  pinMode(LedPin, OUTPUT); 
  pinMode(ButtonPin, INPUT);

  pullUpDnControl(ButtonPin, PUD_UP); //pull up to 3.3V,make GPIO1 a stable level

  while(1)
  {
    digitalWrite(LedPin, HIGH);
    if(digitalRead(ButtonPin) == 0)
    { //indicate that button has pressed down
      digitalWrite(LedPin, LOW); //led on
		}
	}
  return(0);
}
// Let's define our functions
int buttonPressed(int *pSwitches, int *pLeds);