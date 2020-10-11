#include "Core.h"
#include "unity.h"
#include "Main.h"

#include "MockAnalogConductor.h"
#include "MockDigital.h"
#include "MockLED.h"
#include "MockTimer.h"
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
    LED_Init_Expect();
    Digital_Init_Expect();
    Timer_Init_Expect();
    AnalogConductor_Init_Expect();

    Executor_Init();
}

void test_Executor_Exec_should_TurnOnLeds_when_FirstOfPairGreaterThanSecondOfPair(void)
{
    AnalogConductor_Exec_Expect();
    AnalogModel_GetChannel_ExpectAndReturn(0, 101);
    AnalogModel_GetChannel_ExpectAndReturn(1, 100);
    LED_On_Expect(LED0);

    AnalogModel_GetChannel_ExpectAndReturn(2, 1);
    AnalogModel_GetChannel_ExpectAndReturn(3, 0);
    LED_On_Expect(LED1);

    AnalogModel_GetChannel_ExpectAndReturn(4, 0x8000);
    AnalogModel_GetChannel_ExpectAndReturn(5, 0x7FFF);
    LED_On_Expect(LED2);

    Executor_Exec();
}

