#ifndef _COMMANDHANDLERS_H
#define _COMMANDHANDLERS_H

#include "CommandConductor.h"

void     CommandHandlers_Init(void);
STATUS_T CommandHandlerVersion(MESSAGE_T* Msg);
STATUS_T CommandHandlerClock(MESSAGE_T* Msg);
STATUS_T CommandHandlerDefault(MESSAGE_T* Msg);
STATUS_T CommandHandlerParams(MESSAGE_T* Msg);
STATUS_T CommandHandlerResults(MESSAGE_T* Msg);
STATUS_T CommandHandlerArm(MESSAGE_T* Msg);
STATUS_T CommandHandlerTrigger(MESSAGE_T* Msg);

#endif // _COMMANDHANDLERS_H
