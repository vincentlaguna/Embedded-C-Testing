#include "unity.h"
#include "Core.h"
#include "USBDriver.h"

#include "MockBuffer.h"
#include "Mockserial_api.h"

#define USB_BUFFER_MAX    (75)

extern serial_t USBDriver_serial;
extern uint8_t  tx_data[USB_BUFFER_MAX];
extern uint8_t  rx_data[USB_BUFFER_MAX];
extern BUFFER_T tx;
extern BUFFER_T rx;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_USBDriver_Init_should_InitTheBuffers_and_ConfigureTheSerialPort(void)
{
    TEST_ASSERT_FALSE( USBDriver_Connected() );

    Buffer_Init_ExpectAndReturn(&rx, rx_data, USB_BUFFER_MAX, STATUS_OK);
    Buffer_Init_ExpectAndReturn(&tx, tx_data, USB_BUFFER_MAX, STATUS_OK);

    serial_init_Expect(&USBDriver_serial, USBTX, USBRX);
    serial_clear_Expect(&USBDriver_serial);

    USBDriver_Init();

    TEST_ASSERT_TRUE( USBDriver_Connected() );
}

void test_USBDriver_Exec_should_DoNothing_when_NothingToWrite_and_NothingToRead(void)
{
    serial_writable_IgnoreAndReturn(TRUE);
    Buffer_IsEmpty_IgnoreAndReturn(TRUE);
    Buffer_IsFull_IgnoreAndReturn(FALSE);
    serial_readable_IgnoreAndReturn(FALSE);

    USBDriver_Exec();
}

void test_USBDriver_Exec_should_DoNothing_when_TooFullToWrite_and_TooFullToRead(void)
{
    serial_writable_IgnoreAndReturn(FALSE);
    Buffer_IsEmpty_IgnoreAndReturn(FALSE);
    Buffer_IsFull_IgnoreAndReturn(TRUE);
    serial_readable_IgnoreAndReturn(TRUE);

    USBDriver_Exec();
}

void test_USBDriver_Exec_should_WriteAByte_when_OneBufferedAndWritable(void)
{
    uint8_t test_char = '$';

    serial_writable_IgnoreAndReturn(TRUE);
    Buffer_IsEmpty_IgnoreAndReturn(FALSE);
    Buffer_IsFull_IgnoreAndReturn(TRUE);
    serial_readable_IgnoreAndReturn(TRUE);

    //The first time through the loop, we have a character
    Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
    Buffer_Get_ReturnThruPtr_Val(&test_char);
    serial_putc_Expect(&USBDriver_serial, test_char);

    //The second time through the loop, we don't have a character any longer
    Buffer_Get_ExpectAnyArgsAndReturn(STATUS_NONE_YET);

    USBDriver_Exec();
}

void test_USBDriver_Exec_should_WriteBytes_when_BytesBufferedAndWritable(void)
{
    uint8_t a = 'A';
    uint8_t b = 'B';
    uint8_t c = 'C';

    serial_writable_IgnoreAndReturn(TRUE);
    Buffer_IsFull_IgnoreAndReturn(TRUE);
    serial_readable_IgnoreAndReturn(TRUE);

    //The first time through the loop, we have a character
    Buffer_IsEmpty_IgnoreAndReturn(FALSE);
    Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
    Buffer_Get_ReturnThruPtr_Val(&a);
    serial_putc_Expect(&USBDriver_serial, a);

    //The second time through the loop, we have a character
    Buffer_IsEmpty_IgnoreAndReturn(FALSE);
    Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
    Buffer_Get_ReturnThruPtr_Val(&b);
    serial_putc_Expect(&USBDriver_serial, b);

    //The third time through the loop, we have a character
    Buffer_IsEmpty_IgnoreAndReturn(FALSE);
    Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
    Buffer_Get_ReturnThruPtr_Val(&c);
    serial_putc_Expect(&USBDriver_serial, c);

    //The fourth time through the loop, we don't have a character any longer
    Buffer_IsEmpty_IgnoreAndReturn(TRUE);

    USBDriver_Exec();
}

