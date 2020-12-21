#include "unity.h"
#include "Tenmw.h"

void test_Walk_should_BeTenMinutes(void) 
{
  const char *walk = {"nsnsnsnsns\0"};
    
  TEST_ASSERT_TRUE(isValidWalk(&walk));
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
    RUN_TEST(test_Walk_should_BeTenMinutes);
    // RUN_TEST(test_TheSecond);
    // RUN_TEST(test_TheThird);
    // RUN_TEST(test_TheFourth);
    // RUN_TEST(test_TheFifth);
    return UNITY_END();
}