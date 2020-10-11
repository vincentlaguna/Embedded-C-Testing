#include "Core.h"
#include "Timer.h"

#ifdef TEST
uint32_t TestCounter;
#define WAIT_UNTIL_EQUAL(a,b) while(a++ != b) { TestCounter++; }
#else
#define WAIT_UNTIL_EQUAL(a,b) while(a != b) {}
#endif

void SysTick_Handler(void);
static volatile uint32_t TimeStamp;

void Timer_Init(void)
{
    long* isr_vector;
    uint32_t counts_per_tick = __CORE_CLK / 100;

    //Disable so we can config
    SysTick->CTRL  = ~SysTick_CTRL_CLKSOURCE_Msk;

    //Set up Tick Handler
    isr_vector = (long*)(SCB->VTOR);
    isr_vector[15] = (long)SysTick_Handler;

    //Configure
    SysTick->LOAD  = counts_per_tick - 1;
    SysTick->VAL   = 0UL;

    //Enable
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                     SysTick_CTRL_TICKINT_Msk   |
                     SysTick_CTRL_ENABLE_Msk;

    TimeStamp = 0;
}

void Timer_SetStamp(uint32_t Stamp)
{
    TimeStamp = Stamp;
}

uint32_t Timer_GetStamp(void)
{
    return TimeStamp;
}

void Timer_WaitMilli(uint32_t msec)
{
    uint32_t Goal = TimeStamp + msec;
    WAIT_UNTIL_EQUAL(TimeStamp, Goal);
}

void SysTick_Handler(void)
{
    TimeStamp += 10;
}
