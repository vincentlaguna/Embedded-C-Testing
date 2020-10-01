#include "unity.h"
#include "MockParser.h"
#include "MockPacker.h"
#include "MockUSBDriver.h"

#include "Utils.h"
#include "CommandHardware.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_CommandHardware_CheckForMsg_Should_ReturnNoneYet_When_NoBytesAvailable(void)
{
    MESSAGE_T Msg = { 0 };

    USBDriver_OkayToRead_ExpectAndReturn(FALSE);

    TEST_ASSERT_EQUAL( STATUS_NONE_YET, CommandHardware_CheckForMsg( &Msg ));
}

void test_CommandHardware_CheckForMsg_Should_GetCharAndAddToPacker_When_BytesAvailable(void)
{
    MESSAGE_T Msg = { 0 };

    USBDriver_OkayToRead_ExpectAndReturn(TRUE);
    USBDriver_GetChar_ExpectAndReturn('V');
    Parser_AddChar_ExpectAndReturn('V', NULL);

    TEST_ASSERT_EQUAL( STATUS_NONE_YET, CommandHardware_CheckForMsg( &Msg ));
}

void test_CommandHardware_CheckForMsg_Should_FillOutMsgStruct_When_ZeroLenPacketComplete(void)
{
    char* Cmd = "[V0]";
    MESSAGE_T Msg = { 0 };

    USBDriver_OkayToRead_ExpectAndReturn(TRUE);
    USBDriver_GetChar_ExpectAndReturn(']');
    Parser_AddChar_ExpectAndReturn(']', Cmd);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHardware_CheckForMsg( &Msg ));
    TEST_ASSERT_EQUAL_HEX8( 'V', Msg.Cmd );
    TEST_ASSERT_EQUAL_INT8( 0, Msg.Len );
}

void test_CommandHardware_CheckForMsg_Should_FillOutMsgStruct_When_MultiBytePacketComplete(void)
{
    char* Cmd = "[T20133]";
    MESSAGE_T Msg = { 0 };
    uint8_t Data[] = { 0x01, 0x33 };

    USBDriver_OkayToRead_ExpectAndReturn(TRUE);
    USBDriver_GetChar_ExpectAndReturn(']');
    Parser_AddChar_ExpectAndReturn(']', Cmd);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHardware_CheckForMsg( &Msg ));
    TEST_ASSERT_EQUAL_HEX8( 'T', Msg.Cmd );
    TEST_ASSERT_EQUAL_INT8( 2, Msg.Len );
    TEST_ASSERT_EQUAL_HEX8_ARRAY( Data, Msg.Data, 2 );
}

void test_CommandHardware_SendResponse_Should_DoNothing_When_NothingPacked(void)
{
    MESSAGE_T Msg = { 'V', 2, { 0x01, 0x02 } };

    Packer_AddMsg_ExpectAndReturn('V', "0102", 2, NULL);

    TEST_ASSERT_EQUAL( STATUS_BAD_MSG, CommandHardware_SendResponse(&Msg) );
}

void test_CommandHardware_SendResponse_Should_SendBytes_When_MessagePacked(void)
{
    MESSAGE_T Msg = { 'V', 2, { 0x01, 0x02 } };
    char* Packed = "[V20102]";

    Packer_AddMsg_ExpectAndReturn('V', "0102", 2, Packed);
    USBDriver_PutChar_ExpectAndReturn('[', TRUE);
    USBDriver_PutChar_ExpectAndReturn('V', TRUE);
    USBDriver_PutChar_ExpectAndReturn('2', TRUE);
    USBDriver_PutChar_ExpectAndReturn('0', TRUE);
    USBDriver_PutChar_ExpectAndReturn('1', TRUE);
    USBDriver_PutChar_ExpectAndReturn('0', TRUE);
    USBDriver_PutChar_ExpectAndReturn('2', TRUE);
    USBDriver_PutChar_ExpectAndReturn(']', TRUE);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHardware_SendResponse(&Msg) );
}

void test_CommandHardware_SendResponse_Should_Complain_When_USBDriverOverflows(void)
{
    MESSAGE_T Msg = { 'V', 2, { 0x01, 0x02 } };
    char* Packed = "[V20102]";

    Packer_AddMsg_ExpectAndReturn('V', "0102", 2, Packed);
    USBDriver_PutChar_ExpectAndReturn('[', TRUE);
    USBDriver_PutChar_ExpectAndReturn('V', TRUE);
    USBDriver_PutChar_ExpectAndReturn('2', TRUE);
    USBDriver_PutChar_ExpectAndReturn('0', FALSE);

    TEST_ASSERT_EQUAL( STATUS_OVERFLOW, CommandHardware_SendResponse(&Msg) );
}

void test_CommandHardware_SendError_Should_SendBytes_When_MessagePacked(void)
{
    MESSAGE_T Msg = { '?', 2, { 0x01, 0x02 } };
    char* Packed = "[E10B]";

    Packer_AddMsg_ExpectAndReturn('E', "0B", 1, Packed);
    USBDriver_PutChar_ExpectAndReturn('[', TRUE);
    USBDriver_PutChar_ExpectAndReturn('E', TRUE);
    USBDriver_PutChar_ExpectAndReturn('1', TRUE);
    USBDriver_PutChar_ExpectAndReturn('0', TRUE);
    USBDriver_PutChar_ExpectAndReturn('B', TRUE);
    USBDriver_PutChar_ExpectAndReturn(']', TRUE);

    TEST_ASSERT_EQUAL( STATUS_OK, CommandHardware_SendError(&Msg, STATUS_NONE_YET) );
}

void test_CommandHardware_SendError_Should_Complain_When_USBDriverOverflows(void)
{
    MESSAGE_T Msg = { '?', 2, { 0x01, 0x02 } };
    char* Packed = "[E107]";

    Packer_AddMsg_ExpectAndReturn('E', "07", 1, Packed);
    USBDriver_PutChar_ExpectAndReturn('[', TRUE);
    USBDriver_PutChar_ExpectAndReturn('E', TRUE);
    USBDriver_PutChar_ExpectAndReturn('1', TRUE);
    USBDriver_PutChar_ExpectAndReturn('0', FALSE);

    TEST_ASSERT_EQUAL( STATUS_OVERFLOW, CommandHardware_SendError(&Msg, STATUS_BAD_MSG) );
}



