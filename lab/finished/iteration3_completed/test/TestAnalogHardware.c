#include "Core.h"
#include "unity.h"
#include "AnalogHardware.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_AnalogHardware_Init_should_InitializeAnalogChansAndStartContinuousAquisitions(void)
{

    LPC_PINCON->PINSEL1  = 0;
    LPC_PINCON->PINSEL3  = 0;
    LPC_PINCON->PINMODE1 = 0;
    LPC_PINCON->PINMODE3 = 0;
    LPC_SC->PCONP        = 0;
    LPC_SC->PCLKSEL0     = 0;

    AnalogHardware_Init();

    TEST_ASSERT_EQUAL_HEX32(0x00154000, LPC_PINCON->PINSEL1  );
    TEST_ASSERT_EQUAL_HEX32(0xF0000000, LPC_PINCON->PINSEL3  );
    TEST_ASSERT_EQUAL_HEX32(0x003FC000, LPC_PINCON->PINMODE1 );
    TEST_ASSERT_EQUAL_HEX32(0xF0000000, LPC_PINCON->PINMODE3 );
    TEST_ASSERT_EQUAL_HEX32(0x00001000, LPC_SC->PCONP        );
    TEST_ASSERT_EQUAL_HEX32(0x01000000, LPC_SC->PCLKSEL0     );
}

void test_AnalogHardware_IsReady_should_ReturnSuitableStatusForState(void)
{
    LPC_ADC->ADSTAT = 0x00000001;

    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(0));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(1));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(2));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(3));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(4));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(5));

    LPC_ADC->ADSTAT = 0x00000006;

    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(0));
    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(1));
    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(2));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(3));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(4));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(5));

    LPC_ADC->ADSTAT = 0x00000022;

    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(0));
    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(1));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(2));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(3));
    TEST_ASSERT_EQUAL(STATUS_NONE_YET, AnalogHardware_IsReady(4));
    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(5));

    LPC_ADC->ADSTAT = 0x0000003F;

    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(0));
    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(1));
    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(2));
    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(3));
    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(4));
    TEST_ASSERT_EQUAL(STATUS_OK,       AnalogHardware_IsReady(5));
}

void test_AnalogHardware_GetReading_should_FetchLatestDataFromAnalogPeripheralShiftedDownCorrectly(void)
{
    LPC_ADC->ADDR0 = 0x1000;
    LPC_ADC->ADDR1 = 0x2000;
    LPC_ADC->ADDR2 = 0x3000;
    LPC_ADC->ADDR3 = 0x4000;
    LPC_ADC->ADDR4 = 0x5000;
    LPC_ADC->ADDR5 = 0x6000;

    TEST_ASSERT_EQUAL_HEX16(0x0100, AnalogHardware_GetReading(0));
    TEST_ASSERT_EQUAL_HEX16(0x0200, AnalogHardware_GetReading(1));
    TEST_ASSERT_EQUAL_HEX16(0x0300, AnalogHardware_GetReading(2));
    TEST_ASSERT_EQUAL_HEX16(0x0400, AnalogHardware_GetReading(3));
    TEST_ASSERT_EQUAL_HEX16(0x0500, AnalogHardware_GetReading(4));
    TEST_ASSERT_EQUAL_HEX16(0x0600, AnalogHardware_GetReading(5));
}

void test_AnalogHardware_GetReading_should_IgnoreTheRestOfTheResultsRegisters(void)
{
    LPC_ADC->ADDR0 = 0xFFFF100F;
    LPC_ADC->ADDR1 = 0xFFFF200F;
    LPC_ADC->ADDR2 = 0xFFFF300F;
    LPC_ADC->ADDR3 = 0xFFFF400F;
    LPC_ADC->ADDR4 = 0xFFFF500F;
    LPC_ADC->ADDR5 = 0xFFFF600F;

    TEST_ASSERT_EQUAL_HEX16(0x0100, AnalogHardware_GetReading(0));
    TEST_ASSERT_EQUAL_HEX16(0x0200, AnalogHardware_GetReading(1));
    TEST_ASSERT_EQUAL_HEX16(0x0300, AnalogHardware_GetReading(2));
    TEST_ASSERT_EQUAL_HEX16(0x0400, AnalogHardware_GetReading(3));
    TEST_ASSERT_EQUAL_HEX16(0x0500, AnalogHardware_GetReading(4));
    TEST_ASSERT_EQUAL_HEX16(0x0600, AnalogHardware_GetReading(5));
}
