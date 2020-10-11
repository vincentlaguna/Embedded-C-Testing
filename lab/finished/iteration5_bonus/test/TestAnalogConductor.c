#include "Core.h"
#include "unity.h"
#include "MockAnalogModel.h"
#include "MockAnalogHardware.h"
#include "AnalogConductor.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_AnalogConductor_Init_should_InitSubmodules(void)
{
    AnalogModel_Init_Expect();
    AnalogHardware_Init_Expect();

    AnalogConductor_Init();
}

void test_AnalogConductor_Exec_should_NotUpdateTheModelIfNoChannelsReady(void)
{
    AnalogHardware_IsReady_ExpectAndReturn(0, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(1, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(2, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(3, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(4, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(5, STATUS_NONE_YET);

    AnalogConductor_Exec();
}

void test_AnalogConductor_Exec_should_UpdateTheModelForAChannelWithData(void)
{
    AnalogHardware_IsReady_ExpectAndReturn(0, STATUS_OK);
    AnalogHardware_GetReading_ExpectAndReturn(0, 0x1234);
    AnalogModel_AddReading_Expect(0, 0x1234);
    AnalogHardware_IsReady_ExpectAndReturn(1, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(2, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(3, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(4, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(5, STATUS_NONE_YET);

    AnalogConductor_Exec();
}

void test_AnalogConductor_Exec_should_UpdateTheModelForChannelsWithData(void)
{
    AnalogHardware_IsReady_ExpectAndReturn(0, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(1, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(2, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(3, STATUS_NONE_YET);
    AnalogHardware_IsReady_ExpectAndReturn(4, STATUS_OK);
    AnalogHardware_GetReading_ExpectAndReturn(4, 0x5A5A);
    AnalogModel_AddReading_Expect(4, 0x5A5A);
    AnalogHardware_IsReady_ExpectAndReturn(5, STATUS_OK);
    AnalogHardware_GetReading_ExpectAndReturn(5, 0xA5A5);
    AnalogModel_AddReading_Expect(5, 0xA5A5);

    AnalogConductor_Exec();
}

void test_AnalogConductor_Exec_should_UpdateTheModelForAllChannelsIfAllReady(void)
{
    AnalogHardware_IsReady_ExpectAndReturn(0, STATUS_OK);
    AnalogHardware_GetReading_ExpectAndReturn(0, 0x1111);
    AnalogModel_AddReading_Expect(0, 0x1111);
    AnalogHardware_IsReady_ExpectAndReturn(1, STATUS_OK);
    AnalogHardware_GetReading_ExpectAndReturn(1, 0x2222);
    AnalogModel_AddReading_Expect(1, 0x2222);
    AnalogHardware_IsReady_ExpectAndReturn(2, STATUS_OK);
    AnalogHardware_GetReading_ExpectAndReturn(2, 0x3333);
    AnalogModel_AddReading_Expect(2, 0x3333);
    AnalogHardware_IsReady_ExpectAndReturn(3, STATUS_OK);
    AnalogHardware_GetReading_ExpectAndReturn(3, 0x4444);
    AnalogModel_AddReading_Expect(3, 0x4444);
    AnalogHardware_IsReady_ExpectAndReturn(4, STATUS_OK);
    AnalogHardware_GetReading_ExpectAndReturn(4, 0x5555);
    AnalogModel_AddReading_Expect(4, 0x5555);
    AnalogHardware_IsReady_ExpectAndReturn(5, STATUS_OK);
    AnalogHardware_GetReading_ExpectAndReturn(5, 0x6666);
    AnalogModel_AddReading_Expect(5, 0x6666);

    AnalogConductor_Exec();
}
