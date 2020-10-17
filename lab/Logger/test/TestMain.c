#include "Core.h"
#include "unity.h"
#include "cmock.h"
#include "MockLED.h"
#include "Main.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Main_Should_InitializeTheLedDriver(void)
{
    //
    // NOTE: Do not attempt to test main() in Main.c directly.
    //       See Lecture 9 for how to handle this special case.
    //
    LED_Init_Expect();
    TEST_ASSERT_EQUAL(0, TestableMain());
}
