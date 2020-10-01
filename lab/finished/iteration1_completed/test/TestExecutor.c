#include "Core.h"
#include "unity.h"
#include "Main.h"

#include "MockDigital.h"
#include "MockLED.h"
#include "MockTimer.h"
#include "Executor.h"

void setUp(void)
{
    Timer_WaitMilli_Ignore();
}

void tearDown(void)
{
}

void test_Executor_Init_should_InitializeAllSubsystems(void)
{
    LED_Init_Expect();
    Digital_Init_Expect();
    Timer_Init_Expect();

    Executor_Init();
}

void test_Executor_Exec_should_ToggleLed0_when_Digital0IsHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x01);
    LED_Toggle_Expect(LED3);
    LED_Toggle_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Off_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed0_when_Digital1IsHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x02);
    LED_Toggle_Expect(LED3);
    LED_Toggle_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Off_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed0_when_Digital0and1AreHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x03);
    LED_Toggle_Expect(LED3);
    LED_Toggle_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Off_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_NotToggleLed0_when_Digital0and1AreLow(void)
{
    Digital_GetBits_ExpectAndReturn(0x00);
    LED_Toggle_Expect(LED3);
    LED_Off_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Off_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed1_when_Digital2IsHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x04);
    LED_Toggle_Expect(LED3);
    LED_Off_Expect(LED0);
    LED_Toggle_Expect(LED1);
    LED_Off_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed1_when_Digital3IsHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x08);
    LED_Toggle_Expect(LED3);
    LED_Off_Expect(LED0);
    LED_Toggle_Expect(LED1);
    LED_Off_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed1_when_Digital2and3AreHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x0C);
    LED_Toggle_Expect(LED3);
    LED_Off_Expect(LED0);
    LED_Toggle_Expect(LED1);
    LED_Off_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_NotToggleLed1_when_Digital2and3AreLow(void)
{
    Digital_GetBits_ExpectAndReturn(0x00);
    LED_Toggle_Expect(LED3);
    LED_Off_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Off_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed2_when_Digital4IsHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x10);
    LED_Toggle_Expect(LED3);
    LED_Off_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Toggle_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed2_when_Digital5IsHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x20);
    LED_Toggle_Expect(LED3);
    LED_Off_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Toggle_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed2_when_Digital4and5AreHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x30);
    LED_Toggle_Expect(LED3);
    LED_Off_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Toggle_Expect(LED2);

    Executor_Exec();
}

void test_Executor_Exec_should_NotToggleLed2_when_Digital4and5AreLow(void)
{
    Digital_GetBits_ExpectAndReturn(0x00);
    LED_Toggle_Expect(LED3);
    LED_Off_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Off_Expect(LED2);

    Executor_Exec();
}

