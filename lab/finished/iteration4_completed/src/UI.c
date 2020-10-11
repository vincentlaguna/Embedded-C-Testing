
#include "Core.h"
#include "Trigger.h"
#include "LED.h"
#include "UI.h"

void UI_Init(void)
{
    LED_Blink(LED_IDLE);
    LED_Off(LED_ARMED);
    LED_Off(LED_CAPTURING);
    LED_Off(LED_COMPLETE);
}

void UI_Exec(void)
{
    if (Trigger_IsComplete())
    {
        LED_Blink(LED_COMPLETE);
        LED_On(LED_CAPTURING);
        LED_On(LED_ARMED);
        LED_On(LED_IDLE);
    }
    else if (Trigger_IsTriggered())
    {
        LED_Off(LED_COMPLETE);
        LED_Blink(LED_CAPTURING);
        LED_On(LED_ARMED);
        LED_On(LED_IDLE);
    }
    else if (Trigger_IsArmed())
    {
        LED_Off(LED_COMPLETE);
        LED_Off(LED_CAPTURING);
        LED_Blink(LED_ARMED);
        LED_On(LED_IDLE);
    }
    else
    {
        LED_Off(LED_COMPLETE);
        LED_Off(LED_CAPTURING);
        LED_Off(LED_ARMED);
        LED_Blink(LED_IDLE);
    }
}
