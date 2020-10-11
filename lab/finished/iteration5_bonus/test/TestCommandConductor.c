#include "unity.h"
#include "CommandConductor.h"
#include "MockCommandHardware.h"
#include "MockCommandHandlers.h"

static MESSAGE_T msg;
static MESSAGE_T rsp;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_CommandConductor_Init_ShouldInitializeSubmodules(void)
{
    CommandHardware_Init_Expect();
    CommandHandlers_Init_Expect();

    CommandConductor_Init();
}

void test_CommandConductor_Exec_Should_CheckForMessages_And_DoNothingIfNone(void)
{
    CommandHardware_Exec_Expect();
    CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_NONE_YET );

    CommandConductor_Exec();
}

void test_CommandConductor_Exec_Should_CheckForMessages_And_DoNothingIfUnknown(void)
{
    msg.Cmd = 'U'; //Unknown Command

    CommandHardware_Exec_Expect();
    CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
    CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
    CommandHardware_SendError_ExpectAndReturn( &msg, STATUS_UNKNOWN_CMD, STATUS_OK );

    CommandConductor_Exec();
}

void test_CommandConductor_Exec_Should_CheckForMessages_And_ProcessIfVersionAndReturnResponse(void)
{
    msg.Cmd = 'V'; //Version Command
    rsp.Cmd = 'v'; //Something different to show it's a response

    CommandHardware_Exec_Expect();
    CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
    CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
    CommandHandlerVersion_ExpectAndReturn( &msg, STATUS_OK );
    CommandHandlerVersion_ReturnThruPtr_Msg( &rsp );
    CommandHardware_SendResponse_ExpectAndReturn( &rsp, STATUS_OK );

    CommandConductor_Exec();
}

void test_CommandConductor_Exec_Should_CHeckForMessages_And_ProcessIfVersionAndHandleErrors(void)
{
    msg.Cmd = 'V'; //Version Command
    rsp.Cmd = 'v'; //Something different to show it's a response

    CommandHardware_Exec_Expect();
    CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
    CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
    CommandHandlerVersion_ExpectAndReturn( &msg, STATUS_EXTRA_ARG );
    CommandHandlerVersion_ReturnThruPtr_Msg( &rsp );
    CommandHardware_SendError_ExpectAndReturn( &rsp, STATUS_EXTRA_ARG, STATUS_OK );

    CommandConductor_Exec();
}

void test_CommandConductor_Exec_Should_CheckForMessages_And_ProcessIfClockAndReturnResponse(void)
{
    msg.Cmd = 'C'; //Clock Command
    rsp.Cmd = 'c'; //Something different to show it's a response

    CommandHardware_Exec_Expect();
    CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
    CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
    CommandHandlerClock_ExpectAndReturn( &msg, STATUS_OK );
    CommandHandlerClock_ReturnThruPtr_Msg( &rsp );
    CommandHardware_SendResponse_ExpectAndReturn( &rsp, STATUS_OK );

    CommandConductor_Exec();
}

void test_CommandConductor_Exec_Should_CheckForMessages_And_ProcessIfResultsAndReturnResponse(void)
{
    msg.Cmd = 'R'; //Results Command
    rsp.Cmd = 'r'; //Something different to show it's a response

    CommandHardware_Exec_Expect();
    CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
    CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
    CommandHandlerResults_ExpectAndReturn( &msg, STATUS_OK );
    CommandHandlerResults_ReturnThruPtr_Msg( &rsp );
    CommandHardware_SendResponse_ExpectAndReturn( &rsp, STATUS_OK );

    CommandConductor_Exec();
}

void test_CommandConductor_Exec_Should_CheckForMessages_And_ProcessIfArmAndReturnResponse(void)
{
    msg.Cmd = 'A'; //Arm Command
    rsp.Cmd = 'a'; //Something different to show it's a response

    CommandHardware_Exec_Expect();
    CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
    CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
    CommandHandlerArm_ExpectAndReturn( &msg, STATUS_OK );
    CommandHandlerArm_ReturnThruPtr_Msg( &rsp );
    CommandHardware_SendResponse_ExpectAndReturn( &rsp, STATUS_OK );

    CommandConductor_Exec();
}

void test_CommandConductor_Exec_Should_CheckForMessages_And_ProcessIfTriggerAndReturnResponse(void)
{
    msg.Cmd = 'T'; //Trigger Command
    rsp.Cmd = 't'; //Something different to show it's a response

    CommandHardware_Exec_Expect();
    CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
    CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
    CommandHandlerTrigger_ExpectAndReturn( &msg, STATUS_OK );
    CommandHandlerTrigger_ReturnThruPtr_Msg( &rsp );
    CommandHardware_SendResponse_ExpectAndReturn( &rsp, STATUS_OK );

    CommandConductor_Exec();
}

void test_CommandConductor_Exec_Should_CheckForMessages_And_ProcessIfParamsAndReturnResponse(void)
{
    msg.Cmd = 'P'; //Params Command
    rsp.Cmd = 'p'; //Something different to show it's a response

    CommandHardware_Exec_Expect();
    CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
    CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
    CommandHandlerParams_ExpectAndReturn( &msg, STATUS_OK );
    CommandHandlerParams_ReturnThruPtr_Msg( &rsp );
    CommandHardware_SendResponse_ExpectAndReturn( &rsp, STATUS_OK );

    CommandConductor_Exec();
}

void test_CommandConductor_Exec_Should_CheckForMessages_And_ProcessIfDefaultAndReturnResponse(void)
{
    msg.Cmd = 'D'; //Default Command
    rsp.Cmd = 'd'; //Something different to show it's a response

    CommandHardware_Exec_Expect();
    CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
    CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
    CommandHandlerDefault_ExpectAndReturn( &msg, STATUS_OK );
    CommandHandlerDefault_ReturnThruPtr_Msg( &rsp );
    CommandHardware_SendResponse_ExpectAndReturn( &rsp, STATUS_OK );

    CommandConductor_Exec();
}


