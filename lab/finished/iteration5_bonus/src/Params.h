#ifndef _PARAMS_H
#define _PARAMS_H

#define PARAM_NUM_SAMPLES          (0x00)
#define PARAM_CAPTURE_RATE         (0x01)
#define PARAM_DIGITAL_CHANS        (0xD0)
#define PARAM_DIGITAL_PULLDOWN     (0xD1)
#define PARAM_DIGITAL_PULLUP       (0xD2)
#define PARAM_DIGITAL_DEBOUNCE     (0xD3)
#define PARAM_ANALOG_CHANS         (0xA0)
#define PARAM_FILTER_CHANS         (0xA1)
#define PARAM_FILTER_NUMERATOR     (0xA2)
#define PARAM_FILTER_DENOMINATOR   (0xA3)
#define PARAM_COMM_CHANS           (0xC0)
#define PARAM_COM1_BAUD            (0xC1)
#define PARAM_COM2_BAUD            (0xC2)
#define PARAM_COM3_BAUD            (0xC3)

typedef void (*PARAM_CALLBACK_T)(void);

void     Param_Init(void);
STATUS_T Param_RegisterU8(PARAM_ID_T ID, uint8_t MinVal, uint8_t MaxVal, uint8_t Default, uint8_t* Ptr);
STATUS_T Param_RegisterU16(PARAM_ID_T ID, uint16_t MinVal, uint16_t MaxVal, uint16_t Default, uint16_t* Ptr) ;
STATUS_T Param_RegisterU8WithCallback(PARAM_ID_T ID, uint8_t MinVal, uint8_t MaxVal, uint8_t Default, uint8_t* Ptr, PARAM_CALLBACK_T Callback);
STATUS_T Param_RegisterU16WithCallback(PARAM_ID_T ID, uint16_t MinVal, uint16_t MaxVal, uint16_t Default, uint16_t* Ptr, PARAM_CALLBACK_T Callback);
uint8_t  Param_List(PARAM_ID_T* IDs, uint8_t MaxIDs);
STATUS_T Param_Get(PARAM_ID_T ID, uint16_t* Val);
STATUS_T Param_Set(PARAM_ID_T ID, uint16_t Val);
STATUS_T Param_Defaults(void);

#endif // _PARAMS_H
