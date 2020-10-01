#include "Core.h"
#include "Timer.h"
#include "Capture.h"
#include "Trigger.h"
#include "Params.h"
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

STATUS_T CommandHandlerDefault(MESSAGE_T* Msg)
{
    if (Msg->Len > 0)
        return STATUS_EXTRA_ARG;

    return Param_Defaults();
}

STATUS_T CommandHandlerParams(MESSAGE_T* Msg)
{
    STATUS_T status;
    uint16_t val;

    switch (Msg->Len) {
        case 0: //List the Registered IDs with the length first
            Msg->Len = Param_List((uint8_t*)(&Msg->Data[1]), COMMAND_MAX_LEN-1);
            Msg->Data[0] = Msg->Len;
            Msg->Len += 1;
            return STATUS_OK;
        case 1: //Get a particular ID's value
            status = Param_Get((PARAM_ID_T)(Msg->Data[0]), &val);
            if ((val & 0xFF00) != 0) {
                Msg->Len = 3;
                Msg->Data[1] = (uint8_t)(val >> 8);
                Msg->Data[2] = (uint8_t)(val & 0x00FF);
            }
            else {
                Msg->Len = 2;
                Msg->Data[1] = (uint8_t)(val);
            }
            return status;
        case 2: //Set a particular ID's value
            val = (uint16_t)(Msg->Data[1]);
            return Param_Set((PARAM_ID_T)(Msg->Data[0]), val);
        case 3: //Set a particular ID's value
            val = ((uint16_t)(Msg->Data[1]) << 8) | (Msg->Data[2]);
            return Param_Set((PARAM_ID_T)(Msg->Data[0]), val);
        default:
            return STATUS_INVALID_ARG;
    }
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

STATUS_T CommandHandlerArm(MESSAGE_T* Msg)
{
    if (Msg->Len > 0)
        return STATUS_INVALID_ARG;

    return Trigger_Arm();
}

STATUS_T CommandHandlerTrigger(MESSAGE_T* Msg)
{
    uint32_t timestamp;
    TRIGGER_T TrigType = (TRIGGER_T)(Msg->Data[0]);
    STATUS_T status = STATUS_UNKNOWN_ERR;

    if (Msg->Len < 1) {
        Msg->Len = 1;
        Msg->Data[0] = Trigger_GetStyle();
        return STATUS_OK;
    }

    switch(TrigType)
    {
        case TRIGGER_NOW:
            if (Msg->Len != 1)
                return STATUS_EXTRA_ARG;
            status = Trigger_Now();
            break;

        case TRIGGER_BIT_CHANGE:
            if (Msg->Len < 2)
                return STATUS_MISSING_ARG;
            if (Msg->Len > 2)
                return STATUS_EXTRA_ARG;
            status = Trigger_OnBitChange(Msg->Data[1]);
            break;

        case TRIGGER_BIT_STATE:
            if (Msg->Len < 3)
                return STATUS_MISSING_ARG;
            if (Msg->Len > 3)
                return STATUS_EXTRA_ARG;
            status = Trigger_OnBitState(Msg->Data[1], Msg->Data[2]);
            break;

        case TRIGGER_SEQUENCE:
            if (Msg->Len < 3)
                return STATUS_MISSING_ARG;
            status = Trigger_OnSequence(Msg->Data[1], (uint8_t*)(&Msg->Data[2]), Msg->Len - 2);
            break;

        case TRIGGER_TIMESTAMP:
            if (Msg->Len < 5)
                return STATUS_MISSING_ARG;
            if (Msg->Len > 5)
                return STATUS_EXTRA_ARG;
            timestamp  = BYTE3_TO_UINT32( Msg->Data[1] );
            timestamp |= BYTE2_TO_UINT32( Msg->Data[2] );
            timestamp |= BYTE1_TO_UINT32( Msg->Data[3] );
            timestamp |= BYTE0_TO_UINT32( Msg->Data[4] );
            status = Trigger_OnTimestamp(timestamp);
            break;

        default:
            return STATUS_INVALID_ARG;
    }

    if (status == STATUS_OK) {
        status = Capture_Reset();
    }

    return status;
}
