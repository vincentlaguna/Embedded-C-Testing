#include "Core.h"
#include "unity.h"
#include "Digital.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Digital_Init_should_InitializeBitsForReading(void)
{
    LPC_GPIO2->FIOMASK   = 0xFFFFFFFF;
    LPC_GPIO2->FIODIR    = 0xFFFFFFFF;
    LPC_PINCON->PINSEL4  = 0xFFFFFFFF;
    LPC_PINCON->PINMODE4 = 0x00000000;

    Digital_Init();

    TEST_ASSERT_EQUAL_HEX(0xFFFFFFC0, LPC_GPIO2->FIOMASK);
    TEST_ASSERT_EQUAL_HEX(0xFFFFFFC0, LPC_GPIO2->FIODIR);
    TEST_ASSERT_EQUAL_HEX(0xFFFFF000, LPC_PINCON->PINSEL4);
    TEST_ASSERT_EQUAL_HEX(0x00000FFF, LPC_PINCON->PINMODE4);
}

void test_Digital_ConfigResistors_should_HandleDifferentMasks(void)
{
    LPC_PINCON->PINMODE4 = 0x00000000;

    Digital_ConfigResistors(0x00, 0x3F);

    TEST_ASSERT_EQUAL_HEX(0x00000FFF, LPC_PINCON->PINMODE4);

    Digital_ConfigResistors(0x3F, 0x00);

    TEST_ASSERT_EQUAL_HEX(0x00000000, LPC_PINCON->PINMODE4);


    Digital_ConfigResistors(0x02A, 0x15);

    TEST_ASSERT_EQUAL_HEX(0x00000333, LPC_PINCON->PINMODE4);
}

void test_Digital_GetBits_should_ReadDigitalInputsAndReturnCurrentValues(void)
{
    LPC_GPIO2->FIOPIN = 0xFFFFFFFF;

    TEST_ASSERT_EQUAL_HEX(0x0000003F, Digital_GetBits());

    LPC_GPIO2->FIOPIN = 0xFFFFFFC0;

    TEST_ASSERT_EQUAL_HEX(0x00000000, Digital_GetBits());

    LPC_GPIO2->FIOPIN = 0x00000000;

    TEST_ASSERT_EQUAL_HEX(0x00000000, Digital_GetBits());

    LPC_GPIO2->FIOPIN = 0x0000001A;

    TEST_ASSERT_EQUAL_HEX(0x0000001A, Digital_GetBits());

    LPC_GPIO2->FIOPIN = 0xABCDEF2C;

    TEST_ASSERT_EQUAL_HEX(0x0000002C, Digital_GetBits());
}
