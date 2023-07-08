/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testGround.h"
#include "testBullet.h"
#include "testDisplay.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
int runTests()
{
   TestPosition().run();
   TestGround().run();
   //TestBullet().run();
   TestDisplay().run();
   return 1;
}
