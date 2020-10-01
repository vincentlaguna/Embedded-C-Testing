
#include "Core.h"
#include "unity.h"
#include "MockParams.h"
#include "Digital.h"

void setUp(void)
{
}

void tearDown(void)
{
}

extern void ResistorsChangedNotifier(void);
extern uint8_t Debounce(uint8_t Prev, uint8_t NewVal, uint8_t Mask);

STATUS_T ParamRegisterCallback(PARAM_ID_T ID, uint8_t MinVal, uint8_t MaxVal, uint8_t Default, uint8_t* Ptr, int NumCalls)
{
    (void)NumCalls;

    switch(ID)
    {
        case PARAM_DIGITAL_CHANS:
            TEST_ASSERT_EQUAL_HEX8_MESSAGE(0x00, MinVal,  "Minimum Value");
            TEST_ASSERT_EQUAL_HEX8_MESSAGE(0x3F, MaxVal,  "Maximum Value");
            TEST_ASSERT_EQUAL_HEX8_MESSAGE(0x3F, Default, "Default Value");
            break;

        case PARAM_DIGITAL_DEBOUNCE:
            TEST_ASSERT_EQUAL_HEX8_MESSAGE(0x00, MinVal,  "Minimum Value");
            TEST_ASSERT_EQUAL_HEX8_MESSAGE(0x3F, MaxVal,  "Maximum Value");
            TEST_ASSERT_EQUAL_HEX8_MESSAGE(0x00, Default, "Default Value");
            break;

        defult:
            TEST_FAIL_MESSAGE("Did Not Expect To See This Value Configured");
    }

    TEST_ASSERT_NOT_NULL(Ptr);

    return STATUS_OK;
}

void test_Digital_Init_should_InitializeBitsForReading(void)
{
    LPC_GPIO2->FIOMASK   = 0xFFFFFFFF;
    LPC_GPIO2->FIODIR    = 0xFFFFFFFF;
    LPC_PINCON->PINSEL4  = 0xFFFFFFFF;
    LPC_PINCON->PINMODE4 = 0x00000000;

    Param_RegisterU8_ExpectAndReturn(PARAM_DIGITAL_CHANS, 0x00, 0x3F, 0x3F, NULL, STATUS_OK);
    Param_RegisterU8_IgnoreArg_Ptr();
    Param_RegisterU8_StubWithCallback( ParamRegisterCallback );

    Param_RegisterU8_ExpectAndReturn(PARAM_DIGITAL_DEBOUNCE, 0x00, 0x3F, 0x00, NULL, STATUS_OK);
    Param_RegisterU8_IgnoreArg_Ptr();
    Param_RegisterU8_StubWithCallback( ParamRegisterCallback );

    Param_RegisterU8WithCallback_ExpectAndReturn(PARAM_DIGITAL_PULLUP, 0x00, 0x3F, 0x00, NULL, ResistorsChangedNotifier, STATUS_OK);
    Param_RegisterU8WithCallback_IgnoreArg_Ptr();

    Param_RegisterU8WithCallback_ExpectAndReturn(PARAM_DIGITAL_PULLDOWN, 0x00, 0x3F, 0x3F, NULL, ResistorsChangedNotifier, STATUS_OK);
    Param_RegisterU8WithCallback_IgnoreArg_Ptr();

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

void test_Digital_Debouce_should_PassStableSignals(void)
{
    TEST_ASSERT_EQUAL_HEX8( 0x00, Debounce(0x00, 0x00, 0xFF) );
    TEST_ASSERT_EQUAL_HEX8( 0x01, Debounce(0x01, 0x01, 0xFF) );
    TEST_ASSERT_EQUAL_HEX8( 0xFF, Debounce(0xFF, 0xFF, 0xFF) );
    TEST_ASSERT_EQUAL_HEX8( 0x7F, Debounce(0x7F, 0x7F, 0xFF) );
}

void test_Digital_Debouce_should_OnlyChangeOnDoubleUpdates(void)
{
    TEST_ASSERT_EQUAL_HEX8( 0x00, Debounce(0x00, 0x01, 0xFF) );
    TEST_ASSERT_EQUAL_HEX8( 0x01, Debounce(0x01, 0x00, 0xFF) );
    TEST_ASSERT_EQUAL_HEX8( 0xFF, Debounce(0xFF, 0x00, 0xFF) );
    TEST_ASSERT_EQUAL_HEX8( 0x7F, Debounce(0x7F, 0x3C, 0xFF) );
    TEST_ASSERT_EQUAL_HEX8( 0x5A, Debounce(0x5A, 0xCC, 0xFF) );
}

void test_Digital_Debouce_should_OnlyDebounceBitsInMask(void)
{
    TEST_ASSERT_EQUAL_HEX8( 0x01, Debounce(0x00, 0x01, 0xF0) );
    TEST_ASSERT_EQUAL_HEX8( 0x00, Debounce(0x01, 0x00, 0xF0) );
    TEST_ASSERT_EQUAL_HEX8( 0x0F, Debounce(0xFF, 0x00, 0x0F) );
    TEST_ASSERT_EQUAL_HEX8( 0x3F, Debounce(0x7F, 0x3C, 0x0F) );
    TEST_ASSERT_EQUAL_HEX8( 0xCA, Debounce(0x5A, 0xCC, 0x0F) );
}
