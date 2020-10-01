#include "Core.h"

void HexToBin(const char* Src, char* Dst, uint8_t Pairs)
{
    uint8_t i;

    for (i=0; i < Pairs; i++)
    {
        if ((*Src >= '0') && (*Src <= '9'))
            *Dst = (*Src++ - '0') << 4;
        else if ((*Src >= 'A') && (*Src <= 'F'))
            *Dst = (*Src++ +10 - 'A') << 4;

        if ((*Src >= '0') && (*Src <= '9'))
            *Dst++ |= (*Src++ - '0');
        else if ((*Src >= 'A') && (*Src <= 'F'))
            *Dst++ |= (*Src++ +10 - 'A');
    }
    *Dst = 0;
}

void BinToHex(const char* Src, char* Dst, uint8_t Bytes)
{
    uint8_t i;
    char Nibble;

    for (i=0; i < Bytes; i++)
    {
        Nibble = *Src >> 4;
        if (Nibble < 10)
            *Dst++ = (Nibble + '0');
        else
            *Dst++ = (Nibble - 10 + 'A');

        Nibble = *Src & 0x0F;
        if (Nibble < 10)
            *Dst++ = (Nibble + '0');
        else
            *Dst++ = (Nibble - 10 + 'A');

        Src++;
    }
    *Dst = 0;
}
