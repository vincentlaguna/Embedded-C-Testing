#include "../inc/Reflex.h"
#include "unity.h"

void test_Buttons_Init_should_Initialize(void) {
    TEST_ASSERT_EQUAL(1, Buttons_Init());
}

// void test_TheSecond(void) {
//     TEST_ASSERT_EQUAL(2,3);
// }

// void test_TheThird(void) {
//     TEST_ASSERT_EQUAL_FLOAT(1.1, 1.2);
// }

// void test_TheFourth(void) {
//     TEST_ASSERT_TRUE(0 == 1);
// }

// void test_TheFifth(void) {
//     TEST_ASSERT_FALSE(1 == 1);
// }

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_Buttons_Init_should_Initialize);
    // RUN_TEST(test_TheSecond);
    // RUN_TEST(test_TheThird);
    // RUN_TEST(test_TheFourth);
    // RUN_TEST(test_TheFifth);
    return UNITY_END();
}