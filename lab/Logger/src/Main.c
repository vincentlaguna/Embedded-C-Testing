#include "Core.h"
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
    LED_Init();    
		
    return 0;
}
