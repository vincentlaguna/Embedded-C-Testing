#include "unity.h"
#include "MockTimer.h"
#include "MockCapture.h"
#include "MockCommandConductor.h"
#include "MockParams.h"
#include "MockTrigger.h"
#include "CommandHandlers.h"


static uint8_t Seq[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

void setUp(void)
{
}

void tearDown(void)
{
}

void test_CommandHandlers_Init_Should_DoNothing(void)
{
    CommandHandlers_Init();
}

void test_CommandHandlerVersion_Should_ReturnVersionInformation(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'V';
    Msg.Len = 0;
    Msg.Data[0] = 0x5A;
    Msg.Data[1] = 0x5A;
    Msg.Data[2] = 0x5A;

    const char expected[] = { VERSION_MAJOR, VERSION_MINOR, 0x5A };

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerVersion( &Msg ));
    TEST_ASSERT_EQUAL_HEX8( 'V', Msg.Cmd );
    TEST_ASSERT_EQUAL( 2, Msg.Len );
    TEST_ASSERT_EQUAL_INT8_ARRAY(expected, Msg.Data, 3);
}

void test_CommandHandlerClock_should_GetTimeStamp_when_Empty(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'C';
    Msg.Len = 0;

    Timer_GetStamp_ExpectAndReturn(0x12345678);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerClock(&Msg) );
    TEST_ASSERT_EQUAL_INT8( 4, Msg.Len );
    TEST_ASSERT_EQUAL_HEX8( 0x12, Msg.Data[0] );
    TEST_ASSERT_EQUAL_HEX8( 0x34, Msg.Data[1] );
    TEST_ASSERT_EQUAL_HEX8( 0x56, Msg.Data[2] );
    TEST_ASSERT_EQUAL_HEX8( 0x78, Msg.Data[3] );
}

void test_CommandHandlerClock_should_IgnoreUndersizedMessages(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'C';

    Msg.Len = 3;
    TEST_ASSERT_EQUAL( STATUS_MISSING_ARG, CommandHandlerClock(&Msg) );


    Msg.Len = 1;
    TEST_ASSERT_EQUAL( STATUS_MISSING_ARG, CommandHandlerClock(&Msg) );
}

void test_CommandHandlerClock_should_IgnoreOversizedMessages(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'C';

    Msg.Len = 5;
    TEST_ASSERT_EQUAL( STATUS_EXTRA_ARG, CommandHandlerClock(&Msg) );

    Msg.Len = 8;
    TEST_ASSERT_EQUAL( STATUS_EXTRA_ARG, CommandHandlerClock(&Msg) );
}

void test_CommandHandlerClock_should_SetTimeStamp_when_FourBytesLong(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'C';
    Msg.Len = 4;
    Msg.Data[0] = 0x88;
    Msg.Data[1] = 0x77;
    Msg.Data[2] = 0x66;
    Msg.Data[3] = 0x55;

    Timer_SetStamp_Expect( 0x55667788 );

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerClock(&Msg) );
    TEST_ASSERT_EQUAL_INT8( 4, Msg.Len );
    TEST_ASSERT_EQUAL_HEX8( 0x88, Msg.Data[0] );
    TEST_ASSERT_EQUAL_HEX8( 0x77, Msg.Data[1] );
    TEST_ASSERT_EQUAL_HEX8( 0x66, Msg.Data[2] );
    TEST_ASSERT_EQUAL_HEX8( 0x55, Msg.Data[3] );
}

void test_CommandHandlerResults_should_ErrorOut_when_GivenExtraData(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'R';
    Msg.Len = 1;
    Msg.Data[0] = 0x5A;
    Msg.Data[1] = 0xA5;

    TEST_ASSERT_EQUAL( STATUS_INVALID_ARG, CommandHandlerResults(&Msg) );
}

void test_CommandHandlerResults_should_ReturnError_when_CapturingResultsFails(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'R';
    Msg.Len = 0;

    Capture_GetResult_ExpectAnyArgsAndReturn(STATUS_NONE_YET);


    TEST_ASSERT_EQUAL( STATUS_NONE_YET, CommandHandlerResults(&Msg) );
}

