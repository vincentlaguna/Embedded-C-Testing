/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#ifndef TEST_INSTANCES
#define TEST_INSTANCES
#endif /* TEST_INSTANCES */
#include "stdint.h"
#include "Core.h"

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_MASK_RANGE_should_ReturnProperRangesGivenValidInputs(void);
extern void test_MASK_BIT_PAIR_should_ProperlyCreateMasksForBits0To31(void);
extern void test_MASK_RANGE_PAIRS_should_ReturnProperRangesGivenValidInputs(void);
extern void test_COUNT_HIGH_BITS8_should_ProperlyCountHighBitsInAByte(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("TestUtils.c");
  run_test(test_MASK_RANGE_should_ReturnProperRangesGivenValidInputs, "test_MASK_RANGE_should_ReturnProperRangesGivenValidInputs", 13);
  run_test(test_MASK_BIT_PAIR_should_ProperlyCreateMasksForBits0To31, "test_MASK_BIT_PAIR_should_ProperlyCreateMasksForBits0To31", 45);
  run_test(test_MASK_RANGE_PAIRS_should_ReturnProperRangesGivenValidInputs, "test_MASK_RANGE_PAIRS_should_ReturnProperRangesGivenValidInputs", 81);
  run_test(test_COUNT_HIGH_BITS8_should_ProperlyCountHighBitsInAByte, "test_COUNT_HIGH_BITS8_should_ProperlyCountHighBitsInAByte", 134);

  return UnityEnd();
}