#include "Core.h"
#include "unity.h"

#include "MockDigital.h"
#include "MockAnalogModel.h"
#include "MockBuffer.h"
#include "MockTrigger.h"
#include "MockParams.h"

#include "Capture.h"

static int TestMaxLen = 64;
static uint8_t TestBuffer[64];

extern uint8_t CaptureAnalogMask;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Capture_Init_should_InitBuffer(void)
{
    Buffer_Init_ExpectAndReturn(NULL, NULL, 4096, STATUS_OK);
    Buffer_Init_IgnoreArg_Buffer();
    Buffer_Init_IgnoreArg_Bytes();
    Trigger_Init_Expect();

    Param_RegisterU8_ExpectAndReturn(PARAM_ANALOG_CHANS, 0x00, 0x3F, 0x3F, NULL, STATUS_OK);
    Param_RegisterU8_IgnoreArg_Ptr();

    Capture_Init();
}

void test_Capture_Exec_should_NotGrabData_when_NotTriggered(void)
{
    Trigger_IsTriggered_ExpectAndReturn(0);

    Capture_Exec();
}

void test_Capture_Exec_should_GrabTheLatestDigitalAndAnalogData(void)
{
    uint8_t i;
    uint8_t ExpectedData[] = { 0x17,       //Digital
                               0xC4, 0x0C, //Analog Header
                               0x00, 0x00, //Analog Channel 0
                               0x11, 0x01, //Analog Channel 1
                               0x22, 0x02, //Analog Channel 2
                               0x33, 0x03, //Analog Channel 3
                               0x44, 0x04, //Analog Channel 4
                               0x55, 0x05, //Analog Channel 5
                             };

    Trigger_IsTriggered_ExpectAndReturn(1);
    Digital_GetBits_ExpectAndReturn(0x17);
    AnalogModel_GetChannel_ExpectAndReturn( 0, 0x0000 );
    AnalogModel_GetChannel_ExpectAndReturn( 1, 0x1101 );
    AnalogModel_GetChannel_ExpectAndReturn( 2, 0x2202 );
    AnalogModel_GetChannel_ExpectAndReturn( 3, 0x3303 );
    AnalogModel_GetChannel_ExpectAndReturn( 4, 0x4404 );
    AnalogModel_GetChannel_ExpectAndReturn( 5, 0x5505 );

    for (i=0; i < DIMENSION_OF(ExpectedData); i++)
    {
        Buffer_Put_ExpectAndReturn(NULL, ExpectedData[i], STATUS_OK);
        Buffer_Put_IgnoreArg_Buffer();
    }

    Capture_Exec();
}

void test_Capture_Exec_should_StopOnFullBuffer(void)
{
    Trigger_IsTriggered_ExpectAndReturn(1);
    Digital_GetBits_ExpectAndReturn(0x17);
    AnalogModel_GetChannel_ExpectAndReturn( 0, 0x0000 );

    Buffer_Put_ExpectAndReturn(NULL, 0x17, STATUS_OK);
    Buffer_Put_IgnoreArg_Buffer();
    Buffer_Put_ExpectAndReturn(NULL, 0xC4, STATUS_OK);
    Buffer_Put_IgnoreArg_Buffer();
    Buffer_Put_ExpectAndReturn(NULL, 0x0C, STATUS_OK);
    Buffer_Put_IgnoreArg_Buffer();
    Buffer_Put_ExpectAndReturn(NULL, 0x00, STATUS_OK);
    Buffer_Put_IgnoreArg_Buffer();
    Buffer_Put_ExpectAndReturn(NULL, 0x00, STATUS_OVERFLOW);
    Trigger_Complete_ExpectAndReturn(STATUS_OK);
    Buffer_Put_IgnoreArg_Buffer();

    Capture_Exec();
}

void test_Capture_GetResult_should_GrabTheLatestDataFromTheBuffer(void)
{
    uint8_t i;
    uint8_t Len;
    uint8_t ExpectedData[] = { 0x17,       //Digital
                               0xC4, 0x0C, //Analog Header
                               0x00, 0x00, //Analog Channel 0
                               0x11, 0x01, //Analog Channel 1
                               0x22, 0x02, //Analog Channel 2
                               0x33, 0x03, //Analog Channel 3
                               0x44, 0x04, //Analog Channel 4
                               0x55, 0x05, //Analog Channel 5
                             };

    for (i=0; i < DIMENSION_OF(ExpectedData); i++)
    {
        Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
        Buffer_Get_ReturnThruPtr_Val(&ExpectedData[i]);
    }

    TEST_ASSERT_EQUAL(STATUS_OK, Capture_GetResult( TestBuffer, &Len, TestMaxLen));
    TEST_ASSERT_EQUAL_INT8(sizeof(ExpectedData), Len);
    TEST_ASSERT_EQUAL_HEX8_ARRAY( ExpectedData, TestBuffer, sizeof(ExpectedData) );
}