void test_CommandHandlerResults_should_FillResults_when_CapturingResultsSucceeds(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'R';
    Msg.Len = 0;

    uint8_t CapturedData[] = { 0x13, 0x24, 0x35, 0x46, 0x57, 0x68, 0x79 };
    uint8_t CapturedLen = sizeof( CapturedData );

    Capture_GetResult_ExpectAnyArgsAndReturn(STATUS_OK);
    Capture_GetResult_ReturnArrayThruPtr_buffer( CapturedData, CapturedLen );
    Capture_GetResult_ReturnThruPtr_len( &CapturedLen );

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerResults(&Msg) );
    TEST_ASSERT_EQUAL_INT8( CapturedLen, Msg.Len );
    TEST_ASSERT_EQUAL_HEX8_ARRAY( CapturedData, Msg.Data, CapturedLen );
}

void test_CommandHandlerArm_should_ReturnError_when_GivenExtraData(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'A';
    Msg.Len = 1;
    Msg.Data[0] = 'A';
    Msg.Data[1] = 'B';

    TEST_ASSERT_EQUAL( STATUS_INVALID_ARG, CommandHandlerArm(&Msg) );
}

void test_CommandHandlerArm_should_ArmCapture_when_RequestedAndReturnStatus(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'A';
    Msg.Len = 0;

    Trigger_Arm_ExpectAndReturn( STATUS_OK );

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerArm(&Msg) );

    Trigger_Arm_ExpectAndReturn( STATUS_ALREADY_TRIGGERED );

    TEST_ASSERT_EQUAL( STATUS_ALREADY_TRIGGERED, CommandHandlerArm(&Msg) );
}

void test_CommandHandlerTrigger_should_ReturnTriggerStyle_when_NotSuppliedAStyle(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 0;

    Trigger_GetStyle_ExpectAndReturn( TRIGGER_NOW );
    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerTrigger(&Msg) );
    TEST_ASSERT_EQUAL( 'T', Msg.Cmd );
    TEST_ASSERT_EQUAL( 1, Msg.Len );
    TEST_ASSERT_EQUAL( TRIGGER_NOW, Msg.Data[0] );
}

