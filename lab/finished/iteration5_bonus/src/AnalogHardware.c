
#include "Core.h"
#include "AnalogHardware.h"

#define ANALOG_PIN0_MIN    (23)
#define ANALOG_PIN0_MAX    (26)
#define ANALOG_PIN1_MIN    (30)
#define ANALOG_PIN1_MAX    (31)

//Verify we have the right number of channels
#define ANALOG_NUM_ACTUAL  ((1 + ANALOG_PIN1_MAX - ANALOG_PIN1_MIN) + (1 + ANALOG_PIN0_MAX - ANALOG_PIN0_MIN))
#if ANALOG_NUM_CHANS != ANALOG_NUM_ACTUAL
#error "The number of analog channels does not match pin configuration"
#endif

#define ANALOG_PIN0SEL     LPC_PINCON->PINSEL1
#define ANALOG_PIN0FUNC    0x01 //ADC
#define ANALOG_PIN0PULL    0x03 //pulldown
#define ANALOG_PIN0MODE    LPC_PINCON->PINMODE1

#define ANALOG_PIN1SEL     LPC_PINCON->PINSEL3
#define ANALOG_PIN1FUNC    0x03 //ADC
#define ANALOG_PIN1PULL    0x03 //pulldown
#define ANALOG_PIN1MODE    LPC_PINCON->PINMODE3

#define ANALOG_CLK_SEL     LPC_SC->PCLKSEL0
#define ANALOG_PERIPH_NUM  12   //12th pair on CLK SEL Register
#define ANALOG_PERIPH_VAL  0x1  //Clk / 1
#define ANALOG_MAX_CLK     13000000
#define ANALOG_CLK_DIV     (DIV_ROUND_UP(__CORE_CLK, ANALOG_MAX_CLK) - 1)

void AnalogHardware_Init(void)
{
    uint32_t temp;

    //Set the PORT 0 PINS to be ADC pins
    temp = ANALOG_PIN0SEL;
    temp &= ~MASK_RANGE_PAIRS(ANALOG_PIN0_MIN, ANALOG_PIN0_MAX, 0x3);
    temp |=  MASK_RANGE_PAIRS(ANALOG_PIN0_MIN, ANALOG_PIN0_MAX, ANALOG_PIN0FUNC);
    ANALOG_PIN0SEL = temp;

    //Set the PORT 1 PINS to be ADC pins
    temp = ANALOG_PIN1SEL;
    temp &= ~MASK_RANGE_PAIRS(ANALOG_PIN1_MIN, ANALOG_PIN1_MAX, 0x3);
    temp |=  MASK_RANGE_PAIRS(ANALOG_PIN1_MIN, ANALOG_PIN1_MAX, ANALOG_PIN1FUNC);
    ANALOG_PIN1SEL = temp;

    //Set the PORT 0 PINS to have correct pullup or pulldown
    temp = ANALOG_PIN0MODE;
    temp &= ~MASK_RANGE_PAIRS(ANALOG_PIN0_MIN, ANALOG_PIN0_MAX, 0x3);
    temp |=  MASK_RANGE_PAIRS(ANALOG_PIN0_MIN, ANALOG_PIN0_MAX, ANALOG_PIN0PULL);
    ANALOG_PIN0MODE = temp;

    //Set the PORT 1 PINS to have correct pullup or pulldown
    temp = ANALOG_PIN1MODE;
    temp &= ~MASK_RANGE_PAIRS(ANALOG_PIN1_MIN, ANALOG_PIN1_MAX, 0x3);
    temp |=  MASK_RANGE_PAIRS(ANALOG_PIN1_MIN, ANALOG_PIN1_MAX, ANALOG_PIN1PULL);
    ANALOG_PIN1MODE = temp;

    //Ensure power is turned on
    LPC_SC->PCONP |= BIT_TO_MASK(ANALOG_PERIPH_NUM);

    //Set the peripheral clock of the ADC to 1 (same as main clock)
    temp = ANALOG_CLK_SEL;
    temp &= ~MASK_BIT_PAIR(ANALOG_PERIPH_NUM, 0x3);
    temp |=  MASK_BIT_PAIR(ANALOG_PERIPH_NUM, ANALOG_PERIPH_VAL);
    ANALOG_CLK_SEL = temp;

    AnalogHardware_SetChans(0x3F);
}

void AnalogHardware_SetChans(uint8_t mask)
{
    uint32_t UseBurst = (mask != 0);

    //Use Burst Mode To Constantly Cycle Between Values
    LPC_ADC->ADCR = (uint32_t)(mask)      // SEL: channels selected
                  | (ANALOG_CLK_DIV << 8) // CLKDIV: PCLK max ~= 25MHz, /25 to give safe 1MHz at fastest
                  | (UseBurst << 16)      // BURST: 1 = automatic control
                  | (0 << 17)             // CLKS: not applicable
                  | (1 << 21)             // PDN: 1 = operational
                  | (0 << 24)             // START: 0 = no start for burst mode
                  | (0 << 27);            // EDGE: not applicable
}

STATUS_T AnalogHardware_IsReady(uint8_t channel)
{
    uint32_t mask = BIT_TO_MASK(channel);

    if (channel >= ANALOG_NUM_CHANS)
        return STATUS_TOO_HIGH;

    if ((LPC_ADC->ADSTAT & mask) == mask)
        return STATUS_OK;
    else
        return STATUS_NONE_YET;
}

uint16_t AnalogHardware_GetReading(uint8_t channel)
{
    uint32_t* cur_data = (uint32_t*)(&(LPC_ADC->ADDR0));

    if (channel >= ANALOG_NUM_CHANS)
        return STATUS_TOO_HIGH;

    //shift register down to correct bits
    return (uint16_t)((cur_data[channel] >> 4) & 0x0FFF);
}
