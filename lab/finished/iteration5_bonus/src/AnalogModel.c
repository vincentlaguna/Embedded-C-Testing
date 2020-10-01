#include "Core.h"
#include "AnalogModel.h"
#include "Params.h"
#include "Filter.h"

STATIC uint16_t AnalogValues[ANALOG_NUM_CHANS];
STATIC uint8_t  FilterChans       = 0x3F;
STATIC uint16_t FilterNumerator   = 3;
STATIC uint16_t FilterDenominator = 4;

void AnalogModel_Init(void)
{
    int i;

    for (i=0; i < ANALOG_NUM_CHANS; i++)
    {
        AnalogValues[i] = 0;
    }

    Param_RegisterU8(PARAM_FILTER_CHANS,        0x00, 0x3F, 0x00, &FilterChans);
    Param_RegisterU16(PARAM_FILTER_NUMERATOR,   0x00, 0xFF, 0x00, &FilterNumerator);
    Param_RegisterU16(PARAM_FILTER_DENOMINATOR, 0x01, 0xFF, 0x00, &FilterDenominator);
}

void AnalogModel_AddReading(uint8_t Channel, uint16_t Reading)
{
    uint8_t ChanMask;

    if (Channel < ANALOG_NUM_CHANS)
    {
        ChanMask = 1u << Channel;
        if ((ChanMask & FilterChans) == ChanMask)
            AnalogValues[Channel] = Filter_AddVal( AnalogValues[Channel], Reading, FilterNumerator, FilterDenominator );
        else
            AnalogValues[Channel] = Reading;
    }
}

uint16_t AnalogModel_GetChannel(uint8_t Channel)
{
    if (Channel < ANALOG_NUM_CHANS)
        return AnalogValues[Channel];
    else
        return 0;
}
