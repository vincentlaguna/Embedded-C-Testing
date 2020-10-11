#include "Core.h"
#include "Params.h"

#define PARAMS_MAX    (16)

typedef struct _PARAM_T
{
    PARAM_ID_T ID;
    uint16_t MinVal;
    uint16_t MaxVal;
    uint16_t Default;
    uint8_t*  U8;
    uint16_t* U16;
    PARAM_CALLBACK_T Callback;
} PARAM_T;

static PARAM_T Params[ PARAMS_MAX ];
static uint8_t NumParams;

void Param_Init(void)
{
    NumParams = 0;
}


STATUS_T Param_RegisterU8(PARAM_ID_T ID, uint8_t MinVal, uint8_t MaxVal, uint8_t Default, uint8_t* Ptr) {
    return Param_RegisterU8WithCallback(ID, MinVal, MaxVal, Default, Ptr, NULL);
}

STATUS_T Param_RegisterU16(PARAM_ID_T ID, uint16_t MinVal, uint16_t MaxVal, uint16_t Default, uint16_t* Ptr) {
    return Param_RegisterU16WithCallback(ID, MinVal, MaxVal, Default, Ptr, NULL);
}

STATUS_T Param_RegisterU8WithCallback(PARAM_ID_T ID, uint8_t MinVal, uint8_t MaxVal, uint8_t Default, uint8_t* Ptr, PARAM_CALLBACK_T Callback)
{
    if (NumParams >= PARAMS_MAX)
        return STATUS_TOO_MANY_PARAMS;

    Params[ NumParams ].ID = ID;
    Params[ NumParams ].MinVal = MinVal;
    Params[ NumParams ].MaxVal = MaxVal;
    Params[ NumParams ].Default = Default;
    Params[ NumParams ].U16 = NULL;
    Params[ NumParams ].U8 = Ptr;
    Params[ NumParams ].Callback = Callback;
    NumParams++;

    *Ptr = Default;

    return STATUS_OK;
}

STATUS_T Param_RegisterU16WithCallback(PARAM_ID_T ID, uint16_t MinVal, uint16_t MaxVal, uint16_t Default, uint16_t* Ptr, PARAM_CALLBACK_T Callback)
{
    if (NumParams >= PARAMS_MAX)
        return STATUS_TOO_MANY_PARAMS;

    Params[ NumParams ].ID = ID;
    Params[ NumParams ].MinVal = MinVal;
    Params[ NumParams ].MaxVal = MaxVal;
    Params[ NumParams ].Default = Default;
    Params[ NumParams ].U16 = Ptr;
    Params[ NumParams ].U8 = NULL;
    Params[ NumParams ].Callback = Callback;
    NumParams++;

    *Ptr = Default;

    return STATUS_OK;
}

uint8_t Param_List(PARAM_ID_T* IDs, uint8_t MaxIDs)
{
    uint8_t i;

    if (MaxIDs > NumParams)
        MaxIDs = NumParams;

    for (i = 0; i < MaxIDs; i++)
        IDs[i] = Params[i].ID;

    return MaxIDs;
}

STATUS_T Param_Get(PARAM_ID_T ID, uint16_t* Val)
{
    uint8_t i;

    for (i=0; i < NumParams; i++) {
        if (Params[i].ID == ID) {
            if (Params[i].U16)
                *Val = *Params[i].U16;
            else
                *Val = *Params[i].U8;
            return STATUS_OK;
        }
    }
    return STATUS_INVALID_PARAM;
}

STATUS_T Param_Set(PARAM_ID_T ID, uint16_t Val)
{
    uint8_t i;

    for (i=0; i < NumParams; i++) {
        if (Params[i].ID == ID) {

            if (Val < Params[i].MinVal)
                return STATUS_TOO_LOW;
            if (Val > Params[i].MaxVal)
                return STATUS_TOO_HIGH;

            if (Params[i].U16)
                *Params[i].U16 = Val;
            else
                *Params[i].U8 = Val;

            if (Params[i].Callback)
                Params[i].Callback();

            return STATUS_OK;
        }
    }
    return STATUS_INVALID_PARAM;
}

STATUS_T Param_Defaults(void)
{
    uint8_t i;

    for (i=0; i < NumParams; i++) {
        if (Params[i].U16)
            *Params[i].U16 = Params[i].Default;
        else
            *Params[i].U8 = Params[i].Default;

        if (Params[i].Callback)
            Params[i].Callback();
    }
    return STATUS_OK;
}
