#ifndef _COMMANDHARDWARE_H
#define _COMMANDHARDWARE_H

#include "CommandConductor.h"
#include "USBDriver.h"

#define USB_MAX_BUFFER_LENGTH    (256)

#ifdef TEST
void CommandHardware_Init(void);
void CommandHardware_Exec(void);
#else
static inline void CommandHardware_Init(void) { USBDriver_Init(); };
static inline void CommandHardware_Exec(void) { USBDriver_Exec(); };
#endif

STATUS_T CommandHardware_CheckForMsg(MESSAGE_T* msg);
STATUS_T CommandHardware_SendResponse(MESSAGE_T* Msg);
STATUS_T CommandHardware_SendError(MESSAGE_T* Msg, STATUS_T Error);

#endif // _COMMANDHARDWARE_H
