#ifndef _MAIN_H
#define _MAIN_H

#define MAIN_TICK_MSEC    (50)

#ifndef TEST
int main(void);
#else
int TestableMain(void);
#endif

#endif // _MAIN_H
