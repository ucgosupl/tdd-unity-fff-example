#include "unity_fixture.h"

#include "cyclic_buffer/cyclic_buffer.h"

TEST_GROUP(cyclic_buffer);

TEST_SETUP(cyclic_buffer)
{
    /* Init before every test */
}

TEST_TEAR_DOWN(cyclic_buffer)
{
    /* Cleanup after every test */
}

TEST(cyclic_buffer, BufferEmptyAfterInit)
{
    struct cbuf buffer;

    cbuf_init(&buffer);

    TEST_ASSERT_TRUE(cbuf_is_empty(&buffer));
}

TEST(cyclic_buffer, AfterPushingItemTheSameIsReturned)
{
    struct cbuf buffer;
    cbuf_item_t item = 0x55AA00FF;

    cbuf_init(&buffer);

    cbuf_push(&buffer, item);

    TEST_ASSERT_EQUAL_HEX32(item, cbuf_pop(&buffer));
}

TEST(cyclic_buffer, AfterPushingTwoItemsTheyAreReturnedInTheSameOrder)
{
    struct cbuf buffer;
    cbuf_item_t item1 = 0x55AA00FF;
    cbuf_item_t item2 = 0xFF00AA55;

    cbuf_init(&buffer);

    cbuf_push(&buffer, item1);
    cbuf_push(&buffer, item2);

    TEST_ASSERT_EQUAL_HEX32(item1, cbuf_pop(&buffer));
    TEST_ASSERT_EQUAL_HEX32(item2, cbuf_pop(&buffer));
}

TEST(cyclic_buffer, Overflow)
{
    int i;

    struct cbuf buffer;
    cbuf_item_t item1 = 0x55AA00FF;
    cbuf_item_t item2 = 0xFF00AA55;

    cbuf_init(&buffer);

    for (i = 0; i < CBUF_ITEM_CNT; i++)
    {
        cbuf_push(&buffer, item1);
        cbuf_pop(&buffer);
    }

    cbuf_push(&buffer, item2);
    TEST_ASSERT_EQUAL_HEX32(item2, cbuf_pop(&buffer));
}

//number of items in the buffer is returned by function
//pass nullptr to functions
//not empty after adding item
//is full
