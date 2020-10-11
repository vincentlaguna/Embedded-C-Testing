#ifndef _COMMANDCONDUCTOR_H
#define _COMMANDCONDUCTOR_H

#include "Defs.h"

#define COMMAND_MAX_LEN    (75) // 1-Z is 1-35 pairs of nibbles, therefore 70 nibbles + overhead

typedef struct _MESSAGE_T
{
    char Cmd;
    char Len;
    char Data[COMMAND_MAX_LEN];
} MESSAGE_T;

void CommandConductor_Init(void);
void CommandConductor_Exec(void);

#endif // _COMMANDCONDUCTOR_H
