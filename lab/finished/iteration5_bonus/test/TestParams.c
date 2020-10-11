#include "unity.h"
#include "Core.h"
#include "Params.h"

uint8_t list[8];
uint16_t Val16_1;
uint16_t Val16_2;
uint16_t Val16_3;
uint16_t Val16_4;
uint8_t Val8_1;
uint8_t Val8_2;
uint8_t Val8_3;
uint8_t Val8_4;

uint8_t CallbackCounter;

void ParameterCallback(void)
{
    TEST_ASSERT_TRUE_MESSAGE( (CallbackCounter > 0), "Parameter Callback Called More Times Than Expected");
    CallbackCounter--;
}

void ParameterCallback_Expect(void)
{
    CallbackCounter++;
}

void setUp(void)
{
    Param_Init();
    CallbackCounter = 0;
}

void tearDown(void)
{
    TEST_ASSERT_EQUAL_MESSAGE( 0, CallbackCounter, "Parameter Callback Called Fewer Times Than Expected");
}

void test_Param_Init_should_ClearParams(void)
{
    TEST_ASSERT_EQUAL_INT8(0, Param_List(list, 8));
}

void test_Param_List_should_ReportASingleRegisteredParam(void)
{
    Param_RegisterU16(0x11, 0, 65535, 12, &Val16_1);

    TEST_ASSERT_EQUAL_INT8(1, Param_List(list, 8));
    TEST_ASSERT_EQUAL_HEX8(0x11, list[0]);
}

void test_Param_List_should_ReportMultipleRegisteredParams(void)
{
    Param_RegisterU16(0x11, 0, 65535, 12, &Val16_1);
    Param_RegisterU16(0x22, 0, 65535, 14, &Val16_2);

    TEST_ASSERT_EQUAL_INT8(2, Param_List(list, 8));
    TEST_ASSERT_EQUAL_HEX8(0x11, list[0]);
    TEST_ASSERT_EQUAL_HEX8(0x22, list[1]);
}

void test_Param_List_should_ReportMultipleRegisteredOfDifferentTypes(void)
{
    Param_RegisterU16(0x11, 0, 65535, 12, &Val16_1);
    Param_RegisterU8(0x22, 0, 255, 14, &Val8_2);

    TEST_ASSERT_EQUAL_INT8(2, Param_List(list, 8));
    TEST_ASSERT_EQUAL_HEX8(0x11, list[0]);
    TEST_ASSERT_EQUAL_HEX8(0x22, list[1]);
}

void test_Param_List_should_ReportNumerousRegisteredOfDifferentTypes(void)
{
    uint8_t exp[] = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88 };
    Param_RegisterU16(0x11, 0, 65535, 12, &Val16_1);
    Param_RegisterU8( 0x22, 0, 255,   14, &Val8_1);
    Param_RegisterU16(0x33, 0, 65535, 12, &Val16_2);
    Param_RegisterU16(0x44, 0, 65535, 12, &Val16_3);
    Param_RegisterU16(0x55, 0, 65535, 12, &Val16_4);
    Param_RegisterU8( 0x66, 0, 255,   14, &Val8_2);
    Param_RegisterU8( 0x77, 0, 255,   14, &Val8_3);
    Param_RegisterU8( 0x88, 0, 255,   14, &Val8_4);

    TEST_ASSERT_EQUAL_INT8(8, Param_List(list, 8));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(exp, list, 8);
}

void test_Param_Get_should_ReturnAnErrorForInvalidParams(void)
{
    uint16_t Val;
    Param_RegisterU16(0x11, 0, 65535, 12, &Val16_1);

    TEST_ASSERT_EQUAL(STATUS_INVALID_PARAM, Param_Get(0x22, &Val));
}

void test_Param_Get_should_BeAbleToFetchTheDefaultValueOfARegisteredParam(void)
{
    uint16_t Val;
    Param_RegisterU16(0x11, 0, 65535, 12, &Val16_1);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x11, &Val));
    TEST_ASSERT_EQUAL_INT16(12, Val);
}

void test_Param_Get_should_BeAbleToFetchTheDefaultValuesOfARegisteredParams(void)
{
    uint16_t Val;
    Param_RegisterU16(0x11, 0, 65535, 12, &Val16_1);
    Param_RegisterU16(0x22, 0, 65535, 14, &Val16_2);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x11, &Val));
    TEST_ASSERT_EQUAL_INT16(12, Val);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x22, &Val));
    TEST_ASSERT_EQUAL_INT16(14, Val);
}

void test_Param_Get_should_BeAbleToFetchTheDefaultValuesOfDifferentSizeParams(void)
{
    uint16_t Val;
    Param_RegisterU16(0x11, 0, 65535, 8888, &Val16_1);
    Param_RegisterU8(0x22, 0, 255, 77, &Val8_1);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x11, &Val));
    TEST_ASSERT_EQUAL_INT16(8888, Val);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x22, &Val));
    TEST_ASSERT_EQUAL_INT16(77, Val);
}

void test_Param_Get_should_BeAbleToFetchTheExternallyChangesValuesOfDifferentSizeParams(void)
{
    uint16_t Val;
    Param_RegisterU16(0x11, 0, 65535, 8888, &Val16_1);
    Param_RegisterU8(0x22, 0, 255, 77, &Val8_1);

    Val16_1 = 44444;
    Val8_1 = 111;

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x11, &Val));
    TEST_ASSERT_EQUAL_INT16(44444, Val);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x22, &Val));
    TEST_ASSERT_EQUAL_INT16(111, Val);
}

