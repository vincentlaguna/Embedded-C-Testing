#include "Core.h"
#include "unity.h"
#include "Main.h"

#include "MockAnalogConductor.h"
#include "MockCommandConductor.h"
#include "MockDigital.h"
#include "MockLED.h"
#include "MockTimer.h"
#include "MockCapture.h"
#include "MockUI.h"
#include "MockParams.h"
#include "MockSampler.h"
#include "Executor.h"

#include "MockAnalogModel.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Executor_Init_should_InitializeAllSubsystems(void)
{
    Param_Init_Expect();
    LED_Init_Expect();
    UI_Init_Expect();
    Digital_Init_Expect();
    Timer_Init_Expect();
    CommandConductor_Init_Expect();
    AnalogConductor_Init_Expect();
    Capture_Init_Expect();
    Sampler_Init_Expect();

    Executor_Init();
}

void test_Executor_Exec_should_TurnOnLeds_when_FirstOfPairGreaterThanSecondOfPair(void)
{
    AnalogConductor_Exec_Expect();
    CommandConductor_Exec_Expect();
    Capture_Exec_Expect();
    LED_Exec_Expect();
    UI_Exec_Expect();

    Executor_Exec();
}

