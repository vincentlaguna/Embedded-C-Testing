#include "Core.h"
#include "unity.h"
#include "Main.h"

#include "MockExecutor.h"
#include "MockTimer.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Main_Should_InitializeTheDriversThenCallMainLoop(void)
{
    Timer_GetStamp_IgnoreAndReturn(0);
    Timer_WaitRemainder_IgnoreAndReturn(0);

    Executor_Init_Expect();

    Executor_Exec_ExpectAndReturn(TRUE);
    Executor_Exec_ExpectAndReturn(TRUE);
    Executor_Exec_ExpectAndReturn(FALSE);

    TEST_ASSERT_EQUAL(0, TestableMain());
}

void test_Main_Should_ExecuteTheMainLoopAtAPeriodicRate(void)
{
    Executor_Init_Expect();
    Timer_GetStamp_ExpectAndReturn(0);

    Executor_Exec_ExpectAndReturn(TRUE);
    Timer_WaitRemainder_ExpectAndReturn(0, 50, 50);

    Executor_Exec_ExpectAndReturn(TRUE);
    Timer_WaitRemainder_ExpectAndReturn(50, 50, 101);

    Executor_Exec_ExpectAndReturn(FALSE);

    TEST_ASSERT_EQUAL(0, TestableMain());
}
