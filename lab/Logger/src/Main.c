#include "Core.h"
#include "Executor.h"
#include "Main.h"

//
// NOTE: Do not attempt to test main() directly.
//       See Lecture 9 for how to handle this special case.
// ========================================================
//
#ifndef TEST
int main(void)
#else
int TestableMain(void)
#endif
{
    Executor_Init();    

    while(Executor_Exec())
    {
        // Do nothing else...
    };    
		
    return 0;
}
