#include "Core.h"
#include "unity.h"

#include "MockDigital.h"
#include "MockAnalogModel.h"
#include "MockBuffer.h"
#include "MockTrigger.h"
#include "MockParams.h"
#include "MockSampler.h"
#include "MockUARTDriver.h"

#include "Capture.h"

static int TestMaxLen = 64;
static uint8_t TestBuffer[64];

extern uint8_t CaptureAnalogMask;
extern uint8_t CaptureCommMask;

void setUp(void)
{
    CaptureAnalogMask = 0x3F;
    CaptureCommMask = 0x00;
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

    Param_RegisterU8WithCallback_ExpectAndReturn(PARAM_COMM_CHANS, 0x00, 0x07, 0x00, NULL, NULL, STATUS_OK);
    Param_RegisterU8WithCallback_IgnoreArg_Ptr();
    Param_RegisterU8WithCallback_IgnoreArg_Callback();

    Capture_Init();
}

void test_Capture_Exec_should_NotGrabData_when_NotTriggered(void)
{
    Trigger_IsTriggered_ExpectAndReturn(0);

    Capture_Exec();
}

void test_Capture_Exec_should_NotGrabData_when_TriggeredButNotSampleReady(void)
{
    Trigger_IsTriggered_ExpectAndReturn(1);
    Sampler_IsReady_ExpectAndReturn(0);

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
    Sampler_IsReady_ExpectAndReturn(1);
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
    Sampler_IsReady_ExpectAndReturn(1);
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
    Sampler_IsReady_ExpectAndReturn(1);
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
    Sampler_IsReady_ExpectAndReturn(1);
    Digital_GetBits_ExpectAndReturn(0x17);

    for (i=0; i < DIMENSION_OF(ExpectedData); i++) {
        Buffer_Put_ExpectAndReturn(NULL, ExpectedData[i], STATUS_OK);
        Buffer_Put_IgnoreArg_Buffer();
    }
    Capture_Exec();
}

void test_Capture_Exec_should_CaptureCommDataIfMaskIsNotZero(void) {
    uint8_t i;
    uint8_t CommData[] = { 'H', 'E', 'L', 'L', 'O' };
    uint8_t ExpectedData[] = { 0x17, 0xC4, 0x00, 0xA5, 'H', 'E', 'L', 'L', 'O' };
    CaptureAnalogMask = 0x00;
    CaptureCommMask = 0x01;

    Trigger_IsTriggered_ExpectAndReturn(1);
    Sampler_IsReady_ExpectAndReturn(1);
    Digital_GetBits_ExpectAndReturn(0x17);

    for (i=0; i < DIMENSION_OF(CommData); i++) {
        UARTDriver_OkayToRead_ExpectAndReturn(0, TRUE);
        UARTDriver_GetChar_ExpectAndReturn(0, CommData[i]);
    }
    UARTDriver_OkayToRead_ExpectAndReturn(0, FALSE);

    for (i=0; i < DIMENSION_OF(ExpectedData); i++) {
        Buffer_Put_ExpectAndReturn(NULL, ExpectedData[i], STATUS_OK);
        Buffer_Put_IgnoreArg_Buffer();
    }
    Capture_Exec();
}

void test_Capture_Exec_should_CaptureMultipleCommPortsIfDesired(void) {
    uint8_t i;
    uint8_t CommData1[] = { 'H', 'E', 'L', 'L', 'O' };
    uint8_t CommData2[] = { 'H', 'O', 'L', 'A' };
    uint8_t CommData3[] = { 'H', 'E', 'J' };
    uint8_t ExpectedData[] = { 0x17, 0xC4, 0x00, 0xA5, 'H', 'E', 'L', 'L', 'O',
                               0xA4, 'H', 'O', 'L', 'A', 0xA3, 'H', 'E', 'J' };
    CaptureAnalogMask = 0x00;
    CaptureCommMask = 0x07;

    Trigger_IsTriggered_ExpectAndReturn(1);
    Sampler_IsReady_ExpectAndReturn(1);
    Digital_GetBits_ExpectAndReturn(0x17);

    for (i=0; i < DIMENSION_OF(CommData1); i++) {
        UARTDriver_OkayToRead_ExpectAndReturn(0, TRUE);
        UARTDriver_GetChar_ExpectAndReturn(0, CommData1[i]);
    }
    UARTDriver_OkayToRead_ExpectAndReturn(0, FALSE);

    for (i=0; i < DIMENSION_OF(CommData2); i++) {
        UARTDriver_OkayToRead_ExpectAndReturn(1, TRUE);
        UARTDriver_GetChar_ExpectAndReturn(1, CommData2[i]);
    }
    UARTDriver_OkayToRead_ExpectAndReturn(1, FALSE);

    for (i=0; i < DIMENSION_OF(CommData3); i++) {
        UARTDriver_OkayToRead_ExpectAndReturn(2, TRUE);
        UARTDriver_GetChar_ExpectAndReturn(2, CommData3[i]);
    }
    UARTDriver_OkayToRead_ExpectAndReturn(2, FALSE);

    for (i=0; i < DIMENSION_OF(ExpectedData); i++) {
        Buffer_Put_ExpectAndReturn(NULL, ExpectedData[i], STATUS_OK);
        Buffer_Put_IgnoreArg_Buffer();
    }
    Capture_Exec();
}

