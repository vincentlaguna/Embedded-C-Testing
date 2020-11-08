#ifndef LED_H
#define LED_H

typedef enum _LED_ID_T
{
    LED0 = 0,
    LED1,
    LED2,
    LED3,
    NUM_LED
} LED_ID_T;

void LED_Init(void);

void LED_On(void);

void LED_Off(void);

void LED_Toggle(LED_ID_T id);

#endif // LED_H
