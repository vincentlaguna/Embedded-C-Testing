#include "Core.h"
#include "Params.h"
#include "Sampler.h"

STATIC uint16_t SampleMax = 16;
STATIC uint16_t SampleRate = 50;
static uint16_t SampleCountsRemaining;
static uint16_t SampleTicksRemaining;

void Sampler_Init(void)
{
    Param_RegisterU16(PARAM_NUM_SAMPLES,  0,  4096,  16, &SampleMax );
    Param_RegisterU16(PARAM_CAPTURE_RATE, 50, 10000, 50, &SampleRate);
}

void Sampler_Reset(void)
{
    SampleCountsRemaining = SampleMax;
    SampleTicksRemaining  = 1;
}

BOOL Sampler_IsReady(void)
{
    if (SampleCountsRemaining) {
        if (--SampleTicksRemaining == 0) {
            SampleTicksRemaining = SampleRate / MAIN_TICK_MSEC;
            SampleCountsRemaining--;
            return TRUE;
        }
    }
    return FALSE;
}
