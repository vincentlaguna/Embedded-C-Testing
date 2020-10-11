#include "Core.h"
#include "Executor.h"
#include "Digital.h"
#include "AnalogConductor.h"
#include "CommandConductor.h"
#include "Timer.h"
#include "Capture.h"
#include "LED.h"
#include "UI.h"
#include "Params.h"
#include "Sampler.h"

#include "AnalogModel.h"

void Executor_Init(void)
{
    Param_Init();
    LED_Init();
    UI_Init();
    Digital_Init();
    Timer_Init();
    CommandConductor_Init();
    AnalogConductor_Init();
    Capture_Init();
    Sampler_Init();
}

BOOL Executor_Exec(void)
{
    AnalogConductor_Exec();
    CommandConductor_Exec();
    Capture_Exec();
    LED_Exec();
    UI_Exec();

    return TRUE;
}
