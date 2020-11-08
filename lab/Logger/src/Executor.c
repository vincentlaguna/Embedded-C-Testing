#include "Digital.h"
#include "LED.h"
#include "Executor.h"

void Executor_Init(void)
{
    LED_Init();
    Digital_Init();
}

bool Executor_Exec(void)
{
    return true;
}
