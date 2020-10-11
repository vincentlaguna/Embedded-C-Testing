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

void test_Timer_GetStamp_should_ReturnCurrentTimeStamp(void)
{
    Timer_SetStamp(0x12345678);
    TEST_ASSERT_EQUAL_HEX32(0x12345678, Timer_GetStamp());

    Timer_SetStamp(0xABCDEFAB);
    TEST_ASSERT_EQUAL_HEX32(0xABCDEFAB, Timer_GetStamp());

    Timer_SetStamp(0xA1B2C3D4);
    TEST_ASSERT_EQUAL_HEX32(0xA1B2C3D4, Timer_GetStamp());
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

void test_Timer_WaitRemainder_should_NotWaitIfWeDidNotAsForTime(void)
{
    TestCounter = 0;

    Timer_SetStamp(0x10000000);

    Timer_WaitRemainder(0x10000000, 0);

    TEST_ASSERT_EQUAL(0, TestCounter);
}

void test_Timer_WaitRemainder_should_NotWaitIfWeAlreadyReachedTimestamp(void)
{
    TestCounter = 0;

    Timer_SetStamp(0x10000008);

    Timer_WaitRemainder(0x10000000, 8);

    TEST_ASSERT_EQUAL(0, TestCounter);
}

void test_Timer_WaitRemainder_should_WaitIfWeHaveNotReachedTimestamp(void)
{
    TestCounter = 0;

    Timer_SetStamp(0x10000008);

    Timer_WaitRemainder(0x10000000, 20);

    TEST_ASSERT_EQUAL(12, TestCounter);
}

void test_Timer_WaitRemainder_should_HandleRollOverInCounter(void)
{
    TestCounter = 0;

    Timer_SetStamp(0xFFFFFFF0);

    Timer_WaitRemainder(0xFFFFFF00, 256);

    TEST_ASSERT_EQUAL(16, TestCounter);
}

void test_Timer_WaitRemainder_should_HandleRollOverInCurrentStamp(void)
{
    TestCounter = 0;

    Timer_SetStamp(64);

    Timer_WaitRemainder(0xFFFFFF00, 512);

    TEST_ASSERT_EQUAL(192, TestCounter);
}
