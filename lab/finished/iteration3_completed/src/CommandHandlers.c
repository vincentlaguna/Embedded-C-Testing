#include "Core.h"
#include "Timer.h"
#include "Capture.h"
#include "CommandConductor.h"
#include "CommandHandlers.h"

void CommandHandlers_Init(void)
{

}

STATUS_T CommandHandlerVersion(MESSAGE_T* Msg)
{
    Msg->Data[0] = VERSION_MAJOR;
    Msg->Data[1] = VERSION_MINOR;
    Msg->Len     = 2;

    return STATUS_OK;
}

STATUS_T CommandHandlerClock(MESSAGE_T* Msg)
{
    uint32_t Stamp;

    if (Msg->Len == 0) {
        Stamp = Timer_GetStamp();
        Msg->Data[0] = UINT32_BYTE3( Stamp );
        Msg->Data[1] = UINT32_BYTE2( Stamp );
        Msg->Data[2] = UINT32_BYTE1( Stamp );
        Msg->Data[3] = UINT32_BYTE0( Stamp );
        Msg->Len = 4;
    }
    else //Set the time
    {
        if (Msg->Len < 4)
            return STATUS_MISSING_ARG;
        if (Msg->Len > 4)
            return STATUS_EXTRA_ARG;
        Stamp  = BYTE3_TO_UINT32( Msg->Data[0] );
        Stamp |= BYTE2_TO_UINT32( Msg->Data[1] );
        Stamp |= BYTE1_TO_UINT32( Msg->Data[2] );
        Stamp |= BYTE0_TO_UINT32( Msg->Data[3] );
        Timer_SetStamp(Stamp);
    }

    return STATUS_OK;
}

STATUS_T CommandHandlerResults(MESSAGE_T* Msg)
{
    STATUS_T retval;

    if (Msg->Len > 0)
        return STATUS_INVALID_ARG;

    //Grab the next snapshot of data
    retval = Capture_GetResult((uint8_t*)(Msg->Data), (uint8_t*)(&Msg->Len), COMMAND_MAX_LEN);
    return retval;
}
