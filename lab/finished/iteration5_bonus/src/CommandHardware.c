#include "Core.h"
#include "Parser.h"
#include "Packer.h"
#include "CommandHardware.h"
#include "USBDriver.h"

STATIC char DataOut[USB_MAX_BUFFER_LENGTH];

STATUS_T CommandHardware_CheckForMsg(MESSAGE_T* msg)
{
    if (USBDriver_OkayToRead()) {
        char byte = USBDriver_GetChar();
        char* ParsedPacket = Parser_AddChar(byte);
        if (ParsedPacket != NULL){
            msg->Cmd = ParsedPacket[1];
            msg->Len = (ParsedPacket[2] - '0');
            HexToBin(&ParsedPacket[3], msg->Data, msg->Len);
            return STATUS_OK;
        }
    }
    return STATUS_NONE_YET;
}

STATUS_T CommandHardware_SendResponse(MESSAGE_T* Msg)
{
    char* PacketOut;

    BinToHex(Msg->Data, DataOut, Msg->Len);
    PacketOut = Packer_AddMsg(Msg->Cmd, DataOut, Msg->Len);
    if (PacketOut == NULL)
        return STATUS_BAD_MSG;

    while (*PacketOut) {
        if (!USBDriver_PutChar(*PacketOut++))
            return STATUS_OVERFLOW;
    }

    return STATUS_OK;
}

STATUS_T CommandHardware_SendError(MESSAGE_T* Msg, STATUS_T Error)
{
    Msg->Cmd = 'E';
    Msg->Data[0] = Error;
    Msg->Len = 1;

    return CommandHardware_SendResponse(Msg);
}
