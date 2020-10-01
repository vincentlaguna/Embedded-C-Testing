#include "unity.h"
#include "MockGetter.h"
#include "MockPoster.h"
#include "DoubleAndPass.h"

void setUp(void)
{
    MockGetter_Init();
    MockPoster_Init();
}

void tearDown(void)
{
    MockGetter_Verify();
    MockPoster_Verify();
}

void test_DoubleAndPass_should_DoNothingIfNotCalled(void)
{
}

void test_DoubleAndPass_should_DoubleNothingAndGetNothing(void)
{
    GetNumber_ExpectAndReturn(0);
    PostNumber_Expect(0);

    DoubleAndPass();
}

void test_DoubleAndPass_should_DoubleOneAndGetTwo(void)
{
    GetNumber_ExpectAndReturn(1);
    PostNumber_Expect(2);

    DoubleAndPass();
}

void test_DoubleAndPass_should_DoubleOtherNumbers(void)
{
    int i;

    for (i=2; i < 100; i++) {
        GetNumber_ExpectAndReturn(i);
        PostNumber_Expect(2*i);

        DoubleAndPass();
    }
}

void test_DoubleAndPass_should_NotPostNumbersThatAreTooBigToDouble(void)
{
    GetNumber_ExpectAndReturn(INT_MAX);

    DoubleAndPass();
}

void test_DoubleAndPass_should_NotPostNumbersThatAreTooNegativeToDouble(void)
{
    GetNumber_ExpectAndReturn(INT_MIN);

    DoubleAndPass();
}

int main(void) {

    UNITY_BEGIN();
    RUN_TEST(test_DoubleAndPass_should_DoNothingIfNotCalled);
    RUN_TEST(test_DoubleAndPass_should_DoubleNothingAndGetNothing);
    RUN_TEST(test_DoubleAndPass_should_DoubleOneAndGetTwo);
    RUN_TEST(test_DoubleAndPass_should_DoubleOtherNumbers);
    RUN_TEST(test_DoubleAndPass_should_NotPostNumbersThatAreTooBigToDouble);
    RUN_TEST(test_DoubleAndPass_should_NotPostNumbersThatAreTooNegativeToDouble);
    return UNITY_END();
}
