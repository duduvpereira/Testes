
#include "unity.h"
#include "unity_fixture.h"
#include "stdlib.h"
#include "string.h"

#include "float.h"

TEST_GROUP(Identifier);

TEST_SETUP(Identifier)
{
}

TEST_TEAR_DOWN(Identifier)
{
}



TEST(Identifier, TestIdentifier1)
{
  // All of these should pass
  TEST_ASSERT_EQUAL(0, Identifier());
}

TEST(Identifier, TestIdentifier2)
{
  // This test will fail
  //TEST_ASSERT_EQUAL(1, Identifier2(1,2));
}
