#include "Core.h"
#include "unity.h"
#include "MockParams.h"
#include "Sampler.h"

extern uint16_t SampleMax;
extern uint16_t SampleRate;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Sampler_Init_ShouldSetUpParamters(void)
{
    Param_RegisterU16_ExpectAndReturn(PARAM_NUM_SAMPLES,  0,  4096,  16, NULL, STATUS_OK);
    Param_RegisterU16_IgnoreArg_Ptr();

    Param_RegisterU16_ExpectAndReturn(PARAM_CAPTURE_RATE, 50, 10000, 50, NULL, STATUS_OK);
    Param_RegisterU16_IgnoreArg_Ptr();

    Sampler_Init();
}

void test_Sample_should_SupportOncePerTickForSixteenTicksByDefault(void)
{
    uint8_t i;

    Sampler_Reset();

    for (i=0; i < 16; i++) {
        TEST_ASSERT_TRUE( Sampler_IsReady() );
    }

    TEST_ASSERT_FALSE( Sampler_IsReady() );
}

void test_Sample_should_SupportEveryOtherTickFor8Ticks(void)
{
    uint8_t i;

    SampleMax = 8;
    SampleRate = 100;

    Sampler_Reset();

    for (i=0; i < 8; i++) {
        TEST_ASSERT_TRUE( Sampler_IsReady() );
        TEST_ASSERT_FALSE( Sampler_IsReady() );
    }

    TEST_ASSERT_FALSE( Sampler_IsReady() );
}

void test_Sample_should_SupportEveryEighthTickFor4Ticks(void)
{
    uint8_t i;

    SampleMax = 4;
    SampleRate = 400;

    Sampler_Reset();

    for (i=0; i < 4; i++) {
        TEST_ASSERT_TRUE( Sampler_IsReady() );
        TEST_ASSERT_FALSE( Sampler_IsReady() );
        TEST_ASSERT_FALSE( Sampler_IsReady() );
        TEST_ASSERT_FALSE( Sampler_IsReady() );
        TEST_ASSERT_FALSE( Sampler_IsReady() );
        TEST_ASSERT_FALSE( Sampler_IsReady() );
        TEST_ASSERT_FALSE( Sampler_IsReady() );
        TEST_ASSERT_FALSE( Sampler_IsReady() );
    }

    TEST_ASSERT_FALSE( Sampler_IsReady() );
}
