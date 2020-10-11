
#include "Core.h"
#include "AnalogModel.h"
#include "AnalogHardware.h"
#include "AnalogConductor.h"


void AnalogConductor_Init(void)
{
    AnalogModel_Init();
    AnalogHardware_Init();
}

void AnalogConductor_Exec(void)
{
    uint8_t i;
    uint16_t Value;

    //Check up on the Analog Channels
    for (i=0; i < ANALOG_NUM_CHANS; i++)
    {
        if (AnalogHardware_IsReady(i) == STATUS_OK)
        {
            Value = AnalogHardware_GetReading(i);
            AnalogModel_AddReading(i, Value);
        }
    }
}

