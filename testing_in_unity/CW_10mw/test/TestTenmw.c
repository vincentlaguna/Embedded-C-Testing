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
  printf("\n");
    
  TEST_ASSERT_FALSE(isValidWalkLength(fWalk));
}

void test_moveWalkerHome_should_return_True_onValidPosition(void)
{
  char *pGrid = NULL;
  pGrid = gridSquare;
  
  char *walk = {"nnwwwsseee"};
  // const char *walk = {"wwwwwwwwww"};
  
  TEST_ASSERT_TRUE(moveWalkerHome(walk, pGrid, SQUARE_DIMENSION));
}

void test_moveWalkerHome_should_return_False_onInvalidPosition(void)
{
  char *pGrid = NULL;
  pGrid = gridSquare;
  
  char *walk = {"nsnwensses"};
  
  TEST_ASSERT_FALSE(moveWalkerHome(walk, pGrid, SQUARE_DIMENSION));
}

void test_moveWalkerOutofBounds_should_return_False(void)
{
  char *pGrid = NULL;
  pGrid = gridSquare;
  
  const char *walk = {"eeeeeeeeee"};
  
  TEST_ASSERT_FALSE(moveWalkerHome(walk, pGrid, SQUARE_DIMENSION));
}

// void test_moveWalkerHome_should_return_True_onValidPosition(void)
// {
//   char *pGrid = NULL;
//   pGrid = gridSquare;
  
//   const char *walk = {"nnwwwsseen"};
//   //const char *walk = {"wwwwwwwwww"};
  
//   TEST_ASSERT_FALSE(moveWalkerHome(walk, pGrid, SQUARE_DIMENSION));
// }

// void test_TheFifth(void) {
//     TEST_ASSERT_FALSE(1 == 1);
// }

int main(void) 
{
  UNITY_BEGIN();
    
  RUN_TEST(test_walk_should_BeTenMinutes);
  RUN_TEST(test_fWalk_should_notBeTenMinutes);
  RUN_TEST(test_moveWalkerHome_should_return_True_onValidPosition);
  RUN_TEST(test_moveWalkerHome_should_return_False_onInvalidPosition);
  RUN_TEST(test_moveWalkerOutofBounds_should_return_False);
  // RUN_TEST(test_TheFifth);
  return UNITY_END();
}