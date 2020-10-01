#ifndef _ANALOGMODEL_H
#define _ANALOGMODEL_H

//Internal API
void     AnalogModel_Init(void);
void     AnalogModel_AddReading(uint8_t Channel, uint16_t Reading);

//Public API
uint16_t AnalogModel_GetChannel(uint8_t Channel);

#endif // _ANALOGMODEL_H