void test_Capture_Exec_should_MaximumBufferIfNecessary(void) {
    uint8_t i;
    uint8_t ExpectedData[] = { 0x17, 0xC4, 0x00, 0xBF, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                               10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                               23, 24, 25, 26, 27, 28, 29, 30 };
    CaptureAnalogMask = 0x00;
    CaptureCommMask = 0x01;

    Trigger_IsTriggered_ExpectAndReturn(1);
    Sampler_IsReady_ExpectAndReturn(1);
    Digital_GetBits_ExpectAndReturn(0x17);

    for (i=0; i < 31; i++) {
        UARTDriver_OkayToRead_ExpectAndReturn(0, TRUE);
        UARTDriver_GetChar_ExpectAndReturn(0, i);
    }

    for (i=0; i < DIMENSION_OF(ExpectedData); i++) {
        Buffer_Put_ExpectAndReturn(NULL, ExpectedData[i], STATUS_OK);
        Buffer_Put_IgnoreArg_Buffer();
    }
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

void test_Capture_GetResult_should_GrabCommDataIfAnySpecified(void)
{
    uint8_t i;
    uint8_t Len;
    uint8_t ExpectedData[] = { 0x17,       //Digital
                               0xC4, 0x00, //Analog Header
                               0xA7,       //Comm Header
                               0x01, 0x02,
                               0x03, 0x04,
                               0x05, 0x06,
                               0x07
                             };

    CaptureAnalogMask = 0x00;
    CaptureCommMask = 0x01;

    for (i=0; i < DIMENSION_OF(ExpectedData); i++)
    {
        Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
        Buffer_Get_ReturnThruPtr_Val(&ExpectedData[i]);
    }

    TEST_ASSERT_EQUAL(STATUS_OK, Capture_GetResult( TestBuffer, &Len, TestMaxLen));
    TEST_ASSERT_EQUAL_INT8(sizeof(ExpectedData), Len);
    TEST_ASSERT_EQUAL_HEX8_ARRAY( ExpectedData, TestBuffer, sizeof(ExpectedData) );
}

void test_Capture_GetResult_should_GrabMultipleCommDataIfAnySpecified(void)
{
    uint8_t i;
    uint8_t Len;
    uint8_t ExpectedData[] = { 0x17,       //Digital
                               0xC4, 0x00, //Analog Header
                               0xA7,       //Comm Header 1
                               0x01, 0x02,
                               0x03, 0x04,
                               0x05, 0x06,
                               0x07,
                               0xA2,       //Comm Header 2
                               0x01, 0x02,
                               0xA4,       //Comm Header 3
                               0x01, 0x02,
                               0x03, 0x04,
                             };

    CaptureAnalogMask = 0x00;
    CaptureCommMask = 0x07;

    for (i=0; i < DIMENSION_OF(ExpectedData); i++)
    {
        Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
        Buffer_Get_ReturnThruPtr_Val(&ExpectedData[i]);
    }

    TEST_ASSERT_EQUAL(STATUS_OK, Capture_GetResult( TestBuffer, &Len, TestMaxLen));
    TEST_ASSERT_EQUAL_INT8(sizeof(ExpectedData), Len);
    TEST_ASSERT_EQUAL_HEX8_ARRAY( ExpectedData, TestBuffer, sizeof(ExpectedData) );
}

void test_Capture_GetResult_should_HandleEmptyCommData(void)
{
    uint8_t i;
    uint8_t Len;
    uint8_t ExpectedData[] = { 0x17,       //Digital
                               0xC4, 0x00, //Analog Header
                               0xA0,       //Comm Header
                             };

    CaptureAnalogMask = 0x00;
    CaptureCommMask = 0x01;

    for (i=0; i < DIMENSION_OF(ExpectedData); i++)
    {
        Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
        Buffer_Get_ReturnThruPtr_Val(&ExpectedData[i]);
    }

    TEST_ASSERT_EQUAL(STATUS_OK, Capture_GetResult( TestBuffer, &Len, TestMaxLen));
    TEST_ASSERT_EQUAL_INT8(sizeof(ExpectedData), Len);
    TEST_ASSERT_EQUAL_HEX8_ARRAY( ExpectedData, TestBuffer, sizeof(ExpectedData) );
}

void test_Capture_Reset_should_ResetBuffersAndSuch(void)
{
    Buffer_Clear_ExpectAnyArgs();
    Sampler_Reset_Expect();

    TEST_ASSERT_EQUAL(STATUS_OK, Capture_Reset());
}

void test_Capture_HasResults_should_ReportBasedOnBufferStatus(void)
{
    Buffer_IsEmpty_ExpectAnyArgsAndReturn(FALSE);

    TEST_ASSERT_TRUE(Capture_HasResults());

    Buffer_IsEmpty_ExpectAnyArgsAndReturn(TRUE);

    TEST_ASSERT_FALSE(Capture_HasResults());
}

