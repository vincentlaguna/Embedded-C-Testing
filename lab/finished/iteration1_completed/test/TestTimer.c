#include "Core.h"
#include "unity.h"
#include "Timer.h"

extern uint32_t TestCounter;

void setUp(void)
{
}

void tearDown(void)
{
}

void SysTick_Handler(void);

void test_Timer_Init_should_SetUpTheTickTimerAt10msecPerTick(void)
{
    SysTick->CTRL  = 0x5A5A5A5A;
    SysTick->LOAD  = 0x5A5A5A5A;
    SysTick->VAL   = 0x5A5A5A5A;

    Timer_Init();

    //TEST_ASSERT_EQUAL_HEX32(~SysTick_CTRL_CLKSOURCE_Msk, SysTick->CTRL);
    TEST_ASSERT_EQUAL_HEX32(0x000EA5FF, SysTick->LOAD);
    TEST_ASSERT_EQUAL_HEX32(0x00000000, SysTick->VAL);
    TEST_ASSERT_EQUAL_HEX32(SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk, SysTick->CTRL);
}


void test_SysTick_Handler_ShouldIncrementTickByTenMilliseconds(void)
{
    Timer_Init();

    SysTick_Handler();

    TEST_ASSERT_EQUAL(10, Timer_GetStamp());

    Timer_SetStamp(0xFFFFFFF8);

    SysTick_Handler();

    TEST_ASSERT_EQUAL(2, Timer_GetStamp());
}

void test_Timer_WaitMilli_should_NotWaitIfMillisecondsIsZero(void)
{
    TestCounter = 0;

    Timer_WaitMilli(0);

    TEST_ASSERT_EQUAL(0, TestCounter);
}

void test_Timer_WaitMilli_should_IterateUntilCorrectMillisecondsElapsed(void)
{
    TestCounter = 0;

    Timer_WaitMilli(10);

    TEST_ASSERT_EQUAL(10, TestCounter);
}
