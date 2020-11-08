#include "Core.h"
#include "unity.h"
#include "LED.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_LED_Init_should_ConfigureRegistersofLED1OnOnly(void)
{
    LPC_GPIO1->FIOSET    = 0;
    LPC_GPIO1->FIOCLR    = 0;
    LPC_GPIO1->FIODIR    = 0;
    LPC_PINCON->PINSEL3  = 0xFFFFFFFF;
    LPC_PINCON->PINMODE3 = 0xFFFFFFFF;

    LED_Init();

    TEST_ASSERT_EQUAL_HEX(0x00040000, LPC_GPIO1->FIOSET);
    TEST_ASSERT_EQUAL_HEX(0x00B00000, LPC_GPIO1->FIOCLR);
    TEST_ASSERT_EQUAL_HEX(0x00B40000, LPC_GPIO1->FIODIR);
    TEST_ASSERT_EQUAL_HEX(0xFFFF30CF, LPC_PINCON->PINSEL3);
    TEST_ASSERT_EQUAL_HEX(0xFFFF30CF, LPC_PINCON->PINMODE3);
}

void helperUpdatePin(void)
{
    LPC_GPIO1->FIOPIN |=  LPC_GPIO1->FIOSET;
    LPC_GPIO1->FIOPIN &= ~LPC_GPIO1->FIOCLR;
    LPC_GPIO1->FIOSET = 0;
    LPC_GPIO1->FIOCLR = 0;
}

void test_LED_Toggle_should_ToggleTheCorrectOutput(void)
{
    TEST_IGNORE_MESSAGE("Implement LED_Toggle");
} 
