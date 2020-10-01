#include "Core.h"
#include "unity.h"
#include "MockParams.h"
#include "Mockserial_api.h"

#include "UARTDriver.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_UARTDriver_Init_should_RegisterParametersForBaudRates(void)
{
    Param_RegisterU16WithCallback_ExpectAndReturn(PARAM_COM1_BAUD, 300, 57600, 9600, NULL, NULL, STATUS_OK);
    Param_RegisterU16WithCallback_IgnoreArg_Ptr();
    Param_RegisterU16WithCallback_IgnoreArg_Callback();

    Param_RegisterU16WithCallback_ExpectAndReturn(PARAM_COM2_BAUD, 300, 57600, 9600, NULL, NULL, STATUS_OK);
    Param_RegisterU16WithCallback_IgnoreArg_Ptr();
    Param_RegisterU16WithCallback_IgnoreArg_Callback();

    Param_RegisterU16WithCallback_ExpectAndReturn(PARAM_COM3_BAUD, 300, 57600, 9600, NULL, NULL, STATUS_OK);
    Param_RegisterU16WithCallback_IgnoreArg_Ptr();
    Param_RegisterU16WithCallback_IgnoreArg_Callback();

    UARTDriver_Init();
}

void test_UARTDriver_Connected_should_ReturnFalseIfJustInitialized(void)
{
    Param_RegisterU16WithCallback_IgnoreAndReturn(STATUS_OK);
    UARTDriver_Init();

    TEST_ASSERT_FALSE(UARTDriver_Connected(UART_PORT1));
    TEST_ASSERT_FALSE(UARTDriver_Connected(UART_PORT2));
    TEST_ASSERT_FALSE(UARTDriver_Connected(UART_PORT3));
}

void test_UARTDriver_Connected_should_ReturnTrueWhenEnabled(void)
{
    Param_RegisterU16WithCallback_IgnoreAndReturn(STATUS_OK);
    UARTDriver_Init();

    serial_init_ExpectAnyArgs();
    serial_baud_ExpectAnyArgs();
    serial_clear_ExpectAnyArgs();
    TEST_ASSERT_EQUAL(STATUS_OK, UARTDriver_Enable(UART_PORT2));

    TEST_ASSERT_FALSE(UARTDriver_Connected(UART_PORT1));
    TEST_ASSERT_TRUE(UARTDriver_Connected(UART_PORT2));
    TEST_ASSERT_FALSE(UARTDriver_Connected(UART_PORT3));
}

void test_UARTDriver_Connected_should_ReturnFalseWhenDisabled(void)
{
    Param_RegisterU16WithCallback_IgnoreAndReturn(STATUS_OK);
    UARTDriver_Init();

    serial_init_ExpectAnyArgs();
    serial_baud_ExpectAnyArgs();
    serial_clear_ExpectAnyArgs();
    TEST_ASSERT_EQUAL(STATUS_OK, UARTDriver_Enable(UART_PORT1));

    serial_init_ExpectAnyArgs();
    serial_baud_ExpectAnyArgs();
    serial_clear_ExpectAnyArgs();
    TEST_ASSERT_EQUAL(STATUS_OK, UARTDriver_Enable(UART_PORT2));

    serial_init_ExpectAnyArgs();
    serial_baud_ExpectAnyArgs();
    serial_clear_ExpectAnyArgs();
    TEST_ASSERT_EQUAL(STATUS_OK, UARTDriver_Enable(UART_PORT3));

    TEST_ASSERT_EQUAL(STATUS_OK, UARTDriver_Disable(UART_PORT2));

    TEST_ASSERT_TRUE(UARTDriver_Connected(UART_PORT1));
    TEST_ASSERT_FALSE(UARTDriver_Connected(UART_PORT2));
    TEST_ASSERT_TRUE(UARTDriver_Connected(UART_PORT3));
}

void test_UARTDriver_Enable_should_AlwaysReturnErrorIfInvalidPort(void)
{
    TEST_ASSERT_EQUAL(STATUS_UART_BAD_PORT, UARTDriver_Enable(UART_NUM_PORTS));
}

void test_UARTDriver_Disable_should_AlwaysReturnErrorIfInvalidPort(void)
{
    TEST_ASSERT_EQUAL(STATUS_UART_BAD_PORT, UARTDriver_Disable(UART_NUM_PORTS));
}

void test_UARTDriver_OkayToRead_should_BasicallyCallReadableFromSerialPort(void)
{
    serial_readable_ExpectAnyArgsAndReturn(1);

    TEST_ASSERT_TRUE(UARTDriver_OkayToRead(0));

    serial_readable_ExpectAnyArgsAndReturn(0);

    TEST_ASSERT_FALSE(UARTDriver_OkayToRead(0));
}

void test_UARTDriver_OkayToRead_should_AlwaysReturnFalseIfInvalidPort(void)
{
    TEST_ASSERT_FALSE(UARTDriver_OkayToRead(UART_NUM_PORTS));
}

void test_UARTDriver_OkayToWrite_should_BasicallyCallWriteableFromSerialPort(void)
{
    serial_writable_ExpectAnyArgsAndReturn(1);

    TEST_ASSERT_TRUE(UARTDriver_OkayToWrite(0));

    serial_writable_ExpectAnyArgsAndReturn(0);

    TEST_ASSERT_FALSE(UARTDriver_OkayToWrite(0));
}

void test_UARTDriver_OkayToWrite_should_AlwaysReturnFalseIfInvalidPort(void)
{
    TEST_ASSERT_FALSE(UARTDriver_OkayToWrite(UART_NUM_PORTS));
}

void test_UARTDriver_GetChar_should_BasicallyCallGetCFromSerialPort(void)
{
    serial_getc_ExpectAnyArgsAndReturn(0x45);

    TEST_ASSERT_EQUAL_HEX8(0x45, UARTDriver_GetChar(0));
}

void test_UARTDriver_GetChar_should_AlwaysReturnZeroIfInvalidPort(void)
{
    TEST_ASSERT_EQUAL(0, UARTDriver_GetChar(UART_NUM_PORTS));
}

void test_UARTDriver_PutChar_should_BasicallyCallPutCFromSerialPort(void)
{
    serial_putc_Expect(NULL, 0x67);
    serial_putc_IgnoreArg_obj();

    TEST_ASSERT_EQUAL(STATUS_OK, UARTDriver_PutChar(1, 0x67));
}

void test_UARTDriver_PutChar_should_AlwaysReturnErrorIfInvalidPort(void)
{
    TEST_ASSERT_EQUAL(STATUS_UART_BAD_PORT, UARTDriver_PutChar(UART_NUM_PORTS, 0x54));
}