void test_CommandHandlerTrigger_should_ReturnError_when_GivenInvalidStyles(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 1;
    Msg.Data[0] = 5;

    TEST_ASSERT_EQUAL( STATUS_INVALID_ARG, CommandHandlerTrigger(&Msg) );

    Msg.Data[0] = 0xFF;

    TEST_ASSERT_EQUAL( STATUS_INVALID_ARG, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_ReturnError_when_GivenTriggerNowButExtraData(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 2;
    Msg.Data[0] = 0;
    Msg.Data[1] = 1;

    TEST_ASSERT_EQUAL( STATUS_EXTRA_ARG, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_TriggerImmediately_when_GivenTriggerNow(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 1;
    Msg.Data[0] = 0;

    Trigger_Now_ExpectAndReturn( STATUS_OK );
    Capture_Reset_ExpectAndReturn( STATUS_OK );

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerTrigger(&Msg) );

    Trigger_Now_ExpectAndReturn( STATUS_ALREADY_TRIGGERED );

    TEST_ASSERT_EQUAL( STATUS_ALREADY_TRIGGERED, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_TriggerOnBitChange_when_ValidMask(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 2;
    Msg.Data[0] = 1;
    Msg.Data[1] = 0x1C;

    Trigger_OnBitChange_ExpectAndReturn( 0x1C, STATUS_OK );
    Capture_Reset_ExpectAndReturn( STATUS_OK );

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_ReturnErrors_when_TriggerOnBitChangeAndNotOneMaskByte(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 3;
    Msg.Data[0] = 1;
    Msg.Data[1] = 0x1C;
    Msg.Data[1] = 0x1D;

    TEST_ASSERT_EQUAL( STATUS_EXTRA_ARG, CommandHandlerTrigger(&Msg) );

    Msg.Len = 1;

    TEST_ASSERT_EQUAL( STATUS_MISSING_ARG, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_TriggerOnBitState_when_ValidMaskAndData(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 3;
    Msg.Data[0] = 2;
    Msg.Data[1] = 0x33;
    Msg.Data[2] = 0x55;

    Trigger_OnBitState_ExpectAndReturn( 0x33, 0x55, STATUS_OK );
    Capture_Reset_ExpectAndReturn( STATUS_OK );

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_ReturnErrors_when_TriggerOnBitStateAndNotTwoBytes(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 4;
    Msg.Data[0] = 2;
    Msg.Data[1] = 0x33;
    Msg.Data[2] = 0x55;
    Msg.Data[3] = 0x77;

    TEST_ASSERT_EQUAL( STATUS_EXTRA_ARG, CommandHandlerTrigger(&Msg) );

    Msg.Len = 2;

    TEST_ASSERT_EQUAL( STATUS_MISSING_ARG, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_TriggerOnSequence_when_ValidMaskAndDataShortest(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 3;
    Msg.Data[0] = 3;
    Msg.Data[1] = 0x33;
    Msg.Data[2] = 1;

    Trigger_OnSequence_ExpectWithArrayAndReturn( 0x33, Seq, 1, 1, STATUS_OK );
    Capture_Reset_ExpectAndReturn( STATUS_OK );

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_TriggerOnSequence_when_ValidMaskAndDataLongest(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 10;
    Msg.Data[0] = 3;
    Msg.Data[1] = 0x0F;
    Msg.Data[2] = 1;
    Msg.Data[3] = 2;
    Msg.Data[4] = 3;
    Msg.Data[5] = 4;
    Msg.Data[6] = 5;
    Msg.Data[7] = 6;
    Msg.Data[8] = 7;
    Msg.Data[9] = 8;

    Trigger_OnSequence_ExpectWithArrayAndReturn( 0x0F, Seq, 8, 8, STATUS_OK );
    Capture_Reset_ExpectAndReturn( STATUS_OK );

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_ReturnErrors_when_TriggerOnSequenceAndNotCorrectBytes(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 2;
    Msg.Data[0] = 3;
    Msg.Data[1] = 0x07;

    TEST_ASSERT_EQUAL( STATUS_MISSING_ARG, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_TriggerOnTime_when_ValidMaskAndData(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 5;
    Msg.Data[0] = 4;
    Msg.Data[1] = 0x33;
    Msg.Data[2] = 0x55;
    Msg.Data[3] = 0x77;
    Msg.Data[4] = 0x99;

    Trigger_OnTimestamp_ExpectAndReturn( 0x99775533, STATUS_OK );
    Capture_Reset_ExpectAndReturn( STATUS_OK );

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerTrigger_should_ReturnErrors_when_TriggerOnTimeButInvalidLength(void)
{
    MESSAGE_T Msg;
    Msg.Cmd = 'T';
    Msg.Len = 6;
    Msg.Data[0] = 4;
    Msg.Data[1] = 0x33;
    Msg.Data[2] = 0x55;
    Msg.Data[3] = 0x77;
    Msg.Data[4] = 0x99;
    Msg.Data[5] = 0xBB;

    TEST_ASSERT_EQUAL( STATUS_EXTRA_ARG, CommandHandlerTrigger(&Msg) );

    Msg.Len = 4;

    TEST_ASSERT_EQUAL( STATUS_MISSING_ARG, CommandHandlerTrigger(&Msg) );
}

void test_CommandHandlerParams_should_ReturnRegisteredParams_when_NoData(void)
{
    uint8_t Exp[8] = { PARAM_NUM_SAMPLES, PARAM_CAPTURE_RATE, PARAM_DIGITAL_CHANS,
                       PARAM_DIGITAL_PULLDOWN, PARAM_DIGITAL_PULLUP, PARAM_DIGITAL_DEBOUNCE,
                       PARAM_ANALOG_CHANS, PARAM_FILTER_CHANS };
    MESSAGE_T Msg = { 'P', 0, { 0 } };

    Param_List_ExpectAnyArgsAndReturn(8);
    Param_List_ReturnArrayThruPtr_IDs(Exp, 8);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerParams(&Msg) );
    TEST_ASSERT_EQUAL( 9, Msg.Len );
    TEST_ASSERT_EQUAL_INT8( 8, Msg.Data[0]);
    TEST_ASSERT_EQUAL_HEX8_ARRAY( Exp, &Msg.Data[1], 8);
}

void test_CommandHandlerParams_should_ReturnAParameterValue_when_ParameterIdIsValid(void)
{
    uint16_t exp = 0x1234;
    MESSAGE_T Msg = { 'P', 1, { PARAM_DIGITAL_CHANS } };

    Param_Get_ExpectAndReturn(PARAM_DIGITAL_CHANS, 0, STATUS_OK);
    Param_Get_IgnoreArg_Val();
    Param_Get_ReturnThruPtr_Val(&exp);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerParams(&Msg) );
    TEST_ASSERT_EQUAL( 3, Msg.Len );
    TEST_ASSERT_EQUAL_HEX8( PARAM_DIGITAL_CHANS, Msg.Data[0] );
    TEST_ASSERT_EQUAL_HEX8( 0x12, Msg.Data[1] );
    TEST_ASSERT_EQUAL_HEX8( 0x34, Msg.Data[2] );
}

void test_CommandHandlerParams_should_ReturnAParameterValueAsShorthand_when_ParameterIdIsValidAndValueOneByte(void)
{
    uint16_t exp = 0x87;
    MESSAGE_T Msg = { 'P', 1, { PARAM_DIGITAL_CHANS } };

    Param_Get_ExpectAndReturn(PARAM_DIGITAL_CHANS, 0, STATUS_OK);
    Param_Get_IgnoreArg_Val();
    Param_Get_ReturnThruPtr_Val(&exp);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerParams(&Msg) );
    TEST_ASSERT_EQUAL( 2, Msg.Len );
    TEST_ASSERT_EQUAL_HEX8( PARAM_DIGITAL_CHANS, Msg.Data[0] );
    TEST_ASSERT_EQUAL_HEX8( 0x87, Msg.Data[1] );
}

void test_CommandHandlerParams_should_ReturnAnError_when_ParameterIdIsInvalid(void)
{
    MESSAGE_T Msg = { 'P', 1, { PARAM_DIGITAL_CHANS } };

    Param_Get_ExpectAndReturn(PARAM_DIGITAL_CHANS, 0, STATUS_INVALID_PARAM);
    Param_Get_IgnoreArg_Val();

    TEST_ASSERT_EQUAL( STATUS_INVALID_PARAM, CommandHandlerParams(&Msg) );
}

void test_CommandHandlerParams_should_SetAParameterValue_when_OneByteValue(void)
{
    MESSAGE_T Msg = { 'P', 2, { PARAM_DIGITAL_CHANS, 0x03 } };

    Param_Set_ExpectAndReturn(PARAM_DIGITAL_CHANS, 0x0003, STATUS_OK);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerParams(&Msg) );
}

void test_CommandHandlerParams_should_SetAParameterValue_when_TwoByteValue(void)
{
    MESSAGE_T Msg = { 'P', 3, { PARAM_DIGITAL_CHANS, 0x23, 0x45 } };

    Param_Set_ExpectAndReturn(PARAM_DIGITAL_CHANS, 0x2345, STATUS_OK);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerParams(&Msg) );
}

void test_CommandHandlerDefault_should_ReturnErrorIfGivenData(void)
{
    MESSAGE_T Msg = { 'D', 1, { 0x00 } };

    TEST_ASSERT_EQUAL( STATUS_EXTRA_ARG, CommandHandlerDefault( &Msg ) );
}

void test_CommandHandlerDefault_should_SetToDefaultsIfRequested(void)
{
    MESSAGE_T Msg = { 'D', 0, { 0 } };

    Param_Defaults_ExpectAndReturn(STATUS_OK);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHandlerDefault( &Msg ) );
}
