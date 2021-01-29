#include "unity.h"
#include "Tenmw.h"

void test_walk_should_BeTenMinutes(void) 
{
  const char *walk = {"nsnsnsnsns"};
    
  TEST_ASSERT_TRUE(isValidWalkLength(walk));
}

void test_fWalk_should_notBeTenMinutes(void) 
{
  const char *fWalk = {"nsnsnsnsnsx"};
    
  TEST_ASSERT_FALSE(isValidWalkLength(fWalk));
}

void test_moveWalkerHome_should_return_validPosition(void)
{
  char *pGrid;
  pGrid = gridSquare;
  
  const char *walk = {"nnwwwsseee"};
  
  TEST_ASSERT_TRUE(moveWalkerHome(walk, pGrid, SQUARE_DIMENSION));

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

int main(void) 
{
  UNITY_BEGIN();
    
  RUN_TEST(test_walk_should_BeTenMinutes);
  RUN_TEST(test_fWalk_should_notBeTenMinutes);
  //RUN_TEST(test_moveWalker_should_return_validPosition);
  // RUN_TEST(test_TheThird);
  // RUN_TEST(test_TheFourth);
  // RUN_TEST(test_TheFifth);
  return UNITY_END();
}