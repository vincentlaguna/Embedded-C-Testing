#include "Core.h"
#include "Filter.h"

uint16_t Filter_AddVal(uint16_t PrevVal, uint16_t NewVal)
{
    uint32_t Sum = 3 * (uint32_t)PrevVal + NewVal + 2;
    return (uint16_t)( Sum / 4 );
}
