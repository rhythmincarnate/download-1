#include<stdlib.h>

#include<lqueue.h>

int lqueue_init(int size, lqueue_t **l)
{	
	return dlisthead_init(size, l);
}

int lqueue_isempty(lqueue_t *l)
{	
	return dlist_isempty(l);
}

int lqueue_enq(lqueue_t *l, const void *data)
{
	return dlist_insert(l, data, INSERT_TAIL);
}

static int __cmp(const void *data, const void *key)
{
	return 0;
}

int lqueue_deq(lqueue_t *l, void *data)
{ 	
	return dlist_fetch(l, NULL, __cmp, data);
}

void lqueue_destory(lqueue_t *l)
{
	dlist_destroy(l);
}


