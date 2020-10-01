#include "Core.h"
#include "AnalogModel.h"
#include "Digital.h"
#include "Capture.h"

STATUS_T Capture_GetResult(uint8_t* buffer, uint8_t* len, uint8_t maxLen)
{
    uint8_t i;
    uint16_t data;
    uint8_t* starting_buffer = buffer;

    //Capture the Digital
    *buffer++ = Digital_GetBits();

    //Add Analog Header
    *buffer++ = 0xC4;
    *buffer++ = (uint8_t)(ANALOG_NUM_CHANS * 2);

    //Capture the Analog
    for (i=0; i < ANALOG_NUM_CHANS; i++)
    {
        data = AnalogModel_GetChannel( i );
        *buffer++ = (uint8_t)(data >> 8);
        *buffer++ = (uint8_t)(data & 0x00FF);
    }

    //Update the length
    *len = (uint8_t)(buffer - starting_buffer);

    return STATUS_OK;
}