void test_Capture_GetResult_should_FailWhenNotEnoughData(void)
{
    uint8_t Len;

    Buffer_Get_IgnoreAndReturn(STATUS_NONE_YET);

    TEST_ASSERT_EQUAL(STATUS_NONE_YET, Capture_GetResult( TestBuffer, &Len, TestMaxLen));
}

void test_Capture_Reset_should_ResetBuffersAndSuch(void)
{
    Buffer_Clear_ExpectAnyArgs();

    TEST_ASSERT_EQUAL(STATUS_OK, Capture_Reset());
}

void test_Capture_HasResults_should_ReportBasedOnBufferStatus(void)
{
    Buffer_IsEmpty_ExpectAnyArgsAndReturn(FALSE);

    TEST_ASSERT_TRUE(Capture_HasResults());

    Buffer_IsEmpty_ExpectAnyArgsAndReturn(TRUE);

    TEST_ASSERT_FALSE(Capture_HasResults());
}

void test_Capture_Exec_should_OnlyCaptureChannelsFromTheMask(void)
{
    uint8_t i;
    uint8_t ExpectedData[] = { 0x17,       //Digital
                               0xC4, 0x06, //Analog Header
                               0x11, 0x22, //Analog Channel 0
                               0x33, 0x44, //Analog Channel 3
                               0x55, 0x66, //Analog Channel 5
                             };
    CaptureAnalogMask = 0x29;
    Trigger_IsTriggered_ExpectAndReturn(1);
    Digital_GetBits_ExpectAndReturn(0x17);
    AnalogModel_GetChannel_ExpectAndReturn( 0, 0x1122 );
    AnalogModel_GetChannel_ExpectAndReturn( 3, 0x3344 );
    AnalogModel_GetChannel_ExpectAndReturn( 5, 0x5566 );

    for (i=0; i < DIMENSION_OF(ExpectedData); i++)
    {
        Buffer_Put_ExpectAndReturn(NULL, ExpectedData[i], STATUS_OK);
        Buffer_Put_IgnoreArg_Buffer();
    }

    Capture_Exec();
}

void test_Capture_Exec_should_NotCaptureAnalogDataIfMaskIsZero(void) {
    uint8_t i;
    uint8_t ExpectedData[] = { 0x17, 0xC4, 0x00 };
    CaptureAnalogMask = 0x00;

    Trigger_IsTriggered_ExpectAndReturn(1);
    Digital_GetBits_ExpectAndReturn(0x17);

    for (i=0; i < DIMENSION_OF(ExpectedData); i++) {
        Buffer_Put_ExpectAndReturn(NULL, ExpectedData[i], STATUS_OK);
        Buffer_Put_IgnoreArg_Buffer();
    }
    Capture_Exec();
}

void test_Capture_GetResult_should_GrabOnlyDataSpecifiedInTheMask(void)
{
    uint8_t i;
    uint8_t Len;
    uint8_t ExpectedData[] = { 0x17,       //Digital
                               0xC4, 0x06, //Analog Header
                               0x11, 0x22, //Analog Channel 0
                               0x33, 0x44, //Analog Channel 3
                               0x55, 0x66, //Analog Channel 5
                             };

    for (i=0; i < DIMENSION_OF(ExpectedData); i++)
    {
        Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
        Buffer_Get_ReturnThruPtr_Val(&ExpectedData[i]);
    }

    TEST_ASSERT_EQUAL(STATUS_OK, Capture_GetResult( TestBuffer, &Len, TestMaxLen));
    TEST_ASSERT_EQUAL_INT8(sizeof(ExpectedData), Len);
    TEST_ASSERT_EQUAL_HEX8_ARRAY( ExpectedData, TestBuffer, sizeof(ExpectedData) );
}

void test_Capture_GetResult_should_GrabNoAnalogDataIfNoneSpecified(void)
{
    uint8_t i;
    uint8_t Len;
    uint8_t ExpectedData[] = { 0x17,       //Digital
                               0xC4, 0x00, //Analog Header
                             };

    for (i=0; i < DIMENSION_OF(ExpectedData); i++)
    {
        Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
        Buffer_Get_ReturnThruPtr_Val(&ExpectedData[i]);
    }

    TEST_ASSERT_EQUAL(STATUS_OK, Capture_GetResult( TestBuffer, &Len, TestMaxLen));
    TEST_ASSERT_EQUAL_INT8(sizeof(ExpectedData), Len);
    TEST_ASSERT_EQUAL_HEX8_ARRAY( ExpectedData, TestBuffer, sizeof(ExpectedData) );
}

