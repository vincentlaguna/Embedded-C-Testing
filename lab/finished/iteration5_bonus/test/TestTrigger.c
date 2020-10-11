#include "unity.h"
#include "Core.h"
#include "MockDigital.h"
#include "MockTimer.h"
#include "Trigger.h"
#include "UnityHelper.h"

uint8_t Seq[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void setUp(void)
{
    Trigger_Init();
}

void tearDown(void)
{
}

void test_Trigger_IsTriggered_should_BeFalseWhenJustInit(void)
{
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeFalseWhenJustArmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());

    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeFalseWhenAttemptToTriggerAndUnarmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_NOT_ARMED, Trigger_Now());

    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggered(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());

    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_ReportIfAlreadyArmedButWillRemainArmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_ALREADY_ARMED, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());

    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_NotBeTriggerableWhenDisarmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Disarm());
    TEST_ASSERT_EQUAL( STATUS_NOT_ARMED, Trigger_Now());

    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeAbleToArmAfterBeingDisarmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Disarm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());

    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_NotAllowMultipleTriggersOffOneArm(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());
    TEST_ASSERT_EQUAL( STATUS_ALREADY_TRIGGERED, Trigger_Now());

    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_AllowRearmAfterTriggering(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());

    TEST_ASSERT_TRUE( Trigger_IsTriggered() );

    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());

    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());

    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_AllowRearmAfterTriggeringAndDisarm(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());

    TEST_ASSERT_TRUE( Trigger_IsTriggered() );

    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Disarm());

    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());

    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_GetStyle_should_ReturnTriggerNow_when_Appropriate(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());
    TEST_ASSERT_EQUAL_TRIGGER_T( TRIGGER_NOW, Trigger_GetStyle() );
}

void test_Trigger_GetStyle_should_ReturnTriggerOnBitChange_when_Appropriate(void)
{
    Digital_GetBits_IgnoreAndReturn(0x00);

    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnBitChange(0x5A));
    TEST_ASSERT_EQUAL_TRIGGER_T( TRIGGER_BIT_CHANGE, Trigger_GetStyle() );
}

void test_Trigger_GetStyle_should_ReturnTriggerOnBitState_when_Appropriate(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnBitState(0x5A, 0x3C));
    TEST_ASSERT_EQUAL_TRIGGER_T( TRIGGER_BIT_STATE, Trigger_GetStyle() );
}

void test_Trigger_GetStyle_should_ReturnTriggerOnSequence_when_Appropriate(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnSequence(0x5A, Seq, 1));
    TEST_ASSERT_EQUAL_TRIGGER_T( TRIGGER_SEQUENCE, Trigger_GetStyle() );
}

void test_Trigger_GetStyle_should_ReturnTriggerOnTimestamp_when_Appropriate(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnTimestamp(0x12345678));
    TEST_ASSERT_EQUAL_TRIGGER_T( TRIGGER_TIMESTAMP, Trigger_GetStyle() );
}

void test_Trigger_Now_should_OnlyTriggerWhenAlreadyArmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_NOT_ARMED, Trigger_Now());
    TEST_ASSERT_EQUAL_TRIGGER_T( TRIGGER_NONE, Trigger_GetStyle() );
}

void test_Trigger_OnBitChange_should_OnlyTriggerWhenAlreadyArmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_NOT_ARMED, Trigger_OnBitChange(0x5A));
    TEST_ASSERT_EQUAL_TRIGGER_T( TRIGGER_NONE, Trigger_GetStyle() );
}

void test_Trigger_OnBitState_should_OnlyTriggerWhenAlreadyArmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_NOT_ARMED, Trigger_OnBitState(0x5A, 0x3C));
    TEST_ASSERT_EQUAL_TRIGGER_T( TRIGGER_NONE, Trigger_GetStyle() );
}

void test_Trigger_OnSequence_should_OnlyTriggerWhenAlreadyArmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_NOT_ARMED, Trigger_OnSequence(0x5A, Seq, 1));
    TEST_ASSERT_EQUAL_TRIGGER_T( TRIGGER_NONE, Trigger_GetStyle() );
}

