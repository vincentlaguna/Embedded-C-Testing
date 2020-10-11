#ifndef _DIGITAL_H
#define _DIGITAL_H

void    Digital_Init(void);
void    Digital_ConfigResistors(uint8_t pull_up_mask, uint8_t pull_down_mask);
uint8_t Digital_GetBits(void);

#endif // _DIGITAL_H
