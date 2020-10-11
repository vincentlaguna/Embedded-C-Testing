#include "Core.h"
#include "Executor.h"
#include "Digital.h"
#include "AnalogConductor.h"
#include "CommandConductor.h"
#include "Timer.h"
#include "LED.h"

#include "AnalogModel.h"

void Executor_Init(void)
{
    LED_Init();
    Digital_Init();
    Timer_Init();
    CommandConductor_Init();
    AnalogConductor_Init();
}

BOOL Executor_Exec(void)
{
    AnalogConductor_Exec();
    CommandConductor_Exec();

    return TRUE;
}
