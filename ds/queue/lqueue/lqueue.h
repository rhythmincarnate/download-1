#ifndef __LQUEUE_H
#define __LQUEUE_H

#include <dlist.h>

typedef dlisthead_t lqueue_t;

int lqueue_init(int size, lqueue_t **l);

int lqueue_isempty(lqueue_t *l);

int lqueue_enq(lqueue_t *l, const void *data);

int lqueue_deq(lqueue_t *l, void *data);

void lqueue_destory(lqueue_t *l);

#endif