void test_Trigger_OnTimestamp_should_OnlyTriggerWhenAlreadyArmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_NOT_ARMED, Trigger_OnTimestamp(0x12345678));
    TEST_ASSERT_EQUAL_TRIGGER_T( TRIGGER_NONE, Trigger_GetStyle() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnBitChange(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());

    //We capture a sample of the inputs when we set up our trigger
    Digital_GetBits_ExpectAndReturn(0x01);
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnBitChange(0x03));

    //No bits change when we read it, so nothing happens
    Digital_GetBits_ExpectAndReturn(0x01);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    //No bits change within our mask when we read it, so nothing happens
    Digital_GetBits_ExpectAndReturn(0x81);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    //A bit has changed, therefore we actually trigger!
    Digital_GetBits_ExpectAndReturn(0x02);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );

    //Futher calls continue to report that we're triggered without needing to check anything
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnBitState_Immediately(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnBitState(0x03, 0x71));

    //Our bits are in the correct state on the first read, so it triggers
    Digital_GetBits_ExpectAndReturn(0xF1);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnBitState_Later(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnBitState(0x03, 0xF2));

    //Our bits aren't quite correct
    Digital_GetBits_ExpectAndReturn(0x01);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    //Still Not Correct
    Digital_GetBits_ExpectAndReturn(0x83);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    //Now They're Right. Triggered!
    Digital_GetBits_ExpectAndReturn(0x82);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );

    //Futher calls continue to report that we're triggered without needing to check anything
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_OnSequence_should_RejectAnOversizedSequence(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_INVALID_ARG, Trigger_OnSequence(0x03, Seq, 9));
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnSequence_SingleItem(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnSequence(0x03, Seq, 1));

    //Our bits are in the correct state on the first read, so it triggers
    Digital_GetBits_ExpectAndReturn(0xF1);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );

    //Futher calls continue to report that we're triggered without needing to check anything
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnSequence_EightItemsStraight(void)
{
    uint8_t i;

    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnSequence(0x0F, Seq, 8));

    for (i=0; i < 8; i++)
    {
        Digital_GetBits_ExpectAndReturn(i);
        TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    }

    Digital_GetBits_ExpectAndReturn(8);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnSequence_EightItemsWithDelays(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnSequence(0x0F, Seq, 8));

    //The wrong values before the sequence starts do not matter
    Digital_GetBits_ExpectAndReturn(7);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(8);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    //We work our way through part of the sequence
    Digital_GetBits_ExpectAndReturn(1);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(2);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(3);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(4);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    //It won't break anything to keep reading the previous step
    Digital_GetBits_ExpectAndReturn(4);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(4);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(4);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(4);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    //We continue a bit more, and unmasked bits don't ruin anything
    Digital_GetBits_ExpectAndReturn(0xF5);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(0x16);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(0x87);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    //There is another stall that doesn't hurt anything.. even if other bits are changing
    Digital_GetBits_ExpectAndReturn(0x07);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(0x47);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    Digital_GetBits_ExpectAndReturn(0x37);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    //Finally we finish the sequence
    Digital_GetBits_ExpectAndReturn(0x18);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );

    //Futher calls continue to report that we're triggered without needing to check anything
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnSequence_WithRestarts(void)
{
    uint8_t i;

    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnSequence(0x0F, Seq, 8));

    //Start a sequence
    for (i=1; i <= 3; i++)
    {
        Digital_GetBits_ExpectAndReturn(i);
        TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    }

    //Inject a wrong value. The sequence should restart
    Digital_GetBits_ExpectAndReturn(8);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    //Finish the sequence... it should not finish with a TRUE because it should have started over
    for (i=4; i <= 8; i++)
    {
        Digital_GetBits_ExpectAndReturn(i);
        TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    }

    //Restart the whole sequence, this time successfully
    for (i=1; i <= 7; i++)
    {
        Digital_GetBits_ExpectAndReturn(i);
        TEST_ASSERT_FALSE( Trigger_IsTriggered() );
    }
    Digital_GetBits_ExpectAndReturn(8);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnTimestamp_ImmediatelyOnTheNose(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnTimestamp(0x12345678));

    Timer_GetStamp_ExpectAndReturn(0x12345678);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnTimestamp_ImmediatelyAlreadyPast(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnTimestamp(0x12345678));

    Timer_GetStamp_ExpectAndReturn(0x76543210);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnTimestamp_IfItHasToWait(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnTimestamp(0x12345678));

    Timer_GetStamp_ExpectAndReturn(0x12345670);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    Timer_GetStamp_ExpectAndReturn(0x12345674);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    Timer_GetStamp_ExpectAndReturn(0x12345678);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsTriggered_should_BeTrueWhenArmedAndThenTriggeredOnTimestamp_IfItSkips(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_OnTimestamp(0x12345678));

    Timer_GetStamp_ExpectAndReturn(0x12345670);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    Timer_GetStamp_ExpectAndReturn(0x12345675);
    TEST_ASSERT_FALSE( Trigger_IsTriggered() );

    Timer_GetStamp_ExpectAndReturn(0x1234567A);
    TEST_ASSERT_TRUE( Trigger_IsTriggered() );
}

void test_Trigger_IsArmed_should_BeFalseWhenJustInit(void)
{
    TEST_ASSERT_FALSE( Trigger_IsArmed() );
}

void test_Trigger_IsArmed_should_BeTrueWhenArmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());

    TEST_ASSERT_TRUE( Trigger_IsArmed() );
}

void test_Trigger_IsArmed_should_BeTrueWhenTriggered(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());

    TEST_ASSERT_TRUE( Trigger_IsArmed() );
}

void test_Trigger_IsArmed_should_BeTrueWhenDisarmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Disarm());

    TEST_ASSERT_FALSE( Trigger_IsArmed() );
}

void test_Trigger_IsComplete_should_BeFalseWhenFirstInit(void)
{
    TEST_ASSERT_FALSE( Trigger_IsComplete() );
}

void test_Trigger_IsComplete_should_BeFalseWhenFirstArmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());

    TEST_ASSERT_FALSE( Trigger_IsComplete() );
}

void test_Trigger_IsComplete_should_BeFalseWhenFirstTriggered(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());

    TEST_ASSERT_FALSE( Trigger_IsComplete() );
}

void test_Trigger_IsComplete_should_BeFalseWhenCompleted(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Complete());

    TEST_ASSERT_TRUE( Trigger_IsComplete() );

    TEST_ASSERT_TRUE( Trigger_IsComplete() );
}

void test_Trigger_IsComplete_should_JustSayOkayIfAlreadyComplete(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Now());
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Complete());

    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Complete());

    TEST_ASSERT_TRUE( Trigger_IsComplete() );
}

void test_Trigger_IsComplete_should_NotBeAbleToCompleteIfNotTriggered(void)
{
    TEST_ASSERT_EQUAL( STATUS_OK, Trigger_Arm());
    TEST_ASSERT_EQUAL( STATUS_NONE_YET, Trigger_Complete());

    TEST_ASSERT_FALSE( Trigger_IsComplete() );
}

void test_Trigger_IsComplete_should_NotBeAbleToCompleteIfNotArmed(void)
{
    TEST_ASSERT_EQUAL( STATUS_NOT_ARMED, Trigger_Complete());

    TEST_ASSERT_FALSE( Trigger_IsComplete() );
}
