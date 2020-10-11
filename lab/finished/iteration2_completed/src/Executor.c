#include "Core.h"
#include "Executor.h"
#include "Digital.h"
#include "AnalogConductor.h"
#include "Timer.h"
#include "LED.h"

#include "AnalogModel.h"

void Executor_Init(void)
{
    LED_Init();
    Digital_Init();
    Timer_Init();
    AnalogConductor_Init();
}

BOOL Executor_Exec(void)
{
    AnalogConductor_Exec();

    if (AnalogModel_GetChannel(0) > AnalogModel_GetChannel(1))
        LED_On(LED0);
    else
        LED_Off(LED0);

    if (AnalogModel_GetChannel(2) > AnalogModel_GetChannel(3))
        LED_On(LED1);
    else
        LED_Off(LED1);

    if (AnalogModel_GetChannel(4) > AnalogModel_GetChannel(5))
        LED_On(LED2);
    else
        LED_Off(LED2);

    return TRUE;
}
