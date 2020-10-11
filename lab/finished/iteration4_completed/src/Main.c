#include "Core.h"
#include "Executor.h"
#include "LED.h"
#include "Main.h"
#include "Timer.h"

#ifndef TEST
int main(void)
#else
int TestableMain(void)
#endif
{
    uint32_t LastTick;

    Executor_Init();

    LastTick = Timer_GetStamp();
    while (Executor_Exec())
    {
        LastTick = Timer_WaitRemainder(LastTick, MAIN_TICK_MSEC);
    }

    return 0;
}
