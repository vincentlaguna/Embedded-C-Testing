#include "unity.h"
#include "MockPoster.h"

static int should_be_called;
static int should_be_called_with_this_value;

//This looks just like the real function
void PostNumber(int number) {

    TEST_ASSERT_TRUE_MESSAGE(should_be_called, "Did Not Expect PostNumber to be called");
    TEST_ASSERT_EQUAL_INT_MESSAGE(should_be_called_with_this_value, number, "Wrong PostNumber argument 'number'");
    should_be_called = 0;
}

//These were added to help with testing
void MockPoster_Init(void)
{
    should_be_called = 0;
}

void MockPoster_Verify(void)
{
    TEST_ASSERT_FALSE_MESSAGE(should_be_called, "Expected PostNumber to be called");
}

void PostNumber_Expect(int expected_number)
{
    should_be_called = 1;
    should_be_called_with_this_value = expected_number;
}

