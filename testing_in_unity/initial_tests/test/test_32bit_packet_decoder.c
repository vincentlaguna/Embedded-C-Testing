
#include "unity.h"

void test_TheFirst(void) {
    TEST_ASSERT_EQUAL(1,2);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_TheFirst);
    return UNITY_END();
}