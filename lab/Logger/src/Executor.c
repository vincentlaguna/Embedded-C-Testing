#include <stdint.h>
#include "Digital.h"
#include "LED.h"
#include "Executor.h"

void Executor_Init(void)
{
    LED_Init();
    Digital_Init();
}

bool Executor_Exec(void)
{
    uint8_t bits = Digital_GetBits();        

    if ((bits & 0x03) == 0)
    {
        LED_Off(LED0);
    }
    else
    {
        LED_Toggle(LED0);
    }
    return true;
}
