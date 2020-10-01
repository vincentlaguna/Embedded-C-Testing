#include "Core.h"
#include "CommandConductor.h"
#include "CommandHardware.h"
#include "CommandHandlers.h"

typedef STATUS_T (*COMMAND_HANDLER_T)(MESSAGE_T* Msg);

static const struct _COMMAND_HANDLERS
{
    char Cmd;
    COMMAND_HANDLER_T Func;
} CommandHandlers[] =
{
    { 'A', CommandHandlerArm        },
    { 'C', CommandHandlerClock      },
    { 'D', CommandHandlerDefault    },
    { 'P', CommandHandlerParams     },
    { 'R', CommandHandlerResults    },
    { 'T', CommandHandlerTrigger    },
    { 'V', CommandHandlerVersion    },
};

void CommandConductor_Init(void)
{
    CommandHardware_Init();
    CommandHandlers_Init();
}

void CommandConductor_Exec(void)
{
    uint32_t i;
    MESSAGE_T Msg;
    STATUS_T retval;

    CommandHardware_Exec();

    if (CommandHardware_CheckForMsg(&Msg) == STATUS_OK) {
        retval = STATUS_UNKNOWN_CMD;
        for (i=0; i < DIMENSION_OF(CommandHandlers); i++)
        {
            if (CommandHandlers[i].Cmd == Msg.Cmd)
            {
                retval = CommandHandlers[i].Func(&Msg);
                break;
            }
        }

        //Handle our Response
        if (retval == STATUS_OK)
        {
            CommandHardware_SendResponse(&Msg);
        }
        else
        {
            CommandHardware_SendError(&Msg, retval);
        }
    }
}
