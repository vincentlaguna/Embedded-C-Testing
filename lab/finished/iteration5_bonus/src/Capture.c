#include "Core.h"
#include "AnalogModel.h"
#include "Digital.h"
#include "Buffer.h"
#include "Trigger.h"
#include "Params.h"
#include "Sampler.h"
#include "UARTDriver.h"
#include "Capture.h"

#define MAX_COMM_BYTES_PER_PACKET    32

static BUFFER_T CaptureBuffer;
static uint8_t  CaptureBytes[BUFFER_MAX_BYTES];
STATIC uint8_t  CaptureAnalogMask = 0x3F;
STATIC uint8_t  CaptureCommMask = 0x00;
static uint8_t  Scratch[MAX_COMM_BYTES_PER_PACKET];

void OpenOrCloseComm(UART_PORT_T port, BOOL state)
{
    if (state)
        UARTDriver_Enable(port);
    else
        UARTDriver_Disable(port);
}

void CaptureCommChanUpdate(void)
{
    uint8_t Changed, i;
    static uint8_t RunningComm = 0x00;

    Changed = RunningComm ^ CaptureCommMask;
    RunningComm = CaptureCommMask;

    for (i=0; i < UART_NUM_PORTS; i++) {
        if (Changed & (1u << i))
            OpenOrCloseComm((UART_PORT_T)i, RunningComm & (1u << i));
    }
}

void Capture_Init(void)
{
    Trigger_Init();
    Buffer_Init(&CaptureBuffer, CaptureBytes, (uint16_t)(sizeof(CaptureBytes)));

    Param_RegisterU8(PARAM_ANALOG_CHANS, 0x00, 0x3F, 0x3F, &CaptureAnalogMask);
    Param_RegisterU8WithCallback(PARAM_COMM_CHANS, 0x00, 0x07, 0x00, &CaptureCommMask, CaptureCommChanUpdate);
}

void Capture_Exec(void)
{
    uint8_t i, j;
    uint8_t Count, Val8;
    uint16_t data;
    STATUS_T Retval;

    //Nothing To Do if Not Triggered
    if (!Trigger_IsTriggered())
        return;

    //Also Need to wait correct Sample Rate and Count
    if (!Sampler_IsReady())
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

    //Capture Serial Ports If Any Enabled
    for (i=0; i < UART_NUM_PORTS; i++)
    {
        uint8_t Mask = 1u << i;
        if ((Mask & CaptureCommMask) == Mask) {
            Val8 = 1;
            while ((Val8 < MAX_COMM_BYTES_PER_PACKET) && UARTDriver_OkayToRead((UART_PORT_T)i))
            {
                Scratch[Val8++] = UARTDriver_GetChar((UART_PORT_T)i);
            }

            //Append Length (not including length byte) With Start of StrFix Tag
            Scratch[0] = (Val8 - 1) | 0xA0;

            //Append Values
            for (j=0; j < Val8; j++)
            {
                Retval = Buffer_Put(&CaptureBuffer, Scratch[j]);
                if (STATUS_OK != Retval) {
                    Trigger_Complete();
                    return;
                }
            }
        }
    }
}

STATUS_T Capture_GetResult(uint8_t* buffer, uint8_t* len, uint8_t maxLen)
{
    uint8_t Val8;
    uint8_t i, j;
    uint8_t AnalogLen;
    STATUS_T status;
    STATUS_T retval;

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

    //Grab Comm Data If Any
    for (i=0; i < 3; i++)
    {
        uint8_t num;
        uint8_t Mask = 1u << i;
        if ((Mask & CaptureCommMask) == Mask) {
            retval = Buffer_Get(&CaptureBuffer, (uint8_t*)(&Val8));
            if (retval != STATUS_OK)
                return retval;
            if ((Val8 & 0xE0) != 0xA0)
                return STATUS_MISSING_DATA;

            num = Val8 & 0x1F;

            if ((*len + num + 1) >= maxLen)
                return STATUS_OVERFLOW;

            *len += num + 1;
            *buffer++ = Val8;

            for (j = 0; j < num; j++)
            {
                retval = Buffer_Get(&CaptureBuffer, (uint8_t*)(buffer++));
                if (retval != STATUS_OK)
                    return retval;
            }
        }
    }

    return STATUS_OK;
}

STATUS_T Capture_Reset(void)
{
    Buffer_Clear(&CaptureBuffer);
    Sampler_Reset();

    return STATUS_OK;
}

int Capture_HasResults(void)
{
    return (!Buffer_IsEmpty(&CaptureBuffer));
}