void test_Param_Set_should_BeAbleToMakeChangesToValuesOfDifferentSizeParams(void)
{
    uint16_t Val;
    Param_RegisterU16(0x11, 0, 65535, 8888, &Val16_1);
    Param_RegisterU8(0x22, 0, 255, 77, &Val8_1);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Set(0x11, 44444));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x11, &Val));
    TEST_ASSERT_EQUAL_INT16(44444, Val);
    TEST_ASSERT_EQUAL_INT16(44444, Val16_1);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Set(0x22, 111));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x22, &Val));
    TEST_ASSERT_EQUAL_INT16(111, Val);
    TEST_ASSERT_EQUAL_INT8(111, Val8_1);
}

void test_Param_Set_should_RejectIllegalParameters(void)
{
    uint16_t Val;
    Param_RegisterU16(0x11, 0, 65535, 8888, &Val16_1);
    Param_RegisterU8(0x22, 0, 255, 77, &Val8_1);

    TEST_ASSERT_EQUAL(STATUS_INVALID_PARAM, Param_Set(0x12, 44444));
    TEST_ASSERT_EQUAL(STATUS_INVALID_PARAM, Param_Get(0x77, &Val));
}

void test_Param_Set_should_RejectValuesBelowMinimum(void)
{
    uint16_t Val;
    Param_RegisterU16(0x11, 10000, 20000, 15000, &Val16_1);
    Param_RegisterU8(0x22, 100, 200, 150, &Val8_1);

    TEST_ASSERT_EQUAL(STATUS_TOO_LOW, Param_Set(0x11, 9999));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x11, &Val));
    TEST_ASSERT_EQUAL_INT16(15000, Val);
    TEST_ASSERT_EQUAL_INT16(15000, Val16_1);

    TEST_ASSERT_EQUAL(STATUS_TOO_LOW, Param_Set(0x22, 99));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x22, &Val));
    TEST_ASSERT_EQUAL_INT16(150, Val);
    TEST_ASSERT_EQUAL_INT8(150, Val8_1);
}

void test_Param_Set_should_RejectValuesAboveMaximum(void)
{
    uint16_t Val;
    Param_RegisterU16(0x11, 10000, 20000, 15000, &Val16_1);
    Param_RegisterU8(0x22, 100, 200, 150, &Val8_1);

    TEST_ASSERT_EQUAL(STATUS_TOO_HIGH, Param_Set(0x11, 20001));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x11, &Val));
    TEST_ASSERT_EQUAL_INT16(15000, Val);
    TEST_ASSERT_EQUAL_INT16(15000, Val16_1);

    TEST_ASSERT_EQUAL(STATUS_TOO_HIGH, Param_Set(0x22, 201));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x22, &Val));
    TEST_ASSERT_EQUAL_INT16(150, Val);
    TEST_ASSERT_EQUAL_INT8(150, Val8_1);
}

void test_Param_Set_should_FireCallbacksForDifferentSizeParams(void)
{
    uint16_t Val;
    Param_RegisterU16WithCallback(0x11, 0, 65535, 8888, &Val16_1, ParameterCallback);
    Param_RegisterU8WithCallback(0x22, 0, 255, 77, &Val8_1, ParameterCallback);

    ParameterCallback_Expect();
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Set(0x11, 44444));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x11, &Val));
    TEST_ASSERT_EQUAL_INT16(44444, Val);
    TEST_ASSERT_EQUAL_INT16(44444, Val16_1);

    ParameterCallback_Expect();
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Set(0x22, 111));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x22, &Val));
    TEST_ASSERT_EQUAL_INT16(111, Val);
    TEST_ASSERT_EQUAL_INT8(111, Val8_1);
}

void test_Param_Defaults_should_RestoreAllDefaultsForAllParams(void)
{
    uint16_t Val;
    Param_RegisterU16(0x00, 0, 65535, 66, &Val16_2);
    Param_RegisterU16WithCallback(0x11, 0, 65535, 8888, &Val16_1, ParameterCallback);
    Param_RegisterU8WithCallback(0x22, 0, 255, 77, &Val8_1, ParameterCallback);
    Param_RegisterU8(0x33, 0, 255, 55, &Val8_2);

    ParameterCallback_Expect();
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Set(0x11, 44444));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x11, &Val));
    TEST_ASSERT_EQUAL_INT16(44444, Val);
    TEST_ASSERT_EQUAL_INT16(44444, Val16_1);

    ParameterCallback_Expect();
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Set(0x22, 111));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x22, &Val));
    TEST_ASSERT_EQUAL_INT16(111, Val);
    TEST_ASSERT_EQUAL_INT8(111, Val8_1);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Set(0x00, 22222));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x00, &Val));
    TEST_ASSERT_EQUAL_INT16(22222, Val);
    TEST_ASSERT_EQUAL_INT16(22222, Val16_2);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Set(0x33, 56));
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x33, &Val));
    TEST_ASSERT_EQUAL_INT16(56, Val);
    TEST_ASSERT_EQUAL_INT8(56, Val8_2);

    ParameterCallback_Expect();
    ParameterCallback_Expect();
    TEST_ASSERT_EQUAL(STATUS_OK, Param_Defaults());

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x11, &Val));
    TEST_ASSERT_EQUAL_INT16(8888, Val);
    TEST_ASSERT_EQUAL_INT16(8888, Val16_1);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x22, &Val));
    TEST_ASSERT_EQUAL_INT16(77, Val);
    TEST_ASSERT_EQUAL_INT8(77, Val8_1);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x00, &Val));
    TEST_ASSERT_EQUAL_INT16(66, Val);
    TEST_ASSERT_EQUAL_INT16(66, Val16_2);

    TEST_ASSERT_EQUAL(STATUS_OK, Param_Get(0x33, &Val));
    TEST_ASSERT_EQUAL_INT16(55, Val);
    TEST_ASSERT_EQUAL_INT8(55, Val8_2);
}

