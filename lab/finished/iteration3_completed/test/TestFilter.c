#include "Core.h"
#include "unity.h"
#include "Filter.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Filter_AddVal_should_OutputPrevVal_if_PreValAndNewValMatch(void)
{
    TEST_ASSERT_EQUAL_HEX16( 0, Filter_AddVal(0, 0) );
    TEST_ASSERT_EQUAL_HEX16( 0xFFFF, Filter_AddVal(0xFFFF, 0xFFFF) );
    TEST_ASSERT_EQUAL_HEX16( 0x8000, Filter_AddVal(0x8000, 0x8000) );
    TEST_ASSERT_EQUAL_HEX16( 0x7FFF, Filter_AddVal(0x7FFF, 0x7FFF) );
}

void test_Filter_AddVal_should_HandleSimpleMiddleRangeCalculations(void)
{
    TEST_ASSERT_EQUAL_HEX16( 775, Filter_AddVal(1000, 100) );
    TEST_ASSERT_EQUAL_HEX16( 325, Filter_AddVal(100, 1000) );
}

void test_Filter_AddVal_should_HandleExtremeCalculations(void)
{
    TEST_ASSERT_EQUAL_HEX16( 0xFFFE, Filter_AddVal(0xFFFF, 0xFFFC) );
    TEST_ASSERT_EQUAL_HEX16( 0xFFFD, Filter_AddVal(0xFFFC, 0xFFFF) );
    TEST_ASSERT_EQUAL_HEX16( 1, Filter_AddVal(0, 4) );
    TEST_ASSERT_EQUAL_HEX16( 3, Filter_AddVal(4, 0) );
    TEST_ASSERT_EQUAL_HEX16( 0x4000, Filter_AddVal(0, 0xFFFF) );
    TEST_ASSERT_EQUAL_HEX16( 0xBFFF, Filter_AddVal(0xFFFF, 0) );
}
