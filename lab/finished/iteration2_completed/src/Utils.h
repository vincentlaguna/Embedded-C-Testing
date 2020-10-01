#ifndef _UTILS_H
#define _UTILS_H

#define DIMENSION_OF(a)    (sizeof(a) / sizeof(a[0]))

#define BIT_TO_MASK(bit)   (1u << bit)
#define BIT_TO_MASK8(bit)  (uint8_t)(1u << bit)
#define BIT_TO_MASK16(bit) (uint16_t)(1u << bit)

#define UINT32_BYTE3(w)    ((w >> 24) & 0x00FF)
#define UINT32_BYTE2(w)    ((w >> 16) & 0x00FF)
#define UINT32_BYTE1(w)    ((w >>  8) & 0x00FF)
#define UINT32_BYTE0(w)    ((w      ) & 0x00FF)

#define BYTE0_TO_UINT32(b) ((uint32_t)(b) << 24)
#define BYTE1_TO_UINT32(b) ((uint32_t)(b) << 16)
#define BYTE2_TO_UINT32(b) ((uint32_t)(b) <<  8)
#define BYTE3_TO_UINT32(b) ((uint32_t)(b)      )

void HexToBin(const char* Src, char* Dst, uint8_t Pairs);
void BinToHex(const char* Src, char* Dst, uint8_t Bytes);

#define DIV_ROUND_UP(n,d) ((n + (d - 1)) / d)

//This is useful for setting the pinsel and pinmode config registers
#define MASK_BIT_PAIR(bit, val)     (val << ((bit % 16) << 1))

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"

static inline uint32_t MASK_RANGE(uint32_t b1, uint32_t b2)
{
    return ((2 << b2) - 1) - ((1 << b1) - 1);
}

static inline uint32_t MASK_RANGE_PAIRS(uint32_t b1, uint32_t b2, uint32_t val)
{
    uint32_t i;
    uint32_t retval = 0;

    for (i = b1; i <= b2; i++)
        retval |= MASK_BIT_PAIR(i, val);

    return retval;
}

static inline uint8_t COUNT_HIGH_BITS8(uint8_t b)
{
    b -= ((b >> 1) & 0x55);
    b  = ((b >> 2) & 0x33) + (b & 0x33);
    b  = ((b >> 4) + b) & 0x0F;
    return b;
}

#pragma GCC diagnostic pop

#endif // _UTILS_H
