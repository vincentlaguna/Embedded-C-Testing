#include "Core.h"
#include "Filter.h"

uint16_t Filter_AddVal(uint16_t PrevVal, uint16_t NewVal, uint16_t Numerator, uint16_t Denominator)
{
    uint32_t Sum = Numerator * (uint32_t)PrevVal + NewVal + (Numerator / 2);
    return (uint16_t)( Sum / Denominator );
}
