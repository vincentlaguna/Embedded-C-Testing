#include "Core.h"
#include "Digital.h"

#define DIGITAL_PORT     LPC_GPIO2
#define DIGITAL_PIN_MIN  (0)
#define DIGITAL_PIN_MAX  (5)

#define DIGITAL_PINSEL   LPC_PINCON->PINSEL4
#define DIGITAL_PINMODE  LPC_PINCON->PINMODE4

void Digital_Init(void)
{
    //All our Digital I/O are going to be inputs
    DIGITAL_PORT->FIOMASK &= ~MASK_RANGE(DIGITAL_PIN_MIN, DIGITAL_PIN_MAX);
    DIGITAL_PORT->FIODIR  &= ~MASK_RANGE(DIGITAL_PIN_MIN, DIGITAL_PIN_MAX);

    //Clear pin select bits for bits we plan to use to make them GPIO pins
    DIGITAL_PINSEL &= ~MASK_RANGE_PAIRS(DIGITAL_PIN_MIN, DIGITAL_PIN_MAX, 0x3);

    Digital_ConfigResistors(0x00, 0x3F);
}

void Digital_ConfigResistors(uint8_t pull_up_mask, uint8_t pull_down_mask)
{
    uint32_t full_mask_add = 0;
    uint32_t full_mask_rem = 0;
    uint32_t cur_mask;
    int i;

    for (i = DIGITAL_PIN_MIN; i <= DIGITAL_PIN_MAX; i++)
    {
        //determine which bits to update for each pin
        cur_mask = BIT_TO_MASK(i);
        if ((pull_up_mask & cur_mask) == cur_mask)
        {
            //drive both bits low to get the 0x0 needed for a pullup
            full_mask_rem |= (0x03 << (i << 1));
        }
        else if ((pull_down_mask & cur_mask) == cur_mask)
        {
            //drive both bits high to get the 0x3 needed for a pulldown
            full_mask_add |= (0x03 << (i << 1));
        }
        else
        {
            //drive first bit low and second high to get the 0x2 needed for no resistor
            full_mask_add |= (0x02 << (i << 1));
            full_mask_rem |= (0x01 << (i << 1));
        }
    }

    //Update the actual pullup/down registers
    cur_mask = DIGITAL_PINMODE;
    cur_mask |= full_mask_add;
    cur_mask &= ~full_mask_rem;
    DIGITAL_PINMODE = cur_mask;
}

uint8_t Digital_GetBits(void)
{
    uint32_t bits = DIGITAL_PORT->FIOPIN;

    //remove bits above our range
    bits &= ((2 << DIGITAL_PIN_MAX) - 1);

    //shift bits down to bottom
    bits = bits >> DIGITAL_PIN_MIN;

    return (uint8_t)bits;
}

