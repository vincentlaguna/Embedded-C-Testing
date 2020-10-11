#include "Core.h"
#include "Executor.h"
#include "Digital.h"
#include "Timer.h"
#include "LED.h"

void Executor_Init(void)
{
    LED_Init();
    Digital_Init();
    Timer_Init();
}

BOOL Executor_Exec(void)
{
    uint8_t bits = Digital_GetBits();
    LED_Toggle(LED3);

    if ((bits & 0x03) != 0)
        LED_Toggle(LED0);
    else
        LED_Off(LED0);
    if ((bits & 0x0C) != 0)
        LED_Toggle(LED1);
    else
        LED_Off(LED1);
    if ((bits & 0x30) != 0)
        LED_Toggle(LED2);
    else
        LED_Off(LED2);

    return TRUE;
}
