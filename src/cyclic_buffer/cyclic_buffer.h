#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t cbuf_item_t;

enum
{
    CBUF_ITEM_CNT = 8,
};

struct cbuf
{
    cbuf_item_t items[CBUF_ITEM_CNT];
    uint32_t head;
    uint32_t tail;
};

void cbuf_init(struct cbuf *buf);
bool cbuf_is_empty(struct cbuf *buf);
void cbuf_push(struct cbuf *buf, cbuf_item_t item);
cbuf_item_t cbuf_pop(struct cbuf *buf);
