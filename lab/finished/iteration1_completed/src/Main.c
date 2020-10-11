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
    Executor_Init();

    while (Executor_Exec())
    {
        Timer_WaitMilli(MAIN_TICK_MSEC);
    }

    return 0;
}
