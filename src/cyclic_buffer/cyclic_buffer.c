#include "cyclic_buffer.h"

void cbuf_init(struct cbuf *buf)
{
    buf->head = 0;
    buf->tail = 0;
}

bool cbuf_is_empty(struct cbuf *buf)
{
    (void) buf;

    return true;
}

void cbuf_push(struct cbuf *buf, cbuf_item_t item)
{
    buf->items[buf->tail] = item;

    buf->tail = (buf->tail + 1) % CBUF_ITEM_CNT;
}

cbuf_item_t cbuf_pop(struct cbuf *buf)
{
    uint32_t idx = buf->head;
    buf->head = (buf->head + 1) % CBUF_ITEM_CNT;

    return buf->items[idx];
}
