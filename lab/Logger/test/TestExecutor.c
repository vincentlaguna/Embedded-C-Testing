#include "unity.h"
#include "MockDigital.h"
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

    Digital_Init_Expect();

    Executor_Init();
}

void test_Executor_Exec_should_ToggleLed0_when_Digital1IsHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x02);
    
    LED_Toggle_Expect(LED0);
    
    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed0_when_Digital0and1AreHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x03);
    
    LED_Toggle_Expect(LED0);
    
    Executor_Exec();
}

void test_Executor_Exec_should_NotToggleLed0_when_Digital0and1AreLow(void)
{
    Digital_GetBits_ExpectAndReturn(0x00);
    
    LED_Off_Expect(LED0);
    
    Executor_Exec();
}

void test_Executor_Exec_should_AlwaysReturnTrue(void)
{
    TEST_ASSERT_TRUE(Executor_Exec());
    TEST_ASSERT_TRUE(Executor_Exec());
    TEST_ASSERT_TRUE(Executor_Exec());
    TEST_ASSERT_TRUE(Executor_Exec());
    TEST_ASSERT_TRUE(Executor_Exec());
}
