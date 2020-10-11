#include "Core.h"
#include "unity.h"
#include "AnalogModel.h"
#include "MockFilter.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_AnalogModel_GetChannel_should_ReturnZeroWhenChannelIllegal(void)
{
    TEST_ASSERT_EQUAL_HEX16(0, AnalogModel_GetChannel(6));
}

void test_AnalogModel_GetChannel_should_ReturnZeroWhenNoValueCapturedYet(void)
{
    AnalogModel_Init();

    TEST_ASSERT_EQUAL_HEX16(0, AnalogModel_GetChannel( 0 ));
    TEST_ASSERT_EQUAL_HEX16(0, AnalogModel_GetChannel( ANALOG_NUM_CHANS - 1 ));
}

void test_AnalogModel_GetChannel_should_ReturnLatestDataForChan0(void)
{
    AnalogModel_Init();

    Filter_AddVal_ExpectAndReturn( 0x0000, 0x1234, 0x4321);
    AnalogModel_AddReading(0, 0x1234);

    TEST_ASSERT_EQUAL_HEX16(0x4321, AnalogModel_GetChannel( 0 ));
    TEST_ASSERT_EQUAL_HEX16(0, AnalogModel_GetChannel( 1 ));
    TEST_ASSERT_EQUAL_HEX16(0, AnalogModel_GetChannel( ANALOG_NUM_CHANS - 1 ));
}

void test_AnalogModel_GetChannel_should_ReturnLatestDataForLastChan(void)
{
    AnalogModel_Init();

    Filter_AddVal_ExpectAndReturn( 0x0000, 0x5678, 0x8765);
    AnalogModel_AddReading(ANALOG_NUM_CHANS - 1, 0x5678);

    TEST_ASSERT_EQUAL_HEX16(0, AnalogModel_GetChannel( 0 ));
    TEST_ASSERT_EQUAL_HEX16(0, AnalogModel_GetChannel( ANALOG_NUM_CHANS - 2 ));
    TEST_ASSERT_EQUAL_HEX16(0x8765, AnalogModel_GetChannel( ANALOG_NUM_CHANS - 1 ));
}

void test_AnalogModel_GetChannel_should_ReturnLatestDataForMultipleChans(void)
{
    AnalogModel_Init();

    Filter_AddVal_ExpectAndReturn( 0x0000, 0x9876, 0x6789);
    Filter_AddVal_ExpectAndReturn( 0x0000, 0x5432, 0x2345);
    AnalogModel_AddReading(0, 0x9876);
    AnalogModel_AddReading(2, 0x5432);

    TEST_ASSERT_EQUAL_HEX16(0x6789, AnalogModel_GetChannel( 0 ));
    TEST_ASSERT_EQUAL_HEX16(0, AnalogModel_GetChannel( 1 ));
    TEST_ASSERT_EQUAL_HEX16(0x2345, AnalogModel_GetChannel( 2 ));
    TEST_ASSERT_EQUAL_HEX16(0, AnalogModel_GetChannel( 3 ));
    TEST_ASSERT_EQUAL_HEX16(0, AnalogModel_GetChannel( ANALOG_NUM_CHANS - 1 ));
}

void test_AnalogModel_GetChannel_should_ReturnLatestDataForAllChans(void)
{
    AnalogModel_Init();

    TEST_ASSERT_EQUAL_MESSAGE(6, ANALOG_NUM_CHANS, "Need to Update This Test");

    Filter_AddVal_ExpectAndReturn( 0x0000, 1, 11);
    Filter_AddVal_ExpectAndReturn( 0x0000, 2, 22);
    Filter_AddVal_ExpectAndReturn( 0x0000, 3, 33);
    Filter_AddVal_ExpectAndReturn( 0x0000, 4, 44);
    Filter_AddVal_ExpectAndReturn( 0x0000, 5, 55);
    Filter_AddVal_ExpectAndReturn( 0x0000, 6, 66);

    AnalogModel_AddReading(0, 1);
    AnalogModel_AddReading(1, 2);
    AnalogModel_AddReading(2, 3);
    AnalogModel_AddReading(3, 4);
    AnalogModel_AddReading(4, 5);
    AnalogModel_AddReading(5, 6);

    TEST_ASSERT_EQUAL_HEX16(11, AnalogModel_GetChannel( 0 ));
    TEST_ASSERT_EQUAL_HEX16(22, AnalogModel_GetChannel( 1 ));
    TEST_ASSERT_EQUAL_HEX16(33, AnalogModel_GetChannel( 2 ));
    TEST_ASSERT_EQUAL_HEX16(44, AnalogModel_GetChannel( 3 ));
    TEST_ASSERT_EQUAL_HEX16(55, AnalogModel_GetChannel( 4 ));
    TEST_ASSERT_EQUAL_HEX16(66, AnalogModel_GetChannel( 5 ));
}

void test_AnalogModel_GetChannel_should_NotCareAboutStaleness(void)
{
    AnalogModel_Init();

    TEST_ASSERT_EQUAL_MESSAGE(6, ANALOG_NUM_CHANS, "Need to Update This Test");

    Filter_AddVal_ExpectAndReturn( 0x0000, 11, 10);
    Filter_AddVal_ExpectAndReturn( 0x0000, 22, 20);

    AnalogModel_AddReading(0, 11);
    AnalogModel_AddReading(1, 22);

    TEST_ASSERT_EQUAL_HEX16(10, AnalogModel_GetChannel( 0 ));
    TEST_ASSERT_EQUAL_HEX16(20, AnalogModel_GetChannel( 1 ));
    TEST_ASSERT_EQUAL_HEX16(0,  AnalogModel_GetChannel( 2 ));

    Filter_AddVal_ExpectAndReturn( 20, 222, 220);
    Filter_AddVal_ExpectAndReturn( 0,  333, 330);

    AnalogModel_AddReading(1, 222);
    AnalogModel_AddReading(2, 333);

    TEST_ASSERT_EQUAL_HEX16(10,  AnalogModel_GetChannel( 0 ));
    TEST_ASSERT_EQUAL_HEX16(220, AnalogModel_GetChannel( 1 ));
    TEST_ASSERT_EQUAL_HEX16(330, AnalogModel_GetChannel( 2 ));
}
