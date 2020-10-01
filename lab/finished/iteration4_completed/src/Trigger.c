#include "Core.h"
#include "Digital.h"
#include "Timer.h"
#include "Trigger.h"

#define TRIGGER_SEQUENCE_MAX 8

static STATUS_T  TriggerState;
static TRIGGER_T TriggerStyle;
static uint8_t   PrevBitState;
static uint8_t   TriggerBitMask;
static uint8_t   TriggerSeq[ TRIGGER_SEQUENCE_MAX ];
static uint8_t   TriggerSeqPos;
static uint8_t   TriggerSeqStart;
static uint32_t  TriggerTime;

#define RETURN_IF_NOT_ARMED()                    \
    if (TriggerState != STATUS_NONE_YET)         \
    {                                            \
        if (TriggerState == STATUS_CAPTURING)    \
            return STATUS_ALREADY_TRIGGERED;     \
        else                                     \
            return STATUS_NOT_ARMED;             \
    }

void Trigger_Init(void)
{
    Trigger_Reset();
}

void Trigger_Reset(void)
{
    TriggerState = STATUS_NOT_ARMED;
    TriggerStyle = TRIGGER_NONE;
}

int Trigger_IsArmed(void)
{
    return ((TriggerState == STATUS_CAPTURING) || (TriggerState == STATUS_NONE_YET));
}

int Trigger_IsComplete(void)
{
    return (TriggerState == STATUS_OK);
}

int Trigger_IsTriggered(void)
{
    uint8_t CurBitState;

    if (TriggerState == STATUS_CAPTURING)
        return 1;

    //check for latest conditions
    switch(TriggerStyle)
    {
        case TRIGGER_BIT_CHANGE:
            CurBitState = Digital_GetBits() & TriggerBitMask;
            if (CurBitState != PrevBitState) {
                TriggerState = STATUS_CAPTURING;
                return 1;
            }
            break;

        case TRIGGER_BIT_STATE:
        case TRIGGER_SEQUENCE:
            CurBitState = Digital_GetBits() & TriggerBitMask;
            if (CurBitState == (TriggerBitMask & TriggerSeq[TriggerSeqPos]))
            {
                if (TriggerSeqPos == 0) {
                    TriggerState = STATUS_CAPTURING;
                    return 1;
                }
                TriggerSeqPos--;
            }
            else if (CurBitState != PrevBitState)
                TriggerSeqPos = TriggerSeqStart;
            PrevBitState = CurBitState;
            break;

        case TRIGGER_TIMESTAMP:
            if (Timer_GetStamp() >= TriggerTime) {
                TriggerState = STATUS_CAPTURING;
                return 1;
            }
            break;

        default:
            break;
    }
    return 0;
}

STATUS_T Trigger_Disarm(void)
{
    TriggerState = STATUS_NOT_ARMED;
    return STATUS_OK;
}

STATUS_T Trigger_Arm(void)
{
    if (TriggerState != STATUS_NONE_YET)
    {
        TriggerState = STATUS_NONE_YET;
        TriggerStyle = TRIGGER_NONE;
        return STATUS_OK;
    }
    else
    {
        return STATUS_ALREADY_ARMED;
    }
}

STATUS_T Trigger_OnBitChange(uint8_t MaskToCheck)
{
    RETURN_IF_NOT_ARMED();

    TriggerBitMask = MaskToCheck;
    PrevBitState = Digital_GetBits() & MaskToCheck;
    TriggerStyle = TRIGGER_BIT_CHANGE;
    return STATUS_OK;
}

STATUS_T Trigger_OnBitState( uint8_t MaskToCheck, uint8_t MaskStates)
{
    RETURN_IF_NOT_ARMED();

    TriggerBitMask = MaskToCheck;
    TriggerSeq[0] = MaskStates & MaskToCheck;
    TriggerSeqStart = 0;
    TriggerSeqPos = 0;
    TriggerStyle = TRIGGER_BIT_STATE;
    return STATUS_OK;
}

STATUS_T Trigger_OnSequence( uint8_t MaskToCheck, uint8_t* MaskStates, uint8_t Len)
{
    uint8_t i;

    RETURN_IF_NOT_ARMED();
    if (Len > TRIGGER_SEQUENCE_MAX)
        return STATUS_INVALID_ARG;

    TriggerBitMask = MaskToCheck;
    for (i = 0; i < Len; i++)
        TriggerSeq[Len - i - 1] = MaskStates[i] & MaskToCheck;
    TriggerSeqStart = Len - 1;
    TriggerSeqPos = TriggerSeqStart;

    TriggerStyle = TRIGGER_SEQUENCE;
    return STATUS_OK;
}

STATUS_T Trigger_OnTimestamp(uint32_t Timestamp)
{
    RETURN_IF_NOT_ARMED();

    TriggerTime = Timestamp;

    TriggerStyle = TRIGGER_TIMESTAMP;
    return STATUS_OK;
}

STATUS_T Trigger_Now(void)
{
    RETURN_IF_NOT_ARMED();

    TriggerState = STATUS_CAPTURING;
    TriggerStyle = TRIGGER_NOW;
    return STATUS_OK;
}

TRIGGER_T Trigger_GetStyle(void)
{
    if ((TriggerState == STATUS_NONE_YET) || (TriggerState == STATUS_CAPTURING))
        return TriggerStyle;
    else
        return TRIGGER_NONE;
}

STATUS_T Trigger_Complete(void)
{
    if (TriggerState == STATUS_CAPTURING)
    {
        TriggerState = STATUS_OK;
        TriggerStyle = TRIGGER_NONE;
        return STATUS_OK;
    }
    else
    {
        return TriggerState;
    }
}
