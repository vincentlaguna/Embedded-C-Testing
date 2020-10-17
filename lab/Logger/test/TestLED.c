#include "Core.h"
#include "LED.h"

#define LED_PORT		LPC_GPIO1
#define LED_1_BIT		(18)
#define LED_2_BIT		(20)
#define LED_3_BIT		(21)
#define LED_4_BIT		(23)

#define LED_PINSEL 		LPC_PINCON->PINSEL3

#define LED_PIN_BIT(bit)  	(0x3u << ((bit & 0x0F) << 1))

static uint8_t BlinkMask;

void LED_Init(void)
{
    BlinkMask = 0xF;

    //We're just going to set LED 1 to signify we've started up... everything else starts low.
    LED_PORT->FIOSET  = BIT_TO_MASK(LED_1_BIT);
    LED_PORT->FIOCLR  = BIT_TO_MASK(LED_2_BIT) | BIT_TO_MASK(LED_3_BIT) | BIT_TO_MASK(LED_4_BIT);
    LED_PORT->FIODIR |= BIT_TO_MASK(LED_1_BIT) | BIT_TO_MASK(LED_2_BIT) | BIT_TO_MASK(LED_3_BIT) | BIT_TO_MASK(LED_4_BIT);
    //Set the mode for the bits we plan to use to make them all use pulldown resistors
    LED_PINMODE = ~( LED_PIN_BIT(LED_1_BIT) | LED_PIN_BIT(LED_2_BIT) | LED_PIN_BIT(LED_3_BIT) | LED_PIN_BIT(LED_4_BIT));
 }
