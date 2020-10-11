#include "unity.h"
#include "MockGetter.h"

static int should_be_called;
static int should_return_this;

//This looks just like the real function
int GetNumber() {

    TEST_ASSERT_TRUE_MESSAGE(should_be_called, "Did Not Expect GetNumber to be called");
    should_be_called = 0;

    return should_return_this;
}

//These were added to help with testing
void MockGetter_Init(void)
{
    should_be_called = 0;
}

void MockGetter_Verify(void)
{
    TEST_ASSERT_FALSE_MESSAGE(should_be_called, "Expected GetNumber to be called");
}

void GetNumber_ExpectAndReturn(int return_value)
{
    should_be_called = 1;
    should_return_this = return_value;
}

