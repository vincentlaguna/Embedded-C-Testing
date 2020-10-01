#ifndef _ANALOGHARDWARE_H
#define _ANALOGHARDWARE_H

void     AnalogHardware_Init(void);
void     AnalogHardware_SetChans(uint8_t mask);
STATUS_T AnalogHardware_IsReady(uint8_t channel);
uint16_t AnalogHardware_GetReading(uint8_t channel);

#endif // _ANALOGHARDWARE_H
