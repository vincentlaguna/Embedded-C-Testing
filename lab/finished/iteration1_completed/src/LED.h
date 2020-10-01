#ifndef _LED_H
#define _LED_H

typedef enum _LED_ID_T
{
    LED0 = 0,
    LED1,
    LED2,
    LED3,

    NUM_LED,
} LED_ID_T;

void LED_Init(void);
void LED_On(LED_ID_T num);
void LED_Off(LED_ID_T num);
void LED_Toggle(LED_ID_T num);

#endif // _LED_H
