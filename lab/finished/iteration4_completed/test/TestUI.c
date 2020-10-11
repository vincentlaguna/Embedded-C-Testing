#include "unity.h"
#include "Core.h"
#include "MockTrigger.h"
#include "MockLED.h"
#include "UI.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_UI_Init_should_StartInIdleOrWaitingToBeArmedState(void)
{
    LED_Blink_Expect(LED_IDLE);
    LED_Off_Expect(LED_ARMED);
    LED_Off_Expect(LED_CAPTURING);
    LED_Off_Expect(LED_COMPLETE);

    UI_Init();
}

void test_UI_Exec_should_BlinkIdle_when_NothingElseActive(void)
{
    Trigger_IsArmed_IgnoreAndReturn(0);
    Trigger_IsTriggered_IgnoreAndReturn(0);
    Trigger_IsComplete_IgnoreAndReturn(0);

    LED_Off_Expect(LED_COMPLETE);
    LED_Off_Expect(LED_CAPTURING);
    LED_Off_Expect(LED_ARMED);
    LED_Blink_Expect(LED_IDLE);

    UI_Exec();
}

void test_UI_Exec_should_BlinkArm_when_Armed(void)
{
    Trigger_IsArmed_IgnoreAndReturn(1);
    Trigger_IsTriggered_IgnoreAndReturn(0);
    Trigger_IsComplete_IgnoreAndReturn(0);

    LED_Off_Expect(LED_COMPLETE);
    LED_Off_Expect(LED_CAPTURING);
    LED_Blink_Expect(LED_ARMED);
    LED_On_Expect(LED_IDLE);

    UI_Exec();
}

void test_UI_Exec_should_BlinkCapturing_when_Triggered(void)
{
    Trigger_IsArmed_IgnoreAndReturn(1);
    Trigger_IsTriggered_IgnoreAndReturn(1);
    Trigger_IsComplete_IgnoreAndReturn(0);

    LED_Off_Expect(LED_COMPLETE);
    LED_Blink_Expect(LED_CAPTURING);
    LED_On_Expect(LED_ARMED);
    LED_On_Expect(LED_IDLE);

    UI_Exec();
}

void test_UI_Exec_should_BlinkComplete_when_Complete(void)
{
    Trigger_IsArmed_IgnoreAndReturn(0);
    Trigger_IsTriggered_IgnoreAndReturn(0);
    Trigger_IsComplete_IgnoreAndReturn(1);

    LED_Blink_Expect(LED_COMPLETE);
    LED_On_Expect(LED_CAPTURING);
    LED_On_Expect(LED_ARMED);
    LED_On_Expect(LED_IDLE);

    UI_Exec();
}
