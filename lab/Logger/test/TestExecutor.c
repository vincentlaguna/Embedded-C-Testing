#include "unity.h"
#include "MockLED.h"
#include "Executor.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Executor_Init_should_InitializeAllSubsystems(void)
{
    
    LED_Init_Expect();

    Executor_Init();
}

void test_Executor_Exec_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement Executor_Exec");
}
