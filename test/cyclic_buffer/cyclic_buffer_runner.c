#include "unity_fixture.h"

TEST_GROUP_RUNNER(cyclic_buffer)
{
   /* Test cases to run */
   RUN_TEST_CASE(cyclic_buffer, BufferEmptyAfterInit);
   RUN_TEST_CASE(cyclic_buffer, AfterPushingItemTheSameIsReturned);
   RUN_TEST_CASE(cyclic_buffer, AfterPushingTwoItemsTheyAreReturnedInTheSameOrder);
   RUN_TEST_CASE(cyclic_buffer, Overflow);
}
