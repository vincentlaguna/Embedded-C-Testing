#include "Core.h"
#include "AnalogModel.h"
#include "Digital.h"
#include "Buffer.h"
#include "Trigger.h"
#include "Params.h"
#include "Capture.h"

static BUFFER_T CaptureBuffer;
static uint8_t  CaptureBytes[BUFFER_MAX_BYTES];
STATIC uint8_t  CaptureAnalogMask = 0x3F;

void Capture_Init(void)
{
    Trigger_Init();
    Buffer_Init(&CaptureBuffer, CaptureBytes, (uint16_t)(sizeof(CaptureBytes)));

    Param_RegisterU8(PARAM_ANALOG_CHANS, 0x00, 0x3F, 0x3F, &CaptureAnalogMask);
}

void Capture_Exec(void)
{
    uint8_t i;
    uint8_t Count;
    uint16_t data;

    //Nothing To Do if Not Triggered
    if (!Trigger_IsTriggered())
        return;

    //Capture Digital
    if (STATUS_OK != Buffer_Put(&CaptureBuffer, Digital_GetBits()))
        return;

    //Count Analog Channels Used
    Count = 0;
    for (i=0; i < ANALOG_NUM_CHANS; i++)
    {
        uint8_t Mask = 1u << i;
        if ((Mask & CaptureAnalogMask) == Mask)
            Count++;
    }

    //Put Analog Header
    if (STATUS_OK != Buffer_Put(&CaptureBuffer, 0xC4))
        return;
    if (STATUS_OK != Buffer_Put(&CaptureBuffer, (uint8_t)(Count * 2)))
        return;

    //Capture Analog
    for (i=0; i < ANALOG_NUM_CHANS; i++)
    {
        uint8_t Mask = 1u << i;
        if ((Mask & CaptureAnalogMask) == Mask) {
            data = AnalogModel_GetChannel( i );
            if ( (STATUS_OK != Buffer_Put(&CaptureBuffer, (uint8_t)(data >> 8))) ||
                 (STATUS_OK != Buffer_Put(&CaptureBuffer, (uint8_t)(data & 0x00FF)))
               ) {
                Trigger_Complete();
                return;
            }
        }
    }
}

STATUS_T Capture_GetResult(uint8_t* buffer, uint8_t* len, uint8_t maxLen)
{
    uint8_t i;
    uint8_t AnalogLen;
    STATUS_T status;

    //Grab data from buffer up to length & Determine Length Remaining
    for (i=0; i < 3; i++)
    {
        status = Buffer_Get(&CaptureBuffer, buffer++);
        if (status != STATUS_OK)
            return status;
    }
    --buffer;
    AnalogLen = *buffer++;
    *len = 3 + AnalogLen;

    //Grab Analog Data Too
    for (i=0; i < AnalogLen; i++)
    {
        status = Buffer_Get(&CaptureBuffer, buffer++);
        if (status != STATUS_OK)
            return status;
    }

    return STATUS_OK;
}

STATUS_T Capture_Reset(void)
{
    Buffer_Clear(&CaptureBuffer);

    return STATUS_OK;
}

int Capture_HasResults(void)
{
    return (!Buffer_IsEmpty(&CaptureBuffer));
}
