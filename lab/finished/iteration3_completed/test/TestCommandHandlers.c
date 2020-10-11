#include "unity.h"
#include "MockTimer.h"
#include "MockCapture.h"
#include "MockCommandConductor.h"
#include "CommandHandlers.h"

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