void test_USBDriver_Exec_should_NotWriteAByte_when_CouldNotFetchByte(void)
{
    serial_writable_IgnoreAndReturn(TRUE);
    Buffer_IsEmpty_IgnoreAndReturn(FALSE);
    Buffer_IsFull_IgnoreAndReturn(TRUE);
    serial_readable_IgnoreAndReturn(TRUE);

    Buffer_Get_ExpectAnyArgsAndReturn(STATUS_NONE_YET);

    USBDriver_Exec();
}

void test_USBDriver_Exec_should_ReadAByte_when_FreeBufferedAndReadable(void)
{
    uint8_t test_char = '$';

    serial_writable_IgnoreAndReturn(FALSE);
    Buffer_IsEmpty_IgnoreAndReturn(TRUE);
    Buffer_IsFull_IgnoreAndReturn(FALSE);
    serial_readable_IgnoreAndReturn(TRUE);

    //The first time through the loop, we have a character
    serial_getc_ExpectAndReturn(&USBDriver_serial, test_char);
    Buffer_Put_ExpectAndReturn(&rx, test_char, STATUS_OK);

    //The second time through the loop, we don't have a character to read any longer
    serial_readable_IgnoreAndReturn(FALSE);

    USBDriver_Exec();
}

void test_USBDriver_Exec_should_ReadBytes_when_BytesInBufferedAndReadable(void)
{
    int i;
    uint8_t vals[5] = { 'Q', 'R', 'S', 'T', 'U' };

    serial_writable_IgnoreAndReturn(FALSE);
    Buffer_IsEmpty_IgnoreAndReturn(TRUE);
    Buffer_IsFull_IgnoreAndReturn(FALSE);

    //We expect that there will be data the first few times through the loop
    for (i=0; i < DIMENSION_OF(vals); i++)
    {
        serial_readable_IgnoreAndReturn(TRUE);
        serial_getc_ExpectAndReturn(&USBDriver_serial, vals[i]);
        Buffer_Put_ExpectAndReturn(&rx, vals[i], STATUS_OK);
    }

    //After that, though, we don't have a character to read any longer
    serial_readable_IgnoreAndReturn(FALSE);

    USBDriver_Exec();
}

void test_USBDriver_PutChar_should_ReturnFalse_when_Full(void)
{
    Buffer_IsFull_ExpectAndReturn(&tx, TRUE);

    TEST_ASSERT_FALSE(USBDriver_PutChar('D'));
}

void test_USBDriver_PutChar_should_PushBytesIntoTheTransmitQueue_when_NotFull(void)
{
    Buffer_IsFull_ExpectAndReturn(&tx, FALSE);
    Buffer_Put_ExpectAndReturn(&tx, 'A', STATUS_OK);

    TEST_ASSERT_TRUE(USBDriver_PutChar('A'));

    Buffer_IsFull_ExpectAndReturn(&tx, FALSE);
    Buffer_Put_ExpectAndReturn(&tx, 'B', STATUS_OK);

    TEST_ASSERT_TRUE(USBDriver_PutChar('B'));

    Buffer_IsFull_ExpectAndReturn(&tx, FALSE);
    Buffer_Put_ExpectAndReturn(&tx, 'C', STATUS_OK);

    TEST_ASSERT_TRUE(USBDriver_PutChar('C'));
}

void test_USBDriver_GetChar_should_GrabBytesFromReceiveQueue_when_NotEmpty(void)
{
    int i;
    uint8_t vals[5] = { 'Z', 'Y', 'X', 'W', 'V' };

    for (i=0; i < DIMENSION_OF(vals); i++) {
        Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
        Buffer_Get_ReturnThruPtr_Val( &vals[i] );

        TEST_ASSERT_EQUAL_HEX8( vals[i], USBDriver_GetChar() );
    }
}

void test_USBDriver_GetChar_should_ReturnZero_when_Empty(void)
{
    Buffer_Get_ExpectAnyArgsAndReturn(STATUS_NONE_YET);

    TEST_ASSERT_EQUAL_HEX8( 0, USBDriver_GetChar() );
}

void test_USBDriver_OkayToRead_should_NegateReceiveEmptyStatus(void)
{
    Buffer_IsEmpty_ExpectAndReturn(&rx, FALSE);

    TEST_ASSERT_TRUE( USBDriver_OkayToRead() );

    Buffer_IsEmpty_ExpectAndReturn(&rx, TRUE);

    TEST_ASSERT_FALSE( USBDriver_OkayToRead() );
}

