#include "unity_fixture.h"

#include "cyclic_buffer/cyclic_buffer.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(cbuf_init, struct cbuf *);

TEST_GROUP(cyclic_buffer_mock);

TEST_SETUP(cyclic_buffer_mock)
{
    /* Init before every test */

    RESET_FAKE(cbuf_init);
}

TEST_TEAR_DOWN(cyclic_buffer_mock)
{
    /* Cleanup after every test */
}

TEST(cyclic_buffer_mock, MockExample)
{
    struct cbuf buffer;

    TEST_ASSERT_EQUAL(0, cbuf_init_fake.call_count);
    cbuf_init(&buffer);

    TEST_ASSERT_EQUAL(1, cbuf_init_fake.call_count);
    //TEST_ASSERT_EQUAL_MEMORY(&buffer, DISPLAY_output_fake.arg0_val, sizeof(struct cbuf));
}
