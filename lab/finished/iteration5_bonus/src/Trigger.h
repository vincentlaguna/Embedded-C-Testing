#ifndef _TRIGGER_H
#define _TRIGGER_H

typedef enum _TRIGGER_T
{
    TRIGGER_NOW         = 0,
    TRIGGER_BIT_CHANGE  = 1,
    TRIGGER_BIT_STATE   = 2,
    TRIGGER_SEQUENCE    = 3,
    TRIGGER_TIMESTAMP   = 4,

    TRIGGER_MAX,
    TRIGGER_NONE = TRIGGER_MAX

} TRIGGER_T;

void Trigger_Init(void);
void Trigger_Reset(void);
int  Trigger_IsTriggered(void);
int  Trigger_IsArmed(void);
int  Trigger_IsComplete(void);

STATUS_T Trigger_Arm(void);
STATUS_T Trigger_Disarm(void);
STATUS_T Trigger_OnBitChange(uint8_t MaskToCheck);
STATUS_T Trigger_OnBitState( uint8_t MaskToCheck, uint8_t MaskStates);
STATUS_T Trigger_OnSequence( uint8_t MaskToCheck, uint8_t* MaskStates, uint8_t Len);
STATUS_T Trigger_OnTimestamp(uint32_t Timestamp);
STATUS_T Trigger_Now(void);
STATUS_T Trigger_Complete(void);

TRIGGER_T Trigger_GetStyle(void);

#endif // _TRIGGER_H
